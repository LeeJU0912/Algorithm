#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, Q;
vector<pair<pair<int, int>, pair<int, int>>> save;
int group[100001];
int groupNum;

int main() {
    FastIO

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        save.push_back({{x1, x2}, {y, i + 1}});
    }

    sort(save.begin(), save.end());

    int idx = 1;
    for (int i = 0; i < N; i++) {
        if (!group[save[i].second.second]) groupNum++;
        group[save[i].second.second] = groupNum;

        while(idx < N && save[idx].first.first <= save[i].first.second) {
            group[save[idx++].second.second] = groupNum;
        }

        if (idx == N) break;
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        if (group[a] == group[b]) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}