#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    int cost;
    TreeNode* lNode;
    TreeNode* rNode;
    TreeNode(int icost, int ival) : val(ival), cost(icost), lNode(nullptr),
        rNode(nullptr) {};
};

class Solution {
public:
    void createTree(int num, vector<TreeNode*>& prolist) {
        vector<vector<int>>affvec;
        for (int i = 0; i < num; i++) {
            int c, v, b;
            cin >> c >> v >> b;
            if (b == 0) {
                TreeNode* getNode = new TreeNode(c, v);
                prolist[i] = getNode;
            }
            else {
                affvec.push_back({ c,v,b });
            }
        }
 
        for (int j = 0; j < affvec.size(); j++) {
            if (prolist[affvec[j][2] - 1]->lNode)   prolist[affvec[j][2] - 1]->rNode = new TreeNode(affvec[j][0], affvec[j][1]);
            else prolist[affvec[j][2] - 1]->lNode = new TreeNode(affvec[j][0], affvec[j][1]);
        }
        for (vector<TreeNode*>::iterator it = prolist.begin(); it != prolist.end();) {
            if (!*it)    it = prolist.erase(it);
            else it++;
        }
    }

    void setdparry(vector<vector<int>>& dp, vector<TreeNode*>prolist, int value) {

        for (int i = 1; i <= prolist.size() ; i++) {
            cout << "考虑主件" << i << "的情况，花费和重要性及满意度分别为" << prolist[i - 1]->cost << "、" << prolist[i - 1]->val << "、" << getval(prolist[i - 1]) << endl;
            for (int j = 1; j <= value; j++) {

                dp[i][j] = (j >= prolist[i - 1]->cost) ? max(dp[i - 1][j], (dp[i - 1][j - prolist[i - 1]->cost] + getval(prolist[i - 1]))) : dp[i - 1][j];

                if (prolist[i - 1]->lNode) dp[i][j] = (j >= (prolist[i - 1]->cost + prolist[i - 1]->lNode->cost)) ? max(dp[i][j], dp[i - 1][j - prolist[i - 1]->cost - prolist[i - 1]->lNode->cost] + getval(prolist[i - 1]) + getval(prolist[i - 1]->lNode)) : dp[i][j];

                if (prolist[i - 1]->rNode) dp[i][j] = (j >= (prolist[i - 1]->cost + prolist[i - 1]->rNode->cost)) ? max(dp[i][j], dp[i - 1][j - prolist[i - 1]->cost - prolist[i - 1]->rNode->cost] + getval(prolist[i - 1]) + getval(prolist[i - 1]->rNode)) : dp[i][j];

                if (prolist[i - 1]->lNode&& prolist[i - 1]->rNode) dp[i][j] = (j >= (prolist[i - 1]->cost + prolist[i - 1]->lNode->cost + prolist[i - 1]->rNode->cost)) ? max(dp[i][j], dp[i - 1][j - prolist[i - 1]->cost - prolist[i - 1]->lNode->cost - prolist[i - 1]->rNode->cost] + getval(prolist[i - 1]) + getval(prolist[i - 1]->lNode) + getval(prolist[i - 1]->rNode)) : dp[i][j];
                
                
            }
        }
    }
    void cal(vector<vector<int>>& dp, vector<TreeNode*>prolist) {

    }

    int getval(TreeNode* getNode) {
        return getNode->cost * getNode->val;
    }

    void prTree(vector<TreeNode*>prolist) {
        for (int i = 0; i < prolist.size(); i++) {
            cout << "第" << i << "个主件和附件" << endl;
            cout << i << " " << prolist[i]->cost << " " << prolist[i]->val << endl;
            if(prolist[i]->lNode)   cout << i << " " << prolist[i]->lNode->cost << " " << prolist[i]->lNode->val << endl;
            if(prolist[i]->rNode)   cout << i << " " << prolist[i]->rNode->cost << " " << prolist[i]->rNode->val << endl;
        }
    }


};

int main() {
    Solution sol;

    int cash, num;
    cin >> cash >> num;

    vector<TreeNode*>prolist(num);

    sol.createTree(num, prolist);

    sol.prTree(prolist);

    cout << "prolist size is " << prolist.size() << endl;

    vector<vector<int>> dp(prolist.size()+1, vector<int>(cash + 1, 0));

    //
    sol.setdparry(dp, prolist, cash);
    cout << dp[prolist.size()][cash] << endl;


}
// 64 位输出请用 printf("%lld")