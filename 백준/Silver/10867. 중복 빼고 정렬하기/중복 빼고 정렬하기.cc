#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;

    cin >> N;

    set<int> s;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    for (auto i : s) {
        cout << i << ' ';
    }

    return 0;
}