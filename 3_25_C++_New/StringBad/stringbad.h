#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#include <iostream>
void callme1(stringBad & );
//void callme2(stringBad);
class stringBad
{
public:
	stringBad();
	stringBad(const char* s);
	friend std::ostream & operator<<(std::ostream& os, const stringBad& st);
	friend bool operator<(const stringBad& st1, const stringBad& st2);
	friend bool operator>(const stringBad& st1, const stringBad& st2);
	friend bool operator==(const stringBad& st1, const stringBad& st2);
	//friend char& operator[](stringBad str);	//[]����ʵ���ǲ����Ե�
	char& operator[](int i);
	stringBad(const stringBad& s);	//���ƹ��캯��
	stringBad& operator=(const stringBad& st);
	~stringBad();
private:
	char* str = NULL;
	int len;
	static int num_strings;
};

#endif