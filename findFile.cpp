#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void solve(const char* filepath, const char* filename)
{
    DIR* dir; //DIR *opendir（const char *name）;
    struct dirent* drip;
    char childDir[500];
    if((dir = opendir(filepath))!= NULL)  //路径不为空
    {
        while((drip = readdir(dir)) != NULL)
        {
            if(strcmp(drip->d_name,".") == 0 || strcmp(drip->d_name,"..") ==0) //不用查找该目录下的. ..
            {
                continue;
            }
            else if(strcmp(drip->d_name,filename) == 0)  //输入的路径下有该文件名，则直接输出
            {
                cout << filepath << "/" << filename <<endl;

            }
            else if(drip->d_type == DT_DIR)  //遍历出是一个目录，则继续递归
            {
                sprintf(childDir,"%s/%s",filepath,drip->d_name);
                solve(childDir,filename);
            }
        }
    }
    closedir(dir);
}

void findFile()
{
     char filepath[100],filename[100];
     string arg;
     cin >> filepath >> arg >> filename;
     solve(filepath,filename);
}
