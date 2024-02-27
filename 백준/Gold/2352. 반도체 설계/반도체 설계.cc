#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
vector<int> save;
int lis[40001];

int binary_search(int start, int end, int val) {
    int idx;
    while(start <= end) {
        int mid = (start + end) / 2;

        if (lis[mid] >= val) {
            idx = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return idx;
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    int counter = 1;
    lis[1] = save[0];
    for (int i = 1; i < n; i++) {
        if (lis[counter] < save[i]) {
            lis[counter + 1] = save[i];
            counter++;
        }
        else {
            int idx = binary_search(1, counter, save[i]);

            lis[idx] = save[i];
        }
    }

    cout << counter;

    return 0;
}