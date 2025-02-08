#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int a, b, c, d;

map<long long, int> mp;

void calc() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 0}});

    while(!pq.empty()) {
        int cnt = pq.top().first;
        int l = pq.top().second.first;
        int r = pq.top().second.second;
        pq.pop();

        if (mp.find(l * 1000000 + r) != mp.end()) continue;
        mp[l * 1000000 + r] = cnt;

        if (l != a) {
            pq.push({cnt + 1, {a, r}});
        }
        if (l != 0) {
            pq.push({cnt + 1, {0, r}});
            pq.push({cnt + 1, {l - min(l, (b - r)), r + min(l, (b - r))}});
        }
        if (r != b) {
            pq.push({cnt + 1, {l, b}});
        }
        if (r != 0) {
            pq.push({cnt + 1, {l, 0}});
            pq.push({cnt + 1, {l + min(r, (a - l)), r - min(r, (a - l))}});
        }
    }
}

int main() {
    FastIO

    cin >> a >> b >> c >> d;

    calc();

    if (mp.find(c * 1000000 + d) != mp.end()) {
        cout << mp[c * 1000000 + d];
    }
    else {
        cout << -1;
    }

    return 0;
}