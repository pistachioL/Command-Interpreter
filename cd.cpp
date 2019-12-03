#include <iostream>
#include <cerrno>
#include <cstring>
#include <unistd.h>
using namespace std;


void cd()
{
    char path[50];
    cin >> path;

    if(chdir(path) == -1)
    {
        cout << "cd: " << strerror(2) << endl;
    }
    else
    {
        cout << "切换成功!请用list查看"<<endl;
    }

}
