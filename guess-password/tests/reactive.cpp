#include <iostream>
#include <regex>
using namespace std;

#include "reactive.hpp"

const int MAX_N = 250;
const int MAX_Q = 1000;

int wa(string msg) {
	cout << "WA" << endl;
#ifdef DEBUG
	cerr << msg << endl;
#endif
	reactive_write("#\n");
	reactive_end();
	return 0;
}

int main(int argc, char *argv[]) {
    reactive_start(argv[1]);

    int n;
    cin >> n;
    string s;
    cin >> s;

    reactive_write(to_string(n) + "\n");

    int left = MAX_Q;
    bool found = false;
    string ans;
    while (left >= 0 && !found) {
        string query = reactive_read();
        if (regex_match(query, regex("^!\\s+[a-z]*\\s+$"))) {
            found = true;
			char tmp[251];
			sscanf(query.c_str(), "! %250s", &tmp[0]);
			ans = tmp;
            break;
        }

        if (left == 0) { break; }

        --left;
        if (!regex_match(query, regex("^\\?\\s+\\d+\\s+[a-z]\\s+$"))) {
            return wa("Invalid query: " + query);
        }

        int x;
        char c;
        sscanf(query.c_str(), "? %d %c", &x, &c);
        --x;

        if (x < 0 || n <= x) {
            return wa("Query out of range: " + query);
        }

        if (s[x] == c) { reactive_write("=\n"); }
        else if (s[x] < c) { reactive_write("<\n"); }
        else { reactive_write(">\n"); }
    }

    while (ans.back() == '\n' || ans.back() == '\r' || ans.back() == '\t' || ans.back() == ' ')
        ans.pop_back();

    if (found && ans == s) {
        cout << "AC" << endl;
		reactive_end();
		return 0;
    }

	return wa(found ? "Expected: " + s + "\nReceived: " + ans : "Query limit exceeded");
}
