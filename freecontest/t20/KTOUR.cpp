//nnd
using namespace std;
#include<bits/stdc++.h>

const int maxN = 5000;
 
int n;
long double dp[maxN][30];
int s[maxN];
long double a[maxN];
 
 
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    swap(a[n], a[1]);
    sort(a + 1, a + n, greater<int>());
    int m = ceil(log2(n));
    int temp = 1<<(m-1);
    int last = temp + temp - n;
    vector <int> v;
    for(int i = n - last + 1; i <= n; i++) {
        v.push_back(a[i]);
    }
    reverse(v.begin(), v.end());
    int cur = n - last;
    for(int i = n - last + 1; i <= n; i++) {
        a[++cur] = 0;
        a[++cur] = v.back();
        v.pop_back();
    }
    n = cur;
    for(int i = 1; i <= n; i++)
        dp[i][0] = 1;
    for (int match = 1; match <= m; match++) {
        int sz = 1<<match;
        int cur = 0, left = 1;
        for(int i = 1; i <= n; i++) {
            cur++;
            if (cur > sz) {
                cur = 1;
                left += sz;
            }
            int right = left + sz - 1;
            int l = left, r = right, mid = (left + right)/2;
            if (i <= mid) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
            long double g = 0;
            for(int j = l; j <= r; j++) {
                g += dp[j][match-1];
            }
            if (a[i] != 0) {
                for (int j = l; j <= r; j++) {
                    assert(i != j);
                    dp[i][match] += dp[j][match-1] * (a[i] / (a[j] + a[i]));
                }
             }
            dp[i][match] *= dp[i][match-1];
        }
 
    }
    cout << setprecision(6) << fixed << dp[n][m] << "\n";
}