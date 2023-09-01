#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save;

int main() {
	FastIO
	
	cin >> N >> M;
	save = vector<int>(N);
	
	for (int i = 0; i < N; i++) {
		cin >> save[i];
	}
	
	sort(save.begin(), save.end());
	
	
	int ans = INT_MAX;
	for (int i = 0; i < N; i++) {
		int start = i;
		int end = N - 1;
		int temp;
		
		while (start <= end) {
			int mid = (start + end) / 2;
			
			if (save[mid] - save[i] >= M) {
				temp = save[mid] - save[i];
				end = mid - 1;
			}
			else start = mid + 1;
		}
		
		ans = min(ans, temp);
	}
	
	cout << ans;
	
	return 0;
}