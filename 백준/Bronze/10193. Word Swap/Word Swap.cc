#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        string a, b;
        cin >> a >> b;

        int hap = 0;
        for (int i = 0; i < a.size(); i++) {
            hap += a[i] - b[i];
        }

        cout << "Swapping letters to make " << a << " look like " << b;

        if (hap < 0) {
            cout << " cost " << -hap << " coins.";
        }
        else if (hap > 0) {
            cout << " earned " << hap << " coins.";
        }
        else {
            cout << " was FREE.";
        }
        cout << '\n';
    }

    return 0;
}