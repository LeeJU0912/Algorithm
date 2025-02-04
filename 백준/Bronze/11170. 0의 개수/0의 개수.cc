#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int zero[1000001];
int hap[1000001];

int calc(int x) {
    int cnt = 0;
    while(x) {
        if (x % 10 == 0) cnt++;

        x /= 10;
    }

    return cnt;
}

int main() {
    FastIO

    zero[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        zero[i] = calc(i);
    }

    hap[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        hap[i] = zero[i] + hap[i - 1];
    }

    int T;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        cout << hap[M] - hap[N] + zero[N] << '\n';
    }

    return 0;
}