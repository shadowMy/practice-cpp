#include<cmath>
#include "vector.h"		//包含了iostream
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{													//内置数学函数在使用角度时以弧度为单位
	const double Rad_to_deg = 45.0 / atan(1.0);		//弧度转换成度数 compute degrees角度 in one radian弧度
	
	//private methods
	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		if (x == 0 && y == 0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}

	void Vector::set_x()
	{
		x = mag * cos(ang);
	}

	void Vector::set_y()
	{
		y = mag * sin(ang);
	}

	//public methods
	Vector::Vector()			//默认构造函数
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)			//如果是RECT则从直角坐标构造矢量（默认），如果是POL则极坐标
	{														//rectangular coordinate直角坐标；polar coordinate极坐标
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()	//析构函数
	{
	}

	void Vector::polar_mode()
	{
		mode = POL;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator-() const		//向量的相反数
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	//友元函数friend methods
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}

	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)									//标识符RECT、POL作用域为类，因此在类定义中可使用未限定名称
			os << "(x,y) = (" << v.x << ", " << v.y << ")";			//但其全名为 VECTOR::Vector::RECT和VECTOR::Vector::POL
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}
}