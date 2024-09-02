#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    int maxi = 0;
    int mini = INT_MAX;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        maxi = max(maxi, tmp);
        mini = min(mini, tmp);
    }

    cout << maxi - mini;

    return 0;
}