/*

A review of abstraction section from cplusplus.com

*/

/// ios_base::openmode
//
//  Type of stream opening mode flags
//  A value of this type can be any valid combination of the following member constants:
//  member      opening mode
//  app         (append)    Set the stream's position indicator to the end of the stream before each output operation.
//  ate         (at end)    Set the stream's position indicator to the end of the stream on opening.
//  binary      (binary)    Consider stream as binary rather than text.
//  in          (input)     Allow input operations on the stream.
//  out         (output)    Allow output operations on the stream.
//  trunc       (truncate)  Any current content is discarded, assuming a length of zero on opening.








#include <iostream> // std::cout, std::ios
#include <fstream>

int main(){

    std::cout << std::ifstream( "file", std::ios_base::ate ).tellg();




}
/**
221
Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.





**/
