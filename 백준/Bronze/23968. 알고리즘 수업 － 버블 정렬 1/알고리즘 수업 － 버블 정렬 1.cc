#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, K;
    cin >> N >> K;
    vector<int> arr = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ans++;

                if (ans == K) {
                    cout << arr[j] << ' ' << arr[j + 1];
                    return 0;
                }
            }
        }
    }

    cout << -1;

    return 0;
}