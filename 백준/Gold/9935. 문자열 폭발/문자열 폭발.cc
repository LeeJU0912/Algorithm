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

using namespace std;

string s;
string boom;
string answer;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    cin >> boom;

    for (int i = 0; i < s.length(); i++) {
        answer += s[i];
        if (answer.back() == boom.back()) {
            bool chk = true;
            if (answer.length() < boom.length()) continue;
            for (int j = 0; j < boom.length(); j++) {
                if (answer[answer.length() - boom.length() + j] != boom[j]) {
                    chk = false;
                    break;
                }
            }
            if (chk) {
                for (int j = 0; j < boom.size(); j++){
                    answer.pop_back();
                }
            }
        }
    }
    if (answer.empty()) {
        cout << "FRULA";
    }
    else {
        cout << answer;
    }

    return 0;
}