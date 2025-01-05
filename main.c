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
    printf("|           ��ӭʹ���������ϵͳ��  |\n");
    printf("+---------------------------------- +\n");
    printf("| 1. ע��                           |\n");
    printf("| 2. ��¼                           |\n");
    printf("| 3. �˳�ϵͳ                       |\n");
    printf("+---------------------------------- +\n");
    printf("������ѡ��: ");
    
    do {
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
            printf("ѡ��Ϸ���������1-3֮�������:");
            getchar(); // ������뻺����
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
            printf("����������������룡");
            break;
    }
    }while(1);
    freeAllKanban();
    return 0;
}
