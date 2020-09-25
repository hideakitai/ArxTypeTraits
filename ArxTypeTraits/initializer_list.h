#pragma once

#ifndef ARX_TYPE_TRAITS_INITIALIZER_H
#define ARX_TYPE_TRAITS_INITIALIZER_H

namespace std {
    template<class T>
    class initializer_list
    {
    private:
        const T* array;
        size_t len;
        initializer_list(const T* a, size_t l) : array(a), len(l) {}
    public:
        initializer_list() : array(nullptr), len(0) {}
        size_t size() const { return len; }
        const T *begin() const { return array; }
        const T *end() const { return array + len; }
    };
} // namespace std

#endif // ARX_TYPE_TRAITS_INITIALIZER_LIST_H
