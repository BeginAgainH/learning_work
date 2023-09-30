#include<iostream>
#include<vector>

using namespace std;

class test {
public:
	test() {
		cout << "create test" << endl;
	}
	~test() {
		cout << "delete class" << endl;
	}
};

void testfunc() {
	test* checktest = new test;
}

struct TreeNode {
	int val;
	TreeNode* lNode;
	TreeNode* rNode;

	TreeNode(int x) :val(x), lNode(nullptr), rNode(nullptr) {};
};

void preTra(TreeNode* myTree, vector<int>& getNode) {
	if (myTree == nullptr)	return;

	getNode.push_back(myTree->val);
	
	preTra(myTree->lNode, getNode);
	preTra(myTree->rNode, getNode);
}

void midTra(TreeNode* myTree, vector<int>& getNode) {
	if (myTree == nullptr)	return;
	
	preTra(myTree->lNode, getNode);
	getNode.push_back(myTree->val);
	preTra(myTree->rNode, getNode);
}

void backTra(TreeNode* myTree, vector<int>& getNode) {
	if (myTree == nullptr)	return;
	
	preTra(myTree->lNode, getNode);
	preTra(myTree->rNode, getNode);
	getNode.push_back(myTree->val);
}

void printVec(vector<int> &getNode) {
	for (int i = 0; i < getNode.size(); i++) {
		cout << getNode[i];
	}
	cout << endl;

	getNode.clear();
}

void createTree(TreeNode* &myTree,int &num) {
	

	int innum;
	cin >> innum;
	myTree = new TreeNode(innum);

	num--;
	if (num == 0)	return;
	else if (num > 1) {
		if (num % 2)	createTree(myTree->rNode, num);
		else createTree(myTree->lNode, num);
	}
	else {
		if(myTree->lNode == nullptr) createTree(myTree->lNode, num);
		else createTree(myTree->rNode, num);
	}
	
}

int main() {
	int num;
	cin >> num;
	vector<int> getNode;
	TreeNode* myTree = nullptr;

	createTree(myTree, num);

	preTra(myTree, getNode);
	printVec(getNode);

	midTra(myTree, getNode);
	printVec(getNode);

	backTra(myTree, getNode);
	printVec(getNode);
}