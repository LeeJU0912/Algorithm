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

string s[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string a;
    cin >> a;


    if (a.size() == 1 && a[0] == '0') {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < a.length(); i++) {
        if (i == 0) {
            string tmp = s[a[i] - '0'];
            while(tmp.front() != '1') {
                tmp.erase(tmp.begin(), tmp.begin() + 1);
            }
            cout << tmp;
        }
        else {
            cout << s[a[i] - '0'];
        }
    }

    return 0;
}