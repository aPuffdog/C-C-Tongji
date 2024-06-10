// 2252902 赵梓成
/*
分析：
数据成员：x, y
函数成员：构造函数 Point, printPoint, dictaPoint
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
	cout << "请输入第一个点的 x, y 坐标：（用空格隔开）" << endl;
	cin >> x >> y;
	Point p1(x, y);
	cout << "请输入第二个点的 x, y 坐标：（用空格隔开）" << endl;
	cin >> x >> y;
	Point p2(x, y);
	cout << "\n我将向你输出两个点的信息：" << endl;
	p1.printPoint();
	p2.printPoint(); // 这不是 python，别忘了()
	cout << "\n计算 p1 到 p2 的距离：" << p1.dictaPoint(p2) << endl; 
	return 0;
}
