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

int n, k;
int a[N], b[N], id[N][2];
set< pair<int, int> > sa, sb;
vector<int> v;

main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i], id[i][0] = 1;
    FOR(i, 1, n) cin >> b[i], id[i][1] = 1;

    id[1][1] = 2;

    sort(a + 1, a + 1 + n); 
    sort(b + 1, b + 1 + n);

    FOR(i, 2, n) sa.insert({a[i] + b[1], i}), sb.insert({b[i] + a[1], i});
    sa.insert({a[1] + b[1], 1}); sb.insert({a[2] + b[1], 1});

    while (k--) {
        pair<int, int> p = *sa.begin(), q = *sb.begin();

        //cerr << p.fi << " " << p.se << " "<< id[p.se][0] << " -- " << q.fi << " " << q.se << " " << id[q.se][1] << "\n";

        if (p.fi <= q.fi) {
            sa.erase(p);
            int x = id[p.se][0];
            if (p.se == id[x][1]) {
                sb.erase( {a[p.se] + b[x], x} );
                if (id[x][1] < n) sb.insert( {a[ ++id[x][1] ] + b[x], x} );
            }

            if (id[p.se][0] < n) sa.insert( {a[p.se] + b[ ++id[p.se][0] ], p.se} );
            v.pb(p.fi);

        } else {
            sb.erase(q);
            //++id[q.se][1];
            //if (id[q.se][1] == q.se) ++id[q.se][1];
            if (id[q.se][1] < n) sb.insert( {b[q.se] + a[ ++id[q.se][1] ], q.se} );
            v.pb(q.fi);
        }
    }

    for (auto x : v) cout << x << " " ;

}
