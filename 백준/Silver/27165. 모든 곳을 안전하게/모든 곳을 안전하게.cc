#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int n;
    cin >> n;

    vector<int> save(n + 1);

    int one = 0;

    for (int i = 0; i <= n; i++) {
        cin >> save[i];
        if (save[i] == 1) {
            one++;
        }
    }

    int x;
    cin >> x;

    if (one >= 3) {
        cout << "NO";
        return 0;
    }
    else if (one == 2) {
        for (int i = 0; i <= n; i++) {
            if (save[i] == 1) {
                if (i + x <= n) {
                    if (save[i + x] == 1) {
                        cout << "YES" << '\n';
                        cout << i << ' ' << i + x;
                        return 0;
                    }
                    else {
                        cout << "NO";
                        return 0;
                    }
                }
                else {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    else if (one == 1) {
        for (int i = 0; i <= n; i++) {
            if (save[i] >= 3) {
                if (i + x <= n) {
                    if (save[i + x] == 1) {
                        cout << "YES" << '\n';
                        cout << i << ' ' << i + x;
                        return 0;
                    }
                }
                else {
                    cout << "NO";
                    return 0;
                }
            }
            else if (save[i] == 1) {
                if (i + x <= n) {
                    if (save[i + x] >= 1) {
                        cout << "YES" << '\n';
                        cout << i << ' ' << i + x;
                        return 0;
                    }
                    else {
                         cout << "NO";
                         return 0;
                    }
                }
                else {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    else {
        for (int i = 0; i <= n; i++) {
            if (save[i] >= 3) {
                if (i + x <= n) {
                    if (save[i + x] >= 1) {
                        cout << "YES" << '\n';
                        cout << i << ' ' << i + x;
                        return 0;
                    }
                }
                else {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }

    cout << "NO";

    return 0;
}