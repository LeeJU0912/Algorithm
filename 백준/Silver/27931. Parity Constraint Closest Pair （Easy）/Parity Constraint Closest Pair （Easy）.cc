#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> odd, even;

int odds = INT_MAX;
int evens = INT_MAX;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp % 2) {
            odd.push_back(tmp);
        }
        else {
            even.push_back(tmp);
        }
    }

    if (!odd.empty()) {
        sort(odd.begin(), odd.end());
        for (int i = 0; i < odd.size() - 1; i++) {
            evens = min(evens, odd[i + 1] - odd[i]);
        }
    }
    if (!even.empty()) {
        sort(even.begin(), even.end());
        for (int i = 0; i < even.size() - 1; i++) {
            evens = min(evens, even[i + 1] - even[i]);
        }
    }

    if (evens == INT_MAX) evens = -1;

    if (odd.empty() || even.empty()) {
        cout << evens << ' ' << -1;
        return 0;
    }

    for (int i = 0; i < odd.size(); i++) {
        int idx = lower_bound(even.begin(), even.end(), odd[i]) - even.begin();

        if (idx == even.size()) {
            odds = min(odds, odd[i] - even[idx - 1]);
        }
        else if (idx == 0) {
            odds = min(odds, even[idx] - odd[i]);
        }
        else {
            odds = min(odds, even[idx] - odd[i]);
            odds = min(odds, odd[i] - even[idx - 1]);
        }
    }

    cout << evens << ' ' << odds;

    return 0;
}