#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int K, N;

int sosu[101];

priority_queue<int, vector<int>, greater<int>> pq;
set<int> st;

int main() {
	FastIO
	
	cin >> K >> N;
	
	for (int i = 0; i < K; i++) {
		cin >> sosu[i];
		pq.push(sosu[i]);
	}
	
	for (int i = 0; i < N; i++) {
		long long now = pq.top();
		pq.pop();
		
		if (st.find(now) != st.end()) {
			i--;
			continue;
		}
		st.insert(now);
		
		if (i == N - 1) {
			cout << now;
			break;
		}
		
		for (int j = 0; j < K; j++) {
			if (now * sosu[j] > INT_MAX) continue;
			pq.push(now * sosu[j]);
		}
	}
	
	return 0;
}