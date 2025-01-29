#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
bool notSosu[10001];
vector<int> sosu;

int main() {
    FastIO

    for (int i = 2; i <= 10000; i++) {
        if (notSosu[i]) continue;
        for (int j = 2; i * j <= 10000; j++) {
            notSosu[i * j] = true;
        }

        if (!notSosu[i]) {
            sosu.push_back(i);
        }
    }

    cin >> N;

    for (int i = 0; i < sosu.size() - 1; i++) {
        if (sosu[i] * sosu[i + 1] > N) {
            cout << sosu[i] * sosu[i + 1];
            return 0;
        }
    }

    return 0;
}