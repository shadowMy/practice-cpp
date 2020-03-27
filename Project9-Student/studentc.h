#pragma once
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include<iostream>
#include<string>
#include<valarray>
class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name;
	ArrayDb scores;
	std::ostream& arr_out(std::ostream& os) const;
public:
	Student() : name("Null Student"), scores() { }
	explicit Student(const std::string& s)		//防止string到Student的隐式类型转换
		: name(s), scores() 					//explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的, 
	{ }											//跟它相对应的另一个关键字是implicit, 意思是隐藏的, 类构造函数默认情况下即声明为implicit(隐式).	 
	explicit Student(int n)						//防止int到Student的隐式类型转换
		: name("Nully"), scores(n) 
	{ }											
	Student(const std::string& s, int n)
		: name(s), scores(n) { }
	Student(const std::string&s, const ArrayDb& a)
		: name(s), scores(a) { }
	Student(const char* str, const double* pd, int n)
		: name(str), scores(pd, n) { }
	~Student() { }
	double Average() const;
	const std::string& Name() const;
	double& operator[](int i);
	double operator[](int i) const;			//要调用 const 的重载，只需要上下文是 const 的即可，比如在某个 const 函数内部调用 func，或者调用 const 对象（引用）的成员函数时。

//friend
	//input
	friend std::istream& operator>>(std::istream& is, Student& stu);	//1 word
	friend std::istream& getline(std::istream& is, Student& stu);		//1 line
	//output
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};

#endif