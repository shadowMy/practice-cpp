#pragma once
#ifndef WORKER0_H_
#define WORKER0_H_

#include<string>

class Worker		//一个抽象基类an abstract base class
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;	//模块化组合
	virtual void Get();			//防止set取得两次worker的信息
public:
	Worker() : fullname("no one"), id(0L) { }
	Worker(const std::string& s, long n) : fullname(s), id(n) { }
	virtual ~Worker() = 0;			//纯虚函数（证明是抽象类）pure virtual destructor
	virtual void Set() = 0;			//声明为纯虚函数，可以不实现，在派生类中再具体实现。
	virtual void Show() const = 0;	//声明为纯虚函数，可以不实现，在派生类中再具体实现。
};

class Waiter : virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter() : Worker(), panache(0) { }
	Waiter(const std::string& s, long n, int p = 0)
		: Worker(s, n), panache(p) { }
	Waiter(const Worker& wk, int p = 0)
		: Worker(wk), panache(p) { }
	void Set();
	void Show() const;
};

class Singer : virtual public Worker
{
protected:
	enum{other,alto,contralto,soprano,bass,baritone,tenor};
	enum{ Vtypes = 7 };
	void Data() const;
	void Get();
private:
	static char* pv[Vtypes];		//静态数组pv，存储指向相应字符串的指针
	int voice;
public:
	Singer() : Worker(), voice(other) { }
	Singer(const std::string& s, long n, int v = other)
		: Worker(s, n), voice(v) { }
	Singer(const Worker& wk, int v = other)
		: Worker(wk), voice(v) { }
	void Set();
	void Show() const;
};

class SingingWaiter : public Singer, public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() { }
	SingingWaiter(const std::string& s, long n, int p = 0, int v = other)
		: Worker(s,n), Waiter(s,n,p), Singer(s,n,v) { }
	SingingWaiter(const Worker& wk, int p = 0, int v = other)
		: Worker(wk), Waiter(wk,p), Singer(wk,v) { }

	SingingWaiter(const Waiter& wk, int v = other)
		: Worker(wk), Waiter(wk), Singer(wk, v) { }

	SingingWaiter(const Singer& wk, int p = 0)
		: Worker(wk), Waiter(wk, p), Singer(wk) { }
	void Set();
	void Show() const;
};

#endif