using namespace std;
#include<bits/stdc++.h>

const long long maxN = 3000;

long long row[maxN], col[maxN];
long long m, n, q;

int main() {

	cin >> m >> n >> q;
	while (q--) {
		long long k;
		cin >> k;
		if (k == 1) {
			long long r, x;
			cin >> r >> x;
			row[r] += x;
		}
		if (k == 2) {
			long long c, x;
			cin >> c >> x;
			col[c] += x;
		}
		if (k == 3) {
			long long maxC = -1, maxR = -1;
			long long x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for (long long i=x1; i<=x2; ++i) maxR = max(maxR, row[i]);
			for (long long i=y1; i<=y2; ++i) maxC = max(maxC, col[i]);
			cout << maxC + maxR << "\n";
		}
	}

 return 0;	
}