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
	cout << "嗨，你叫啥？\n";
	cin >> name;

	cout << name << "， 请输入最多 " << ArSize << " 个谚语<啥也不说就退出>:\n";
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
		cout << "这是你说的话：\n";
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;		//sayings[i][0]打印每句话第一个字母

		String* shortest = &sayings[0];			//String* shortest;	shortest = &sayings[0];
		String* first = &sayings[0];
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first)
				first = &sayings[i];
		}
		cout << "最短的谚语是：\n" << *shortest << endl;
		cout << "首字母最小的是：\n" << *first << endl;
		srand(time(0));
		int choice = rand() % total;
		String* favorite = new String(sayings[choice]);
		cout << "my favorite sayings:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "又瞎忙活呗？啊哈？\n";
	return 0;
}