#include<iostream>
#include<cstdlib>
#include<cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using std::cout;
using std::endl;
const int MAXN = 100;
char readBuf[MAXN];
int main(int argc , char* argv[]){
    if(argc != 3){
        cout << "Three parameters should be entered incorrectly!" << endl;
        return 0;
    }
    int fpSource = -1 , fpTarget = -1;
    if((fpSource = open(argv[1] , O_RDONLY)) == -1){
        cout << "Open source file error!" << endl;
        return 0;
    }
    if((fpTarget = open(argv[2] , O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWGRP)) == -1){
        cout << "Open target file error!" << endl;
        return 0;
    }
    while(true){
        memset(readBuf , 0 , sizeof readBuf);
        int len = read(fpSource , readBuf , MAXN);
        write(fpTarget , readBuf , len);
        if(len != MAXN) break;
    }
    close(fpSource);
    close(fpTarget);
    return 0;
}