#include<bits/stdc++.h>
using namespace std;

const int M = 5e6;
const int N = 5e6 + 12;
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

int n, x, m = 0;
int a[N], d[N];

main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    
    x = a[1];
    FOR(i, 2, n) x = __gcd(x, a[i]);

    FOR(i, 1, n) a[i] /= x, d[a[i]]++, m = max(m, a[i]);

    int ans = n;
    FOR(i, 2, m) {
        int t = 0;
        for(int j = i; j <= m; j += i) t += d[j];
        ans = min(ans, n - t);
    }

    if (ans == n) ans = -1;

    cout << ans ;
    
}
