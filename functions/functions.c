/* functions in C 
 *
/* The program show a simple illustration of functions in C language. C has exponential function like the fortran(**) and, we can write our functions as programmers. Functions provide easy, convinient and efficient way to write code, with properly designed functions it is possiblw to ignore how the job is done, knowing whats done is efficient.
 *
 * A function definition has this form:
 *
 * return-type function-name(parameters declaration, if any)
 * {
 *
 *  declarations;
 *  statements;
 *
 * }
 *
 * Arguments to the function can either be passed by value or reference. Both called by value or reference have certain effects on variables they acting upon.
 * Called by reference has an implementation slightly different in syntax with called by value as it involves pointers and dereferrencing operands acting on the variables.
*/



#include<stdio.h>


/* A test of the power function
 *
 *
 * int power(int m, int n) 
 *
 */
 
int intergerPower(int base, int exponent)

{

 int result = 1;

 for(int v = 0; v < exponent; v++)
  
 {
	 result *= base;
 }

     return result;
  

}

/* A function definition can appear in any order, and in one source file or several, although no function can be split between files. If the source file appearsseverals file, we have to say more to compile and load it than if it it all appears in one.
 *
 *The function intergerPower() is called twice by main, in the line;

 printf("%d %d %d\n", i, intergerPower(2, i), intergerPower(-3, i));

 Each call passes arguments to intergerPower, which each time returns an interger to be formatted and printed. Not all functions return produce interger values.
 *
 *int intergerPower(int base, int exponent);

 declares the parameter types and names, and the type of the result that the function returns. The names used by intergerPower for its parameters are local to intergerPower, and are not visible to any other function: other routines can use the same names without conflict. This is als true of the variables i and result:the the v in the intergerPower is unrelated to the i in the main.

 The value that intergerPower computes is returned to main by the return: any expression may follow return:
 
return expression;

A function need not return a value; a return statement with no expression causes control, but no useful value, to be return to the caller, as does"falling off the end" of function by  reaching the terminating right brace. And the calling function can ignore a value returned by a function.

The declaration;

int intergerPower(int base, int exponent);
is called a function prototype, and it is not necessary to have one if the function definition appears before any calls to the function. But if the function definition appears after any call to the function, then a prototype is needed to tell the compiler about the type of the result and the types of the arguments. The prototype can be in a separate file, and included by several source files, so that they can all call the same function without having to repeat its definition.
It is an error if the definition of a function or any uses of it do not agree with its prototype. The compiler can check for such errors, and it is a good idea to use prototype.

Parameter names need not to gree .Indeed , parameter names are optional in a function protoype, so for the prototype we could have written;

int intergerPower(int, int);
Well-chosen named are good documentaion however, and it is a good idea to use them in prototypes as well as definitions. The names of parameters in a prototype are not part of the function's interface, and they are not used by the compiler to check for consistency between the prototype and the definition. But they can be used by programmers to understand what the function does and how to use it.
So we will often use them.

EXERCISE: REWRITE THE TEMPERATURE CONVERSION PROGRAM OF SECTION 1.2 TO USE A FUNCTION TO CONVERT TEMPERATURES FROM FAHRENHEIT TO CELSIUS. THE FORMULA FOR THE CONVERSION IS C = (5/9) * (F - 32).




 * */




int main ()

{ 
   
 int i;
 

 for(i = 0; i < 10; i++)
 
 {

	   printf("%d %d %d\n", i, intergerPower(2, i), intergerPower(-3, i));

 }
 
		  return 0;

}


/*ARGUMENT - CALL BY VALUE

One aspect of a C functions is that all arguments are passed by value.
This meaans that  the called function is given the values of its arguments in temporary variables rather than the originals. This leads to  some different peoperties
than are seen with called by reference, which is used in some other languages.
In particular, the called function cannot change the value of an argument in the calling function,  and it cannot even tell whether the argument is a variable or a constant. 
The called function can only use the values of its arguments to compute its result, and it can only return a value to the caller by using the return statement.

Call by value is an sssert not a liability. Its leads to more compact programs with fewer extranneous variables, because parameters can be treated as conveniently initilized local variables in the called function.
For example, the parameters base and exponent in intergerPower are initialized by the caller, and they can be used directly in the body of intergerPower without any extra code to copy them into local variables.

intergerPower: raise bse to n-th power; n >= 0

int intergerPower(int base, int n)
{

int p;

for (p = 1; n > 0; --n)
p = p * base;
return p;

}

The parameter n is being used as a local or temporary variable in intergerPower, and it is being modified by the loop. This is possible because n is a copy of the argument passed by the caller, and it does not affect the original argument in the caller.
When neccessary, we can use call by reference in C by passing pointers to the arguments, and using dereferencing to access the original variables in the caller. This allows the called function to modify the values of the arguments in the caller, and it can also allow the called function to return multiple values to the caller by modifying multiple variables through pointers. However, this is more complex than call by value, and it is not always necessary or desirable to use call by reference in C.
The caller must provide the adddress of the variable to be set(technically a pointer to the variable), and the called function must declare the parameter to be a pointer and acces the variable indirectly through it.
*/

