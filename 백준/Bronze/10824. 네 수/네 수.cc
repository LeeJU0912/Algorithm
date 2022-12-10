#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {

	string a, b, c, d;	

	cin >> a >> b >> c >> d;

	

	a += b;

	c += d;

	

	cout << stoll(a) + stoll(c);

	

	return 0;

}