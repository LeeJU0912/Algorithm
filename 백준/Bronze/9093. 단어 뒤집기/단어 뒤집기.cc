#include <bits/stdc++.h>
using namespace std;

int TC;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    stringstream ss;
    cin >> TC;
    cin.ignore();
    while (TC--) {

        string input;

        getline(cin, input);

        vector<string> v;
        ss.str(input);
        string temp;

        while(getline(ss, temp, ' '))
            v.push_back(temp);

        for (auto i : v) {
            for (int j = i.length() - 1; j >= 0; j--) {
                cout << i[j];
            }
            cout << ' ';
        }
        cout << '\n';

        ss.str("");
        ss.clear();
    }
    return 0;
}