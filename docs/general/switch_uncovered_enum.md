
```c++
// Compile with `clang++ main.cpp -o a.out -Wcovered-switch-default`

#include <iostream>
#include <cassert>

enum class Kind{
	A,
	B,
	C
};

int main(){
  Kind t{Kind::A};	

  switch(t){
	  case Kind::A: std::cout<< "A"; break; 
	  case Kind::B: std::cout<< "B"; break; 
         // default: assert(false && "case not covered"); break;			
  };

  return 0;
}
```
