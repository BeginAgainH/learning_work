#include<iostream>
#include<vector>

using namespace std;

struct LNode {
	int val;
	LNode* next = nullptr;
};

struct Nodelist {

};

void InsSort(vector<int>&arr) {
	for (int i = 0; i < arr.size()-1; i++) {
		int end = i;
		int temp = arr[end + 1];
		while (end >= 0) {
			if (arr[i] < temp) {
				arr[end + 1] = arr[end];
				end--;
			}
			else break;
		}
		arr[end + 1] = temp;
	}
}

void sortLNode(LNode *n1, LNode *n2,LNode *newNode) {
	vector<int>arr;
	while (n1) {
		arr.push_back(n1->val);
		if (n1->next) {
			n1 = n1->next;
		}
	}
	while (n2) {
		arr.push_back(n1->val);
		if (n2->next) {
			n2 = n2->next;
		}
	}
	InsSort(arr);

	LNode* head = new LNode;
	head = newNode;

	for (int i = 0; i < arr.size(); i++) {
		LNode* p = new LNode;

		p->val = arr[i];
		head->next = p;
		head = head->next;
	}
}



LNode* createNode(int num) {

	LNode* nextNode = nullptr;
	nextNode = new(LNode);

	nextNode->val = num;
	nextNode->next = NULL;

	return  nextNode;
	
}

int main() {
	LNode* p1 = nullptr;
	LNode* p2 = nullptr;
	LNode* newNode = nullptr;
	
	int num;

	p1 = new LNode;
	p2 = new LNode;
	newNode = new LNode;

	struct LNode* head = new LNode;
	head = p1;
	//插入p1数据
	while (cin >> num) {		
		LNode *pNode = new LNode;

		pNode = createNode(num);
		head->next = pNode;
		head = head->next;	

		if (cin.get() == '\n')	break;
	}

	//插入p2数据
	head = p2;
	while (cin >> num) {
		LNode* pNode = new LNode;

		pNode = createNode(num);
		head->next = pNode;
		head = head->next;

		if (cin.get() == '\n')	break;
	}

	struct LNode* n1 = p1->next;
	struct LNode* n2 = p2->next;
	
	vector<int>arr;
	while (n1) {
		arr.push_back(n1->val);
		if (n1->next) {
			n1 = n1->next;
		}
		else break;
	}
	while (n2) {
		arr.push_back(n2->val);
		if (n2->next) {
			n2 = n2->next;
		}
		else break;
	}

	head = newNode;

	InsSort(arr);

	for (int i = 0; i < arr.size(); i++) {
		LNode* pNode = new LNode;

		pNode->val = arr[i];
		head->next = pNode;
		head = head->next;
	}
	head = newNode;
	while (head) {
		if (head->next) {
			cout << head->next->val;
			head = head->next;
		}
		else break;
	}

	cout << endl;
}