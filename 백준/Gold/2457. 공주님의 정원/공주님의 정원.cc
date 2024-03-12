#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int date[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

vector<pair<int, int>> save;

int start_date = 60;
int end_date = 334;

int ans = INT_MAX;

void solve(int idx, int counter, int end) {
    if (end > end_date) {
        ans = counter;
        return;
    }

    int a = idx + 1;
    int max_len = end;

    for (int i = idx + 1; i < N; i++) {
        if (save[i].first > end) break;
        if (max_len < save[i].second) {
            a = i;
            max_len = save[i].second;
        }
    }

    if (max_len > end) {
        solve(a, counter + 1, max_len);
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int start = 0;
        int end = 0;

        for (int j = 1; j < a; j++) {
            start += date[j];
        }
        start += b;

        for (int j = 1; j < c; j++) {
            end += date[j];
        }
        end += d;

        save.push_back({start,end});
    }

    sort(save.begin(), save.end());

    int idx = 0;
    int max_len = 0;
    for (int i = 0; i < N; i++) {
        if (save[i].second < start_date) continue;
        if (save[i].first > start_date) break;

        if (max_len <= save[i].second) {
            idx = i;
            max_len = save[i].second;
        }
    }

    if (max_len) {
        solve(idx, 1, max_len);
    }

    cout << (ans == INT_MAX ? 0 : ans);

    return 0;
}