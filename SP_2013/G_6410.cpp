#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int countEmails(string s) {

	stringstream ss;
	ss << s;

	int emailCount = 0;

	while (ss >> s) {
		//cout << s << endl;
		int istart = 3;
		int iend = s.size() - 10;

		for (int i = istart; i < iend; ++i) {
			if (s[i] == 'a' && s[i+1] == 't') {
				int jstart = i+5;
				int jend = min(i + 19, (int)s.size() - 5);
				for (int j = jstart; j < jend; ++j) {
					if (s[j] == 'd' && s[j+1] == 'o' && s[j+2] == 't') {
						emailCount++;
						i = j + 8;
						break;
					}
				}
			}
		}
	}

	return emailCount;
}

int main() {
	int tests;
	scanf("%d\n", &tests);
	while(tests--) {
		string s;
		getline(cin, s);

		printf("%.2f\n", 1.28 * countEmails(s));
	}
}