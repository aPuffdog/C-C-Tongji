// 2252902 赵梓成

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
	cout << "请输入第一个分数的分子和分母：" << endl;
	cin >> x1 >> y1;
	Franction F1(x1, y1);
	cout << "请输入第二个分数的分子和分母：" << endl;
	cin >> x1 >> y1;
	Franction F2(x1, y1);
	cout << "约分前展示：" << endl;
	F1.print();
	F2.print();
	F1.Reduction();
	F2.Reduction();
	cout << "约分后展示：" << endl;
	F1.print();
	F2.print();
	return 0;
}

/*
样例输入：
12 24
45 30
*/

/*
样例输出：
请输入第一个分数的分子和分母：
12 24
请输入第二个分数的分子和分母：
45 30
约分前展示：
12/24
45/30
约分后展示：
1/2
3/2
*/