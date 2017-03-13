/*
 *  Unordered Containers:
 *      - unordered set / multiset      Hash Set
 *      - unordered map / multimap      Hash Table
 *
 */

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

/**
 * Example: unordered_set (hash set, no duplicates, unordered)
 *
 * http://www.cplusplus.com/reference/unordered_set/unordered_set/
 */
void unordered_set_example() {
    std::unordered_set<int> us = {1, 0, 3, 1}; // {1, 0 , 3}
    us.insert(3);
    for (int v : us)
        std::cout << v << std::endl;
    // prints out: 3 0 1

    std::unordered_set<int>::iterator it = us.find(0); // O(1)
    if (it != us.end()) // check if it found an item
        std::cout << *it << std::endl;

    auto vec = std::vector<int>{99, 98};
    us.insert(vec.begin(), vec.end()); // inserts every item in vec

    /* Hash Table API */
    printf("Load Factor = %f = %llu / %llu\n", us.load_factor(), us.size(), us.bucket_count());
    us.load_factor(); // ratio of total #elements/#buckets
    us.bucket(0); // tells which bucket '0' is in
    us.bucket_count(); // total number of buckets
}

/**
 * Example: unordered_map (hash map, associative array)
 *
 * http://www.cplusplus.com/reference/unordered_map/unordered_map/
 */
void unordered_map_example() {
    std::unordered_map<char, std::string> um = {
            {'S', "Sunday"},
            {'M', "Monday"},
            {'T', "Tuesday"},
    };

    std::cout << um['S'] << std::endl; // prints Sunday, no range check
    std::cout << um.at('S') << std::endl; // with range check

    // ways to insert
    um.insert(std::make_pair('R', "Thursday")); // insert() CANNOT update an already existing mapping
    um['W'] = "Wednesday"; // this way can update an existing mapping

    // passing const map will not allow use subscript operator, even when not modifying the value
    const std::unordered_map<char, std::string> const_map(um);
    // obviously won't work since its const
    //      const_map['F'] = "Friday";

    // this will not work either because compiler assumes you will write when using subscript operator
    //      std::cout << const_map['F'] << std::endl;

    // to print out, you should use find()
    auto itr = const_map.find('W');
    if (itr != const_map.end())
        std::cout << (*itr).second << std::endl;
}

int main() {
    printf("\n---------- Example: unordered set ----------\n");
    unordered_set_example();

    printf("\n---------- Example: unordered map ----------\n");
    unordered_map_example();
    return 0;
}