#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
	vector<pair<int,int>>respath;
	vector<vector<int>> matrix;
public:
	Solution(int n,int m) {
		matrix = vector<vector<int>>(n, vector<int>(m));
	}


	void dfs(int x,int y,int n,int m, vector<vector<int>>matrix, vector<pair<int,int>>& tempath) {
		tempath.push_back(make_pair(x,y));
		matrix[x][y] = 1;
		if (x == n - 1 && y == m - 1) {
			respath = tempath;
			return;
		}

		if (x + 1 < n && matrix[x + 1][y] == 0)		dfs(x + 1, y, n, m, matrix, tempath);
		if (y + 1 < m && matrix[x][y + 1] == 0)		dfs(x , y + 1, n, m, matrix, tempath);
		if (x - 1 >= 0 && matrix[x - 1][y] == 0)	dfs(x - 1, y, n, m, matrix, tempath);
		if (y - 1 >= 0 && matrix[x][y - 1] == 0)	dfs(x , y - 1, n, m, matrix, tempath);

		tempath.pop_back();
		matrix[x][y] = 0;
	}

	void getway() {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				cin >> matrix[i][j];
			}
		}

		vector<pair<int, int>> tempath;
		dfs(0, 0, matrix.size(), matrix[0].size(), matrix, tempath);

		for (int i = 0; i < respath.size(); i++) {
			cout << "(" << respath[i].first << "," << respath[i].second << ")" << endl;
		}
	}
};

int main(){
	int n, m;
	while (cin >> n >> m) {
		Solution s1(n, m);
		s1.getway();
	}
}