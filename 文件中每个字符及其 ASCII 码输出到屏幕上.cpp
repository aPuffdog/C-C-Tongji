// 2252902 ������
// ����ѧ��һѧ�� C++������ C++ �����ļ�����ȫ�������� C++ д��������ļ���ϰ��
// ��Ϊ�ľ��˿����ܶ�����ͨ��ճ���������ж�����
// �����������ģ���Ϊ ANSI ������� GBK

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string s;
    ifstream in("input.txt");
    cout << "���ǽ���ȡ.cpp�ļ���Ŀ¼�µ�input.txt�������Ӧascii���ע���������Ļ:\n" << endl;
    streambuf* cinbuf = cin.rdbuf(); // ���ݾɵ�buf
    cin.rdbuf(in.rdbuf()); // �ض���cout���ļ���ע��д���������װ� out.rdbuf() ������д��
    getline(cin, s); // ʹ�� getline����Ϊ������Ϊ�ո�ͣ��
    for (int i = 0; s[i] != '\0'; i++)
        cout << s[i] << "(" << int(s[i]) << ")";
    cin.rdbuf(cinbuf); // �黹����͵����buf
    cout << "\n\n������" << endl;
    return 0;
}

/*
����ʾ����
I love China!

���ʾ����
I(73) (32)l(108)o(111)v(118)e(101) (32)C(67)h(104)i(105)n(110)a(97)!(33)
*/