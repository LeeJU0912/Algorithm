#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> save;
int sorted[1000001];
long long ans;

void merge(int start, int mid, int end) {
    int a = start;
    int b = mid + 1;
    int idx = start;

    while(a <= mid && b <= end) {
        if (save[a] <= save[b]) {
            sorted[idx] = save[a];
            a++;
        }
        else {
            sorted[idx] = save[b];
            b++;

            ans += mid - a + 1;
        }
        idx++;
    }

    while(a <= mid) {
        sorted[idx++] = save[a++];
    }
    while(b <= end) {
        sorted[idx++] = save[b++];
    }

    for (int i = start; i <= end; i++) {
        save[i] = sorted[i];
    }
}

void mergesort(int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    mergesort(start, mid);
    mergesort(mid + 1, end);
    merge(start, mid, end);
}

int main() {
    FastIO

    int N;
    cin >> N;

    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    mergesort(0, N - 1);

    cout << ans;

    return 0;
}