using namespace std;
#include<bits/stdc++.h>

long long n;

int digits(long long n) {
	int temp = 0;
	while (n > 0) {
		temp++;
		n /=  10;
	}
	return temp;
}

int mindig(long long n) {
	int temp = 10;
	while (n > 0) {
		int temp1 = n%10;
		temp = min(temp, temp1);
		n /= 10;
	}
	return temp;
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		long long temp = pow(10, digits(n)-1);
		long long temp1 = n/temp;
		long long temp2 = (temp*10-1)/9*temp1;
		if (n < temp2) temp1--;
		cout << (9*(digits(n)-1)+temp1) << "\n";
	}

 return 0;	
}