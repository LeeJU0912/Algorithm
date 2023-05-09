#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int main() {
    FastIO

    cin >> N;

    vector<int> save;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    sort(save.begin(), save.end());

    cout << save[((N + 1) / 2) - 1];

    return 0;
}