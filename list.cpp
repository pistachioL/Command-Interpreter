#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <string.h>
using namespace std;

void listAll()
{
    char filename[255];
    string allFile[1000];
    DIR *dir;
    struct dirent *rent;  //dirent结构体
    dir = opendir(".");
    int cnt = 0;
    while((rent = readdir(dir)))
    {
        strcpy(filename,rent->d_name); //获取文件名
        if(filename[0] != '.' && filename)
        {
            allFile[cnt++] = filename;
        }
    }
    sort(allFile,allFile+cnt);
    for(int i=0;i<cnt;i++)
        cout << allFile[i] << "   ";

    puts(" ");
    closedir(dir);


}
