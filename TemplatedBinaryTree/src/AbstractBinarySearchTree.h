//
//  AbstractBinarySearchTree.h
//
//  Created by Martin Kysel on 07/12/2015.
//  Copyright © 2015 NuoDB. All rights reserved.
//

#ifndef AbstractBinarySearchTree_h
#define AbstractBinarySearchTree_h

template<class T>
class AbstractBinarySearchTree
{
public:
    virtual bool isEmpty() const = 0;
    virtual void insert(T) = 0;
    virtual bool search(T) = 0;
    virtual int size() = 0;
};


#endif /* AbstractBinarySearchTree_h */
