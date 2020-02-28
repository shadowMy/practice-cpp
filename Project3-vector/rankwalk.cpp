#include<iostream>
#include<cstdlib>	//rand(), srand()原型prototypes
#include<ctime>		//time()原型prototype
#include "vector.h"
int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;	//方向 方位
	Vector step;		//步 一步 脚步
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;		//目标 靶子
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << "steps, the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance(q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}