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

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map<string, pair<int, int>> m;
    map<string, int> temp;

    int base_time = fees[0];
    int base_fee = fees[1];
    int plus_time = fees[2];
    int plus_fee = fees[3];



    for (int i = 0; i < records.size(); i++) {
        string hour;
        string minute;
        string time;
        string num;
        string stat;
        istringstream iss(records[i]);
        iss >> time >> num >> stat;

        hour.push_back(time[0]);
        hour.push_back(time[1]);
        minute.push_back(time[3]);
        minute.push_back(time[4]);

        int ihour = stoi(hour);
        int iminute = stoi(minute);


        if (stat == "IN") {
            m[num].first = ihour * 60 + iminute;
            m[num].second = 0;
        }
        else if (stat == "OUT") {
            temp[num] += ihour * 60 + iminute - m[num].first;
            m[num].first = 0;
            m[num].second = 1;
        }
    }

    for (auto i : m) {
        if (i.second.second == 0) {
            i.second.first = 1439 - i.second.first;
            temp[i.first] += i.second.first;
        }
    }
    for (auto i : temp) {
        int total = i.second;
        int ans = 0;
        if (total <= base_time) {
            ans = base_fee;
        }
        else {
            ans = base_fee;
            total -= base_time;
            if (total % plus_time != 0) {
                ans += (total / plus_time + 1) * plus_fee;
            }
            else {
                ans += (total / plus_time) * plus_fee;
            }
        }

        answer.push_back(ans);
    }
    return answer;
}