#pragma once

#include "traits.hpp"
#include "pair.hpp"

namespace ft{
    template <class Value, class Compare, class Alloc = std::allocator <Value> >
    class Tree{
    public:
        typedef Alloc                               allocator_type;
        typedef typename allocator_type::pointer    node_ptr;
    private:
        allocator_type                              _alloc;
        Compare                                     _compare;
    public:
        node_ptr create_node(Value value){
            node_ptr new_node = _alloc.allocate(1);

            _alloc.construct(new_node, value);
            return new_node;
        }

        void delete_node(node_ptr node){
            if (node){
                _alloc.destroy(node);
                _alloc.deallocate(node, 1);
            }
        }

        void swap_color(node_ptr node){
            bool color = node->isBlack;
            node->isBlack = node->right->isBlack;
            node->right->isBlack = color;
            node->left->isBlack = color;
        }

        node_ptr min_node(node_ptr node) const{
            if (node){
                while(node->left)
                    node = node->left;
            }
            return node;
        }

        node_ptr max_node(node_ptr node) const{
            if (node){
                while(node->right)
                    node = node->right;
            }
            return node;
        }

        node_ptr find_node(node_ptr tmp, Value key) const{
            if (tmp){
                if (_compare(tmp->pair, key))
                    return find_node(tmp->right, key);
                else if (_compare(key, tmp->pair))
                    return find_node(tmp->left, key);
            }
            return tmp;
        }

        node_ptr lower(node_ptr root, Value key) const{
            node_ptr tmp = 0;

            while(root){
                if (_compare(root->pair, key))
                    root = root->right;
                else{
                    if (root->left){
                        tmp = lower(root->left, key);
                        if(tmp)
                            root = tmp;
                        break;
                    }
                    else
                        break;
                }
            }
            return root;
        }

        void clear(node_ptr* root){
            if(*root == 0)
                return;
            if(*root){
                if((*root)->left)
                    clear(&((*root)->left));
                if((*root)->right)
                    clear(&((*root)->right));
                delete_node((*root));
            }
            *root = 0;
        }

        size_t max_size() const{
            return _alloc.max_size();
        }

        void insert_balance(node_ptr* root, node_ptr node){
            node_ptr parent;
            node_ptr grand;
            node_ptr tmp;

            while (node) {
                parent = node->parent;
                grand = 0;
                tmp = parent;
                if (parent) {
                    grand = parent->parent;
                    if (node->isBlack == false) {
                        if (parent->isBlack == true)
                            node = parent;
                        else if (grand) {
                            if (grand->left && grand->left->isBlack == false && grand->right && grand->right->isBlack == false) {
                                swap_color(grand);
                                node = grand;
                            }
                            else if (grand->right == parent) {
                                if (parent->left == node) {
                                    rotate_right(parent, root);
                                    parent = node;
                                }
                                if (parent->right == node)
                                    rotate_left(grand, root);
                                node = parent->parent;
                            }
                            else {
                                if (parent->right == node) {
                                    rotate_left(parent, root);
                                    parent = node;
                                }
                                if (parent->left == node)
                                    rotate_right(grand, root);
                                node = parent->parent;
                            }
                        }
                    }
                    else
                        node = parent;
                }
                else {
                    node->isBlack = true;
                    node = node->parent;
                }
            }
        }

        bool insert(node_ptr* root, node_ptr new_node){
            if (*root == 0) {
                *root = new_node;
                new_node->isBlack = true;
            }
            else {
                node_ptr tmp = *root;
                while (tmp) {
                    if (!_compare(tmp->pair, new_node->pair) && !_compare(new_node->pair, tmp->pair)) {
                        if (tmp != new_node)
                            delete_node(new_node);
                        return false;
                    }
                    else if (_compare(new_node->pair, tmp->pair)) {
                        if (tmp->left)
                            tmp = tmp->left;
                        else {
                            tmp->left = new_node;
                            new_node->parent = tmp;
                            break;
                        }
                    }
                    else {
                        if (tmp->right)
                            tmp = tmp->right;
                        else {
                            tmp->right = new_node;
                            new_node->parent = tmp;
                            break;
                        }
                    }
                }
            }
            insert_balance(root, new_node);
            return true;
        }

        void swap_p(node_ptr remove, node_ptr replace){
            if (remove->parent) {
                if (remove->parent->left == remove)
                    remove->parent->left = replace;
                else
                    remove->parent->right = replace;
            }
            replace->parent = remove->parent;
            if (remove->left) {
                remove->left->parent = replace;
            }
            replace->left = remove->left;
            if (remove->right) {
                remove->right->parent = replace;
            }
            replace->right = remove->right;
            replace->isBlack = remove->isBlack;
        }

