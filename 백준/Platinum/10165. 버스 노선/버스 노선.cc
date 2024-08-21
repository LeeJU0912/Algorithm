#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<pair<pair<int, int>, int>> save;
bool chk[500001];

bool comp(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    if (a.first.first == b.first.first) return a.first.second > b.first.second;
    else return a.first.first < b.first.first;
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b && b != 0) {
            save.push_back({{a - N, b}, i});
        }
        else {
            if (b == 0) {
                save.push_back({{a, b + N}, i});
                save.push_back({{a - N, b}, i});
            }
            else {
                save.push_back({{a - N, b - N}, i});
                save.push_back({{a, b}, i});
            }
        }
    }

    sort(save.begin(), save.end(), comp);

    for (int i = 0; i < save.size(); i++) {
        if (chk[save[i].second]) continue;

        vector<int> exclude;

        int nowEnd = save[i].first.second;

        int start = i + 1;
        int end = save.size() - 1;
        int nextEnd = start;
        while (start <= end) {
            int mid = (start + end) / 2;

            if (save[mid].first.first >= nowEnd) {
                end = mid - 1;
            } else {
                nextEnd = mid;
                start = mid + 1;
            }
        }

        for (int j = i + 1; j <= nextEnd; j++) {
            if (save[j].first.second <= nowEnd) {
                exclude.push_back(save[j].second);
            }
        }

        for (int j : exclude) {
            chk[j] = true;
        }
    }

    for (int i = 1; i <= M; i++) {
        if (chk[i]) continue;
        cout << i << ' ';
    }

    return 0;
}