using namespace std;
#include<bits/stdc++.h>

const int maxN = 3e5+19;

long long d[maxN];

void solve() {
	int a[maxN];
	int n, q;
	cin >> n >> q;
	for (int i=1; i<=n; ++i) {
		char c;
		cin >> c;
		a[i] = (c == '+')? 1: -1;
	}
	for (int i=1; i<=n; ++i) {
		int tmp = (i % 2)? 1: -1;
        d[i] = d[i - 1] + tmp * a[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (d[r] == d[l-1]) {
			cout << 0 << "\n";
			continue;
		}
		if ((r-l)%2 == 0) {
 			cout << 1 << "\n";
 			continue;
 		}
 		cout << 2 << "\n";
	}
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}