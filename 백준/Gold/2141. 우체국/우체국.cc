#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> town;

long long sum[100000];

int binarySearch() {
    int left = 0;
    int right = N - 1;

    int ans = INT_MAX;

    while(left <= right) {
        int mid = (left + right) / 2;
        long long leftSum = sum[mid];
        long long rightSum = sum[N - 1] - sum[mid];
        if (leftSum >= rightSum) {
            right = mid - 1;
            ans = min(ans, town[mid].first);
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        town.emplace_back(a, b);
    }

    sort(town.begin(), town.end());

    sum[0] = town[0].second;

    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + town[i].second;
    }

    cout << binarySearch();

    return 0;
}