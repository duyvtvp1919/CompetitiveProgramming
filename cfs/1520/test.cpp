#include<bits/stdc++.h>
using namespace std;

const int N = 3e6 + 12;
const long long Mod = 1e9 + 7;
const long long oo = 1e18;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back

#define Bit(a, i) (((int)a>>((int)i - 1))&1)
#define dBit(x) __builtin_popcount((int)x)
#define FOR(i, a, b) for (int _ = a, _ = b, i = _; i <= _; i++)
#define FORD(i, a, b) for (int _ = a, _ = b, i = _; i >= _; i--)
#define FIX(n, x) cout << setprecision((int)n) << fixed << x << "\n";

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int ntest, n;
long long a[N], L[N], R[N];

main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> ntest;
    while (ntest--) {
        cin >> n;
        int len = 0;
        FOR (i, 1, n) {
            char x;
            cin >> x;
            if (x == '*') {
                a[len + 1] = i - len;
                len++;
            }
        }
        L[0] = R[len + 1] = 0;
        FOR (i, 1, len) L[i] = L[i - 1] + a[i];
        FORD (i, len, 1) R[i] = R[i + 1] + a[i];

        int pos = 1;
        long long ret = oo;

        if (len == 0) {
            cout << 0 << "\n"; continue;
        }

        FOR (val, 1, n - len + 1) {
            while (a[pos] <= val && pos <= len) pos++; pos--;
            long long tmp = 0; 
            tmp = (1LL*pos * val - L[pos]) + (R[pos + 1] - 1LL*val * (len - pos) );
            //cout << pos << " " << val << "\n"; 
            ret = min(ret, tmp);
        } 
        cout << ret << "\n";
        //FOR (i, 1, len) cout << a[i] << " " ; cout << "\n";
    }
    
}