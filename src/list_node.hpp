/**
 * @file list_node.hpp
 * @author maj0rio
 * @brief node of list header with templates
 * @version 0.1
 * @date 2024-04-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _LIST_NODE_HPP
#define _LIST_NODE_HPP


#include <utility>


template<typename T>
class Node {
  public:
    Node* prev;
    Node* next;
    T data;

    Node(T item) : data{std::move(item)}, prev(nullptr), next(nullptr) {};
    ~Node() {
        data = T{};
        prev = nullptr;
        next = nullptr;
    }
};

#endif