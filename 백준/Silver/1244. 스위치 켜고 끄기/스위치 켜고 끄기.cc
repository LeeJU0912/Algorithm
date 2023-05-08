#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    int N;
    cin >> N;

    vector<int> save(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> save[i];
    }

    int student;
    cin >> student;

    for (int i = 0; i < student; i++) {
        int a, b;
        cin >> a >> b;

        if (a == 1) {
            for (int j = 1; b * j <= N; j++) {
                save[b * j] = !save[b * j];
            }
        }
        else {
            int left = b;
            int right = b;

            while(true) {
                if (left - 1 <= 0 || right + 1 > N) break;
                if (save[left - 1] == save[right + 1]) {
                    left--;
                    right++;
                }
                else break;
            }

            for (int j = left; j <= right; j++) {
                save[j] = !save[j];
            }
        }
    }

    int cursor = 1;
    while(true) {
        cout << save[cursor] << ' ';
        if (cursor % 20 == 0) {
            cout << '\n';
        }
        cursor++;
        if (cursor > N) break;
    }

    return 0;
}