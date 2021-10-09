using namespace std;
#include<bits/stdc++.h>

const long long maxN = 4e5+19;

long long a[maxN];
long long dp[maxN][33];

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool Cal(long long l, long long r){
    long long k = log2(r - l + 1);
    long long x = gcd(dp[l][k], dp[r - (1<<k) + 1][k]);
    return x != 1;
}

void solve() {
    long long n;
    cin >> n;
    for (long long i=1; i<=n; ++i) cin >> a[i];
    for (long long i=1; i<=n; ++i) dp[i][0] = abs(a[i]-a[i-1]);
    for (long long j = 1; (1<<j) <= n; j++){
        for (long long i = 2; i + (1<<j) - 1 <= n; i++)
            dp[i][j] = gcd(dp[i][j - 1], dp[i + (1<<(j - 1))][j - 1]);
    }
    long long pos = 2;
    long long ans = 1;
    for (long long i=2; i<=n; ++i) {
        if (pos > n) break;
        if (pos < i) pos = i;
        while (pos <= n && Cal(i, pos)) {
            ans = max(ans, pos - i + 1 + 1);
            pos++;
        } 
    }
    cout << ans << "\n";
} 

int main() {

    long long T;
    cin >> T;
    while (T--) {
        solve();
    }

 return 0;    
}