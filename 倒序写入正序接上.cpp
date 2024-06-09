// 2252902 赵梓成
// 我们学了一学期 C++，而且 C++ 处理文件更安全，还是用 C++ 写法来完成文件练习吧
// 因为阅卷人看不很懂可以通过粘贴运行来判定分数
// 请勿输入中文，因为 ANSI 编码而非 GBK
// 若你疲于输入，可以复制末尾的样例输入进行测试

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "请输入一串字符" << endl;
    getline(cin, s);
    ofstream out("f1.txt"); // 书写方式打开
    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf()); // 输出定向到文件
    int i = 0;
    while (s[i] != '\0')
        i++;
    i--;
    for (; i>=0; i--) // 处理的同时输出
        cout << s[i];
    for (i = 0; s[i] != '\0'; i++)
        cout << s[i];
    cout.rdbuf(coutbuf); // 输出定向到屏幕
    cout << "完成输出，请查看 text.txt 文档" << endl;
    return 0;
}

/*
样例输入：
A man, a plan, a canal, Panama!
*/

/*
样例输出：
!amanaP ,lanac a ,nalp a ,nam AA man, a plan, a canal, Panama!
*/

/*
笑死了，这是很有趣，在国际上也很有名的一个回文句，反向忽略标点是相同的
!!!amanaplanacanalpanama!!!
真的很有趣
*/
