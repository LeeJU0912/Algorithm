#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n1, n2;
int c1, c2;

struct NODE {
    long long all_sum;
    long long left_sum;
    long long right_sum;
    long long max_sum;

    NODE operator + (const NODE &b) const {
        NODE c;
        c.all_sum = all_sum + b.all_sum;
        c.left_sum = max(all_sum + b.left_sum, left_sum);
        c.right_sum = max(right_sum + b.all_sum, b.right_sum);
        c.max_sum = max({c.all_sum, right_sum + b.left_sum, max_sum, b.max_sum});

        return c;
    }
};

vector<NODE> tree;

void update(int node, int left, int right, int target, int val) {
    if (right < target || target < left) return;
    if (left == right) {
        tree[node].all_sum += val;
        tree[node].left_sum += val;
        tree[node].right_sum += val;
        tree[node].max_sum += val;
        return;
    }

    update(node * 2, left, (left + right) / 2, target, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

vector<pair<int, pair<int, int>>> save;

bool comp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
    return a.second.second < b.second.second;
}

set<int> X, Y;
map<int, int> conv_x, conv_y;

int main() {
    FastIO

    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int x, y;
        cin >> x >> y;
        save.push_back({0, {x, y}});
        X.insert(x);
        Y.insert(y);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int x, y;
        cin >> x >> y;
        save.push_back({1, {x, y}});
        X.insert(x);
        Y.insert(y);
    }
    cin >> c1 >> c2;
    for (int i = 0; i < save.size(); i++) {
        if (save[i].first == 0) {
            save[i].first = c1;
        }
        else {
            save[i].first = -c2;
        }
    }

    int counter = 1;
    for (int x : X) {
        conv_x[x] = counter++;
    }
    counter = 1;
    for (int y : Y) {
        conv_y[y] = counter++;
    }

    for (int i = 0; i < save.size(); i++) {
        save[i].second.first = conv_x[save[i].second.first];
        save[i].second.second = conv_y[save[i].second.second];
    }

    sort(save.begin(), save.end(), comp);

    long long ans = 0;
    for (int y = 1; y <= Y.size(); y++) {
        tree = vector<NODE>(8001);

        for (int j = 0; j < save.size(); j++) {
            if (save[j].second.second < y) continue;
            update(1, 1, X.size(), save[j].second.first, save[j].first);

            ans = max(ans, tree[1].max_sum);
        }
    }

    cout << ans;

    return 0;
}