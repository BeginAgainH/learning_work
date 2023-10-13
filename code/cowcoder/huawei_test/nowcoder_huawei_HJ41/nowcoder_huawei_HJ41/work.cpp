#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;

vector<int> alter(vector<vector<int>>proj) {
	vector<int>temp;
	temp.push_back(0);
	for (int i = 0; i < proj.size(); i++) {
		for (int j = 0; j < proj[i][1]; j++) {
			temp.push_back(proj[i][0]);
		}
	}
	sort(temp.begin(), temp.end());
	return temp;
}

void inser(int n, vector<vector<int>>& proj) {
	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		proj[i][0] = weight;
	}
	for (int i = 0; i < proj.size(); i++) {
		int num;
		cin >> num;
		proj[i][1] = num;
	}
}

void backtracing(int start,int len, vector<vector<int>>proj, vector<bool>& used, map<int, int>& allres, int& temp, vector<int>& tempout, int n) {
	if (n == len) {
		/*if (tempout.size()) {
			cout << "all possibilities in this way has been found,n is " << n << endl;
			for (int a : tempout) {
				cout << a << " ";
			}
			cout << endl;
		}*/
		//if (len < proj.size())	backtracing(start + 1, len + 1, proj, used, allres, temp, tempout, n + 1);
		return;
	}
	for (int i = start; i < proj.size(); i++) {
		if (i != 0 && !used[i - 1] && proj[i][0] == proj[i - 1][0] && allres[temp + proj[i][0]] == 1)	continue;

		
		allres[temp + proj[i][0]] = 1;
		//cout << "inster val "<<proj[i] << endl;
		temp += proj[i][0];
		used[i] = true;
		tempout.push_back(proj[i][0]);
		backtracing(i + 1, len, proj, used, allres, temp, tempout, n + 1);
		temp -= proj[i][0];
		used[i] = false;
		if (tempout.size()) tempout.pop_back();
		
		
	}
}

void sortallval(vector<vector<int>>proj, map<int, int>& allres) {
	for (int i = 0; i < proj.size(); i++) {
		for (int j = 1; j < proj[i][1]; j++) {
			//cout <<"weight " << proj[i][0] << " has more" << endl;
			map<int, int>temp(allres);
			for (auto iter = allres.begin(); iter != allres.end(); iter++) {
				//cout << iter->first << " is using weight " << proj[i][0] << endl;
				temp[iter->first + proj[i][0]] = 1;
			}
			//cout << "weight " << proj[i][0] << " has been used all" << endl;
			allres.clear();
			allres = temp;
		}
	}
}

//void backtracing(int start,int len, vector<int>proj, vector<bool>& used, map<int, int>& allres, int& temp, vector<int>& tempout, int n) {
//	if (n == len) {
//		/*if (tempout.size()) {
//			cout << "all possibilities in this way has been found,n is " << n << endl;
//			for (int a : tempout) {
//				cout << a << " ";
//			}
//			cout << endl;
//		}*/
//		//if (len < proj.size())	backtracing(start + 1, len + 1, proj, used, allres, temp, tempout, n + 1);
//		return;
//	}
//	for (int i = start; i < proj.size(); i++) {
//		if (i != 0 && !used[i - 1] && proj[i] == proj[i - 1] && allres[temp + proj[i]] == 1)	continue;
//
//		
//		allres[temp + proj[i]] = 1;
//		//cout << "inster val "<<proj[i] << endl;
//		temp += proj[i];
//		used[i] = true;
//		tempout.push_back(proj[i]);
//		backtracing(i + 1, len, proj, used, allres, temp, tempout, n + 1);
//		temp -= proj[i];
//		used[i] = false;
//		if (tempout.size()) tempout.pop_back();
//		
//		
//	}
//}

void makegro(vector<vector<int>>proj, map<int, int>& allres) {
	vector<bool>used(proj.size(), false);
	int temp = 0;
	vector<int>tempout;
	//backtracing(0, 0, proj, used, allres, temp, tempout, 0);
	for (int i = 0; i <= proj.size(); i++) {
		backtracing(0,i, proj, used, allres, temp, tempout, 0);
	}
	sortallval(proj, allres);

}

//void makegro(vector<int>proj, map<int, int>& allres) {
//	vector<bool>used(proj.size(), false);
//	int temp = 0;
//	vector<int>tempout;
//	//backtracing(0, 0, proj, used, allres, temp, tempout, 0);
//	for (int i = 0; i <= proj.size(); i++) {
//		backtracing(0, i, proj, used, allres, temp, tempout, 0);
//	}
//}



int main() {
	cout << "using backtracing in one time" << endl;
	int n;
	clock_t star, end;
	while (cin >> n) {
		star = clock();
		vector<vector<int>>proj(n, vector<int>(2));
		map<int, int>allres;
		inser(n, proj);
		vector<int>alterval = alter(proj);
		//cout << "there has " << alterval.size() << " projs" << endl;
		//makegro(alterval, allres);
		makegro(proj, allres);
		cout <<"num of probilities is " << allres.size()+1  << endl;
		/*cout << "they are ";
		for (auto iter = allres.begin(); iter != allres.end(); iter++) {
			cout << iter->first << " ";
		}
		cout << endl;*/
		end = clock();
		cout << "run time is " << double(end - star)/CLOCKS_PER_SEC<<"s" << endl;
	}


}
// 64 位输出请用 printf("%lld")

//测试用例
//3
//10 191 103
//6 6 5
////
//2
//1 2
//2 1
////
//4
//109 189 121 141
//6 1 4 3
////
//7
//58 18 139 163 57 167 178
//1 1 3 2 6 3 4
//
////
//8
//69 54 119 85 103 53 155 170
//6 6 3 7 6 2 2 4

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    while (cin >> n) {
//        vector<int> weight(n);
//        vector<int> num(n);
//        int sum = 0;
//        for (int i = 0; i < n; i++) //输入n种砝码重量
//            cin >> weight[i];
//        for (int i = 0; i < n; i++) {//输入n种砝码的数量
//            cin >> num[i];
//            sum += num[i] * weight[i]; //砝码总重量
//        }
//        vector<bool> dp(sum + 1, false); //记录0到sum是否可行
//        dp[0] = true;
//        for (int i = 0; i < n; i++) { //遍历每一种砝码
//            for (int j = 0; j < num[i]; j++) { //遍历砝码每一个数量
//                for (int k = sum; k >= weight[i]; k--) //每次剩余的每个都可以添加
//                    if (dp[k - weight[i]])
//                        dp[k] = 1;
//            }
//        }
//        int count = 0;
//        for (int i = 0; i <= sum; i++) //找到为1的就是可以组成的质量，计数
//            if (dp[i])
//                count++;
//        cout << count << endl;
//    }
//    return 0;
//}
