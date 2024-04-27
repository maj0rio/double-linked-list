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

  #include "list_node.hpp"


  template<typename T> 
  class List {
    public:
      List() : size_(0), start_(nullptr), tail_(nullptr) {};
      List(const List& other);
      ~List();

      List& operator=(const List &rhs);

      void push_back(const T &x);
      void push_front(const T &x);
      void pop_back();
      void pop_front();

      size_t size() const noexcept; 

      class Iterator;

      Iterator begin() const;
      Iterator end() const;

      class Iterator {
        public:
        explicit Iterator(Node<T>* node, const List<T>* list) : m_pNode(node), m_List(list) {}
          Iterator(const Iterator& other);
          Iterator& operator=(const Iterator& rhs);
          ~Iterator();

          Iterator& operator++();
          Iterator& operator--();

          Node<T>* operator->() const;
          T& operator*() const;

          bool operator==(const Iterator&) const;
          bool operator!=(const Iterator&) const;

        private:
          Node<T>* m_pNode;
          const List<T>* m_List;
          
      };

      // void splice(Iterator it, List &&other);

      void clear();
    private:
      size_t size_;
      Node<T>* start_;
      Node<T>* tail_;
  };

template class List<int>;

#endif