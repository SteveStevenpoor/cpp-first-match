#ifndef MATCH_H
#define MATCH_H

#include <new>
#include <utility>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

// short curciets execution
template <typename Checker, typename... Args>
int getIndexOfFirstMatch(Checker check, Args&&... args) {
    int idx = -1;
    int i = 0;

    ((check(std::forward<Args>(args))? idx = i : i++), ...);
    
    return idx;
}


#endif // MATCH_H
