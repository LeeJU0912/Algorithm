#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save[1001];

int ans = INT_MAX;

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;

            save[i].push_back(x);
        }

        sort(save[i].begin(), save[i].end(), greater());
    }

    int mini = INT_MAX;
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < N; i++) {
        pq.push({save[i][0], {i, 0}});
        mini = min(mini, save[i][0]);
    }

    while(true) {
        int maxi = pq.top().first;
        int groupNum = pq.top().second.first;
        int studentNum = pq.top().second.second;
        pq.pop();

        ans = min(ans, maxi - mini);

        if (studentNum == M - 1) break;

        pq.push({save[groupNum][studentNum + 1], {groupNum, studentNum + 1}});
        mini = min(mini, save[groupNum][studentNum + 1]);
    }

    cout << ans;

    return 0;
}