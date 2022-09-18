#pragma once

#include "colors.hpp"
#include <iomanip>

#include "../vector.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <deque>
#include <vector>

#include <ctime>

template <class Vector, class Data>
void add_any_data_to_vector(Vector vector, Data data, int size){
    for (int i = 0; i < size; ++i){
        vector.push_back(data);
    }
}

template<class Vector>
void add_data_to_vector(Vector v, int size){
    for (int i = 0; i < size; ++i){
        v.push_back(i);
    }
}

void print_time(unsigned int std_time, unsigned int ft_time){
    std::cout << std::setfill(' ') << std::fixed << std::setprecision(3) << (ft_time <= std_time ? FOREGRN : FORERED) 
                <<  std::setw(10) << "FT_time: " << std::setw(8) << ft_time/1000.0 << CL ;
    std::cout << (ft_time <= std_time ? FORERED : FOREGRN) 
                << std::setw(10) << "| STD_time: " << std::setw(8) << std_time/1000.0 << "|" CL << "\n" ;
}

template <class Vector1, class Vector2>
void compare_vectors(Vector1 stl_v1, Vector2 v2, std::string massege, unsigned int std_time, unsigned int ft_time){
    if (stl_v1.capacity() != v2.capacity() && stl_v1.size() != v2.size()){
        std::cout << std::left << std::setfill('-') << std::setw(30) << massege << std::setw(5)<< FORERED <<  "KO \n" << CL;
        return;
    }
    else{
        for(size_t i = 0; i < stl_v1.size(); ++i)
            if(stl_v1[i] != v2[i]){
                std::cout << std::setfill('-') << std::left << std::setw(30) << massege << std::setw(5)<< FORERED <<  "KO \n" << CL;
                return;
            }
    }
    std::cout << std::left << std::setfill('-') 
                << std::setw(30) << massege << std::setw(5)<< FOREGRN <<  "OK | " << CL;
    print_time(std_time, ft_time);
}

template<class T>
void test_constructor(T data, std::string type){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(40)  << "START TEST CONSTRUCTOR with type: " << std::setw(34) << type << CL << "\n\n";

    std::vector<T>    stl_first;
    ft::vector<T>     my_first;
    compare_vectors(stl_first, my_first, "empty constructor", 0, 0);

    std::vector<T> stl_second (40,data);
    ft::vector<T> my_second (40,data);
    compare_vectors(stl_second, my_second, "with data", 0, 0);

    std::vector<T> stl_third (stl_second.begin(),stl_second.end());
    ft::vector<T> my_third (my_second.begin(),my_second.end());
    compare_vectors(stl_third, my_third, "with iterator", 0, 0);

    std::vector<T> stl_fourth (stl_third);
    ft::vector<T> my_fourth (my_third);
    compare_vectors(stl_fourth, my_fourth, "copy constructor", 0, 0);
}

void test_opertor(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST OPERATOR=..." << CL << "\n\n";

    std::vector<int> std_foo(1234, 1200);
    std::vector<int> std_bar(4321, 1999);

    ft::vector<int> ft_foo(1234, 1200);
    ft::vector<int> ft_bar(4321, 1999);

    unsigned int time_std = clock();
    std_bar = std_foo;
    std_foo.clear();
    unsigned int time_std_end = clock() - time_std;


    unsigned int time_ft = clock();
    ft_bar = ft_foo;
    ft_foo.clear();
    unsigned int time_ft_end = clock() - time_ft;

    compare_vectors(std_foo, ft_foo, "test1", time_std_end, time_ft_end);
    compare_vectors(std_bar, ft_bar, "test2",time_std_end, time_ft_end);
}

