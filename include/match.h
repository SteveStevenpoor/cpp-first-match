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
    int i = 0;

    ((check(std::forward<Args>(args)) || (i++, false)) || ...);

    if (i >= sizeof...(Args)) i = -1;
    
    return i;
}


#endif // MATCH_H
