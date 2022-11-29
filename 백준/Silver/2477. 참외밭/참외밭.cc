#include <bits/stdc++.h>

using namespace std;

int K;
int dist[5];
int dist2[5];
int small;
int big_x;
int big_y;

vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> K;

    for (int i = 0; i < 6; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i = 0; i < 6; i++) {
        if ((v[i].first == 1 || v[i].first == 2) && big_x < v[i].second) {
            big_x = v[i].second;
        }
        if ((v[i].first == 3 || v[i].first == 4) && big_y < v[i].second) {
            big_y = v[i].second;
        }
        if (v[i].first == v[(i + 2) % 6].first) {
            if (v[(i + 5) % 6].second < v[(i + 3) % 6].second) {
                small = v[(i + 1) % 6].second * v[i].second;
            }
            else {
                small = v[(i + 1) % 6].second * v[(i + 2) % 6].second;
            }
        }
    }

    cout << (big_x * big_y - small) * K;

    return 0;
}