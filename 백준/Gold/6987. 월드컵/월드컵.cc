#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct INFO {
    int win, draw, lose;
};

vector<INFO> save;

bool matched[6][6];
bool ans;

void solve(int idx, int counter) {
    if (idx == 5) {
        for (int i = 0; i < 6; i++) {
            if (save[i].win && save[i].draw && save[i].lose) {
                return;
            }
        }

        ans = true;
        return;
    }

    for (int i = idx + counter + 1; i < 6; i++) {
        if (save[idx].win && save[i].lose) {
            save[idx].win--;
            save[i].lose--;
            if (counter == 5 - idx - 1) {
                solve(idx + 1, 0);
            }
            else {
                solve(idx, counter + 1);
            }
            save[idx].win++;
            save[i].lose++;
        }
        if (save[idx].draw && save[i].draw) {
            save[idx].draw--;
            save[i].draw--;
            if (counter == 5 - idx - 1) {
                solve(idx + 1, 0);
            }
            else {
                solve(idx, counter + 1);
            }
            save[idx].draw++;
            save[i].draw++;
        }
        if (save[idx].lose && save[i].win) {
            save[idx].lose--;
            save[i].win--;
            if (counter == 5 - idx - 1) {
                solve(idx + 1, 0);
            }
            else {
                solve(idx, counter + 1);
            }
            save[idx].lose++;
            save[i].win++;
        }
    }
}

int main() {
    FastIO

    int T = 4;
    while(T--) {
        save.clear();
        memset(matched, false, sizeof(matched));
        ans = false;

        for (int i = 0; i < 6; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            save.push_back({a, b, c});
        }

        bool not_five = false;
        for (int i = 0; i < 6; i++) {
            if (save[i].win + save[i].draw + save[i].lose != 5) {
                not_five = true;
                break;
            }
        }

        if (not_five) {
            cout << 0 << ' ';
            continue;
        }

        solve(0 , 0);

        if (ans) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }

    return 0;
}