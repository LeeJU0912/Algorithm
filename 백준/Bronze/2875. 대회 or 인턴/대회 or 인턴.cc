#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    int group_w = N / 2;
    int other_w = N % 2;

    int other_m;

    if (M >= group_w) {
        other_m = M - group_w;
    }
    else {
        group_w = M;
        other_w = N - M * 2;
        other_m = 0;
    }

    int more = other_m + other_w - K;

    if (more >= 0) {
        cout << group_w;
    }
    else {
        if (more % 3 == 0) {
            more /= 3;
        }
        else {
            more /= 3;
            more--;
        }
        cout << group_w + more;
    }

    return 0;
}