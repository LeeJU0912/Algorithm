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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    int timer[3] = {0,};

    if (T >= 300) {
        timer[0] = T / 300;
        T %= 300;
    }
    if (T >= 60) {
        timer[1] = T / 60;
        T %= 60;
    }
    if (T >= 10) {
        timer[2] = T / 10;
        T %= 10;
    }
    if (T != 0) {
        cout << -1;
        return 0;
    }
    else {
        cout << timer[0] << ' ' << timer[1] << ' ' << timer[2];
    }

    return 0;
}