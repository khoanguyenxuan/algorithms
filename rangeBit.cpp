#include <bits/stdc++.h>

using namespace std;

int rangeBitwiseAnd(int left, int right) {
	int ret = left;
	while (ret > 0 && left <= right) {
		ret = ret & left++; 
	}
	return ret;
}

int main() {
	cout << rangeBitwiseAnd(5, 7) << endl;
	return 0;
}