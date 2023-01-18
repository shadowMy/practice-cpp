#pragma once
//vector——矢量
#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>
namespace VECTOR
{
	class Vector			//大小写！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	{
	public:
		enum Mode{RECT, POL};		//枚举创建。分别标识两种表示法
	private:
		double x;		//水平分量horizontal value
		double y;		//垂直分量vertical value
		double mag;		//大小（长度）
		double ang;		//方位（角度）
		Mode mode;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }
		void polar_mode();
		void rect_mode();

		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;		//向量相减
		Vector operator-()const;			//向量的相反数
		Vector operator*(double n) const;

		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
#endif