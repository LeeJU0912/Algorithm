#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, t;
int sqrtN;
long long save[100001];
long long ans[100001];
int cnt[1000001];

struct INFO {
    int first, last, idx;
};
vector<INFO> query;

bool comp(INFO a, INFO b) {
    if ((a.first / sqrtN) != (b.first / sqrtN)) return (a.first / sqrtN) < (b.first / sqrtN);
    else return a.last < b.last;
}

int main() {
    FastIO

    cin >> n >> t;
    sqrtN = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> save[i];
    }

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        query.push_back({a, b, i});
    }

    sort(query.begin(), query.end(), comp);

    int first = query[0].first;
    int last = query[0].last;
    long long counter = 0;

    for (int i = first; i <= last; i++) {
        counter -= save[i] * cnt[save[i]] * cnt[save[i]];
        cnt[save[i]]++;
        counter += save[i] * cnt[save[i]] * cnt[save[i]];
    }
    ans[query[0].idx] = counter;

    for (int i = 1; i < t; i++) {
        int nowFirst = query[i].first;
        int nowLast = query[i].last;

        while(first < nowFirst) {
            counter -= save[first] * cnt[save[first]] * cnt[save[first]];
            cnt[save[first]]--;
            counter += save[first] * cnt[save[first]] * cnt[save[first]];
            first++;
        }
        while(first > nowFirst) {
            first--;
            counter -= save[first] * cnt[save[first]] * cnt[save[first]];
            cnt[save[first]]++;
            counter += save[first] * cnt[save[first]] * cnt[save[first]];
        }
        while(last < nowLast) {
            last++;
            counter -= save[last] * cnt[save[last]] * cnt[save[last]];
            cnt[save[last]]++;
            counter += save[last] * cnt[save[last]] * cnt[save[last]];
        }
        while(last > nowLast) {
            counter -= save[last] * cnt[save[last]] * cnt[save[last]];
            cnt[save[last]]--;
            counter += save[last] * cnt[save[last]] * cnt[save[last]];
            last--;
        }

        ans[query[i].idx] = counter;
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}