//#include<iostream>		iosteram --> std::cout<<..... / using std::cout / using namespace std;
/*
#include<cstdlib>		exit();		exit(EXIT_FAILURE);
#include<cmath>			sqrt().....
#include<climits>		一些符号常量表示类型的限制信息
#include<string>		string类，string str1 = "字符串内容";
#include<cstring>		提供字符串相关函数声明:
						strlen()确定字符串长度;	int len1 = str1.size()是string类的求长度，
												int len2 = strlen(ch)是普通字符串用cstring字符串相关函数的求长度
												getline(cin,str);是string类的输入；
												cin.getline(ch,20);是普通字符串的输入；
						strcpy(1,2)复制;
						strcat(1.2)把2连到1后面;
						strcmp("1","2");比较两个字符串，相同返回0，按字母排序1在2前返回负数，1在2后返回正数。
#include<cctype>		isalpha(ch);ch是字母，返回非零值，否则返回0.
						ispunct(ch);ch是标点符号,返回true.
						isdigits();检测是否是数字
						isspace();检测是否是空白(如换行符 空格 制表符）
*/
/*#include<fstream>			for file I/O 文件输出输入
							ofstream对象要主动声明，与文件关联后，像cout一样使用它。
								往文件里面输出(文件类似屏幕输出）						从文件往外输入（文件类似键盘）
							声明：													
								ofstream outFile;							|			ifstream inFile;
								ofstream fout;								|			ifstream fin;
							关联文件：										|
								outFile.open("fish.txt");					|			inFile.open("bowling.txt");
																			|
								char filename[50];							|			char filename[50];
								cin >> filename;							|			cin >> filename;
								fout.open(filename);						|			fin.open(filename);
							使用：											|
								double wt = 125.8;							|			double wt;
								outFile << wt;		//往fish.txt里写入wt。	|			inFile >> wt;		//从bowling.txt里读取一个数字到wt
																			|
								char line[81] = "一串字符 啊啊啊"；			|			char line[81];
								fout << line <<endl；						|			fin.getline(line,81);
is_open()	检查文件是否被成功打开， good() 也可以。  如:文件名为inFile.   inFile.is_open();inFile.good();
检测文件尾EOF	inFile.eof();判断是否到达文件末尾EOF，到达返回true
						if (inFile.eof())	cout << "End of file reached.\n";
				inFile.fail();判断EOF和类型匹配不匹配，即看一个流是否“坏”掉了。不匹配返回true	
						else if (inFile.fail())		cout << "Input terminated by data mismatch.\n";
				inFile.good();指出最后一次读取输入是否成功
						inFile >> value;
						while (inFile.good())
						{
							++count;
							sum += value;
							inFile >> value;
						}
				可替换为
						while（inFile >> value)
						{
							++count;
							sum += value;
						}
*/

/*	ostream类中的格式化方法
setf(ios_base::fixed);			//将对象置于使用定点表示法的模式
setf(ios_base::showpoint);		//将对象置于显示小数点的模式，即使小数部分为零
precision();					//指定显示多少位小数（假定对象处于定点模式下）
width();						//设置下一次输出操作使用的字段宽度，只在显示下一个值时有效，然后恢复到默认设置。

ios_base::fmtflags initial;					//ios_base::fmtflags是存储格式化设置信息的数据类型名称，initial存储初始的格式化设置
initial = os.setf(ios_base::fixed);
...
os.setf(initial);							//将各种设置恢复到原来的值

例子：
	using std::ios_base;

	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	.......
	.......
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
*/

/*
	循环中cin输入
cin >> ch;						//将忽略空格和换行符； 
cin.get(ch);					//即cin.get(char);格式，返回一个cin对象。
因此	while(cin)				//读取成功返回true，运行while；失败返回false,结束whlie.
进一步	whlie(cin.get(ch))
以前学过的
cin.get();						//接受一个换行符；
cin.get(name,20);				//往数组name中输入，不大于20的字符串；
检查文件尾EOF：
cin,eof();
cin.fail();正常结尾返回true，否则返回false
*/

/*		
	数组
struct inflatable
{
	char name[20];
	float volume;
	double price;
};
*/

/*
	指针
int* pn = new int;
delete pn;
char* pn = new char[10];
delete [] pn;
*/

/*	声明一个
指针数组				==			二维数组				==		string对象数组
char* pn[5] =		等同于		char pn[5][10] =		等同于		string pn[5] =
{						|		{							|		{
	"first",			|			"first",				|			"first",
	"second",			|			"second",				|			"second",
	"third",			|			"third",				|			"third",
	"fourth",			|			"fourth",				|			"fourth",
	"fifth"				|			"fifth"					|			"fifth"
};						|		};							|		};
*/

/*	const区别
int sloth = 16;
int gorp = 12;
const int * ps = &sloth;	  ·禁止修改ps指向的值		 * ps = 20;  ×
								而ps可以指向另一个变量	 ps = &gorp; √
int * const ps = &sloth;		ps可以用来修改指向的值	 * ps =	20;	 √
							  ·禁止改变ps指向别的变量	 ps = &gorp; ×
*/

/*	引用& 和 指针*的区别（何时用引用，何时用指针，何时按值传递）
一、函数使用传递的值，无需修改
对象很小：按值传递
	数组：指针，并声明为指向const的指针
	较大的结构：const指针或const引用，以提高效率
	类对象：const引用
二、函数要修改调用函数中的数据
对象是内置数据类型：指针
	  数组：指针
	  结构：指针或引用
	  类对象：引用
*/

