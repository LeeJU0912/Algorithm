#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int before[1001];
int after[1001];
int gap[1001];

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> before[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> after[i];
    }
    for (int i = 0; i < N; i++) {
        gap[i] = after[i] - before[i];
    }

    int ans = 0;
    queue<vector<int>> minus, plus;
    vector<int> tmp;
    bool isMinus = false;

    if (gap[0] < 0) {
        isMinus = true;
    }
    tmp.push_back(gap[0]);

    for (int i = 1; i < N; i++) {
        if (gap[i] < 0) {
            if (!isMinus) {
                plus.push(tmp);
                tmp.clear();
                isMinus = true;
            }
        }
        else {
            if (isMinus) {
                minus.push(tmp);
                tmp.clear();
                isMinus = false;
            }
        }
        tmp.push_back(gap[i]);
    }

    if (isMinus) {
        minus.push(tmp);
    }
    else {
        plus.push(tmp);
    }

    tmp.clear();

    while(!plus.empty()) {
        auto x = plus.front();
        plus.pop();

        int mini = INT_MAX;
        for (auto y : x) {
            mini = min(mini, y);
        }

        ans += mini;

        for (auto y : x) {
            if (y - mini == 0) {
                if (tmp.empty()) continue;
                plus.push(tmp);
                tmp.clear();
            }
            else {
                tmp.push_back(y - mini);
            }
        }

        if (!tmp.empty()) plus.push(tmp);
        tmp.clear();
    }

    while(!minus.empty()) {
        auto x = minus.front();
        minus.pop();

        int maxi = INT_MIN;
        for (auto y : x) {
            maxi = max(maxi, y);
        }

        ans += abs(maxi);

        for (auto y : x) {
            if (y - maxi == 0) {
                if (tmp.empty()) continue;
                minus.push(tmp);
                tmp.clear();
            }
            else {
                tmp.push_back(y - maxi);
            }
        }

        if (!tmp.empty()) minus.push(tmp);
        tmp.clear();
    }

    cout << ans;

    return 0;
}