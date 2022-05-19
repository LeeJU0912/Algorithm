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

using namespace std;

int counter;

stack<string> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i, j;
	
	string a;

	string answer;

	cin >> a;
	
	for (i = 0; i < a.length(); i++) {
		if (a[i] == '(') {

			s.push("(");
		}
		else if (a[i] == ')') {

			while (s.top() != "(") {
				answer += s.top();
				s.pop();
			}
			s.pop();
		}

		else if (a[i] == '+') {
			while (s.size() != 0 && s.top() != "(") {
				answer += s.top();
				s.pop();
			}
			s.push("+");
		}
		else if (a[i] == '-') {
			while (s.size() != 0 && s.top() != "(") {
				answer += s.top();
				s.pop();
			}
			s.push("-");
		}
		else if (a[i] == '*') {
			while (s.size() != 0 && (s.top() == "*" || s.top() == "/")) {
				answer += s.top();
				s.pop();
			}
			s.push("*");
		}
		else if (a[i] == '/') {
			while (s.size() != 0 && (s.top() == "*" || s.top() == "/")) {
				answer += s.top();
				s.pop();
			}
			s.push("/");
		}
		else {
			answer += a[i];
		}
	}
	while (s.size() != 0) {
		answer += s.top();
		s.pop();
	}
	cout << answer;
	return 0;
}