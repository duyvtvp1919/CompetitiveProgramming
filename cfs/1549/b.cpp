using namespace std;
#include<bits/stdc++.h>

const int maxN = 2e5+19;

void solve() {
	int a[maxN];
	int b[maxN];
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i=1; i<=n; ++i) a[i] = s[i-1]-'0';
	cin >> s;
	for (int j=1; j<=n; ++j) b[j] = s[j-1]-'0';
	// for (int i=1; i<=n; ++i) cout << a[i];
	// cout << "\n";
	// for (int i=1; i<=n; ++i) cout << b[i];
	// cout << "\n";
	a[0] = -1;
	a[n+1] = -1;
	int ans = 0;
	for (int i=1; i<=n; ++i) {
		if (b[i] == 1) {
			if (a[i] == 0) ans++;
			else {
				if (a[i-1] == 1) {
					ans ++;
					a[i-1] = -1;
				}
				else {
					if (a[i+1] == 1) {
						ans++;
						a[i+1] = -1;
					}
				}
			}
		}
	}
	cout << ans << "\n";
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}