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

using namespace std;

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,
               31, 30, 31};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int a, b;

    cin >> a >> b;

    int i = 1;
    int sum = 0;
    while(i < a) {
        sum += day[i];
        i++;
    }
    sum += b;
    int ans = sum % 7;
    if (ans == 1) {
        cout << "MON";
    }
    else if (ans == 2) {
        cout << "TUE";
    }
    else if (ans == 3) {
        cout << "WED";
    }
    else if (ans == 4) {
        cout << "THU";
    }
    else if (ans == 5) {
        cout << "FRI";
    }
    else if (ans == 6) {
        cout << "SAT";
    }
    else if (ans == 0) {
        cout << "SUN";
    }

    return 0;
}