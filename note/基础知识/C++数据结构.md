# C++数据结构

## 链表

```C++
//建立节点
struct LNode {
    int val;
    LNode* next = nullptr;
};

//建立链表
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

//d
void printList(LNode* node) {
    LNode* head = new LNode;
    head = node;

    while (head->next) {
        cout << head->next->val;
        if (head->next->next)    head = head->next;
        else break;
    }
}

```



## 树



## 图