/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD12-
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP
#define UNIQUEPOINTER_HPP

template <class Type>
class UniquePointer {
public:
    UniquePointer()
    {
        uniqPtr = nullptr;
    }
    UniquePointer(Type *ptr)
    {
        uniqPtr = ptr;
    }
    UniquePointer(const UniquePointer &) = delete;
    ~UniquePointer()
    {
        this->reset();
    }
    void reset()
    {
        if (uniqPtr)
            delete uniqPtr;
        uniqPtr = nullptr;
    }
    Type *get()
    {
        return uniqPtr;
    }
    UniquePointer &operator=(Type *ptr)
    {
        if (uniqPtr)
            reset();
        uniqPtr = ptr;
        return *this;
    }
    Type *operator->()
    {
        return uniqPtr;
    }

protected:
private:
    Type *uniqPtr;
};

#endif /* !UNIQUEPOINTER_HPP */
