/**
 * @file test.cpp
 * @author maj0rio
 * @brief testing class list
 * @version 0.1
 * @date 2024-04-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <cassert>

#include "list.hpp"


int main() {
    List<int> l;
    l.push_back(12);
    l.push_back(13);
    l.push_front(10);

    for (auto& i: l)
        std::cout << i << " ";
    std::cout << "\n";
    std::cout << l.size();
    std::cout << "\n//////////////\n";
    auto it = l.begin();
    std::cout << *it;
    ++it;
    std::cout << it->data;
    std::cout << "\n//////////////\n";
    l.pop_back();
    std::cout << "new_size " << l.size() << "\n"; 
    for (auto& i: l)
        std::cout << i << " ";
    std::cout << "\n";
    l.pop_front();
    for (auto& i: l)
        std::cout << i << " ";



}