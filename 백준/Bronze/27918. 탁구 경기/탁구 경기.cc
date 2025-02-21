#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int score1 = 0, score2 = 0;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;

        if (c == 'D') {
            score1++;
        }
        else {
            score2++;
        }

        if (abs(score1 - score2) == 2) break;
    }

    cout << score1 << ':' << score2;

    return 0;
}