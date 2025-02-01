#include <iostream>
#include <cassert>
#include "SkipList.h"

int main() {
    SkipList<int, int> skipList;
    for (int i = 11110; i >= 1; --i) {
        skipList.insert(i, i);
    }
//    skipList.print();
    for (int i = 1; i < 11111; ++i) {
        auto res = skipList.search(i);
        assert(res.first == true);
        assert(res.second == i);
    }
    for (int i = 5000; i < 11111; ++i) {
        auto res = skipList.erase(i);
        assert(res == true);
    }
    for (int i = 5000; i < 11111; ++i) {
        auto res = skipList.erase(i);
        assert(res == false);
    }
    for (int i = 1; i < 5000; ++i) {
        auto res = skipList.search(i);
        assert(res.first == true);
        assert(res.second == i);
    }
    for (int i = 5000; i < 11111; ++i) {
        auto res = skipList.search(i);
        assert(res.first == false);
    }
    return 0;
}
