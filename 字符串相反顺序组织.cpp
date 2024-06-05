// 2252902 赵梓成
#include <iostream>
using namespace std;

struct ListNode {
    char data;
    ListNode* next;
};

ListNode* insertAtHead(char p, ListNode* head) {
    ListNode* New = new ListNode;
    New->data = p;
    New->next = head;
    return New;
}

void printNode(ListNode* head) {
    for (; head != nullptr; head = head->next)
        cout << head->data;
}

int main() {
    char ch[100] = "";
    ListNode* head = nullptr;
    cin >> ch;
    for (int i = 0; ch[i] != '\0'; i++)
        head = insertAtHead(ch[i], head);
    printNode(head);
    return 0;
}

