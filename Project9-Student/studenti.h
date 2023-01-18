#pragma once
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include<iostream>
#include<string>
#include<valarray>			//valarray��
class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	std::ostream& arr_out(std::ostream& os) const;
public:
	Student() : std::string("Null Student"), ArrayDb() { }
	explicit Student(const std::string& s)		//��ֹstring��Student����ʽ����ת��
		: std::string(s), ArrayDb() 					//explicit�ؼ���ֻ����������ֻ��һ���������๹�캯��, ���������Ǳ����ù��캯������ʾ��, ������ʽ��, 
	{ }											//�������Ӧ����һ���ؼ�����implicit, ��˼�����ص�, �๹�캯��Ĭ������¼�����Ϊimplicit(��ʽ).	 
	explicit Student(int n)						//��ֹint��Student����ʽ����ת��
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
	using std::valarray<double>::operator[];		//using�޶������¶������Ȩ�ޣ�ʹ������Student����ʹ�û���valarray��operator[]��������
													//��������Ĺ��в��ּ���using������ֻʹ�ó�Ա����û��Բ���š�������ͷ�������
													//usingֻ�����ڼ̳У��������ڰ�����
	//double& operator[](int i);
	//double operator[](int i) const;			//Ҫ���� const �����أ�ֻ��Ҫ�������� const �ļ��ɣ�������ĳ�� const �����ڲ����� func�����ߵ��� const �������ã��ĳ�Ա����ʱ��

//friend
	//input
	friend std::istream& operator>>(std::istream& is, Student& stu);	//1 word
	friend std::istream& getline(std::istream& is, Student& stu);		//1 line
	//output
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};

#endif