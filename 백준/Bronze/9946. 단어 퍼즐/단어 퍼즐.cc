#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

void merge(string& s, int left, int mid, int right) {
    vector<char> sorted = vector<char>(s.size());

    int cursor = left;
    int l = left;
    int r = mid + 1;

    while(l <= mid && r <= right) {
        if (s[l] <= s[r]) {
            sorted[cursor++] = s[l++];
        }
        else {
            sorted[cursor++] = s[r++];
        }
    }

    for (int i = l; i <= mid; i++) {
        sorted[cursor++] = s[i];
    }
    for (int i = r; i <= right; i++) {
        sorted[cursor++] = s[i];
    }

    for (int i = left; i <= right; i++) {
        s[i] = sorted[i];
    }
}

void mergeSort(string& s, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(s, left, mid);
    mergeSort(s, mid + 1, right);

    merge(s, left, mid, right);
}

int main() {
    FastIO

    string a, b;

    int t = 1;
    while(true) {
        cin >> a >> b;

        if (a == "END" && b == "END") break;

        mergeSort(a, 0, a.size() - 1);
        mergeSort(b, 0, b.size() - 1);

        if (a == b) {
            cout << "Case " << t++ << ": " << "same" << '\n';
        }
        else {
            cout << "Case " << t++ << ": " << "different" << '\n';
        }
    }

    return 0;
}