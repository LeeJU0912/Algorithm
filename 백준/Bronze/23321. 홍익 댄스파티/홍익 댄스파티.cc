#include <bits/stdc++.h>
using namespace std;

string s[5];
int mark[10000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i < 5; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < s[0].length(); i++) {
        for (int j = 0; j < 5; j++) {
            if (s[j][i] == 'w') {
                mark[i] = 2;
            }
            else if (s[j][i] == 'm') {
                mark[i] = 1;
            }
            else if (s[j][i] == 'L') {
                mark[i] = 3;
            }
        }
    }

    for (int i = 0; i < s[0].length(); i++) {
        for (int j = 0; j < 5; j++) {
            if (mark[i] == 1) {
                if (s[j][i] == '.') {
                    s[j][i] = 'o';
                }
                else if (s[j][i] == 'o') {
                    s[j][i] = 'w';
                }
                else if (s[j][i] == 'm') {
                    s[j][i] = 'l';
                }
                else if (s[j][i] == 'l') {
                    s[j][i] = 'n';
                }
                else if (s[j][i] == 'n') {
                    s[j][i] = '.';
                }
            }
            else if (mark[i] == 2) {
                if (s[j][i] == 'o') {
                    s[j][i] = '.';
                }
                else if (s[j][i] == 'w') {
                    s[j][i] = 'o';
                }
                else if (s[j][i] == 'l') {
                    s[j][i] = 'm';
                }
                else if (s[j][i] == 'n') {
                    s[j][i] = 'l';
                }
                else if (s[j][i] == '.') {
                    s[j][i] = 'n';
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << s[i] << '\n';
    }


    return 0;
}