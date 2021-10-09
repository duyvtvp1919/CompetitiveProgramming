using namespace std;
#include<bits/stdc++.h>

const int maxN = 60;

bool ok(int x) {
	if (x == 1) return true;
	int t = 0;
	for (int i=2; i<=(int)sqrt(x); ++i) if (x % i == 0) t++;
	return t != 0;

}

void solve() {
	int n;
	cin >> n;
	int a[maxN];
	for (int i=1; i<=n; ++i) {
		char c;
		cin >> c;
		a[i] = (int) (c-'0');
	}
	bool ok1 = true, pos = -1;
	for (int i=1; i<=n; ++i) {
		if (ok(a[i])) {
			cout << 1 << "\n" << a[i] << "\n";
			return;
		}
	}
	//-----------------------------------------------------------
	bool ok2 = true;
	for (int i=1; i<=n; ++i) {
		for (int j=i+1; j<=n; ++j) {
			int temp = a[i]*10+a[j];
			if (ok(temp)) {
				cout << 2 << "\n" << temp << "\n";
				return;
			}
		}
	}
	//-------------------------------------------------------------
	for (int i=1; i<=n; ++i) {
		for (int j=i+1; j<=n; ++j) {
			for (int k=j+1; k<=n; ++k) {
				int temp = a[i]*100+a[j]*10+a[k];
				if (ok(temp)) {
					cout << 3 << "\n" << temp << "\n";
					return;
				}
			}
		}
	}
	// //-------------------------------------------------------------
	// for (int i=1; i<=n; ++i) {
	// 	for (int j=i+1; j<=n; ++j) {
	// 		for (int k=j+1; k<=n; ++k) {
	// 			for (int z=k+1; z<=n; ++z) {
	// 				int temp = a[i]*1000+a[j]*100+a[k]*10+a[z];
	// 				if (ok(temp)) {
	// 					cout << 4 << "\n" << temp << "\n";
	// 					return;
	// 				}
	// 			}
	// 		}
	// 	}
	// }
}

int main() {

	int T;
	cin >> T;
	//for (int i=1; i<=100; ++i) cout << i << "-" << ok(i) << "\n";
	while (T--) {
		solve();
	}

 return 0;	
}