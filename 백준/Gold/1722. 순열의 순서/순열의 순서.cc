#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
long long k;
vector<int> save;
vector<int> answer;

bool chk[21];

long long factorial[21];

int main() {
    FastIO

    cin >> N;

    factorial[0] = 1;

    for (int i = 1; i <= 20; i++) {
        factorial[i] = i * factorial[i - 1];
    }

    int order;
    cin >> order;

    if (order == 1) {
        cin >> k;

        for (int i = N - 1; i >= 0; i--) {
            for (int j = 1; j <= 20; j++) {
                if (chk[j]) continue;

                if (k > factorial[i]) {
                    k -= factorial[i];
                }
                else {
                    answer.push_back(j);
                    chk[j] = true;
                    break;
                }

            }
        }

        for (auto i : answer) {
            cout << i << ' ';
        }
    }
    else if (order == 2) {
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            save.push_back(temp);
        }

        long long ans = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 1; j < save[i]; j++) {
                if (chk[j]) continue;

                ans += factorial[N - i - 1];
            }
            chk[save[i]] = true;
        }

        cout << ans + 1;
    }

    return 0;
}