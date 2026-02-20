#include <stdio.h>

/*From the book K&R the first version of the copy input to output; 1st Version
NB: putchar and printf function are interleaved; more note coming here
*/

int main() {
    
    int c;

    c = getchar();

    while(c != EOF) {
        /* The != sign means "not equal to" */
        putchar(c);

        c = getchar();
    
    }

    return 0;
}