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
	static int num_strings;					//��̬���Ա�����۴������ٶ��󣬳���ֻ����һ����̬�����������������������󶼾�����ֵͬ�������������Ƿǳ������
	static const int CINLIM = 80;			//������ֻ������η����ڴ棬�������з��䡣�����������н��г�ʼ��
public:
	String(const char* s);			//���캯��
	String();						//Ĭ�Ϲ��캯��
	String(const String& st);		//���ƹ��캯��
	~String();
	int length() const { return len; }

	String& operator=(const String&);			//��ȸ��� ��ֵ�����,һ������󸳸���һ��
	String& operator=(const char*);				//һ��char�ַ������������
	char& operator[](int i);					//���Զ�д����String����
	const char& operator[](int i) const;		//ֻ�ܶ�constString���󣬲���д

	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend istream& operator>>(istream& is, String& st);
	friend ostream& operator<<(ostream& os, const String& st);

	static int HowMany();
};
#endif