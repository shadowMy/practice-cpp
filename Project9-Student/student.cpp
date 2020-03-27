#include "studenti.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;
//public methods
double Student::Average() const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}

const string& Student::Name() const
{
	return (const string&) *this;
}

double& Student::operator[](int i)
{
	return ArrayDb::operator[](i) ;			//use valarray<double>::operator[]()
}

double Student::operator[](int i) const			//Ҫ���� const �����أ�ֻ��Ҫ�������� const �ļ��ɣ�������ĳ�� const �����ڲ����� func�����ߵ��� const �������ã��ĳ�Ա����ʱ��
{
	return ArrayDb::operator[](i);
}

//private methods
ostream& Student::arr_out(ostream& os) const
{
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (i % 5 == 4)		//5��һ�У�i�Ǵ�0��ʼ�ģ�i=4ʱ�Ѿ�5�����ˣ�
				os << endl;
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
		os << " empty array ";
	return os;
}

//friends
//use string version of operator>>()
istream& operator>>(istream& is, Student& stu)
{
	is >> (string&)stu;
	return is;
}

//use string firend getline(ostream&, const string&)
istream& getline(istream& is, Student& stu)
{
	getline(is, (string&)stu);
	return is;
}

//use string version of operator<<()
ostream& operator<<(ostream& os, const Student& stu)
{
	os << "Scores for " << (const string&)stu << ":\n";
	stu.arr_out(os);
	return os;
}