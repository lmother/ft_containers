#pragma once

#include "colors.hpp"
#include <iomanip>

#include "../stack.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <stack>
#include <stack>

#include <ctime>

template <class Stack1, class Stack2>
void compare_stacks(Stack1 stl_s1, Stack2 s2, std::string massege, unsigned int std_time, unsigned int ft_time){
    if (stl_s1.size() != s2.size()){
        std::cout << std::left << std::setfill('-') << std::setw(30) << massege << std::setw(5)<< FORERED <<  "KO \n" << CL;
        return;
    }
    else{
        for(size_t i = 0; i < stl_s1.size(); ++i)
            if(stl_s1.top() != s2.top()){
                std::cout << std::setfill('-') << std::left << std::setw(30) << massege << std::setw(5)<< FORERED <<  "KO \n" << CL;
                return;
            }
    }
    std::cout << std::left << std::setfill('-') 
                << std::setw(30) << massege << std::setw(5)<< FOREGRN <<  "OK | " << CL;
    print_time(std_time, ft_time);
}

void test_stack_constructor(){      
    std::cout << BACKBLU << std::left << std::setfill(' ') << std::setw(74) 
            << "START TEST constructor()..." << CL << "\n\n";
    std::vector<int> std_vector (220000,200);
    ft::vector<int> ft_vector (220000,200);                

    unsigned int time_std = clock();
    std::stack<int,std::vector<int> > std_stack (std_vector);
    unsigned int time_std_end = clock() - time_std;

    unsigned int time_ft = clock();
    ft::stack<int,ft::vector<int> > ft_stack (ft_vector);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_stack, ft_stack, "test1", time_std_end, time_ft_end);
}

void test_stack_empty(){
    std::cout << BACKBLU << std::left << std::setfill(' ') << std::setw(74) 
            << "START TEST empty()..." << CL << "\n\n";
    std::stack<int> std_stack;
    std::stack<int> std_others;
    std::stack<int> std_res;
    ft::stack<int> ft_stack;
    ft::stack<int> ft_others;
    ft::stack<int> ft_res;

    for(int i = 1; i < 100; ++i)
        std_others.push(i);
    for(int i = 1; i < 100; ++i)
        ft_others.push(i);

    unsigned int time_std = clock();
    std_stack.empty() ? std_res.push(1): std_res.push(0);
    unsigned int time_std_end = clock() - time_std;
    unsigned int time_ft = clock();
    ft_stack.empty() ? ft_res.push(1): ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test1", time_std_end, time_ft_end);
}

void test_stack_size(){
    std::cout << BACKBLU << std::left << std::setfill(' ') << std::setw(74) 
            << "START TEST size()..." << CL << "\n\n";
    std::stack <int> std_stack;
    ft::stack<int> ft_stack;
    std::stack<int> std_res;
    ft::stack<int> ft_res;

     for(int i = 1; i < 100; ++i)
        std_stack.push(i);
    for(int i = 1; i < 100; ++i)
        ft_stack.push(i);
    unsigned int time_std = clock();
    std_res.push(std_stack.size());
    unsigned int time_std_end = clock() - time_std;
    unsigned int time_ft = clock();
    ft_res.push(ft_stack.size());
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test1", time_std_end, time_ft_end);
    for(int i = 1; i < 13; ++i)
        std_stack.pop();
    for(int i = 1; i < 13; ++i)
        ft_stack.pop();
    time_std = clock();
    std_res.push(std_stack.size());
    time_std_end = clock() - time_std;
    time_ft = clock();
    ft_res.push(ft_stack.size());
    time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test2", time_std_end, time_ft_end);
}

void test_stack_top(){
    std::cout << BACKBLU << std::left << std::setfill(' ') << std::setw(74) 
            << "START TEST top()..." << CL << "\n\n";
    std::stack <int> std_stack;
    ft::stack<int> ft_stack;
    std::stack<int> std_res;
    ft::stack<int> ft_res;
    unsigned int time_std = 0;
    unsigned int time_std_end = 0;
    unsigned int time_ft = 0;
    unsigned int time_ft_end = 0;

    for(int i = 1; i < 10000; ++i)
        std_stack.push(i);
    for(int i = 1; i < 10000; ++i)
        ft_stack.push(i);

    while(!std_stack.empty()){
        time_std = clock();
        std_res.push(std_stack.top());
        time_std_end += clock() - time_std;
        std_stack.pop();
    }
    while(!ft_stack.empty()){
        time_ft = clock();
        ft_res.push(ft_stack.top());
        time_ft_end += clock() - time_ft;
        ft_stack.pop();
    }
    compare_stacks(std_res, ft_res, "test1", time_std_end, time_ft_end);
}