void test_operator1(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST OPERATOR[]..." << CL << "\n\n";

    std::vector<int> std_vector (1000000);
    ft::vector<int> ft_vector (1000000);

  std::vector<int>::size_type std_sz = std_vector.size();
  ft::vector<int>::size_type ft_sz = ft_vector.size();

    unsigned int time_std;
    unsigned int time_std_end;
  for (unsigned i=0; i<std_sz; i++) std_vector[i]=i;
  for (unsigned i=0; i<std_sz/2; i++)
  {
    int temp;
    time_std = clock();
    temp = std_vector[std_sz-1-i];
    std_vector[std_sz-1-i]=std_vector[i];
    std_vector[i]=temp;
    time_std_end = clock() - time_std;
  }
  

   unsigned int time_ft;
   unsigned int time_ft_end;
  for (unsigned i=0; i<ft_sz; i++) ft_vector[i]=i;
  for (unsigned i=0; i<ft_sz/2; i++)
  {
    int temp;
    time_ft = clock();
    temp = ft_vector[ft_sz-1-i];
    ft_vector[ft_sz-1-i]=ft_vector[i];
    ft_vector[i]=temp;
    time_ft_end = clock() - time_ft;
  }
  compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
}

void test_begin(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST begin()..." << CL << "\n\n";
    
    std::vector<int> std_vector;
    std::vector<int> std_res;
    for(int i = 0; i < 20; ++i)
        std_vector.push_back(i * 1000000);

    unsigned int time_std = clock();
    std_res.push_back(*std_vector.begin());
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector;
    ft::vector<int> ft_res;
    for(int i = 0; i < 20; ++i)
        ft_vector.push_back(i * 1000000);

    unsigned int time_ft = clock();
    ft_res.push_back(*ft_vector.begin());
    unsigned int time_ft_end = clock() - time_ft;

    compare_vectors(std_res, ft_res, "test1", time_std_end, time_ft_end);
}

void test_end(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST end()..." << CL << "\n\n";
    
    std::vector<int> std_vector;
    std::vector<int> std_vector1;
    std::vector<int> std_vector2;
    std::vector<int> std_res;
    std::vector<int> std_res1;
    std::vector<int> std_res2;

    ft::vector<int> ft_vector;
    ft::vector<int> ft_vector1;
    ft::vector<int> ft_vector2;
    ft::vector<int> ft_res;
    ft::vector<int> ft_res1;
    ft::vector<int> ft_res2;


    add_data_to_vector(std_vector, 20000);
    add_data_to_vector(std_vector1, 2);
    add_data_to_vector(std_vector2, 1);

    add_data_to_vector(ft_vector, 20000);
    add_data_to_vector(ft_vector1, 2);
    add_data_to_vector(ft_vector2, 1);
    
    {
    unsigned int time_std1 = clock();
    std::vector<int>::iterator it = std_vector.begin();
    for(; it !=std_vector.end(); ++it) std_res.push_back(*it);
    unsigned int time_std_end1 = clock() - time_std1;
    unsigned int time_ft1 = clock();
    ft::vector<int>::iterator it1 = ft_vector.begin();
    for(; it1 !=ft_vector.end(); ++it1) ft_res.push_back(*it1);
    unsigned int time_ft_end1 = clock() - time_ft1;
    compare_vectors(std_res, ft_res, "test1", time_std_end1, time_ft_end1);
    }

    {
    unsigned int time_std2 = clock();
    std::vector<int>::iterator it2 = std_vector1.begin();
    for(; it2 !=std_vector1.end(); ++it2) std_res1.push_back(*it2);
    unsigned int time_std_end2 = clock() - time_std2;
    unsigned int time_ft2 = clock();
    ft::vector<int>::iterator it3 = ft_vector1.begin();
    for(; it3 !=ft_vector1.end(); ++it3) ft_res1.push_back(*it3);
    unsigned int time_ft_end2 = clock() - time_ft2;
    compare_vectors(std_res1, ft_res1, "test2", time_std_end2, time_ft_end2);
    }

    {
    unsigned int time_std2 = clock();
    std::vector<int>::iterator it2 = std_vector2.begin();
    for(; it2 !=std_vector2.end(); ++it2) std_res1.push_back(*it2);
    unsigned int time_std_end2 = clock() - time_std2;
    unsigned int time_ft2 = clock();
    ft::vector<int>::iterator it3 = ft_vector2.begin();
    for(; it3 !=ft_vector2.end(); ++it3) ft_res1.push_back(*it3);
    unsigned int time_ft_end2 = clock() - time_ft2;
    compare_vectors(std_res2, ft_res2, "test3", time_std_end2, time_ft_end2);
    }
}

