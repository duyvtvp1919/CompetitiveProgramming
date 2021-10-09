#include <iostream>
using namespace std;
typedef long long ll;
 
ll MOD = 10000007;
ll dp[200005];
ll pangkat(ll n, ll k) {
    ll ret = 1;
    while (k) {
        if (k&1) {
            ret = (ret * n) % MOD;
        }
        k = k/2;
        n = (n*n) % MOD;
    }
    return ret;
}
 
ll calc(ll bit_pos, ll num_bits, ll num_elems) {
    if (bit_pos == num_bits) {
        return 1;
    }
    if (dp[bit_pos] != -1)
        return dp[bit_pos];
    ll &ret = dp[bit_pos];
    ll win, tie_1 = 0;
    if (num_elems % 2 == 0) {
        win = calc(bit_pos+1, num_bits, num_elems);
        tie_1 = 0;
    } else {
        win = 0;
        tie_1 = 1;
    }
    ll tie_0 = pangkat(2, num_elems - 1);
    if (num_elems % 2 == 0) {
        tie_0 = tie_0 - 1;
    }
    tie_0 = tie_0 * calc(bit_pos + 1, num_bits, num_elems);
    tie_0 = tie_0 % MOD;
    ret = (win + tie_1 + tie_0) % MOD;
    return ret;
}
 
 
int main() {
    ll t,n,k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0;i<200005;++i) {
            dp[i] = -1;
        }
        if (k == 0) {
            cout << 1 << '\n';
        } else {
            cout << calc(0, k, n) << '\n';
        }
    }
    return 0;
}