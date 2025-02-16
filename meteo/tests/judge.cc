#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    // This command initializes checker environment.
    registerTestlibCmd(argc, argv);
    // Now there are three global variables specifying testlib streams:
    // inf - stream with the testdata.
    // ouf - stream with the contestant output.
    // ans - stream with the jury answer.
    // All those streams provide the similar interface for reading data.

    // This function reads a single integer from the participant output that 
    // should be between -2000 and 2000. If it doesn't belong to the specified
    // range, checker finishes with verdict _pe and comment saying that [sum of numbers]
    // is outside of the specified range.
    double actual = ouf.readDouble(0.0, 1.0, "probability");
    
    // This function reads a single integer from the jury output. Here we suppose
    // that jury's answer is correct and we do not need to additionally verify it.
    double expected = ans.readDouble(0.0, 1.0, "probability"); // We suppose that jury's answer is correct
    
    if (!doubleCompare(expected, actual, 1e-9)) {
        quitf(_wa, "Expected %.12f, but found %.12f (absolute error = %.12f, relative error = %.12f)",
              expected, actual, fabs(expected - actual));
    }

    quitf(_ok, "Accepted: %.12f", actual);
}