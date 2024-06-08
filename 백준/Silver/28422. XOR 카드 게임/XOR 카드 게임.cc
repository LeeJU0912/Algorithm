#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
int DP[100001];
int pre[1025];

void pre_calc(int x) {
    int now = x;

    int counter = 0;
    while(x) {
        counter += x & 1;
        x >>= 1;
    }

    pre[now] = counter;
}

int get_xor(int idx, int time) {
    int ret = save[idx];

    for (int i = 1; i < time; i++) {
        ret ^= save[idx + i];
    }

    return ret;
}

int main() {
    FastIO

    for (int i = 1; i < 1024; i++) {
        pre_calc(i);
    }

    cin >> N;
    save = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    if (N == 1) {
        cout << 0;
    }
    else if (N == 2) {
        cout << pre[get_xor(0, 2)];
    }
    else if (N == 3) {
        cout << pre[get_xor(0, 3)];
    }
    else if (N == 4) {
        cout << pre[get_xor(0, 2)] + pre[get_xor(2, 2)];
    }
    else {
        DP[1] = pre[get_xor(0, 2)];
        DP[2] = pre[get_xor(0, 3)];
        DP[3] = DP[1] + pre[get_xor(2, 2)];
        for (int i = 4; i < N; i++) {
            DP[i] = max(DP[i - 2] + pre[get_xor(i - 1, 2)], DP[i - 3] + pre[get_xor(i - 2, 3)]);
        }
        cout << DP[N - 1];
    }

    return 0;
}