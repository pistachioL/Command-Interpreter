#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <cerrno>
#include <cstring>

using namespace std;
//创建目录
void mkdir()
{
    char dirname[20];
    cin >> dirname;

    if(access(dirname,F_OK) == 0)  //判断目录名是否存在，存在返回0，不存在返回-1
    {
        cout << "目录" << dirname << "已存在，创建失败！" <<endl;
    }
    else if(mkdir(dirname,0777) == 0)  //mkdir只能创建空的目录包括mkdir -p /test/1/2 创建多个目录
    {
        cout << "创建成功！" <<endl;
    }


}
