#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


    vector<int> v;

    int a, b;
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        int temp;
        cin >> temp;
        v.emplace_back(temp);
    }

    for (int i = 0; i < b; i++) {
        int temp;
        cin >> temp;
        v.emplace_back(temp);
    }

    sort(v.begin(), v.end());

    for (auto i : v) {
        cout << i << ' ';
    }

    return 0;
}