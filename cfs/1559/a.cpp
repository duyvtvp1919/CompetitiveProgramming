using namespace std;
#include<bits/stdc++.h>

const int maxN = 300;

void solve() {
	int n;
	long long a[maxN];
	cin >> n;
    for (int i=1; i<=n; ++i) cin >> a[i];
   	long long ans = a[1];
	for (int i=2; i<=n; ++i) ans = ans&a[i];
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