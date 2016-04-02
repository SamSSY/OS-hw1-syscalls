#include<sys/syscall.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
  syscall(349);
  long num1, num2;
  printf("please input number 1: \n");
  scanf("%ld", &num1);
  printf("please input number 2: \n");
  scanf("%ld", &num2);
  long result1 = syscall(350, num1, num2);
  printf("%ld multiply %ld is: %ld \n", num1, num2, result1);
  long num3, num4;  
  printf("please input number 3: \n");
  scanf("%ld", &num3);
  printf("please input number 4: \n");
  scanf("%ld", &num4);
  long result2 = syscall(351, num3, num4);
  printf("%ld is the min value between %ld and %ld \n", result2, num3, num4);
  return 0;
}
