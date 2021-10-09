#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 12;
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

int n;
int L[N], R[N], a[N];
long long ret;
string s;

main(){
    // #define file "abc"
    // freopen (file ".inp", "r", stdin);
    // freopen (file ".out", "w", stdout);
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> s;
    s = ' ' + s;

    FOR(i, 1, s.size() - 1) {
    	if (s[i] == '<') L[i] = L[i - 1] + 1;
    }

    FORD(i, s.size() - 1, 1) if (s[i] == '>') R[i - 1] = R[i] + 1;

    int n = s.size() -1 ;

   //FOR(i, 0, n) cout << L[i] << " " << R[i] << "\n";

    FOR(i, 0, s.size() - 1) a[i] = max(L[i], R[i]), ret += 1LL*a[i];

    //FOR(i, 0, s.size() - 1) cout << a[i] << " "; cout << "\n";
    
    cout << ret ;

}
