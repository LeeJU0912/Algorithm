#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string A;
    string B;

    cin >> A >> B;

    int maxi = INT_MAX;

    for (int i = 0; i < B.length() - A.length() + 1; i++) {
        int temp = 0;
        for (int j = 0; j < A.length(); j++) {
            if (B[i + j] != A[j]) temp++;
        }
        maxi = min(temp, maxi);
    }

    cout << maxi;

    return 0;
}