#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<>());

    for (int i : v) {
        cout << i << '\n';
    }


    return 0;
}