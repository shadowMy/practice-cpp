#pragma once
#ifndef BRASS_H_
#define BRASS_H_
#include<string>
using std::string;
class Brass
{
private:
	string fullName;
	long acctNum;
	double balance;
public:
	Brass(const string& s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);				//存款	
	virtual void Withdraw(double amt);		//取款	//虚方法virtual method
	double Balance() const;					//余额
	virtual void ViewAcct() const;			//显示账户信息
	virtual ~Brass() {}						//虚析构函数
};

class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const string& s = "Nullbody", long an = -1, double  al = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct() const;			//显示账户信息（更新的方法
	virtual void Withdraw(double amt);		//取款（更新的方法
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

#endif