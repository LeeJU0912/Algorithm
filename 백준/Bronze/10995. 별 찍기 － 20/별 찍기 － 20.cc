#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N * 2; j++) {
            if (i & 1) {
                if (j & 1) {
                    cout << '*';
                }
                else {
                    cout << ' ';
                }
            }
            else {
                if (j & 1) {
                    cout << ' ';
                }
                else {
                    cout << '*';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}