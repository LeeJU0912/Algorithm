#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> save;

// 0 ~ N-1 중에서 dist 간격 만큼 C개를 구할 수 있는가?
bool possible(int dist) {
    int counter = 1;
    int check = save[0];

    for (int i = 1; i < N; i++) {
        if (save[i] - check >= dist) {
            counter++;
            check = save[i];
        }
    }

    if (counter >= C) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    sort(save.begin(), save.end());

    int mini = 1;   // 가능한 최소 거리
    int maxi = save[N - 1] - save[0];   // 가능한 최대 거리
    int ans = 0;

    while (mini <= maxi) {
        int mid = (mini + maxi) / 2;    // (최소 + 최대) / 2 = 평균 을 이용하여 이분 탐색
        if (possible(mid)) {
            ans = max(ans, mid);
            mini = mid + 1; // 가능할 경우 거리를 1 늘려서 다시 시도
        }
        else {
            maxi = mid - 1; // 불가능할 경우 거리를 1 줄여서 다시 시도
        }
    }

    cout << ans;

    return 0;
}