/*	函数模板
template<typename AnyType>
template<class AnyType>			typename和class等价

函数模板无法处理数组 结构 指针等数据类型，因此要为特定的类型提供具体化模板定义，即显式具体化

*****显式具体化*****
template<> void Swap<job>(job &, job &);	//<job>可省略
template<> void Swap(job &, job &);			//不用Swap（）模板生成函数定义，而是用专门为int类型显示的定义的函数定义，因为这个原型有自己的函数定义。
void：函数类型	Swap：函数名	job：参数类型	（job &, jib &）：参数
具体化优先于常规模板；
非模板函数优先于具体化和常规模板。

*****显式实例化*****
template void Swap<int>(int,int);		   //使用Swap()模板生成int类型的函数定义	
void：函数类型	Swap：函数名	int：参数类型	（int,int）：参数

//与显式具体化不同！！！
*/

/*	头文件管理
1、头文件包含：函数原型
			使用#define或const定义的符号常量
			结构声明
			类声明
			模板声明
			内联函数inline
2、头文件用“”	#include"头文件名"
3、避免多次包含同一个头文件：#ifndef 头文件名	//if not define
							 #define 头文件名
							 ...
							 #endif
	仅当以前没有使用预处理器编译指令#define定义头文件名称时才处理#ifndef和#endif之间的语句
	此方法并不是防止编译器将文件包含两次，而只是让它忽略除第一次包含之外的所有内容
*/

/*		存储持续性——数据保留在内存中的时间长度
		作用域和链接——程序的哪一部分可以访问数据
一、自动存储持续性——自动变量：随函数开始和结束而增减，因此用栈来管理。LIFO
二、静态存储持续性——静态持续变量：
			1、外部链接性：在代码块外面声明它
						外部变量，又称全局变量
						定义声明（定义definition declarrtion) 给变量分配存储空间		//double up;	//definition,up is 0;
						引用声明（声明referencing declaration） 引用已有变量			//extern int blem;	//blem defined elsewhere;
					·引用声明使用关键字extern 且不进行初始化，否则声明为定义声明，导致分配存储空间。	//extern char gr = 'z';	//definition because initialized
						多文件中使用外部变量，一个文件中定义，其他文件中用extern声明即可。
						定义域全局变量同名的局部变量后，局部变量将隐藏全局变量，
					·但（::）作用域解析运算符将使用变量的全局版本。如cout << warming;显示为局部值， cout << :: warming;显示为全局变量值。
			2、内部链接性：在代码块外面声明它，并用static限定符
			3、无链接性：在代码块内声明它，并用static限定符
*/

/*	类
类声明：数据部分-数据成员；公有接口-成员函数（方法）
类方法定义：成员函数的实现
将接口（类定义）放在头文件中，将实现（类方法的代码）放在源代码文件中

1/定义类：（头文件中）
·关键字 class 指出代码定义了一个类设计
class XX
{
private:		//不必使用private，是类对象的默认访问控制。
	...
public:			//只需显示的使用public
	...
};
·关键字privata,public描述对类成员的访问控制。		//只能通过公有成员函数来访问对象的私有成员。防止程序直接访问数据被称为数据隐藏

2/实现类成员函数：（源代码文件中）
·定义成员函数时，使用作用域解析运算符（::）来标识函数所属的类。
·类方法（成员函数）可以访问类的private组件。

3/this指针

topval()方法比较两个对象
原型：	
const Stock & topval(const Stock & s) const;
说明：
topval()方法返回一个 const Stock & 类型的参数
对象一调用topval()方法，这个方法将对象二作为参数传递过来，即 const Stock & s
const Stock* top;
top = 对象1.topval(对象2)
三个const： 括号里的const表示函数不会修改被显式访问的对象（对象二），
			括号后面的const表示函数不会修改被隐式访问的对象（对象一），
			由于两个对象都是const，所以该函数返回一个const的引用（const Stock &），即第一个const

定义（实现）：	
const Stock & Stock::topval(const Stock & s) const
{
	if(s.total_val > total_val)
		return s;
	else
		return *this;
}
说明：
对象2用s来称呼，对象1用this这个特殊指针来称呼。this指针指向用来调用成员函数的对象（对象1）
this是对象1的地址，*this才是对象1本身。
返回类型为引用（const Stock &）意味着返回的是调用对象本身，而不是其副本。

4/类中的常量
不能直接在类中int 常量名 = 12;	这只是描述了对象的形式，没有创建对象。
·声明一个枚举	enum{常量名 = 12};
				double costs[常量名];
·关键字static  static const int 常量名 = 12;
				double costs[常量名];
*/

/*		使用类
一、重载
operator_()
例子：
	原型：	
		Time operator+(const Time& t) const;
	定义：
		Time Time::operator+(const Time& t) const			//返回对象不能是引用，因为这是个局部变量/临时变量，引用将指向不存在的数据。而返回Sum则是创建一个拷贝，调用的函数将得到这个拷贝。
		{
			Time sum;
			sum.minutes = minutes + t.minutes;
			sum.hours = hours + t.hours + sum.minutes / 60;
			sum.minutes %= 60;
			return sum;
		}
	用法：
		cout << "total work time = ";
		total = weeding + waxing;
		total.Show();
		cout << endl;
二、友元
背景：·问题一：一般重载将 A = B * 2.75; 转换成A = B.operator*(2.75);
			    但是若 A = 2.75 * B； 则转换失败。
	  ·方案：而用非成员函数 Time operator*(double m, const Time & t);
			  则转换成 A = operator*(2.75, B);
	  ·问题二：但非成员函数无法访问类（Time)的私有数据。
	  ·方案：友元。将原型放置在类声明中
关键字：friend
声明：friend Time operator*(double m, const Time & t);
*/