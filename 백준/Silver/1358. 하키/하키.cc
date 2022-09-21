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

double W, H, X, Y, P;
int ans;

double length(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool square(double x, double y) {
    if (x >= X && x <= X + W && y >= Y && y <= Y + H) return true;
    else return false;
}

bool circle(double x, double y) {
    if (length(X, Y + H / 2, x, y) <= H / 2) return true;
    else if (length(X + W, Y + H / 2, x, y) <= H / 2) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> W >> H >> X >> Y >> P;

    for (int i = 0; i < P; i++) {
        double x, y;
        cin >> x >> y;
        if(square(x, y)) ans++;
        else if(circle(x, y)) ans++;
    }

    cout << ans;


    return 0;
}