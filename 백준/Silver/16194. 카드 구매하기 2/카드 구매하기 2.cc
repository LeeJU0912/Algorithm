#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> card;

int DP[1001];

int main() {
    FastIO

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        card.push_back(temp);
        DP[i] = temp;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < card.size(); j++) {
            if (i + j + 1 > N) continue;
            if (DP[i + j + 1] > DP[i] + card[j]) {
                DP[i + j + 1] = DP[i] + card[j];
            }
        }
    }

    cout << DP[N];

    return 0;
}