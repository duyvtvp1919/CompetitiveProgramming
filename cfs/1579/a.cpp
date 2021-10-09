//nnd
using namespace std;
#include<bits/stdc++.h>



void solve() {
	string s;
	cin >> s;
	int ca = 0, cb = 0, cc = 0;
	for (auto c : s) {
		ca += (c == 'A');
		cb += (c == 'B');
		cc += (c == 'C');
	}
	cout << (ca+cc == cb ? "YES\n" : "NO\n");
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;    
}		