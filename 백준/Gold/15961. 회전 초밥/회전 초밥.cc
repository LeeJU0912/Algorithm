#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, d, k ,c;

int sushi[3000001];
int counter[3001];
int ans;

int main() {
    FastIO

    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }

    int kind = 0;
    for (int i = 0; i < k; i++) {
        if (counter[sushi[i]]) {
            counter[sushi[i]]++;
            continue;
        }
        counter[sushi[i]]++;
        kind++;
    }

    for (int i = 0; i < N; i++) {
        if (counter[c] == 0) {
            ans = max(ans, kind + 1);
        }
        else {
            ans = max(ans, kind);
        }

        counter[sushi[i]]--;

        if (counter[sushi[i]] == 0) {
            kind--;
        }

        if (counter[sushi[(i + k) % N]] == 0) {
            kind++;
        }

        counter[sushi[(i + k) % N]]++;

    }

    cout << ans;

    return 0;
}