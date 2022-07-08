#include <iostream>
#include <iterator>
#include <string>
#include <deque>



#include "vector.hpp"
#include "stack.hpp"
#include <vector>

#define CL  "\x1B[0m" // Set all colors back to normal.
#define FOREBLK  "\x1B[30m" // Black
#define FORERED  "\x1B[31m" // Red
#define FOREGRN  "\x1B[32m" // Green
#define FOREYEL  "\x1B[33m" // Yellow
#define FOREBLU  "\x1B[34m" // Blue
#define FOREMAG  "\x1B[35m" // Magenta
#define FORECYN  "\x1B[36m" // Cyan
#define FOREWHT  "\x1B[37m" // White

/* BACKGROUND */
// These codes set the background color behind the text.
#define BACKBLK "\x1B[40m"
#define BACKRED "\x1B[41m"
#define BACKGRN "\x1B[42m"
#define BACKYEL "\x1B[43m"
#define BACKBLU "\x1B[44m"
#define BACKMAG "\x1B[45m"
#define BACKCYN "\x1B[46m"
#define BACKWHT "\x1B[47m"



int main() {

	for (int i = 0; i < 10; i++)
		std::cout << '\n';
	std::cout << BACKMAG << "Test 1______________________________________________________________________________________________" << CL << "\n\n";
	std::cout << FOREYEL << "|||||||||| My Vector. Empty constructor:  |||||||||||\n" << CL;

	try {
		ft::vector<int> myvector;
		std::cout << "##### creat myvector <INT> #####\n";
		std::cout << "size myvector : " << myvector.size() << std::endl;
		std::cout << "Capacity myvector : " << myvector.capacity() << std::endl;
		ft::vector<float> myvector1;
		std::cout << "##### creat myvector1 <FLOAT> #####\n";
		std::cout << "size myvector1 : " << myvector1.size() << std::endl;
		std::cout << "Capacity myvector1 : " << myvector1.capacity() << std::endl;
		ft::vector<std::string> myvector11;
		std::cout << "##### creat myvector11 <STRING> #####\n";
		std::cout << "size myvector11 : " << myvector11.size() << std::endl;
		std::cout << "Capacity myvector11 : " << myvector11.capacity() << std::endl;
		std::cout << FOREGRN << "OK" << CL;

	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: Empty constructor! \n" << CL;
	}

	std::cout << "\n\n";
/////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << FOREBLU << "|||||||||| Not myne. Empty constructor:   ||||||||||||\n" << CL;
	try {
		std::vector<int> myvector;
		std::cout << "##### creat myvector <INT> #####\n";
		std::cout << "size myvector : " << myvector.size() << std::endl;
		std::cout << "Capacity myvector : " << myvector.capacity() << std::endl;
		std::vector<float> myvector1;
		std::cout << "##### creat myvector1 <FLOAT> #####\n";
		std::cout << "size myvector1 : " << myvector1.size() << std::endl;
		std::cout << "Capacity myvector1 : " << myvector1.capacity() << std::endl;
		std::vector<std::string> myvector11;
		std::cout << "##### creat myvector11 <STRING> #####\n";
		std::cout << "size myvector11 : " << myvector11.size() << std::endl;
		std::cout << "Capacity myvector11 : " << myvector11.capacity() << std::endl;
		std::cout << FOREGRN << "OK" << CL;
	}
	catch (...) {
		std::cout << FORERED <<  "Error Not myne: Empty constructor! \n" << CL;
	}

	std::cout << "\n\n";
	////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << BACKMAG << "Test 2______________________________________________________________________________________________" << CL << "\n\n";
	std::cout << FOREYEL << "|||||||||| My Vector. Vis NOT Empty constructor_1:  |||||||||||\n" << CL;

	try {
		ft::vector<int> test2(100, 333);
		std::cout << "##### creat test2 <INT>(100, 333) #####\n";
		std::cout << "size test2 : " << test2.size() << std::endl;
		std::cout << "Capacity test2 : " << test2.capacity() << std::endl;

		ft::vector<float> test22(200, 23.22);
		std::cout << "##### creat test22 <FLOAT>(200, 23.22) #####\n";
		std::cout << "size test22 : " << test22.size() << std::endl;
		std::cout << "Capacity test22 : " << test22.capacity() << std::endl;

		ft::vector<std::string> test222(50, "myvector");
		std::cout << "##### creat test222 <STRING>(50, \"myvector\") #####\n";
		std::cout << "size test2 : " << test222.size() << std::endl;
		std::cout << "Capacity test2 : " << test222.capacity() << std::endl;

		std::cout << FOREGRN << "OK" << CL;
	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: Vis NOT Empty constructor! \n" << CL;
	}

	std::cout << "\n\n";
	
	std::cout << FOREBLU << "|||||||||| Not myne. Vis NOT Empty constructor_1:   ||||||||||||\n" << CL;
	try {
		std::vector<int> test2(100, 333);
		std::cout << "##### creat test2 <INT>(100, 333) #####\n";
		std::cout << "size test2 : " << test2.size() << std::endl;
		std::cout << "Capacity test2 : " << test2.capacity() << std::endl;

		std::vector<float> test22(200, 23.22);
		std::cout << "##### creat test22 <FLOAT>(200, 23.22) #####\n";
		std::cout << "size test22 : " << test22.size() << std::endl;
		std::cout << "Capacity test22 : " << test22.capacity() << std::endl;

		std::vector<std::string> test222(50, "myvector");
		std::cout << "##### creat test222 <STRING>(50, \"myvector\") #####\n";
		std::cout << "size test2 : " << test222.size() << std::endl;
		std::cout << "Capacity test2 : " << test222.capacity() << std::endl;

		std::cout << FOREGRN << "OK" << CL;
	}
	catch (...) {
		std::cout << FORERED <<  "Error Not myne: Vis NOT Empty constructor! \n" << CL;
	}
	std::cout << "\n\n";
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << BACKMAG << "Test 3______________________________________________________________________________________________" << CL << "\n\n";
	std::cout << FOREYEL << "|||||||||| My Vector. Print content  and use iterator:  |||||||||||\n" << CL;

	try {
		ft::vector<int> test3(100, 333);
		ft::vector<int>::iterator it1;
		for (it1 = test3.begin(); it1 != test3.end(); ++it1)
			std::cout << ' ' << *it1;
			std::cout << "\n\n";

		ft::vector<float> test33(200, 23.22);
		ft::vector<float>::iterator it2;
		for (it2 = test33.begin(); it2 != test33.end(); ++it2)
			std::cout << ' ' << *it2;
			std::cout << "\n\n";

		ft::vector<std::string> test333(50, "myvector");
		ft::vector<std::string>::iterator it3;
		for (it3 = test333.begin(); it3 != test333.end(); ++it3)
			std::cout << ' ' << *it3;
		std::cout << FOREGRN << "\nOK" << CL;
	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: Print content \n" << CL;
	}

	std::cout << "\n\n";
	
	std::cout << FOREBLU << "|||||||||| Not myne. Print content and use iterator :   ||||||||||||\n" << CL;
		try {
		std::vector<int> test3(100, 333);
		std::vector<int>::iterator it1;
		for (it1 = test3.begin(); it1 != test3.end(); ++it1)
			std::cout << ' ' << *it1;
			std::cout << "\n\n";

		std::vector<float> test33(200, 23.22);
		std::vector<float>::iterator it2;
		for (it2 = test33.begin(); it2 != test33.end(); ++it2)
			std::cout << ' ' << *it2;
			std::cout << "\n\n";

		std::vector<std::string> test333(50, "notmyne");
		std::vector<std::string>::iterator it3;
		for (it3 = test333.begin(); it3 != test333.end(); ++it3)
			std::cout << ' ' << *it3;
		std::cout << FOREGRN << "\nOK" << CL;
	}
	catch (...) {
		std::cout << FORERED <<  "Error Not myne: Print content \n" << CL;
	}

	std::cout << "\n\n";
	////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << BACKMAG << "Test 4______________________________________________________________________________________________" << CL << "\n\n";
	std::cout << FOREYEL << "|||||||||| My Vector. Copy cnstructor:  |||||||||||\n" << CL;

	try {
		std::cout << "##### creat test2 <INT> #####\n";
		ft::vector<int> test2(25, 333);
		std::cout << "size test2 : " << test2.size() << std::endl;
		std::cout << "Capacity test2 : " << test2.capacity() << std::endl;
		std::cout << "\n";

		std::cout << "#### print test2 ####\n";
		for (int i = 0; test2.begin() + i < test2.end(); i++)
			std::cout << ' ' << *(test2.begin() + i);
		std::cout << "\n\n";

		std::cout << "####### creat test4 and copy test2 in test4: #######\n";

		ft::vector<int> test4 (test2);
		std::cout << "size test4 : " << test4.size() << std::endl;
		std::cout << "Capacity test4 : " << test4.capacity() << std::endl;
		std::cout << "#### print test4 ####\n";
		for (int i = 0; test4.begin() + i < test4.end(); i++)
			std::cout << ' ' << *(test4.begin() + i);
		std::cout << "\n\n";

		std::cout << "##### creat test22 <STRING> #####\n";
		ft::vector<std::string> test22(25, "myvector");
		std::cout << "size test2 : " << test22.size() << std::endl;
		std::cout << "Capacity test2 : " << test22.capacity() << std::endl;
		std::cout << "\n";

		std::cout << "#### print test22 ####\n";
		for (int i = 0; test22.begin() + i < test22.end(); i++)
			std::cout << ' ' << *(test22.begin() + i);
		std::cout << "\n\n";

		std::cout << "####### creat test44 and copy test22 in test4: #######\n";

		ft::vector<std::string> test44 (test22);
		std::cout << "size test44 : " << test44.size() << std::endl;
		std::cout << "Capacity test4 : " << test44.capacity() << std::endl;
		std::cout << "#### print test4 ####\n";
		for (int i = 0; test44.begin() + i < test44.end(); i++)
			std::cout << ' ' << *(test44.begin() + i);
		std::cout << "\n";

		std::cout << FOREGRN << "OK" << CL;
	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: Copy constructor! \n" << CL;
	}

	std::cout << "\n\n";
	
	std::cout << FOREBLU << "|||||||||| Not myne. Copy cnstructor:   ||||||||||||\n" << CL;
	try {
		std::cout << "##### creat test2 <INT> #####\n";
		std::vector<int> test2(25, 333);
		std::cout << "size test2 : " << test2.size() << std::endl;
		std::cout << "Capacity test2 : " << test2.capacity() << std::endl;
		std::cout << "\n";

		std::cout << "#### print test2 ####\n";
		for (int i = 0; test2.begin() + i < test2.end(); i++)
			std::cout << ' ' << *(test2.begin() + i);
		std::cout << "\n\n";

		std::cout << "####### creat test4 and copy test2 in test4: #######\n";

		std::vector<int> test4 (test2);
		std::cout << "size test4 : " << test4.size() << std::endl;
		std::cout << "Capacity test4 : " << test4.capacity() << std::endl;
		std::cout << "#### print test4 ####\n";
		for (int i = 0; test4.begin() + i < test4.end(); i++)
			std::cout << ' ' << *(test4.begin() + i);
		std::cout << "\n\n";

		std::cout << "##### creat test22 <STRING> #####\n";
		std::vector<std::string> test22(25, "not myne");
		std::cout << "size test2 : " << test22.size() << std::endl;
		std::cout << "Capacity test2 : " << test22.capacity() << std::endl;
		std::cout << "\n";

		std::cout << "#### print test22 ####\n";
		for (int i = 0; test22.begin() + i < test22.end(); i++)
			std::cout << ' ' << *(test22.begin() + i);
		std::cout << "\n\n";

		std::cout << "####### creat test44 and copy test22 in test4: #######\n";

		std::vector<std::string> test44 (test22);
		std::cout << "size test44 : " << test44.size() << std::endl;
		std::cout << "Capacity test4 : " << test44.capacity() << std::endl;
		std::cout << "#### print test4 ####\n";
		for (int i = 0; test44.begin() + i < test44.end(); i++)
			std::cout << ' ' << *(test44.begin() + i);
		std::cout << "\n";

		std::cout << FOREGRN << "OK" << CL;
	}
	catch (...) {
		std::cout << FORERED <<  "Error Not myne: Copy constructor! \n" << CL;
	}
	std::cout << "\n\n";

	////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << BACKMAG << "Test 5______________________________________________________________________________________________" << CL << "\n\n";
	std::cout << FOREYEL << "|||||||||| My Vector. Operator = :  |||||||||||\n" << CL;

	try {
		std::cout << "##### creat test2 <INT> #####\n";
		ft::vector<int> test2(25, 333);
		std::cout << " size test2 : " << test2.size() << std::endl;
		std::cout << " Capacity test2 : " << test2.capacity() << std::endl;
		std::cout << "\n";

		std::cout << "#### print test2 ####\n";
		for (int i = 0; test2.begin() + i < test2.end(); i++)
			std::cout << ' ' << *(test2.begin() + i);
		std::cout << "\n\n";

		std::cout << "####### creat test4 and test4  =  test2: #######\n";

		ft::vector<int> test4 = test2;
		std::cout << " size test4 : " << test4.size() << std::endl;
		std::cout << " Capacity test4 : " << test4.capacity() << std::endl;
		std::cout << "#### print test4 ####\n";
		for (int i = 0; test4.begin() + i < test4.end(); i++)
			std::cout << ' ' << *(test4.begin() + i);
		std::cout << "\n\n";

		std::cout << "##### creat test22 <STRING> #####\n";
		ft::vector<std::string> test22(25, "myvector");
		std::cout << " size test2 : " << test22.size() << std::endl;
		std::cout << " Capacity test2 : " << test22.capacity() << std::endl;
		std::cout << "\n";

		std::cout << "#### print test22 ####\n";
		for (int i = 0; test22.begin() + i < test22.end(); i++)
			std::cout << ' ' << *(test22.begin() + i);
		std::cout << "\n\n";

		std::cout << "####### creat test44 and test44 = test22 : #######\n";

		ft::vector<std::string> test44 = test22;
		std::cout << " size test44 : " << test44.size() << std::endl;
		std::cout << " Capacity test4 : " << test44.capacity() << std::endl;
		std::cout << "#### print test4 ####\n";
		for (int i = 0; test44.begin() + i < test44.end(); i++)
			std::cout << ' ' << *(test44.begin() + i);
		std::cout << "\n";

		std::cout << FOREGRN << "OK" << CL;
	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: operator = ! \n" << CL;
	}

	std::cout << "\n\n";
	
	std::cout << FOREBLU << "|||||||||| Not myne. Operator = :   ||||||||||||\n" << CL;
	try {
		std::cout << "##### creat test2 <INT> #####\n";
		std::vector<int> test2(25, 333);
		std::cout << " size test2 : " << test2.size() << std::endl;
		std::cout << " Capacity test2 : " << test2.capacity() << std::endl;
		std::cout << "\n";

		std::cout << "#### print test2 ####\n";
		for (int i = 0; test2.begin() + i < test2.end(); i++)
			std::cout << ' ' << *(test2.begin() + i);
		std::cout << "\n\n";

		std::cout << "####### creat test4 and test4  =  test2: #######\n";

		std::vector<int> test4 = test2;
		std::cout << " size test4 : " << test4.size() << std::endl;
		std::cout << " Capacity test4 : " << test4.capacity() << std::endl;
		std::cout << "#### print test4 ####\n";
		for (int i = 0; test4.begin() + i < test4.end(); i++)
			std::cout << ' ' << *(test4.begin() + i);
		std::cout << "\n\n";

		std::cout << "##### creat test22 <STRING> #####\n";
		std::vector<std::string> test22(25, "myvector");
		std::cout << " size test2 : " << test22.size() << std::endl;
		std::cout << " Capacity test2 : " << test22.capacity() << std::endl;
		std::cout << "\n";

		std::cout << "#### print test22 ####\n";
		for (int i = 0; test22.begin() + i < test22.end(); i++)
			std::cout << ' ' << *(test22.begin() + i);
		std::cout << "\n\n";

		std::cout << "####### creat test44 and test44 = test22 : #######\n";

		std::vector<std::string> test44 = test22;
		std::cout << " size test44 : " << test44.size() << std::endl;
		std::cout << " Capacity test4 : " << test44.capacity() << std::endl;
		std::cout << "#### print test4 ####\n";
		for (int i = 0; test44.begin() + i < test44.end(); i++)
			std::cout << ' ' << *(test44.begin() + i);
		std::cout << "\n";

		std::cout << FOREGRN << "OK" << CL;
	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: operator = ! \n" << CL;
	}
	std::cout << "\n\n";

	////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << BACKMAG << "Test 6______________________________________________________________________________________________" << CL << "\n\n";
	std::cout << FOREYEL << "|||||||||| My Vector. func: resize() :  |||||||||||\n" << CL;
	try {
		std::cout << "#### creat test1 <INT> (34, 555) ####\n";
		ft::vector <int> test1(34, 555);
		std::cout << "#### print test4 ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n";
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		std::cout << "#### resize(135, 87) ####\n";
		test1.resize(35, 87);
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		std::cout << "#### print test4 ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n";
	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: resize() ! \n" << CL;
	}


	std::cout << FOREBLU << "|||||||||| Not myne. func: resize() :   ||||||||||||\n" << CL;

	try {
		std::cout << "#### creat test1 <INT> (34, 555) ####\n";
		std::vector <int> test1(34, 555);
		std::cout << "#### print test4 ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n";
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;

		std::cout << "#### resize(135, 87) ####\n";
		test1.resize(35, 87);
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		std::cout << "#### print test1 ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n";
	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: resize() ! \n" << CL;
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << BACKMAG << "Test 7______________________________________________________________________________________________" << CL << "\n\n";
	std::cout << FOREYEL << "|||||||||| My Vector. func: insert() :  |||||||||||\n" << CL;
	try {
		std::cout << "#### creat test1 <INT> (34, 555) ####\n";
		ft::vector <int> test1(30, 555);
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;

		ft::vector <int>::iterator it;
		std::cout << "#### creat iterator - it ####\n";
		std::cout << "#### print test1 ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n\n";

		std::cout << "#### run - iterator insert (it, 200); ####\n";
		it = test1.end();
		it = test1.insert(it, 200);
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		std::cout << "#### print test1 after iterator insert() ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n\n";

		test1.insert(it, 10, 300);
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		std::cout << "#### print test1 after insert() ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n\n";

		std::cout << "#### creat test2 <INT> (10, 77) ####\n";
		ft::vector <int> test2(10, 77);
		test1.insert(test1.begin() + 2, test2.begin(), test2.end());
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		std::cout << "#### print test1 after insert() test2 ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n\n";

		int myarray [] = { 501,502,503 };
		test1.insert (test1.begin(), myarray, myarray+3);
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n\n";

	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: insert() ! \n" << CL;
	}


	std::cout << FOREBLU << "|||||||||| Not myne. func: insert() :   ||||||||||||\n" << CL;

	try {
		std::cout << "#### creat test1 <INT> (34, 555) ####\n";
		std::vector <int> test1(30, 555);
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		std::vector <int>::iterator it;
		std::cout << "#### creat iterator - it ####\n";
		std::cout << "#### print test1 ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n\n";

		std::cout << "#### run - iterator insert (it, 200); ####\n";
		it = test1.end();
		it = test1.insert(it, 200);
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		std::cout << "#### print test1 after insert() ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n\n";

		test1.insert(it, 10, 300);
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		std::cout << "#### print test1 after insert() ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n\n";

		std::cout << "#### creat test2 <INT> (10, 77) ####\n";
		std::vector <int> test2(10, 77);
		test1.insert(test1.begin() + 2, test2.begin(), test2.end());
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		std::cout << "#### print test1 after insert() test2 ####\n";
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n\n";


		int myarray [] = { 501,502,503 };
		test1.insert (test1.begin(), myarray, myarray+3);
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		for (int i = 0; test1.begin() + i < test1.end(); i++)
			std::cout << ' ' << *(test1.begin() + i);
		std::cout << "\n\n";

	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: insert() ! \n" << CL;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << BACKMAG << "Test 8______________________________________________________________________________________________" << CL << "\n\n";
	std::cout << FOREYEL << "|||||||||| My Vector. func: at() :  |||||||||||\n" << CL;

	
	try {
		ft::vector<int> test1(10);
		for (unsigned i = 0; i < test1.size(); i++)
    		test1.at(i) = i;
	
		std::cout << "test1 contains: ";
		for (unsigned i = 0; i < test1.size(); i++)
			std::cout << ' ' << test1.at(i);
		std::cout << "\n\n";
	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: at() ! \n" << CL;
	}

	try {
		ft::vector<int> test1(10);
		std::cout << "#### test at() if out of range ####\n";
		test1.at(120);
	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: at() ! \n" << CL;
	}

	std::cout << FOREBLU << "|||||||||| Not myne. func: at() :   ||||||||||||\n" << CL;

	try {
		std::vector<int> test1(10);
		for (unsigned i = 0; i < test1.size(); i++)
    		test1.at(i) = i;
	
		std::cout << "test1 contains: ";
		for (unsigned i = 0; i < test1.size(); i++)
			std::cout << ' ' << test1.at(i);
		std::cout << "\n\n";
	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: at() ! \n" << CL;
	}

	try {
		ft::vector<int> test1(10);
		std::cout << "#### test at() if out of range ####\n";
		test1.at(120);
	}
	catch (...) {
		std::cout << FORERED <<  "Error MY VECTOR: at() ! \n" << CL;
	}
	std::cout << "\n\n";

	////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << BACKMAG << "Test 9______________________________________________________________________________________________" << CL << "\n\n";
	std::cout << FOREYEL << "|||||||||| My Vector. func: empty() :  |||||||||||\n" << CL;

	std::cout << "#### creat test1(13, 234) ####\n";
	ft::vector <int> test1(13, 234);
	std::cout << " size test1 : " << test1.size() << std::endl;

	std::cout << "vector is empty : " << test1.empty() << std::endl;

	std::cout << "#### clear test1 ####\n";
	test1.clear();
	std::cout << " size test1 : " << test1.size() << std::endl;

	std::cout << "vector is empty : " << test1.empty() << std::endl;

	std::cout << FOREBLU << "|||||||||| Not myne. func: empty() :   ||||||||||||\n" << CL;

	{
		std::cout << "#### creat test1(13, 234) ####\n";
	std::vector <int> test1(13, 234);
	std::cout << " size test1 : " << test1.size() << std::endl;

	std::cout << "vector is empty : " << test1.empty() << std::endl;

	std::cout << "#### clear test1 ####\n";
	test1.clear();
	std::cout << " size test1 : " << test1.size() << std::endl;

	std::cout << "vector is empty : " << test1.empty() << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << BACKMAG << "Test 10______________________________________________________________________________________________" << CL << "\n\n";
	std::cout << FOREYEL << "|||||||||| My Vector. func: erase() :  |||||||||||\n" << CL;

	{
		ft::vector <int> test1 (10);

		for (unsigned i  = 0; i < test1.size(); i++) {
			test1[i] = i;
			std::cout << " " << test1[i];
		}
		std::cout << '\n';

		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;

		std::cout << "iterator after erase  one element : " << *test1.erase(test1.begin()+2) << std::endl;
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;

		for (unsigned i  = 0; i < test1.size(); i++) {
			std::cout << " " << test1[i];
		}
		std::cout << '\n';

		std::cout << "iterator after erase  three elements : " << *test1.erase(test1.begin(), test1.begin() + 3) << std::endl;
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		for (unsigned i  = 0; i < test1.size(); i++) {
			std::cout << " " << test1[i];
		}
		std::cout << '\n';

		std::cout << "iterator after erase  all elements : " << *test1.erase(test1.begin(), test1.end()) << std::endl;
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		for (unsigned i  = 0; i < test1.size(); i++) {
			std::cout << " " << test1[i];
		}
		std::cout << '\n';


		std::cout << "iterator after erase  empty vector : " << *test1.erase(test1.begin(), test1.end() + 3) << std::endl;
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		for (unsigned i  = 0; i < test1.size(); i++) {
			std::cout << " " << test1[i];
		}
		std::cout << '\n';


	}

	std::cout << FOREBLU << "|||||||||| Not myne. func: erase() :   ||||||||||||\n" << CL;

	{
		std::vector <int> test1 (10);

		for (unsigned i  = 0; i < test1.size(); i++) {
			test1[i] = i;
			std::cout << " " << test1[i];
		}
		std::cout << '\n';

		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;

		std::cout << "iterator after erase  one element : " << *test1.erase(test1.begin()+2) << std::endl;
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		for (unsigned i  = 0; i < test1.size(); i++) {
			std::cout << " " << test1[i];
		}
		std::cout << '\n';

		std::cout << "iterator after erase  three elements : " << *test1.erase(test1.begin(), test1.begin() + 3) << std::endl;
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		for (unsigned i  = 0; i < test1.size(); i++) {
			std::cout << " " << test1[i];
		}
		std::cout << '\n';

		std::cout << "iterator after erase  all elements : " << *test1.erase(test1.begin(), test1.end()) << std::endl;
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		for (unsigned i  = 0; i < test1.size(); i++) {
			std::cout << " " << test1[i];
		}
		std::cout << '\n';

		std::cout << "iterator after erase  empty vector : " << *test1.erase(test1.begin(), test1.end()) << std::endl;
		std::cout << " size test1 : " << test1.size() << std::endl;
		std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		for (unsigned i  = 0; i < test1.size(); i++) {
			std::cout << " " << test1[i];
		}
		std::cout << '\n';
	}


	std::cout << BACKMAG << "Test 11______________________________________________________________________________________________" << CL << "\n\n";
		std::cout << FOREYEL << "|||||||||| My Vector. func: assign() :  |||||||||||\n" << CL;
		{
			ft::vector <int> test1(10, 567);
			ft::vector <int> test2(30, 888);

			test2.assign(test1.begin() + 1, test1.end());
			std::cout << " size test2 : " << test2.size() << std::endl;
			std::cout << " Capacity test2 : " << test2.capacity() << std::endl;
			for (unsigned i  = 0; i < test1.size(); i++) {
				std::cout << " " << test1[i];
			}
			std::cout << '\n';

			test1.assign(4, 34);
			std::cout << " size test2 : " << test1.size() << std::endl;
			std::cout << " Capacity test2 : " << test1.capacity() << std::endl;
			for (unsigned i  = 0; i < test1.size(); i++) {
				std::cout << " " << test1[i];
			}
			std::cout << '\n';
		}

		std::cout << FOREBLU << "|||||||||| Not myne. func: assign() :   ||||||||||||\n" << CL;
		{
			std::vector <int> test1(10, 567);
			std::vector <int> test2(30, 888);

			test2.assign(test1.begin() + 1, test1.end());

			std::cout << " size test2 : " << test2.size() << std::endl;
			std::cout << " Capacity test2 : " << test2.capacity() << std::endl;
			for (unsigned i  = 0; i < test1.size(); i++) {
				std::cout << " " << test1[i];
			}

			std::cout << '\n';

			test1.assign(4, 34);
			std::cout << " size test2 : " << test1.size() << std::endl;
			std::cout << " Capacity test2 : " << test1.capacity() << std::endl;
			for (unsigned i  = 0; i < test1.size(); i++) {
				std::cout << " " << test1[i];
			}
			std::cout << '\n';
		}

		std::cout << BACKMAG << "Test 12______________________________________________________________________________________________" << CL << "\n\n";
		std::cout << FOREYEL << "|||||||||| My Vector. func: get_allocator() :  |||||||||||\n" << CL;

		{
			ft::vector<int> myvector;
  			int * p;
  			unsigned int i;

  			p = myvector.get_allocator().allocate(5);

  			for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  			std::cout << "The allocated array contains:";
  			for (i=0; i<5; i++) std::cout << ' ' << p[i];
  			std::cout << '\n';

  			for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  			myvector.get_allocator().deallocate(p,5);
		}
		std::cout << FOREBLU << "|||||||||| Not myne. func: get_allocator() :   ||||||||||||\n" << CL;
		{
			std::vector<int> myvector;
  			int * p;
  			unsigned int i;

  			p = myvector.get_allocator().allocate(5);

  			for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  			std::cout << "The allocated array contains:";
  			for (i=0; i<5; i++) std::cout << ' ' << p[i];
  			std::cout << '\n';

  			for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  			myvector.get_allocator().deallocate(p,5);
		}

		std::cout << BACKMAG << "Test 13______________________________________________________________________________________________" << CL << "\n\n";
		std::cout << FOREYEL << "|||||||||| My Vector. func: push_back() :  |||||||||||\n" << CL;

		{
			ft::vector<int> test1;

			for (unsigned i = 0; i < 10; i++) {
				test1.push_back(i);
			}

			std::cout << " size test1 : " << test1.size() << std::endl;
			std::cout << " Capacity test1 : " << test1.capacity() << std::endl;

			for (unsigned i  = 0; i < test1.size(); i++) {
				std::cout << " " << test1[i];
			}
			std::cout << '\n';


			for (int i = 0; i < (5500); ++i)
				test1.push_back(i);
			std::cout << " size test1 : " << test1.size() << std::endl;
			std::cout << " Capacity test1 : " << test1.capacity() << std::endl;

		}

		std::cout << FOREBLU << "|||||||||| Not myne. func: push_back() :   ||||||||||||\n" << CL;
		{
			std::vector<int> test1;

			for (unsigned i = 0; i < 10; i++) {
				test1.push_back(i);
			}

			std::cout << " size test1 : " << test1.size() << std::endl;
			std::cout << " Capacity test1 : " << test1.capacity() << std::endl;

			for (unsigned i  = 0; i < test1.size(); i++) {
				std::cout << " " << test1[i];
			}
			std::cout << '\n';

			for (int i = 0; i < (5500); ++i)
				test1.push_back(i);
			std::cout << " size test1 : " << test1.size() << std::endl;
			std::cout << " Capacity test1 : " << test1.capacity() << std::endl;
		}

		std::cout << BACKMAG << "Test 13______________________________________________________________________________________________" << CL << "\n\n";
		std::cout << FOREYEL << "|||||||||| My Vector. func: pop_back() :  |||||||||||\n" << CL;
		{
			ft::vector<int> myvector;
			int sum (0);
			myvector.push_back (100);
			myvector.push_back (200);
			myvector.push_back (300);

			while (!myvector.empty())
			{
				sum+=myvector.back();
				myvector.pop_back();
			}

			std::cout << "The elements of myvector add up to " << sum << '\n';
		}
		std::cout << FOREBLU << "|||||||||| Not myne. func: pop_back() :   ||||||||||||\n" << CL;
		{
			std::vector<int> myvector;
			int sum (0);
			myvector.push_back (100);
			myvector.push_back (200);
			myvector.push_back (300);

			while (!myvector.empty())
			{
				sum+=myvector.back();
				myvector.pop_back();
			}

			std::cout << "The elements of myvector add up to " << sum << '\n';
		}

		std::cout << BACKMAG << "Test 14______________________________________________________________________________________________" << CL << "\n\n";
		std::cout << FOREYEL << "|||||||||| My Vector. func: swap() :  |||||||||||\n" << CL;

		{
			ft::vector<int> foo (3,100);   // three ints with a value of 100
			ft::vector<int> bar (5,200);   // five ints with a value of 200

			foo.swap(bar);

			std::cout << "foo contains:";
			for (unsigned i=0; i<foo.size(); i++)
				std::cout << ' ' << foo[i];
			std::cout << '\n';

			std::cout << "bar contains:";
			for (unsigned i=0; i<bar.size(); i++)
				std::cout << ' ' << bar[i];
			std::cout << '\n';
		}
		std::cout << FOREBLU << "|||||||||| Not myne. func: swap() :   ||||||||||||\n" << CL;
		{
			std::vector<int> foo (3,100);   // three ints with a value of 100
			std::vector<int> bar (5,200);   // five ints with a value of 200

			foo.swap(bar);

			std::cout << "foo contains:";
			for (unsigned i=0; i<foo.size(); i++)
				std::cout << ' ' << foo[i];
			std::cout << '\n';

			std::cout << "bar contains:";
			for (unsigned i=0; i<bar.size(); i++)
				std::cout << ' ' << bar[i];
			std::cout << '\n';
		}


		{
			int foo[]={10,20,5,15,25};
			int bar[]={15,10,20};
			std::sort (foo, foo+5, std::less<float>());  // 5 10 15 20 25
			std::sort (bar, bar+3, std::less<int>());  //   10 15 20
			if (std::includes (foo, foo+5, bar, bar+3, std::less<int>()))
				std::cout << "foo includes bar.\n\n";
			for (int i = 0; i < 5; ++i)
				std::cout << foo[i] << ' ';
		}

	return (0);
}