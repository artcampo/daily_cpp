
// Global variable is visible by default (has external linkage).
int globalVar1;
// Global variable marked with static has internal linkage.
static int globalVar2;
// Global variable in unnamed namespace has internal linkage.
namespace { int globalVar3; }

// Global function has external linkage by default.
void globalFunction1(){}
// Global function with static has internal linkage.
static void globalFunction2(){}
// Global function in unnamed namespace has internal linkage.
namespace { void globalFunction3(){} }
