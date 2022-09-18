#pragma once

#include "colors.hpp"
#include <iomanip>

#include "../stack.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <stack>
#include <vector>

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
    std::stack<int> std_stack;
    std::stack<int> std_others;
    std::stack<int> std_res;
    for(int i = 1; i < 100; ++i){
        std_others.push(i);
    }

    unsigned int time_std = clock();
    std_stack.empty() ? std_res.push(1): std_res.push(0);
    unsigned int time_std_end = clock() - time_std;
}

