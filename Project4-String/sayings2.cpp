#include<iostream>
#include<cstdlib>		//rand(), srand()
#include<ctime>			//time()
#include "string1.h"
const int ArSize = 10;
const int MaxLen = 81;
int main()
{
	using namespace std;
	String name;
	cout << "�ˣ����ɶ��\n";
	cin >> name;

	cout << name << "�� ��������� " << ArSize << " ������<ɶҲ��˵���˳�>:\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;

	if (total > 0)
	{
		cout << "������˵�Ļ���\n";
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;		//sayings[i][0]��ӡÿ�仰��һ����ĸ

		String* shortest = &sayings[0];			//String* shortest;	shortest = &sayings[0];
		String* first = &sayings[0];
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first)
				first = &sayings[i];
		}
		cout << "��̵������ǣ�\n" << *shortest << endl;
		cout << "����ĸ��С���ǣ�\n" << *first << endl;
		srand(time(0));
		int choice = rand() % total;
		String* favorite = new String(sayings[choice]);
		cout << "my favorite sayings:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "��Ϲæ���£�������\n";
	return 0;
}