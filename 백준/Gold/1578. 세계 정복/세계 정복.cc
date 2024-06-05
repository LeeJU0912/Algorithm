#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<long long> save;

int main() {
    FastIO

    cin >> N >> K;
    save = vector<long long>(N);
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    // 그룹 수에 대한 매변탐
    long long start = 1;
    long long end = 50000000000;
    long long ans;
    while(start <= end) {
        // 현재 그룹 수
        long long mid = (start + end) / 2;

        long long group = 0;

        // 각 나라 별로 최대로 참여가 가능한 만큼 때려 넣기 (?)
        for (int i = 0; i < N; i++) {
            group += min(mid, save[i]);
        }

        // 현재 그룹 수 * 그룹 인원 K = 그룹 전체 인원
        // 다 긁어모은 사람이 이론치보다 클 경우 그룹 성립(넘어가는 짜투리를 버리고 성립할 수밖에 없다). 따라서 그룹 수를 늘려본다.
        if (group >= mid * K) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
    }

    cout << ans;

    return 0;
}