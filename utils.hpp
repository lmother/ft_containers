#pragma once

#include "traits.hpp"

namespace ft {
    template <class T>
    struct switch_const{
        typedef T type;
    };

    template <class T>
	struct switch_const<const T> {
		typedef T type;
	};

    template <class Arg1, class Arg2, class Result> 
    struct binary_function {
        typedef Arg1    first_argument_type;
        typedef Arg2    second_argument_type;
        typedef Result  result_type;
    };

    template <class T> 
    struct less : binary_function < T, T, bool> {
        bool operator() (const T& x, const T& y) const {
            return x < y;
        }
    };

    template <class T, bool val>
    struct integral_constant {
        static const bool value  = val;
        typedef T                   value_type;
        typedef integral_constant   type;

        operator value_type() const {
            return value;
        }
    };

    template <class T>
    struct is_integral : public ft::integral_constant<T, false> {};

    template <>
    struct is_integral<bool> : public ft::integral_constant<bool, true> {};

    template <>
    struct is_integral<char> : public ft::integral_constant<char , true> {};

    template <>
    struct is_integral<char16_t> : public ft::integral_constant<char16_t, true> {};

    template <>
    struct is_integral<char32_t> : public ft::integral_constant<char32_t, true> {};

    template <>
    struct is_integral<wchar_t> : public ft::integral_constant<wchar_t, true> {};

    template <>
    struct is_integral<signed char> : public ft::integral_constant<signed char, true> {};

    template <>
    struct is_integral<short int> : public ft::integral_constant<short int, true> {};

    template <>
    struct is_integral<int> : public ft::integral_constant<int, true> {};

    template <>
    struct is_integral<long int> : public ft::integral_constant<long int, true> {};

    template <>
    struct is_integral<long long int> : public ft::integral_constant<long long int, true> {};

    template <>
    struct is_integral<unsigned char> : public ft::integral_constant<unsigned char, true> {};

    template <>
    struct is_integral<unsigned short int> : public ft::integral_constant<unsigned short int, true> {};

    template <>
    struct is_integral<unsigned int> : public ft::integral_constant<unsigned int, true> {};

    template <>
    struct is_integral<unsigned long int> : public ft::integral_constant<unsigned long int, true> {};

    template <>
    struct is_integral<unsigned long long int> : public ft::integral_constant<unsigned long long int, true> {};


    template <bool Cond, class T = void> 
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
        while (first1 != last1) {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
        while (first1 != last1) {
            if (!pred(*first1, *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
        while (first1 != last1) {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1; ++first2;
        }
        return first2 != last2;
    }

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
        while (first1 != last1) {
            if (comp(*first1, *first2))
                return true;
            else if (comp(*first2, *first1))
                return false;
            ++first1; ++first2;
        }
        return first2 != last2;
    }

    template <class Iterator1, class Iterator2>
    size_t distance(Iterator1 begin, Iterator2  end) {
        size_t dist = 0;

        for(; begin != end; ++begin)
            dist++;
        return dist;
    }

    template <typename U>
    void swap_obj(U& a, U& b) {
        U tmp = a;
        a = b;
        b = tmp;
    }
}