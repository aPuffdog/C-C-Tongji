// 2252902 ������
/*
������
���ݳ�Ա��x, y
������Ա�����캯�� Point, printPoint, dictaPoint
*/

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
	double x, y;
public:
	Point(double x1, double y1)
	{ x = x1; y = y1; }
	void printPoint()
	{ cout << "x = " << x << "\ty = " << y << endl; }
	double dictaPoint(Point p)
	{ return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y)); }
};

int main()
{
	double x, y;
	cout << "�������һ����� x, y ���꣺���ÿո������" << endl;
	cin >> x >> y;
	Point p1(x, y);
	cout << "������ڶ������ x, y ���꣺���ÿո������" << endl;
	cin >> x >> y;
	Point p2(x, y);
	cout << "\n�ҽ�����������������Ϣ��" << endl;
	p1.printPoint();
	p2.printPoint(); // �ⲻ�� python��������()
	cout << "\n���� p1 �� p2 �ľ��룺" << p1.dictaPoint(p2) << endl; 
	return 0;
}
