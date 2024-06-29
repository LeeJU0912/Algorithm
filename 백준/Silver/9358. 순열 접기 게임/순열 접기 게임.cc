#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> save;

int main() {
    FastIO

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        save = vector<int>(N);

        for (int i = 0; i < N; i++) {
            cin >> save[i];
        }

        vector<int> tmp = save;

        while(tmp.size() > 2) {
            vector<int> tmp2;

            for (int i = 0; i < (tmp.size() % 2 == 1 ? (tmp.size() + 1) / 2 : tmp.size() / 2); i++) {
                tmp2.push_back(tmp[i] + tmp[tmp.size() - 1 - i]);
            }

            tmp = tmp2;
        }

        cout << "Case #" << t << ": ";
        if (tmp[0] > tmp[1]) {
            cout << "Alice" << '\n';
        }
        else {
            cout << "Bob" << '\n';
        }
    }

    return 0;
}