#include <bits/stdc++.h>

using namespace std;
#define long long long
#define pp pair<long, long>

const int N = 1e5 + 100;
const int K = 5;

long d[1 << K][N];
vector<pp> e[N];
int star[N];

void Min(long &a, long b){ a = (a > b ? b : a); }
const long inf = 2e16;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, k, m;
    cin >> n >> k >> m;
    priority_queue<pp> q;
    for (int i = 0; i < (1 << k); ++i) for (int j = 0; j < n; ++j) d[i][j] = inf;
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        --x;
        d[1 << i][x] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        e[u].push_back(pp(v, c));
        e[v].push_back(pp(u, c));
    }
    for (int mask = 0; mask < (1 << k); ++mask) {
        for (int preMask = 0; preMask <= mask / 2; ++preMask) if ((mask & preMask) == preMask) {
            int sufMask = mask ^ preMask;
            for (int i = 0; i < n; ++i) {
                Min(d[mask][i], d[preMask][i] + d[sufMask][i]);
            }
        }
        for (int i = 0; i < n; ++i) if (d[mask][i] != inf) q.emplace(-d[mask][i], i);
        while (!q.empty()) {
            int u = q.top().second;
            long dist = -q.top().first;
            q.pop();
            if (d[mask][u] != dist) continue;
         //   cerr << "Say " << mask << ' ' << u << ' ' << dist << '\n';
            for (auto t : e[u]) {
                int v = t.first;
                long c = t.second;
                if (d[mask][v] > d[mask][u] + c) {
                    d[mask][v] = d[mask][u] + c;
                    q.emplace(-d[mask][v], v);
             //       cerr << "To " << v << ' ' << d[mask][v] << '\n';
                }
            }
        }
    }
    long ans = *min_element(d[(1 << k) - 1], d[(1 << k) - 1] + n);
    cout << ans << '\n';
}