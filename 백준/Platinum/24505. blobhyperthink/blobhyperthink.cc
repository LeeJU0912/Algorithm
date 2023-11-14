#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

#define MOD 1000000007

int N;
vector<int> save;
long long tree[400001][12]; //  <자식노드포함min, 현재idx일때 갯수>

long long ans;

long long query(int node, int left, int right, int start, int end, int len) {
    if (right < start || left > end) return 0;
    if (start <= left && right <= end) return tree[node][len];

    long long l = query(node * 2, left, (left + right) / 2, start, end, len);
    long long r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end, len);

    return (l + r) % MOD;
}

void update(int node, int left, int right, int target, int diff, int len) {
    if (right < target || target < left) return;
    if (left == right) {
        tree[node][len] += diff;
        tree[node][len] %= MOD;
        return;
    }

    update(node * 2, left, (left + right) / 2, target, diff, len);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, diff, len);

    tree[node][len] = (tree[node * 2][len] + tree[node * 2 + 1][len]) % MOD;
}

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        update(1, 1, N, temp, 1, 1);

        for (int j = 2; j <= 11; j++) {
            update(1, 1, N, temp, query(1, 1, N, 1, temp - 1, j - 1), j);
        }
    }

    cout << query(1, 1, N, 1, N, 11);

    return 0;
}