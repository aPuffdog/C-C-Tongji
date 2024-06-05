// 2252902 赵梓成
// 将从键盘输入的N个学生的学号和成绩存入到文件student.dat中。
// 再从文件中读取学生的信息，求出最高分、最低分和总分。N可通过符号常量自行定义大小

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	int N, score;
	string num;
	cout << "输入你将要输入学生的数量（小于100）：" << endl;
	cin >> N;
	cout << "请逐行输入学生的学号和成绩：" << endl;

	ofstream out("student.dat");
	streambuf* coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	ifstream in("student.dat");
	streambuf* cinbuf = cin.rdbuf();

	int n = N;

	while (n--)
	{
		cin >> num >> score;
		cout << num << " " << score << endl;
	}

	cout.rdbuf(coutbuf);
	cout << "现已经完成存储，开始进行读取和分析：\n" << endl;

	cin.rdbuf(in.rdbuf());
	
	n = N;

	int minS = 151, maxS = -1;
	double ave = 0;
	string minNum = "", maxNum = "";

	while (n--)
	{
		cin >> num >> score;
		if (minS > score)
		{
			minS = score;
			minNum = num;
		}
		if (maxS < score)
		{
			maxS = score;
			maxNum = num;
		}
		ave += score;
	}
	ave = ave / N;

	cout << "最高分是 " << maxNum << " 同学" << " 分数为:" << maxS << endl;
	cout << "最低分是 " << minNum << " 同学" << " 分数为:" << minS << endl;
	cout << "平均分是 " << setprecision(4) << ave << endl;

	return 0;
}

/*
样例输入：
10
2023001 85
2023002 90
2023003 78
2023004 88
2023005 92
2023006 76
2023007 95
2023008 84
2023009 80
2023010 89
*/

/*
样例输出：
最高分是 2023007 同学 分数为:95
最低分是 2023006 同学 分数为:76
平均分是 85.7
*/