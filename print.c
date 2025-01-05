void printAbout(){
    printf("系统名:kanban\n");
    printf("版本号:0.0.1\n");
    printf("开发语言:C语言\n");
    printf("开发环境:Windows\n");
    printf("开发工具:Dev-C++\n");
    printf("项目地址:https://github.com/zhangsanlzh/kanban\n");
    getchar();getchar();
}

void printHelp(){
    printf("欢迎使用kanban系统！在这里，我将提供一些基本的帮助信息\n");
    printf("基本功能：\n");
    printf("    kanban是一个基于C语言的看板管理系统，它可以帮助用户管理自己的工作任务，并将其分成不同的看板。\n");
    printf("    你可以创建、删除、修改看板，创建、删除、修改任务，并将任务分配到不同的看板中。\n");
    printf("    你可以通过不同的视图查看任务的进度，并根据优先级、状态、时间等进行筛选。\n");
    printf("    默认情况下，看板和任务都将按照优先级由高到低依次显示，相同优先级的任务，优先显示进行中的任务。\n");
    printf("\n");
    printf("0.0.1版本说明：\n");
    printf("    0.0.1版本添加了登录管理，允许多用户同时使用，每个用户都有自己的用户名和密码。\n");
    printf("    同时，系统将对每个用户的数据进行独立存储，用户可以到系统文件中的data文件夹中找到自己的数据文件。\n");
    printf("    未实现对暂时数据的缓存，如果是非正常退出，那么本次操作的数据将丢失！\n"); 
    printf("    暂时为对用户的数据进行加密处理，请不要在系统中存储重要数据！\n"); 
    printf("\n");
    printf("编者的话：\n");
    printf("    这是一个非常棒的项目，它可以帮助你管理工作任务，并将其分成不同的看板。\n");
    printf("    你应该尝试一下这个项目，看看它是否能帮助你提高工作效率。\n");
    printf("\n");
    printf("你可以在以下地址查看项目源代码：\n");
    printf("    https://github.com/zhangsanlzh/kanban\n");
    printf("    祝你好运！\n");
    getchar();getchar();
}

void printTask(kanban **p, char name[51], int priority){
    for(int i=0;i<MAX_KANBAN;i++){
        if(strcmp(allKanban[i]->name, name) == 0){
            for(int j=0;j<MAX_TASK;j++){
                if(allKanban[i]->allTask[j].occupied == 1 && allKanban[i]->allTask[j].priority == priority){
                    if(allKanban[i]->allTask[j].status == DOING){
                        switch(allKanban[i]->allTask[j].priority){
                            case 0:
                                printf("    (LOW)");
                                break;
                            case 1:
                                printf("    (MIDDLE)");
                                break;
                            case 2:
                                printf("    (HIGH)");
                                break;
                        }
                        printf("(DOING)");
                        printf("%s\n        %s\n", 
                        allKanban[i]->allTask[j].name, allKanban[i]->allTask[j].content);
                    }
                    else if(allKanban[i]->allTask[j].status == TODO){
                        switch(allKanban[i]->allTask[j].priority){
                            case 0:
                                printf("    (LOW)");
                                break;
                            case 1:
                                printf("    (MIDDLE)");
                                break;
                            case 2:
                                printf("    (HIGH)");
                                break;
                        }
                        printf("(TODO)");
                        printf("%s\n        %s\n", 
                        allKanban[i]->allTask[j].name, allKanban[i]->allTask[j].content);
                    }
                    else if(allKanban[i]->allTask[j].status == DONE){
                        switch(allKanban[i]->allTask[j].priority){
                            case 0:
                                printf("    (LOW)");
                                break;
                            case 1:
                                printf("    (MIDDLE)");
                                break;
                            case 2:
                                printf("    (HIGH)");
                                break;
                        }
                        printf("(DONE)");
                        printf("%s\n        %s\n", 
                        allKanban[i]->allTask[j].name, allKanban[i]->allTask[j].content);
                    }
                }
            }
        }
    }
}

void printDoingTask(){
    for(int i=0;i<MAX_KANBAN;i++){
        if(allKanban[i]->occupied == 1){
            for(int j=0;j<MAX_TASK;j++){
                if(allKanban[i]->allTask[j].occupied == 1 && allKanban[i]->allTask[j].status == DOING){
                    switch(allKanban[i]->allTask[j].priority){
                            case 0:
                                printf("    (LOW)");
                                break;
                            case 1:
                                printf("    (MIDDLE)");
                                break;
                            case 2:
                                printf("    (HIGH)");
                                break;
                    }
                    printf("(DOING)");
                    printf("%s\n        %s\n", 
                    allKanban[i]->allTask[j].name, allKanban[i]->allTask[j].content);
                }
            }
        }
    }
    getchar();getchar();
}

