#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    string s;
    cin >> s;

    int countR = 0;
    int countB = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') countR++;
        else countB++;
    }

    char leftX = s[0];
    int leftMax = 1;

    char rightX = s[s.size() - 1];
    int rightMax = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != leftX) break;
        leftMax++;
    }
    for (int j = s.size() - 2; j >= 0; j--) {
        if (s[j] != rightX) break;
        rightMax++;
    }

    int leftCalc, rightCalc;
    if (leftX == 'R') {
        leftCalc = countR - leftMax;
    }
    else {
        leftCalc = countB - leftMax;
    }
    if (rightX == 'R') {
        rightCalc = countR - rightMax;
    }
    else {
        rightCalc = countB - rightMax;
    }

    cout << min(min(leftCalc, rightCalc), min(countB, countR));

    return 0;
}