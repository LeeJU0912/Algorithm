#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v;

    for (int i = 1; i <= N; i++) {
        v.push_back(i);
    }

    do {
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    } while(next_permutation(v.begin(), v.end()));

    return 0;
}