        bool arase(node_ptr* root, Value key){
            node_ptr remove = find_node(*root, key);
			
            if (remove) {
                node_ptr replace = 0;
                if (remove->left)
                    replace = erase_left(remove, root);
                else if (remove->right)
                    replace = erase_right(remove, root);
                else
                    erase_not_child(remove, root);
                if (replace)
                    swap_p(remove, replace);
                if (remove == *root) {
                    if (replace)
                        *root = replace;
                    else
                        *root = 0;
                }
                delete_node(remove);
                return true;
            }
            return false;
        }

        node_ptr erase_left(node_ptr node, node_ptr* root){
            node_ptr replace = max_node(node->left);

            if (replace) {
                if (replace == node->left) {
                    node->left = replace->left;
                    if (replace->left)
                        replace->left->parent = node;
                }
                else {
                    replace->parent->right = replace->left;
                    if (replace->left)
                        replace->left->parent = replace->parent;
                }
                if (replace->isBlack == true) {
                    if (replace->left && replace->left->isBlack == false)
                        replace->left->isBlack = true;
                    erase_balance(root, replace->parent);
                }
            }
            return replace;
        }

        node_ptr erase_right(node_ptr node, node_ptr* root){
            node_ptr replace = min_node(node->right);

            if (replace) {
                if (replace == node->right) {
                    node->right = replace->right;
                    if (replace->right)
                        replace->right->parent = node;
                }
                else {
                    replace->parent->left = replace->right;
                    if (replace->right)
                        replace->right->parent = replace->parent;
                }
                if (replace->isBlack == true) {
                    if (replace->right && replace->right->isBlack == false)
                        replace->right->isBlack = true;
                    erase_balance(root, replace->parent);
                }
            }
            return replace;
        }

        node_ptr erase_not_child(node_ptr node, node_ptr* root){
            node_ptr replace = node;

            if (replace && replace->parent) {
                if (replace->parent->right == replace)
                    replace->parent->right = 0;
                else
                    replace->parent->left = 0;
                if (replace->isBlack == true) {
                    if (replace->right && replace->right->isBlack == false)
                        replace->right->isBlack = true;
                    erase_balance(root, replace->parent);
                }
            }
            return replace;
        }

        void erase_balance(node_ptr* root, node_ptr node){
            node_ptr right;
            node_ptr left;
            node_ptr brother;

            while (node != *root && node->isBlack) {
                brother = node->right;
                if (brother) {
                    right = brother->right;
                    left = brother->left;
                    if ((right || left) && (!right || right->isBlack == true) && (!left || left->isBlack == true)) {
                        if (brother->isBlack == true) {
                            brother->isBlack = false;
                            node->isBlack = true;
                            rotate_left(node, root);
                        }
                        else
                            node = node->parent;
                    }
                    else if (right && brother->isBlack == true) {
                        if (left && left->isBlack == false && right->isBlack == true) {
                            rotate_right(brother, root);
                            right = brother;
                            brother = left;
                        }
                        if (right->isBlack == false && (!left || left->isBlack == true || !node->left))
                            rotate_left(node, root);
                        else
                            node = node->parent;
                    }
                    else if (brother->isBlack == true && node->isBlack == false) {
                        node->isBlack = true;
                        brother->isBlack = false;
                        node = node->parent;
                    }
                    else
                        node = node->parent;
                }
                else
                    break;
            }
        }

        void rotate_left(node_ptr node, node_ptr* root){
            node_ptr right = node->right;
            right->parent = node->parent;

            if (right->parent) {
                if (right->parent->right == node)
                    right->parent->right = right;
                else
                    right->parent->left = right;
            }
            node->parent = right;
            node->right = right->left;
            if (node->right) {
                if (node->right->parent == right)
                    node->right->parent = node;
                else
                    node->right->parent = node;
            }
            right->left = node;
            bool color = node->isBlack;
            node->isBlack = right->isBlack;
            right->isBlack = color;
            if (!right->parent)
                *root = right;
        }

        void rotate_right(node_ptr node, node_ptr* root){
            node_ptr left = node->left;
            left->parent = node->parent;
			
            if (left->parent) {
                if (left->parent->left == node)
                    left->parent->left = left;
                else
                    left->parent->right = left;
            }
            node->parent = left;
            node->left = left->right;
            if (node->left) {
                if (node->left->parent == left)
                    node->left->parent = node;
                else
                    node->left->parent = node;
            }
            left->right = node;
            node->isBlack = false;
            left->isBlack = true;
            if (!left->parent)
                *root = left;
        }

    };
}