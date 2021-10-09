//nnd
using namespace std;
#include<bits/stdc++.h>

const int maxN = 100;

struct data {
	int l, r, d;
};

struct arr {
	int val, pos;
};

bool cmp (arr a, arr b) {
	return (a.val < b.val);
}

void solve() {
	int n;
	int a[maxN];
	int b[maxN];
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> a[i];
	for (int i=1; i<=n; ++i) b[i] = a[i];
	sort(b+1, b+n+1);
	int i = 1;
	vector<data> v;
	while (i <= n) {
		if (a[i] == b[i]) {
			i++;
			continue;
		}
		int pos;
		for (int j=i; j<=n; ++j) if (b[i] == a[j]) {
			pos = j;
			break;
		}
		data x;
		x.l = i;
		x.r = pos;
		x.d = pos-i;
		v.push_back(x);
		int temp = a[i];
		a[i] = b[i];
		for (int z=i+1; z<=pos; ++z) {
			swap(temp, a[z]);
		}
		i++;
	}
	cout << v.size() << "\n";
	for (auto c : v) cout << c.l << " " << c.r << " " << c.d << "\n";
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;    
}		