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

int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s.length() >= 3 && i < s.length() - 2) {
            if (s[i] == 'd') {
                if (s[i + 1] == 'z' && s[i + 2] == '=') {
                    ans++;
                    i += 2;
                    continue;
                }
            }
        }

        if (s.length() >= 2 && i < s.length() - 1) {

            if (s[i] == 'c') {
                if (s[i + 1]== '=') {
                    ans++;
                    i++;
                    continue;
                }
                else if (s[i + 1]== '-') {
                    ans++;
                    i++;
                    continue;
                }
            }
            else if (s[i] == 'd' && s[i + 1] == '-') {
                ans++;
                i++;
                continue;
            }
            else if (s[i] == 'l' && s[i + 1] == 'j') {
                ans++;
                i++;
                continue;
            }
            else if (s[i] == 'n' && s[i + 1] == 'j') {
                ans++;
                i++;
                continue;
            }
            else if (s[i] == 's' && s[i + 1] == '=') {
                ans++;
                i++;
                continue;
            }
            else if (s[i] == 'z' && s[i + 1] == '=') {
                ans++;
                i++;
                continue;
            }
        }

        ans++;
    }

    cout << ans;

    return 0;
}