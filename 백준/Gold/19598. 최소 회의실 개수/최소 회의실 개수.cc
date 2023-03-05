#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    FastIO

    int N;
    cin >> N;

    vector<pair<int, int>> save;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        save.emplace_back(a, b);
    }

    sort(save.begin(), save.end());

    int ans = 1;
    priority_queue<int, vector<int>, greater<>> fin;

    fin.push(save[0].second);

    for (int i = 1; i < save.size(); i++) {
        int comp_end = fin.top();
        if (comp_end <= save[i].first) {
            fin.pop();
            fin.push(save[i].second);
        }
        else {
            fin.push(save[i].second);
            ans++;
        }
    }

    cout << ans;

    return 0;
}