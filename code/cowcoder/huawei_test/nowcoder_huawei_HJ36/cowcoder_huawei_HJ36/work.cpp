#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

void make_dic(map<char, int>& dic, vector<char>& code_dic, string instr) {
	char j = 'a';
	map<char, int>code_tool;
	for (int i = 1; i <= 26; i++, j++) {
		dic[j] = i;
	}

	for (char a : instr) {
		if (a >= 'a' && a <= 'z') {
			if (code_tool[a] == 0) {
				code_dic.push_back(a);
				code_tool[a] = 1;
			}
		}
	}
	int count = 1;
	for (auto cptr = dic.begin(); cptr != dic.end(); cptr++) {
		if (!code_tool[cptr->first])	code_dic.push_back(cptr->first);
	}
}

string encryption(map<char, int> dic, vector<char> code_dic, string code) {
	string outstr;
	for (char a : code) {
		if (a >= 'a' && a <= 'z')	outstr += code_dic[dic[a] - 1];
		else outstr += a;
	}
	return outstr;
}

int main() {
	map<char, int>dic;
	string instr;
	getline(cin, instr);
	vector<char>code_dic;
	make_dic(dic, code_dic, instr);
	string costr;
	getline(cin, costr);
	cout << encryption(dic, code_dic, costr) << endl;

}