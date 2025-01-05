void changeKanban() {
	char continueChoice;
	int i;
    char name[51];
    printf("请输入想要修改的看板名称：");
    do {
    	do{
        if (scanf("%50s", name) != 1) {
            printf("输入错误，请重新输入看板名称：");
            getchar(); // 清除输入缓冲区
            continue;
        }
        break;
    	}while(1);
        for (i = 0; i < MAX_KANBAN; i++) {
            if (strcmp(allKanban[i]->name, name) == 0) {
                do {
                    printf("输入想要修改的项目(0-名称, 1-描述, 2-优先级): ");
                    int choice;
                    do {
                        if (scanf("%d", &choice) != 1 || (choice < 0 || choice > 2)) {
                            printf("输入错误，请输入0-3之间的数字：");
                            getchar(); // 清除输入缓冲区
                            continue;
                        }
                        break;
                    } while (1);
                    while (getchar() != '\n'); // 清除输入缓冲区
                    switch (choice) {
                        case 0:
                        	printf("请输入新的看板名称(最多50字符): ");
                            do {
                                if (scanf("%50s", allKanban[i]->name) != 1) {
                                    printf("输入错误，请重新输入看板名称：");
                                    getchar(); // 清除输入缓冲区
                                    continue;
                                }
                                break;
                            } while (1);
                            break;
                        case 1:
                        	printf("请输入新的看板描述(最多200字符): ");
                            do {
                                if (scanf("%200s", allKanban[i]->content) != 1) {
                                    printf("输入错误，请重新输入看板描述：");
                                    getchar(); // 清除输入缓冲区
                                    continue;
                                }
                                break;
                            } while (1);
                            break;
                        case 2:
                        	printf("请输入新的看板优先级(0-低, 1-中, 2-高): ");
                            do {
                                if (scanf("%d", &allKanban[i]->priority) != 1 || allKanban[i]->priority < 0 || allKanban[i]->priority > 2) {
                                    printf("优先级输入错误，请输入0-2之间的数字：");
                                    getchar(); // 清除输入缓冲区
                                    continue;
                                }
                                break;
                            } while (1);
                            break;
                        default:
                            printf("输入错误，请重新输入！\n");
                            break;
                    }
                    printf("继续修改项目(y/n)? ");
                    scanf(" %c", &continueChoice); // 注意前面的空格，用于跳过前面的换行符
                    while (getchar() != '\n'); // 清除输入缓冲区
                } while (continueChoice == 'y' || continueChoice == 'Y');
                break;
            }
        }
        if (i == MAX_KANBAN) { // 如果没有找到看板，i 将等于 MAX_KANBAN
            printf("没有该看板，请重新输入看板名称：");
        }
    } while (i == MAX_KANBAN);
    printf("看板修改成功！\n");
    getchar();
    system("cls");
}

void changeTask() {
    char continueChoice;
    char name[51];
    char taskName[51];
    int foundKanban = 0; // 标志变量，用于指示是否找到看板
    int foundTask = 0;   // 标志变量，用于指示是否找到任务
    printf("请输入想要修改任务所在看板的名称：");
    do {
        do {
            if (scanf("%50s", name) != 1) {
                printf("输入错误，请重新输入：");
                getchar(); // 清除输入缓冲区
                continue;
            }
            break;
        } while (1);

        foundKanban = 0; // 每次循环开始时重置看板标志变量
        for (int i = 0; i < MAX_KANBAN; i++) {
            if (strcmp(allKanban[i]->name, name) == 0) {
                foundKanban = 1;
                printf("请输入想要修改任务的名称：");
                do {
                    if (scanf("%50s", taskName) != 1) {
                        printf("输入错误，请重新输入：");
                        getchar(); // 清除输入缓冲区
                        continue;
                    }
                    break;
                } while (1);
                foundTask = 0; // 每次循环开始时重置任务标志变量
                for (int j = 0; j < MAX_TASK; j++) {
                    if (strcmp(allKanban[i]->allTask[j].name, taskName) == 0) {
                        foundTask = 1;
                        int found = 0;
                        do {
                            printf("输入想要修改的项目(0-名称, 1-内容, 2-优先级, 3-状态): ");
                            int choice;
                            do {
                                if (scanf("%d", &choice) != 1 || (choice < 0 || choice > 3)) {
                                    printf("输入错误，请输入0-3之间的数字：");
                                    getchar(); // 清除输入缓冲区
                                    continue;
                                }
                                found = 1;
                                break;
                            } while (!found);

                            switch (choice) {
                                case 0:
                                    printf("请输入新的任务名称(最多50字符): ");
                                    do {
                                        if (scanf("%50s", allKanban[i]->allTask[j].name) != 1) {
                                            printf("输入错误，请重新输入：");
                                            getchar(); // 清除输入缓冲区
                                            continue;
                                        }
                                        break;
                                    } while (1);
                                    break;
                                case 1:
                                    printf("请输入新的任务内容(最多200字符): ");
                                    do {
                                        if (scanf("%200s", allKanban[i]->allTask[j].content) != 1) {
                                            printf("输入错误，请重新输入：");
                                            getchar(); // 清除输入缓冲区;
                                            continue;
                                        }
                                        break;
                                    } while (1);
                                    break;
                                case 2:
                                    printf("请输入新的任务优先级(0-低, 1-中, 2-高): ");
                                    do {
                                        if (scanf("%d", &allKanban[i]->allTask[j].priority) != 1 || allKanban[i]->allTask[j].priority < 0 || allKanban[i]->allTask[j].priority > 2) {
                                            printf("优先级输入错误，请输入0-2之间的数字：");
                                            getchar(); // 清除输入缓冲区
                                            continue;
                                        }
                                        break;
                                    } while (1);
                                    break;
                                case 3:
                                    printf("请输入新的任务状态(0-TODO, 1-DOING, 2-DONE): ");
                                    do {
                                        if (scanf("%d", &allKanban[i]->allTask[j].status) != 1 || allKanban[i]->allTask[j].status < 0 || allKanban[i]->allTask[j].status > 2) {
                                            printf("状态输入错误，请输入0-2之间的数字：");
                                            getchar(); // 清除输入缓冲区
                                            continue;
                                        }
                                        break;
                                    } while (1);
                                    break;
                                default:
                                    printf("输入错误，请重新输入！\n");
                                    break;
                            }
                            printf("继续修改项目(y/n)? ");
                            scanf(" %c", &continueChoice); // 注意前面的空格，用于跳过前面的换行符
                            while (getchar() != '\n'); // 清除输入缓冲区
                        } while (continueChoice == 'y' || continueChoice == 'Y');
                        printf("任务修改成功！\n");
                        getchar();
                        system("cls");
                        return;
                    }
                }
                if (!foundTask) {
                    printf("没有该任务，请重新输入任务名称：");
                }
                break;
            }
        }
        if (!foundKanban) {
            printf("没有该看板，请重新输入看板名称：");
        }
    } while (!foundKanban || !foundTask);
}
