When you want to generate a string from a class enum, you have two options:
1) data-based: map between the values and string, and assert on the default case.
2) code-based: switch on its values. More verbose but can offer compile-time warning about missing mappings.

```c++
#include <iostream>
#include <cassert>
#include <map>

enum class Kind{
	A,
	B,
	C
};

namespace{
// Non-const global variable has external linkage by default. Use anonymous namespace to make it internal.
std::map<Kind,std::string> KindToString{{Kind::A,"A"}, {Kind::B, "B"}};
}

std::string ToString(Kind k){
    const auto it = KindToString.find(k);
    assert(it != KindToString.cend() && "case not covered");
    return it->second;
}

int main(){
  Kind t{Kind::A};	

  std::cout<< ToString(t);

  return 0;
}
```

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
