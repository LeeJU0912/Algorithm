#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;


    if (N != 1) {
        for (int i = 0; i < N - 1; i++) {
            cout << ' ';
        }
        cout << '*' << '\n';
    }


    for (int i = 1; i <= N - 2; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            cout << ' ';
        }
        cout << '*';

        for (int j = 0; j < i * 2 - 1; j++) {
            cout << ' ';
        }
        cout << '*' << '\n';


    }

    for (int i = 0; i < N * 2 - 1; i++) {
        cout << '*';
    }

    return 0;
}