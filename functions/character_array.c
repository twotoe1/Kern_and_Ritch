

/*The most common common type of array in C is the characters. We can use character arrays and functions to manipulate a string of characters
Here is an example of a character array and a function that prints the longest lines in a file

pseudo code

while (there's another line)
if (it's longer than the previous longest)
save it
save its length
print the longest line and its length

This outline  makes it clear that the program divides naturally into  pieces. One piece gets a new line , another saves it,
and rest controls the  processs.
Accordingly let's write a seperate function gettline() to fetch the next line of input. At the minimum get a line has to return a signal about possible end of file;
a more useful design would be return the length of the line, or zero if end of file is encountered. Zero is accepteable end-of-file return because it is never a valid line length 1

When we find a line longer than the previous longest, it must be saved somewhere, this suggest a swccond function , copy() to copy the new line to a safe place.

NOTE; I will try to simulate the same functionality using pointers, one of most powerful concept that comes with C language. Pointers are a powerful tool in hand for a programmer, with pointers
programmers are able to write effecient and more robust code or programs. Will also try to use this as an exercide to understanding memory management.
In future exercises i will try to go over all the illustrations on this book perhaps let the project for the future learners, workout on different versions of the programs themselves.
*/
 #include<stdio.h>
 #define MAXLINE 1000 /* maximum input line size */

 int getline(char line[], int maxline);
 void copy(char to[], char from[]);

 /*print the longest input line */

 int main() {

    int  len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = getline) > 0) {
        if  (len > max) {
            max = len;
            copy(longest, line);
        }
        
        if (max > 0) { /* there was a line */
            printf("%s", longest);
            return 0;
        }


    }
}

    /*getline; read a line into s, retuen length */

    int getline(char s[], int lim) {

        int c, i;

        for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
            s[i] = c;
        if (c == '\n') {
            s[i] = c;
            ++i;
        }
        s[i] = '\0';
        return i;

        }

    /*copy; copy 'from' into 'to'; assuming to is big enough */
    void copy(char to[], char from[]) {

        int i;

        i = 0;
        while ((to[i] = from[i]) != '\0')
            ++i;
 }
