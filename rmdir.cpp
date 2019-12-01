#include <iostream>
#include <ftw.h>
using namespace std;
   char dirname[20];

void rmdir()
{
    char dirname[20];
    cin >> dirname;

    if(rmdir(dirname) == 0)
    //if(nftw(dirname,10, FTW_DEPTH|FTW_MOUNT|FTW_PHYS) < 0)
    {
        cout << "目录" << dirname << "删除成功！"<<endl; //递归
    }
    else
    {
        cout << "删除失败，目录必须为空！" <<endl;  //权限不够或者没有该文件
    }

}
