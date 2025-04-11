#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];

    int l = left;
    int r = right;

    while(l <= r) {
        while(arr[l] < pivot) l++;
        while(arr[r] > pivot) r--;

        if (l <= r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }

    quickSort(arr, left, r);
    quickSort(arr, l, right);
}

int main() {
    FastIO

    int N;
    cin >> N;

    vector<int> save = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    quickSort(save, 0, save.size() - 1);
    
    if (save[0] > 1) {
        cout << 1;
        return 0;
    }

    for (int i = 0; i < N - 1; i++) {
        if (save[i + 1] - save[i] > 1) {
            cout << save[i] + 1;
            return 0;
        }
    }

    cout << save[N - 1] + 1;

    return 0;
}