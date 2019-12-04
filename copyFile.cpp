#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
using namespace std;
int isFolder(char *desFile)   //判断目标文件的目录是否存在
{
    DIR *dir;
    if((dir = opendir(desFile)) == NULL)
    {
        return 0;
    }
    else
    {
        closedir(dir);
        return 1;
    }
}
int copyFileToFile(char* srcFile,char* desFile)
{
    FILE *psrc = NULL,*pdes = NULL;
    char buffer[1024];
    if(access(srcFile,F_OK) == -1)  //若文件不存在
    {
        cout << strerror(2) << endl;
        return -1;
    }
    else
    {
        psrc = fopen(srcFile,"r");
        pdes = fopen(desFile,"w+");
        if(psrc && pdes)
        {
            int len = 0;
            memset(buffer, 0, sizeof(buffer));
            while((len = fread(buffer,1,sizeof(buffer),psrc))>0)  //把源文件的内容读入缓冲区buffer
            {
                fwrite(buffer,1,len,pdes);  //把缓冲区buffer的内容写入副本文件
            }
            cout << "复制成功！" <<endl;
        }
        else
        {
            cout << "复制失败！" <<endl;
            return -2;
        }

        fclose(psrc);
        fclose(pdes);
        return 1;
    }
}

int copyFileToFolder(char *srcFile,char *folder)
{
    char fileName[500];  //副本文件名
    char desPath[500];  //副本文件路径
    int len = strlen(srcFile);
    int i;
    for(i=len-1; i>=0; i--)
    {
        if(srcFile[i] == '/')
        {
            strncpy(fileName,srcFile+i+1,len-i);
            break;
        }
    }
    if(i<= -1)  //没有/即为文件名
        strcpy(fileName,srcFile);

    strcpy(desPath, folder);
    strcat(desPath,"/");
    strcat(desPath,fileName);
    return copyFileToFile(srcFile,desPath);
    cout << "复制成功！" <<endl;

}

int Copy(char *srcFile,char *desFile)
{
    if(isFolder(desFile))  //目标文件是目录
    {
        return copyFileToFolder(srcFile,desFile);
    }
    else
    {
        return copyFileToFile(srcFile,desFile);
    }
}
