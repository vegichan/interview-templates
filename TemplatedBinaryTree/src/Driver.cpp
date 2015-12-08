// Driver.cpp

/*
 * Copyright 2015 NuoDB
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 *
*/

/*
 *  This file tests your functionality against a defined set of unit tests. 
 *  Consider these tests to be a clarification of the problem, should any 
 *  inconsistencies occur. You are supposed to implement the class that 
 *  inherits from AbstractBinarySearchTree and can be found in BinarySearchTreeImpl.h.
 *  AbstractBinarySearchTree is a abstract class and this file will not link 
 *  without it's implementation.
 *
*/

#include <cstdio>
#include <cstdlib>
#include <memory>

#include <set>
#include <climits>

#include "AbstractBinarySearchTree.h" // follow this interface
#include "BinarySearchTreeImpl.h" // file provided by you

#ifndef __FUNCTION_NAME__
    # ifdef WIN32  //WINDOWS
        #  define __FUNCTION_NAME__   __FUNCTION__
    # else         //*NIX
        #  define __FUNCTION_NAME__   __func__
    # endif
#endif

inline void call_assert(bool expr, const char* file_name, int line_no, const char* content, 
        const char* func_name)
{
    if (!expr) {
        printf("%04d:%-40s FAILED [ %s ]\n", line_no, func_name, content);
    } else {
        printf("%04d:%-40s OK\n", line_no, func_name);
    }
}

#define assert(expr) call_assert((expr), __FILE__, __LINE__, __STRING(expr), __FUNCTION_NAME__)

const int FIRST_ELEMENT = 1;
const int SECOND_ELEMENT = 2;
const int THIRD_ELEMENT = 3;
const std::string STR_ELEMENT("abc");

void testConstructor()
{
    std::unique_ptr<AbstractBinarySearchTree<int> > b(new BinarySearchTree<int>());
    assert(b->isEmpty());
    assert(b->size() == 0);
}

void testSingleInsertion()
{
    std::unique_ptr<AbstractBinarySearchTree<int> > b(new BinarySearchTree<int>());
    b->insert(FIRST_ELEMENT);
    assert(!b->isEmpty());
    assert(b->search(FIRST_ELEMENT));
    assert(b->size() == 1);
}

void testMultipleInsertions()
{
    std::unique_ptr<AbstractBinarySearchTree<int> > b(new BinarySearchTree<int>());
    b->insert(FIRST_ELEMENT);
    b->insert(SECOND_ELEMENT);
    b->insert(THIRD_ELEMENT);
    assert(!b->isEmpty());
    assert(b->size() == 3);
}

void testDuplicates()
{
    std::unique_ptr<AbstractBinarySearchTree<int> > b(new BinarySearchTree<int>());
    b->insert(FIRST_ELEMENT);
    b->insert(FIRST_ELEMENT);
    assert(!b->isEmpty());
    assert(b->size() == 1);
}

void testFailingSearch()
{
    std::unique_ptr<AbstractBinarySearchTree<int> > b(new BinarySearchTree<int>());
    assert(b->isEmpty());
    assert(!b->search(FIRST_ELEMENT));
}

void testFailingSearch2()
{
    std::unique_ptr<AbstractBinarySearchTree<int> > b(new BinarySearchTree<int>());
    b->insert(SECOND_ELEMENT);
    assert(!b->search(FIRST_ELEMENT));
}

void testRandomInserts()
{
    std::unique_ptr<AbstractBinarySearchTree<int> > b(new BinarySearchTree<int>());

    std::set<int> verifier;

    const int min = 1;
    const int max = INT_MAX;

    for (int i = 0; i < 10000; i++) {
        int randNum = rand()%(max-min + 1) + min;

        b->insert(randNum);
        verifier.insert(randNum);
    }

    assert(b->size() == verifier.size());
}

void testStringTemplate()
{
    std::unique_ptr<AbstractBinarySearchTree<std::string> > b(new BinarySearchTree<std::string>());

    b->insert(STR_ELEMENT);
    assert(!b->isEmpty());
    assert(b->search(STR_ELEMENT));
}

int main()
{

    printf("Executing custom test suite for BinarySearchTree\n");

    testConstructor();
    testSingleInsertion();
    testMultipleInsertions();
    testDuplicates();
    testFailingSearch();
    testFailingSearch2();

    testRandomInserts();

    testStringTemplate();
}
