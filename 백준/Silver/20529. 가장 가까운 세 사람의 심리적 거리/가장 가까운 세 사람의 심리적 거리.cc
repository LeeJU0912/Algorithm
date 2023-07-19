#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

map<pair<string, string>, int> DP;

vector<string> MBTI = {
        "ISTJ",
        "ISFJ",
        "INFJ",
        "INTJ",
        "ISTP",
        "ISFP",
        "INFP",
        "INTP",
        "ESTP",
        "ESFP",
        "ENFP",
        "ENTP",
        "ESTJ",
        "ESFJ",
        "ENFJ",
        "ENTJ"
};

int diff(string a, string b) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            count++;
        }
    }

    return count;
}

int main() {
    FastIO

    for (int i = 0; i < 15; i++) {
        for (int j = i + 1; j < 16; j++) {
            DP[{MBTI[i], MBTI[j]}] = diff(MBTI[i], MBTI[j]);
            DP[{MBTI[j], MBTI[i]}] = DP[{MBTI[i], MBTI[j]}];
        }
    }


    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        vector<string> save(n);

        for (int i = 0; i < n; i++) {
            cin >> save[i];
        }

        if (n > 32) {
            cout << 0 << '\n';
            continue;
        }

        int ans = INT_MAX;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    ans = min(ans, DP[{save[i], save[j]}] + DP[{save[j], save[k]}] + DP[{save[i], save[k]}]);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}