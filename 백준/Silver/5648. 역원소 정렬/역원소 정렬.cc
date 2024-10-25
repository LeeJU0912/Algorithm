#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<long long> save;

int main() {
    FastIO

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        long long x = stoll(s);
        save.push_back(x);
    }

    sort(save.begin(), save.end());

    for (long long x : save) {
        cout << x << '\n';
    }

    return 0;
}