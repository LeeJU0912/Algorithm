#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, L;
vector<pair<int, int>> save;
deque<pair<int, int>> dq;

int main() {
    FastIO

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back({temp, i});
    }

    for (int i = 0; i < N; i++) {
        if (!dq.empty()) {
            if (dq.front().second == i - L) {
                dq.pop_front();
            }
        }
        while(!dq.empty() && dq.back().first > save[i].first) dq.pop_back();

        dq.push_back(save[i]);

        cout << dq.front().first << ' ';
    }

    return 0;
}