#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
int before[200001];

int counter;
stack<int> ans;

void solve() {
    queue<int> q;
    q.push(N);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == K) {
            while(now != N) {
                ans.push(now);
                now = before[now];
                counter++;
            }
            break;
        }

        if (now * 2 <= K * 2) {
            if (before[now * 2] == -1) {
                before[now * 2] = now;
                q.push(now * 2);
            }
        }
        if (now + 1 <= K) {
            if (before[now + 1] == -1) {
                before[now + 1] = now;
                q.push(now + 1);
            }
        }
        if (now - 1 >= 0) {
            if (before[now - 1] == -1) {
                before[now - 1] = now;
                q.push(now - 1);
            }
        }
    }
}

int main() {
    FastIO

    memset(before, -1, sizeof(before));

    cin >> N >> K;

    solve();

    cout << counter << '\n';

    cout << N << ' ';
    while(!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}