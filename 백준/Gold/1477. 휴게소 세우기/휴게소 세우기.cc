#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, L;
vector<int> save;
int ans;

int main() {
    FastIO

    cin >> N >> M >> L;

    save = vector<int>(N + 2);

    save[0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> save[i];
    }

    save[N + 1] = L;

    sort(save.begin(), save.end());

    int start = 1;
    int end = L;

    while(start <= end) {
        int mid = (start + end) / 2;

        int counter = 0;

        for (int i = 1; i < save.size(); i++) {
            int gap = save[i] - save[i - 1];

            counter += gap / mid;
            if (gap % mid == 0) counter--;
        }

        if (counter > M) start = mid + 1;
        else {
            ans = mid;
            end = mid - 1;
        }
    }

    cout << ans;

    return 0;
}