using namespace std;
#include<bits/stdc++.h>

const int maxN = 500;
typedef pair <long long, long long> ii;
#define fi first
#define se second

long long n;
long long res = 0;
ii a[maxN];

long long ad( long long i, long long j, long long k ) {
    ii u = ii(a[j].fi-a[i].fi, a[j].se-a[i].se);
    ii v = ii(a[k].fi-a[j].fi, a[k].se-a[j].se);
    long long ans = u.fi*v.se-v.fi*u.se ;
    return ans;
}

long long calc( long long u1, long long v1, long long k1) {
    ii u = a[u1];
    ii v = a[v1];
    ii k = a[k1];
    return abs((v.fi-u.fi)*(k.se-u.se)-(k.fi-u.fi)*(v.se-u.se));
}

void sol( long long i, long long j )
{
    long long am = 0 ;
    long long du = 0 ;

    long long cntam = 0 ;
    long long cntdu = 0 ;

    for (int i1 = 1; i1<=n; ++i1) if( i1 != i && i1 != j )
    {
        long long tmp = ad(i, j, i1);

        if (tmp == 0) continue ;
        if (tmp > 0) {
            du = max(du, calc(i ,j, i1));
            cntdu ++;
        }
        else {
            am = max(am, calc(i ,j, i1)) ;
            cntam ++;
        }
    }

    if(cntam==0 || cntdu==0) du = 0, am = 0 ;
    res = max(res, du+am);
}

void solve() {
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> a[i].fi >> a[i].se;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            sol(i, j);
        }
    }
    cout << res << "\n";
}

int main() {

    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }

 return 0;    
}