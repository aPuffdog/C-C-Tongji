// 2252902 ������

#include <iostream>
#include <cstring>
using namespace std;

class Mystring
{
	string str;
public:
	Mystring(string str1)
	{
		str = str1;
	}
	void setMystring(string str1)
	{
		str = str1;
	}
	void printMystring()
	{
		cout << str << endl;
	}
	int lenMystring()
	{
		int i = 0;
		for (i = 0; str[i] != '\0'; i++)
			continue;
		return i;
	}
	string connectMystring(Mystring str1)
	{
		char newString[101];
		// ������Ŀ�ϸ�Ҫ����ʹ���ַ������Ӻ������ҽ���C�������ֶ���д�ַ������ӣ���Ȼ�����޴���
		int Ptr1 = 0, Ptr2 = 0;
		while (str[Ptr1] != '\0')
		{
			newString[Ptr1] = str[Ptr1];
			Ptr1++;
		}
		while (str[Ptr2] != '\0')
		{
			newString[Ptr1] = str1.str[Ptr2];
			Ptr1++;
			Ptr2++;
		}
		newString[Ptr1] = '\0';
		return newString;
	}
	static string connection(Mystring str1, Mystring str2)
	{
		char newString[101];
		// ������Ŀ�ϸ�Ҫ����ʹ���ַ������Ӻ������ҽ���C�������ֶ���д�ַ������ӣ���Ȼ�����޴���
		int Ptr1 = 0, Ptr2 = 0;
		while (str1.str[Ptr1] != '\0')
		{
			newString[Ptr1] = str1.str[Ptr1];
			Ptr1++;
		}
		while (str2.str[Ptr2] != '\0')
		{
			newString[Ptr1] = str2.str[Ptr2];
			Ptr1++;
			Ptr2++;
		}
		newString[Ptr1] = '\0';
		return newString;
	}
};


int main()
{
	string s11, s12, s13; // ̫��Ĭ�ˣ�����Ϊһ����ϰ��
	cout << "����������ַ��������ǽ��洢�� s1, s2, s3 �У�" << endl;
	cin >> s11 >> s12 >> s13;
	Mystring s1(s11);
	Mystring s2(s12);
	Mystring s3(s13);
	cout << "\n��������������������" << endl;
	s1.printMystring();
	s2.printMystring();
	s3.printMystring();
	cout << "\n�ַ����ĳ��ȷֱ�Ϊ��" << endl;
	cout << s1.lenMystring() << " " << s2.lenMystring() << " " << s3.lenMystring() << endl;
	cout << "\nʹ�����Ӻ������� s1 �� s2��" << endl;
	cout << s1.connectMystring(s2) << endl;
	cout << "\nʹ��static�ӳֵĺ������� s2 �� s3��" << endl;
	cout << Mystring::connection(s2, s3) << endl;
	return 0;
}