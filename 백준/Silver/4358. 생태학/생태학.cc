#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int all = 0;

    map<string, long long> tree;

    string s;
    while(getline(cin, s)) {
        tree[s]++;
        all++;
    }

    cout << fixed;
    cout.precision(4);

    for (auto i : tree) {
        cout << i.first << ' ' << (double)i.second / all * 100 << '\n';
    }

    return 0;
}