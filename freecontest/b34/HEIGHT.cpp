#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 12;
const long long Mod = 1e9 + 7;
const long long oo = 1e18;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back

#define Bit(a, i) (((long long)a>>((int)i - 1))&1)
#define dBit(x) __builtin_popcountll((long long)x)
#define FOR(i, a, b) for (int _ = a, __ = b, i = _; i <= __; i++)
#define FORD(i, a, b) for (int _ = a, __ = b, i = _; i >= __; i--)
#define FIX(n, x) cout << setprecision((int)n) << fixed << x << "\n";

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int ntest, n;
int a[N], ret[N];
pair<int, int> q[N];

main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> ntest;
    while (ntest--) {
    	cin >> n;
    	FOR(i, 1, n) cin >> a[i], ret[i] = 0;
    	int m = 1;
    	q[0] = {1e9 + 2, 0};
    	q[1] = {a[1], 1};
    	FOR(i, 2, n) {
    		while (a[i] > q[m].fi) m--;
    		if (a[i] == q[m].fi) q[m].se++, ret[i] += q[m].se - 1;
    		else q[++m] = {a[i], 1};
    	}
    	q[1] = {a[n], 1};
    	FORD(i, n - 1, 1) {
    		while (a[i] > q[m].fi) m--;
    		if (a[i] == q[m].fi) q[m].se++, ret[i] += q[m].se - 1;
    		else q[++m] = {a[i], 1};
    	}

    	FOR(i, 1, n) cout << ret[i] << " "; cout <<"\n";

    }

    
}
