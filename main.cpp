
#include "./utils/test_vector.hpp"


int main() {
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



	return (0);
}