#pragma once

#include "traits.hpp"
#include <iostream>

namespace ft {
    template <class T>
    class vector_iterator {
    private:
        typedef iterator_traits<T> iterator_type;
        T _val;
    public:
        typedef typename iterator_type::difference_type      difference_type;
        typedef typename iterator_type::value_type           value_type;
        typedef typename iterator_type::pointer              pointer;
        typedef typename iterator_type::reference            reference;
        typedef std::random_access_iterator_tag              iterator_category;

        vector_iterator() : _val(T()) {}

        explicit vector_iterator(const T &iter) : _val(iter) {}

        vector_iterator(const vector_iterator &iter) : _val(iter._val) {}

        ~vector_iterator() {}

        template <class Type>
        operator vector_iterator<Type>() const{
            return vector_iterator<Type>(_val);
        }

        template <class Iter>
        vector_iterator& operator=(vector_iterator<Iter> const &other) {
            _val = &(*other);
            return *this;
        }

        reference operator*() const {
            return *(_val);
        }

        pointer operator->() const {
            return &(*_val);
        }

        vector_iterator& operator++() {
            ++_val;
            return *this;
        }

        vector_iterator operator++(int) {
            vector_iterator tmp(*this);
            ++_val;
            return tmp;
        }

        vector_iterator operator+(difference_type n) const {
            return vector_iterator(_val + n);
        }

        vector_iterator operator+=(difference_type n) {
            _val += n;
            return *this;
        }

        vector_iterator& operator--() {
            --_val;
            return *this;
        }

        vector_iterator operator--(int) {
            vector_iterator tmp(*this);
            --_val;
            return tmp;
        }

        vector_iterator operator-(difference_type n) const {
            return vector_iterator(_val - n);
        }

        vector_iterator operator-=(difference_type n) {
            _val -= n;
            return *this;
        }

        reference operator[](difference_type n) {
            return *(*this + n);
        }

        template <class Iterator1, class Iterator2>
        friend bool operator==(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b);

        template <class Iterator1, class Iterator2>
        friend bool operator!=(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b);

        template <class Iterator1, class Iterator2>
        friend bool operator<=(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b);

        template <class Iterator1, class Iterator2>
        friend bool operator>(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b);

        template <class Iterator1, class Iterator2>
        friend bool operator<(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b);

        template <class Iterator1, class Iterator2>
        friend bool operator>=(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b);

        template <class Iterator>
        friend typename vector_iterator<Iterator>::difference_type operator-(const vector_iterator<Iterator>& a, const vector_iterator<Iterator>& b);

        template <class Iterator1, class Iterator2>
        friend typename vector_iterator<Iterator1>::difference_type operator-(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b);
    };
    
    template <class Iterator1, class Iterator2>
    bool operator==(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b) {
        return a._val == b._val;
    }

    template <class Iterator1, class Iterator2>
    bool operator!=(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b) {
        return !(a._val == b._val);
    }

    template <class Iterator1, class Iterator2>
    bool operator<=(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b) {
        return a._val < b._val || a._val == b._val;
    }

    template <class Iterator1, class Iterator2>
    bool operator>(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b) {
        return a._val > b._val;
    }

    template <class Iterator1, class Iterator2>
    bool operator<(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b) {
        return a._val < b._val;
    }

    template <class Iterator1, class Iterator2>
    bool operator>=(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b) {
        return a._val > b._val || a._val == b._val;
    }

    template <class Iterator>
    typename vector_iterator<Iterator>::difference_type operator-(const vector_iterator<Iterator>& a, const vector_iterator<Iterator>& b) {
        return a._val - b._val;
    }

    template <class Iterator1, class Iterator2>
    typename vector_iterator<Iterator1>::difference_type operator-(const vector_iterator<Iterator1>& a, const vector_iterator<Iterator2>& b) {
        return a._val - b._val;
    }

    template <class Iterator>
    vector_iterator<Iterator> operator+(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator>& iter) {
        return vector_iterator<Iterator>(iter + n);
    }

    template <class T>
    class reverse_iterator {
    private:
        typedef iterator_traits<T> iterator_traits;
        T _val;
    public:
        typedef typename iterator_traits::difference_type       difference_type;
        typedef typename iterator_traits::value_type            value_type;
        typedef typename iterator_traits::pointer               pointer;
        typedef typename iterator_traits::reference             reference;
        typedef typename iterator_traits::iterator_category     iterator_category;

        reverse_iterator() : _val(T()) {}

        explicit reverse_iterator(const T &iter) : _val(iter) {}

        reverse_iterator(const reverse_iterator &iter) : _val(iter._val) {}

        ~reverse_iterator() {}

        template <class Type>
        operator reverse_iterator<Type>() {
            return reverse_iterator<Type>(_val);
        }

        template <class Iter>
        reverse_iterator& operator=(reverse_iterator<Iter> const & other) {
            _val = other._val;
            return *this;
        }

        T base() const {
            return _val;
        }

        reference operator*() const {
            T tmp = _val;
            return *(--tmp);
        }

        pointer operator->() const {
            T tmp = _val;
            return *(--tmp);
        }

        reverse_iterator& operator++() {
            --_val;
            return *this;
        }

        reverse_iterator operator++(int) {
            reverse_iterator tmp(*this);

            --_val;
            return tmp;
        }

        reverse_iterator operator+(difference_type n) const {
            return reverse_iterator (_val - n);
        }

        reverse_iterator operator+=(difference_type n) {
            _val -= n;
            return *this;
        }

        reverse_iterator& operator--() {
            ++_val;
            return *this;
        }

        reverse_iterator operator--(int) {
            reverse_iterator tmp(*this);

            ++_val;
            return tmp;
        }

        reverse_iterator operator-(difference_type n) const {
            return (reverse_iterator(_val + n));
        }

        reverse_iterator operator-=(difference_type n) {
            _val += n;
            return *this;
        }

        reference operator[](difference_type n) {
            return _val[-n - 1];
        }
    };

    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) {
        return a.base() == b.base();
    }

    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) {
        return a.base() != b.base();
    }
    
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) {
        return a.base() > b.base();
    }

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) {
        return a.base() >= b.base();
    }

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) {
        return a.base() < b.base();
    }

    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) {
        return a.base() <= b.base();
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
        return rev_it.base() + n;
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& a, const reverse_iterator<Iterator>& b) {
        return a.base() - b.base();
    }
}