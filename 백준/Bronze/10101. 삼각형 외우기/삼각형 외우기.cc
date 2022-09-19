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

    int a, b, c;

    cin >> a >> b >> c;

    if (a == 60 && b == 60 && c == 60) {
        cout << "Equilateral";
    }
    else if (a + b + c == 180 && (a == b || b == c || a == c)) {
        cout << "Isosceles";
    }
    else if (a + b + c == 180 && (a != b && b != c && a != c)) {
        cout << "Scalene";
    }
    else if (a + b + c != 180) {
        cout << "Error";
    }

    return 0;
}