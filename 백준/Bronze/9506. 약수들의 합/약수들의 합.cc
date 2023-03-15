#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;

    while(true) {
        cin >> N;

        if (N == -1) break;

        int ans = 0;

        vector<int> save;

        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                save.push_back(i);
                if (N / i != i) {
                    save.push_back(N / i);
                }
            }
        }

        sort(save.begin(), save.end());

        for (auto i : save) {
            ans += i;
        }

        if (ans - N != N) {
            cout << N << ' ' << "is NOT perfect." << '\n';
        }
        else {
            cout << N << ' ' << '=' << ' ';
            for (int i = 0; i < save.size() - 1; i++) {
                if (i == save.size() - 2) {
                    cout << save[i] << '\n';
                }
                else {
                    cout << save[i] << " + ";
                }
            }
        }

    }

    return 0;
}