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
    std::map<char, int>::iterator std_it = stl_m1.begin();
    ft::map<char, int>::iterator ft_it = m2.begin();

    if (stl_m1.size() != m2.size()){
        std::cout << std::left << std::setfill('-') << std::setw(30) << massege << std::setw(5)<< FORERED <<  "KO \n" << CL;
        return;
    }
    else{
        for(size_t i = 0; i < stl_m1.size(); ++i){
           if(std_it->first != ft_it->first || std_it->second != ft_it->second){
                std::cout << std::setfill('-') << std::left << std::setw(30) << massege << std::setw(5)<< FORERED <<  "KO \n" << CL;
                return;
            }
            std_it++;
            ft_it++;
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
        my_first['a']=10;
        my_first['b']=30;
        my_first['c']=50;
        my_first['d']=70;
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

void test_map_operator1(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> first;
    std::map<char,int> second;
    ft::map<char,int> ft_first;
    ft::map<char,int> ft_second;

    print_header_test("operator=()...");

    first['x']=8;
    first['y']=16;
    first['z']=32;

    ft_first['x']=8;
    ft_first['y']=16;
    ft_first['z']=32;

    time_std = clock();
    second=first;
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_second = ft_first;
    time_ft_end = clock() - time_ft;
    compare_maps(second, ft_second, "test1", time_std_end, time_ft_end);

    time_std = clock();
    first=std::map<char,int>();
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_first=ft::map<char,int>();
    time_ft_end = clock() - time_ft;
    compare_maps(first, ft_first, "test2", time_std_end, time_ft_end);
}

void test_map_begin(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> first;
    ft::map<char,int> ft_first;
    std::map<char,int> res;
    ft::map<char,int> ft_res;

    print_header_test("begin()...");

    first['x']=8;
    first['y']=16;
    first['z']=32;
    time_std = clock();
    std::map<char, int>::iterator std_it = first.begin();
    time_std_end = clock() - time_std;

    ft_first['x']=8;
    ft_first['y']=16;
    ft_first['z']=32;
    time_ft = clock();
    ft::map<char, int>::iterator ft_it = ft_first.begin();
    time_ft_end = clock() - time_ft;

    res[std_it->first] = std_it->second;
    ft_res[ft_it->first] = ft_it->second;
    compare_maps(res, ft_res, "test1", time_std_end, time_ft_end);
}

void test_map_clear(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> first;
    ft::map<char,int> ft_first;
    std::map<char,int> res;
    ft::map<char,int> ft_res;

    print_header_test("clear()...");

    std::map<char,int> mymap;

    first['x']=100;
    first['y']=200;
    first['z']=300;

    time_std = clock();
    first.clear();
    time_std_end = clock() - time_std;

    ft_first['x']=100;
    ft_first['y']=200;
    ft_first['z']=300;

    time_ft = clock();
    ft_first.clear();
    time_ft_end = clock() - time_ft;
    compare_maps(first, ft_first, "test1", time_std_end, time_ft_end);


    first['a']=8;
    first['b']=16;
    first['c']=32;
    ft_first['a']=8;
    ft_first['b']=16;
    ft_first['c']=32;
    compare_maps(first, ft_first, "test2", time_std_end, time_ft_end);
}

void test_map_count(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    std::vector<int> res;
    ft::map<char,int> ft_mymap;
    ft::vector<int> ft_res;
    size_t std_res, my_res;

    print_header_test("count()...");

    for(int i = 0; i <= 'z'; ++i){
        mymap[('a' + i)] = i;
    }

    for(int i = 0; i <= 'z'; ++i){
        ft_mymap[('a' + i)] = i;
    }

    time_std = clock();
    std_res = mymap.count('z');
    time_std_end = clock() - time_std;
    time_ft = clock();
    my_res = ft_mymap.count('z');
    time_ft_end = clock() - time_ft;
    res.push_back(std_res);
    ft_res.push_back(my_res);

    compare_vectors(res, ft_res, "test1", time_std_end, time_ft_end);

    time_std = clock();
    std_res = mymap.count('a');
    time_std_end = clock() - time_std;
    time_ft = clock();
    my_res = ft_mymap.count('a');
    time_ft_end = clock() - time_ft;
    res.push_back(std_res);
    ft_res.push_back(my_res);
    compare_vectors(res, ft_res, "test2", time_std_end, time_ft_end);


    time_std = clock();
    std_res = mymap.count('t');
    time_std_end = clock() - time_std;
    time_ft = clock();
    my_res = ft_mymap.count('t');
    time_ft_end = clock() - time_ft;
    res.push_back(std_res);
    ft_res.push_back(my_res);
    compare_vectors(res, ft_res, "test3", time_std_end, time_ft_end);
}

void test_map_empty(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;
    std::vector<bool> res;
    ft::vector<bool> ft_res;

    print_header_test("empty()...");

    time_std = clock();
    res.push_back(mymap.empty());
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_res.push_back(ft_mymap.empty());
    time_ft_end = clock() - time_ft;

    compare_vectors(res, ft_res, "test1", time_std_end, time_ft_end);

    for(int i = 0; i <= 'z'; ++i){
        mymap[('a' + i)] = i;
    }

    for(int i = 0; i <= 'z'; ++i){
        ft_mymap[('a' + i)] = i;
    }

    time_std = clock();
    while (!mymap.empty())
    {
        mymap.erase(mymap.begin());
    }
    time_std_end = clock() - time_std;

    time_ft = clock();
    while (!ft_mymap.empty())
    {
        ft_mymap.erase(ft_mymap.begin());
    }
    time_ft_end = clock() - time_ft;

    compare_maps(mymap, ft_mymap, "test2", time_std_end, time_ft_end);
}

void test_map_end(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;
    std::map<char,int> second;
    ft::map<char,int> ft_second;
    std::vector<char> res;
    ft::vector<char> ft_res;

    print_header_test("end()...");


    time_std = clock();
    mymap.begin();
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_mymap.begin();
    time_ft_end = clock() - time_ft;

    compare_vectors(res, ft_res, "test1", time_std_end, time_ft_end);

    for(int i = 0; i <= 'z'; ++i){
        mymap[('a' + i)] = i;
    }

    for(int i = 0; i <= 'z'; ++i){
        ft_mymap[('a' + i)] = i;
    }

    time_std = clock();
    res.push_back(mymap.begin()->first);
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_res.push_back(ft_mymap.begin()->first);
    time_ft_end = clock() - time_ft;

    compare_vectors(res, ft_res, "test2", time_std_end, time_ft_end);

    second['a'] = 123312;
    ft_second['a'] = 123312;

    time_std = clock();
    res.push_back(mymap.begin()->first);
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_res.push_back(ft_mymap.begin()->first);
    time_ft_end = clock() - time_ft;

    compare_vectors(res, ft_res, "test3", time_std_end, time_ft_end);
}

void test_map_equal_range(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;
    std::map<char,int> second;
    ft::map<char,int> ft_second;


    print_header_test("equal_range()...");

    for(int i = 0; i <= 'z'; ++i){
        mymap[('a' + i)] = i;
    }

    for(int i = 0; i <= 'z'; ++i){
        ft_mymap[('a' + i)] = i;
    }

    time_std = clock();
    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ft_ret;
    ft_ret = ft_mymap.equal_range('b');
    time_ft_end = clock() - time_ft;


    second[ret.first->first] = ret.first->second;
    second[ret.second->first] = ret.second->second;
    ft_second[ft_ret.first->first] = ft_ret.first->second;
    ft_second[ft_ret.second->first] = ft_ret.second->second;
    compare_maps(mymap, ft_mymap, "test1", time_std_end, time_ft_end);
}


void test_map_erase(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;
    std::map<char,int> second;
    ft::map<char,int> ft_second;
    std::map<char,int>::iterator std_it;
    ft::map<char,int>::iterator ft_it;


    print_header_test("arase()...");
  
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;
    ft_mymap['a']=10;
    ft_mymap['b']=20;
    ft_mymap['c']=30;
    ft_mymap['d']=40;
    ft_mymap['e']=50;
    ft_mymap['f']=60;

    std_it=mymap.find('b');
    time_std = clock();
    mymap.erase (std_it);
    time_std_end = clock() - time_std;

    ft_it=ft_mymap.find('b');
    time_ft = clock();
    ft_mymap.erase (ft_it);
    time_ft_end = clock() - time_ft;
    compare_maps(mymap, ft_mymap, "test1", time_std_end, time_ft_end);


    time_std = clock();
    mymap.erase ('c');
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_mymap.erase ('c');
    time_ft_end = clock() - time_ft;
    compare_maps(mymap, ft_mymap, "test1", time_std_end, time_ft_end);

    std_it=mymap.find('e');
    time_std = clock();
    mymap.erase ( std_it, mymap.end() );
    time_std_end = clock() - time_std;

    ft_it=ft_mymap.find('e');
    time_ft = clock();
    ft_mymap.erase ( ft_it, ft_mymap.end() );
    time_ft_end = clock() - time_ft;
    compare_maps(mymap, ft_mymap, "test1", time_std_end, time_ft_end);

}

void test_map_find(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;
    std::map<char,int> second;
    ft::map<char,int> ft_second;
    std::vector<int> res;
    ft::vector<int> ft_res;


    print_header_test("find()...");
  
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;
    ft_mymap['a']=10;
    ft_mymap['b']=20;
    ft_mymap['c']=30;
    ft_mymap['d']=40;
    ft_mymap['e']=50;
    ft_mymap['f']=60;

    time_std = clock();
    res.push_back(mymap.find('a')->second);
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_res.push_back(ft_mymap.find('a')->second);
    time_ft_end = clock() - time_ft;
    compare_vectors(res, ft_res, "test1", time_std_end, time_ft_end);

    time_std = clock();
    res.push_back(mymap.find('b')->second);
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_res.push_back(ft_mymap.find('b')->second);
    time_ft_end = clock() - time_ft;
    compare_vectors(res, ft_res, "test2", time_std_end, time_ft_end);


    time_std = clock();
    res.push_back(mymap.find('e')->second);
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_res.push_back(ft_mymap.find('e')->second);
    time_ft_end = clock() - time_ft;
    compare_vectors(res, ft_res, "test3", time_std_end, time_ft_end);

    time_std = clock();
    res.push_back(mymap.find('f')->second);
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_res.push_back(ft_mymap.find('f')->second);
    time_ft_end = clock() - time_ft;
    compare_vectors(res, ft_res, "test4", time_std_end, time_ft_end);

}

void test_map_insert(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;


    print_header_test("insert()...");

    time_std = clock();
    mymap.insert ( std::pair<char,int>('a',100) );
    mymap.insert ( std::pair<char,int>('z',200) );
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_mymap.insert ( ft::pair<char,int>('a',100) );
    ft_mymap.insert ( ft::pair<char,int>('z',200) );
    time_ft_end = clock() - time_ft;
    compare_maps(mymap, ft_mymap, "test1", time_std_end, time_ft_end);


  // second insert function version (with hint position):
    std::map<char,int>::iterator it = mymap.begin();
    ft::map<char,int>::iterator ft_it = ft_mymap.begin();

    time_std = clock();
    mymap.insert (it, std::pair<char,int>('b',300));
    mymap.insert (it, std::pair<char,int>('c',400));
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_mymap.insert (ft_it, ft::pair<char,int>('b',300));
    ft_mymap.insert (ft_it, ft::pair<char,int>('c',400));
    time_ft_end = clock() - time_ft;
    compare_maps(mymap, ft_mymap, "test2", time_std_end, time_ft_end);



    std::map<char,int> anothermap;
    ft::map<char,int> ft_anothermap;

    time_std = clock();
    anothermap.insert(mymap.begin(),mymap.find('c'));
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_anothermap.insert(ft_mymap.begin(),ft_mymap.find('c'));
    time_ft_end = clock() - time_ft;
    compare_maps(mymap, ft_mymap, "test3", time_std_end, time_ft_end);

}


void test_map_key_kompare(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;
    ft_mymap['a']=20;
    ft_mymap['b']=40;
    ft_mymap['c']=60;
    ft_mymap['d']=80;
    ft_mymap['e']=100;

    print_header_test("key_kompare()...");

    time_std = clock();
    std::map<char,int>::key_compare mycomp = mymap.key_comp();
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft::map<char,int>::key_compare ft_mycomp = ft_mymap.key_comp();
    time_ft_end = clock() - time_ft;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;
    ft_mymap['a']=20;
    ft_mymap['b']=40;
    ft_mymap['c']=60;
    ft_mymap['d']=80;
    ft_mymap['e']=100;

    (void) mycomp;
    (void) ft_mycomp;

    compare_maps(mymap, ft_mymap, "test1", time_std_end, time_ft_end);
}


void test_map_lower_bound(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;
    std::map<char,int>::iterator itlow,itup;
    ft::map<char,int>::iterator ft_itlow,ft_itup;
    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;
    ft_mymap['a']=20;
    ft_mymap['b']=40;
    ft_mymap['c']=60;
    ft_mymap['d']=80;
    ft_mymap['e']=100;
    print_header_test("lower_bound()...");

    time_std = clock();
    itlow=mymap.lower_bound ('b');
    itup=mymap.upper_bound ('d');
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_itlow=ft_mymap.lower_bound ('b');
    ft_itup=ft_mymap.upper_bound ('d');
    time_ft_end = clock() - time_ft;

    mymap.erase(itlow,itup);
    ft_mymap.erase(ft_itlow,ft_itup);

    compare_maps(mymap, ft_mymap, "test1", time_std_end, time_ft_end);
}

void test_map_upper_bound(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;
    std::map<char,int>::iterator itlow,itup;
    ft::map<char,int>::iterator ft_itlow,ft_itup;
    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;
    ft_mymap['a']=20;
    ft_mymap['b']=40;
    ft_mymap['c']=60;
    ft_mymap['d']=80;
    ft_mymap['e']=100;
    print_header_test("lower_bound()...");

    time_std = clock();
    itlow=mymap.lower_bound ('b');
    itup=mymap.upper_bound ('d');
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_itlow=ft_mymap.lower_bound ('b');
    ft_itup=ft_mymap.upper_bound ('d');
    time_ft_end = clock() - time_ft;

    mymap.erase(itlow,itup);
    ft_mymap.erase(ft_itlow,ft_itup);

    compare_maps(mymap, ft_mymap, "test1", time_std_end, time_ft_end);
}

void test_map_rbegin(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;
    ft_mymap['a']=20;
    ft_mymap['b']=40;
    ft_mymap['c']=60;
    ft_mymap['d']=80;
    ft_mymap['e']=100;

    print_header_test("rbegin()...");

    std::map<char,int>::reverse_iterator rit;
    ft::map<char,int>::reverse_iterator ft_rit;

    time_std = clock();
    for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
        std_vec.push_back(rit->second);
    time_std_end = clock() - time_std;


    time_ft = clock();
    for (ft_rit=ft_mymap.rbegin(); ft_rit!=ft_mymap.rend(); ++ft_rit)
        ft_vec.push_back(ft_rit->second);
    time_ft_end = clock() - time_ft;

    compare_vectors(std_vec, ft_vec, "test1", time_std_end, time_ft_end);

}

void test_map_rend(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;
    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;
    ft_mymap['a']=20;
    ft_mymap['b']=40;
    ft_mymap['c']=60;
    ft_mymap['d']=80;
    ft_mymap['e']=100;

    print_header_test("rend()...");

    std::map<char,int>::reverse_iterator rit;
    ft::map<char,int>::reverse_iterator ft_rit;

    time_std = clock();
    for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
        std_vec.push_back(rit->second);
    time_std_end = clock() - time_std;


    time_ft = clock();
    for (ft_rit=ft_mymap.rbegin(); ft_rit!=ft_mymap.rend(); ++ft_rit)
        ft_vec.push_back(ft_rit->second);
    time_ft_end = clock() - time_ft;

    compare_vectors(std_vec, ft_vec, "test1", time_std_end, time_ft_end);

}

void test_map_swap(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;

    std::map<char,int> foo,bar;
    ft::map<char,int> ft_foo,ft_bar;

    print_header_test("swap()...");

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;
    ft_foo['x']=100;
    ft_foo['y']=200;

    ft_bar['a']=11;
    ft_bar['b']=22;
    ft_bar['c']=33;

    time_std = clock();
    foo.swap(bar);
    time_std_end = clock() - time_std;

    time_ft = clock();
    ft_foo.swap(ft_bar);
    time_ft_end = clock() - time_ft;

    compare_maps(foo, ft_foo, "test1", time_std_end, time_ft_end);
    compare_maps(bar, ft_bar, "test2", time_std_end, time_ft_end);
}

void test_map_operator2(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;

    std::map<char,int> mymap;
    ft::map<char,int> ft_mymap;

    print_header_test("operator[]...");

    time_std = clock();
    mymap['a']=10;
    mymap['b']=30;
    mymap['c']=50;
    mymap['d']=70;
    time_std_end = clock() - time_std;
        
    time_ft = clock();
    ft_mymap['a']=10;
    ft_mymap['b']=30;
    ft_mymap['c']=50;
    ft_mymap['d']=70;
    time_ft_end = clock() - time_ft;
    compare_maps(mymap, ft_mymap, "test1", time_std_end, time_ft_end);
}

void test_map_operator3(){
    unsigned int time_std;
    unsigned int time_std_end;
    unsigned int time_ft;
    unsigned int time_ft_end;

    std::map<char,int> foo, bar;
    ft::map<char,int> ft_foo, ft_bar;
    std::vector<bool> res;
    ft::vector<bool> ft_res;

    ft_foo['a']=20;
    ft_foo['b']=40;
    ft_bar['c']=60;
    ft_bar['d']=80;
    foo['a']=20;
    foo['b']=40;
    bar['c']=60;
    bar['d']=80;

    print_header_test("operator==...");

    time_std = clock();
    res.push_back(foo == bar);
    time_std_end = clock() - time_std;


    time_ft = clock();
    ft_res.push_back(ft_foo == ft_bar);
    time_ft_end = clock() - time_ft;
    compare_vectors(res, ft_res, "test1", time_std_end, time_ft_end);

    print_header_test("operator!=...");

    time_std = clock();
    res.push_back(foo != bar);
    time_std_end = clock() - time_std;


    time_ft = clock();
    ft_res.push_back(ft_foo != ft_bar);
    time_ft_end = clock() - time_ft;
    compare_vectors(res, ft_res, "test1", time_std_end, time_ft_end);

    print_header_test("operator<...");

    time_std = clock();
    res.push_back(foo < bar);
    time_std_end = clock() - time_std;


    time_ft = clock();
    ft_res.push_back(ft_foo < ft_bar);
    time_ft_end = clock() - time_ft;
    compare_vectors(res, ft_res, "test1", time_std_end, time_ft_end);


    print_header_test("operator>...");

    time_std = clock();
    res.push_back(foo > bar);
    time_std_end = clock() - time_std;


    time_ft = clock();
    ft_res.push_back(ft_foo > ft_bar);
    time_ft_end = clock() - time_ft;
    compare_vectors(res, ft_res, "test1", time_std_end, time_ft_end);

    print_header_test("operator<=...");

    time_std = clock();
    res.push_back(foo <= bar);
    time_std_end = clock() - time_std;


    time_ft = clock();
    ft_res.push_back(ft_foo <= ft_bar);
    time_ft_end = clock() - time_ft;
    compare_vectors(res, ft_res, "test1", time_std_end, time_ft_end);


    print_header_test("operator>=...");

    time_std = clock();
    res.push_back(foo >= bar);
    time_std_end = clock() - time_std;


    time_ft = clock();
    ft_res.push_back(ft_foo >= ft_bar);
    time_ft_end = clock() - time_ft;
    compare_vectors(res, ft_res, "test1", time_std_end, time_ft_end);
    
}

