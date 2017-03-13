/*
 * Associative Containers: (always sorted, usually with binary tree)
 *      - set, multiset
 *      - map, multimap
 *
 */

#include <iostream>
#include <set>

/**
 * Example: set (no duplicates)
 *
 * http://www.cplusplus.com/reference/set/set/
 */
void set_example() {
    std::set<int> s;
    s.insert(3); // {3}
    s.insert(2); // {2, 3}
    s.insert(1); // {1, 2, 3} -- O(log(n)) insertion

    std::set<int>::iterator it;
    it = s.find(2); // O(log(n)) to find, points to 2

    std::pair<std::set<int>::iterator, bool> ret;
    ret = s.insert(2); // no new element inserted, bool will be false
    if (ret.second == false)
        it = ret.first; // ret.first is the element that already exists

    // *it = 10; NOT ALLOWED, read-only, breaks data structure

    // 1 (2) 3
    // we wish to insert 4 and it acts as a hint of where to find the insert location
    s.insert(it, 4); // it still points to 2
    // 1 (2) 3  4
    s.erase(it); // {1, 3, 4}
    s.erase(4); // {1, 3}

    for (int item : s)
        std::cout << item << " ";
}

/**
 * Example: multiset (allows duplicates)
 *
 * http://www.cplusplus.com/reference/set/multiset/
 */
void multiset_example() {
    std::multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    // {1, 2}

    // *it = 10; NOT ALLOWED, read-only
}

int main() {
    set_example();
    multiset_example();
    return 0;
}
