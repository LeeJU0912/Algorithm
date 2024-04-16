#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool ans;
int counter[28];

void moo(int idx, int N) {
    if (idx == 0) {
        if (N <= 3) {
            if (N == 1) {
                ans = true;
            }
            return;
        }

        return;
    }

    int front = counter[idx - 1];
    if (N <= front) {
        moo(idx - 1, N);
    }
    else if (front < N && N <= front + idx + 3) {
        if (front + 1 == N) {
            ans = true;
        }
        return;
    }
    else {
        moo(idx - 1, N - front - idx - 3);
    }
}

int main() {
    FastIO

    counter[0] = 3;
    for (int i = 1; i <= 27; i++) {
        counter[i] = counter[i - 1] * 2 + (i + 3);
    }

    int N;
    cin >> N;

    moo(27, N);

    cout << (ans ? 'm' : 'o');

    return 0;
}