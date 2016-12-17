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


compiler:

![my compiler](https://github.com/k-five/1000_examples_with_cpp/blob/master/codeblocks.png)

operating system:

![my OS](https://github.com/k-five/1000_examples_with_cpp/blob/master/os.png)



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

```c++
1:	hello world!
2:	hello world!
3:	hello world!
4:	hello world!
5:	hello world!
6:	hello world!
7:	hello world!
8:	hello world!

```

# How about obfuscation a code?
```C++
#include                         <iostream>
#include                          <sstream>
#define                            HW(...)\
std::cout<<"1:\t"<<#__VA_ARGS__<<std::endl;
int main(){HW(hello world!);std::cout<<""""
"2:\thello world!"<<std::endl;std::operator
<<(std::cout,"3:\thello world!")<<(std::endl
);endl(std::cout<<"4:\thello world!");std::
                  cout
                .put('5')
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
for(const char* hw("6:\thello world!\n");*hw!=
'\0';std::cout<<*hw++);[]{std::cout<<"7:\the"
  "llo world!\n";}();std::istringstream("8:"
   "\thello world!\n")>>std::cout.rdbuf();}
```
**output**

`the same as above`



.
├── [00_Language](https://github.com/k-five/1000_examples_with_cpp/tree/master/Language)
│   ├── [01_preprocessor](https://github.com/k-five/1000_examples_with_cpp/tree/master/Language/01_preprocessor)
│   ├── [02_expression](https://github.com/k-five/1000_examples_with_cpp/tree/master/Language/02_expression)
│   ├── [03_declaration](https://github.com/k-five/1000_examples_with_cpp/tree/master/Language/03_declaration)
│   ├── [04_initialization](https://github.com/k-five/1000_examples_with_cpp/tree/master/Language/04_initialization)
│   ├── [05_function](https://github.com/k-five/1000_examples_with_cpp/tree/master/Language/05_function)
│   ├── [06_classes](https://github.com/k-five/1000_examples_with_cpp/tree/master/Language/06_classes)
│   ├── [07_template](https://github.com/k-five/1000_examples_with_cpp/tree/master/Language/07_template)
│   ├── [08_exception](https://github.com/k-five/1000_examples_with_cpp/tree/master/Language/08_exception)
│   ├── [09_statement](https://github.com/k-five/1000_examples_with_cpp/tree/master/Language/09_statement)
│   └── [10_miscellaneous](https://github.com/k-five/1000_examples_with_cpp/tree/master/Language/10_miscellaneous)
├── [01_Inout_Output_Library]()
│   ├── [03_basic_streambuf]()
│   │   └── [protected_member]()
│   ├── [04_basic_istream]()
│   ├── [05_basic_ostream]()
│   ├── [06_basic_iostream]()
│   ├── [07_basic_filebuf]()
│   ├── [08_basic_ifstream]()
│   ├── [09_basic_ofstream]()
│   ├── [10_basic_fstream]()
│   ├── [11_basic_stringbuf]()
│   ├── [12_basic_istringstream]()
│   ├── [13_basic_ostringstream]()
│   ├── [14_basic_stringstream]()
│   ├── [basic_ios]()
│   ├── [I_O_manipulators]()
│   └── [ios_base]()
├── [02_String_Library]()
│   ├── [null_terminated_string]()
│   └── [std_basic_string]()
├── [03_Container]()
│   ├── [01_std_array]()
│   ├── [02_std_deque]()
│   ├── [03_std_vector]()
│   ├── [04_std_list]()
│   ├── [05_std_forward_list]()
│   ├── [06_std_set]()
│   ├── [07_std_multiset]()
│   └── [08_std_map]()
├── [04_Algorithm_library]()
├── [05_Iterator_Library]()
├── [06_Regex_Library]()
├── [07_Type_Support]()
├── [08_Dynamic_Memory_Management]()
├── [09_Error_Handling]()
├── [10_Initializer_List]()
├── [11_Varisdic_Function]()
├── [12_Program_Utility]()
├── [13_Date_and_Time]()
├── [14_Bitset]()
├── [15_Function_Object]()
└── [helpful]()

[53]() directories
