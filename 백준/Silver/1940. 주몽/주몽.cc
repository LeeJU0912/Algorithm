#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

int main() {
    FastIO

    cin >> N;
    cin >> M;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    int front = 0;
    int back = N - 1;

    int ans = 0;

    while (front < back) {
        int hap = save[front] + save[back];

        if (hap > M) {
            back--;
        }
        else if (hap < M) {
            front++;
        }
        else {
            ans++;
            front++;
            back--;
        }
    }

    cout << ans;

    return 0;
}