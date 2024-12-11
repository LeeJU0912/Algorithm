#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K, D;
vector<pair<pair<int, int>, int>> save;

bool overD(int limit) {
    long long hap = 0;
    for (int i = 0; i < K; i++) {
        int left = save[i].first.first;
        int right = min(limit, save[i].first.second);
        int gap = save[i].second;

        if (right < left) continue;

        hap += (right - left) / gap + 1;
    }

    if (hap >= D) return true;
    else return false;
}

int main() {
    FastIO

    cin >> N >> K >> D;
    for (int i = 0; i < K; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        save.push_back({{A, B}, C});
    }

    int start = 1;
    int end = N;
    int ans;
    while(start <= end) {
        int mid = (start + end) / 2;

        if (overD(mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << ans;

    return 0;
}