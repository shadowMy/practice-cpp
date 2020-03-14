#pragma once
#ifndef BRASS_H_
#define BRASS_H_
#include<string>
#include<iostream>

//ABC(Abstract Bace Class)�������
class AcctABC
{
private:
	std::string fullName;
	long acctNum;
	double balance;
protected:
	//�����ʽ��
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
	void Deposit(double amt);								//���	
	virtual void Withdraw(double amt) = 0;					//ȡ��	//���麯��
	double Balance() const { return balance; };				//���
	virtual void ViewAcct() const = 0;						//��ʾ�˻���Ϣ	//���麯��
	virtual ~AcctABC() { }
};

class Brass : public AcctABC
{
public:
	Brass(const std::string& s = "Nullbody", long an = -1,
		double bal = 0.0) : AcctABC(s, an, bal) { };
	virtual void Withdraw(double amt);		//ȡ��	//�鷽��virtual method
	virtual void ViewAcct() const;			//��ʾ�˻���Ϣ
	virtual ~Brass() {}						//����������
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
	virtual void ViewAcct() const;			//��ʾ�˻���Ϣ�����µķ���
	virtual void Withdraw(double amt);		//ȡ����µķ���
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

#endif