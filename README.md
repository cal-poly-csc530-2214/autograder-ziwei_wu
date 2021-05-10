# autograder-ziwei_wu

For my 4 hours I did the following:
- Read the paper and to understand the idea and how the authors implemented it in Sketch.
- Downloaded the Sketch source, built it, and tested it to see how it works.
- test.sk and add_to_equal_14.sk contains some code I tested with. **add_to_equal_14.cpp** and **add_to_equal_14.h** is the output of the Sketch program with the flag **--fe-output-code**. The synthesized program is outputted as C++ code.
- **deriv_ret_example.sk** and its .cpp and .h files solves a single thing: what to return if the input polynomial array has the length of 1? The other parts of the program is correct.
- **figure_4.sk** and its C++ files solve for the MPY program in figure 4 (translated into Sketch). Currently, it only generates a program for the given input Array that contains [1,2,3,4,5]. The reason is because if something like [4] is an input as well, it becomes unsolvable. 
- Note: Array is a struct that contains: an integer representing the array length (named sz) and an integer array of length sz (named A).

The reason it becomes unsolvable is because of the below snippet.

```
Array computeDeriv(Array poly){//example where we don't know what is wrong  
    Array deriv = new Array(sz = 0, A = {});  
    int zero = 0;  
    if(boolOrFalse(poly.sz == 1)){  
        return modRetVal0(deriv);
    }  
    int start_index = intOrPlusOne(0);  
    int arrSize = poly.sz - start_index;  
    int[arrSize] tempArr;  
    for(int e = start_index; e < poly.sz; ++e){  
        if(boolOrFalse(poly.A[e] ==0)){  
            zero = zero + 1;  
        }  
        else{  
            tempArr[e-start_index] = poly.A[e] * e;  
        }  
    }  
    Array possibleArray = new Array(sz = arrSize, A = tempArr);  
    return modRetVal0(possibleArray);  
}  
  
Array modRetVal0(Array a){  
    if(??){  
        return a;  
    }  
    return new Array(sz = 1, A = {0});  
}  
```

As seen above, there are two places that use **modRetVal(...);** in **computeDeriv(...)** : below the first if-statement and at the end.
If the input (poly) contains [1,2,3,4,5], the ?? in modRetVal has to equal 1 (true). If the input contains [4] and the return statement is incorrect (which, in this case, is), the ?? in modRetVal has to be 0 (false). Since it cannot be both 0 and 1 at the same time, it becomes unsolvable when trying to use both as inputs.  
I tried to stick as close to the code in the paper as possible and assumed that similar modifications to the program use the same function call for solving. But now that I think about it, that wouldn't make sense as some bools or ints would need to be different. Oh well.


Other notes:
- For **deriv_ret_example.sk** and **figure_4.sk**:
  - computeDeric_list_int(...) is the correct program used for assertions
  - computeDeriv(...) is a student program/ program with things incorrect
  - The functions that have if(??){return a} in them represent the bracketed lists in MPY, where the input(a) is the default choice.
