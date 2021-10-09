using namespace std;
#include<bits/stdc++.h>

int n, m, dp[55][55];
char a[50], b[50];
int main()
{
    cin >> n >> m;
    int i, j, k;
    for(i=0; i<=n; ++i)
        for(j=0; j<=m; ++j)
         cin >> dp[i][j];
    for(i=1; i<30; ++i)
         a[i] = 'a'-1+i;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j) {
            if(dp[i][j] != max(dp[i - 1][j], dp[i][j - 1])) {
                if(b[j]) {
                    for(k=1; k<=m; ++k)
	                    if(b[k] == a[i])
	                    b[k] = b[j];
                    for(k=1; k<=n; ++k)
                        if(a[i]==a[k] && k!=i) a[k] = b[j];
                    a[i] = b[j];
                }
                else
                    b[j] = a[i];
            }
        }
 
    for(i=1; i<=m; ++i)
        if(!b[i]) b[i] = 'z';
 	a[n+1] = b[m+1] = 0;
    cout << (a+1) << endl << (b+1) << endl;
    return 0;
}