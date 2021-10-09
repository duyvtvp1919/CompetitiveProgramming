#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 12;
const long long Mod = 1e9 + 7;
const long long oo = 1e18;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back

#define Bit(a, i) (((long long)a>>((int)i - 1))&1)
#define dBit(x) __builtin_popcountll((long long)x)
#define FOR(i, a, b) for (int _ = a, _ = b, i = _; i <= _; i++)
#define FORD(i, a, b) for (int _ = a, _ = b, i = _; i >= _; i--)
#define FIX(n, x) cout << setprecision((int)n) << fixed << x << "\n";

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m1, m2;
int dad[N][3], cnt[N][3];
vector<int> g[N][3];

int Get(int u, int k) {
    if (dad[u][k] == u) return u;
    return dad[u][k] = Get(dad[u][k], k);
}

void Join(int u, int v, int k) {
    int pu = Get(u, k), pv = Get(v, k);
    if (cnt[pu][k] < cnt[pv][k]) swap(pu, pv);
    dad[pv][k] = pu; cnt[pu][k] += cnt[pv][k];

    return ;
}

bool Check(int u, int v) {
    int pu = Get(u, 1), pv = Get(v, 1);
    if (pu == pv) return false;
    pu = Get(u, 2), pv = Get(v, 2);
    if (pu == pv) return false;
    Join(u, v, 1); Join(u, v, 2);
    return true;

}

main(){
    #define file "abc"
    freopen (file ".inp", "r", stdin);
    freopen (file ".out", "w", stdout);
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m1 >> m2;

    FOR(i, 1, n) dad[i][2] = dad[i][1] = i, cnt[i][1] = cnt[i][2] = 1;

    FOR(i, 1, m1) {
        int u, v; cin >> u >> v;
        Join(u, v, 1);
    }

    FOR(i, 1, m2) {
        int u, v; cin >> u >> v;
        Join(u, v, 2);
    }

    vector<pair<int, int> > ans;
    FOR(i, 1, n - 1) FOR(j, i + 1, n) {
        if (Check(i, j)) {
            ans.pb({i, j});
        }
    }

    cout << ans.size() << "\n";
    FOR(i, 0, ans.size() - 1) cout << ans[i].fi <<  " " << ans[i].se << "\n"; 
    
}