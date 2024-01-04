#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save;

int ans;
vector<int> ans2;

void find_maxi() {
    int mini = *max_element(save.begin(), save.end());
    int maxi = accumulate(save.begin(), save.end(), 0);

    while(mini <= maxi) {
        int mid = (mini + maxi) / 2;

        int hap = 0;

        int counter = 0;

        for (int i = 0; i < N; i++) {
            if (hap + save[i] > mid) {
                hap = 0;
                counter++;
            }
            hap += save[i];
        }

        if (hap <= mid) {
            counter++;
        }

        if (counter <= M) {
            ans = mid;
            maxi = mid - 1;
        }
        else {
            mini = mid + 1;
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    find_maxi();

    cout << ans << '\n';

    int hap = 0;
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (hap + save[i] > ans) {
            ans2.push_back(counter);
            counter = 0;
            hap = 0;
        }
        hap += save[i];
        counter++;
    }

    if (hap > 0 && hap <= ans) {
        ans2.push_back(counter);
    }

    for (int i = 0; i < ans2.size(); i++) {
        while(ans2[i] > 1 && ans2.size() < M) {
            cout << 1 << ' ';
            ans2[i]--;
            M--;
        }
        cout << ans2[i] << ' ';
    }

    return 0;
}