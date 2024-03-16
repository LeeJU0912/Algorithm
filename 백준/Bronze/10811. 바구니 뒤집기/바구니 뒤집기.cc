#include <bits/stdc++.h>
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
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < (b - a + 1) / 2; j++) {
            swap(ans[a + j], ans[b - j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}