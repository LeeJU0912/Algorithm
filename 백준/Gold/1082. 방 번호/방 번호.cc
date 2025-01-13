#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int P[51];
int idxToPrice[10];
vector<pair<int, int>> sorted;

string ans;

void makeFirst() {
    int tmp = 0;

    if (sorted[0].second == 0) {
        if (sorted[1].first > M) {
            ans = "0";
            return;
        }
        ans += to_string(sorted[1].second);
        tmp = sorted[1].first;

        for (int i = 0; i < (M - tmp) / sorted[0].first; i++) {
            ans += '0';
        }

        tmp += (M - tmp) / sorted[0].first * sorted[0].first;
    }
    else {
        for (int i = 0; i < M / sorted[0].first; i++) {
            ans += to_string(sorted[0].second);
        }
        tmp = M / sorted[0].first * sorted[0].first;
    }
    
    if (tmp) {
        for (int i = 0; i < ans.size(); i++) {
            tmp -= idxToPrice[(ans[i] - '0')];
            
            int maxi = -1;
            int price = -1;
            for (int j = M - tmp; j >= 1; j--) {
                if (maxi < P[j]) {
                    maxi = P[j];
                    price = j;
                }
            }

            if (maxi == -1) {
                return;
            }

            ans[i] = maxi + '0';

            tmp += price;
        }
    }
}

int main() {
    FastIO

    for (int i = 1; i <= 50; i++) {
        P[i] = -1;
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        P[x] = i;
        idxToPrice[i] = x;
    }
    cin >> M;

    if (N == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= 50; i++) {
        if (P[i] >= 0) sorted.push_back({i, P[i]});
    }

    makeFirst();

    cout << ans;

    return 0;
}