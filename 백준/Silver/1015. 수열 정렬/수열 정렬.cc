#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<pair<int, int>> save;
int ans[1001];

int main() {
    FastIO

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back({temp, i});
    }


    sort(save.begin(), save.end());

    for (int i = 0; i < N; i++) {
        ans[save[i].second] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}