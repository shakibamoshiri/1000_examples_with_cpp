// how many way do you know for "hello world" in C++?
#include <iostream>
#include <sstream>
#define HW(...) std::cout<<"1:\t"<<#__VA_ARGS__<<std::endl;

int main(){

	HW(hello world!);

	std::cout<<"2:\thello world!"<<std::endl;

	std::operator<<(std::cout,"3:\thello world!")<<(std::endl);

	endl(std::cout<<"4:\thello world!");

	std::cout.put('5')
	         .put(':')
			 .put('\t')
			 .put('h')
			 .put('e')
			 .put('l')
			 .put('l')
			 .put('o')
			 .put(' ')
			 .put('w')
			 .put('o')
			 .put('r')
			 .put('l')
			 .put('d')
			 .put('!')
			 .put('\n');

	for(const char* hw("6:\thello world!\n");
		*hw!='\0';
		std::cout<<*hw++);

	[]{std::cout<<"7:\thello world!\n";}();

	std::istringstream("8:\thello world!\n")>>std::cout.rdbuf();
}
