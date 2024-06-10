// 2252902 赵梓成

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
		// 介于题目严格要求不能使用字符串连接函数，我将以C风格进行手动书写字符串连接，虽然这是愚蠢的
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
		// 介于题目严格要求不能使用字符串连接函数，我将以C风格进行手动书写字符串连接，虽然这是愚蠢的
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
	string s11, s12, s13; // 太幽默了，就作为一个练习罢
	cout << "请给出三个字符串，我们将存储在 s1, s2, s3 中：" << endl;
	cin >> s11 >> s12 >> s13;
	Mystring s1(s11);
	Mystring s2(s12);
	Mystring s3(s13);
	cout << "\n调用输出函数进行输出：" << endl;
	s1.printMystring();
	s2.printMystring();
	s3.printMystring();
	cout << "\n字符串的长度分别为：" << endl;
	cout << s1.lenMystring() << " " << s2.lenMystring() << " " << s3.lenMystring() << endl;
	cout << "\n使用连接函数连接 s1 和 s2：" << endl;
	cout << s1.connectMystring(s2) << endl;
	cout << "\n使用static加持的函数连接 s2 和 s3：" << endl;
	cout << Mystring::connection(s2, s3) << endl;
	return 0;
}