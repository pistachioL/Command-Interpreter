#include <unistd.h>
#include <iostream>
using namespace std;
void pwd()
{
   char path[80];
   getcwd(path,sizeof(path));  //调用getcwd()获得当前目录getcwd()会将当前的工作目录绝对路径复制到参数buf 所指的内存空间，参数size 为buf 的空间大小。
   cout<<path<<endl;
}