void test_rbegin(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST rbegin()..." << CL << "\n\n";
    
    std::vector<int> std_vector;
    std::vector<int> std_vector1;
    std::vector<int> std_vector2;
    std::vector<int> std_res;
    std::vector<int> std_res1;
    std::vector<int> std_res2;

    ft::vector<int> ft_vector;
    ft::vector<int> ft_vector1;
    ft::vector<int> ft_vector2;
    ft::vector<int> ft_res;
    ft::vector<int> ft_res1;
    ft::vector<int> ft_res2;


    add_data_to_vector(std_vector, 20000);
    add_data_to_vector(std_vector1, 2);
    add_data_to_vector(std_vector2, 1);

    add_data_to_vector(ft_vector, 20000);
    add_data_to_vector(ft_vector1, 2);
    add_data_to_vector(ft_vector2, 1);
    
    {
    unsigned int time_std1 = clock();
    std::vector<int>::reverse_iterator it = std_vector.rbegin();
    for(; it !=std_vector.rend(); ++it) std_res.push_back(*it);
    unsigned int time_std_end1 = clock() - time_std1;
    unsigned int time_ft1 = clock();
    ft::vector<int>::reverse_iterator it1 = ft_vector.rbegin();
    for(; it1 !=ft_vector.rend(); ++it1) ft_res.push_back(*it1);
    unsigned int time_ft_end1 = clock() - time_ft1;
    compare_vectors(std_res, ft_res, "test1", time_std_end1, time_ft_end1);
    }

    {
    unsigned int time_std2 = clock();
    std::vector<int>::reverse_iterator it2 = std_vector1.rbegin();
    for(; it2 !=std_vector1.rend(); ++it2) std_res1.push_back(*it2);
    unsigned int time_std_end2 = clock() - time_std2;
    unsigned int time_ft2 = clock();
    ft::vector<int>::reverse_iterator it3 = ft_vector1.rbegin();
    for(; it3 !=ft_vector1.rend(); ++it3) ft_res1.push_back(*it3);
    unsigned int time_ft_end2 = clock() - time_ft2;
    compare_vectors(std_res1, ft_res1, "test2", time_std_end2, time_ft_end2);
    }

    {
    unsigned int time_std2 = clock();
    std::vector<int>::reverse_iterator it2 = std_vector2.rbegin();
    for(; it2 !=std_vector2.rend(); ++it2) std_res1.push_back(*it2);
    unsigned int time_std_end2 = clock() - time_std2;
    unsigned int time_ft2 = clock();
    ft::vector<int>::reverse_iterator it3 = ft_vector2.rbegin();
    for(; it3 !=ft_vector2.rend(); ++it3) ft_res1.push_back(*it3);
    unsigned int time_ft_end2 = clock() - time_ft2;
    compare_vectors(std_res2, ft_res2, "test3", time_std_end2, time_ft_end2);
    }
}

