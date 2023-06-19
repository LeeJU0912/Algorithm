#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int a, b;
int N;

vector<int> save[2];

int main() {
    FastIO

    cin >> a >> b;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int c, d;
        cin >> c >> d;

        save[c].push_back(d);
    }

    int maxi1 = 0, maxi2 = 0;

    if (!save[0].empty()) {
        sort(save[0].begin(), save[0].end());
        maxi1 = save[0][0];

        for (int i = 1; i < save[0].size(); i++) {
            maxi1 = max(maxi1, save[0][i] - save[0][i - 1]);
        }

        maxi1 = max(maxi1, b - save[0][save[0].size() - 1]);
    }

    if (!save[1].empty()) {
        sort(save[1].begin(), save[1].end());
        maxi2 = save[1][0];

        for (int i = 1; i < save[1].size(); i++) {
            maxi2 = max(maxi2, save[1][i] - save[1][i - 1]);
        }

        maxi2 = max(maxi2, a - save[1][save[1].size() - 1]);
    }

    if (maxi1 == 0) {
        maxi1 = b;
    }
    if (maxi2 == 0) {
        maxi2 = a;
    }

    cout << maxi1 * maxi2;


    return 0;
}