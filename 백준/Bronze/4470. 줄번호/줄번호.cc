#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;
    cin.ignore();
    
    for (int i = 1; i <= N; i++) {
        string s;
        getline(cin, s);

        cout << i << ". " << s <<'\n';
    }

    return 0;
}