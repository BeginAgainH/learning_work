#include <iostream>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
    void getmaxsubstring() {
        string str;
        int n, pos, temp;
        int max = 0;
        cin >> str >> n;
        for (int i = 0; i < n; i++) {
            if (str[i] == 'C' || str[i] == 'G')  max++;
        }
        temp = max;
        pos = 0;
        for (int i = 1; i + n - 1 <str.size()-1 ; i++) {
            if (str[i - 1] == 'C' || str[-1] == 'G')   temp--;
            if (str[i + n - 1] == 'C' || str[i + n - 1] == 'G')  temp++;
            if (temp > max) {
                cout<<"max "<<max<<" udpate to "<<temp<<" and pos is "<<i<<endl;
                max = temp;
                pos = i;
            }
        }

        for (int i = n; i > 0; i--) {
            cout << str[pos + (n - i)];
        }
    }
};

int main() {
    /*Solution sol;
    sol.getmaxsubstring();*/

    string str;
    int n, pos, temp;
    int max = 0;
    cin >> str >> n;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'C' || str[i] == 'G')  max++;
    }
    temp = max;
    pos = 0;
    for (int i = 1; i + n - 1 < str.size() - 1; i++) {
        if (str[i - 1] == 'C' || str[i-1] == 'G')   temp--;
        if (str[i + n - 1] == 'C' || str[i + n - 1] == 'G')  temp++;
        if (temp > max) {
            cout << "max " << max << " udpate to " << temp << " and pos is " << i << endl;
            max = temp;
            pos = i;
        }
    }

    for (int i = n; i > 0; i--) {
        cout << str[pos + (n - i)];
    }

    system("pause");
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")