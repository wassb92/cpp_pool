/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD12-
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_HPP
#define SHAREDPOINTER_HPP

#include <iostream>

template <class Type>
class SharedPointer {
public:
    SharedPointer()
    {
        ++count;
        sharedPtr = nullptr;
    }
    SharedPointer(Type *ptr)
    {
        ++count;
        sharedPtr = ptr;
    }
    SharedPointer(const SharedPointer *ptr)
    {
        ++count;
        sharedPtr = ptr;
    };
    virtual ~SharedPointer()
    {
        --count;
        this->reset();
    }
    void reset()
    {
        if (count == 0) {
            delete sharedPtr;
        }
        sharedPtr = nullptr;
    }
    Type *get()
    {
        return sharedPtr;
    }
    SharedPointer &operator=(Type *ptr)
    {
        sharedPtr = ptr;
        return *this;
    }
    Type *operator->()
    {
        return sharedPtr;
    }

protected:
private:
    Type *sharedPtr;
    size_t count { 0 };
};

#endif /* !SHAREDPOINTER_HPP */
