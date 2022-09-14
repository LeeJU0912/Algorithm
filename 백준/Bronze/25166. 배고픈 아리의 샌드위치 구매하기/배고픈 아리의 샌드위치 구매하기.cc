#include <iostream>
#include <bitset>

using namespace std;

int S, M;

int main() {
    int coin = 0b1111111111;
    cin >> S >> M;

    if (S <= 0b1111111111) cout << "No thanks";
    else {
        coin += M;
        int ans = S ^ coin;
        if (ans == 0) cout << "Thanks";
        else cout << "Impossible";
    }

    return 0;
}