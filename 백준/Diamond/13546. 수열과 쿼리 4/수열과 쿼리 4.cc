#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K, M;
int sqrtN;
vector<int> save;
vector<int> length_count;
vector<int> bucket;

list<int> position[100001];

struct INFO {
    int idx, start, end;

    bool operator < (const INFO &b) const {
        if (start/sqrtN != b.start/sqrtN) {
            return start/sqrtN < b.start/sqrtN;
        }
        return end < b.end;
    }
};

vector<INFO> queries;
int ans[100001];

void right_push(int idx) {
    int now = 0;
    auto &dq = position[save[idx]];
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

void right_pop(int idx) {
    auto &dq = position[save[idx]];
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

void left_push(int idx) {
    int now = 0;
    auto &dq = position[save[idx]];
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

void left_pop(int idx) {
    auto &dq = position[save[idx]];
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

int find_max_length() {
    for (int i = N / sqrtN; i >= 0; i--) {
        if (bucket[i] == 0) continue;
        for (int j = sqrtN - 1; j >= 0; j--) {
            if (length_count[i * sqrtN + j] > 0) {
                return i * sqrtN + j;
            }
        }
    }
    return 0;
}

int main() {
    FastIO

    cin >> N >> K;
    sqrtN = sqrt(N);
    save = vector<int>(N + 1);
    length_count = vector<int>(N * 2);
    bucket = vector<int>(N);

    for (int i = 1; i <= N; i++) {
        cin >> save[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({i, l, r});
    }

    sort(queries.begin(), queries.end());

    int start = queries[0].start;
    int end = queries[0].end;

    for (int i = start; i <= end; i++) {
        right_push(i);
    }

    ans[queries[0].idx] = find_max_length();

    for (int i = 1; i < M; i++) {

        while(end < queries[i].end) {
            right_push(++end);
        }
        while(start > queries[i].start) {
            left_push(--start);
        }

        while(end > queries[i].end) {
            right_pop(end--);
        }
        while(start < queries[i].start) {
            left_pop(start++);
        }

        ans[queries[i].idx] = find_max_length();
    }


    for (int i = 0; i < M; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}