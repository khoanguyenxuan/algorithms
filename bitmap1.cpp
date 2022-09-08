#include <bits/stdc++.h>

using namespace std;

int matrixScore(vector<vector<int>> grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<int> arr;
	for (int i = 0; i < m; i++) {
		int v = 0;
		for (int j = 0; j < n; j++) {
			v = v << 1;	
			v = v | grid[i][j];
		}
		if (!(v & (1 << n - 1))) {
			v = v ^ ((1 << n) - 1);
		}
		arr.push_back(v);
	}
	
	for (int i = 1; i < n; i++) {
		int pos = (n - i) - 1;
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (arr[j] & (1 << pos)) cnt++;
		}	
		if (cnt <= n / 2) {
			for (int j = 0; j < m; j++) {
				arr[j] = arr[j] ^ (1 << pos);
			}
		}
	}

	return accumulate(arr.begin(), arr.end(), 0);
}

int main() {
	vector<vector<int>> v = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
	int ret = matrixScore(v);
	cout << ret << endl;
	return 0;
}
