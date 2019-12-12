#	LinuxShell命令模拟器

###	一.原理分析

1）读取用户从键盘输入的命令，终端会分析是否是内部命令。如果是，则把命令分解为系统调用，并传给linux内核。如果不是，若不是再检查是否是一个应用程序，模拟shell的命令解析器正是这样。上述两种情况也不是的话，则报出错误信息。

2）分析命令，以命令名为文件名，将其他参数改造为系统调用execve()内核级系统调用所要求的形式；

> int execve(const char * filename,char * const argv[ ],char * const envp[ ]); 
>
> execve()用来执行参数filename字符串所代表的文件路径（用户输入的命令），第二个参数是利用指针数组来传递给执行文件，并且需要以空指针(NULL)结束，最后一个参数则为传递给执行文件的新环境变量数组envp，envp数组里保存的系统的环境变量。

3）终端进程调用fork()建立一个子进程；

4）终端进程本身用系统调用wait()等待子进程完成。子进程执行execve()时，子进程根据命令名到目录中查找相关的文件，把它调入内存，执行程序（解析命令）。（即fork()子进程，调用exec()加载运行命令）

5）当子进程完成后，向父进程（终端进程）报告，唤醒终端进程。在做必要的判断之后，终端向用户发出提示符，让用户输入新命令，重复上述过程进行处理。



###	二、功能展示

#####	1.输入pwd，能显示当前目录的绝对路径

![1.png](https://i.loli.net/2019/12/12/nXVg2h7LRiZDbdM.png)



##### 2.输入list，能显示当前文件夹中所有的文件和文件夹

![2.png](https://i.loli.net/2019/12/12/XpCvmSIlgurKBWs.png)



##### 3.输入cd，能切换当前工作路径

![3.png](https://i.loli.net/2019/12/12/OJzMTPvSXuocy45.png)



##### 4. mkdir 创建文件夹，能创建一次创建多个文件夹，或者只创建一个文件夹

![4.png](https://i.loli.net/2019/12/12/mMDOgjXCRyw7SJr.png)



##### 5.rmdir 删除空或者非空的文件夹

![5-1.png](https://i.loli.net/2019/12/12/Vp87LsIcl9TXgDO.png)

![5-2.png](https://i.loli.net/2019/12/12/31nXx8ON2DshbR4.png)



#####	6.rename 旧文件名 新文件名

![6.png](https://i.loli.net/2019/12/12/Y6GJ5z9ZLlCuUXi.png)



#####	7.copy 已存在的文件名 新文件名

![7.png](https://i.loli.net/2019/12/12/fYW7x4a6vHJwOnA.png)



##### 8.find 目录 -name 带查找文件名

![8.png](https://i.loli.net/2019/12/12/GqJfcOVpvBeEx6u.png)



