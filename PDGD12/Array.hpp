/*
** EPITECH PROJECT, 2022
** c++pool B-PDG-300-PAR-3-1-PDGD12-
** File description:
** Array
*/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <vector>
#include <functional>

template <typename Type, std::size_t Size>
class Array {
public:
    Array()
        : vec(m_array, m_array + Size)
    {
    }
    ~Array()
    {
        if (m_array)
            delete[] m_array;
    }
    Type &operator[](std::size_t const &index) const
    {
        if (index >= Size)
            throw std::out_of_range("Out of range");

        return m_array[index];
    }

    std::size_t size() const
    {
        return Size;
    }
    void forEach(const std::function<void(const Type &)> &task) const
    {
        if (!task)
            return;
        for (std::size_t i = 0; i < Size; ++i)
            task(m_array[i]);
    }
    template <typename U>
    Array<U, Size> convert(const std::function<U(const Type &)> &converter) const
    {
        Array<U, Size> result;

        if (!converter)
            return result;

        for (std::size_t i = 0; i < Size; ++i)
            result[i] = converter(m_array[i]);
        return result;
    }

protected:
private:
    Type *m_array = new Type[Size];
    const std::vector<Type> vec;
};

template <class Type, std::size_t Size>
std::ostream &operator<<(std::ostream &stream, const Array<Type, Size> &array)
{
    stream << "[";
    for (std::size_t i = 0; i < Size; ++i) {
        stream << array[i];
        if (i + 1 != Size)
            stream << ", ";
    }
    stream
        << "]";
    return stream;
}

#endif /* !ARRAY_HPP */