void test_stack_push(){
     std::cout << BACKBLU << std::left << std::setfill(' ') << std::setw(74) 
            << "START TEST push()..." << CL << "\n\n";
    std::stack<int> std_stack;
    ft::stack<int> ft_stack;
    unsigned int time_std = clock();
    for(int i = 1; i < 100000; ++i)
        std_stack.push(i);
    unsigned int time_std_end = clock() - time_std;
    unsigned int time_ft = clock();
    for(int i = 1; i < 100000; ++i)
        ft_stack.push(i);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_stack, ft_stack, "test1", time_std_end, time_ft_end);
}

void test_stack_operator1(){
    std::cout << BACKBLU << std::left << std::setfill(' ') << std::setw(74) 
            << "START TEST operator==()..." << CL << "\n\n";

    {
        std::stack<int> std_stack;
        for(int i = 1; i < 100000; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack == std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

        ft::stack<int> ft_stack;
        for(int i = 1; i < 100000; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack == ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test1", time_std_end, time_ft_end);
    }
    { std::stack<int> std_stack;
        for(int i = 1; i < 999; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack == std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

    ft::stack<int> ft_stack;
        for(int i = 1; i < 999; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack == ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test2", time_std_end, time_ft_end);
    }
}

void test_stack_operator2(){
    std::cout << BACKBLU << std::left << std::setfill(' ') << std::setw(74) 
            << "START TEST operator!=()..." << CL << "\n\n";
    {
        std::stack<int> std_stack;
        for(int i = 1; i < 100000; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack != std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

        ft::stack<int> ft_stack;
        for(int i = 1; i < 100000; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack != ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test1", time_std_end, time_ft_end);
    }
    { std::stack<int> std_stack;
        for(int i = 1; i < 999; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack != std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

    ft::stack<int> ft_stack;
        for(int i = 1; i < 999; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack != ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test2", time_std_end, time_ft_end);
    }
}

void test_stack_operator3(){
    std::cout << BACKBLU << std::left << std::setfill(' ') << std::setw(74) 
            << "START TEST operator<()..." << CL << "\n\n";
    {
        std::stack<int> std_stack;
        for(int i = 1; i < 100000; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack < std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

        ft::stack<int> ft_stack;
        for(int i = 1; i < 100000; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack < ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test1", time_std_end, time_ft_end);
    }
    { std::stack<int> std_stack;
        for(int i = 1; i < 999; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack < std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

    ft::stack<int> ft_stack;
        for(int i = 1; i < 999; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack < ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test2", time_std_end, time_ft_end);
    }
}

void test_stack_operator4(){
    std::cout << BACKBLU << std::left << std::setfill(' ') << std::setw(74) 
            << "START TEST operator<=()..." << CL << "\n\n";
     {
        std::stack<int> std_stack;
        for(int i = 1; i < 100000; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack <= std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

        ft::stack<int> ft_stack;
        for(int i = 1; i < 100000; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack <= ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test1", time_std_end, time_ft_end);
    }
    { std::stack<int> std_stack;
        for(int i = 1; i < 999; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack <= std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

    ft::stack<int> ft_stack;
        for(int i = 1; i < 999; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack <= ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test2", time_std_end, time_ft_end);
    }
}

void test_stack_operator5(){
    std::cout << BACKBLU << std::left << std::setfill(' ') << std::setw(74) 
            << "START TEST operator>()..." << CL << "\n\n";
         {
        std::stack<int> std_stack;
        for(int i = 1; i < 100000; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack > std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

        ft::stack<int> ft_stack;
        for(int i = 1; i < 100000; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack > ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test1", time_std_end, time_ft_end);
    }
    { std::stack<int> std_stack;
        for(int i = 1; i < 999; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack > std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

    ft::stack<int> ft_stack;
        for(int i = 1; i < 999; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack > ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test2", time_std_end, time_ft_end);
    }
}

void test_stack_operator6(){
    std::cout << BACKBLU << std::left << std::setfill(' ') << std::setw(74) 
            << "START TEST operator>=()..." << CL << "\n\n";
             {
        std::stack<int> std_stack;
        for(int i = 1; i < 100000; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack >= std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

        ft::stack<int> ft_stack;
        for(int i = 1; i < 100000; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack >= ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test1", time_std_end, time_ft_end);
    }
    { std::stack<int> std_stack;
        for(int i = 1; i < 999; ++i)
            std_stack.push(i);
        std::stack<int> std_other;
        for(int i = 1; i < 999; ++i)
            std_other.push(i);
        std::stack<int> std_res;

    
    unsigned int time_std = clock();
    std_stack >= std_other?std_res.push(1):std_res.push(0);
    unsigned int time_std_end = clock() - time_std;

    ft::stack<int> ft_stack;
        for(int i = 1; i < 999; ++i)
            ft_stack.push(i);
        ft::stack<int> ft_other;
        for(int i = 1; i < 999; ++i)
            ft_other.push(i);
        ft::stack<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_stack >= ft_other?ft_res.push(1):ft_res.push(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_stacks(std_res, ft_res, "test2", time_std_end, time_ft_end);
    }
}

