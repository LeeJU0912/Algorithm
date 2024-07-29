#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, S;
vector<pair<int, int>> save;
int range[300001];
int DP[300001];
int ans;

void preCalc() {
    for (int i = 1; i <= N; i++) {
        int first = 1;
        int last = i - 1;
        int end = -1;
        while(first <= last) {
            int mid = (first + last) / 2;

            if (save[mid].first > save[i].first - S) {
                last = mid - 1;
            }
            else {
                first = mid + 1;
                end = mid;
            }
        }

        range[i] = end;
    }
}

int main() {
    FastIO

    cin >> N >> S;
    save = vector<pair<int, int>>(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> save[i].first >> save[i].second;
    }

    sort(save.begin() + 1, save.end());

    preCalc();

    for (int i = 1; i <= N; i++) {
        DP[i] = max(DP[i - 1], DP[range[i]] + save[i].second);
    }

    cout << DP[N];

    return 0;
}