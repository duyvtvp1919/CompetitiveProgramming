using namespace std;
#include<bits/stdc++.h>

void solve() {
	long long l, r;
	cin >> l >> r;
	if ((r/2+1) > l) cout << (r%(r/2+1)) << "\n";
	else cout << (r%l) << "\n";
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
 return 0;	
}