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

#include <iostream>
#include <stdexcept>
#include <assert.h>

#include "list.hpp"
#include "list_node.hpp"


template<typename T>
size_t List<T>::size() const noexcept {
    return size_;
}

template<typename T>
typename List<T>::Iterator List<T>::begin() const {
    Iterator it(start_, this);
    return it;
}

template<typename T>
typename List<T>::Iterator List<T>::end() const {
    Iterator it{nullptr, this};
    return it;
}

template<typename T>
void List<T>::push_back(const T &x){
    if (size_ == 0) {
        Node<T>* new_node = new Node<T>(x);
        start_ = new_node;
        tail_ = new_node; 
        size_ += 1;
        return; 
    } 
    Node<T>* new_node = new Node<T>(x);
    Node<T>* old_end = this->tail_;
    old_end->next = new_node;
        
    new_node->prev = old_end;
    tail_ = new_node;
    size_ += 1;
}

template<typename T>
void List<T>::push_front(const T &x) {
    if (size_ == 0) {
        Node<T> *new_node = new Node<T>(x);
        start_ = new_node;
        tail_ = new_node; 
        size_ += 1;
        return; 
    }
    Node<T>* new_node = new Node<T>(x);
    Node<T>* old_start = this->start_;
    old_start->prev = new_node;
    
    new_node->next = old_start;
    this->start_ = new_node;
    this->size_ += 1;
}

template<typename T>
void List<T>::pop_back() {
    if (size_ < 1)
        throw std::runtime_error("Size should be positive");
    if (size_ == 1) {
        Node<T>* head = start_;
        delete head;
        start_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        return;
    }
    Node<T>* old_tail = tail_;
    Node<T>* new_tail = old_tail->prev;
    tail_ = new_tail;
    tail_->next = nullptr;
    delete old_tail;
    size_ -= 1;
}

template<typename T>
void List<T>::pop_front() {
    if (size_ < 1)
        throw std::runtime_error("Size should be positive");
    
    if (size_ == 1) {
        Node<T> *head = start_;
        delete head;
        start_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        return;
    }
    Node<T>* old_start = start_;
    Node<T>* new_start = old_start->next;
    start_ = new_start;
    start_->prev = nullptr;
    delete old_start;
    size_ -= 1;
}

template<typename T>
List<T>& List<T>::operator=(const List<T> &rhs) {
    if (this != &rhs) {
        this->clear();
        Iterator it = rhs.begin();
        while (it != rhs.end()) {
            this->push_back(it->data);
            ++it;
        }
    }
    return *this;
}

template <typename T>
void List<T>::clear() {
    Node<T>* current = start_;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    start_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
List<T>::List(const List& other) {
    size_ = other.size_;
    if (other.start_ == nullptr) {
        start_ = nullptr;
    } else {
        Node<T>* current = other.start_;
        start_ = new Node<T>(current->data);
        Node<T>* previous = start_;
        current = current->next;
        while (current != nullptr) {
            previous->next = new Node<T>(current->data);
            previous = previous->next;
            current = current->next;
        }
        previous->next = nullptr;
    }
}

#endif