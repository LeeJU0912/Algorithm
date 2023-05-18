#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int Plus[5] = {60, 10, -10, 1, -1};

struct save {
    int a, b, c, d, e, f;
};

bool visited[61];
save DP[61];

void solve() {
    queue<save> q;
    q.push({0, 0, 0, 0, 0, 0});

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        if (visited[now.f] || now.f < 0 || now.f > 60) continue;
        visited[now.f] = true;
        DP[now.f] = now;
        q.push({now.a, now.b, now.c, now.d, now.e + 1, now.f + Plus[4]});
        q.push({now.a, now.b, now.c, now.d + 1, now.e, now.f + Plus[3]});
        q.push({now.a, now.b, now.c + 1, now.d, now.e, now.f + Plus[2]});
        q.push({now.a, now.b + 1, now.c, now.d, now.e, now.f + Plus[1]});
        q.push({now.a + 1, now.b, now.c, now.d, now.e, now.f + Plus[0]});
    }
}

int main() {
    FastIO

    int T;
    cin >> T;

    solve();

    while(T--) {
        cin >> N;

        int ans = N / 60;

        save answer = DP[N % 60];

        cout << answer.a + ans << ' ' << answer.b << ' ' << answer.c << ' ' << answer.d << ' ' << answer.e << '\n';
    }

    return 0;
}