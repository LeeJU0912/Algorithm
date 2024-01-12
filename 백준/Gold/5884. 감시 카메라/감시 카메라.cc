#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

vector<pair<int, int>> save;
bool ans;

void solve(int counter, vector<pair<int, int>> line) {
    if (ans) return;
    if (line.size() > 3) return;
    if (counter == N) {
        ans = true;
        return;
    }

    bool in_line = false;
    for (int i = 0; i < line.size(); i++) {
        auto now = save[counter];

        if (now.first == line[i].first) {
            solve(counter + 1, line);
            in_line = true;
            break;
        }

        if (now.second == line[i].second) {
            solve(counter + 1, line);
            in_line = true;
            break;
        }
    }
    if (!in_line) {
        line.push_back({save[counter].first, -1});
        solve(counter + 1, line);
        line.pop_back();

        line.push_back({-1, save[counter].second});
        solve(counter + 1, line);
        line.pop_back();
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        save.push_back({x, y});
    }

    if (save.size() <= 3) {
        cout << 1;
        return 0;
    }

    solve(1, {{save[0].first, -1}});
    solve(1, {{0, save[0].second}});

    if (ans) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}