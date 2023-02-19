#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int S, M;
    cin >> S >> M;

    if (S < 1024) {
        cout << "No thanks";
        return 0;
    }
    
    int money = 512;

    vector<int> kugi;

    while(money > 0 && M > 0) {
        if (M >= money) {
            M -= money;
            kugi.push_back(money);
        }
        money /= 2;
    }

    money = S - 1023;

    for (int i = 0; i < kugi.size(); i++) {
        if (money >= kugi[i]) money -= kugi[i];
    }

    if (money) {
        cout << "Impossible";
    }
    else {
        cout << "Thanks";
    }

    return 0;
}