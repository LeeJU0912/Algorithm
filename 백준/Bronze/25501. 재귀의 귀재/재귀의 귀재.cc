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
string s;
int counter = 1;

void recursion(const string& st, int l, int r) {
    if (l >= r) {
        cout << 1 << ' ' << counter << '\n';
        }
    else if (st[l] != st[r]) {
        cout << 0 << ' ' << counter << '\n';
    }
    else {
        counter++;
        recursion(st, l+1, r-1);
    }
}

void isPalindrome(const string& st) {
    recursion(st, 0, st.length() - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> s;
        isPalindrome(s);
        counter = 1;
    }

    return 0;
}