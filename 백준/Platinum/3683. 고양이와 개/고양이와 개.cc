#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int c, d, v;
vector<pair<int, int>> catWin, dogWin;
vector<int> graph[501];
int cat[501];
int dog[501];
bool visited[501];

bool dfs(int a) {
    for (auto b : graph[a]) {
        if (visited[b]) continue;
        visited[b] = true;
        if (dog[b] == -1 || dfs(dog[b])) {
            cat[a] = b;
            dog[b] = a;
            return true;
        }
    }

    return false;
}

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        cin >> c >> d >> v;

        memset(cat, -1, sizeof(cat));
        memset(dog, -1, sizeof(dog));
        catWin.clear();
        dogWin.clear();
        for (int i = 0; i < v; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < v; i++) {
            string a, b;
            cin >> a >> b;

            int first = 0;
            int second = 0;
            for (int j = 1; j < a.size(); j++) {
                first *= 10;
                first += a[j] - '0';
            }
            for (int j = 1; j < b.size(); j++) {
                second *= 10;
                second += b[j] - '0';
            }

            if (a[0] == 'C') {
                catWin.push_back({first, second});
            }
            else {
                dogWin.push_back({first, second});
            }
        }

        for (int i = 0; i < catWin.size(); i++) {
            for (int j = 0; j < dogWin.size(); j++) {
                if (catWin[i].first == dogWin[j].second || catWin[i].second == dogWin[j].first) {
                    graph[i].push_back(j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < catWin.size(); i++) {
            if (cat[i] == -1) {
                memset(visited, false, sizeof(visited));
                if (dfs(i)) ans++;
            }
        }

        cout << v - ans << '\n';
    }

    return 0;
}