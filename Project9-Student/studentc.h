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
	explicit Student(const std::string& s)		//��ֹstring��Student����ʽ����ת��
		: name(s), scores() 					//explicit�ؼ���ֻ����������ֻ��һ���������๹�캯��, ���������Ǳ����ù��캯������ʾ��, ������ʽ��, 
	{ }											//�������Ӧ����һ���ؼ�����implicit, ��˼�����ص�, �๹�캯��Ĭ������¼�����Ϊimplicit(��ʽ).	 
	explicit Student(int n)						//��ֹint��Student����ʽ����ת��
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
	double operator[](int i) const;			//Ҫ���� const �����أ�ֻ��Ҫ�������� const �ļ��ɣ�������ĳ�� const �����ڲ����� func�����ߵ��� const �������ã��ĳ�Ա����ʱ��

//friend
	//input
	friend std::istream& operator>>(std::istream& is, Student& stu);	//1 word
	friend std::istream& getline(std::istream& is, Student& stu);		//1 line
	//output
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};

#endif