

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

 /*The function getline() and copy are declared at the top of the file or program, which we assume are contained in one file.
 main() and getline() communicate through a pair of argumentd and a returned value.In getline(), the argument is declared by the line.

 int getline(char s[], int lim);
 which specifies taht the first argument s iss an array and the second, lim, is an interger. 
 The purpose of supplying the size of an array in a declaration is to set aside storage.
 The length of an array s is not necessary in getline() since its size is set in main.
 getline() uses return to send a value back to the  caller, just as the function intergerPower() did. 
 This  line also declares that getline() returns an int; since int is the default return type, it culd be ommitted.
 
 getline() puts the character '\0'(the null character, whose value is zero) at the end of the array it is creating,
 to mark the end of the string of characters. This conversion is also used by the C language: when a string constat like

 "hello"
 appears in a C program, it is stored as an array of characterrs containing the characters  in the string and terminated with a '\0' to mark the end. 

 "hello\n\0"

 The %s format specification in a printf expects the corresponding argument to be a string represented in this form. copy also relies on the fact that
 its input argument is terminated with a '\0', and copies this character into ouput.

 It is worth mentioning in passing that even a program as smaall as this one represents some sticky design problem.
 For what should main do when it encounters a line which is bigger than its limit? getline() works safely, in that  it stops collecting when the array is full,
 even if no newline has been seen. By testing the length and the last character returned, main() can determine whether the line was too long, and the cope as it wishes.
 In the interest of simplicity, we will ignore this problem for now, and assume that all input lines are shorter than MAXLINE.

 There is no way  for a user of getline() to know in advance how long an input line might be, so getline() checks overflow.
 On the other hand, the user of copy() already  knows (or can finf out) how big the string are, so copy() does not check for ovverflow.

 **EXERCISE**
1. Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines,
and as much as possible of the text.

2. Write a program to print all input lines that are longer than 80 characters.

3. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

4. Write a function to reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.


*/