#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
using namespace std;
//创建目录
void mkdir()
{
    char dirname[50];
    cin.getline(dirname,50);  //能读取空格，创建多个文件夹
    int len = strlen(dirname);
    int flag;
    for(int i=0;i<len;i++)
    {
        if(dirname[i] == '/')
        {
            dirname[i] = '\0';
            if(access(dirname,F_OK) != 0)
            {
                mkdir(dirname,0777);
                flag = 1;
            }
            else
                flag = 0;

            dirname[i] = '/';

        }
    }
    if(len > 0 && access(dirname,F_OK) != 0)  //判断目录名是否存在，存在返回0，不存在返回-1
    {
        mkdir(dirname,0777);
        flag = 1;


    }
    else if(mkdir(dirname,0777) == 0)  //mkdir只能创建空的目录包括mkdir -p /test/1/2 创建多个目录
    {
        flag = 0;

    }
    if(flag == 1)
        cout << "创建成功！" <<endl;
    else
        cout << "目录" << dirname << "已存在，创建失败！" <<endl;



}
