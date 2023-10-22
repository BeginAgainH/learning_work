#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
private:
    vector<string> backstr;
    int outnum = 0;
public:
    void informula() {
        string instr;
        getline(cin, instr);
        cout << "instr size is " << instr.size() << endl;
        for (auto a : instr) {
            cout << a;
        }
        cout << endl;
        stack<char>symbol;
        string temp;
        for (int i = 0; i < instr.size(); i++) {
            if (instr[i] >= '0' && instr[i] <= '9')  temp += instr[i];
            else {
                if (temp.size())
                {
                    backstr .push_back(temp);
                    temp.clear();
                }
                if (instr[i] == '*' || instr[i] == '/' || instr[i] == '(' || instr[i] == '[' || instr[i] == '{') {
                    if (instr[i] == '[' || instr[i] == '{')  symbol.push('(');
                    else symbol.push(instr[i]);
                }
                else {
                    if (instr[i] == ')' || instr[i] == ']' ||instr[i] == '}') {
                        while (!symbol.empty() && symbol.top() != '(') {
                            backstr.push_back(string(1, symbol.top()));
                            symbol.pop();
                        }
                        symbol.pop();
                    }
                    else { 
                        while (!symbol.empty() && (symbol.top() == '*' || symbol.top() == '/')) {
                            backstr.push_back(string(1,symbol.top()));
                            symbol.pop();
                        }
                        if (instr[i] == '-') {
                            if (i > 0 && ((instr[i - 1] >= '0' && instr[i - 1] <= '9') || (instr[i - 1] == ')' || instr[i - 1] == ']' || instr[i - 1] == '}'))) {
                                    
                                    cout << "front is " << instr[i - 1] << " back is " << instr[i + 1] << endl;
                                    /*while (!symbol.empty() && (symbol.top() == '*' || symbol.top() == '/')) {
                                        backstr.push_back(string(1, symbol.top()));
                                        symbol.pop();
                                    }*/
                                    symbol.push('+');
                                    symbol.push('*');
                                    backstr.push_back("-1");
                            }
                            else {
                                    //symbol.push('+');
                                    symbol.push('*');
                                    backstr.push_back("-1");
                            }
                        }
                        else symbol.push(instr[i]);
                    }
                }
            }
        }
        if (temp.size()) {
            backstr.push_back(temp);
            temp.clear();
        }
        while (!symbol.empty()) {
            backstr.push_back(string(1, symbol.top()));
            symbol.pop();
        }
        
    }

    void calculate() {
        stack<int>getval;
        for (int i = 0; i < backstr.size(); i++) {
            if (backstr[i] != "+"  && backstr[i] != "*" && backstr[i] != "/") {
                istringstream ss(backstr[i]);
                int val;
                ss >> val;
                getval.push(val);
            }
            else {
                if (getval.size() >= 2) {
                    int va1,va2;
                    va1 = getval.top();
                    getval.pop();
                    va2 = getval.top();
                    getval.pop();

                    istringstream ss(backstr[i]);
                    char sym;
                    ss >> sym;
                    switch (sym) {
                    case '+':
                        getval.push(va1 + va2);
                        break;

                    case '*':
                        getval.push(va1 * va2);
                        break;

                    case '/':
                        getval.push(va2 / va1);
                        break;
                    }
                }
                
            }
        }

        cout <<  getval.top() << endl;
    }

    void prtback() {
        for (string a : backstr) {
            cout << a;
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    sol.informula();
    sol.prtback();
    sol.calculate();
    system("pause");
}