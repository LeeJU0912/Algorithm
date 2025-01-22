#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<pair<int, int>> uphill, downhill;
int ancestor[1001];

int ans1, ans2;

int findParent(int x) {
    if (ancestor[x] == x) return ancestor[x];
    else return ancestor[x] = findParent(ancestor[x]);
}

void Union(int a, int b) {
    int parentA = findParent(a);
    int parentB = findParent(b);

    if (parentA != parentB) {
        ancestor[parentB] = parentA;
    }
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c) {
            downhill.push_back({a, b});
        }
        else {
            uphill.push_back({a, b});
        }
    }

    for (int i = 0; i <= N; i++) {
        ancestor[i] = i;
    }
    for (const auto & now : uphill) {
        if (findParent(now.first) != findParent(now.second)) {
            Union(now.first, now.second);
            ans1++;
        }
    }

    for (int i = 0; i <= N; i++) {
        ancestor[i] = i;
    }
    for (const auto & now : downhill) {
        if (findParent(now.first) != findParent(now.second)) {
            Union(now.first, now.second);
        }
    }
    for (const auto & now : uphill) {
        if (findParent(now.first) != findParent(now.second)) {
            Union(now.first, now.second);
            ans2++;
        }
    }

    cout << ans1 * ans1 - ans2 * ans2;

    return 0;
}