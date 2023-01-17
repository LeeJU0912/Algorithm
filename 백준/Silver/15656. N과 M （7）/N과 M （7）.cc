#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> save;
vector<int> out;

void solve(int counter) {
    if (counter == M) {
        for (auto j : out) {
            cout << j << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        out.push_back(save[i]);
        solve(counter + 1);
        out.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    sort(save.begin(), save.end());

    for (int i = 0; i < N; i++) {
        out.push_back(save[i]);
        solve(1);
        out.pop_back();
    }

    return 0;
}