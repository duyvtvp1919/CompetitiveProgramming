//nnd
using namespace std;
#include<bits/stdc++.h>

long long l, r;

long long sol(long long x) {
	long long temp = 0;
	while (x > 0) {
		x = x >> 1;
		temp += x;
	}
	return temp;
}

int main() {

	cin >> l >> r;
	cout << sol(r) - sol(l-1) << "\n";

 return 0;    
}