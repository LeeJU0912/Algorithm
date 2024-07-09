#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, C, M;
int sqrtN;
int save[300001];
int counter[10001];
int ans[10001];

struct INFO {
    int idx, left, right;
};

vector<INFO> query;

bool comp(INFO a, INFO b) {
    if (a.left / sqrtN != b.left / sqrtN) return a.left / sqrtN < b.left / sqrtN;
    else return a.right < b.right;
}

int main() {
    FastIO

    cin >> N >> C;
    sqrtN = sqrt(N);
    for (int i = 1; i <= N; i++) {
        cin >> save[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        query.push_back({i, a, b});
    }

    sort(query.begin(), query.end(), comp);

    int left = query[0].left;
    int right = query[0].right;

    for (int i = left; i <= right; i++) {
        counter[save[i]]++;
    }

    for (int i = 1; i <= C; i++) {
        if (counter[i] * 2 > (right - left + 1)) {
            ans[query[0].idx] = i;
            break;
        }
    }

    for (int i = 1; i < M; i++) {
        int now_left = query[i].left;
        int now_right = query[i].right;

        while(now_left > left) {
            counter[save[left]]--;
            left++;
        }
        while(now_left < left) {
            left--;
            counter[save[left]]++;
        }
        while(now_right > right) {
            right++;
            counter[save[right]]++;
        }
        while(now_right < right) {
            counter[save[right]]--;
            right--;
        }

        for (int j = 1; j <= C; j++) {
            if (counter[j] * 2 > (now_right - now_left + 1)) {
                ans[query[i].idx] = j;
                break;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        if (ans[i]) {
            cout << "yes " << ans[i] << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }

    return 0;
}