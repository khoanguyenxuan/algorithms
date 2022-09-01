#include <bits/stdc++.h>

using namespace std;

int getFirstSetBit(int n) {
	return n & ~(n - 1);	
}

int uniqueNo2(vector<int> arr) {
	int n = arr.size();
	int r = 0;
	for (int v: arr) {
		r = r ^ v;
	}
	int ffs = getFirstSetBit(r);
	int val = 0;
	for (int v: arr) {
		if (v & ffs) {
			val = val ^ v;
		}
	}
	
	return val;
}

int main () {
	vector<int> arr = {1, 3, 5, 4, 3, 1, 5, 7};
	cout << uniqueNo2(arr) << endl;
	return 0;
}

