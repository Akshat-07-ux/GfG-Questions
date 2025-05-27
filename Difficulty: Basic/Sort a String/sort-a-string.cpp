#include <algorithm> // for sort

string sort(string s) {
    std::sort(s.begin(), s.end());
    return s;
}
