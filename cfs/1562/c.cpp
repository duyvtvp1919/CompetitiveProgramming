using namespace std;
#include<bits/stdc++.h>

const int maxN = 1e5+19;

void solve() {
	int n;
	char a[maxN];
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> a[i];
	int Max = -1, Min = maxN;
	for (int i=1; i<=n; ++i) {
		if (a[i] == '0') {
			Max = max(Max, i);
			Min = min(Min, i);
		}
	}
	if (n - Min >= n / 2) {
            cout << Min << " " << n << " " << Min + 1 << " " << n << "\n";
            return;
    }
    if (Max - 1 >= n / 2) {
            cout << 1 << " " << Max << " " << 1 << " " << Max - 1 << "\n";
            return;
    }
    cout << 1 << " " << n / 2 << " " << 2 << " " << n / 2 + 1 << "\n";
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}