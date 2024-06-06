#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct INFO {
    int A, B, C;
};

int N;
vector<INFO> save;
bool visited[50];
int node[50];

bool solve(int idx) {
    if (visited[idx]) return false;
    visited[idx] = true;

    for (int i = 0; i < N; i++) {
        if (idx == i) continue;

        INFO next = save[i];
        if (save[idx].A == next.A && save[idx].B == next.B && save[idx].C == next.C) {
            if (idx < i) {
                if (node[i] == -1 || solve(node[i])) {
                    node[i] = idx;
                    return true;
                }
            }
        }
        else if ((save[idx].A > next.A && save[idx].B > next.B && save[idx].C > next.C)||
                (save[idx].A == next.A && save[idx].B > next.B && save[idx].C > next.C)||
                (save[idx].A > next.A && save[idx].B == next.B && save[idx].C > next.C)||
                (save[idx].A > next.A && save[idx].B > next.B && save[idx].C == next.C)||
                (save[idx].A == next.A && save[idx].B == next.B && save[idx].C > next.C)||
                (save[idx].A > next.A && save[idx].B == next.B && save[idx].C == next.C)||
                (save[idx].A == next.A && save[idx].B > next.B && save[idx].C == next.C)) {
            if (node[i] == -1 || solve(node[i])) {
                node[i] = idx;
                return true;
            }
        }
    }

    return false;
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        INFO x;
        cin >> x.A >> x.B >> x.C;
        save.push_back(x);
    }

    int ans = 0;
    memset(node, -1, sizeof(node));
    for (int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        if (solve(i)) ans++;
        memset(visited, false, sizeof(visited));
        if (solve(i)) ans++;
    }

    cout << N - ans;

    return 0;
}