#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    while(N--) {
        int r, e, c;
        cin >> r >> e >> c;

        if (r < e - c) {
            cout << "advertise" << '\n';
        }
        else if (r > e - c) {
            cout << "do not advertise" << '\n';
        }
        else {
            cout << "does not matter" << '\n';
        }
    }

    return 0;
}