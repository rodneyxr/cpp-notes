#include <iostream>

using namespace std;

template<typename T>
T square(T x) {
    return x * x;
}

int main() {
    // We can define type
    cout << square<int>(1) << endl;
    cout << square<double>(1.0) << endl;

    // type can also be inferred
    cout << square(1) << endl;

    return 0;
}