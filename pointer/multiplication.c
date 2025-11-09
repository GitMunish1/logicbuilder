#include <stdio.h>
//write a program to change of variable to ten times of its current value

int main(){
int i = 5;
int *p;
p = &i;
printf("before changing, value of i = %d\n", i);
*p = *p * 10;
printf("after changing value of i=%d\n", i);
    return 0;
}