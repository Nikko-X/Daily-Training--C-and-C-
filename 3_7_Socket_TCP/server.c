/*
*socket
*bind
*listen
*accept
*send/recv
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


#define SERVER_PORT 8888
#define BACKLOG 10

int main(int argc,char **argv)
{
  int iSocketServer;
  int iRet;
  int iAddrLen;
  int iSocketClient;
  int iRecvLen;
  int iClientNum = -1;
  unsigned char ucRecvBuf[1000];
  struct sockaddr_in tSocketServerAddr;
  struct sockaddr_in tSocketClientAddr;
  
  signal(SIGCHLD,SIG_IGN);

  iSocketServer = socket(AF_INET, SOCK_STREAM, 0); /*选择ipv4 TCP连接模式*/
  if(-1 == iSocketServer)
  {
      printf("souck erro!\n");
      return -1;

  }

  tSocketServerAddr.sin_family          = AF_INET;
  tSocketServerAddr.sin_port            = htons(SERVER_PORT);     /*将主机字节序转换成网路字节序  host to net,short(2个字节)*/
  tSocketServerAddr.sin_addr.s_addr     = INADDR_ANY;   /*设置ip 这里设置的是本机所有的ip*/
  memset(tSocketServerAddr.sin_zero,0,8); /*将该项设置为0,8个字节*/

  iRet = bind(iSocketServer, (const struct sockaddr *)&tSocketServerAddr,sizeof(struct sockaddr));
  if(-1 == iRet)
  {
    printf("bind error!\n");
    return -1;
  }

  iRet = listen(iSocketServer, BACKLOG); /*启动监测，BACKLOG定义了最大连接数*/
  if(-1 == iRet)
  {
    printf("listen error!\n");
    return -1;
  }

  while(1)
  {
    iAddrLen = sizeof(struct sockaddr);
    iSocketClient = accept(iSocketServer,(struct sockaddr *)&tSocketClientAddr,&iAddrLen); /*等待接收一条连接*/
    if(-1 != iSocketClient)
    {
      iClientNum++;
      printf("Get connect form %d: %s\n",iClientNum,inet_ntoa(tSocketClientAddr.sin_addr)); /*inet_ntoa()将网络IP 转化为字符串*/

      if(!fork()) /*复制出另一个进程,这样可以监测多个客户端*/
      {
        while(1)
        {
          /*接收客户端发来的源码并显示出来*/
          iRecvLen = recv(iSocketClient, ucRecvBuf, 999, 0);
          if(iRecvLen <= 0) /*接收错误就关闭否则打印出来*/
          {
            close(iSocketServer);
            return -1;
          }
          else
          {
            ucRecvBuf[iRecvLen] = '\0';
            printf("Get Message Form Client %d: %s",iClientNum,ucRecvBuf);
          }
        }
      }
    }
  }

  close(iSocketServer);
  return 0;
}