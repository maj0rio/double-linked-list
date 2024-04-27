/**
 * @file list_unittest.cpp
 * @author maj0rio
 * @brief testing class list
 * @version 0.1
 * @date 2024-04-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdexcept>

#include "include/acutest.hpp"
#include "list.hpp"

void test_list_push_back() {
    List<int> l;
    l.push_back(12);
    l.push_back(13);
    TEST_CHECK(l.size() == 2);
    l.push_back(1);
    l.push_back(0);
    TEST_CHECK(l.size() == 4);
}

void test_list_push_front() {
    List<int> l;
    l.push_front(10);
    l.push_front(20);
    TEST_CHECK(l.size() == 2);
    l.push_front(1);
    l.push_front(0);
    TEST_CHECK(l.size() == 4);
}

void test_list_pop_back() {
    List<int> l;
    l.push_back(12);
    l.push_back(13);
    l.pop_back();
    TEST_CHECK(l.size() == 1);
    l.pop_back();
    TEST_CHECK(l.size() == 0);
    TEST_EXCEPTION(l.pop_back(), std::runtime_error);
}

void test_list_pop_front() {
    List<int> l;
    l.push_back(12);
    l.push_back(13);
    l.pop_front();
    TEST_CHECK(l.size() == 1);
    l.pop_front();
    TEST_EXCEPTION(l.pop_front(), std::runtime_error);
}

void test_list_copy_constructor() {
    List<int> l;
    l.push_back(12);
    l.push_back(13);
    List<int> a(l);
    TEST_CHECK(a.size() == 2);
}

TEST_LIST = {
    { "test_list_push_back", test_list_push_back },
    { "test_list_push_front", test_list_push_front },
    { "test_list_pop_back", test_list_pop_back },
    { "test_list_pop_front", test_list_pop_front },
    { "test_list_copy_constructor", test_list_copy_constructor },
    { NULL, NULL }
};
