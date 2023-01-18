#include<iostream>
#include<cstdlib>
#include<ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximun size of queue: ";
	int qs;
	cin >> qs;

	Queue line(qs);				//队列建成

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;		//转换成总分钟

	cout << "Enter the average number of customer per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;		//计算平均多长时间来一名顾客

	Item temp;			//新顾客
	long turnaways = 0;	//由于队满而离开的顾客
	long customers = 0;	//加入队列的顾客	
	long served = 0;	//接受服务的总人数
	long sum_line = 0;	//累计的队伍长度
	int wait_time = 0;	//当前顾客需要的处理时间
	long line_wait = 0;	//等候的累计时间

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}

	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "	customers served（被服务的）: " << served << endl;
		cout << "		turnaways（离开的）: " << turnaways << endl;
		cout << "average queue size（平均的队伍长度）: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time（平均的等待时间）: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";

	return 0;
}

bool newcustomer(double x)
{
	return(std::rand() * x / RAND_MAX < 1);		//值在0~6之间，小于1时返回true
}