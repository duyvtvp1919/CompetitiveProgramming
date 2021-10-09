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

long long nq, n, d;
int a[N];

main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> nq;
    while (nq--) {
        cin >> n >> d;
        long long t = 0;
        FOR(i, 1, n) {
            long long x; cin >> x;
            t += x;
        }
        long long Max = d/2*n;
        //if (d%2 == 0) {
            if (n%2 == 0) {
                Max = d*(n/2);
                if (Max < t) cout << "NO\n";
                else cout << "YES\n";
            }
            else {
                Max = d*(n/2+1);
                if (Max < t) cout << "NO\n";
                else cout << "YES\n";
            }
        //}
        // else {
        //     if (n%2 == 0) {
        //         Max += n/2;
        //         if (Max < t) cout << "NO\n";
        //         else cout << "YES\n";
        //     }
        //     else {
        //         Max += n/2+1;
        //         if (Max < t) cout << "NO\n";
        //         else cout << "YES\n";
        //     }
        // }
    }
    
}
