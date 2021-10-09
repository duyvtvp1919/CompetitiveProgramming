//nnd
using namespace std;
#include<bits/stdc++.h>



int main() {

	int a, b, c;
	cin >> a >> b >> c;
	cout << (((a==b+c) || (b==a+c) || (c==a+b)) ? 1 : 0) << "\n";

 return 0;    
}