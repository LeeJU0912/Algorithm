#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, M;
    cin >> N >> M;

    deque<int> plus;
    deque<int> minus;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp > 0) plus.push_back(temp);
        else minus.push_back(temp);
    }

    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end(), greater<>());

    int ans = 0;

    if (-minus.front() > plus.front()) {
        ans += -minus.front();
        for (int i = 0; i < M; i++) {
            minus.pop_front();
            if (minus.empty()) break;
        }
        while (!minus.empty()) {
            ans += -minus.front() * 2;
            for (int i = 0; i < M; i++) {
                minus.pop_front();
                if (minus.empty()) break;
            }
        }

        while (!plus.empty()) {
            ans += plus.front() * 2;
            for (int i = 0; i < M; i++) {
                plus.pop_front();
                if (plus.empty()) break;
            }
        }
    }
    else {
        ans += plus.front();
        for (int i = 0; i < M; i++) {
            plus.pop_front();
            if (plus.empty()) break;
        }
        while (!plus.empty()) {
            ans += plus.front() * 2;
            for (int i = 0; i < M; i++) {
                plus.pop_front();
                if (plus.empty()) break;
            }
        }

        while (!minus.empty()) {
            ans += -minus.front() * 2;
            for (int i = 0; i < M; i++) {
                minus.pop_front();
                if (minus.empty()) break;
            }
        }
    }

    cout << ans;



    return 0;
}