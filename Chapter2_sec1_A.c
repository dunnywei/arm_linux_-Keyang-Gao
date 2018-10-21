https://www.youtube.com/playlist?list=PLhqasd25bl-igPZWIM2cQrcSX7oFZJ9Bo
https://www.youtube.com/watch?v=DIePk-tlvgI&list=PLhqasd25bl-igPZWIM2cQrcSX7oFZJ9Bo&index=2
Linux嵌入式开发和驱动开发--2开发板外设驱动
Section1_c和汇编混合编程   
->ATPCS protocol (协议)(0:48)
    -link->http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0056d/ch02s01s03.html
    -link->http://infocenter.arm.com/help/topic/com.arm.doc.espc0002/ATPCS.pdf
->Use C lanquage to call the function (调用函数) written in assembly or vice versa (0:28)(0:58)
->How to passing the paramter (传递参数) between C and assemlby during function call 函数调用(0:58)
->In C programming lanquage, we have two parameters (参数) (1:06)
    -Code 1
int fun(int a,int b)
{
    
}
int main(void)
{
    fun(4,6)
}
    -They are using stack (堆栈)(2:56) to pass the parameter (参数) from RIGHT to LEFT (3:36)
    -So it will starts from 6 then to 4 a.k.a 压栈 (3:55)
    -graphical view
---------------------------------
//Stack grows down
   6 as b  (Stack Segment)
   4 as a 
        
        
   main (code segment)
   fun
----------------------------


    -main and fun are both saved in the code segment (代码段) (4:28)
    -When main is call the "fun" function,we need to pass two parameters as 4 and 6 (参数)(4:34)
    -They use stack 栈 to pass it from main to "func" (4:37)
    -They will pass from the right to the left while pushing on the stack a.k.a 压栈 (4:44)
    -Therefore, it will put 6 first then put 4 later (4:54)
    -In C programming code, when it start to execute fun(4,6), flow of execution will jump 跳转 to the  function of the address (函数地址)
        from main function to "fun" function (5:07)
    -After the flow of control is at the address of "fun" function, arguments (实参) 6 and 4 passed then obtained during the execution time (5:26)
        link->https://blog.csdn.net/marcelwu/article/details/65629158
    -Within the function of "fun", when function start to obtain the value from parameter 形参 a or b (5:27), it will get from
    the stack 栈 (5:30)
    -While pushing on the stack 压栈, we go from right to the left. While poping out of stack 出栈, we goes from left to the right due to
    FIFO (5:42)
    -During the execution of the "fun" function, PC (R15) points to the address of function (6:08)
    -When function need to get the vale of the paparamter, it will obtain the value from stack 栈
    via index (索引) (6:14)
->Now we need to cross programming in both C and assembly (汇编) (6:21)
->We can write the function 函数 in assembly(汇编) and use C lanquage to call 调用 it (6:25)
->For example, I am writing a bubbble_sort in assemlby (汇编) (6:30) by using the label 标号 (6:47)
-> label 标号 represents the address (地址) (6:51). It is the same as the fuction name 函数名 (6:54)
->What bubble sort is doing is to have the 泡泡排序 (7:15)
->The Following is the demonstration of bubble sort in C lanquage as Code 2. (7:32)



->code 2 (10:05)
----------------------------------------------
void bubble_sort(int a[],int n)
{
        
}

/*汇编
 *bubble.s*/
bubble_sort
   move r0
   
/*main.c*/
int main()
{
    int a[10];
    bubble_sort(a,10); (8:10)
}
------------------------------------------------
->Under CODE 2
->The first parameter represents the start address 起始地址 or 首地址 of the array 数组. The second parameter represents the length of
array(7:39)
->IN C programming, I have two paramters (参数) passing (传递) to the bubble_sort function. Therefore, I also need to pass
in two paramters (参数) in assemlby lanquage as well. (7:53)
->If I have already written the bubble_sort and the main function try to call 调用 it (8:04),
->The main function is written in C lanquage (8:37), bubble_sort is written in assembly code (汇编) (8:48)
->When C program needs to call the function in in assembly code (汇编) (9:04)
->When the main function in C program wants to call bubble_sort function in assembly lanquage 汇编代码 
in ARM architecture (体系结构), do we do the same way as in x86 architecture architecture (9:30)
->The answer is Yes. We can use stack 栈 / registers (寄存器) to pass the paramter (传递参数) (9:35)    
->Using the resters 寄存器 vs using the stack 栈. Which is faster? (9:35)
    -Using register 寄存器 is faster (9:51)
    -There are 37 registers 寄存器 in ARM architecutre. Under each mode, ARM can see 17/18 registers 寄存器(9:59)
    -ARM has more registers 寄存器 than x86 (10:01) so it pass the parameter (传递参数) via the registers (寄存器) (10:09)
    -X86 only has the limited registers 寄存器 so it has to use stack 栈 
    -ARM has more registers so it pass the paramter via registers for speeding perfomrance up (提高速度)  (10:19)
    -This is why we have ATPS protocol 协议 (10:25)
    -We will use R0 to R3 used for passing the parameter (传递参数) during the function call 函数调用 (10:34)
    -For example, we are going to make a function to the following (10:37)
    -int add(int a,int b,int c, int d) 
    -so R0=a,R1=b,R2=c, R3=d for using registers 寄存器 to pass the paramter (传递参数) (10:55)
    -using stack to passing the parameter (传递参数) if, there are more than "FOUR" (>4) paramters 参数. (11:16)
        -Those will require to use the stack 栈 to passing the parameter (传递参数)
    -R0 is used to keep the return value 返回值 from the function call (函数调用) (12:04)
    -Can a function use return stetement.It can only return one varialbe? (12:14)
        -If we want to return more than one variable. We can use pointer 指针.
        -However, we have to ensure that what pointer doesn't point to a local variable (局部变量)(12:32)
            -The reason is that the local variable 局部变量  will be released 释放 after the function ends (12:35)
            -Usually there are two ways. One is use addressed aloocated from "mollac" through static number 静态数 (12:40)(12:43)
           ->https://blog.csdn.net/wzy_1988/article/details/8687859 (most imporant)
           -link->https://blog.csdn.net/weiyuefei/article/details/51563890
           -link->https://blog.csdn.net/zkangaroo/article/details/61202533?utm_source=blogxgwz1
           -Or you package 封装 as a structure 结构体 (12:46) then return it as a structure 结构体(12:49)
    -(starts here)
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->



->code 3 (15:10)(16:07)
#include <stdio.h>

extern int myadd(int a,int b);

int main(void)
{
   int a=3;
   int b=5;
   int c;
   c=myadd(a,b);
   printf("%d\n",c);
   
   return 0;
}

;(17:05)
   AREA MYADD,CODE,READONLY
   ENTRY
   EXPORT my
myadd
   ADD R2,R0,R1
   MOV R0,R2
   MOV R15,R14 ;MOV PC,LR (19:04)

   END

->code 4 (29:16)

    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    -
    
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
    
    
    ->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->

