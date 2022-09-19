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

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);

    map<string, int> id_idx_map;

    map<string, set<string>> report_map;

    for (int i = 0; i < id_list.size(); i++) {
        id_idx_map[id_list[i]] = i;
    }

    for (auto rep : report) {
        stringstream ss(rep);
        string from, to;
        ss >> from >> to;

        report_map[to].insert(from);
    }

    for (auto iter : report_map) {
        if (iter.second.size() >= k) {
            for (auto in_iter : iter.second) {
                answer[id_idx_map[in_iter]]++;
            }
        }
    }
    
    return answer;
}