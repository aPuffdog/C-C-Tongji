// 2252902 ������
// ���Ӽ��������N��ѧ����ѧ�źͳɼ����뵽�ļ�student.dat�С�
// �ٴ��ļ��ж�ȡѧ������Ϣ�������߷֡���ͷֺ��ܷ֡�N��ͨ�����ų������ж����С

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	int N, score;
	string num;
	cout << "�����㽫Ҫ����ѧ����������С��100����" << endl;
	cin >> N;
	cout << "����������ѧ����ѧ�źͳɼ���" << endl;

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
	cout << "���Ѿ���ɴ洢����ʼ���ж�ȡ�ͷ�����\n" << endl;

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

	cout << "��߷��� " << maxNum << " ͬѧ" << " ����Ϊ:" << maxS << endl;
	cout << "��ͷ��� " << minNum << " ͬѧ" << " ����Ϊ:" << minS << endl;
	cout << "ƽ������ " << setprecision(4) << ave << endl;

	return 0;
}

/*
�������룺
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
���������
��߷��� 2023007 ͬѧ ����Ϊ:95
��ͷ��� 2023006 ͬѧ ����Ϊ:76
ƽ������ 85.7
*/