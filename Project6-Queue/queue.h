#pragma once
#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;			//用typedef定义Item

class Queue
{
private:
	struct Node { Item item; struct Node* next; };
	enum { Q_SIZE = 10 };

	Node* front;			//头指针
	Node* rear;				//尾指针
	int items;				//目前队列中的数量
	const int qsize;		//队列最大数量

	Queue(const Queue& q) : qsize(0){	}							//显示复制构造函数和赋值运算符，避免系统自动生成默认的方法定义，
	Queue& operator=(const Queue& q) { return*this; }			//定义为伪私有方法，以易于跟踪编译错误，指出这些操作是不可行的

public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};

#endif