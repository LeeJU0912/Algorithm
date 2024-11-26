#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, Q;
vector<long long> tree;
vector<int> treeL;
vector<int> save;

void update(int target, int val) {
    while(target <= N) {
        tree[target] += val;
        if (val > 0) {
            treeL[target]++;
        }
        else {
            treeL[target]--;
        }
        target += (target & -target);
    }
}

long long query(int X) {
    long long ret = 0;
    while(X > 0) {
        ret += tree[X];
        X -= (X & -X);
    }
    return ret;
}

long long queryL(int X) {
    long long ret = 0;
    while(X > 0) {
        ret += treeL[X];
        X -= (X & -X);
    }
    return ret;
}

int main() {
    FastIO

    cin >> N;
    tree = vector<long long>(N + 1);
    treeL = vector<int>(N + 1);
    save = vector<int>(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> save[i];
    }

    cin >> Q;
    while(Q--) {
        int order;
        cin >> order;

        if (order == 1) {
            int L, R;
            cin >> L >> R;
            update(L, L);
            update(R + 1, -L);
        }
        else if (order == 2) {
            int X;
            cin >> X;
            cout << queryL(X) * (X + 1) - query(X) + save[X] << '\n';
        }
    }

    return 0;
}