#pragma once

#include "iterator.hpp"
#include "utils.hpp"
#include "pair.hpp"


namespace ft {
    template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator< pair<const Key, T> >>
    class map {
    public:
        typedef Key key_type;
        typedef T   mapped_type;
        typedef ft::pair<const Key, T> value_type;
        typedef Compare key_compare;
        typedef Alloc   allocator_type;
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;

        typedef size_t  size_type;


    };
}