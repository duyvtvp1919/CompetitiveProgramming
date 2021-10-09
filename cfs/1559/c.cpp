using namespace std;
#include<bits/stdc++.h>

const int maxN = 2e4;

void solve() {
	int n;
	int a[maxN];
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> a[i];
	if (a[1] == 1) {
		cout << n+1 << " ";
		for (int i=1; i<=n; ++i) cout << i << " ";
		cout << "\n";
		return;
	}
	bool ok = false;
	int pos = 0;
	for (int i=1; i<=n-1; ++i) if (a[i] == 0 && a[i+1] != 0) {
		ok = true; 
		pos = i;
	}
	if (ok == false) {
		if (a[n] != 0) cout << -1 << "\n";
		else {
			for (int i=1; i<=n+1; ++i) cout << i << " ";
		}
		return;
	}
	//cout << "-" << pos << "-";
	for (int i=1; i<=pos; ++i) cout << i << " ";
    cout << n + 1 << " ";
    for (int i=pos+1; i<=n; ++i) cout << i << " "; 
    cout << "\n";

}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}