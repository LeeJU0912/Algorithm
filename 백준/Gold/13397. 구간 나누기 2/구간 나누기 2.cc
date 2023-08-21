#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save;

int main() {
    FastIO

    cin >> N >> M;

    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    int start = 0;
    int end = *max_element(save.begin(), save.end());

    while(start <= end) {
        int mid = (start + end) / 2;

        int counter = 0;
        int maxi = save[0];
        int mini = save[0];
        for (int i = 1; i < N; i++) {
            if (save[i] - mini > mid || maxi - save[i] > mid) {
                counter++;
                maxi = save[i];
                mini = save[i];
            }

            if (mini > save[i]) mini = save[i];
            if (maxi < save[i]) maxi = save[i];

            if (counter >= M) break;
        }

        if (counter >= M) start = mid + 1;
        else end = mid - 1;
    }

    cout << start;


    return 0;
}