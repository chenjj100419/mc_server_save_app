#include <iostream>
//软件作者：chenjj100419

#include <string>
#include <iostream>
#include <vector>
#include <Shlwapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <direct.h>
#include <windows.h>
#include <io.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <map>

int last = 0
static int num = 0;
using namespace std;
string folderPath = ".\\backups";
string cd =EnterBox("请输入服务器文件夹路径注意，请把所有的斜杠换成两个);
string app =EnterBox("请输入软件的libpack文件夹路径，请把所有的斜杠换成两个);
wenjianjia();
using namespace std;
void loop(){
    int wenjianjia(){
        if (0 != access(folderPath.c_str(), 0))
        {
// if this folder not exist, create a new one.
            mkdir(folderPath.c_str());   // 返回 0 表示创建成功，-1 表示失败

        }
        return true;



    }


    int  API::TraverseDir_Num(const char* strVideoDir)//返回该文件夹的文件个数
    {
        //遍历目录

        DIR *dp;
        struct dirent *entry;
        struct stat statbuf;
        dp = opendir(strVideoDir);
        if (!dp) {
            LLERROR("无法打开目录:%s", strVideoDir);
            return -1;
        }
        chdir(strVideoDir);
        while ((entry = readdir(dp)) != nullptr) {
            lstat(entry->d_name, &statbuf);
            if (S_ISDIR(statbuf.st_mode)) {
                if (!strcmp(".", entry->d_name) || !strcmp("..", entry->d_name)) {
                    continue;
                }
                char strNewDir[256];
                sprintf(strNewDir, "%s/%s", strVideoDir, entry->d_name);
                TraverseDir_Num(strNewDir);
            } else {
                num += 1;
            }

        };

        chdir("..");
        closedir(dp);
        return num;
    }



    void main() {
        std::cout << "Hello THis is a Minecraft server of automatic backups app" + last << std::endl; //欢迎语句+计数
        sleep(3600*1000); //延迟1小时
        if num >= 3
        {
            string delfile1 = ".\\1\\*.*";
            string delfile2 = ".\\2\\*.*";
            rmdir(delfile1.c_str());
            rmdir(delfile2.c_str());


        }
        else
        {
            last = last + 1; //延迟+1

            //system(cd.c_str());
            string copy = "app + "\\rar" + "Rar.exe a -r -ep1 cd + "\\backups\\" +last +".zip" cd + "\\word\\*.*"";
            system(copy.c_str());

        }
        if last == 3
        {
            last = 1
        }





        return true; //返回true
    }



}
