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

typedef Customer Item;			//��typedef����Item

class Queue
{
private:
	struct Node { Item item; struct Node* next; };
	enum { Q_SIZE = 10 };

	Node* front;			//ͷָ��
	Node* rear;				//βָ��
	int items;				//Ŀǰ�����е�����
	const int qsize;		//�����������

	Queue(const Queue& q) : qsize(0){	}							//��ʾ���ƹ��캯���͸�ֵ�����������ϵͳ�Զ�����Ĭ�ϵķ������壬
	Queue& operator=(const Queue& q) { return*this; }			//����Ϊα˽�з����������ڸ��ٱ������ָ����Щ�����ǲ����е�

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