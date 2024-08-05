#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int counter[1001];

int main() {
    FastIO

    int now;
    int maxCounter = 0;

    int hap = 0;
    for (int i = 0; i < 10; i++) {
        int tmp;
        cin >> tmp;
        hap += tmp;
        counter[tmp]++;
        if (counter[tmp] > maxCounter) {
            maxCounter = counter[tmp];
            now = tmp;
        }
    }

    cout << hap / 10 << '\n' << now;

    return 0;
}