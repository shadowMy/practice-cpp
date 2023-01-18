#include<iostream>
#include<cstdlib>	//rand(), srand()ԭ��prototypes
#include<ctime>		//time()ԭ��prototype
#include "vector.h"
////	#include<fstream>
int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));					//srand()��time()
	double direction;	//���� ��λ
	Vector step;		//�� һ�� �Ų�
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
////	unsigned long i = 0;
	double target;		//Ŀ�� ����
	double dstep;
////	ofstream fout;
////	fout.open("test.txt");
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target)
		{
			direction = rand() % 360;					//rand()
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
////			fout << i << ": " << result << endl;
////			i++;
			steps++;
		}
		cout << "After " << steps << "steps, the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
////		i = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance(q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}