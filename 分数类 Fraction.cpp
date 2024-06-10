// 2252902 ������

#include<iostream>
using namespace std;

class Franction
{
	int fz, fm;
public:
	Franction(int fz1 = 1, int fm1 = 1)
	{
		fz = fz1;
		fm = fm1;
	}
	void print()
	{
		cout << fz << "/" << fm << endl;
	}
	void Reduction()
	{
		int tempfz = fz, tempfm = fm, temp;
		while (tempfz != tempfm)
		{
			if (tempfz < tempfm)
			{
				temp = tempfz;
				tempfz = tempfm;
				tempfm = temp;
			}
			tempfz = tempfz - tempfm;
		}
		fz /= tempfz;
		fm /= tempfz;
	}
};

int main()
{
	int x1, y1;
	cout << "�������һ�������ķ��Ӻͷ�ĸ��" << endl;
	cin >> x1 >> y1;
	Franction F1(x1, y1);
	cout << "������ڶ��������ķ��Ӻͷ�ĸ��" << endl;
	cin >> x1 >> y1;
	Franction F2(x1, y1);
	cout << "Լ��ǰչʾ��" << endl;
	F1.print();
	F2.print();
	F1.Reduction();
	F2.Reduction();
	cout << "Լ�ֺ�չʾ��" << endl;
	F1.print();
	F2.print();
	return 0;
}

/*
�������룺
12 24
45 30
*/

/*
���������
�������һ�������ķ��Ӻͷ�ĸ��
12 24
������ڶ��������ķ��Ӻͷ�ĸ��
45 30
Լ��ǰչʾ��
12/24
45/30
Լ�ֺ�չʾ��
1/2
3/2
*/