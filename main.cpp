#include <iostream>
#include <cstring>
#include "link.h"

using namespace std;

int main()
{
    while(true)
    {
        cout << "Linux命令行,请选择要操作的命令："<<endl;
        char s[100];
        cin >> s;
        if(strcmp(s,"pwd") == 0)
        {
            pwd();
            cout << endl;
        }
        if(strcmp(s,"list") == 0)
        {
            listAll();
            cout << endl;
        }
        if(strcmp(s,"cd") == 0)
        {
            cd();
            cout << endl;
        }
        if(strcmp(s,"mkdir") == 0)
        {
            mkdir();
            cout << endl;
        }
        if(strcmp(s,"rmdir") == 0)
        {
            rmdir();
            cout << endl;
        }

        if(strcmp(s,"exit") == 0)
        {
            cout << "正在退出命令解析器..." <<endl;
            break;
        }

        if(strcmp(s,"rename") == 0)
        {
            reName();
            cout << endl;
        }

        if(strcmp(s,"copy") == 0)
        {
            char src[500],dest[500];
            cin >> src >> dest;
            Copy(src,dest);
            cout << endl;
        }

        if(strcmp(s,"find") == 0)
        {
            findFile();
            cout << endl;
        }
    }
       return 0;
}
