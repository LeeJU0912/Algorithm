#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

int ans[1000001];

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        save.push_back(temp);
    }

    for (int i = 0; i <= 1000000; i++) {
        ans[i] = INT_MAX;
    }

    vector<int> save2 = save;
    sort(save2.begin(), save2.end());

    for (int i = N - 1; i >= 0; i--) {
        ans[save2[i]] = 0;
        int multi = 2;
        while (save2[i] * multi <= save2[N - 1]) {
            if (ans[save2[i] * multi] != INT_MAX) {
                ans[save2[i] * multi]--;
                ans[save2[i]]++;
            }
            multi++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[save[i]] << ' ';
    }

    return 0;
}