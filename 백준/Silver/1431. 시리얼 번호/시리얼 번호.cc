#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<string> save;

bool compare(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    else {
        int hap = 0;
        for (int j = 0; j < a.length(); j++) {
            if (a[j] >= '0' && a[j] <= '9') {
                hap += a[j] - '0';
            }
        }

        int hap2 = 0;
        for (int j = 0; j < b.length(); j++) {
            if (b[j] >= '0' && b[j] <= '9') {
                hap2 += b[j] - '0';
            }
        }

        if (hap == hap2) {
            return a < b;
        }
        else {
            return hap < hap2;
        }
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        save.emplace_back(s);
    }

    sort(save.begin(), save.end(), compare);

    for (const auto& i : save) {
        cout << i << '\n';
    }

    return 0;
}