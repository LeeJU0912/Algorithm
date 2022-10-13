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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    for (int i = 0; i < T; i++) {
        for (int j = 0; j <= i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    for (int i = T - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}