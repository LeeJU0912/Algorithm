#include <bits/stdc++.h>
using namespace std;

int temp[50];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i < 50; i++) {
        cin >> temp[i];
    }

    int tmp;
    cin >> tmp;

    for (int i = 0; i < 50; i++) {
        if (temp[i] == tmp) {
            if (i < 5) {
                cout << "A+";
            }
            else if (i < 15) {
                cout << "A0";
            }
            else if (i < 30) {
                cout << "B+";
            }
            else if (i < 35) {
                cout << "B0";
            }
            else if (i < 45) {
                cout << "C+";
            }
            else if (i < 48) {
                cout << "C0";
            }
            else {
                cout << "F";
            }
            return 0;
        }
    }

    return 0;
}