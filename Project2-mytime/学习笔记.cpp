//#include<iostream>		iosteram --> std::cout<<..... / using std::cout / using namespace std;
/*
#include<cstdlib>		exit();		exit(EXIT_FAILURE);
#include<cmath>			sqrt().....
#include<climits>		һЩ���ų�����ʾ���͵�������Ϣ
#include<string>		string�࣬string str1 = "�ַ�������";
#include<cstring>		�ṩ�ַ�����غ�������:
						strlen()ȷ���ַ�������;	int len1 = str1.size()��string����󳤶ȣ�
												int len2 = strlen(ch)����ͨ�ַ�����cstring�ַ�����غ������󳤶�
												getline(cin,str);��string������룻
												cin.getline(ch,20);����ͨ�ַ��������룻
						strcpy(1,2)����;
						strcat(1.2)��2����1����;
						strcmp("1","2");�Ƚ������ַ�������ͬ����0������ĸ����1��2ǰ���ظ�����1��2�󷵻�������
#include<cctype>		isalpha(ch);ch����ĸ�����ط���ֵ�����򷵻�0.
						ispunct(ch);ch�Ǳ�����,����true.
						isdigits();����Ƿ�������
						isspace();����Ƿ��ǿհ�(�绻�з� �ո� �Ʊ����
*/
/*#include<fstream>			for file I/O �ļ��������
							ofstream����Ҫ�������������ļ���������coutһ��ʹ������
								���ļ��������(�ļ�������Ļ�����						���ļ��������루�ļ����Ƽ��̣�
							������													
								ofstream outFile;							|			ifstream inFile;
								ofstream fout;								|			ifstream fin;
							�����ļ���										|
								outFile.open("fish.txt");					|			inFile.open("bowling.txt");
																			|
								char filename[50];							|			char filename[50];
								cin >> filename;							|			cin >> filename;
								fout.open(filename);						|			fin.open(filename);
							ʹ�ã�											|
								double wt = 125.8;							|			double wt;
								outFile << wt;		//��fish.txt��д��wt��	|			inFile >> wt;		//��bowling.txt���ȡһ�����ֵ�wt
																			|
								char line[81] = "һ���ַ� ������"��			|			char line[81];
								fout << line <<endl��						|			fin.getline(line,81);
is_open()	����ļ��Ƿ񱻳ɹ��򿪣� good() Ҳ���ԡ�  ��:�ļ���ΪinFile.   inFile.is_open();inFile.good();
����ļ�βEOF	inFile.eof();�ж��Ƿ񵽴��ļ�ĩβEOF�����ﷵ��true
						if (inFile.eof())	cout << "End of file reached.\n";
				inFile.fail();�ж�EOF������ƥ�䲻ƥ�䣬����һ�����Ƿ񡰻������ˡ���ƥ�䷵��true	
						else if (inFile.fail())		cout << "Input terminated by data mismatch.\n";
				inFile.good();ָ�����һ�ζ�ȡ�����Ƿ�ɹ�
						inFile >> value;
						while (inFile.good())
						{
							++count;
							sum += value;
							inFile >> value;
						}
				���滻Ϊ
						while��inFile >> value)
						{
							++count;
							sum += value;
						}
*/

/*	ostream���еĸ�ʽ������
setf(ios_base::fixed);			//����������ʹ�ö����ʾ����ģʽ
setf(ios_base::showpoint);		//������������ʾС�����ģʽ����ʹС������Ϊ��
precision();					//ָ����ʾ����λС�����ٶ������ڶ���ģʽ�£�
width();						//������һ���������ʹ�õ��ֶο�ȣ�ֻ����ʾ��һ��ֵʱ��Ч��Ȼ��ָ���Ĭ�����á�

ios_base::fmtflags initial;					//ios_base::fmtflags�Ǵ洢��ʽ��������Ϣ�������������ƣ�initial�洢��ʼ�ĸ�ʽ������
initial = os.setf(ios_base::fixed);
...
os.setf(initial);							//���������ûָ���ԭ����ֵ

���ӣ�
	using std::ios_base;

	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	.......
	.......
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
*/

