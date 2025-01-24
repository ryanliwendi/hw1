#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr ullistStr;
    ullistStr.push_back("hello");
    ullistStr.push_front("world");
    ullistStr.push_back("abcd");
    ullistStr.pop_front();
    ullistStr.push_front("efgh");
    cout << ullistStr.size() << endl;
    cout << ullistStr.get(2) << endl;
    cout << ullistStr.get(0) << endl;
}
