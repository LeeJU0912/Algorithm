#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    vector<int> ans(100);
    ans[0] = 1;

    for (int i = 1; i < N; i++) {
        ans[i] = i + 1;

        for (int j = 0; j < save[i]; j++) {
            int temp = ans[i - j];
            ans[i - j] = ans[i - j - 1];
            ans[i - j - 1] = temp;
        }
    }


    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}