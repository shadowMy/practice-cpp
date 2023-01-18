#pragma once
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include<iostream>
#include<string>
#include<valarray>			//valarray类
class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	std::ostream& arr_out(std::ostream& os) const;
public:
	Student() : std::string("Null Student"), ArrayDb() { }
	explicit Student(const std::string& s)		//防止string到Student的隐式类型转换
		: std::string(s), ArrayDb() 					//explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的, 
	{ }											//跟它相对应的另一个关键字是implicit, 意思是隐藏的, 类构造函数默认情况下即声明为implicit(隐式).	 
	explicit Student(int n)						//防止int到Student的隐式类型转换
		: std::string("Nully"), ArrayDb(n)
	{ }											
	Student(const std::string& s, int n)
		: std::string(s), ArrayDb(n) { }
	Student(const std::string&s, const ArrayDb& a)
		: std::string(s), ArrayDb(a) { }
	Student(const char* str, const double* pd, int n)
		: std::string(str), ArrayDb(pd, n) { }
	~Student() { }
	double Average() const;
	const std::string& Name() const;
	using std::valarray<double>::operator[];		//using限定符重新定义访问权限，使派生类Student可以使用基类valarray的operator[]（）方法
													//在派生类的公有部分加入using声明，只使用成员名，没有圆括号、特征标和返回类型
													//using只适用于继承，不适用于包含。
	//double& operator[](int i);
	//double operator[](int i) const;			//要调用 const 的重载，只需要上下文是 const 的即可，比如在某个 const 函数内部调用 func，或者调用 const 对象（引用）的成员函数时。

//friend
	//input
	friend std::istream& operator>>(std::istream& is, Student& stu);	//1 word
	friend std::istream& getline(std::istream& is, Student& stu);		//1 line
	//output
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};

#endif