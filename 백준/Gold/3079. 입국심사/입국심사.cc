#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long N, M;
vector<long long> save;

int main() {
    FastIO

    cin >> N >> M;

    save = vector<long long>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    long long start = 1;
    long long end = save.back() * M;

    while(start <= end) {
        long long mid = (start + end) / 2;

        long long counter = 0;

        for (int i = 0; i < N; i++) {
            counter += mid / save[i];

            if (counter > M) break;
        }

        if (counter >= M) end = mid - 1;
        else start = mid + 1;
    }

    cout << start;

    return 0;
}