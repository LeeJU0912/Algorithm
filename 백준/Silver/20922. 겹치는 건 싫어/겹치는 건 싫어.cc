#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> a;
unordered_map<int, int> mp;

int main() {
    FastIO

    cin >> N >> K;
    a = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int start = 0;
    int end = 0;

    int ans = 1;

    while (end != N) {

        mp[a[end]]++;

        if (mp[a[end]] > K) {
            ans = max(ans, end - start);
            while (mp[a[end]] > K) {
                mp[a[start]]--;
                start++;
            }
        }

        end++;
    }

    ans = max(ans, end - start);

    cout << ans;

    return 0;
}