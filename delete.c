void deleteKanban() {
    int found = 0;
    char name[51];
    printf("��������Ҫɾ���Ŀ������ƣ�");
    do {
    	do{
    	if (scanf("%50s", name) != 1) {
            printf("����������������뿴�����ƣ�");
            getchar(); // ������뻺����
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
            printf("û�иÿ��壬���������뿴�����ƣ�");
        }
    } while (!found);

    printf("����ɾ���ɹ���\n");
    getchar();getchar();
    system("cls");
}

void deleteTask() {
    int foundKanban = 0;
    int foundTask = 0;
    char name[51];
    char taskName[51];

    printf("��������Ҫɾ�����������ڿ�������ƣ�");
    do {
        do{
    	if (scanf("%50s", name) != 1) {
            printf("����������������뿴�����ƣ�");
            getchar(); // ������뻺����
            continue;
        }
        break;
		}while(1);
        for (int i = 0; i < MAX_KANBAN; i++) {
            if (strcmp(allKanban[i]->name, name) == 0) {
                foundKanban = 1;
                printf("��������Ҫɾ������������ƣ�");
                do {
                	do{
                    if (scanf("%50s", taskName) != 1) {
                        printf("������������������������ƣ�");
                        getchar(); // ������뻺����
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
                        printf("û�и����������������������ƣ�");
                    }
                } while (!foundTask);
                break;
            }
        }
        if (!foundKanban) {
            printf("û�иÿ��壬���������뿴�����ƣ�");
        }
    } while (!foundKanban);

    printf("����ɾ���ɹ���\n");
    getchar();getchar();
    system("cls");
}
