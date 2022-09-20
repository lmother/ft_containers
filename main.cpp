
#include "./utils/test_vector.hpp"
#include "./utils/test_stack.hpp"
#include <string.h>

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
		if(!strncmp("1", ac[1], 1))
			start_test_vector();
		else if(!strncmp("2", ac[1], 1))
			start_test_stack();
		else{
			std::cout << "\ntry input arguments:\n \"1\" - test_vector\n \"2\" - test_stack\n \"3\" - test_map\n";
		}
	}else
		std::cout << "try input arguments:\n \"1\" - test_vector\n \"2\" - test_stack\n \"3\" - test_map\n";
	return (0);
}