//nnd
using namespace std;
#include<bits/stdc++.h>

const long long maxN = 2e5+19;

const long long oo = 1e18;

long long n, m, k, a[maxN];
long long dp[300][maxN];

int main() {

    cin >> n >> m >> k;
    for (long long i=1; i<=n; ++i) cin >> a[i];

    dp[1][0] = -oo;
    for (long long i=1; i<=n; ++i) dp[1][i] = a[i];
    for (long long i=2; i<=k; ++i) {
        dp[i][0] = -oo;
        deque<long long> q;
        for (long long j=1; j<=n; ++j) {
            while (!q.empty() && dp[i-1][q.back()] <= dp[i-1][j-1]) q.pop_back();
            q.push_back(j-1);
            while (q.front() < j-m) q.pop_front();
            dp[i][j] = dp[i-1][q.front()] + 1LL*a[j]*i;
        }
    }

    long long ans = -oo;
    for (long long i=1; i<=n; ++i) ans = max(ans, dp[k][i]);
    cout << ans << "\n";

    return 0;
}