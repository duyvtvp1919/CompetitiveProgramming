//nnd
using namespace std;
#include<bits/stdc++.h>

const int maxN = 1e5+19;

int a[maxN];
int dp[30][maxN];
int n;

int get(int u, int v){
    int k = __lg(v-u+1);
    return (min(dp[k][u], dp[k][v-(1<<k)+1])+u-1);
}

int main() {

    cin >> n;
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=1; i<=n; ++i) {
        dp[0][i] = a[i]-i;
    }
    for(int k=1; (1<<k)<=n; ++k)
        for(int i=1; i+(1<<k)-1<=n; ++i)
            dp[k][i] = min(dp[k-1][i], dp[k-1][i+(1<<(k-1))]);

    int ans = 0;
    for (int i=1; i<=n; ++i) {
        int l = i, r = n, rs = i-1;
        while (l <= r) {
            int mid = (l+r)>>1;
            if (get(i, mid)>=0) {
                rs = mid;
                l = mid+1;
            } else r = mid-1;
        }
        ans = max(ans, rs-i+1);
    }
    cout << ans << "\n";

 return 0;    
}