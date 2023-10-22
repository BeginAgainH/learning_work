#include <iostream>
#include <list>
using namespace std;

struct LNode {
    int val;
    LNode* next;
    LNode(int num = 0) : val(num), next(nullptr) {};
};

class Solution {
private:
    LNode* listhead;
public:
    Solution() {
        listhead = new LNode;
    }
    void createList(int n) {
        for (int i = 0; i < n; i++) {
            if (i == 0 && listhead->next == nullptr) {
                int num;
                cin >> num;
                LNode* newNode = new LNode(num);
                listhead->next = newNode;
            }
            else {
                int front, innum;
                cin >> innum >> front;
                LNode* temp = listhead;
                while (temp->next) {
                    if (temp->next->val == front) {
                        temp = temp->next;
                        if (temp->next) {
                            LNode* newNode = new LNode(innum);
                            newNode->next = temp->next;
                            temp->next = newNode;
                            break;
                        }
                        else {
                            LNode* newNode = new LNode(innum);
                            temp->next = newNode;
                            break;
                        }
                    }
                    else temp = temp->next;
                }
            }
        }
    }

    void deleteNode() {
        int denum;
        cin >> denum;
        LNode* temp = listhead;
        while (temp->next) {
            if (temp->next->val == denum) {
                if (temp->next->next)    temp->next = temp->next->next;
                else temp->next = nullptr;
                break;
            }
            else temp = temp->next;
        }
    }

    void prtlist() {
        LNode* temp = listhead;
        while (temp->next) {
            cout << temp->next->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    int n;
    cin >> n;
    
    Solution sol;
    sol.createList(n);
    //sol.prtlist();
    sol.deleteNode();
    sol.prtlist();


    system("pause");
}
// 64 Œª ‰≥ˆ«Î”√ printf("%lld")