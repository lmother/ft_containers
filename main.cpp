
#include "./utils/test_vector.hpp"
#include "./utils/test_stack.hpp"
#include <string.h>

void print_header(std::string str){
	std::cout << BACKWHT << std::left << std::setfill(' ') << std::setw(40)  << "START TEST " << std::setw(34) << str << CL << "\n\n";
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


int main(int av, char** ac) {
	if (av == 2){
		if(!strncmp("1", ac[1], 1)){
			print_header("vector");
			start_test_vector();
		}
		else if(!strncmp("2", ac[1], 1)){
			print_header("stack");
			start_test_stack();
		}
		else
			print_menu();
	}
	else
		print_menu();
	return (0);
}