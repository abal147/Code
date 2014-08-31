#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

set<string> sounds;

void whatDoesTheFoxSay() {
	sounds.clear();
	string line;
	getline(cin, line);
	stringstream ss(line);
	string temp;
	vector<string> words;
	while (ss.good()) {
		ss >> temp;
		words.push_back(temp);
	}
	
	while (true) {
		getline(cin, temp);
		if (temp[temp.size()-1] == '?') {
			break;
		}

		temp = temp.substr(temp.find_last_of(' ')+1);
//		cout << "Inserting " << temp << endl;
		sounds.insert(temp);
	}

	temp = "";

	for (int i = 0; i < words.size(); ++i) {
		if (!sounds.count(words[i])) {
			temp += words[i] + " ";
		}
	}

	if (temp != "") {
		temp = temp.substr(0, temp.size()-1);
	}

	cout << temp << endl;

}

int main() {
	int tests;
	scanf("%d\n", &tests);
	while (tests--) {
		whatDoesTheFoxSay();
	}
	return 0;
}
