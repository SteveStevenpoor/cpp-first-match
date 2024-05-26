#ifndef MATCH_H
#define MATCH_H

#include <new>
#include <utility>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

template <typename Checker, typename... Args>
int getIndexOfFirstMatch(Checker check, Args&&... args) {
    int idx = -1;
    vector<bool> check_results = {check(std::forward<Args>(args)) ...};
    
    for (int i = 0; i < check_results.size(); i++) {
        if (check_results[i]) {
            idx = i;
            break;
        }
    }
    return idx;
}


#endif // MATCH_H
