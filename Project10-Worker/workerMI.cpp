#include<iostream>
#include "WorkerMI.h"
using std::cout;
using std::cin;
using std::endl;

//Worker methods
//即使是纯虚函数，也必须实现虚析构函数
//must implement virtual destructor,even if pure
Worker::~Worker() { }

void Worker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

//Waiter methods
void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "Category:waiter\n ";
	Worker::Data();
	Data();
}
//protected methods
void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

void Waiter::Data() const
{
	cout << "Panache rating: " << panache << endl;
}

//Singer methods

char* Singer::pv[Singer::Vtypes] = { (char*)"other", (char*)"alto", (char*)"contralto", (char*)"soprano", (char*)"bass", (char*)"baritone", (char*)"tenor" };

void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Data();
	Data();
}
//protected methods
void Singer::Get()
{
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << "  ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}

void Singer::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}

//SingerWaiter methods
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "Category singing waiter\n";
	Worker::Data();
	Data();
}