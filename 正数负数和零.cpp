// 2252902 ������
// ����ѧ��һѧ�� C++������ C++ �����ļ�����ȫ�������� C++ д��������ļ���ϰ��
// ����ľ��˿����ܶ�����ͨ��ճ���������ж�����

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in("text.txt");
    streambuf* cinbuf = cin.rdbuf();
    cin.rdbuf(in.rdbuf());
    int n, po = 0, ne = 0, ze = 0;
    while (cin >> n) // ��Ŀ��ʾ��˵������ fscanf �Ҳ���ϣ��ʹ�� != EOF ���ж���ʽ������cpp������ô�鷳��
    {
        if (n > 0)
            po++;
        else if (n == 0)
            ze++;
        else
            ne++;
    }
    cout << "��������Ϊ��" << po << "\n��������Ϊ��" << ne << "\n��ĸ���Ϊ��" << ze;
    return 0;
}
