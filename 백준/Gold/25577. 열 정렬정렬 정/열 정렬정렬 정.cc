#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
map<int, int> mp;

int ans;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);

        mp[temp] = i;
    }

    vector<int> sorted = save;

    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < N; i++) {
        if (save[i] != sorted[i]) {
            int idx = mp[sorted[i]];

            mp[save[i]] = idx;
            mp[sorted[i]] = i;

            int val = save[i];
            save[i] = save[idx];
            save[idx] = val;

            ans++;
        }
    }

    cout << ans;

    return 0;
}