#pragma once
#ifndef BRASS_H_
#define BRASS_H_
#include<string>
#include<iostream>

//ABC(Abstract Bace Class)抽象基类
class AcctABC
{
private:
	std::string fullName;
	long acctNum;
	double balance;
protected:
	//处理格式化
	struct Formatting {
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	Formatting SetFormat() const;
	void Restore(Formatting& f) const;

	const std::string& FullName() const { return fullName; }
	long AcctNum() const { return acctNum; }

public:
	AcctABC(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);								//存款	
	virtual void Withdraw(double amt) = 0;					//取款	//纯虚函数
	double Balance() const { return balance; };				//余额
	virtual void ViewAcct() const = 0;						//显示账户信息	//纯虚函数
	virtual ~AcctABC() { }
};

class Brass : public AcctABC
{
public:
	Brass(const std::string& s = "Nullbody", long an = -1,
		double bal = 0.0) : AcctABC(s, an, bal) { };
	virtual void Withdraw(double amt);		//取款	//虚方法virtual method
	virtual void ViewAcct() const;			//显示账户信息
	virtual ~Brass() {}						//虚析构函数
};

class BrassPlus : public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string& s = "Nullbody", long an = -1, double  al = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.1);
	virtual void ViewAcct() const;			//显示账户信息（更新的方法
	virtual void Withdraw(double amt);		//取款（更新的方法
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

#endif