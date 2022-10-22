#pragma once

#include "colors.hpp"
#include <iomanip>

#include "../map.hpp"
#include "test_vector.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <map>

#include <ctime>

void print_header_test(std::string str){
    std::cout << BACKCYN << std::left << std::setfill(' ') << std::setw(13) 
            << "START TEST :" << std::setw(61) <<  str <<  CL << "\n\n";
}

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

template <class Map1, class Map2>
void compare_maps(Map1 stl_m1, Map2 m2, std::string massege, unsigned int std_time, unsigned int ft_time){
    if (stl_m1.size() != m2.size()){
        std::cout << "STD size - " << stl_m1.size() << std::endl;
        std::cout << "FT size - " << m2.size() << std::endl;
        std::cout << std::left << std::setfill('-') << std::setw(30) << massege << std::setw(5)<< FORERED <<  "KO \n" << CL;
        std::cout << "size!!!!!!!!!!\n";
        return;
    }
    else{
        std::map<char,int>::iterator std_it = stl_m1.begin();
        ft::map<char,int>::iterator my_it = m2.begin();
    
        for(size_t i = 0; i < stl_m1.size(); ++i, std_it++, my_it++){
           if(std_it->first != my_it->first || std_it->second != my_it->second){
                std::cout << std::setfill('-') << std::left << std::setw(30) << massege << std::setw(5)<< FORERED <<  "KO \n" << CL;
                std::cout << "not compare!!!!!!!!!!\n";
                return;
            }
        }
    }
    std::cout << std::left << std::setfill('-') 
                << std::setw(30) << massege << std::setw(5)<< FOREGRN <<  "OK | " << CL;
    print_time(std_time, ft_time);
}



void test_map_constructor(){
    print_header_test("constructor()...");
        std::map<char,int> first;
        ft::map<char,int> my_first;

        unsigned int time_std;
        unsigned int time_std_end;
        unsigned int time_ft;
        unsigned int time_ft_end;

        time_std = clock();
        first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;
        time_std_end = clock() - time_std;
        
        time_ft = clock();
        first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;
        time_ft_end = clock() - time_ft;
        compare_maps(first, my_first, "test1", time_std_end, time_ft_end);


        time_std = clock();
        std::map<char,int> second (first.begin(),first.end());
        time_std_end = clock() - time_std;

        time_ft = clock();
        ft::map<char,int> my_second (my_first.begin(),my_first.end());
        time_ft_end = clock() - time_ft;
        compare_maps(second, my_second, "test2", time_std_end, time_ft_end);

        time_std = clock();
        std::map<char,int> third (second);
        time_std_end = clock() - time_std;

        time_ft = clock();
        ft::map<char,int> my_third (my_second);
        time_ft_end = clock() - time_ft;
        compare_maps(third, my_third, "test3", time_std_end, time_ft_end);

        time_std = clock();
        std::map<char,int,classcomp> fourth; 
        time_std_end = clock() - time_std;

        time_ft = clock();
        ft::map<char,int,classcomp> my_fourth;
        time_ft_end = clock() - time_ft;
        compare_maps(fourth, my_fourth, "test4", time_std_end, time_ft_end);

        bool(*fn_pt)(char,char) = fncomp;

        time_std = clock();
        std::map<char,int,bool(*)(char,char)> fifth (fn_pt);
        time_std_end = clock() - time_std;

        time_ft = clock();
        ft::map<char,int,bool(*)(char,char)> my_fifth (fn_pt);
        time_ft_end = clock() - time_ft;
        compare_maps(fifth, my_fifth, "test5", time_std_end, time_ft_end);
}