#include<iostream>
#ifndef STRING1_H_
#define STRING1_H_
using std::ostream;
using std::istream;

class String
{
private:
	char* str;
	int len;
	static int num_strings;					//静态类成员：无论创建多少对象，程序都只创建一个静态类变量副本。对于所有类对象都具有相同值的类似有数据是非常方便的
	static const int CINLIM = 80;			//声明中只描述如何分配内存，但不进行分配。不能在声明中进行初始化
public:
	String(const char* s);			//构造函数
	String();						//默认构造函数
	String(const String& st);		//复制构造函数
	~String();
	int length() const { return len; }

	String& operator=(const String&);			//深度复制 赋值运算符,一个类对象赋给另一个
	String& operator=(const char*);				//一个char字符串赋给类对象
	char& operator[](int i);					//可以读写常规String对象
	const char& operator[](int i) const;		//只能读constString对象，不能写

	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend istream& operator>>(istream& is, String& st);
	friend ostream& operator<<(ostream& os, const String& st);

	static int HowMany();
};
#endif