#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        unordered_set<int> s;

        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            s.insert(temp);
        }

        int M;
        cin >> M;

        for (int i = 0; i < M; i++) {
            int temp;
            cin >> temp;
            if (s.find(temp) != s.end()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}