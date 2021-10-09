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

int ntest, n, k;
long long chan, le;
long long p[N], q[N], gt[N];

long long Pow(long long a, long long b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	while (b) {
		long long t = Pow(a, b / 2) % Mod;
		t = (t * t) % Mod;
		if (b % 2 == 0) return t;
		else return (t * a) % Mod;
	}
	return 0;
}

long long C(long long k, long long n) {
	long long t = (gt[k] * gt[n - k]) % Mod;
	t = Pow(t, Mod - 2)  % Mod;
	t = (t * gt[n]) % Mod;
	return t;
}

main(){
    #define file "abc"
    freopen(file ".inp", "r", stdin);
    freopen(file ".out", "w", stdout);
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> ntest;

    p[0] = 1;
    FOR(i, 1, 2e5) p[i] = (p[i - 1] * 2) % Mod;
    gt[0] = 1;
    FOR(i, 1, 2e5) gt[i] = (gt[i - 1] * i) % Mod;

    while (ntest--) {
    	cin >> n >> k;
    	long long ans = 0, tmp = 0;
    	if (n % 2 != 0) {
            for (int i = 0; i < n; i += 2) tmp = (tmp + C(i, n)) % Mod;
            FOR(i, 0, k) ans = (ans + C(i, k) * Pow(tmp, k - i) % Mod) % Mod;
            cout <<  ans  << "\n";
        } else {
            for (int i = 0; i < n; i += 2) tmp = (tmp + C(i, n)) % Mod;
            FOR(i, 1, k) ans = (ans + Pow(tmp, i - 1) * Pow(p[k - i], n) % Mod) % Mod;
            ans = (ans + Pow(tmp, k)) % Mod;
            cout << ans << "\n";
        }
    }
    

}