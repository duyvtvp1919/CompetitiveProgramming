using namespace std;
#include<bits/stdc++.h>

const int maxN = 3e5+19;

struct data {
	int val;
	int pos, next;
};

int a[maxN];
data b[maxN];

bool valcmp(data x, data y) {
	return (x.val < y.val);
}

bool nextcmp(data x, data y) {
	return x.pos < y.pos;
}

void solve() {

	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n; ++i) cin >> a[i];
	for (int i=1; i<=n; ++i) b[i].val = a[i], b[i].pos = i;
	sort (b+1, b+1+n, valcmp);
	b[1].next = 1;
	for (int i=2; i<=n; ++i) {
		b[i].next = b[i - 1].next;
		if (b[i].val != b[i-1].val) b[i].next++;
	}
	sort (b+1, b+1+n, nextcmp);
	int cnt = 1;
	for (int i=2; i<=n; ++i) {
		if (b[i].next == b[i-1].next || b[i].next == b[i-1].next+1) continue;
		cnt++;
	}
	cout << (cnt <= k? "Yes\n": "No\n");
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}