#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
pair<int, int> house;
pair<int, int> store[101];
pair<int, int> festival;
bool visited[101];

bool flag;

void searching() {
    queue<pair<int, int>> q;
    q.push(house);

    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        if (abs(now.first - festival.first) + abs(now.second - festival.second) <= 1000) {
            flag = true;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int dist = abs(now.first - store[i].first) + abs(now.second - store[i].second);
            if (dist == 0) continue;

            if (dist <= 1000) {
                q.push(store[i]);
                visited[i] = true;
            }
        }
    }
}

int main() {
    FastIO

    int t;
    cin >> t;

    while(t--) {
        flag = false;
        memset(visited, false, sizeof(visited));

        cin >> n;

        cin >> house.first >> house.second;

        for (int i = 0; i < n; i++) {
            cin >> store[i].first >> store[i].second;
        }

        cin >> festival.first >> festival.second;

        searching();

        if (flag) {
            cout << "happy" << '\n';
        }
        else {
            cout << "sad" << '\n';
        }
    }

    return 0;
}