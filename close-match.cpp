#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<string> dictionary;
	string str;

	while (getline(cin, str) && str[0] != '#') {
		if (str[str.length() - 1] == '\r') {
			str = str.substr(0, str.length() - 1);
		}

		dictionary.push_back(str);
	}

	while (getline(cin, str) && str[0] != '#') {
		bool correct = false;
		bool correct_alter = false;
		bool correct_plus = false;
		bool correct_minus = false;
		string msg;
		int len = str.length();

		if (str[len - 1] == '\r') {
			str = str.substr(0, len - 1);
			len--;
		}

		cout << str;
		for (vector<string>::iterator it = dictionary.begin();
				it != dictionary.end(); ++it) {
			correct_alter = false;
			correct_plus = false;
			correct_minus = false;

			int word_len = (*it).length();
			int token = 1;
			int j = 0;
			if (len == word_len) {
				do {
					if ((*it)[j] != str[j]) {
						if (token == 1) {
							token--;
						} else {
							break;
						}
					}
				} while (++j < len);
				if (len <= j) {
					if (token == 1)
						correct = true;
					else
						correct_alter = true;
				}
			}

			if (!correct) {
				j = 0;
				int expand = 0;
				if (len == word_len + 1) {
					do {
						if ((*it)[j] != str[j + expand]) {
							if (expand == 0) {
								expand++;
								j--;
							} else {
								break;
							}
						}
					} while (++j < len);
					if (len <= j) {
						correct_plus = true;
					}
				}

				j = 0;
				int shrink = 0;
				if (len == (*it).length() - 1) {
					do {
						if ((*it)[j + shrink] != str[j]) {
							if (shrink == 0) {
								shrink++;
								j--;
							} else {
								break;
							}
						}
					} while (++j < len);
					if (len <= j) {
						correct_minus = true;
					}
				}
			}

			if (correct) {
				msg = " is correct";
			} else if (correct_alter || correct_plus || correct_minus) {
				if (msg.empty())
					msg = ": ";
				msg += *it + " ";
			}
		}
		if (msg.empty())
			msg = ": ";
		cout << msg << endl;
	}

	return 0;
}
