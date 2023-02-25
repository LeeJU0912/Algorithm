#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int parent[201];

int find_parent(int idx) {
    if (idx == parent[idx]) return idx;
    else return parent[idx] = find_parent(parent[idx]);
}

int union_parent(int a, int b) {
    return parent[find_parent(a)] = find_parent(b);
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int temp;
            cin >> temp;
            if (temp) union_parent(i, j);
        }
    }

    vector<int> road(M);
    for (int i = 0; i < M; i++) {
        cin >> road[i];
    }

    bool ans = false;
    int now_parent = find_parent(road[0]);

    for (int i = 1; i < M; i++) {
        if (now_parent != find_parent(road[i])) {
            ans = true;
            break;
        }
    }

    if (ans) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    return 0;
}