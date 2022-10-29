
#include "./utils/test_vector.hpp"
#include "./utils/test_stack.hpp"
#include "./utils/test_map.hpp"
#include <string.h>

void print_header(std::string str){
	std::cout << BACKWHT << std::left << std::setfill(' ') << std::setw(40)  
		<< "START TEST " << std::setw(34) << str << CL << "\n\n";
}

void print_menu(){
	std::cout << "\n# Try input one argument:\n" 
		<<  FOREMAG << "\"1\" - test_vector\n" << CL
		<< FOREBLU << "\"2\" - test_stack\n" << CL
		<< FOREGRN "\"3\" - test_map\n" << CL;
}

void start_test_vector(){
	test_constructor("str", "STRING...");
	test_constructor(123, "INT...");
	test_constructor(12.35, "FLOAT...");
	test_opertor();
	test_operator1();
	test_begin();
	test_end();
	test_rbegin();
	test_rend();
	test_size();
	test_resize();
	test_empty();
	test_reserve();
	test_at();
	test_front();
	test_back();
	test_assign();
	test_push_back();
	test_pop_back();
	test_insert();
	test_erase();
	test_swap();
	test_clear();
	test_operator2();
	test_operator3();
	test_operator4();
	test_operator5();
	test_operator6();
	test_operator7();
}

void start_test_stack(){
	test_stack_constructor();
	test_stack_empty();
	test_stack_size();
	test_stack_top();
	test_stack_push();
	test_stack_operator1();
	test_stack_operator2();
	test_stack_operator3();
	test_stack_operator4();
	test_stack_operator5();
	test_stack_operator6();
}

void start_test_map(){
	test_map_constructor();
	test_map_operator1();
	test_map_begin();
	test_map_clear();
	test_map_count();
	test_map_empty();
	test_map_end();
	test_map_equal_range();
	test_map_erase();
	test_map_find();
	test_map_insert();
	test_map_key_kompare();
	test_map_lower_bound();
	test_map_upper_bound();
	test_map_rbegin();
	test_map_rend();
	test_map_swap();
	test_map_operator2();
	test_map_operator3();
}


int main(int av, char** ac) {
	if (av == 2){
		if(!strncmp("1", ac[1], 1)){
			print_header("VECTOR");
			start_test_vector();
		}
		else if(!strncmp("2", ac[1], 1)){
			print_header("STACK");
			start_test_stack();
		}
		else if(!strncmp("3", ac[1], 1)){
			print_header("MAP");
			start_test_map();
		}
		else
			print_menu();
	}
	else
		print_menu();
	return (0);
}