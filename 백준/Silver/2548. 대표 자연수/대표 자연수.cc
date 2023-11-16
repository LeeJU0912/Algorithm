#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

int ans = INT_MAX;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        save.push_back(temp);
    }

    sort(save.begin(), save.end());

    int start = 0;
    int end = N - 1;

    int x = INT_MAX;

    while(start <= end) {
        int mid = (start + end) / 2;

        int temp = 0;
        for (int i = 0; i < N; i++) {
            temp += abs(save[mid] - save[i]);
        }

        if (temp <= ans) {
            ans = temp;
            x = min(x, mid);
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << save[x];

    return 0;
}