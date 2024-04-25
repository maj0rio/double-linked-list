/**
 * @file list.cpp
 * @author maj0rio
 * @brief Double linked list implementation
 * @version 0.1
 * @date 2024-04-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _DOUBLE_LINKED_LIST_CPP
#define _DOUBLE_LINKED_LIST_CPP


#include <stdexcept>

#include "list.hpp"
#include "list_node.hpp"
#include "list_iterator.hpp"




template<typename T>
size_t List<T>::size() const noexcept {
    return size_;
}

template<typename T>
Iterator<T> List<T>::begin() const {
    Iterator<T> it{this->start_};
    return it;
}

template<typename T>
Iterator<T> List<T>::end() const {
    Iterator<T> it{this->tail_};
    return it;
}

template<typename T>
void List<T>::push_back(const T &x){
    Node<T>* new_node = new Node<T>(x);
    Node<T>* old_end = this->tail_;

    if (old_end != nullptr)
        old_end->next = new_node;
    
    new_node->prev = old_end;
    this->tail_ = new_node;
    this->size_ += 1;
}

template<typename T>
void List<T>::push_front(const T &x) {
    Node<T>* new_node = new Node<T>(x);
    Node<T>* old_start = this->start_;

    if (old_start != nullptr)
        old_start->prev = new_node;
    
    new_node->next = old_start;
    this->start_ = new_node;
    this->size_ += 1;
}

template<typename T>
void List<T>::pop_back() {
    if (size_ < 1)
        throw std::runtime_error("Size should be positive");
    
    Node<T>* old_tail = this->tail;
    if (old_tail->prev != nullptr) {
        Node<T>* new_tail = old_tail->prev;
        this->tail_ = new_tail;
    } else {
        this->tail_ = nullptr;
    }
    delete old_tail;
    size_ -= 1;
}

template<typename T>
void List<T>::pop_front() {
    if (size_ < 1)
        throw std::runtime_error("Size should be positive");
    
    Node<T>* old_start = this->start_;
    if (old_start->next != nullptr) {
        Node<T>* new_start = old_start->next;
        this->start_ = new_start;
    } else {
        this->start_ = nullptr;
    }
    delete old_start;
    size_ -= 1;
}

template<typename T>
List<T>& List<T>::operator=(const List<T> &rhs) {
    if (this != &rhs) {
        this->size_ = rhs.size();
        Iterator    
    }
}
#endif