#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

extern void pwd();
extern void listAll();
void cd();
void mkdir();
void rmdir();
void reName();
void copyFile();
void findFile();
int Copy(char *srcFile,char *desFile);
#endif // LINK_H_INCLUDED
