#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    vector<pair<int, int>> save;

    for (int i = 0; i < N; i++) {
        int s, t;
        cin >> s >> t;
        save.emplace_back(s, t);
    }

    sort(save.begin(), save.end());

    priority_queue<int, vector<int>, greater<>> pq;

    pq.push(save[0].second);

    for (int i = 1; i < N; i++) {
        if (save[i].first >= pq.top()) {
            pq.pop();
            pq.push(save[i].second);
        }
        else {
            pq.push(save[i].second);
        }
    }

    cout << pq.size();


    return 0;
}