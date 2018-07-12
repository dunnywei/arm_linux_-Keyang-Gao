/*
link->
https://www.youtube.com/watch?v=GddifYkmZsI&index=2&list=PLhqasd25bl-hamUHgiK7ooKBjt0y7L5XS

-Coretex corresponding to instruction set architeture v7 (0:05)
-If the code developed for ARMv7, it will work for ARM Cortex M. But not vice versa (0:21)
-ARM CPU architecuter (0:43)
-If you want to know arm assembly (汇编)(0:48) or programming in arm, u have to understand how the register(寄存器) works
and cooperate. (0:53)
->In x86, what kind of registers do we have?(1:03)
  -EAX, EBX,ECX,EDX (1:14)
  -ESP, EIP
  -EFLAG (1:18)
->In ARM (1:23), there are 37 registers in side ARM (1:27)
->U need to memorize and know what does each register is doing(1:30)
->There are seven modes in ARM cpu (1:59)
  -System &User
  -FIQ=Fast interrup(快速中断)
  -Supervisor (超级管理模式)(监视模式)(2:12)
  -Abort(终止) (2:16)
  -IRQ(普通中断)(2:20)
  -undefined(未定义)(2:24)
  ->helpful linnk https://blog.csdn.net/yjzl1911/article/details/5642957
-At one time, CPU can only operate in one mode(模式)(2:35)
-If CPU is working on supervisor mode(超级管理模式), CPU can only access/read
those registers (2:46)
-helpful link for banking and unbanking->https://stackoverflow.com/questions/13432297/what-does-banking-a-register-mean
-r0 to r7 is unbanked(未分组) registered (3:09).Those eight registers can store data/value (3:16)
-r8 to r12 (3:24). They can also store value/data (3:33)
-r13 and r14(3:41).
-r13 is used as stacking pointer( 栈指针字寄存器)(SP) for storing the stack's address at the top(栈顶地址) (3:58)
  -In x86, it is named as ESP (4:21)
  -Where r13 or stack pointer opoints to relate to address of th stack (4:37)
->r14 is used as the subroutine link register(LR)(链接寄存器)
  -Keep the return address of the program for example if there is any branch occcurred (4:56)
  -Elaboration (5:24)
  -#1:
  -#2:
  -#3:func();//BL func (5:53)
      -When branch occur, the return address or PC的值(It will always point to the next one as #4)is automaticall stored (6:02)
      in R14/LR (6:27)(6:46)
  -#4:after the function branch, the program needs to continue execue here (5:35). 
     Here it is called the return address(5:41)
  -#5:
  -LR是链接寄存器，是ARM处理器中一个有特殊用途的寄存器，当调用函数时，返回地址即PC的值被保存到LR中（mov lr,pc）。
good link 4->https://blog.csdn.net/vincent_fang/article/details/17166509
good link 5->http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0211h/ch02s08s01.html
->R15 a.k.a PC register(寄存器) or 程序计数器(6:50)
  -elaboration (7:22)
  -预取器(cache) (7:25) obtains the instruction set from the RAM (7:26)
  -but where it really gets from RAM is controlled by L15/PC (7:32)
  -So what does the address which PC keeps (7:45) will be executed in the program within
  RAM (7:50)
  -(7:59) When I have a branch due to function 函数 (8:04),I want to return to #4 to 
  conitnue to execute (8:09)
  -My return address in L14/LR is #4 (8:17)
  -R15 will point out to the next instructin set to execute (8:27)
  -



*/
