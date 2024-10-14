#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        cout << "Distances:";
        for (int j = 0; j < a.size(); j++) {
            cout << " " << (b[j] - a[j] < 0 ? ((b[j] + 26) - a[j]) : b[j] - a[j]);
        }

        cout << '\n';
    }

    return 0;
}