#include<iostream>
#include<string>
#include<cctype>
#include "stacktp.h"
using std::cin;
using std::cout;
using std::string;

int main()
{
	Stack<string> st;	//创建一个空栈，实例化。
	char ch;
	string po;
	cout << "Please enter A to add a purchase order(一个购买订单）,\n"
		<< "P to process a PO(处理采购订单）, or  Q to quit.\n";
	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))		//isalpha:ch不是字母返回0  //如果ch不是字母，则执行...
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a': 
			cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else {
				st.pop(po);
				cout << "PO #" << po << " popped\n";
				break;
			}
		}
		cout << "Please enter A to add a purchase order(一个购买订单）,\n"
			<< "P to process a PO(处理采购订单）, or  Q to quit.\n";
	}
	cout << "Bye\n";
	return 0;
}