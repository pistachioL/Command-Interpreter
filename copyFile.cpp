#include <iostream>
#include <fstream>
using namespace std;

void copyFile()
{
    char srcFile[50],desFile[50];  //源文件，副本文件名或路径
    FILE *psrc = NULL,*pdes = NULL;
    char buffer[1024];
    cin >> srcFile >> desFile;
    if(access(srcFile,F_OK) == -1)  //若文件不存在
    {
        cout << strerror(2) << endl;
    }
    else
    {
        psrc = fopen(srcFile,"r");
        pdes = fopen(desFile,"w+");
        if(psrc && pdes)
        {
            int len = 0;
            while((len = fread(buffer,1,sizeof(buffer),psrc))>0)  //把源文件的内容读入缓冲区buffer
            {
                fwrite(buffer,1,len,pdes);  //把缓冲区buffer的内容写入副本文件
            }
            cout << "复制成功！" <<endl;
        }
        else
        {
            cout << "文件读取失败" <<endl;
        }

        fclose(psrc);
        fclose(pdes);
    }
}
