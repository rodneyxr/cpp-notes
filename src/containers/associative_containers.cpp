/*
 * Associative Containers: (always sorted, usually with binary tree)
 *      - set, multiset
 *      - map, multimap
 *
 */

#include <iostream>
#include <set>
#include <map>

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
    for (auto v : ms)
        std::cout << v << std::endl;
    // {1, 1}

    // *it = 10; NOT ALLOWED, read-only
}

/**
 * Example: map (key/value pairs, no duplicated keys, sorted by key)
 *
 * http://www.cplusplus.com/reference/map/map/
 */
void map_example() {
    std::map<std::string, int> m;
    m.insert(std::pair<std::string, int>("User0", 0));
    m.insert(std::make_pair("User1", 5));

    std::map<std::string, int>::iterator it = m.end();
    m.insert(it, std::make_pair("User2", 10)); // 'it' is a hint

    for (std::pair<std::string, int> p : m) {
        std::cout << "{" << p.first << ":" << p.second << "} ";
    } // Print out: {User0:0} {User1:5} {User2:10}

    it = m.find("User1"); // O(log(n))
    std::cout << (*it).second << std::endl; // prints out 5

    // remove "User1"
    m.erase(it);
    for (auto p : m)
        std::cout << p.first << std::endl;
}

/**
 * Example: multimap (key/values pairs, duplicated keys allowed, key is const)
 *
 * http://www.cplusplus.com/reference/map/multimap/
 */
void multimap_example() {
    std::multimap<char, int> mm;
    mm.insert(std::make_pair('a', 1));
    mm.insert(std::make_pair('b', 99));
    mm.insert(std::make_pair('a', 0));

    for (auto p : mm)
        std::cout << p.first << " => " << p.second << std::endl;
    // a => 1
    // a => 0
    // b => 99
    // NOTE: values are not sorted

    auto it = mm.find('a');
    std::cout << (*it).first << " => " << (*it).second << std::endl;
    // a => 1
}

int main() {
    printf("\n---------- Example: set ----------\n");
    set_example();

    printf("\n---------- Example: multiset ----------\n");
    multiset_example();

    printf("\n---------- Example: map ----------\n");
    map_example();

    printf("\n---------- Example: multimap ----------\n");
    multimap_example();
    return 0;
}
