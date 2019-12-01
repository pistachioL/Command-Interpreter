#include <iostream>
#include "link.h"
#include "pwd.cpp"
#include "list.cpp"
#include "cd.cpp"
#include "mkdir.cpp"
#include "rmdir.cpp"
#include "rename.cpp"
#include "copyFile.cpp"
#include "findFile.cpp"
using namespace std;

int main()
{
    while(true)
    {
        cout << "Linux命令行,请选择要操作的命令："<<endl;
        string s;
        cin >> s;
        if(s == "pwd")
        {
            pwd();
            cout << endl;
        }
        if(s == "list")
        {
            listAll();
            cout << endl;
        }
        if(s == "cd")
        {
            cd();
            cout << endl;
        }
        if(s == "mkdir")
        {
            mkdir();
            cout << endl;
        }
        if(s == "rmdir")
        {
            rmdir();
            cout << endl;
        }

        if(s == "exit")
        {
            cout << "正在退出命令解析器..." <<endl;
            break;
        }

        if(s == "rename")
        {
            reName();
            cout << endl;
        }

        if(s == "copy")
        {
            copyFile();
            cout << endl;
        }

        if(s == "find")
        {
            findFile();
            cout << endl;
        }


    }
       return 0;

}
