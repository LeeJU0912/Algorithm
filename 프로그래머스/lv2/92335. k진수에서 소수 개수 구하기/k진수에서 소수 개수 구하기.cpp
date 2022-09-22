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

int solution(int n, int k) {
    int answer = 0;

    vector<int> v;
    while(n != 0) {
        v.push_back(n % k);
        n /= k;
    }

    int i = v.size() - 1;
    while(i >= 0) {
        long temp = 0;
        bool chk = true;
        while(i >= 0 && v[i] != 0) {
            temp *= 10;
            temp += v[i];
            i--;
        }

        i--;
        if (temp == 0 || temp == 1) continue;
        else if (temp > 3) {
            for (int j = 2; j <= sqrt(temp); j++) {
                if(temp % j == 0) chk = false;
            }
        }

        if (chk) answer++;
    }

    return answer;
}