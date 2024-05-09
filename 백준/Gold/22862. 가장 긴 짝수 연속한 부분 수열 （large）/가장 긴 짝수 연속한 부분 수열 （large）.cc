#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> save;
vector<pair<int, int>> group;

int ans;

int main() {
    FastIO

    cin >> N >> K;
    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    bool first_odd = true;

    int even_counter = 0;
    int odd_counter = 0;

    for (int i = 0; i < N; i++) {
        if (save[i] % 2 == 0) first_odd = false;
        if (first_odd) continue;

        if (save[i] % 2) {
            odd_counter++;
        }
        else {
            if (odd_counter) {
                group.push_back({even_counter, odd_counter});
                odd_counter = 0;
                even_counter = 1;
            }
            else {
                even_counter++;
            }
        }
    }

    if (odd_counter) {
        group.push_back({even_counter, 0});
    }
    else if (even_counter) {
        group.push_back({even_counter, 0});
    }

    queue<pair<int, int>> q;

    int idx = 0;

    int even_temp = 0;
    int odd_temp = 0;
    while(idx < group.size()) {
        q.push(group[idx]);
        even_temp += group[idx].first;
        odd_temp += group[idx].second;

        ans = max(ans, even_temp);
        
        if (odd_temp > K) {
            while(odd_temp > K) {
                even_temp -= q.front().first;
                odd_temp -= q.front().second;
                q.pop();
            }
        }

        idx++;
    }

    cout << ans;

    return 0;
}