/*
	ѭ����cin����
cin >> ch;						//�����Կո�ͻ��з��� 
cin.get(ch);					//��cin.get(char);��ʽ������һ��cin����
���	while(cin)				//��ȡ�ɹ�����true������while��ʧ�ܷ���false,����whlie.
��һ��	whlie(cin.get(ch))
��ǰѧ����
cin.get();						//����һ�����з���
cin.get(name,20);				//������name�����룬������20���ַ�����
����ļ�βEOF��
cin,eof();
cin.fail();������β����true�����򷵻�false
*/

/*		
	����
struct inflatable
{
	char name[20];
	float volume;
	double price;
};
*/

/*
	ָ��
int* pn = new int;
delete pn;
char* pn = new char[10];
delete [] pn;
*/

/*	����һ��
ָ������				==			��ά����				==		string��������
char* pn[5] =		��ͬ��		char pn[5][10] =		��ͬ��		string pn[5] =
{						|		{							|		{
	"first",			|			"first",				|			"first",
	"second",			|			"second",				|			"second",
	"third",			|			"third",				|			"third",
	"fourth",			|			"fourth",				|			"fourth",
	"fifth"				|			"fifth"					|			"fifth"
};						|		};							|		};
*/

/*	const����
int sloth = 16;
int gorp = 12;
const int * ps = &sloth;	  ����ֹ�޸�psָ���ֵ		 * ps = 20;  ��
								��ps����ָ����һ������	 ps = &gorp; ��
int * const ps = &sloth;		ps���������޸�ָ���ֵ	 * ps =	20;	 ��
							  ����ֹ�ı�psָ���ı���	 ps = &gorp; ��
*/

/*	����& �� ָ��*�����𣨺�ʱ�����ã���ʱ��ָ�룬��ʱ��ֵ���ݣ�
һ������ʹ�ô��ݵ�ֵ�������޸�
�����С����ֵ����
	���飺ָ�룬������Ϊָ��const��ָ��
	�ϴ�Ľṹ��constָ���const���ã������Ч��
	�����const����
��������Ҫ�޸ĵ��ú����е�����
�����������������ͣ�ָ��
	  ���飺ָ��
	  �ṹ��ָ�������
	  ���������
*/

/*	����ģ��
template<typename AnyType>
template<class AnyType>			typename��class�ȼ�

����ģ���޷��������� �ṹ ָ����������ͣ����ҪΪ�ض��������ṩ���廯ģ�嶨�壬����ʽ���廯

*****��ʽ���廯*****
template<> void Swap<job>(job &, job &);	//<job>��ʡ��
template<> void Swap(job &, job &);			//����Swap����ģ�����ɺ������壬������ר��Ϊint������ʾ�Ķ���ĺ������壬��Ϊ���ԭ�����Լ��ĺ������塣
void����������	Swap��������	job����������	��job &, jib &��������
���廯�����ڳ���ģ�壻
��ģ�庯�������ھ��廯�ͳ���ģ�塣

*****��ʽʵ����*****
template void Swap<int>(int,int);		   //ʹ��Swap()ģ������int���͵ĺ�������	
void����������	Swap��������	int����������	��int,int��������

//����ʽ���廯��ͬ������
*/

/*	ͷ�ļ�����
1��ͷ�ļ�����������ԭ��
			ʹ��#define��const����ķ��ų���
			�ṹ����
			������
			ģ������
			��������inline
2��ͷ�ļ��á���	#include"ͷ�ļ���"
3�������ΰ���ͬһ��ͷ�ļ���#ifndef ͷ�ļ���	//if not define
							 #define ͷ�ļ���
							 ...
							 #endif
	������ǰû��ʹ��Ԥ����������ָ��#define����ͷ�ļ�����ʱ�Ŵ���#ifndef��#endif֮������
	�˷��������Ƿ�ֹ���������ļ��������Σ���ֻ���������Գ���һ�ΰ���֮�����������
*/

