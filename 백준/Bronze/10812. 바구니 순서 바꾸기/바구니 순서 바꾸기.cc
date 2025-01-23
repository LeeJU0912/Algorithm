#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int ans[101];

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        ans[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        for (int j = 0; j < b - c + 1; j++) {
            int tmp = ans[a];
            for (int k = a; k <= b; k++) {
                if (k == b) {
                    ans[a] = tmp;
                }
                else {
                    int tmp2 = tmp;
                    tmp = ans[k + 1];
                    ans[k + 1] = tmp2;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}