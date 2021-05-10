# autograder-ziwei_wu

For my 4 hours I did the following:
- Read the paper and to understand the idea and how the authors implemented it in Sketch.
- Downloaded the Sketch source, built it, and tested it to see how it works.
- test.sk and add_to_equal_14.sk contains some code I tested with. **add_to_equal_14.cpp** and **add_to_equal_14.h** is the output of the Sketch program with the flag **--fe-output-code**. The synthesized program is outputted as C++ code.
- "deriv_ret_example.sk" and its .cpp and .h tries to solve for a single thing: what to return if the input polynomial array has the length of 1?
- figure_4.sk and its C++ files solve for the MPY program in figure 4. Currently, it only tests for the input [1,2,3,4,5]. The reason is because it is tested alongside with something like [4] as well, it becomes unsolvable.

The reason it becomes unsolvable is because of the below snippet. (Don't )

```
Array computeDeriv(Array poly){//example where we don't know what is wrong  
    Array deriv = new Array(sz = 0, A = {});  
    int zero = 0;  
    if(boolOrFalse(poly.sz == 1)){  
        **return modRetVal0(deriv);**  
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
    **return modRetVal0(possibleArray);**  
}  
  
Array modRetVal0(Array a){  
    if(??){  
        return a;  
    }  
    return new Array(sz = 1, A = {0});  
}  
```

As seen above, there are two places that use **modRetVal(Array);**
If the input is [1,2,3,4,5], the ?? in modRetVal has to equal 1 (true). If the input is [4] and the return statement is incorrect (which, in this case, is true), the ?? in modRetVal has to be 0 (false). Since it cannot be both 0 and 1 at the same time, it becomes unsolvable when trying to use both as inputs.
