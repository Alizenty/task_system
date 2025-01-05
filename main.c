#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

#define TODO 0
#define DOING 1
#define DONE 2
#define LOW 0
#define MIDDLE 1
#define HIGH 2
#define MAX_KANBAN 20
#define MAX_TASK 20
#define MAX_PERSON 10

#include "struct.c"
#include "io.c"
#include "create.c" 
#include "delete.c" 
#include "change.c" 
#include "print.c" 
#include "log.c" 

int main() {
    start();
    load_persons_from_file();
    printLogo();
    printProgressBar();
    system("cls");
    int choice;
    do{
    printf("+---------------------------------- +\n");
    printf("|           欢迎使用任务管理系统！  |\n");
    printf("+---------------------------------- +\n");
    printf("| 1. 注册                           |\n");
    printf("| 2. 登录                           |\n");
    printf("| 3. 退出系统                       |\n");
    printf("+---------------------------------- +\n");
    printf("请输入选项: ");
    
    do {
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
            printf("选项不合法，请输入1-3之间的数字:");
            getchar(); // 清除输入缓冲区
            continue;
        }
        break;
    } while (1);
    system("cls"); 
    switch(choice){
        case 1:
            enRoll();
            break;
        case 2:
            login();
            break;
        case 3:
            save_persons_to_file();
            exit(0);
            break;
        default:
            printf("输入错误，请重新输入！");
            break;
    }
    }while(1);
    freeAllKanban();
    return 0;
}
