/*
 *socket
 *connect
 *sent/recv
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

#define SERVER_PORT 8888

int main(int argc, char **argv)
{
  int iSocketClient;
  int iRet;
  int iSendLen;
  unsigned char ucSendBuf[1000];
  struct sockaddr_in tSocketServerAddr;

  if (argc != 2)
  {
    printf("Usage:\n");
    printf("%s<server_ip>\n", argv[0]);
    return -1;
  }

  iSocketClient = socket(AF_INET, SOCK_STREAM, 0); /*选择ipv4 TCP连接模式*/

  tSocketServerAddr.sin_family  = AF_INET;
  tSocketServerAddr.sin_port    = htons(SERVER_PORT);          /*将主机字节序转换成网路字节序  host to net,short(2个字节)*/
  if (0 == inet_aton(argv[1], &tSocketServerAddr.sin_addr)) /*将ip字符串存入后面地址所指的地方去*/
  {
    printf("invalid server_ip\n");
    return -1;
  }
  memset(tSocketServerAddr.sin_zero, 0, 8); /*将该项设置为0,8个字节*/

  iRet = connect(iSocketClient, (const struct sockaddr *)&tSocketServerAddr, sizeof(struct sockaddr));
  if (-1 == iRet)
  {
    printf("connect error!\n");
    return -1;
  }
  while (1)
  {
    if (fgets(ucSendBuf, 999, stdin))
    {
      iSendLen = send(iSocketClient, ucSendBuf, strlen(ucSendBuf), 0);
      if (iSendLen <= 0)
      {
        close(iSocketClient);
        return -1;
      }
    }
  }

  return 0;
}