/*		�洢�����ԡ������ݱ������ڴ��е�ʱ�䳤��
		����������ӡ����������һ���ֿ��Է�������
һ���Զ��洢�����ԡ����Զ��������溯����ʼ�ͽ����������������ջ������LIFO
������̬�洢�����ԡ�����̬����������
			1���ⲿ�����ԣ��ڴ��������������
						�ⲿ�������ֳ�ȫ�ֱ���
						��������������definition declarrtion) ����������洢�ռ�		//double up;	//definition,up is 0;
						��������������referencing declaration�� �������б���			//extern int blem;	//blem defined elsewhere;
					����������ʹ�ùؼ���extern �Ҳ����г�ʼ������������Ϊ�������������·���洢�ռ䡣	//extern char gr = 'z';	//definition because initialized
						���ļ���ʹ���ⲿ������һ���ļ��ж��壬�����ļ�����extern�������ɡ�
						������ȫ�ֱ���ͬ���ľֲ������󣬾ֲ�����������ȫ�ֱ�����
					������::������������������ʹ�ñ�����ȫ�ְ汾����cout << warming;��ʾΪ�ֲ�ֵ�� cout << :: warming;��ʾΪȫ�ֱ���ֵ��
			2���ڲ������ԣ��ڴ��������������������static�޶���
			3���������ԣ��ڴ������������������static�޶���
*/

/*	��
�����������ݲ���-���ݳ�Ա�����нӿ�-��Ա������������
�෽�����壺��Ա������ʵ��
���ӿڣ��ඨ�壩����ͷ�ļ��У���ʵ�֣��෽���Ĵ��룩����Դ�����ļ���

1/�����ࣺ��ͷ�ļ��У�
���ؼ��� class ָ�����붨����һ�������
class XX
{
private:		//����ʹ��private����������Ĭ�Ϸ��ʿ��ơ�
	...
public:			//ֻ����ʾ��ʹ��public
	...
};
���ؼ���privata,public���������Ա�ķ��ʿ��ơ�		//ֻ��ͨ�����г�Ա���������ʶ����˽�г�Ա����ֹ����ֱ�ӷ������ݱ���Ϊ��������

2/ʵ�����Ա��������Դ�����ļ��У�
�������Ա����ʱ��ʹ������������������::������ʶ�����������ࡣ
���෽������Ա���������Է������private�����

3/thisָ��

topval()�����Ƚ���������
ԭ�ͣ�	
const Stock & topval(const Stock & s) const;
˵����
topval()��������һ�� const Stock & ���͵Ĳ���
����һ����topval()����������������������Ϊ�������ݹ������� const Stock & s
const Stock* top;
top = ����1.topval(����2)
����const�� �������const��ʾ���������޸ı���ʽ���ʵĶ��󣨶��������
			���ź����const��ʾ���������޸ı���ʽ���ʵĶ��󣨶���һ����
			��������������const�����Ըú�������һ��const�����ã�const Stock &��������һ��const

���壨ʵ�֣���	
const Stock & Stock::topval(const Stock & s) const
{
	if(s.total_val > total_val)
		return s;
	else
		return *this;
}
˵����
����2��s���ƺ�������1��this�������ָ�����ƺ���thisָ��ָ���������ó�Ա�����Ķ��󣨶���1��
this�Ƕ���1�ĵ�ַ��*this���Ƕ���1����
��������Ϊ���ã�const Stock &����ζ�ŷ��ص��ǵ��ö������������丱����

4/���еĳ���
����ֱ��������int ������ = 12;	��ֻ�������˶������ʽ��û�д�������
������һ��ö��	enum{������ = 12};
				double costs[������];
���ؼ���static  static const int ������ = 12;
				double costs[������];
*/

/*		ʹ����
һ������
operator_()
���ӣ�
	ԭ�ͣ�	
		Time operator+(const Time& t) const;
	���壺
		Time Time::operator+(const Time& t) const			//���ض����������ã���Ϊ���Ǹ��ֲ�����/��ʱ���������ý�ָ�򲻴��ڵ����ݡ�������Sum���Ǵ���һ�����������õĺ������õ����������
		{
			Time sum;
			sum.minutes = minutes + t.minutes;
			sum.hours = hours + t.hours + sum.minutes / 60;
			sum.minutes %= 60;
			return sum;
		}
	�÷���
		cout << "total work time = ";
		total = weeding + waxing;
		total.Show();
		cout << endl;
������Ԫ
������������һ��һ�����ؽ� A = B * 2.75; ת����A = B.operator*(2.75);
			    ������ A = 2.75 * B�� ��ת��ʧ�ܡ�
	  �����������÷ǳ�Ա���� Time operator*(double m, const Time & t);
			  ��ת���� A = operator*(2.75, B);
	  ������������ǳ�Ա�����޷������ࣨTime)��˽�����ݡ�
	  ����������Ԫ����ԭ�ͷ�������������
�ؼ��֣�friend
������friend Time operator*(double m, const Time & t);
*/