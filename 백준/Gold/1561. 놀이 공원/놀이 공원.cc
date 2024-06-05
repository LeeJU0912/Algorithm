#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save;

int main() {
    FastIO

    cin >> N >> M;
    save = vector<int>(M);
    for (int i = 0; i < M; i++) {
        cin >> save[i];
    }

    if (N <= M) {
        cout << N;
        return 0;
    }

    long long start = 1;
    long long end = 60000000000;
    long long mini = 0;
    while(start <= end) {
        long long mid = (start + end) / 2;

        long long kids = M;
        for (int i = 0; i < M; i++) {
            kids += mid / save[i];
        }

        if (kids >= N) {
            end = mid - 1;
            mini = mid;
        }
        else {
            start = mid + 1;
        }
    }

    long long counter = M;
    for (int i = 0; i < M; i++) {
        counter += (mini - 1) / save[i];
    }
    for (int i = 0; i < M; i++) {
        if (mini % save[i] == 0) counter++;
        if (counter == N) {
            cout << i + 1;
            break;
        }
    }

    return 0;
}