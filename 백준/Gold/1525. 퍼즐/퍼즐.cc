#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans = INT_MAX;

set<string> st;

bool out_range(int a, int b) {
    if (a < 0 || a >= 3 || b < 0 || b >= 3) return true;
    else return false;
}

pair<int, int> find_zero_idx(const string& x) {
    int idx = x.find('0');

    return {idx / 3, idx % 3};
}

string start;

void solve() {
    queue<pair<int, string>> q;

    q.push({0, start});

    while(!q.empty()) {
        int now_count = q.front().first;
        string now_puzzle = q.front().second;
        q.pop();

        if (st.find(now_puzzle) == st.end()) st.insert(now_puzzle);
        else continue;

        if (now_puzzle == "123456780") {
            ans = min(ans, now_count);
            return;
        }

        pair<int, int> now_zero_idx = find_zero_idx(now_puzzle);

        for (int i = 0; i < 4; i++) {
            int next_x = now_zero_idx.first + dx[i];
            int next_y = now_zero_idx.second + dy[i];

            if (out_range(next_x, next_y)) continue;

            string change = now_puzzle;

            swap(change[now_puzzle.find('0')], change[next_x * 3 + next_y]);

            q.push({now_count + 1, change});
        }
    }
}

int main() {
    FastIO
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c;
            cin >> c;
            start += c;
        }
    }

    solve();

    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}