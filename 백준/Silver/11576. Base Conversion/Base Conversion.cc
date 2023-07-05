#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long llpow(long long x, long long y) {
    long long ans = 1;
    for (int i = 0; i < y; i++) {
        ans *= x;
    }
    return ans;
}

int main() {
    FastIO

    int a, b;
    cin >> a >> b;

    int c;
    cin >> c;

    vector<int> save(c);

    for (int i = 0; i < c; i++) {
        cin >> save[i];
    }

    long long ten = 0;

    int multi = 0;

    for (int i = c - 1; i >= 0; i--) {
        ten += llpow(a, multi) * save[i];
        multi++;
    }

    multi = 0;

    while(llpow(b, multi) <= ten) {
        multi++;
    }
    multi--;

    vector<long long> ans;
    while(multi != -1) {
        if (llpow(b, multi) <= ten) {
            ans.push_back(ten / llpow(b, multi));
            ten %= llpow(b, multi);
            multi--;
        }
        else {
            ans.push_back(0);
            multi--;
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}