#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, Q;
int sqrtN;
int save[1000001];
int cnt[1000001];
int ans[1000001];

vector<int> temp;

struct INFO {
    int first, last, idx;
};

vector<INFO> query;

bool comp(INFO a, INFO b) {
    if (a.first / sqrtN != b.first / sqrtN) return a.first / sqrtN < b.first / sqrtN;
    else return a.last < b.last;
}

int main() {
    FastIO

    cin >> N;
    sqrtN = sqrt(N);
    for (int i = 1; i <= N; i++) {
        cin >> save[i];
        temp.emplace_back(save[i]);
    }

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 1; i <= N; i++) {
        save[i] = lower_bound(temp.begin(), temp.end(), save[i]) - temp.begin();
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        query.push_back({a, b, i});
    }

    sort(query.begin(), query.end(), comp);

    int first = query[0].first;
    int last = query[0].last;
    int counter = 0;

    for (int i = first; i <= last; i++) {
        cnt[save[i]]++;
        if (cnt[save[i]] == 1) counter++;
    }
    ans[query[0].idx] = counter;

    for (int i = 1; i < Q; i++) {
        while(first < query[i].first) {
            cnt[save[first]]--;
            if (cnt[save[first]] == 0) counter--;
            first++;
        }
        while(first > query[i].first) {
            first--;
            cnt[save[first]]++;
            if (cnt[save[first]] == 1) counter++;
        }
        while(last < query[i].last) {
            last++;
            cnt[save[last]]++;
            if (cnt[save[last]] == 1) counter++;
        }
        while(last > query[i].last) {
            cnt[save[last]]--;
            if (cnt[save[last]] == 0) counter--;
            last--;
        }

        ans[query[i].idx] = counter;
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}