#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <class Type>
Type stringToNum(const string& instring) {
    istringstream iss(instring);
    Type num;
    iss >> num;
    return num;
}

//template <class Type>
//string numToString(const Type& instring) {
//    ostringstream oss;
//    oss<<instring
//    return num;
//}

class Sloution {
public:

    void calnum(int frontnum, float backnum, string& outstr) {
        if (frontnum >= 0) outstr += '0';
        else outstr += '1';

        while (frontnum != 1) {
            outstr.insert(1,to_string(frontnum%2));
            frontnum /= 2;
            if(frontnum == 1)   outstr.insert(1,"1");
            //cout << outstr << endl;
        }
        

        
        if (backnum) {
            outstr += '.';
            int count = 5;
            while (backnum != 0 && count != 0) {
                if (backnum * 2 >= 1) {
                    outstr += '1';
                    backnum = backnum * 2 - 1;
                }
                else {
                    outstr += '0';
                    backnum *= 2;
                }

                count--;

            }

        }
        

        cout << outstr << "B" << endl;

        cout << "float negnum is ";
        
    }

    void negfloat(float insnum, string& outstr) {
        string restr = to_string(insnum);
        cout << "restr is " << restr << endl;
        string gets;
        int flag;

        int frontnum;
        float backnum;
        for (char a : restr) {
            if (a == '.') {
                cout << "gets is " << gets << endl;
                frontnum = stringToNum<int>(gets);
                gets.clear();
            }
            else gets += a;
        }

        if(gets.size()) backnum = stringToNum<float>(gets);
        cout << insnum << "O change to";
        calnum(frontnum, backnum, outstr);

        for (int i = 0; i < outstr.size(); i++) {
            if (outstr[i] == '1')    outstr[i] = '0';
            if (outstr[i] == '0')   outstr[i] = '1';
        }
    }

    void printstr(string outstr) {

        for (char a : outstr) {
            cout << a;
        }
        cout <<"B"<< endl;
    }
};

int main() {
    Sloution myslo;
    string outstr;

    float insnum;
    
    cin >> insnum;

    myslo.negfloat(insnum, outstr);
    
    myslo.printstr(outstr);
    return 0;
}
