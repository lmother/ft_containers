#pragma once

#include <cstdlib>
#include <algorithm>
#include "traits.hpp"
#include "iterator.hpp"
#include "utils.hpp"

namespace ft{
    template < class T, class Alloc = std::allocator<T> > 
    class vector {
    public:
        typedef T                                                       value_type;
        typedef Alloc                                                   allocator_type;
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;
        typedef ft::vector_iterator<T*>                                 iterator;
        typedef ft::vector_iterator<const T*>                           const_iterator;
        typedef ft::reverse_iterator<iterator>                          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
        typedef typename iterator_traits<iterator>::difference_type     difference_type;
        typedef size_t                                                  size_type;
    private:
        size_type       _size;
        size_type       _capacity;
        allocator_type  _alloc;
        pointer         _pointer;
    public:
        explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), _pointer(0) {}

        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc) {
            _pointer = _alloc.allocate(n);
            for(size_type i  = 0; i < n; i++)
                _alloc.construct(_pointer + i, val);
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) : _size(0), _capacity(0), _alloc(alloc), _pointer(0) {
            insert(begin(), first, last);
        }

        vector(const vector& obj) : _size(0), _capacity(0), _alloc(obj._alloc), _pointer(0) {
            insert(begin(), obj.begin(), obj.end());
        }

        vector& operator=(const vector& obj) {
            if (this != &obj) {
                clear();
                _alloc.deallocate(_pointer, _capacity);
                _capacity = obj.capacity();
                _pointer = _alloc.allocate(_capacity);
                insert(begin(), obj.begin(), obj.end());
            }
            return *this;
        }

        ~vector() {
            clear();
            if (_capacity)
                _alloc.deallocate(_pointer, _capacity);
        }

        iterator begin() {
            return iterator(_pointer);
        }

        const_iterator begin() const {
            return iterator(_pointer);
        }

        iterator end() {
            return iterator(_pointer + _size);
        }
        const_iterator end() const {
            return iterator(_pointer + _size);
        }

        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }
        const_reverse_iterator rbegin() const {
            return const_reverse_iterator(end());
        }

        reverse_iterator rend() {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rend() const {
            return const_reverse_iterator(begin());
        }

        size_type size() const {
            return _size;
        }

        size_type max_size() const {
            return _alloc.max_size();
        }

        size_type capacity() const {
            return _capacity;
        }

        bool empty() const {
            return (_size == 0); 
        }

        void reserve(size_type n) {
            if (n > max_size() || n < 0)
                throw std::logic_error("Error: Incorrect capacity value!");
            else if (n > _capacity) {
                pointer tmp = _alloc.allocate(n);
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(tmp + i, _pointer[i]);
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(_pointer + i);
                _alloc.deallocate(_pointer, _capacity);
                _capacity = n;
                _pointer = tmp;
            }
        }

        void resize(size_type n, value_type val = value_type()) {
            if (n > _size) {
                if (_capacity < n)
                    reserve(_capacity * 2 < n ?  n : _capacity * 2);
                for(size_type i = _size; i < n; i++) {
                    _alloc.construct(_pointer + i, val);
                    _size++;
                }
            }
            else if (n < _size){
                for(size_type i = n; i < _size; i++)
                    _alloc.destroy(_pointer + i);
                _size = n;
            }
        }

        reference operator[](size_type n) {
            return *(_pointer + n);
        }

        const_reference operator[](size_type n) const {
            return *(_pointer + n);
        }

        reference at(size_type n) {
            if (n >= _size || n < 0)
                throw std::out_of_range("Error: Element out of range!");
            return *(_pointer + n);

        }
        const_reference at(size_type n) const {
            if (n >= _size || n < 0)
                throw std::out_of_range("Error: Element out of range!");
            return *(_pointer + n);
        }

        reference front() {
            return *_pointer;
        }
        const_reference front() const {
                return *_pointer;
        }

        reference back() {
            return _pointer[_size - 1];
        }
        const_reference back() const {
            return _pointer[_size - 1];
        }

        void clear() {
            while (_size > 0){
                _alloc.destroy(_pointer + _size - 1);
                _size--;
            }
        }

        allocator_type get_allocator() const {
            return _alloc;
        }

        template <class InputIterator>
        void assign (InputIterator first, InputIterator last) {
            clear();
            insert(begin(), first ,last);
        }

        void assign (size_type n, const value_type& val) {
            clear();
            insert(begin(), n, val);
        }

        iterator insert (iterator position, const value_type& val) {
            size_type current_position = static_cast<size_type>(position - begin());
            
            if (position < begin() || position > end())
                throw std::out_of_range("Error: Iterator bad position!");
            reserve(_size + 1 > _capacity ? _capacity * 2 : 0);
            for (size_type i = 1; i + current_position < _size + 1; i++) {
                _alloc.construct(_pointer + i + current_position, _pointer[current_position + i - 1]);
                _alloc.destroy(_pointer + (i - 1));
            }
            _alloc.construct(_pointer + current_position, val);
            _size++;
            return iterator(begin() + current_position);
        }

        void insert (iterator position, size_type n, const value_type& val) {
            size_type distance = static_cast<size_type>(position - begin());

            if (position > end() || position < begin())
                throw std::logic_error("Error: Iterator bad position!");
            reserve(_size + n);
            for (size_type i = 0; _size - i != distance; ++i) {
                _alloc.construct(_pointer + _size - 1 - i + n, _pointer[_size - i - 1]);
                _alloc.destroy(_pointer + _size - i - 1);
            }
            for (size_type i = 0; i < n; i++) {
                _alloc.construct(_pointer + distance + i, val);
                _size++;
            }
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
            size_type size = static_cast<size_type>(last - first);
            size_type current_position = static_cast<size_type>(position - begin());
            
            if (position < begin() || position > end() || first > last )
                throw std::out_of_range("Error: Iterator bad position!");
            pointer tmp = _alloc.allocate(size);
            try {
                for (size_type i = 0; i < size; i++)
                    _alloc.construct(tmp + i, *first++);
            }
            catch(...) {
				for (size_type i = 0; tmp + i != 0 && i < size; i++) {
                    _alloc.destroy(tmp + i);
				}
                _alloc.deallocate(tmp, size);
                throw std::logic_error("Error: Common error");
            }
            if (_size + size > _capacity * 2)
                reserve(_size + size);
            else if (_size + size > _capacity)
                reserve(_capacity * 2);
            else
                reserve(_size + size);
            for (size_type i = 0; _size - i != current_position; ++i){
                _alloc.construct(_pointer + _size - 1 - i + size, _pointer[_size - i - 1]);
                _alloc.destroy(_pointer + _size - i - 1);
            }
            size_type j = 0;
            for (size_type i = current_position; j < size; i++){
                _alloc.construct(_pointer + i, tmp[j]);
                _alloc.destroy(tmp + j++);
                _size++;
            }
            _alloc.deallocate(tmp, size);
        }

        iterator erase (iterator position) {
            return erase(position, position + 1);
        }

        iterator erase (iterator first, iterator last) {
            size_type size = static_cast<size_type>(last - first);
            size_type pos_arr = static_cast<size_type>(first - begin());

            if (_size == 0)
                return begin();
            for (size_type i = 0; i != size; i++) {
                _alloc.destroy(_pointer + pos_arr + i);
                _size--;
            }
            for(size_type i = 0; i + pos_arr != _size; i++) {
                _alloc.construct(_pointer + pos_arr + i, _pointer[pos_arr + size + i]);
                _alloc.destroy(_pointer + pos_arr + i);
            }
            return begin() + pos_arr;
        }

        void push_back (const value_type& val) {
            if (_size == _capacity)
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            _alloc.construct(_pointer + _size, val);
            _size++;
        }

        void pop_back() {
            if (_size) {
                _size--;
                _alloc.destroy(_pointer + _size);
            }
        }

        void swap (vector& x) {
            if (x == *this)
                return;
            swap_obj(x._alloc, _alloc);
            swap_obj(x._pointer, _pointer);
            swap_obj(x._size, _size);
            swap_obj(x._capacity, _capacity);
        }
    };

    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        if (lhs.size() != rhs.size())
            return false;
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return rhs < lhs;
    }
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        return !(lhs < rhs);
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
        x.swap(y);
    }
};
