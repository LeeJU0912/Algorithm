#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K, D;

vector<pair<int, vector<int>>> save;

int algo[31];

long long ans;

bool comp(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
    return a.first < b.first;
}

int main() {
    FastIO

    cin >> N >> K >> D;

    for (int i = 0; i < N; i++) {
        vector<int> temp;

        int M, d;
        cin >> M >> d;

        for (int j = 0; j < M; j++) {
            int A;
            cin >> A;

            temp.push_back(A);
        }

        save.push_back({d, temp});
    }

    sort(save.begin(), save.end(), comp);

    int from = 0;
    int to;

    int start = 0;
    int end = N - 1;
    while(start <= end) {
        int mid = (start + end) / 2;

        if (save[mid].first - save[from].first > D) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
            to = mid;
        }
    }

    for (int i = from; i <= to; i++) {
        for (int j = 0; j < save[i].second.size(); j++) {
            algo[save[i].second[j]]++;
        }
    }

    while(to != N) {
        if (save[to].first - save[from].first > D) {
            for (int i = 0; i < save[from].second.size(); i++) {
                algo[save[from].second[i]]--;
            }
            from++;
            if (from == N) break;
            continue;
        }

        long long all_algo = 0;
        long long same_algo = 0;

        for (int i = 1; i <= 30; i++) {
            if (algo[i] == (to - from + 1)) {
                same_algo++;
                all_algo++;
            }
            else if (algo[i] != 0) {
                all_algo++;
            }
        }

        ans = max(ans, (all_algo - same_algo) * (to - from + 1));

        to++;
        if (to == N) break;
        for (int i = 0; i < save[to].second.size(); i++) {
            algo[save[to].second[i]]++;
        }
    }

    cout << ans;

    return 0;
}