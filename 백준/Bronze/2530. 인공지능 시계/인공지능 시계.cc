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

int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int a, b, c;

    cin >> a >> b >> c;

    int d;
    cin >> d;

    int hour = 0;
    int minute = 0;
    int second = 0;
    if (d >= 3600) {
        hour = d / 3600;
        d %= 3600;
    }
    if (d >= 60) {
        minute = d / 60;
        d %= 60;
    }
    hour += a;
    minute += b;
    second = d + c;
    int temp = second / 60;
    second %= 60;
    minute += temp;
    temp = minute / 60;
    minute %= 60;
    hour += temp;

    hour %= 24;

    cout << hour << ' ' << minute << ' ' << second;

    return 0;
}