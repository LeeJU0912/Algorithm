#include <bits/stdc++.h>
using namespace std;

int n, m, v;
int node[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> v;

    for (int i = 1; i <= n; i++) {
        cin >> node[i];
    }

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;

        if (temp > n) {
            temp -= n;
            temp %= n - v + 1;
            cout << node[temp + v] << '\n';
        }
        else {
            if (temp + 1 > n) {
                cout << node[v] << '\n';
            }
            else {
                cout << node[temp + 1] << '\n';
            }

        }
    }

    return 0;
}