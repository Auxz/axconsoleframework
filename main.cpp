#include <iostream>
#include "menu.hpp"
 // File used for testing the library

 int doSomeSomething(int a, int b) {return a+b;}
int main() {

  Option test_option = Option(1,"Option 1", "Desc", true, true);
  test_option.execute = [&]{
    std::cout << test_option.m_description << std::endl;
  }; // Testing out lambda functions to automatically execute when option is selected.
  
  
}