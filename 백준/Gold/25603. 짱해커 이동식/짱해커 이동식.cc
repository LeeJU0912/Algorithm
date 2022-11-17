#include <bits/stdc++.h>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;

    vector<int> cost(N);

    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    int s = 0;
    int minCost = cost[0];
    int minIdx = 0;
    int ans = cost[0];

    for (int i = s; i < s + K; i++) {
        if (cost[i] <= minCost) {
            minIdx = i;
            minCost = cost[i];
            ans = minCost;
        }
    }
    s = minIdx + 1;

    while (s + K <= N) {
        deque<int> dq;
        int i = s;
        int minWindow = 0;
        int minWindowIdx = 0;
        for (int j = i; j < N; j++) {
            if (cost[j] <= ans) {
                s = j + 1;
                break;
            }
            else {
                dq.push_back(cost[j]);
                if (minWindow == 0) {
                    minWindow = cost[j];
                    minWindowIdx = j;
                }
                else {
                    if (cost[j] <= minWindow) {
                        minWindow = cost[j];
                        minWindowIdx = j;
                    }
                }
                if (dq.size() >= K) {
                    s = minWindowIdx + 1;
                    ans = minWindow;
                    break;
                }
            }
        }
    }

    cout << ans;


    return 0;
}