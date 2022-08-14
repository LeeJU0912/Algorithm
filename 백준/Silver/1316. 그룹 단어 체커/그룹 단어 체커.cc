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

using namespace std;

int N;
string s;
int check[26];
int counter;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;
        //

        if (s.length() <= 2) {
            counter++;
            continue;
        }
        int j = 0;
        while (true) {
            if (j == s.length() - 1) {
                counter++;
                break;
            }
            check[s[j] - 'a'] = 1;
            if (s[j] != s[j + 1]) {
                if (check[s[j + 1] - 'a'] == 1) {
                    break;
                }
            }
            j++;
        }
        s.clear();
        memset(check, 0, sizeof(check));
    }

    cout << counter;

    return 0;
}