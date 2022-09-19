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

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    string s[50];
    char c[50] = "";

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].length(); j++) {
            if (c[j] == 0) {
                c[j] = s[i][j];
            }
            else if (c[j] == s[i][j]) continue;
            else {
                c[j] = '?';
            }
        }
    }

    cout << c;

    return 0;
}