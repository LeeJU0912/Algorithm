#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
int sorted[500001];
long long ans;

void merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right) {
        if (save[i] <= save[j]) {
            sorted[k] = save[i];
            i++;
        }
        else {
            sorted[k] = save[j];
            ans += j - k;
            j++;
        }
        k++;
    }
    if (i > mid) {
        for (int x = j; x <= right; x++) {
            sorted[k] = save[x];
            k++;
        }
    }
    else {
        for (int x = i; x <= mid; x++) {
            sorted[k] = save[x];
            k++;
        }
    }
    for (int x = left; x <= right; x++) {
        save[x] = sorted[x];
    }
}

void mergesort(int left, int right) {
    if (left >= right) return;
    int mid = (left + right) >> 1;
    mergesort(left, mid);
    mergesort(mid + 1, right);
    merge(left, mid, right);
}

int main() {
    FastIO

    cin >> N;

    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    mergesort(0, N - 1);

    cout << ans;

    return 0;
}