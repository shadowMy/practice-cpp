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
	void Deposit(double amt);				//���	
	virtual void Withdraw(double amt);		//ȡ��	//�鷽��virtual method
	double Balance() const;					//���
	virtual void ViewAcct() const;			//��ʾ�˻���Ϣ
	virtual ~Brass() {}						//����������
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
	virtual void ViewAcct() const;			//��ʾ�˻���Ϣ�����µķ���
	virtual void Withdraw(double amt);		//ȡ����µķ���
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

#endif