void test_rend(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST rend()..." << CL << "\n\n";
    
    std::vector<int> std_vector;
    std::vector<int> std_vector1;
    std::vector<int> std_vector2;
    std::vector<int> std_res;
    std::vector<int> std_res1;
    std::vector<int> std_res2;

    ft::vector<int> ft_vector;
    ft::vector<int> ft_vector1;
    ft::vector<int> ft_vector2;
    ft::vector<int> ft_res;
    ft::vector<int> ft_res1;
    ft::vector<int> ft_res2;


    add_data_to_vector(std_vector, 20000);
    add_data_to_vector(std_vector1, 2);
    add_data_to_vector(std_vector2, 1);

    add_data_to_vector(ft_vector, 20000);
    add_data_to_vector(ft_vector1, 2);
    add_data_to_vector(ft_vector2, 1);
    
    {
    unsigned int time_std1 = clock();
    std::vector<int>::reverse_iterator it = std_vector.rbegin();
    for(; it !=std_vector.rend(); ++it) std_res.push_back(*it);
    unsigned int time_std_end1 = clock() - time_std1;
    unsigned int time_ft1 = clock();
    ft::vector<int>::reverse_iterator it1 = ft_vector.rbegin();
    for(; it1 !=ft_vector.rend(); ++it1) ft_res.push_back(*it1);
    unsigned int time_ft_end1 = clock() - time_ft1;
    compare_vectors(std_res, ft_res, "test1", time_std_end1, time_ft_end1);
    }

    {
    unsigned int time_std2 = clock();
    std::vector<int>::reverse_iterator it2 = std_vector1.rbegin();
    for(; it2 !=std_vector1.rend(); ++it2) std_res1.push_back(*it2);
    unsigned int time_std_end2 = clock() - time_std2;
    unsigned int time_ft2 = clock();
    ft::vector<int>::reverse_iterator it3 = ft_vector1.rbegin();
    for(; it3 !=ft_vector1.rend(); ++it3) ft_res1.push_back(*it3);
    unsigned int time_ft_end2 = clock() - time_ft2;
    compare_vectors(std_res1, ft_res1, "test2", time_std_end2, time_ft_end2);
    }

    {
    unsigned int time_std2 = clock();
    std::vector<int>::reverse_iterator it2 = std_vector2.rbegin();
    for(; it2 !=std_vector2.rend(); ++it2) std_res1.push_back(*it2);
    unsigned int time_std_end2 = clock() - time_std2;
    unsigned int time_ft2 = clock();
    ft::vector<int>::reverse_iterator it3 = ft_vector2.rbegin();
    for(; it3 !=ft_vector2.rend(); ++it3) ft_res1.push_back(*it3);
    unsigned int time_ft_end2 = clock() - time_ft2;
    compare_vectors(std_res2, ft_res2, "test3", time_std_end2, time_ft_end2);
    }
}

void test_size(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST size()..." << CL << "\n\n";
    unsigned int time_std = clock();
    std::vector<int> std_vector;
    unsigned int time_std_end = clock() - time_std;
    unsigned int time_ft = clock();
    ft::vector<int> ft_vector;
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);

    for (int i=0; i<10; i++) std_vector.push_back(i);
    for (int i=0; i<10; i++) ft_vector.push_back(i);
    compare_vectors(std_vector, ft_vector, "test2", 0, 0);

    std_vector.insert (std_vector.end(),10,100);
    ft_vector.insert (ft_vector.end(),10,100);
    compare_vectors(std_vector, ft_vector, "test3", 0, 0);

    std_vector.pop_back();
    ft_vector.pop_back();
    compare_vectors(std_vector, ft_vector, "test4", 0, 0);
}

void test_resize(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST resize()..." << CL << "\n\n";
    std::vector<int> std_vector;
    for (int i=1;i<10000;i++) std_vector.push_back(i);
    ft::vector<int> ft_vector;
    for (int i=1;i<10000;i++) ft_vector.push_back(i);

    {
    unsigned int time_std = clock();
    std_vector.resize(5000);
    unsigned int time_std_end = clock() - time_std;
    unsigned int time_ft = clock();
    ft_vector.resize(5000);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
    }

    {
    unsigned int time_std = clock();
    std_vector.resize(800, 100);
    unsigned int time_std_end = clock() - time_std;
    unsigned int time_ft = clock();
    ft_vector.resize(800, 100);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test2", time_std_end, time_ft_end);
    }

    {
    unsigned int time_std = clock();
    std_vector.resize(12);
    unsigned int time_std_end = clock() - time_std;
    unsigned int time_ft = clock();
    ft_vector.resize(12);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test3", time_std_end, time_ft_end);
    }
}

