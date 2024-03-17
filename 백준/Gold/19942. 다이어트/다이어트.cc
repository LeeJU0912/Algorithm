#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct INFO {
    int a, b, c, d, cost;
};

int N;
int mp, mf, ms, mv;

vector<INFO> save;

int mini = INT_MAX;
vector<int> temp;
vector<int> ans;

bool chk(int a, int b, int c, int d) {
    return mp <= a && mf <= b && ms <= c && mv <= d;
}

void solve(int idx, int a, int b, int c, int d, int cost) {
    if (cost >= mini) return;
    if (chk(a, b, c, d)) {
        if (cost < mini) {
            ans = temp;
            mini = cost;
            return;
        }
    }
    if (idx == N) {
        if (chk(a, b, c, d)) {
            if (cost < mini) {
                ans = temp;
                mini = cost;
                return;
            }
        }
        return;
    }

    for (int i = idx + 1; i < N; i++) {
        temp.push_back(i);
        solve(i, a + save[i].a, b + save[i].b, c + save[i].c, d + save[i].d, cost + save[i].cost);
        temp.pop_back();
    }
}

int main() {
    FastIO

    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        save.push_back({a, b, c, d, e});
    }

    for (int i = 0; i < N; i++) {
        temp.push_back(i);
        solve(i, save[i].a, save[i].b, save[i].c, save[i].d, save[i].cost);
        temp.pop_back();
    }

    if (mini == INT_MAX) {
        cout << -1;
    }
    else {
        cout << mini << '\n';
        for (int i : ans) {
            cout << i + 1 << ' ';
        }
    }

    return 0;
}