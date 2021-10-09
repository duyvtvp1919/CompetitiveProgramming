//nnd
using namespace std;
#include<bits/stdc++.h>

const int maxN = 505;
const long long inf = 1e18;
 
int n, m;
int a[maxN][maxN];
long long col[maxN];
long long row[3][maxN];
long long res = -inf;

void solve() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            col[j] = 0;
            row[0][j] = row[0][j-1] + a[i][j];
        }
        for (int j = i + 1; j <= m; j++) {
            for (int k = 1; k <= n; k++)
                row[1][k] = row[1][k-1] + a[j][k];
 
            long long best = inf;
            for (int k = 1; k <= n; k++) {
                res = max (res, col[k] + row[0][k] + row[1][k] - best);
                best = min (best, row[0][k-1] + row[1][k-1] - col[k]);
            }
 
            for (int k = 1; k <= n; k++)
                col[k] = col[k] + a[j][k];
        }
    }
}
 
int main() {
 
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
 
    solve();   
 
    cout << res;
 
    return 0;
}   