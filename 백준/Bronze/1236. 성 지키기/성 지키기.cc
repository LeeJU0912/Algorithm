#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool garo[50];
bool sero[50];
int garoCount, seroCount;

int main() {
    FastIO

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'X') {
                garo[i] = true;
                sero[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!garo[i]) garoCount++;
    }
    for (int i = 0; i < m; i++) {
        if (!sero[i]) seroCount++;
    }

    cout << max(garoCount, seroCount);

    return 0;
}