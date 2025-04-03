#include <iostream>
using namespace std;

#include "reactive.hpp"

const int MAX_N = 250;
const int MAX_Q = 1000;

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
        if ('a' <= query[0] && query[0] <= 'z') {
            found = true;
            ans = query;
            break;
        }

        if (left == 0) { break; }

        --left;
        if (query[0] < '0' || '9' < query[0]) {
            cout << "WA" << endl;
            // cerr << "Invalid query: " << query << endl;
			reactive_write("!\n");
            reactive_end();
            return 0;
        }

        int x;
        char c;
        sscanf(query.c_str(), "%d %c", &x, &c);
        --x;

		if (x < 0 || n <= x) {
			cout << "WA" << endl;
			// cerr << "Invalid query: " << query << endl;
			reactive_write("!\n");
			reactive_end();
			return 0;
		}

        if (s[x] == c) { reactive_write("=\n"); }
        else if (s[x] < c) { reactive_write("<\n"); }
        else { reactive_write(">\n"); }
    }

    while (ans.back() == '\n' || ans.back() == '\r' || ans.back() == ' ')
        ans.pop_back();

    if (found && ans == s) {
        cout << "AC" << endl;
        reactive_end();
    }
    else {
        cout << "WA" << endl;
        //     if (found) {
        //         cerr << "Expected: " << s << endl;
        //         cerr << "Received: " << ans << endl;
        //     }
        //     else { cerr << "Query limit exceeded" << endl; }
		reactive_write("!\n");
        reactive_end();
    }

    return 0;
}
