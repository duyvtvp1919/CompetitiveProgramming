using namespace std;
#include<bits/stdc++.h>

const int maxN = 500;
const int MOD = 1e9+7;
long long x[maxN];
long long dp[3][2*maxN*maxN+19];

void solve() {
	long long n, a;
	cin >> n >> a;
	for (long long i=1; i<=n; ++i) {
		cin >> x[i];
	}
	memset(dp, 0, sizeof(dp));
	long long N = n+1;
	dp[0][N*N] = 1;
	for(long long i=1; i<=n; ++i) {
        for(long long j=1; j <=2*N*N; ++j) {
            if (dp[0][j] > 0) {
                dp[1][j] += dp[0][j];
                dp[1][j] = dp[1][j]%MOD;
                dp[1][j+(x[i]-a)] += dp[0][j];
                dp[1][j+(x[i]-a)] = dp[1][j+(x[i]-a)] % MOD;
            }
        }
        for(long long j=1; j <=2*N*N; ++j) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    long long ans = dp[0][N*N]-1;
    cout << ans%MOD << "\n";

}

int main() {

	long long T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}