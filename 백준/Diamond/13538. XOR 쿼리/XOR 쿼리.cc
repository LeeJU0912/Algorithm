#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct PST {
    struct Node {
        int l, r, sum;
        Node() : l(-1), r(-1), sum(0) {}
        Node(int sum) : l(-1), r(-1), sum(sum) {}
        Node(int l, int r, int sum) : l(l), r(r), sum(sum) {}
    };
    vector<Node> nodes;
    vector<int> roots;
    int sz;
    PST(int sz) : sz(sz) {
        roots.push_back(init(0, sz));
    }
    int init(int L, int R) {
        if (L == R) nodes.push_back(0);
        else {
            int mid = L + R >> 1;
            nodes.push_back({ init(L, mid), init(mid + 1, R), 0 });
        }
        return nodes.size() - 1;
    }
    int update(int i, int val, int L, int R, int nodeNum) {
        Node cur = nodes[nodeNum];
        if (L == R) nodes.push_back(cur.sum + val);
        else {
            int mid = L + R >> 1;
            if (i <= mid) {
                int l = update(i, val, L, mid, cur.l);
                nodes.push_back({ l, cur.r, cur.sum + val });
            }
            else {
                int r = update(i, val, mid + 1, R, cur.r);
                nodes.push_back({ cur.l, r, cur.sum + val });
            }
        }
        return nodes.size() - 1;
    }
    void update_x(int i, int val) {
        roots.back() = update(i, val, 0, sz, roots.back());
    }
    void update_y() {
        roots.push_back(roots.back());
    }
    int sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
        Node cur = nodes[nodeNum];
        if (L > R) return 0;
        if (R < nodeL || nodeR < L) return 0;
        if (L <= nodeL && nodeR <= R) return cur.sum;
        int mid = nodeL + nodeR >> 1;
        return sum(L, R, cur.l, nodeL, mid) + sum(L, R, cur.r, mid + 1, nodeR);
    }
    int sum(int xl, int xr, int y) {
        return sum(xl, xr, roots[y], 0, sz);
    }
    int sum(int xl, int xr, int yl, int yr) {
        if (yl <= 0) return sum(xl, xr, yr);
        return sum(xl, xr, yr) - sum(xl, xr, yl - 1);
    }
    int kth(int l_idx, int r_idx, int l, int r, int k) {
        if (l == r) return l;
        Node L = nodes[l_idx],R = nodes[r_idx];
        int mid = l + r >> 1;
        int left = nodes[R.l].sum - nodes[L.l].sum;
        if (k <= left) return kth(L.l, R.l, l, mid, k);
        else return kth(L.r, R.r, mid + 1, r, k - left);
    }
    int _xor(int l_idx, int r_idx, int l, int r, int x) {
        if (l == r) return l;
        Node L = nodes[l_idx],R = nodes[r_idx];
        int mid = l + r >> 1;
        int left = nodes[R.l].sum - nodes[L.l].sum;
        int right = nodes[R.r].sum - nodes[L.r].sum;
        if ((r - l + 1) / 2 & x && left || !right) return _xor(L.l, R.l, l, mid, x);
        else return _xor(L.r, R.r, mid + 1, r, x);
    }
} PST(524287);

int xor_query(int l, int r, int x) {
    return PST._xor(PST.roots[l - 1], PST.roots[r], 0, PST.sz, x);
}

int sum_query(int l, int r, int x) {
    return PST.sum(0, x, l, r);
}

int kth_query(int l, int r, int k) {
    return PST.kth(PST.roots[l - 1], PST.roots[r], 0, PST.sz, k);
}

int main() {
    FastIO

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, a, b, c;
        cin >> t >> a;
        if (t != 1 && t != 3) {
            cin >> b >> c;
        }
        if (t == 1) {
            PST.update_y();
            PST.update_x(a, 1);
        }
        else if (t == 2) {
            cout << xor_query(a, b, c) << '\n';
        }
        else if (t == 3) {
            while (a--) PST.roots.pop_back();
        }
        else if (t == 4) {
            cout << sum_query(a, b, c) << '\n';
        }
        else {
            cout << kth_query(a, b, c) << '\n';
        }
    }

    return 0;
}