#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int>val1;
    vector<int>val2;
public:
    void getval() {
        string str1, str2;
        cin >> str1 >> str2;
        for (char a : str1) {
            val1.push_back(a - '0');
        }
        for (char a : str2) {
            val2.push_back(a - '0');
        }

        if (val1.size() < val2.size()) {
            while (val1.size() != val2.size()) {
                val1.insert(val1.begin(), 0);
            }
        }
        if (val1.size() > val2.size()) {
            while (val1.size() != val2.size()) {
                val2.insert(val2.begin(), 0);
            }
        }

        cout << "val1 is ";
        for (int a : val1) {
            cout << a;
        }
        cout << endl;
        cout << "val12 is ";
        for (int a : val2) {
            cout << a;
        }
        cout << endl;
    }

    void calculate() {
        vector<int>outvec(val1.size() + 1, 0);

        for (int i = val1.size() - 1; i >= 0; i--) {
            if (val1[i] + val2[i] >= 10) {
                outvec[i + 1] += (val1[i] + val2[i]) % 10;
                outvec[i] += (val1[i] + val2[i]) / 10;
            }
            else outvec[i + 1] += val1[i] + val2[i];
        }

        while (outvec.front() == 0) {
            outvec.erase(outvec.begin());
        }

        for (int a : outvec) {
            cout << a;
        }

    }

};

int main() {
    Solution sol;
    sol.getval();
    sol.calculate();

    system("pause");
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")