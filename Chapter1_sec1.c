/*
helpful link->https://0xax.gitbooks.io/linux-insides/DataStructures/linux-datastructures-2.html
or
https://www.youtube.com/watch?v=pet3bOhOXzY&list=PLhqasd25bl-hamUHgiK7ooKBjt0y7L5XS

Unit 1->ARM register, ARM CPU mode, ARM assembly, 

Unit 2->External hardware and device driver

Clock->Memory, Flash, port, data sheet, manual

Unit 3->ARM boot loader

Like BIOS
-Boot->like the embedded board to intialized by the minimum hardware enviroment (4:57)
-loader->Let the OS(Linux/Android) inside the flash/hard drive (5:17) into the RAM (5:44)
and redy to execute (5:49)
-U_boot->open source (6:14). They are using tiny-210 development board (6:49) based on ARM 
cortex A8 (1GHz) (@7:48)

Unit 4->ARM interrupt programming (@8:02)
-Software interrupt
-Hardware interrupt(@8:14)
-U must know the interrupt bofore going to the OS. Otherwise, it won't help(@8:26)
-When there is a context switch(切换) required for swapping out one process running on the CPU. It requires
interrupt(@8:42)
-When interrupt happen during the context switch, it needs to keep what have left from previous CPU state (8:48)
-When interrupt ends, it needs to go back to the previous state (8:52)
-how to keep and return to the prvious state, it relates
to the ARM interrupt assembly code (8:55) NOT in C lanquage (9:02)

Unit 6->Linux OS (@9:44)
-After understaning the development board in arm, we will move on to Linux OS
-What we need to know how to register the device driver in Linux (@10:32)
-We will focus on the character device driver (11:11)
  -Block device driver for LED (@18:41)->require development board
  -We can simulate this through our PC(@19:12)
-Network
-USB
-Under chacracter device driver->it deals with a lot of data strcture(12:04)
-Such as double link list in linux kernel (12:30)
-Tree (data structure) (12:36)
-So before we dig into device driver, we need to go through Unit 5

Unit 5->Linux Kernel core data structure (13:14)
-VFS->virtual file system(13:26)
        -file
        -kobject
-data structure
       -double link list (14:26)
       -Radix tree(14:45)
          ->https://0xax.gitbooks.io/linux-insides/DataStructures/linux-datastructures-2.html
          ->Don't use your creat your own data structure (14:55)
       -Data structure->Really important for interviewing
       -Bit array(16:34)
Unit 7->Linux interrupt (17:05)
  -Part 1(上半部)->it relates to kernel while writing device driver (17:55)
  -Part 2(下半部)
  -When there is a requirement to have context switch in process,we need to have interrupt (17:44)
  -
  
 Unit 8->串口驱动(serial port) (18:13)
    -linux interrupt programming
    -character device (18:24)
--------------Now move on to ARM architecture (@20:21)----------------------------------
ARM assembly (@24:20)
-Power Supply(@24:45) usually 5V (24:48)
-Powr ON/OFF (@25:05)
-Push buttom (@25:09)
-USB port(@25:31)
-COM port (25:58)->different COM port (@25:58) relates to RS-232 as desscribed
->https://www.electronicshub.org/types-of-computer-ports/
->https://www.aliexpress.com/item/Tiny210-development-board-with-7-inch-touch-screen-Android-4-0-Cortex-A8/559890438.html
-COM1 usually for transmitting files from PC to target board
-COM3 usually used for writing driver (@26:25)
-audio (26:35)
-microphone (@26:43)
-RJ-45 internet connection (26:50)
-S2 Boot Mode Switch->To boot (@27:03)->important
-Do we start from Nand flash or SD card? (@27:08)
  -It starts from the NAND flash (@27:26). It is like boot from from the hard drive(@27:32)
  -However, you have an optoin to boot from SD card (@27:38)
-Reset(@27:50)->reset the system
-There are extenral periphrals for connecting to the camera such as CDC/COMS switch/COMS camera (@28:04)
-AV2,AV1,TVOUT refers to the TV (@28:09)
-CON14:RS485 (@28:16) 
-adc模数转换器 may be at (@28:29) (Not sure)
-There is a 4.5" screen (@28:45)
-You need to provide the pressure for the touch screen (@29:09)
-There is a smaller board on top of the main board (@29:27)
-Don't ake out the smaller board (29:50)
-What's the core inside the CPU (@30:13)
  -CPU, RAM (30:29)
  -I don't even need a hard drive (@30:33)
-On the small board, there is a CPU (@30:42)
-Coretex A8 core (@30:47)
-In embedded system, the are a.k.a MPU->微处理器 (@31:11)
-Thare are four itmes looks the same (@31:18)->They are DRAM (@31:20)
-Each one has 128MB(兆字节) RAM (@31:27)
-Since there are 4 memories block=4 Channel(通道) (@32:18)
-Each channel provides one 字节(Byte) (@32:22)
-So if you are writing a long (4byte), it will be stored in 4 channels as 32 bytes (@32:39)
-Each byte is stored in each channel/RAM (@32:37)
-IF there is (8 bytes) then each RAM will store 2 bytes(字节) (@32:46)
-Beside CPU, there is a NAND flash (@32:59)
-It is like a hard disk in PC(@33:07)
-NAND flash is 256 MB (@33:16)
-Everthing comes together is a.k.a development board (开发板) (@33:26)
-This board is not a product but a lot of products can be made from this board.(@33:31)
-For the final product, we only pick what we want such as screen or camera
and rests such as COM, USB connectors are all ignored (@34:09)
-This development board is for verificatin/validation purpose (@34:16)
-Why do we need to split the top board containg the CPU and buttom board with a lot of I/O(@34:47)
-OS requires CPU,RAM and hard drive (@35:11)
-However the peripherals for the products can be vary (@35:11)
-Therefore I can have a mass production of the CPU core (Top board) and sell them to the
individual company requiring different peripherals for their prodcuts (@35:25)
-So the can deliver the products in a fast fashion(@35:33)
-Second reason is due to the circut layout 电路布局 (@35:41). The main board(upper board) is 4 layers
(@35:43).
-The based(buttom) board is two layers (@35:48)
-6 layers means that there are six layers of integrated circuit in the PCB (@35:55)
-There will be signal interferences if two circuits get too close together (@36:06)
eg with Eelectrical magnets
-The cost of having 6 layers is more expensive thean having 2 layers (@36:18)
-If we don't split into upper(main) and lower(base) boards, we need to have one board. We are
going to have one board with 6 layers->super expensive and more challenging in layout (36:38)
-Under the screen, there is a buzzer (蜂鸣器) (@37:03), after starting the developmet board.
u will hear a sound (@37:06)
-------------End of introducing the development board--------------------------------------
-u can add/buy a GPS module (37:39)
-ARM CPU->a.k.a ARM 内核 (@38:44)
-What does CPU Core contain? (@39:27)
    -Register 寄存器
    -ALU (算术逻辑单元) or 运算元 (@40:04)
    -cache 预取器 (@40:16)
    -Control unit (控制器) (@40:36)
    -decoder (译码器) (@41:01)
    -It is called ARM v9, ARM v7 (@50:09), or CORTEX_A8 (@50:12)
 -RISC(精简指令集计算机)
    -ARM, MIPS
    -From UC Berkley
    -MP3 player
 -CISC (复杂指令计算机) (@41:55)
    -x86
    -More expensive
-ARM sells its licensie to Samsung, TI, Freescale, huawei Hisilicon (@46:53),Mediatek
-SOC system on chip(片上系统)(@47:52)
-Those companies like mediatek add its own peripheral (@48:13)
-Like samsung focus on multmedia,ipad and LCD so it needs to add
2D/3D hardware accelerator (@48:20),interrupt Controller(中断控制器) (@49:05), MMU(内存管理单元)
(@49:25) and (peripheral controllers)外围控制器 or 外设控制器 to form a CPU (@49:43)(IMPORTANT)is known
as S5PV210 for Samsung (@50:47)
->The tiny-210 development board manufacturers(友善电子) buy S5PV210 from Samsung (@51:30)
------------------------------------------------------------------------------------
-For every CPU of S5PV210 sold, Samsung has to pay ARM inc (@52:45)  
-Difference between RISC and CISC (精简指令集计算机 vs 复杂指令计算机) (@57:47)
->For example in x86 assembly, the short instruction set can be 2 byte(字节) such as MOV %AX,%BX
->The long instruction set can be more than 10 byte byte(字节) (@58:15)
->How does cache 预取器 get the intructin sets from the RAM (@58:26)?
->In x86, the machine instruction set can be vary from 2,10 to 20 bytes(字节)
->Does CPU's cache 预取器 knows that what is the size of the instruction set in advance before execuring the code? (58:54)
->It doesn't know what is the size of the instructions required (58:58)
->So it will analyze(分析) the first byte (字节) (@59:04)
->The first byte (字节) will tell cache 预取器 how is the length of instruction set implicitly (@59:10)
->So if the 1st  byte(字节) tells cache 预取器 that the length of instruction set is 5, so I (@59:20) 
keep reading the next 4 bytes and put into the CPU (@59:19) and give to the decoder (译码器) to analyze the intruction
set as the whole (@59:24)
->please see the following for more detail
https://en.wikipedia.org/wiki/Instruction_cycle
->Therefore, your CPU's cache 预取器 will be more complex since it requires to anayze the size of intructions set (@59:31)
->Advantage for 精简指令集 (@59:35), the length of insruction set is always the same (@59:54)
->In ARM, the length of instruction is 32 bit (@59:57)=4bytes(字节)
->Therefore, when arm CPU load the instruction set from RAM (内存), I don't need to anaylize its length
(@1:00:08)
->1) For RISC 精简指令集, the lenght of instruction set is fixed->important (1:00:23)
     For CISC, the instructio length is not fixed
->2)For RISC 精简指令集, each instruction only handles ONE simple task
    FOR CSIC,each instruction handles more tasks (1:00:41)
-eg. If I want to move data (4byte) from one address space inside RAM to another address (1:00:51)(1:00:56)
-RISC 精简指令集 can't do it directly due to its simple instruction (1:01:17). It has to follow the strucutre
of Load and STORE (@1:01:23)
-So in RISC 精简指令集, it has to load the data from one address inside RAM to CPU (1:01:51)
-Then it will store the data from the register(寄存器) to another address of RAM (1:01:57). Require at least two
instruction set
-In CISC (复杂指令计算机), it can directly access/store from/to the memory due to its more powerful instruction (1:02:06)
so it only need one instruction set (1:02:13) without going through CPU (1:02:19)
-Due to its powerful instruction set, its digital logic will be much more complicated (1:02:27) so it will be more
expensive (1:02:30)
->3)In RISC 精简指令集, there are about (1:04:17) 100 common  used assemblies (1:04:15), in CISC (复杂指令计算机),
there will be around 700 assemblies (1:04:25)
->4) 80% vs 20 %, for those 100 assemblies, you will use 80% of them most of the time in RISC 精简指令集.
Another 20% will be rarely use. In CISC (复杂指令计算机), it will be vice versa (1:04:48)
->Has the hardware logic first then has the specific assembly code to control it (1:08:19)
->If I use instruction set system v7 to armv7, will it work? (1:10:06)
->It may not work since some the intruction set is NOT supported in armv7 (1:10:10)
->backward compataible, it mays if I develop a hellow world program in armv7, it will be compatible in armv9
(1:11:05)
*/
