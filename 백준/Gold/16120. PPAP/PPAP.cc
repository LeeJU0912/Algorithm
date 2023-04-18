#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    
    if (s == "P") {
        cout << "PPAP";
        return 0;
    }

    string temp;

    for (int i = 0; i < 4; i++) {
        temp.push_back(s[i]);
    }

    for (int i = 4; i < s.length(); i++) {
        int idx = temp.length() - 4;

        if (idx >= 0) {
            if (temp[idx] == 'P' && temp[idx + 1] == 'P' && temp[idx + 2] == 'A' && temp[idx + 3] == 'P') {
                for (int j = 0; j < 4; j++) {
                    temp.pop_back();
                }
                temp.push_back('P');
            }
        }

        temp.push_back(s[i]);
    }

    if (temp.length() == 4) {
        if (temp[0] == 'P' && temp[1] == 'P' && temp[2] == 'A' && temp[3] == 'P') {
            for (int j = 0; j < 4; j++) {
                temp.pop_back();
            }
        }
    }

    if (temp.empty()) {
        cout << "PPAP";
    }
    else {
        cout << "NP";
    }


    return 0;
}