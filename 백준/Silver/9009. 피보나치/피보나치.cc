#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
int fibo[45];

int main() {
    FastIO

    int T;
    cin >> T;

    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i <= 44; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    while(T--) {
        cin >> n;

        vector<int> save;
        for (int i = 44; i >= 0; i--) {
            if (fibo[i] <= n) {
                n -= fibo[i];
                save.push_back(fibo[i]);
            }
        }
        for (int i = save.size() - 2; i >= 0; i--) {
            cout << save[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}