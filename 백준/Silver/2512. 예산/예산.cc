#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int ans = 0;

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int M;
    cin >> M;

    // 이분 탐색을 위한 정렬
    sort(v.begin(), v.end());

    // 비용의 총합을 줄여 나간다.
    int mini = 0; // 최소 비용
    int maxi = v[N - 1]; // 최대 비용
    int hap = 0;

    while(mini <= maxi) {
        hap = 0;
        int mid = (mini + maxi) / 2; // 평균값을 기준으로 시작해본다.
        for (int i = 0; i < N; i++) {
            hap += min(v[i], mid); // M과 mid 이상 값을 통일시킨 값과 비교한다.
        }
        if (M >= hap) { // 비용의 평균 값으로 시도했을 때 조건에 많이 부족할 경우,
            ans = mid;
            mini = mid + 1; // 평균값 이상의 범위에서 다시 시도한다.
        }
        else {
            maxi = mid - 1; // 반대의 경우 평균값 이하의 범위에서 다시 시도한다.
        }
    }

    cout << ans;

    return 0;
}