void createKanban() {
    int found = 0;
    for (int i = 0; i < MAX_KANBAN; i++) {
        if (allKanban[i]->occupied == 0) {
            found = 1;
            printf("������kanban����(���50�ַ�): ");
            do {
                if (scanf("%50s", allKanban[i]->name) != 1) {
                    printf("�����������������:");
                    getchar(); // ������뻺����
                    continue;
                }
                break;
            } while (1);

            printf("������kanban����(���200�ַ�): ");
            do {
                if (scanf("%200s", allKanban[i]->content) != 1) {
                    printf("�����������������:");
                    getchar(); // ������뻺����
                    continue;
                }
                break;
            } while (1);

            printf("������kanban���ȼ�(0-��, 1-��, 2-��): ");
            int priority;
            do {
                if (scanf("%d", &priority) != 1 || priority < 0 || priority > 2) {
                    printf("���ȼ��������������0-2֮�������:");
                    getchar(); // ������뻺����
                    continue;
                }
                break;
            } while (1);

            allKanban[i]->priority = priority;
            allKanban[i]->task_num = 0;
            allKanban[i]->occupied = 1;
            printf("���崴���ɹ���\n");
            getchar();getchar();
            system("cls");
            return;
        }
    }
    if (!found) {
        printf("��������,�޷������µĿ���.\n");
    }
}

void createTask() {
    char name[51];
    printf("��������Ҫ�������Ŀ������ƣ�");
    do {
        do {
            if (scanf("%50s", name) != 1) {
                printf("�����������������:");
                getchar(); // ������뻺����
                continue;
            }
            break;
        } while (1);

        for (int i = 0; i < MAX_KANBAN; i++) {
            if (strcmp(allKanban[i]->name, name) == 0) {
                for (int j = 0; j < MAX_TASK; j++) {
                    if (allKanban[i]->allTask[j].occupied == 0) {
                        printf("��������������(���50�ַ�): ");
                        do {
                            if (scanf("%50s", allKanban[i]->allTask[j].name) != 1) {
                                printf("����������������룺");\
                                getchar(); // ������뻺����
                                continue; 
                            }
                            break;
                        } while (1);

                        printf("��������������(���200�ַ�): ");
                        do {
                            if (scanf("%200s", allKanban[i]->allTask[j].content) != 1) {
                                printf("�����������������:");
                                getchar(); // ������뻺����
                                continue;
                            }
                            break;
                        } while (1);

                        printf("�������������ȼ�(0-��, 1-��, 2-��): ");
                        int priority;
                        do {
                            if (scanf("%d", &priority) != 1 || priority < 0 || priority > 2) {
                                printf("���ȼ��������������0-2֮�������:");
                                getchar(); // ������뻺����
                                continue;
                            }
                            break;
                        } while (1);

                        allKanban[i]->allTask[j].priority = priority;
                        allKanban[i]->allTask[j].status = TODO;
                        allKanban[i]->allTask[j].occupied = 1;
                        allKanban[i]->task_num++;
                        printf("���񴴽��ɹ���\n");
                        getchar();getchar();
            			system("cls");
                        return;
                    }
                }
                printf("��������,�޷������µ�����.\n");
                getchar();getchar();
            	system("cls");
                return;
            }
        }
        printf("û�иÿ��壬���������뿴�����ƣ�");
    } while (1);
}
