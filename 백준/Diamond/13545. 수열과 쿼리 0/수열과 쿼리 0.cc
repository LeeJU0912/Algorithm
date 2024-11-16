#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int sqrtN;
vector<int> prefix;

struct INFO {
    int idx, l, r;

    bool operator < (const INFO &b) const {
        if (l/sqrtN != b.l/sqrtN) {
            return l < b.l;
        }
        return r < b.r;
    }
};

vector<INFO> queries;
int bucket[100001];
int length_count[200001];
list<int> range[200001];

int ans[100000];

void pop_left(int idx) {
    auto &dq = range[prefix[idx]];
    int now = dq.back() - dq.front();
    length_count[now]--;
    bucket[now/sqrtN]--;
    dq.pop_front();

    if (!dq.empty()) {
        now = dq.back() - dq.front();
        length_count[now]++;
        bucket[now/sqrtN]++;
    }
}

void pop_right(int idx) {
    auto &dq = range[prefix[idx]];
    int now = dq.back() - dq.front();
    length_count[now]--;
    bucket[now/sqrtN]--;
    dq.pop_back();

    if (!dq.empty()) {
        now = dq.back() - dq.front();
        length_count[now]++;
        bucket[now/sqrtN]++;
    }
}

void add_left(int idx) {
    int now = 0;
    auto &dq = range[prefix[idx]];
    if (!dq.empty()) {
        now = dq.back() - dq.front();
        length_count[now]--;
        bucket[now/sqrtN]--;
    }

    dq.push_front(idx);
    now = dq.back() - dq.front();
    length_count[now]++;
    bucket[now/sqrtN]++;
}

void add_right(int idx) {
    int now = 0;
    auto &dq = range[prefix[idx]];
    if (!dq.empty()) {
        now = dq.back() - dq.front();
        length_count[now]--;
        bucket[now/sqrtN]--;
    }

    dq.push_back(idx);
    now = dq.back() - dq.front();
    length_count[now]++;
    bucket[now/sqrtN]++;
}

int query() {
    for (int i = N/sqrtN; i >= 0; i--) {
        if (bucket[i] == 0) continue;
        for (int j = sqrtN - 1; j >= 0; j--) {
            int idx = i * sqrtN + j;
            if (length_count[idx] > 0) {
                return idx;
            }
        }
    }

    return 0;
}

int main() {
    FastIO

    cin >> N;
    sqrtN = sqrt(N);
    prefix = vector<int>(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        prefix[i] = x + prefix[i - 1];
    }
    for (int i = 0; i <= N; i++) {
        prefix[i] += 100000;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({i, a - 1, b});
    }

    sort(queries.begin(), queries.end());

    int left = queries[0].l;
    int right = queries[0].r;

    for (int i = left; i <= right; i++) {
        add_right(i);
    }

    ans[queries[0].idx] = query();

    for (int i = 1; i < M; i++) {
        while(queries[i].l < left) add_left(--left);
        while(queries[i].r > right) add_right(++right);
        while(left < queries[i].l) pop_left(left++);
        while(right > queries[i].r) pop_right(right--);

        ans[queries[i].idx] = query();
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}