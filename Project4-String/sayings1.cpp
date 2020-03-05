#include<iostream>
#include "string1.h"
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
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

		int shortest = 0;
		int first = 0;
		for (i = 0; i < total; i++)
		{
			if (sayings[i].length() < sayings[shortest].length())			//调用length，比较两个字符串长度
				shortest = i;
			if (sayings[i] < sayings[first])								//重载的<，调用strcmp比较两个字符串首字母大小
				first = i;
		}
		cout << "谚语：\n" << sayings[shortest] << endl;
		cout << "第一个字母：\n" << sayings[first] << endl;
		cout << "This program used " << String::HowMany() << "String objects.白白\n";
	}
	else
		cout << "费半天劲，你啥也没输！再！见！\n";
	return 0;
}