void test_empty(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST empty()..." << CL << "\n\n";
    std::vector<int> std_vector;
    ft::vector<int> ft_vector;
    compare_vectors(std_vector, ft_vector, "test1", 0, 0);


    for (int i=1;i<=10;i++) std_vector.push_back(i);
    for (int i=1;i<=10;i++) ft_vector.push_back(i);

    while (!std_vector.empty())
        std_vector.pop_back();
    while (!ft_vector.empty())
        ft_vector.pop_back();
    compare_vectors(std_vector, ft_vector, "test2", 0, 0);
}

void test_reserve(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST reserve()..." << CL << "\n\n";
    std::vector<int> std_vector;
    ft::vector<int> ft_vector;

    unsigned int time_std = clock();
    std_vector.reserve(10000000);
    unsigned int time_std_end = clock() - time_std;
    unsigned int time_ft = clock();
    ft_vector.reserve(10000000);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);

    time_std = clock();
    std_vector.reserve(1000);
    time_std_end = clock() - time_std;
    time_ft = clock();
    ft_vector.reserve(1000);
    time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test2", time_std_end, time_ft_end);

    time_std = clock();
    std_vector.reserve(10000000);
    time_std_end = clock() - time_std;
    time_ft = clock();
    ft_vector.reserve(10000000);
    time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test3", time_std_end, time_ft_end);
}

void test_at(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST at()..." << CL << "\n\n";
    std::vector<int> std_vector (10);
    ft::vector<int> ft_vector (10);

    for (unsigned i=0; i<std_vector.size(); i++)
    std_vector.at(i)=i;

    unsigned int time_std = clock();
    std_vector.at(5);
    unsigned int time_std_end = clock() - time_std;


    for (unsigned i=0; i<ft_vector.size(); i++)
        ft_vector.at(i)=i;

    unsigned int time_ft = clock();
    ft_vector.at(5);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
}

void test_front(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST front()..." << CL << "\n\n";
    std::vector<int> std_vector;
    ft::vector<int> ft_vector;

    std_vector.push_back(78);
    std_vector.push_back(16);
    unsigned int time_std = clock();
    std_vector.front() -= std_vector.back();
    unsigned int time_std_end = clock() - time_std;

    ft_vector.push_back(78);
    ft_vector.push_back(16);
    unsigned int time_ft = clock();
    ft_vector.front() -= ft_vector.back();
    unsigned int time_ft_end = clock() - time_ft;

    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
}

void test_back(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST back()..." << CL << "\n\n";
    std::vector<int> std_vector;
    ft::vector<int> ft_vector;

    std_vector.push_back(10);
    while (std_vector.back() != 0)
    {
        std_vector.push_back ( std_vector.back() -1 );
    }

    unsigned int time_std = clock();
    std_vector.back();
    unsigned int time_std_end = clock() - time_std;



    ft_vector.push_back(10);
    while (ft_vector.back() != 0)
    {
        ft_vector.push_back ( ft_vector.back() -1 );
    }

    unsigned int time_ft = clock();
    ft_vector.back();
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
}

void test_assign(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST assign()..." << CL << "\n\n";
    std::vector<int>    std_first;
    std::vector<int>    std_second;
    std::vector<int>    std_third;

    ft::vector<int>    ft_first;
    ft::vector<int>    ft_second;
    ft::vector<int>    ft_third;

    unsigned int time_std = clock();
    std_first.assign (1000000,100);
    unsigned int time_std_end = clock() - time_std;
    unsigned int time_ft = clock();
    ft_first.assign (1000000,100);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_first, ft_first, "fill version", time_std_end, time_ft_end);             

    
    std::vector<int>::iterator std_it;
    std_it=std_first.begin()+1;
    time_std = clock();
    std_second.assign (std_it,std_first.end()-1);
    time_std_end = clock() - time_std;

    ft::vector<int>::iterator ft_it;
    ft_it=ft_first.begin()+1;
    time_ft = clock();
    ft_second.assign (ft_it,ft_first.end()-1);
    time_ft_end = clock() - time_ft;
    compare_vectors(std_second, ft_second, "range version", time_std_end, time_ft_end);

    time_std = clock();
    int std_myints[] = {1776,7,4};
    std_third.assign (std_myints,std_myints+3);
    time_std_end = clock() - time_std;

    time_ft = clock();
    int ft_myints[] = {1776,7,4};
    ft_third.assign (ft_myints,ft_myints+3);
    time_ft_end = clock() - time_ft;
    compare_vectors(std_third, ft_third, "assigning from array", time_std_end, time_ft_end);
}