void printKanban(int priority){
    for(int i=0;i<MAX_KANBAN;i++){
        if(allKanban[i]->occupied == 1 && allKanban[i]->priority == priority){
            switch(priority){
                case 0:
                    printf("(LOW)");
                    break;
                case 1:
                    printf("(MIDDLE)");
                    break;
                case 2:
                    printf("(HIGH)");
                    break;
            }
            printf("%s\n%s\n任务列表:\n",allKanban[i]->name, allKanban[i]->content);
            printTask(&allKanban[i], allKanban[i]->name, HIGH);
            printTask(&allKanban[i], allKanban[i]->name, MIDDLE);
            printTask(&allKanban[i], allKanban[i]->name, LOW);
            printf("\n");
        }
    }
}

void printProgressBar() {
    for (int i = 0; i <= 100; ++i) {
	int width = 50; // 进度条的宽度
    int pos = width * i / 100;
    
    printf("         [");
    for (int i = 0; i < width; ++i) {
        if (i < pos) printf("=");
        else if (i == pos) printf(">");
        else printf(" ");
    }
    printf("] %d %%\r", i);
    usleep(50000);
    fflush(stdout);
    }
    printf("\n");
}

void printLogo() {
	printf("\033[34m");
    printf("%s\n","          ██╗  ██╗ █████╗ ███╗   ██╗██████╗  █████╗ ███╗   ██╗");
    printf("%s\n","          ██║ ██╔╝██╔══██╗████╗  ██║██╔══██╗██╔══██╗████╗  ██║");
    printf("%s\n","          █████╔╝ ███████║██╔██╗ ██║██████╔╝███████║██╔██╗ ██║");
    printf("%s\n","          ██╔═██╗ ██╔══██║██║╚██╗██║██╔══██╗██╔══██║██║╚██╗██║");
    printf("%s\n","          ██║  ██╗██║  ██║██║ ╚████║██████╔╝██║  ██║██║ ╚████║");
    printf("%s\n","          ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝");
    printf("%s\n","                                                    ");
    printf("                   kanban 0.0.1 版权归易梦翰所有\n"); 
    printf("%s\n","                                                    ");
    printf("\033[32m");
}


void printMenu() {
    printf("+------------------------------------+\n");
    printf("|             任务管理系统           |\n");
    printf("+------------------------------------+\n");
    printf("| 1. 创建看板                        |\n");
    printf("| 2. 删除看板                        |\n");
    printf("| 3. 修改看板                        |\n");
    printf("| 4. 创建任务                        |\n");
    printf("| 5. 删除任务                        |\n");
    printf("| 6. 修改任务                        |\n");
    printf("| 7. 打印所有看板                    |\n");
    printf("| 8. 打印进行中的任务                |\n");
    printf("| 9. 关于系统                        |\n");
    printf("| 10. 帮助                           |\n");
    printf("| 11. 退出系统                       |\n");
    printf("+------------------------------------+\n");
}

void printChoose(){
    int choice;
    do{
    system("cls");
    printMenu();
    printf("请输入选项: ");
do {
	    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 11) {
	        printf("选项不合法，请输入1-11之间的数字:");
	        getchar(); // 清除输入缓冲区
	        continue;
	    }
	    break;
	} while (1);  
	system("cls");  
	switch(choice){
        case 1:
            createKanban();
            break;
        case 2:
            deleteKanban();
            break;
        case 3:
            changeKanban();
            break;
        case 4:
            createTask();
            break;
        case 5:
            deleteTask();
            break;
        case 6:
            changeTask();
            break;
        case 7:
            printKanban(HIGH);
            printKanban(MIDDLE);
            printKanban(LOW);
            getchar();getchar();
            break;
        case 8:
            printDoingTask();
            break;
        case 9:
            printAbout();
            break;
        case 10:
            printHelp();
            break;
        case 11:
            save_kanbans_to_file(_name);
            save_persons_to_file();
            exit(0);
            break;
        default:
            printf("输入错误，请重新输入！");
            break;
    }
    }while(1);
}
