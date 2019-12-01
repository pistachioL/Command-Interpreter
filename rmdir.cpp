#include <iostream>
#include <ftw.h>
using namespace std;
   char dirname[20];


int rmFile(const char *pathname, const struct stat *sbuf, int type, struct FTW *ftwb)
{
    if(remove(pathname) < 0)
        return -1;
    return 0;
}
void rmdir()
{
    char dirname[20];
    cin >> dirname;

    //if(rmdir(dirname) == 0)
    if(nftw(dirname,rmFile,10, FTW_DEPTH|FTW_MOUNT|FTW_PHYS) < 0)
    {
       cout << "删除目录"<< dirname << "失败" <<endl;  //权限不够或者没有该文件
    }
    else
    {
        cout << "目录" << dirname << "删除成功！"<<endl; //递归

    }

}
