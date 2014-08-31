#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d\n", &n);
	while (n--) {
		string s;
		getline(cin, s, '\n');
		if (s.back() != '1' || s.back() != '0') {
			s.pop_back();
		}
		cout << s << endl;
		int mid = s.size() >> 1;
		printf("len: %d, (%d, %d)\n", s.size(), mid, mid ^ 1);
		if (s[mid] == s[(mid ^ 1)]) {
			printf("Do-it\n");
		} else {
			printf("Do-it-Not\n");
		}
	}
	return 0;
}