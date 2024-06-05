// 2252902 赵梓成 
// 如果你疲于输入测试内容，可以复制代码下方注释部分的样例输入进行测试

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct node
{
    string name, num;
    int wage = 0, no = 0; // no 是额外的一个编号，这样便于用户操作删除
    node* next = NULL;
};

node *nodCreat(int n)
{
    node* head = NULL;
    node* tail = NULL, * newnode = NULL;
    string name, num;
    int no = 0, wage;
    while (n--)
    {
        no++;
        cin >> num >> name >> wage;
        newnode = new node;
        newnode->name = name;
        newnode->num = num;
        newnode->wage = wage;
        newnode->no = no; // 这是额外的一个编号，这样便于用户操作删除
        if (head == NULL)
            head = newnode;
        else
            tail->next = newnode;
        tail = newnode;
    }
    return head;
}

void nodPrint(node* head)
{
    node* p = head;
    int no = 1;
    
    cout << "\n当前的链表状态为:\n编号" << "\t" << "工号" << "\t" << "姓名" << "\t" << "工资" << endl;
    while (p != NULL)
    {
        p->no = no; // 每次输出伴随重置编号
        cout << p->no << "\t" << p->num << "\t" << p->name << "\t" << p->wage << endl;
        p = p->next;
        no++;
    }
}

node *nodDelete(node* head, int n) // 其实可以直接一个循环的计数找到目标，但是没意思，我想实现书上案例那个哈哈哈哈
{
    node* p = head, * q = NULL;
    if (p == NULL)
        cout << "BUG: 链表为空!!!"<<endl; // 虽然不可能出现就是了，但是以后可以抄代码复用
    else
    {
        while (p != NULL && p->no != n) // 找到目标结点后退出循环
        {
            q = p;
            p = p->next;
        }
        // cout << "p停下时，no为：" << p->no << endl; // debug 语句，提交前删除
        if (p == head)
        {
            head = p->next;
            delete p;
        }
        else if (p != NULL)
        {
            q->next = p->next;   // q --- p --- p->next
            delete p;            //    ------->
        }
        else
            cout << "没有找到指定的编号" << endl;
    }
    cout << "已完成删除函数运行" << endl;
    return head;
}

node* nodEdit(node* head, string num, int wage)
{
    node* p = head;
    while (p != NULL && p->num != num) // 将工作指针移到对象上方
        p = p->next;
    if (p != NULL)
        p->wage = wage;
    else
        cout << "BUG: 或许工号输入错误，请检查" << endl;
    cout << "已完成更改函数运行" << endl;
    return head;
}

int main()
{
    int n, Ewage;
    string num;
    node* head;
    cout << "输入一个整数，这是你将要输入的职工信息的条数：" << endl;
    cin >> n;
    cout << "逐行输入职工信息：工号 姓名 工资" << endl;
    head = nodCreat(n);
    nodPrint(head); // 显示当前的链表状态
    cout << "\n请输入你将删除的员工的链表编号（第一列的那个）：" << endl;
    cin >> n;
    head = nodDelete(head, n);
    nodPrint(head); // 再次显示当前的链表状态
    cout << "\n请输入你想要更改工资的员工工号（第二列那个），以及更改后的工资：" << endl;
    cin >> num >> Ewage;
    head = nodEdit(head, num, Ewage);
    nodPrint(head); // again, 再次显示当前的链表状态
    return 0;
}


/*
样例输入：
5
2352983 褚光 7650
2352779 陈华 5282
2351216 孙伟 9316
2350466 郑芳 7524
2352110 卫洋 5830
4
2351216 0
*/

/*
样例输出：

当前的链表状态为:
编号    工号    姓名    工资
1       2352983 褚光    7650
2       2352779 陈华    5282
3       2351216 孙伟    9316
4       2350466 郑芳    7524
5       2352110 卫洋    5830

已完成删除函数运行

当前的链表状态为:
编号    工号    姓名    工资
1       2352983 褚光    7650
2       2352779 陈华    5282
3       2351216 孙伟    9316
4       2352110 卫洋    5830

已完成更改函数运行

当前的链表状态为:
编号    工号    姓名    工资
1       2352983 褚光    7650
2       2352779 陈华    5282
3       2351216 孙伟    0
4       2352110 卫洋    5830
*/