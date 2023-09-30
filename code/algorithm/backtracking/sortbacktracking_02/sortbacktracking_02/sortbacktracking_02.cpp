#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;



bool cmpup(string& a, string& b) {
    return a < b;
}

class Solution {
public:
    map<string,int>brovec;
    string temp;
    void backtracking(string instr, vector<bool>& used) {
        if (temp.size() == instr.size()) {
            brovec[temp]++;
            return;
        }

        for (int i = 0; i < instr.size(); i++) {
            
            if (i > 0 && instr[i] == instr[i - 1] && used[i - 1] == false) {
                continue;
            }

            if (used[i] == false) {
                used[i] = true;
                temp += instr[i];
                backtracking(instr, used);
                temp.pop_back();
                used[i] = false;
            }
            
        }
    }

    int cal(int num) {
        return num * cal(num - 1);
    }

    void solport(string instr) {
        brovec.clear();
        temp.clear();

        vector<bool>used(instr.size(), false);
        backtracking(instr, used);

       

        
    }

    void prtvec() {
        for (auto it = brovec.begin(); it != brovec.end(); it++) {
            cout << it->first<<" ";
        }
        cout << endl;
    }

};

int main() {
    string getstr;
    string getc;

    string instr;
    map<string, int>dict;

    int num1 = -1, num2;

    getline(cin, getstr);

    for (char a : getstr) {
        if (a == ' ') {
            if (getc >= "0" && getc <= "9") {
                num1 = atoi(getc.c_str());
                getc.clear();
            }
            else if (dict.size() <= num1-1) {
                if (dict[getc] == 0) {
                    dict[getc]++;
                    getc.clear();
                }
                else num1--;
            }
            else {
                instr = getc;
                getc.clear();
            }

        }
        else getc += a;
    }

    num2 = atoi(getc.c_str());

    Solution myslo;
    myslo.solport(instr);
    myslo.prtvec();
    
    
    

    if (num2 > myslo.brovec.size())    return 0;




    for (auto itd = dict.begin(); itd != dict.end(); ) {
        if (myslo.brovec[itd->first] == 1 && itd->first != instr) {
            cout << itd->first << " ";
            itd++;
        }
        else
        {
            itd = dict.erase(itd);
        }
    }

    cout << endl;
    int n = 1;

 

    for (auto itd = dict.begin(); itd != dict.end(); itd++) {
        if (n != num2)    continue;
        else
        {
            cout << dict.size()<<endl;
            cout << itd->first << endl;
        }
        n++;
    }
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")