/**
 * @file list_iterator.cpp
 * @author maj0rio
 * @brief implementation of double link iterator
 * @version 0.1
 * @date 2024-04-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _LIST_ITERATOR_CPP
#define _LIST_ITERATOR_CPP


#include <stdexcept>

#include "list.hpp"
#include "list_iterator.hpp"
#include "list_node.hpp"


template<typename T>
Iterator<T>::Iterator(Node<T>* node) {
    m_pNode = node;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++() {
    if (m_pNode == nullptr)
        throw std::runtime_error("Iterator does not point to a valid node");
    
    if (m_pNode->next != nullptr)
        m_pNode = m_pNode->next;
    
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator--() {
    if (m_pNode == nullptr)
        throw std::runtime_error("Iterator does not point to a valid node");
    
    if (m_pNode->prev != nullptr)
        m_pNode = m_pNode->prev;
    
    return *this;
}

template<typename T>
Node<T>* Iterator<T>::operator->() const {
    if (m_pNode == nullptr)
        throw std::runtime_error("Iterator can not be nullptr");
    
    return m_pNode;
}

template<typename T>
T& Iterator<T>::operator*() const {
    if (m_pNode == nullptr)
        throw std::runtime_error("Iterator can not be nullptr");
    
    return m_pNode->data;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T> &other) const {
    return other.m_pNode == m_pNode;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T> &other) const {
    return other.m_pNode != m_pNode;
}

#endif