void test_push_back(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST push_back()..." << CL << "\n\n";
    std::vector<int> std_vector;
    ft::vector<int> ft_vector;

    unsigned int time_std = clock();
    std_vector.push_back(100);
    unsigned int time_std_end = clock() - time_std;

    unsigned int time_ft = clock();
    ft_vector.push_back(100);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);

    time_std = clock();
    add_data_to_vector(std_vector, 10000000);
    time_std_end = clock() - time_std;

    time_ft = clock();
    add_data_to_vector(ft_vector, 10000000);
    time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test2", time_std_end, time_ft_end);
}

void test_pop_back(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST pop_back()..." << CL << "\n\n";
    std::vector<int> std_vector;
    ft::vector<int> ft_vector;
    add_data_to_vector(std_vector, 10000000);
    add_data_to_vector(ft_vector, 10000000);

    unsigned int time_std = clock();
    while (!std_vector.empty())
        std_vector.pop_back();
    unsigned int time_std_end = clock() - time_std;

    unsigned int time_ft = clock();
    while (!ft_vector.empty())
        ft_vector.pop_back();
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
}

void test_insert(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST insert()..." << CL << "\n\n";

    std::vector<int> std_vector (300000,100);
    std::vector<int>::iterator std_it_begin = std_vector.begin();
    //std::vector<int>::iterator std_it_center = std_vector.begin() + std_vector.size()/2;
    ft::vector<int> ft_vector (300000,100);
    ft::vector<int>::iterator ft_it_begin = ft_vector.begin();
    //ft::vector<int>::iterator ft_it_center = ft_vector.begin() + ft_vector.size()/2;
    //test1
    unsigned int time_std = clock();
    std_it_begin = std_vector.insert( std_it_begin , 200 );
    unsigned int time_std_end = clock() - time_std;

    unsigned int time_ft = clock();
    ft_it_begin = ft_vector.insert( ft_it_begin , 200 );
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
    //test2
    time_std = clock();
    std_vector.insert (std_it_begin,211,300);
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_vector.insert (ft_it_begin,211,300);
    time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test2", time_std_end, time_ft_end);
    //test3
    std_it_begin = std_vector.begin();
    std::vector<int> std_anothervector (20,400);
    time_std = clock();
    std_vector.insert (std_it_begin + 100,std_anothervector.begin(),std_anothervector.end());
    time_std_end = clock() - time_std;
    
    ft_it_begin = ft_vector.begin();
    ft::vector<int> ft_anothervector (20,400);
    time_ft = clock();
    ft_vector.insert (ft_it_begin + 100,ft_anothervector.begin(),ft_anothervector.end());
    time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test3", time_std_end, time_ft_end);
    //test4
    int myarray [] = { 501,502,503, 2325, 324, 2321, 234, 234, 678, 345, 567568, 234, 234};
    time_std = clock();
    std_vector.insert (std_vector.begin(), myarray, myarray+3);
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_vector.insert (ft_vector.begin(), myarray, myarray+3);
    time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test4", time_std_end, time_ft_end);
}

