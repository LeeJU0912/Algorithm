#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> go;
vector<int> save;

void solve(int count, int now, int sum) {
    if (sum > 100) return;
    else if (count == 7 && sum == 100) {
        for (auto i : go) {
            cout << i << '\n';
        }
        return;
    }
    if (now > 8) return;
    if (8 - now < 7 - count) return;

    for (int i = 1; i <= 3; i++) {
        int next = now + i;
        if (next > 8) continue;
        go.emplace_back(save[next]);
        solve(count + 1, next, sum + save[next]);
        go.pop_back();
    }
}

int main() {
    FastIO

    save = vector<int>(9);

    for (int i = 0; i < 9; i++) {
        cin >> save[i];
    }

    for (int i = 0; i < 3; i++) {
        go.emplace_back(save[i]);
        solve(1, i, save[i]);
        go.pop_back();
    }

    return 0;
}