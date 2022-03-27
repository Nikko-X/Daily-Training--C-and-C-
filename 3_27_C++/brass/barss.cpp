#include "brass.h"
using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);
brass::brass(const std::string& fname, long num, double bal)
{
	fullName = fname;
	acctNum = num;
	balance = bal;
}
void brass::deposit(double amt)	//存款
{
	if (amt < 0)
		cout << "Error!\n";
	else
		balance += amt;
}
void brass::wirhDraw(double amt)	//取款
{
	format initialState = setFormat();
	precis prec = cout.precision(2);//设置输出浮点格式：###.## 2位小数
	if (amt < 0)
		cout << "Erro!\n";
	else if (amt > balance)
		cout << "Exceeds your balance!\n";
	else
		balance -= amt;
	restore(initialState, prec);
}
double brass::balan()	const	//余额
{
	return balance;
}
void brass::viewAcct() const	//查看账户
{
	format initialState = setFormat();
	precis prec = cout.precision(2);//设置格式：###.## 2位小数
	cout << "Client: " << fullName << endl
		<< "Account Num: " << acctNum << endl
		<< "Balance:$ " << balance << endl;
	restore(initialState, prec);
}

brass::~brass()
{
	cout << "析构函数调用\n";
}

brassPlus::brassPlus(const std::string& fname, long num, double bal, double ml, double ra):brass(fname, num, bal)
{
	maxLoan = ml;
	rate = ra;
	owesBank = 0;
}

brassPlus::brassPlus(const brass& ba, double ml, double ra) :brass(ba)
{
	maxLoan = ml;
	rate = ra;
	owesBank = 0;
}

void brassPlus::viewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);//设置格式：###.##
	brass::viewAcct();
	cout << "Max Loan: $" << maxLoan << endl
		<< "Own To Bank:$ " << owesBank << endl;
	cout.precision(3);	//设置格式：###.###
	cout << "Rate: " << 100 * rate << endl;
	restore(initialState, prec);
}

void brassPlus::withDraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);//设置格式：###.##
	double bal = balan();
	if (amt <= bal)
		brass::wirhDraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1 + rate);	//计算欠银行部分
		cout << "Advance Now: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate << endl;
		deposit(advance);	//银行放贷部分存入余额
		brass::wirhDraw(amt);	//取款
	}
	else if (amt < 0)
		cout << "Erro!\n";
	else 
		cout << "Exceeds your balance!\n";
	restore(initialState, prec);
}

format setFormat()
{
	return cout.setf(std::ios_base::fixed,
					 std::ios_base::floatfield);
}
void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}