void test_erase(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST erase()..." << CL << "\n\n";
    std::vector<int> std_vector(30000, 123);
    ft::vector<int> ft_vector(30000, 123);

    unsigned int time_std = clock();
    std_vector.erase(std_vector.begin() + 23);
    unsigned int time_std_end = clock() - time_std;

    unsigned int time_ft = clock();
    ft_vector.erase(ft_vector.begin() + 23);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);

    time_std = clock();
    std_vector.erase(std_vector.begin(), std_vector.begin() + 200);
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_vector.erase(ft_vector.begin(), ft_vector.begin() + 200);
    time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test2", time_std_end, time_ft_end);
}

void test_swap(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST swap()..." << CL << "\n\n";
    std::vector<int> std_vector(300000, 987654);
    std::vector<int> std_swap(2345, 1123);
    ft::vector<int> ft_vector(300000, 987654);
    ft::vector<int> ft_swap(2345, 1123);

    unsigned int time_std = clock();
    std_vector.swap(std_swap);
    unsigned int time_std_end = clock() - time_std;

    unsigned int time_ft = clock();
    ft_vector.swap(ft_swap);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
}

void test_clear(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST clear()..." << CL << "\n\n";
    std::vector<int> std_vector(50000000,654);
    ft::vector<int> ft_vector(50000000,654);

    unsigned int time_std = clock();
    std_vector.clear();
    unsigned int time_std_end = clock() - time_std;

    unsigned int time_ft = clock();
    ft_vector.clear();
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
}

void test_operator2(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST operator==()..." << CL << "\n\n";

    {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(200, 321);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector == std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(200, 231);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector == ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_res, ft_res, "test1", time_std_end, time_ft_end);
    }
    {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(200, 123);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector == std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(200, 123);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector == ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_res, ft_res, "test2", time_std_end, time_ft_end);
    }
}

void test_operator3(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST operator!=()..." << CL << "\n\n";

    {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(200, 231);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector != std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(200, 231);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector != ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
    }

     {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(20, 123);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector != std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(20, 123);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector != ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test2", time_std_end, time_ft_end);
    }
}

void test_operator4(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST operator<()..." << CL << "\n\n";

    {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(200, 231);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector < std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(200, 231);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector < ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
    }

     {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(20, 123);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector < std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(20, 123);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector < ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test2", time_std_end, time_ft_end);
    }
}

void test_operator5(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST operator<=()..." << CL << "\n\n";

    {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(200, 231);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector <= std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(200, 231);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector <= ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
    }

     {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(20, 123);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector <= std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(20, 123);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector <= ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test2", time_std_end, time_ft_end);
    }
    {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(200, 123);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector <= std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(200, 123);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector <= ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test2", time_std_end, time_ft_end);
    }
}

void test_operator6(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST operator>()..." << CL << "\n\n";

    {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(200, 231);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector > std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(200, 231);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector > ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
    }

     {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(20, 123);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector > std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(20, 123);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector > ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test2", time_std_end, time_ft_end);
    }
}

void test_operator7(){
    std::cout << BACKMAG << std::left << std::setfill(' ') << std::setw(74)  << "START TEST operator>=()..." << CL << "\n\n";

    {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(200, 231);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector >= std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(200, 231);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector >= ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test1", time_std_end, time_ft_end);
    }

     {
        std::vector<int> std_vector(200, 123);
    std::vector<int> std_other(20, 123);
    std::vector<int> std_res;

    
    unsigned int time_std = clock();
    std_vector >= std_other?std_res.push_back(1):std_res.push_back(0);
    unsigned int time_std_end = clock() - time_std;

    ft::vector<int> ft_vector(200, 123);
    ft::vector<int> ft_other(20, 123);
    ft::vector<int> ft_res;
    
    unsigned int time_ft = clock();
    ft_vector >= ft_other?ft_res.push_back(1):ft_res.push_back(0);
    unsigned int time_ft_end = clock() - time_ft;
    compare_vectors(std_vector, ft_vector, "test2", time_std_end, time_ft_end);
    }
}