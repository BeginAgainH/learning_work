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

### 红黑树

#### 概念

**什么是红黑树**	红黑树是一种平衡二叉搜索树

**特点**

​	1、每个结点非黑即红

​	2、根节点为黑，叶节点（只为空的节点）为黑

​	3、一个红节点的子节点都为黑

​	4、从一个节点到该节点的子孙节点所有路径上包含相同数量的黑节点