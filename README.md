**Where did these examples come from?**
I just printed out the whole site of: en.cppreference.com.  

**Well, maybe you ask why am I doing this stupid work?**  

**First** I needed to learn English language, **second** I needed to learn 10-finger-type  
and **third** I liked learning programming. So I do all three of them together. And I  
typed these examples to improve my EN language and TYPING and C++ programming.  

**I tested all these examples with this command-line argument:**  
`g++ -std=c++14 -O2 -Wall -pedantic -pthread`

*On Gnu / Ubuntu 16.01 LTS and code::blocks IDE 16.01 (32 bit)*

If you are confusing with my examples, I apologize to you.
  
**You can see the major reference sites:**  
    :one: en.cppreference.com
    :two: cplusplus.com  
    :three: msdn.microsoft.com  


![Image of codeblock](https://github.com/k-five/1000_examples_with_cpp/blob/master/logo_codeblocks.png)


# how many way do you know for "hello world" in C++?
```C++
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
```

**output**

`
1:	hello world!

2:	hello world!

3:	hello world!

4:	hello world!

5:	hello world!

6:	hello world!

7:	hello world!

8:	hello world!

`