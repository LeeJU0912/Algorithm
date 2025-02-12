#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> graph[51];
vector<int> subordinate[51];

int calcTime(int idx) {
    int ret = 0;
    for (int i = 0; i < graph[idx].size(); i++) {
        int next = graph[idx][i];
        subordinate[idx].push_back(calcTime(next));
    }

    sort(subordinate[idx].begin(), subordinate[idx].end(), greater());

    for (int i = 0; i < subordinate[idx].size(); i++) {
        ret = max(ret, subordinate[idx][i] + i);
    }

    return ret + 1;
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int boss;
        cin >> boss;

        if (i == 0) continue;
        graph[boss].push_back(i);
    }

    cout << calcTime(0) - 1;

    return 0;
}