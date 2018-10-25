When you want to generate a string from a class enum, you have two options:
1) data-based: map between the values and string, and assert on the default case.
2) code-based: switch on its values. More verbose but can offer compile-time warning about missing mappings.

The following aspects have to be considered to pick one:
1) Maintainability, not only which one is easier to update, but which one is more difficult to udpate incorrectly.
2) Time-efficiency, 

In the general case both should have the same kind of efficiency, unless you absolutely don't want to pay the cost of constructing a map.

If this `KindToString` is in the critical path you might consider taking the code-based approach, as every entry will be resolved in O(1) instead of O(logn).

The data-based solution is more concise and elegant. If the data comes from another source (file, network) then it would be the only viable choice.

```c++
#include <iostream>
#include <cassert>
#include <map>

enum class Kind{ A, B, C };

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
  std::cout << ToString(t);
  return 0;
}
```

If you want to get the compile-time warning, you have to use the flag `-Wcovered-switch-default` and make sure that the default case is not specified - otherwise the warning will not trigger, and you will be back to a runtime assert -.

```c++
#include <iostream>
#include <cassert>

enum class Kind{ A, B, C };

std::string ToString(Kind k){
  switch(k){
	  case Kind::A: return "A"; 
	  case Kind::B: return "B"; 
      // default: assert(false && "case not covered"); 			
  };    
}

int main(){
  Kind t{Kind::A};	
  std::cout << ToString(t);
  return 0;
}
```
