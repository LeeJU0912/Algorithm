#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int sqrtN;
int A[100001];
int counter[1000001];
int ans[100001];

struct Query {
    int idx, left, right;

    bool operator < (const Query &x) const {
        if (left / sqrtN != x.left / sqrtN) return left / sqrtN < x.left / sqrtN;
        else return right < x.right;
    }
};

vector<Query> save;

int main() {
    FastIO

    cin >> N;
    sqrtN = sqrt(N);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        save.push_back({i, x, y});
    }

    sort(save.begin(), save.end());

    int sum = 0;
    int left = save[0].left;
    int right = save[0].right;
    for (int i = left; i <= right; i++) {
        if (counter[A[i]] == 0) sum++;
        counter[A[i]]++;
    }

    ans[save[0].idx] = sum;

    for (int i = 1; i < M; i++) {

        while(save[i].left < left) {
            --left;
            if (counter[A[left]] == 0) {
                sum++;
            }
            counter[A[left]]++;
        }
        while(save[i].left > left) {
            counter[A[left]]--;
            if (counter[A[left]] == 0) {
                sum--;
            }
            left++;
        }
        while(save[i].right > right) {
            right++;
            if (counter[A[right]] == 0) {
                sum++;
            }
            counter[A[right]]++;
        }

        while(save[i].right < right) {
            counter[A[right]]--;
            if (counter[A[right]] == 0) {
                sum--;
            }
            right--;
        }

        ans[save[i].idx] = sum;
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}