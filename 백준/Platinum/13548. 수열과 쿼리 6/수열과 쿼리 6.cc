#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int sqrtN;
int save[100001];
int counter[100001];
int count_counter[100001];
int ans[100001];

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

    cin >> N;
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

    int maxi = 0;

    for (int i = left; i <= right; i++) {
        count_counter[counter[save[i]]]--;
        counter[save[i]]++;
        maxi = max(maxi, counter[save[i]]);
        count_counter[counter[save[i]]]++;
    }

    ans[query[0].idx] = maxi;

    for (int i = 1; i < M; i++) {
        int now_left = query[i].left;
        int now_right = query[i].right;

        while(now_left < left) {
            left--;
            count_counter[counter[save[left]]]--;
            counter[save[left]]++;
            maxi = max(maxi, counter[save[left]]);
            count_counter[counter[save[left]]]++;
        }
        while(now_left > left) {
            count_counter[counter[save[left]]]--;
            if ((count_counter[counter[save[left]]] == 0) && (maxi == counter[save[left]])) {
                maxi--;
            }
            counter[save[left]]--;
            count_counter[counter[save[left]]]++;
            left++;
        }
        while(now_right > right) {
            right++;
            count_counter[counter[save[right]]]--;
            counter[save[right]]++;
            maxi = max(maxi, counter[save[right]]);
            count_counter[counter[save[right]]]++;
        }
        while(now_right < right) {
            count_counter[counter[save[right]]]--;
            if ((count_counter[counter[save[right]]] == 0) && (maxi == counter[save[right]])) {
                maxi--;
            }
            counter[save[right]]--;
            count_counter[counter[save[right]]]++;
            right--;
        }

        ans[query[i].idx] = maxi;
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}