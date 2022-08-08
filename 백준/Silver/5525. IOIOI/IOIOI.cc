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

using namespace std;

int N;
int M;
int counter;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> M;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i + 1] == 'O' && s[i + 2] == 'I') {
            int check = 0;
            while (s[i] == 'I' && s[i + 1] == 'O') {
                i += 2;
                check++;
                if (s[i] == 'I' && check == N) {
                    check--;
                    counter++;
                }
            }
        }
    }
    
    cout << counter;

    return 0;
}