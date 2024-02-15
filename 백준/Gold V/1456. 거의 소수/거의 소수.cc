#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long A, B;

bool sosu[10000001];

long long ans;

int main() {
    FastIO

    cin >> A >> B;

    for (int i = 2; i <= 10000; i++) {
        if (sosu[i]) continue;
        for (int j = 2; i * j <= 10000000; j++) {
            if (sosu[i * j]) continue;
            sosu[i * j] = true;
        }
    }

    for (long long i = 2; i <= 10000000; i++) {
        if (sosu[i]) continue;

        long long now = i;
        while(now <= B / i) {
            now *= i;
            if (now >= A && now <= B) ans++;
        }
    }

    cout << ans;

    return 0;
}