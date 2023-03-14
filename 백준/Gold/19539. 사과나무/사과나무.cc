#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main(){
    FastIO

    int N;
    cin >> N;



    int all = 0;
    int div2 = 0;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        all += temp;
        div2 += temp / 2;
    }

    if (all % 3 != 0) {
        cout << "NO";
        return 0;
    }

    if (div2 >= all / 3) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }


    return 0;
}