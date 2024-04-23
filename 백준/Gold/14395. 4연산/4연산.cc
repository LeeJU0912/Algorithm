#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int s, t;

int mini = INT_MAX;
string ans;

void calc(long long val, int counter, string temp) {
    if (val == t) {
        if (counter == mini) {
            if (ans > temp) {
                ans = temp;
            }
        }
        else if (counter < mini) {
            mini = counter;
            ans = temp;
        }

        return;
    }
    else if (val > t) return;

    if (val == 0) return;
    if (val != 1) {
        calc(val * val, counter + 1, temp + '*');
    }
    calc(val + val, counter + 1, temp + '+');
}

int main() {
    FastIO

    cin >> s >> t;

    if (s == t) {
        cout << 0;
        return 0;
    }
    calc(s, 0, "");

    if (s != 0) {
        calc(0, 1, "-");
    }
    if (s != 1) {
        calc(1, 1, "/");
    }

    cout << (ans.empty() ? "-1" : ans);

    return 0;
}