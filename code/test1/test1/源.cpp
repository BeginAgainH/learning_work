#include<iostream>
using namespace std;

//�����ڵ�
struct LNode {
    int val;
    LNode* next = nullptr;
};

//��������
void createList(LNode* node) {
    LNode* head = new LNode;
    head = node;

    int num;
    while (cin >> num) {
        LNode* p = new LNode;
        p->val = num;
        head->next = p;
        head = head->next;

        if (cin.get() == '\n')   break;
    }
}

void printList(LNode* node) {
    LNode* head = new LNode;
    head = node;

    while (head->next) {
        cout << head->next->val;
        if (head->next->next)    head = head->next;
        else break;
    }
}

int main() {
    LNode* myNode = new LNode;
    
    createList(myNode);

    printList(myNode);


}