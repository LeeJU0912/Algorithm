#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string s;
int N;
int chk1[26];
int chk2[26];

int main() {
    FastIO

    cin >> s >> N;
    for (int i = 0; i < N; i++) {
        memset(chk1, 0, sizeof(chk1));
        memset(chk2, 0, sizeof(chk2));

        int A, B, C, D;
        cin >> A >> B >> C >> D;
        A--;
        B--;
        C--;
        D--;

        if (B - A != D - C) {
            cout << "NE" << '\n';
            continue;
        }

        for (int j = 0; j <= B - A; j++) {
            chk1[s[A + j] - 'a']++;
            chk2[s[C + j] - 'a']++;
        }

        bool ans = false;
        for (int j = 0; j < 26; j++) {
            if (chk1[j] != chk2[j]) {
                ans = true;
                break;
            }
        }

        if (ans) {
            cout << "NE" << '\n';
        }
        else {
            cout << "DA" << '\n';
        }
    }

    return 0;
}