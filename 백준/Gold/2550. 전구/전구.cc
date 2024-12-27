#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int from[10001];
int to[10001];
int order[10001];

int DP[10001];
int trace[10001];


int main() {
    FastIO

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        from[x] = i;
        to[i] = x;
    }
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        order[from[x]] = i;
    }

    int maxi = 1;
    for (int i = 1; i <= N; i++) {
        DP[i] = max(DP[i], 1);
        for (int j = i + 1; j <= N; j++) {
            if (order[i] < order[j]) {
                if (DP[i] + 1 > DP[j]) {
                    trace[j] = i;
                    DP[j] = DP[i] + 1;
                    maxi = max(maxi, DP[j]);
                }
            }
        }
    }

    vector<int> ans;
    int idx = N;
    while(DP[idx] != maxi) idx--;
    while(idx) {
        ans.push_back(to[idx]);
        idx = trace[idx];
    }
    sort(ans.begin(), ans.end());

    cout << maxi << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }

    return 0;
}