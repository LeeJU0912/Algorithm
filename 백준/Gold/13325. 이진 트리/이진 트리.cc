#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int k;
int dist[(1 << 22)];

int maxi = 0;
int treeMaxi[(1 << 22)];

long long hap;
long long ans;

void findMaxi(int node, int gathered) {
    if (node >= (1 << (k + 1))) {
        maxi = max(maxi, gathered);
        return;
    }

    findMaxi(node * 2, gathered + dist[node * 2]);
    findMaxi(node * 2 + 1, gathered + dist[node * 2 + 1]);
}

int makeMaxi(int node) {
    if (node >= (1 << (k + 1))) return 0;
    return treeMaxi[node] = max(makeMaxi(node * 2) + dist[node * 2], makeMaxi(node * 2 + 1) + dist[node * 2 + 1]);
}

void dfs(int node, int gathered) {
    if (node >= (1 << (k + 1))) return;
    int gap = maxi - (treeMaxi[node] + gathered);
    ans += gap;

    dfs(node * 2, gathered + gap + dist[node * 2]);
    dfs(node * 2 + 1, gathered + gap + dist[node * 2 + 1]);
}

int main() {
    FastIO

    cin >> k;
    for (int i = 2; i <= (1 << (k + 1)) - 1; i++) {
        cin >> dist[i];
        hap += dist[i];
    }

    findMaxi(1, 0);
    makeMaxi(1);
    dfs(1, 0);

    cout << hap + ans;

    return 0;
}