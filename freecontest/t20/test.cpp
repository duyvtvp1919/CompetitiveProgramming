//nnd
using namespace std;
#include<bits/stdc++.h>

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 200005
#define maxK 205
#define MOD 1000
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, k, a[maxN];
ll dp[maxK][maxN];

int main () {
    freopen("balloon.inp", "r", stdin);
    freopen("balloon.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, n) scanf("%d", &a[i]);

    dp[1][0] = -oo;
    fto(j, 1, n) dp[1][j] = a[j];
    fto(i, 2, k) {
        dp[i][0] = -oo;
        deque<int> q;
        fto(j, 1, n) {
            while (!q.empty() && dp[i-1][q.back()] <= dp[i-1][j-1]) q.pop_back();
            q.push_back(j-1);
            while (q.front() < j-m) q.pop_front();
            dp[i][j] = dp[i-1][q.front()] + 1LL*a[j]*i;
        }
    }

    ll ans = *max_element(dp[k], dp[k]+n+1);
    printf("%lld", ans);

    return 0;
}