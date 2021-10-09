#include "bits/stdc++.h"
using namespace std;

#define FOR(i, l, r) for(int i = l; i <= r; ++i)
#define FOD(i, r, l) for(int i = r; i >= l; --i)
#define fi first
#define se second
#define bit(x, k) (1ll&((x) >> (k)))
#define debug(x) cerr << #x << " = " << x << '\n';
#define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e18;

long long count_setbits(long long N)

{ long long cnt=0;

while(N>0)

{

cnt+=(N&1);

N=N>>1;

}

return cnt;

}

int t;
string s;
int k;
int dp[20][1 << 10][2][2];
int calc(int id, int mask, int ok, int head) {
    if(count_setbits(mask) > k) return inf;
    if(id == s.size()) {
        return 0;
    }
    if(dp[id][mask][ok][head] != -1) return dp[id][mask][ok][head];
    int ret = dp[id][mask][ok][head];
    ret = inf;
    FOR(i, (ok ? 0 : (s[id] - '0')), 9) {
        int val = calc(id + 1, (head || i != 0) ? (mask | (1ll << i)) : mask, ok | (i != (s[id] - '0')), head | (i != 0));
        if(val != inf) {
            int tmp = 1;
            FOR(j, id + 2, s.size()) tmp = tmp * 10;
            ret = tmp * i + val;
            return ret;
        }

    }
    return ret;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> s >> k;
        while(s.size() != 11) s = "0" + s;
        memset(dp, -1, sizeof(dp));
        cout << calc(0, 0, 0, 0) << '\n';
    }
    return 0;
}