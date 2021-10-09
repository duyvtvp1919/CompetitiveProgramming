#include<bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, a[200000], t;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    t = 0;
    if(n%3 == 0)
        for(int i=1; i<=n; i=i+3){
            t = t + a[i+1] + a[i+2];
        }
    else
    if(n%3 == 1)
        for(int i=2; i<=n; i=i+3){
            t = t + a[i+1] + a[i+2] + a[2];
        }
    else
    if(n%3 == 2)
        for(int i=3;i<=n;i=i+3){
            t = t + a[i+1] + a[i+2] + a[2] + a[1];
        }
    if(n==2) t = a[2] + a[1];
    else
    if(n==1) t = a[1];
    else
    if(n==0) t = 0;
 
    cout<< t;
   
    return 0;
}