Linux嵌入式开发和驱动开发--1ARM体系结构和汇
5 led灯实验
https://www.youtube.com/watch?v=xPONsaWO8gE&index=5&list=PLhqasd25bl-hamUHgiK7ooKBjt0y7L5XS
->USB to RS232 connnector (0:24)
  -Reciever and transmitter (0:34)
  -So you need to go to the system control->Device Driver->COM AND LPT
    -Then you will see "COM4" in this case (1:16)
    -Use a terminal which will match as line 7 as "COM4" in this case (1:41)
    -baud rate=115200. It means it can sends 115200 bit per second (bps) (1:52)
      -unit is in 比特位 (2:00)= 115200/8 can be transmitted 传送 in 字节 (2:02)
      -link->https://blog.csdn.net/qq_25077833/article/details/53386562 
      -link->https://blog.csdn.net/dagefeijiqumeiguo/article/details/68921820
    -Databits->In each 8 bits= a data packet (数据包) (2:08)
    -Stop bit->after sending the 8 bits 比特位, we will send a stop 停止 bit 位/标志 (2:12)
    -parity check 奇偶校验 (2:18)
->When system starts, it boots from U-Boot (2:43) or boot loader like the one in BIOS (2:47)
->type "help" to what command line does the system board support (2:59)
      -This is boots from SD card (3:11)
      -I can also choose the boot from NAND flash as well (3:18)
      -Treat NAND flash like a hard disk(256 兆 MB) where linux sysetem is installed (3:22) and 线程(thread)/进程(process) (3:23) 
      browsing 浏览 (3:23)
      -using pwd->it will list where which direcotory 目录 you are in 
      -type pwd and result is "/" it means you are in root directory (根目录) (4:05)
      -After starting the linux on the target board, I can send the elf executable to the linux board (4:17)
      -AFter boot  启动 from SD card, I am like entering the BIOS (4:27) so it only boot 启动 from boot loader(4:31)
      -using "~" to boot 启动 from bootloader (4:31)(??) you will see sth like "U-Boot"
        -Whenn boot 启动 from bootlaoder only, it can't execute ELF file (4:35)
      -It can only deal with pure binary file (二进制文件)(4:38)
->Our development board 开发板 has four LED light (4:46)
   -We need to touch electronic schematic diagram 电子原理图 and data sheets 数据表 (5:07)
   -(6:09)
AREA asm1test,CODE,READONLY
   ENTRY
LED_TEST
   LDR R0,=0XE0200280
   LDR R1,=0x1111
   STR R1,[R0]
   
   LDR R0,=0XE0200284
   LDR R1,=0x3
   STR R1,[R0]
   B LED_TEST

   END
  -after typing "help"
  -you will see that there is a command as "mv" for memory write 写入内存 (6:35)
  -mv 0XE0200280 0x1111 (7:06) so LED light will be ON (7:25)
  -mv 0XE0200280 0x0000 (7:32) so LED light will be OFF (7:25)
  -bootloader only provides a command  命令  to operate it (7:39) via operating its address 地址 (7:43)
  -We can also write the assemlby 汇编 code to operatge LED as well. (7:48)
 ->When we want to operate the LED (7:59)
-> 
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
