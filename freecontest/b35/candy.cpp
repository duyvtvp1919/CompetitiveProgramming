//nnd
using namespace std;
#include<bits/stdc++.h>

long long n, m;

int main() {

    cin >> n >> m;
    long long sum = ((n+1)*n)/2;
    if (m < sum) return cout << -1, 0;
    int minn = 1, maxx = n;
    m -= sum;
    minn += (m/n);
    maxx += (m/n);
    cout << minn << " " << maxx+(m%n > 0);

 return 0;    
}