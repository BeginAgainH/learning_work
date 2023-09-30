#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
	string temp;
	vector<string> allstr;

	void backtracking(string inser,vector<bool>& used) {
		if (temp.size() == inser.size()) {
			allstr.push_back(temp);
			return;
		}

		for (int i = 0; i < inser.size(); i++) {

			if (used[i] == true)	continue;



			used[i] = true;
			temp += inser[i];
			backtracking(inser, used);
			//temp.pop_back();
			temp.erase(temp.end()-1);
			used[i] = false;
		}
	}


	void alport(string inser) {
		temp.clear();
		allstr.clear();
		vector<bool>used(inser.size(),false);

		backtracking(inser, used);

		cout << allstr.size() << endl;
	}

};


int main() {
	/*if ("abc" == "acb")	cout << 1 << endl;
	else cout << 0 << endl;


	string ins;
	Solution myslo;

	cin >> ins;

	myslo.alport(ins);


	system("pause");*/

	string instr = "abcd";
	map<char, int>testmap;
	for (char a : instr) {
		testmap[a]++;
	}
	
	for (int i = 0; i < testmap.size(); i++) {
		cout<<testmap.begin()
	}
}