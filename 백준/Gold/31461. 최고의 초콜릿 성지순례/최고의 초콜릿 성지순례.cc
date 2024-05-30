#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int a, b, c, d;
vector<int> s[2];

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        s[0] = vector<int>(N);
        s[1] = vector<int>(N);

        for (int i = 0; i < N; i++) {
            cin >> s[0][i];
        }
        for (int i = 0; i < N; i++) {
            cin >> s[1][i];
        }

        cin >> b >> a >> d >> c;
        a--; b--; c--; d--;

        if (b > d) {
            swap(a, c);
            swap(b, d);
        }

        if (b == d) {
            int maxi = s[a][b] + s[c][d];

            int hap = maxi;
            for (int i = b + 1; i < N; i++) {
                maxi = max(maxi, max(hap + s[0][i] + s[1][i], max(hap + s[0][i], hap + s[1][i])));
                hap += s[0][i] + s[1][i];
            }

            hap = s[a][b] + s[c][d];
            for (int i = b - 1; i >= 0; i--) {
                maxi = max(maxi, max(hap + s[0][i] + s[1][i], max(hap + s[0][i], hap + s[1][i])));
                hap += s[0][i] + s[1][i];
            }

            cout << maxi << '\n';
        }
        else {
            int start_maxi = s[a][b] + max(0, s[!a][b]);
            int end_maxi = s[c][d] + max(0, s[!c][d]);

            // 가운데 계산
            int mid_maxi = 0;
            for (int i = b + 1; i < d; i++) {
                mid_maxi = max(mid_maxi + s[0][i] + s[1][i], max(mid_maxi + s[0][i], mid_maxi + s[1][i]));
            }

            // 뒤로 빠졌다가 다시 가는 경우(양쪽 존재)
            int left_maxi = s[a][b] + s[!a][b];
            int hap = left_maxi;
            for (int i = b - 1; i >= 0; i--) {
                left_maxi = max(left_maxi, max(hap + s[0][i] + s[1][i], max(hap + s[0][i], hap + s[1][i])));
                hap += s[0][i] + s[1][i];
            }
            start_maxi = max(start_maxi, left_maxi);

            int right_maxi = s[c][d] + s[!c][d];
            hap = right_maxi;
            for (int i = d + 1; i < N; i++) {
                right_maxi = max(right_maxi, max(hap + s[0][i] + s[1][i], max(hap + s[0][i], hap + s[1][i])));
                hap += s[0][i] + s[1][i];
            }
            end_maxi = max(end_maxi, right_maxi);

            cout << start_maxi + mid_maxi + end_maxi << '\n';

        }
    }

    return 0;
}