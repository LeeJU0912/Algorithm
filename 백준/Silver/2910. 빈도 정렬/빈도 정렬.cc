#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, C;
vector<int> save;

map<int, int> mp;
map<int, int> first;

vector<pair<int, int>> counter;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) return true;
    else if (a.first < b.first) return false;
    else {
        if (first[a.second] < first[b.second]) return true;
        else return false;
    }
}

int main() {
    FastIO

    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        if (first.find(temp) == first.end()) {
            first[temp] = i;
        }
        mp[temp]++;
    }

    for (auto i : mp) {
        counter.push_back({i.second, i.first});
    }

    sort(counter.begin(), counter.end(), cmp);

    for (int i = 0; i < counter.size(); i++) {
        for (int j = 0; j < counter[i].first; j++) {
            cout << counter[i].second << ' ';
        }
    }

    return 0;
}