#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> save;

int plug[101];

int ans;

int main() {
    FastIO

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int temp;
        cin >> temp;

        save.push_back(temp);
    }

    for (int i = 0; i < K; i++) {
        bool flag = false;

        for (int j = 1; j <= N; j++) {
            if (plug[j] == save[i]) {
                flag = true;
                break;
            }
        }

        if (flag) continue;

        for (int j = 1; j <= N; j++) {
            if (plug[j] == 0) {
                plug[j] = save[i];
                flag = true;
                break;
            }
        }

        if (flag) continue;

        int plug_idx = -1;
        int last_idx = -1;
        for (int j = 1; j <= N; j++) {
            int temp = 0;
            for (int k = i + 1; k < K; k++) {
                if (plug[j] == save[k]) break;
                temp = k;
            }

            if (temp > last_idx) {
                plug_idx = j;
                last_idx = temp;
            }
        }

        plug[plug_idx] = save[i];

        ans++;
    }


    cout << ans;

    return 0;
}