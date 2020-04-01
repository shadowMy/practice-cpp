#include<iostream>
#include<cstdlib>	//for rand(), srand()
#include<ctime>		//for time()
#include "stacktp1.h"
using std::cin;
using std::cout;

const int Num = 10;
int main()
{
	std::srand(std::time(0));		//randomize rand()
	cout << "Please enter stack size: ";
	int stacksize;
	cin >> stacksize;
	Stack<const char*> st(stacksize);		//创建一个stacksize大小的空栈
	
	const char* in[Num] = {
		"1: Hank Gilgamesh", "2:Kiki Ishtar",
		"3: Betty Rocker", "4:Ian Flagranti",
		"5: Wolf Kibble", "6:A li baba",
		"7: teng xun", "8:bai du",
		"9: sou hu", "10:sou gou",
	};

	const char* out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < Num)
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
		cout << out[i] << std::endl;

	cout << "Bye!\n";
	return 0;
}