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
#include <list>

using namespace std;

int T;
long long a, b;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while (T--) {
        cin >> a >> b;

        long long length = b - a;
        long long ans = 0;
        long long mx = 0;

        while (mx * mx <= length) {
            mx++;
        }
        mx--;

        ans = 2 * mx - 1;
        long long left_length = length - mx * mx;
        left_length = (long long)ceil((double)left_length / (double)mx);

        ans += left_length;
        cout << ans << '\n';
    }


    return 0;
}