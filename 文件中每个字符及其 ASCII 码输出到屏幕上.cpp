// 2252902 赵梓成
// 我们学了一学期 C++，而且 C++ 处理文件更安全，还是用 C++ 写法来完成文件练习吧
// 因为阅卷人看不很懂可以通过粘贴运行来判定分数
// 请勿输入中文，因为 ANSI 编码而非 GBK

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string s;
    ifstream in("input.txt");
    cout << "我们将读取.cpp文件的目录下的input.txt，将其对应ascii码标注并输出到屏幕:\n" << endl;
    streambuf* cinbuf = cin.rdbuf(); // 备份旧的buf
    cin.rdbuf(in.rdbuf()); // 重定向cout到文件，注意写法，很容易把 out.rdbuf() 的括号写掉
    getline(cin, s); // 使用 getline，因为不能因为空格停下
    for (int i = 0; s[i] != '\0'; i++)
        cout << s[i] << "(" << int(s[i]) << ")";
    cin.rdbuf(cinbuf); // 归还我们偷换的buf
    cout << "\n\n完成输出" << endl;
    return 0;
}

/*
输入示例：
I love China!

输出示例：
I(73) (32)l(108)o(111)v(118)e(101) (32)C(67)h(104)i(105)n(110)a(97)!(33)
*/