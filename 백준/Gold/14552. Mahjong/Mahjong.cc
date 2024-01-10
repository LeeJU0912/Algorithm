#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int mahjong[10];
bool visited[10];
bool full[10];

set<int> ans;

void head_and_body(int counter) {
    if (counter == 4) {
        for (int i = 1; i <= 7; i++) {
            bool one = mahjong[i];
            bool two = mahjong[i + 1];
            bool three = mahjong[i + 2];

            if (!full[i] && !one && (two & three)) {
                ans.insert(i);
            }
            else if (!full[i + 1] && !two && (one & three)) {
                ans.insert(i + 1);
            }
            else if (!full[i + 2] && !three && (one & two)) {
                ans.insert(i + 2);
            }
        }

        for (int i = 1; i <= 9; i++) {
            if (!full[i] && mahjong[i] >= 2) ans.insert(i);
        }

        return;
    }

    for (int i = 1; i <= 7; i++) {
        if (mahjong[i] && mahjong[i + 1] && mahjong[i + 2]) {
            mahjong[i]--;
            mahjong[i + 1]--;
            mahjong[i + 2]--;
            head_and_body(counter + 1);
            mahjong[i]++;
            mahjong[i + 1]++;
            mahjong[i + 2]++;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (mahjong[i] < 3) continue;
        mahjong[i] -= 3;
        head_and_body(counter + 1);
        mahjong[i] += 3;
    }
}

void head_and_body2(int counter) {

    if (counter == 4) {
        for (int i = 1; i <= 9; i++) {
            if (visited[i]) continue;
            if (!full[i] && mahjong[i] >= 1) ans.insert(i);
        }

        return;
    }
    for (int i = 1; i <= 7; i++) {
        if (mahjong[i] && mahjong[i + 1] && mahjong[i + 2]) {

            mahjong[i]--;
            mahjong[i + 1]--;
            mahjong[i + 2]--;
            head_and_body2(counter + 1);
            mahjong[i]++;
            mahjong[i + 1]++;
            mahjong[i + 2]++;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (mahjong[i] < 3) continue;
        mahjong[i] -= 3;
        head_and_body2(counter + 1);
        mahjong[i] += 3;
    }
}

void only_head(int counter) {
    if (counter == 6) {
        for (int i = 1; i <= 9; i++) {
            if (visited[i]) continue;
            if (!full[i] && mahjong[i] >= 1) ans.insert(i);
        }

        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (mahjong[i] < 2) continue;
        if (visited[i]) continue;
        visited[i] = true;
        only_head(counter + 1);
        visited[i] = false;
    }
}

int main() {
    FastIO

    for (int i = 0; i < 13; i++) {
        int temp;
        cin >> temp;

        mahjong[temp]++;
        if (mahjong[temp] == 4) full[temp] = true;
    }

    for (int i = 1; i <= 9; i++) {
        if (mahjong[i] < 2) continue;
        visited[i] = true;
        only_head(1);
        visited[i] = false;
    }

    for (int i = 1; i <= 9; i++) {
        if (mahjong[i] < 2) continue;
        mahjong[i] -= 2;
        head_and_body(1);
        mahjong[i] += 2;
    }

    head_and_body2(0);

    if (ans.empty()) {
        cout << -1;
    }
    else {
        for (int i : ans) {
            cout << i << ' ';
        }
    }

    return 0;
}