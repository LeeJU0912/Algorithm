#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;

    int N;
    cin >> N;

    vector<string> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    for (int go = 0; go < 26; go++) {
        for (int i = 0; i < s.length(); i++) {
            s[i]++;
            if (s[i] > 'z') s[i] = 'a';
        }

        for (int i = 0; i < N; i++) {
            if (s.length() < save[i].length()) continue;
            for (int j = 0; j < s.length() - save[i].length() + 1; j++) {
                string temp;
                for (int k = j; k < j + save[i].length(); k++) {
                    temp += s[k];
                }
                if (temp == save[i]) {
                    cout << s;
                    return 0;
                }
            }
        }
    }

    return 0;
}