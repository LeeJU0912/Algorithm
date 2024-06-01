#include <bits/stdc++.h>
using namespace std;

int n;
bool dp[101];
string s;
vector<string> A;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	for (int i = 0; i < s.length(); i++) {
		if (dp[i] || i==0) {
			int st = i;
			
			for (int j = 0; j < n; j++) {
				if (st + A[j].length() > s.length()) continue;

				bool flag = true;
				for (int k = 0; k < A[j].length(); k++) {
					if (A[j][k] != s[st + k]) {
						flag = false;
						break;
					}
				}

				if (flag) {
					dp[st + A[j].length()] = 1;
				}
			}
		}
	}

	cout << dp[s.length()];


	return 0;
}