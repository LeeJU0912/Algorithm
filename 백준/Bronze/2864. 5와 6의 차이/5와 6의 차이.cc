#include <bits/stdc++.h>
using namespace std;

string A, B;

string A_max, A_min;
string B_max, B_min;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> A >> B;

    A_max = A;
    A_min = A;
    B_max = B;
    B_min = B;

    for (int i = 0; i < A.length(); i++) {
        if (A[i] == '5' || A[i] == '6') {
            A_max[i] = '6';
            A_min[i] = '5';
        }
    }

    for (int i = 0; i < B.length(); i++) {
        if (B[i] == '5' || B[i] == '6') {
            B_max[i] = '6';
            B_min[i] = '5';
        }
    }

    cout << stoi(A_min) + stoi(B_min) << ' ' << stoi(A_max) + stoi(B_max);

    return 0;
}