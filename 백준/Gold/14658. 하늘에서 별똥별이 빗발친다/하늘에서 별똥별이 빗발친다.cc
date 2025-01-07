#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, L, K;
vector<pair<int, int>> stars;

int main() {
    FastIO

    cin >> N >> M >> L >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        stars.push_back({x, y});
    }

    sort(stars.begin(), stars.end());

    vector<pair<int, int>> edges;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            edges.push_back({stars[i].first, stars[j].second});
        }
    }

    int maxi = 0;

    for (int i = 0; i < edges.size(); i++) {
        int nowX = edges[i].first;
        int nowY = edges[i].second;

        int start = 0;
        int end = K - 1;
        int startIdx = 0;
        while(start <= end) {
            int mid = (start + end) / 2;

            if (stars[mid].first >= nowX) {
                startIdx = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        start = 0;
        end = K - 1;
        int endIdx = end;
        while(start <= end) {
            int mid = (start + end) / 2;

            if (stars[mid].first <= nowX + L) {
                endIdx = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        int bounce = 0;
        for (int j = startIdx; j <= endIdx; j++) {
            if (stars[j].second < nowY || stars[j].second >= nowY + L + 1) continue;
            bounce++;
        }

        maxi = max(maxi, bounce);
    }
    
    cout << K - maxi;

    return 0;
}