#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, L;
vector<string> save;



int main() {
    FastIO

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        save.push_back(s);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            for (int k = 0; k < 26; k++) {
                string now = save[i];
                now[j] = (char)('A' + k);

                int chk = 0;

                for (int l = 0; l < N; l++) {
                    int counter = 0;
                    for (int m = 0; m < L; m++) {
                        if (now[m] != save[l][m]) {
                            counter++;
                        }
                    }

                    if (counter >= 2) {
                        break;
                    }
                    else {
                        chk++;
                    }
                }

                if (chk == N) {
                    cout << now;
                    return 0;
                }
            }
        }
    }

    cout << "CALL FRIEND";

    return 0;
}