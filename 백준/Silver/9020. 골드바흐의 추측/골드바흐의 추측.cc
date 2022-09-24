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
int sosu[10001];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    sosu[1] = 1;

    for (int i = 2; i <= 100; i++) {
        if (sosu[i] == 1) continue;
        for (int j = i * i; j <= 10000; j += i) {
            sosu[j] = 1;
        }
    }

    while(T--) {
        int temp;
        cin >> temp;

        int temp2 = INT_MAX;
        pair<int, int> p;

        for (int i = 2; i <= temp / 2; i++) {
            if (sosu[i] == 0 && sosu[temp - i] == 0) {
                if (temp2 > temp - i - i) {
                    temp2 = temp - i - i;
                    p.first = i;
                    p.second = temp - i;
                }
            }
        }

        cout << p.first << ' ' << p.second << '\n';


    }

    return 0;
}