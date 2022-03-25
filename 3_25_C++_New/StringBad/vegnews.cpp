#include "stringbad.h"
#include <iostream>
using std::cout;

int main()
{
	stringBad str1;
	stringBad str2( "Hello I Am New One!" );
	stringBad str3 = str2;
	if (str3 > str2)
		cout << "True!\n";
	else
		cout << "Flase!\n";
	//callme1(str1);
}