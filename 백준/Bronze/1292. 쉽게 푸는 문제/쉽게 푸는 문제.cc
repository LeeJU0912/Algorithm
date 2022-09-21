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

int A, B;
int num[1000];
int counter = 0;
int now = 1;
int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> A >> B;

    for (int i = 0; i < 1000; i++) {
        num[i] = now;

        counter++;
        if (counter == now) {
            now++;
            counter = 0;
        }
    }

    for (int i = A - 1; i < B; i++){
        ans += num[i];
    }

    cout << ans;

    return 0;
}