#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>
#include <climits>
#include <cstdlib>
#include <utility>

using namespace std;

int T;
int A, B;
bool visited[10001];

void solve() {
    queue<pair<int, string>> q;
    q.push({ A, "" });
    visited[A] = true;

    while(!q.empty()) {
        int num = q.front().first;
        string ans = q.front().second;
        q.pop();

        if (num == B) {
            cout << ans << '\n';
            return;
        }

        // D
        int D = (2 * num) % 10000;
        if (!visited[D]) {
            visited[D] = true;
            q.push({ D, ans + "D" });
        }
        // S
        int S = (num - 1) < 0 ? 9999 : num - 1;
        if (!visited[S]) {
            visited[S] = true;
            q.push({ S, ans + "S" });
        }
        // L
        int L = (num / 1000) + (num % 1000) * 10;
        if (!visited[L]) {
            visited[L] = true;
            q.push({ L, ans + "L"});
        }
        // R
        int R = (num / 10) + (num % 10) * 1000;
        if (!visited[R]) {
            visited[R] = true;
            q.push({ R, ans + "R" });
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while (T--) {
        cin >> A >> B;
        solve();
        memset(visited, false, sizeof(visited));
    }

    return 0;
}