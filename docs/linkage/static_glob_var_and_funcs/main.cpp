#include <iostream>

// Extern marks tha the global variable will not be defined here in this pount but can be available somewhere else
extern int globalVar1;
extern int globalVar2;
extern int globalVar3;

// Declaration of a function without its body is by default extern.
void globalFunction1();
void globalFunction2();
void globalFunction3();

int main(){
  globalVar1 = 2; // Ok.
  globalVar2 = 2; // Link error.
  globalVar3 = 2; // Link error.

  globalFunction1(); // Ok.
  globalFunction2(); // Link error.
  globalFunction3(); // Link error.
}

