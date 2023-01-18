#include "queue.h"
#include<cstdlib>

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}

Queue::Queue(int qs) : qsize(qs)		//成员初始化列表：const、引用的数据成员必须用这种格式来初始化
{
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items == 0;

}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

bool Queue::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

bool Queue::dequeue(Item& item)
{
	if (isempty())
		return false;
	item = front->item;			//将出队的数据提供给调用函数
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;

}