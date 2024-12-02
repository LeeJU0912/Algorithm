#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
int DP[300001];

int main() {
    FastIO

    cin >> N;

    int before = 0;
    int cnt = 0;
    int idx = 1;
    while(cnt < N) {
        cnt += idx + before;
        before = idx + before;
        idx++;
        save.push_back(cnt);
    }

    for (int i = 0; i <= N; i++) {
        DP[i] = 1e9;
    }

    for (int i = 0; i < save.size(); i++) {
        DP[save[i]] = 1;
    }
    
    for (int i = 0; i < save.size(); i++) {
        for (int j = save[i]; j <= N; j++) {
            DP[j] = min(DP[j], DP[j - save[i]] + 1);
        }
    }

    cout << DP[N];

    return 0;
}