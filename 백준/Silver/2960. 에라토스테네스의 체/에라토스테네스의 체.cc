#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<bool> v(N + 1);

    int counter = 0;

    for (int i = 2; i <= N; i++) {
        if (v[i]) continue;
        int temp = 1;
        while (i * temp <= N) {
            if (v[i * temp]) {
                temp++;
                continue;
            }
            v[i * temp] = true;
            counter++;
            if (counter == K) {
                cout << i * temp;
                return 0;
            }
            temp++;
        }
    }

    return 0;
}