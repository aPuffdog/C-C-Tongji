// 2252902 ������ 
// �����ƣ������������ݣ����Ը��ƴ����·�ע�Ͳ��ֵ�����������в���

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct node
{
    string name, num;
    int wage = 0, no = 0; // no �Ƕ����һ����ţ����������û�����ɾ��
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
        newnode->no = no; // ���Ƕ����һ����ţ����������û�����ɾ��
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
    
    cout << "\n��ǰ������״̬Ϊ:\n���" << "\t" << "����" << "\t" << "����" << "\t" << "����" << endl;
    while (p != NULL)
    {
        p->no = no; // ÿ������������ñ��
        cout << p->no << "\t" << p->num << "\t" << p->name << "\t" << p->wage << endl;
        p = p->next;
        no++;
    }
}

node *nodDelete(node* head, int n) // ��ʵ����ֱ��һ��ѭ���ļ����ҵ�Ŀ�꣬����û��˼������ʵ�����ϰ����Ǹ���������
{
    node* p = head, * q = NULL;
    if (p == NULL)
        cout << "BUG: ����Ϊ��!!!"<<endl; // ��Ȼ�����ܳ��־����ˣ������Ժ���Գ����븴��
    else
    {
        while (p != NULL && p->no != n) // �ҵ�Ŀ������˳�ѭ��
        {
            q = p;
            p = p->next;
        }
        // cout << "pͣ��ʱ��noΪ��" << p->no << endl; // debug ��䣬�ύǰɾ��
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
            cout << "û���ҵ�ָ���ı��" << endl;
    }
    cout << "�����ɾ����������" << endl;
    return head;
}

node* nodEdit(node* head, string num, int wage)
{
    node* p = head;
    while (p != NULL && p->num != num) // ������ָ���Ƶ������Ϸ�
        p = p->next;
    if (p != NULL)
        p->wage = wage;
    else
        cout << "BUG: �����������������" << endl;
    cout << "����ɸ��ĺ�������" << endl;
    return head;
}

int main()
{
    int n, Ewage;
    string num;
    node* head;
    cout << "����һ�������������㽫Ҫ�����ְ����Ϣ��������" << endl;
    cin >> n;
    cout << "��������ְ����Ϣ������ ���� ����" << endl;
    head = nodCreat(n);
    nodPrint(head); // ��ʾ��ǰ������״̬
    cout << "\n�������㽫ɾ����Ա���������ţ���һ�е��Ǹ�����" << endl;
    cin >> n;
    head = nodDelete(head, n);
    nodPrint(head); // �ٴ���ʾ��ǰ������״̬
    cout << "\n����������Ҫ���Ĺ��ʵ�Ա�����ţ��ڶ����Ǹ������Լ����ĺ�Ĺ��ʣ�" << endl;
    cin >> num >> Ewage;
    head = nodEdit(head, num, Ewage);
    nodPrint(head); // again, �ٴ���ʾ��ǰ������״̬
    return 0;
}


/*
�������룺
5
2352983 �ҹ� 7650
2352779 �»� 5282
2351216 ��ΰ 9316
2350466 ֣�� 7524
2352110 ���� 5830
4
2351216 0
*/

/*
���������

��ǰ������״̬Ϊ:
���    ����    ����    ����
1       2352983 �ҹ�    7650
2       2352779 �»�    5282
3       2351216 ��ΰ    9316
4       2350466 ֣��    7524
5       2352110 ����    5830

�����ɾ����������

��ǰ������״̬Ϊ:
���    ����    ����    ����
1       2352983 �ҹ�    7650
2       2352779 �»�    5282
3       2351216 ��ΰ    9316
4       2352110 ����    5830

����ɸ��ĺ�������

��ǰ������״̬Ϊ:
���    ����    ����    ����
1       2352983 �ҹ�    7650
2       2352779 �»�    5282
3       2351216 ��ΰ    0
4       2352110 ����    5830
*/