#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
vector<long long> tree;

long long ans;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = left;
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    if (save[tree[node * 2]] <= save[tree[node * 2 + 1]]) {
        tree[node] = tree[node * 2];
    }
    else {
        tree[node] = tree[node * 2 + 1];
    }
}

long long query(int node, int left, int right, int start, int end) {
    if (left > end || right < start) return -1;
    if (start <= left && right <= end) {
        return tree[node];
    }

    long long l = query(node * 2, left, (left + right) / 2, start, end);
    long long r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    if (l == -1) return r;
    if (r == -1) return l;
    if (save[l] < save[r]) {
        return l;
    }
    else return r;
}

long long find_result(int start, int end) {
    long long idx = query(1, 0, N - 1, start, end);
    long long result = (end - start + 1) * save[idx];
    
    if (idx > start) {
        long long l_result = find_result(start, idx - 1);
        result = max(result, l_result);
    }
    if (idx < end) {
        long long r_result = find_result(idx + 1, end);
        result = max(result, r_result);
    }

    return result;
}

int main() {
    FastIO

    cin >> N;

    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<long long>(tree_size);

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    init(1, 0, N - 1);

    ans = find_result(0, N - 1);

    cout << ans;

    return 0;
}