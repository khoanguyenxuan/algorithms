#include <bits/stdc++.h>

using namespace std;

void updateSum(vector<int> &sumArr, int x) {
	for (int i = 0; i < 32; i++){
		int ith_bit = x & (1 << i);
		sumArr[i] += ith_bit > 0?1:0;
	}
}

int uniqueNo3(vector<int> arr) {
	vector<int> sumArr(32, 0);
	for (int x: arr) {
		updateSum(sumArr, x);
	}
	int val = 0;
	
	for (int i = 0; i < 32; i++) {
		if (sumArr[i] % 3) {
			val = val | (1 << i);
		}
	}
	
 	return val;
}

int main() {
	vector<int> arr = {1, 3, 5, 8, 3, 1, 5, 5, 3, 1};
	cout << uniqueNo3(arr) << endl;
	return 0;
}
// Ra unique xor voi nhau

