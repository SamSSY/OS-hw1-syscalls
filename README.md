#作業系統 HW1
**組別：26**  
**B01901160蘇上育 B01901188 許浩倫**
##自訂System Call
###hw1.c
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

###結果截圖
![Alt Image Text](hw1_1.tiff)
> * 圖中最上方顯示學號以及名字是第一個函數 show(void) 的結果。
> * 接著我們在測試程式中請使用者輸入兩個數字接著會呼叫第二個函數 multiply(long, long) 並且在下面顯示兩個數字的乘積。
> * 在測試程式的最後我們請使用者再輸入兩個數字並且呼叫第三個函數 min(long, long)在下面顯示兩個數字中比較小的數字。

##實作細節及遇到的困難  
- 投影片中的新增system call的方法只適用於32bit的linux kernel。一開始依照投影片新增system call(Hello syscall)，build和安裝都完成後，卻無法呼叫新增的system call，後來才發現原本的Ubuntu是64bit版本。之後重新裝成32bit就成功了。
- 和其他人一樣有遇到以下錯誤訊息  
 
```
ERROR: "__modver_version_show" [drivers/staging/rts5139/rts5139.ko] undefined! 
WARNING: modpost: Found 4 section mismatch(es).  
To see full details build your kernel with:  
'make CONFIG_DEBUG_SECTION_MISMATCH=y'  
make[1]: *** [__modpost] Error 1  
make: *** [modules] Error 2
```

除了使用助教在  

	sudo make menuconfig
中調整`staging drivers`外，一開始我們是自己調整`.config`檔案當中的內容才能夠rebuild成功。