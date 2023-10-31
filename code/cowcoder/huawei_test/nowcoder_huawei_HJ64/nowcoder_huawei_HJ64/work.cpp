#include <iostream>
#include<string>
#include<vector>

#define max_page 4

using namespace std;


class Solution {
public:
    void setMouse() {
        int num;
        cin >> num;
        vector<int>songs(num);
        string ctl;
        cin >> ctl;
        cltdetail(songs, ctl);
    }
    void cltdetail(vector<int>& songs, string ctl) {
        for (int i = 0; i < songs.size(); i++) {
            songs[i] = i + 1;
        }

        int cur = 0;
        int begin = 0, end;
        int flag = 0;
        if (songs.size() > 4) {
            flag = 1;
            end = 3;
        }
        else end = songs.size() - 1;

        for (auto ch : ctl) {
            if (ch == 'U') {
                if (cur == 0) {
                    cur = songs.size() - 1;
                    if (flag) {
                        end = cur;
                        begin = songs.size() - 4;
                    }
                    continue;
                }
                if (cur == begin) {
                    if (flag) {
                        if (begin > 0) {
                            cur--;
                            begin--;
                            end--;
                        }
                        else {
                            cur = songs.size() - 1;
                            end = cur;
                            begin = songs.size() - 4;
                        }

                    }
                    else {
                        cur = end;
                    }
                }
                else {
                    cur--;

                }
            }
            if (ch == 'D') {
                if (cur == songs.size() - 1) {
                    cur = 0;
                    if (flag) {
                        end = 3;
                        begin = 0;
                    }
                    continue;
                }
                if (cur == end) {
                    if (flag) {
                        if (end < songs.size() - 1) {
                            cur++;
                            end++;
                            begin++;
                        }
                        else {
                            cur = 0;
                            end = 3;
                            begin = 0;
                        }
                    }
                    else {
                        cur = begin;
                    }
                }
                else {
                    cur++;
                }
            }
        }

        for (int i = begin; i <= end; i++) {
            cout << songs[i] << " ";
        }
        cout << endl << songs[cur];
    }
};

int main() {
    Solution sol;
    sol.setMouse();
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")