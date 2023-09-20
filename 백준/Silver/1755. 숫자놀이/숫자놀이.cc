#include <bits/stdc++.h>
using namespace std;

int M, N;

map<int, string> number = {{0, "zero"},
                       {1, "one"},
                       {2, "two"},
                       {3, "three"},
                       {4, "four"},
                       {5, "five"},
                       {6, "six"},
                       {7, "seven"},
                       {8, "eight"},
                       {9, "nine"}};

map<string, int> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N;

    for (int i = M; i <= N; i++) {
        string s;
        string tmp = to_string(i);
        for (int j = 0; j < tmp.size(); j++) {
            s += number[tmp[j] - '0'];
        }
        ans.insert({s, i});
    }

    int counter = 0;
    for (auto i : ans) {
        cout << i.second << ' ';
        counter++;
        if (counter == 10) {
            counter = 0;
            cout << '\n';
        }
    }

    return 0;
}