#include <linux/kernel.h>
#include <linux/linkage.h>

asmlinkage int sys_show(void)
{
  printk("B01901160 Shang-Yu, Su \n");
  printk("B01901188 Hao-Lun, Hsu \n");
  return 0;
}

asmlinkage long sys_multiply(long num1, long num2)
{
  return num1 * num2;
}

asmlinkage long sys_min(long num1, long num2)
{
  return (num1 > num2)? num2: num1;
}
