/**
 * @file list.hpp
 * @author maj0rio
 * @brief Double linked list header
 * @version 0.1
 * @date 2024-04-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _DOUBLE_LINKED_LIST_HPP
#define _DOUBLE_LINKED_LIST_HPP


#include <cstddef>


template<typename T> 
class List {

  private:
    struct Node {
        Node* prev;
        Node* next;
        T data;

        Node(T item) : data{std::move(item)} {};
    };

  public:
    List() : size_(0), start_(nullptr), tail(nullptr) {};
    List(const List& other);
    ~List();

    List& operator=(const List &rhs);

    void push_back(const T &x);
    void push_front(const T &x);
    void pop_back();
    void pop_front();

    size_t size() const noexcept; 

    private:
        size_t size_;
        Node* start_;
        Node* tail;
};

#endif _DOUBLE_LINKED_LIST_HPP