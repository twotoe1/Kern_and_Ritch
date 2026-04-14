/*This chapter focuses on variables and their scope, in Cprograms and variable memory allocation.
I will use the previous example from the character_array to illustrate how external variables are used.

There are local(automatic) and external variables, local variables are declared or exist within a function definition,
they can not be accessed from outside the functiion unlike external variables. Each local variable in a function comes
into existence only when the function is called, and disappears when the function is exited.
This is why such variables are known as automatic variables, following terminologgy in other languages

Because automatic variables comes and go witth function invocation, they do not retain their values from one call to the next,
and must be explicitly set upon each entry. If they are not they will contain garbage

AS an alternative to automatic variables, it is possible to define variables that are external to all function, that is,
variables that can be accessed by name by any function.(This mechanism, is rather  like fortran COMMON, Pascal variables declared in the outermost block)
Because external variables are globally accessible, they can be used instead of argument lists to communicate data between functions.
Furthermore,because external variables remain in existence permanently, rather than appearing and disappearing as the functions are called
and exited, they retain thier values even function thst set them have returned. 

An external variable must be defined, exactly oonce, outside of any function; this sets aside storage for it. The variable must also be declred in each
function that wants to access it.; this states the type of the variable. The declaration may be an explicit extern statement or may be implicit
from context. To make the discusssion concrete, will rewrite  the longest-line program with line, longest, and max as external variables.
This requires changing the calls, declarations, and bodies of all functions.*/

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int max; /* maximum length seen so far */
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */

int my_getline(void);
void copy(void);

/* print the longest line; specialzed version*/

int main() {


    int len; /* current line lenghth */
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = my_getline()))
    {
        if (len > max) {
            max = len;
            copy();
        }
    }

    if (max > 0) {
        printf("%s", longest);

        return 0;
    }
    
}

/*getline: specialized version of getline */

int my_getline(void) {

    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE -1 && (c = getchar()) != EOF && c !='\n'; i++)
    line[i] = c;
    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;

}

/*copy: specialized version of copy */
void copy(void) {
    extern char line[], longest[];
    int i;
    while ((longest[i] = line[i]) != '\0');
        i++;
}