#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto it = v.cend()-1; true; --it)
    {
        std::cout << *it << " ";
        if (it == v.cbegin()) break;
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}