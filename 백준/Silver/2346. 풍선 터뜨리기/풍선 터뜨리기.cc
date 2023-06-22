#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int main() {
    FastIO

    cin >> N;

    deque<pair<int, int>> dq;

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        dq.push_back({i, temp});
    }

    while(!dq.empty()) {
        auto now = dq.front();
        dq.pop_front();

        cout << now.first << ' ';

        if (now.second < 0) {
            for (int i = 0; i < -now.second; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        else {
            for (int i = 1; i < now.second; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
    
    return 0;
}