#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int save[100001];

map<int, int> chk;
vector<pair<int, int>> pairs;

long long ans;

long long getValue(int start, int end) {
    long long temp = 0;
    for (int i = 1; i <= end - start + 1; i++) {
        temp += i;
    }

    return temp;
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    int start_idx = 0;
    for (int i = 0; i < N; i++) {
        if (chk.find(save[i]) != chk.end()) {
            pairs.push_back({start_idx, i - 1});

            start_idx = max(start_idx, chk[save[i]] + 1);
            chk.erase(save[i]);
        }

        chk[save[i]] = i;
    }

    pairs.push_back({start_idx, N - 1});

    ans += getValue(pairs[0].first, pairs[0].second);
    for (int i = 1; i < pairs.size(); i++) {
        ans += getValue(pairs[i].first, pairs[i].second);

        if (pairs[i].first <= pairs[i - 1].second) {
            ans -= getValue(pairs[i].first, pairs[i - 1].second);
        }
    }

    cout << ans;

    return 0;
}