#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, I, M;
vector<pair<int, int>> fish;

int ans;

int calc(int x1, int x2, int y1, int y2) {
    int ret = 0;
    for (int i = 0; i < fish.size(); i++) {
        if (fish[i].first >= x1 && fish[i].first <= x2 && fish[i].second >= y1 && fish[i].second <= y2) {
            ret++;
        }
    }

    return ret;
}

int main() {
    FastIO

    cin >> N >> I >> M;
    I >>= 1;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        fish.push_back({x, y});
    }

    for (int i = 0; i < fish.size(); i++) {
        int nowX = fish[i].first;

        for (int k = 1; k < I; k++) {
            int startY = fish[i].second;
            int endY = fish[i].second + I - k;

            int startX = nowX - k;
            int endX = nowX;

            for (int j = max(startX, 0); j <= min(N, endX); j++) {
                ans = max(ans, calc(j, j + k, startY, endY));
            }
        }
    }

    cout << ans;

    return 0;
}