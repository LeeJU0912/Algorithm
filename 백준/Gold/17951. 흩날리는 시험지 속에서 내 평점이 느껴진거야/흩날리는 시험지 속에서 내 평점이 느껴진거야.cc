#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> save;

int main() {
    FastIO

    cin >> N >> K;

    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    int start = 0;
    int end = accumulate(save.begin(), save.end(), 0);

    while(start <= end) {
        int mid = (start + end) / 2;

        int counter = 0;
        int split = 0;

        for (int i = 0; i < N; i++) {
            counter += save[i];

            if (counter >= mid) {
                counter = 0;
                split++;
            }

            if (split > K - 1) break;
        }

        if (split > K - 1) start = mid + 1;
        else end = mid - 1;
    }

    cout << end;

    return 0;
}