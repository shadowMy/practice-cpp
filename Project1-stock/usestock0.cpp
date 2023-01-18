#include<iostream>
#include "stock00.h"

const int STKS = 4;
int main()
{
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 60, 6.5),
		Stock("Fleep Enterprises", 60, 6.5)
	};

	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		stocks[st].show();

	const Stock* top = &stocks[0];			//*top是stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);		//*top = stocks[0]和stock[1]中较大的，top = ... 是地址
	std::cout << "\nMost valuable holding:\n";
	top->show();
	return 0;
} 