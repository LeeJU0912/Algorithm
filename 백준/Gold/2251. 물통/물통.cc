#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int A, B, C;
set<int> ans;
bool visited[201][201][201];

void solve() {
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, C);

    while(!q.empty()) {
        int a = get<0>(q.front());
        int b = get<1>(q.front());
        int c = get<2>(q.front());
        q.pop();

        if (visited[a][b][c]) continue;
        visited[a][b][c] = true;

        if (a == 0) {
            ans.insert(c);
        }

        // a -> b
        if (a + b > B) {
            q.emplace(a + b - B, B, c);
        }
        else {
            q.emplace(0, a + b, c);
        }

        // a -> c
        if (a + c > C) {
            q.emplace(a + c - C, b, C);
        }
        else {
            q.emplace(0, b, a + c);
        }

        // b -> a
        if (a + b > A) {
            q.emplace(A, a + b - A, c);
        }
        else {
            q.emplace(a + b, 0, c);
        }

        // b -> c
        if (b + c > C) {
            q.emplace(a, b + c - C, C);
        }
        else {
            q.emplace(a, 0, b + c);
        }

        // c -> a
        if (a + c > A) {
            q.emplace(A, b, a + c - A);
        }
        else {
            q.emplace(a + c, b, 0);
        }

        // c -> b
        if (c + b > B) {
            q.emplace(a, B, c + b - B);
        }
        else {
            q.emplace(a, c + b, 0);
        }

    }
}

int main() {
    FastIO

    cin >> A >> B >> C;

    solve();

    for (auto i : ans) {
        cout << i << '\n';
    }

    return 0;
}