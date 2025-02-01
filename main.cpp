#include <iostream>
#include <cassert>
#include "SkipList.h"

int main() {
    SkipList<int, int> skipList;
    for(int i = 11110; i >= 1; --i) {
        skipList.insert(i, i);
    }
//    skipList.print();
    for(int i = 1; i < 11111; ++i) {
        auto res = skipList.search(i);
        if (res.first != true) {
            std::cout << res.first << std::endl;
            assert(res.first == true);
        }
        if (res.second != i) {
            std::cout << res.second << std::endl;
            assert(res.second == i);
        }
    }
    return 0;
}
