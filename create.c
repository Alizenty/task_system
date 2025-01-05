void createKanban() {
    int found = 0;
    for (int i = 0; i < MAX_KANBAN; i++) {
        if (allKanban[i]->occupied == 0) {
            found = 1;
            printf("请输入kanban名称(最多50字符): ");
            do {
                if (scanf("%50s", allKanban[i]->name) != 1) {
                    printf("输入错误，请重新输入:");
                    getchar(); // 清除输入缓冲区
                    continue;
                }
                break;
            } while (1);

            printf("请输入kanban描述(最多200字符): ");
            do {
                if (scanf("%200s", allKanban[i]->content) != 1) {
                    printf("输入错误，请重新输入:");
                    getchar(); // 清除输入缓冲区
                    continue;
                }
                break;
            } while (1);

            printf("请输入kanban优先级(0-低, 1-中, 2-高): ");
            int priority;
            do {
                if (scanf("%d", &priority) != 1 || priority < 0 || priority > 2) {
                    printf("优先级输入错误，请输入0-2之间的数字:");
                    getchar(); // 清除输入缓冲区
                    continue;
                }
                break;
            } while (1);

            allKanban[i]->priority = priority;
            allKanban[i]->task_num = 0;
            allKanban[i]->occupied = 1;
            printf("看板创建成功！\n");
            getchar();getchar();
            system("cls");
            return;
        }
    }
    if (!found) {
        printf("看板已满,无法创建新的看板.\n");
    }
}

void createTask() {
    char name[51];
    printf("请输入想要添加任务的看板名称：");
    do {
        do {
            if (scanf("%50s", name) != 1) {
                printf("输入错误，请重新输入:");
                getchar(); // 清除输入缓冲区
                continue;
            }
            break;
        } while (1);

        for (int i = 0; i < MAX_KANBAN; i++) {
            if (strcmp(allKanban[i]->name, name) == 0) {
                for (int j = 0; j < MAX_TASK; j++) {
                    if (allKanban[i]->allTask[j].occupied == 0) {
                        printf("请输入任务名称(最多50字符): ");
                        do {
                            if (scanf("%50s", allKanban[i]->allTask[j].name) != 1) {
                                printf("输入错误，请重新输入：");\
                                getchar(); // 清除输入缓冲区
                                continue; 
                            }
                            break;
                        } while (1);

                        printf("请输入任务内容(最多200字符): ");
                        do {
                            if (scanf("%200s", allKanban[i]->allTask[j].content) != 1) {
                                printf("输入错误，请重新输入:");
                                getchar(); // 清除输入缓冲区
                                continue;
                            }
                            break;
                        } while (1);

                        printf("请输入任务优先级(0-低, 1-中, 2-高): ");
                        int priority;
                        do {
                            if (scanf("%d", &priority) != 1 || priority < 0 || priority > 2) {
                                printf("优先级输入错误，请输入0-2之间的数字:");
                                getchar(); // 清除输入缓冲区
                                continue;
                            }
                            break;
                        } while (1);

                        allKanban[i]->allTask[j].priority = priority;
                        allKanban[i]->allTask[j].status = TODO;
                        allKanban[i]->allTask[j].occupied = 1;
                        allKanban[i]->task_num++;
                        printf("任务创建成功！\n");
                        getchar();getchar();
            			system("cls");
                        return;
                    }
                }
                printf("看板已满,无法创建新的任务.\n");
                getchar();getchar();
            	system("cls");
                return;
            }
        }
        printf("没有该看板，请重新输入看板名称：");
    } while (1);
}
