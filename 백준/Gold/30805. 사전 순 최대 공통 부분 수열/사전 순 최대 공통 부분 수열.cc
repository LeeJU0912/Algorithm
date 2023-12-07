#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> A, B;

vector<int> ans;

void solve(int a_idx, int b_idx) {
    int maxi = 0;
    int maxi_a_idx = -1, maxi_b_idx = -1;
    for (int i = a_idx; i < N; i++) {
        for (int j = b_idx; j < M; j++) {
            if (A[i] == B[j]) {
                if (maxi < A[i]) {
                    maxi = A[i];
                    maxi_a_idx = i;
                    maxi_b_idx = j;
                }
            }
        }
    }

    if (maxi_a_idx == -1) return;

    ans.push_back(maxi);
    solve(maxi_a_idx + 1, maxi_b_idx + 1);
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        B.push_back(temp);
    }

    solve(0, 0);

    cout << ans.size() << '\n';

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}