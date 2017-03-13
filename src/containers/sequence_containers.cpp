/*
 *  Sequence Containers:
 *      - vector (array list grows in one direction)
 *      - deque (array list that grows in both directions)
 *      - list (doubly linked-list)
 *      - forward list (singly linked-list)
 *      - array (thin layer around native array)
 *
 */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
#include <array>

using namespace std;

/**
 * Example: vector (one-sided array list)
 *
 * http://www.cplusplus.com/reference/vector/vector/
 *
 * [begin, end)
 */
void vector_example() {
    vector<int> vec; // vec.size() == 0
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1); // vec.size() == 3
    // vec: {3,2,1}

    cout << vec[2]; // 1 (no range check)
    cout << vec.at(2); // 1 (throw range_error exception if out of range)

    // can be traversed with normal for loop
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

    // containers should be traversed with iterators
    vector<int>::iterator itr1 = vec.begin();
    vector<int>::iterator itr2 = vec.end(); // end() points to item after last element
    for (vector<int>::iterator itr = itr1; itr != itr2; itr++)
        cout << *itr << "  "; // Print out: 3 2 1

    // C++ 11 iterator
    for (auto it : vec)
        cout << it << " ";

    // include <algorithm> for sort
    sort(itr1, itr2); // vec: 1 2 3

    // vector is a dynamically allocated contiguous array in memory
    int *p = &vec[2]; // 3

    // check if vector is empty
    if (vec.empty()); // true if empty

    // to copy a vector
    vector<int> vec2(vec);

    // other methods
    vec.clear();
    vec2.swap(vec);
}

/**
 * Example: deque (two-sided array list)
 *
 * http://www.cplusplus.com/reference/deque/deque/
 *
 * (begin, end)
 */
void deque_example() {
    deque<int> deq = {1, 2, 3};
    // deq == {1, 2, 3}

    deq.push_front(0);
    deq.push_back(4);
    // deq == {0, 1, 2, 3, 4}

    cout << deq[deq.size() - 1] << endl; // 4: last element
}

/**
 * Example: list (double linked list)
 *
 * http://www.cplusplus.com/reference/list/list/
 *
 * [] <-> [] <-> [] <->
 */
void list_example() {
    list<int> li = {1, 2, 3};   // {1, 2, 3}
    li.push_front(0);           // {0, 1, 2, 3}
    li.push_back(4);            // {0, 1, 2, 3, 4}

    // to get an iter at an element in the list
    list<int>::iterator itr = find(li.begin(), li.end(), 2);
    // {  0  1 (2) 3  4  }

    li.insert(itr, 9);
    // {  0  1  9 (2) 3  4  }

    itr++;
    // {  0  1  9  2 (3) 4  }

    li.erase(itr);
    // {  0  1  9  2  4  }
}

/**
 * Example: forward list (single linked list)
 *
 * http://www.cplusplus.com/reference/forward_list/forward_list/
 *
 * [] -> [] -> [] ->
 */
void forward_list_example() {
    forward_list<int> li = {1, 2, 3};   // {1, 2, 3}
    li.push_front(0);                   // {0, 1, 2, 3}
}

/**
 * Example: array (small wrapper for native arrays)
 *
 * http://www.cplusplus.com/reference/array/array/
 *
 * [x, x, x, x]
 */
void array_example() {
    // int a[3];
    array<int, 3> a = {1, 2, 3};
    a.begin();
    a.end();
    a.size();
    a.swap(a);

    // NOTE: array<int, 3> != array<int, 4>
}

int main() {
    vector_example();
    deque_example();
    list_example();
    forward_list_example();
    array_example();
    return 0;
}