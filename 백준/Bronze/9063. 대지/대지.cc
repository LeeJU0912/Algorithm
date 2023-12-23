#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        min_x = min(min_x, a);
        max_x = max(max_x, a);
        min_y = min(min_y, b);
        max_y = max(max_y, b);
    }

    cout << (max_x - min_x) * (max_y - min_y);

    return 0;
}