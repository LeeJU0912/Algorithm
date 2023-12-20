#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int m;

vector<vector<int>> sparse;

int Q;

int query(int count, int start) {
    for (int bit = (int)ceil(log2(500001)); bit >= 0; bit--) {
        if (count & (1 << bit)) {
            start = sparse[bit][start];
        }
    }

    return start;
}

int main() {
    FastIO

    cin >> m;

    sparse = vector<vector<int>>((int)ceil(log2(500001)) + 1, vector<int>(500001));

    for (int i = 1; i <= m; i++) {
        cin >> sparse[0][i];
    }

    for (int i = 1; i <= (int)ceil(log2(500001)); i++) {
        for (int j = 1; j <= m; j++) {
            int next = sparse[i - 1][j];
            sparse[i][j] = sparse[i - 1][next];
        }
    }

    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int n, x;
        cin >> n >> x;

        cout << query(n, x) << '\n';
    }

    return 0;
}