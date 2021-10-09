//nnd
using namespace std;
#include<bits/stdc++.h>
 

void solve() {
	int n;
	int maxx = -1, maxy = -1;
	cin >> n;
	for (int i=1; i<=n; ++i) {
		int x, y;
		cin >> x >> y;
		if (x == y) {
			maxx = max(maxx, x);
			maxy = max(maxy, y);
		}
		if (x < y) {
			y += x;
			maxy = max(maxy, y);
		}
		if (y < x) {
			x += y;
			maxx = max(maxx, x);
		}
	}
	cout << max(maxx, maxy) << "\n";
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;    
}