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
#include <regex>
#include <numeric>
#include <cctype>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <unordered_map>
#include <cfloat>

using namespace std;

int T;
string s[100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while(T--) {
        int temp;
        string ans;
        cin >> temp;

        for (int i = 0; i < temp; i++) {
            cin >> s[i];
        }

        for (int i = 0; i < temp - 1; i++) {
            for (int j = i + 1; j < temp; j++) {
                int counter = 0;
                string tmp = s[i] + s[j];
                for (int k = 0; k < tmp.length(); k++) {
                    if (tmp[k] == tmp[tmp.length() - 1 - k]) counter++;
                }
                if (counter == tmp.length()) ans = tmp;
            }
        }
        for (int i = temp - 1; i > 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                int counter = 0;
                string tmp = s[i] + s[j];
                for (int k = 0; k < tmp.length(); k++) {
                    if (tmp[k] == tmp[tmp.length() - 1 - k]) counter++;
                }
                if (counter == tmp.length()) ans = tmp;
            }
        }

        if (ans.empty()) {
            cout << 0 << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}