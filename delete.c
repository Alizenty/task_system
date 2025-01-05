void deleteKanban() {
    int found = 0;
    char name[51];
    printf("请输入想要删除的看板名称：");
    do {
    	do{
    	if (scanf("%50s", name) != 1) {
            printf("输入错误，请重新输入看板名称：");
            getchar(); // 清除输入缓冲区
            continue;
        }
        break;
	}while(1);
        for (int i = 0; i < MAX_KANBAN; i++) {
            if (strcmp(allKanban[i]->name, name) == 0) {
                allKanban[i]->occupied = 0;
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("没有该看板，请重新输入看板名称：");
        }
    } while (!found);

    printf("看板删除成功！\n");
    getchar();getchar();
    system("cls");
}

void deleteTask() {
    int foundKanban = 0;
    int foundTask = 0;
    char name[51];
    char taskName[51];

    printf("请输入想要删除的任务所在看板的名称：");
    do {
        do{
    	if (scanf("%50s", name) != 1) {
            printf("输入错误，请重新输入看板名称：");
            getchar(); // 清除输入缓冲区
            continue;
        }
        break;
		}while(1);
        for (int i = 0; i < MAX_KANBAN; i++) {
            if (strcmp(allKanban[i]->name, name) == 0) {
                foundKanban = 1;
                printf("请输入想要删除的任务的名称：");
                do {
                	do{
                    if (scanf("%50s", taskName) != 1) {
                        printf("输入错误，请重新输入任务名称：");
                        getchar(); // 清除输入缓冲区
                        continue;
                    }
                    break;
                	}while(1);
                    for (int j = 0; j < MAX_TASK; j++) {
                        if (strcmp(allKanban[i]->allTask[j].name, taskName) == 0) {
                            allKanban[i]->allTask[j].occupied = 0;
                            foundTask = 1;
                            break;
                        }
                    }
                    if (!foundTask) {
                        printf("没有该任务，请重新输入任务名称：");
                    }
                } while (!foundTask);
                break;
            }
        }
        if (!foundKanban) {
            printf("没有该看板，请重新输入看板名称：");
        }
    } while (!foundKanban);

    printf("任务删除成功！\n");
    getchar();getchar();
    system("cls");
}
