using namespace std;
#include<bits/stdc++.h>

const long long maxN = 2000;

struct data {
    long long x, y, z, pos;
};

struct data a[maxN];
long long n, k;

bool cmp1(struct data a,struct data b) {
    return a.x > b.x;
}

bool cmp2(struct data a, struct data b) {
    return a.y > b.y;
}

bool cmp3(struct data a, struct data b) {
    return a.z > b.z;
}

set<long long> s;

int main() {

    cin >> n >> k;
    for (long long i=1; i<=n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].pos = i;
    }
    sort(a+1, a+n+1, cmp1);
    for (long long i=1; i<=k; ++i) s.insert(a[i].pos);
    sort(a+1, a+n+1, cmp2);
    for (long long i=1; i<=k; ++i) s.insert(a[i].pos);
    sort(a+1, a+1+n, cmp3);
    for (long long i=1; i<=k; ++i) s.insert(a[i].pos); 
    cout << s.size() << "\n";  
}