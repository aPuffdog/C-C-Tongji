// 2252902 ������
// ����ѧ��һѧ�� C++������ C++ �����ļ�����ȫ�������� C++ д��������ļ���ϰ��
// ��Ϊ�ľ��˿����ܶ�����ͨ��ճ���������ж�����
// �����������ģ���Ϊ ANSI ������� GBK
// ����ƣ�����룬���Ը���ĩβ������������в���

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "������һ���ַ�" << endl;
    getline(cin, s);
    ofstream out("text.txt"); // ��д��ʽ��
    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf()); // ��������ļ�
    int i = 0;
    while (s[i] != '\0')
        i++;
    i--;
    for (; i>=0; i--) // �����ͬʱ���
        cout << s[i];
    for (i = 0; s[i] != '\0'; i++)
        cout << s[i];
    cout.rdbuf(coutbuf); // ���������Ļ
    cout << "����������鿴 text.txt �ĵ�" << endl;
    return 0;
}

/*
�������룺
A man, a plan, a canal, Panama!
*/

/*
���������
!amanaP ,lanac a ,nalp a ,nam AA man, a plan, a canal, Panama!
*/

/*
Ц���ˣ����Ǻ���Ȥ���ڹ�����Ҳ��������һ�����ľ䣬������Ա������ͬ��
!!!amanaplanacanalpanama!!!
��ĺ���Ȥ
*/