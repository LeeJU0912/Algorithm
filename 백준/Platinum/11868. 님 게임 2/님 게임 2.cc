#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int ans;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        ans ^= temp;
    }

    if (ans) {
        cout << "koosaga";
    }
    else {
        cout << "cubelover";
    }

    return 0;
}