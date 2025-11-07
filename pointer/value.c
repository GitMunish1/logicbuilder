//find the value of variable
#include <stdio.h>

int main(){
 int i=1;
 int *p;
 int **pr;
 p=&i;
pr=&p;
printf("value of i=%d", *p);
printf("\n value of i using pr=%d", **pr);
printf("\n address of i=%u", &i);
printf("\n address of i using p=%u", p);
printf("\n address of i using pr=%u", pr);
return 0;
}