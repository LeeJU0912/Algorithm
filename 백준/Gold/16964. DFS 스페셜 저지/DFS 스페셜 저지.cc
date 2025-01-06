#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
set<int> graph[100001];
vector<int> save;
int saveIdx;

void solve(int now) {
    saveIdx++;
    if (saveIdx == N) return;
    while(true) {
        if (graph[now].find(save[saveIdx]) != graph[now].end()) {
            solve(save[saveIdx]);
        }
        else break;
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        save.push_back(x);
    }

    if (save[0] != 1) {
        cout << 0;
        return 0;
    }

    solve(1);

    if (saveIdx == N) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}