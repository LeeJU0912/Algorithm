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

using namespace std;

int survey_plus;
int survey_minus;
int sum;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> sum;

    while(sum--) {
        int temp;
        cin >> temp;
        if (temp) survey_plus++;
        else survey_minus++;
    }

    if (survey_plus > survey_minus)
        cout << "Junhee is cute!";
    else
        cout << "Junhee is not cute!";

    return 0;
}