#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;

    vector<pair<tuple<int, int, int>, string>> save;

    for (int i = 0; i < n; i++) {
        string a;
        int b, c, d;
        cin >> a >> b >> c >> d;

        save.push_back({{d, c, b}, a});
    }

    sort(save.begin(), save.end());

    cout << save[n - 1].second << '\n';
    cout << save[0].second << '\n';

    return 0;
}