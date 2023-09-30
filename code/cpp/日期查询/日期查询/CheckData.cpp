#include <iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

void printstack(vector<string> str) {
    for (vector<string>::iterator it = str.begin(); it != str.end(); it++) {
        cout << *it;
    }
    cout << endl;
}

void switch_str(vector<string>& switchstr, string gets) {

    stack<char>temp_cal;
    string inser;

    for (int i = 0; i < gets.length(); i++) {
        if (gets[i] <= '9' && gets[i] >= '0') {
            inser += gets[i];
        }

        else {
            //数字装入后序数组
            if (!inser.empty()) {
                switchstr.push_back(inser);
                inser.clear();
            }


            //装入算术符号
            char cal = gets[i];
            switch (cal) {
            case '+':
                if (temp_cal.empty() || temp_cal.top() == '(' || temp_cal.top() == '+') {
                    temp_cal.push(cal);
                }
                else if (temp_cal.top() == '*' || temp_cal.top() == '/') {
                    while (!temp_cal.empty() && temp_cal.top() != '(') {
                        string ss(1, temp_cal.top());
                        switchstr.push_back(ss);
                        temp_cal.pop();
                    }
                    temp_cal.push(cal);
                }
                break;

            case '-':
                if (!temp_cal.empty() && (temp_cal.top() == '*' || temp_cal.top() == '/')) {
                    while (!temp_cal.empty() && temp_cal.top() != '(') {
                        string ss(1, temp_cal.top());
                        switchstr.push_back(ss);
                        temp_cal.pop();
                    }
                    temp_cal.push('+');
                    temp_cal.push('*');
                    switchstr.push_back("-1");
                }

                else if (i == 0 || (!temp_cal.empty() && gets[i - 1] == '(')) {
                    switchstr.push_back("-1");
                    temp_cal.push('*');
                }
                else {
                    temp_cal.push('+');
                    temp_cal.push('*');
                    switchstr.push_back("-1");
                }

                break;

            case '*':case '/':
                temp_cal.push(cal);
                break;

            case'(':

                temp_cal.push(cal);

                break;

            case')':
                while (temp_cal.top() != '(') {
                    string ss(1, temp_cal.top());
                    switchstr.push_back(ss);
                    temp_cal.pop();
                }
                temp_cal.pop();
                break;


            }
        }
    }

    if (inser.length()) {
        switchstr.push_back(inser);
        inser.clear();
        if (temp_cal.empty()) {
            switchstr.push_back("+");
        }
    }


    while (!temp_cal.empty()) {
        string ss(1, temp_cal.top());
        switchstr.push_back(ss);
        temp_cal.pop();
    }
}

void calculate(vector<string>switchstr) {

    stack<int>numstack;

    for (vector<string>::iterator it = switchstr.begin(); it != switchstr.end(); ) {
        if (*it != "+" && *it != "-" && *it != "*" && *it != "/") {
            numstack.push(atoi((*it).c_str()));
            it++;
        }

        else {

            if (numstack.size() > 1) {
                int num1, num2;
                const char* a = (*it++).c_str();
                switch (*a) {
                case'+':
                    num1 = numstack.top();
                    numstack.pop();
                    num2 = numstack.top();
                    numstack.pop();
                    numstack.push(num1 + num2);
                    break;

                case'-':
                    num2 = numstack.top();
                    numstack.pop();
                    num1 = numstack.top();
                    numstack.pop();
                    numstack.push(num1 - num2);

                    break;

                case'*':
                    num1 = numstack.top();
                    numstack.pop();
                    num2 = numstack.top();
                    numstack.pop();
                    numstack.push(num1 * num2);

                    break;

                case'/':
                    num2 = numstack.top();
                    numstack.pop();
                    num1 = numstack.top();
                    numstack.pop();
                    numstack.push(num1 / num2);

                    break;

                }
            }


        }

    }


    cout << numstack.top();
}


int main() {
    string gets;
    cin >> gets;
    vector<string> switchstr;

    cout << "inser str is: " << gets << endl;
   
    switch_str(switchstr, gets);

    cout<< "after switch: ";

    printstack(switchstr);

    calculate(switchstr);



}
// 64 位输出请用 printf("%lld")