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
 * Called by reference has an implementation slightly different in syntax with called by value as it involved pointers and deferencing operands acting on the variables.
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

int main ()

{ 
   
 int i;
 

 for(i = 0; i < 10; i++)
 
 {

	   printf("%d %d %d\n", i, intergerPower(2, i), intergerPower(-3, i));

 }
 
		  return 0;

}


