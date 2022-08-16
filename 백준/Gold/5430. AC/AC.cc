#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>
#include <climits>
#include <cstdlib>
#include <utility>

using namespace std;

int T;
int n;
deque<int> v;
bool rev;
int error;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while (T--) {
        string p;
        cin >> p;

        cin >> n;

        string temp2;
        cin >> temp2;

        int temp = 0;
        if (temp2.length() > 2) {
            for (int i = 1; i < temp2.length(); i++) {
                if (temp2[i] >= '0' && temp2[i] <= '9') {
                    temp *= 10;
                    temp += temp2[i] - '0';
                }
                else {
                    v.push_back(temp);
                    temp = 0;
                }
            }
        }


        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                if (rev) {
                    rev = false;
                }
                else {
                    rev = true;
                }
            }
            else if (p[i] == 'D') {
                if (v.empty()) {
                    cout << "error" << '\n';
                    error = 1;
                    break;
                }
                if (rev) {
                    v.pop_back();
                }
                else {
                    v.pop_front();
                }
            }
        }


        if (error) {
            error = 0;
            v.clear();
            rev = false;
            continue;
        }

        cout << "[";

        if (rev) {
            for (int i = v.size() - 1; i >= 0; i--) {

                if (i == 0) {
                    cout << v[0];
                    break;
                }
                cout << v[i] << ",";
            }


        }
        else {
            for (int i = 0; i < v.size(); i++) {

                if (i == v.size() - 1) {
                    cout << v[v.size() - 1];
                    break;
                }
                cout << v[i] << ",";
            }

        }
        cout << "]" << '\n';

        rev = false;
        v.clear();
    }

    return 0;
}