#include <bits/stdc++.h>
using namespace std;

int N, M;
int ans = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    int pack_mini = INT_MAX;
    int str_mini = INT_MAX;

    for (int i = 0; i < M; i++) {
        int pack, str;
        cin >> pack >> str;

        if (pack < pack_mini) pack_mini = pack;
        if (str < str_mini) str_mini = str;
    }

    if (pack_mini >= str_mini * 6) {
        ans = min(ans, N * str_mini);
    }
    else {
        if (N % 6 == 0) {
            ans = min(ans, pack_mini * (N / 6));
        }
        else {
            ans = min(min(ans, pack_mini * (N / 6) + str_mini * (N % 6)), pack_mini * ((N / 6) + 1));
        }
    }

    cout << ans;

    return 0;
}