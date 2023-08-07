#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> A;
int Q;
vector<int> L;
vector<int> ans;

int DP[100001];

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        A.push_back(temp);
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int temp;
        cin >> temp;
        L.push_back(temp);
    }

    int maxi = *max_element(L.begin(), L.end());

    for (int i = 0; i < N; i++) {
        DP[A[i]]++;
    }

    for (int i = 2; i <= maxi; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                DP[i] += DP[j];

                if (j * j != i && j != 1) {
                    DP[i] += DP[i / j];
                }
            }
        }
    }



    for (int i = 0; i < Q; i++) {
        cout << DP[L[i]] << ' ';
    }



    return 0;
}