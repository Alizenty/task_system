void changeKanban() {
	char continueChoice;
	int i;
    char name[51];
    printf("��������Ҫ�޸ĵĿ������ƣ�");
    do {
    	do{
        if (scanf("%50s", name) != 1) {
            printf("����������������뿴�����ƣ�");
            getchar(); // ������뻺����
            continue;
        }
        break;
    	}while(1);
        for (i = 0; i < MAX_KANBAN; i++) {
            if (strcmp(allKanban[i]->name, name) == 0) {
                do {
                    printf("������Ҫ�޸ĵ���Ŀ(0-����, 1-����, 2-���ȼ�): ");
                    int choice;
                    do {
                        if (scanf("%d", &choice) != 1 || (choice < 0 || choice > 2)) {
                            printf("�������������0-3֮������֣�");
                            getchar(); // ������뻺����
                            continue;
                        }
                        break;
                    } while (1);
                    while (getchar() != '\n'); // ������뻺����
                    switch (choice) {
                        case 0:
                        	printf("�������µĿ�������(���50�ַ�): ");
                            do {
                                if (scanf("%50s", allKanban[i]->name) != 1) {
                                    printf("����������������뿴�����ƣ�");
                                    getchar(); // ������뻺����
                                    continue;
                                }
                                break;
                            } while (1);
                            break;
                        case 1:
                        	printf("�������µĿ�������(���200�ַ�): ");
                            do {
                                if (scanf("%200s", allKanban[i]->content) != 1) {
                                    printf("����������������뿴��������");
                                    getchar(); // ������뻺����
                                    continue;
                                }
                                break;
                            } while (1);
                            break;
                        case 2:
                        	printf("�������µĿ������ȼ�(0-��, 1-��, 2-��): ");
                            do {
                                if (scanf("%d", &allKanban[i]->priority) != 1 || allKanban[i]->priority < 0 || allKanban[i]->priority > 2) {
                                    printf("���ȼ��������������0-2֮������֣�");
                                    getchar(); // ������뻺����
                                    continue;
                                }
                                break;
                            } while (1);
                            break;
                        default:
                            printf("����������������룡\n");
                            break;
                    }
                    printf("�����޸���Ŀ(y/n)? ");
                    scanf(" %c", &continueChoice); // ע��ǰ��Ŀո���������ǰ��Ļ��з�
                    while (getchar() != '\n'); // ������뻺����
                } while (continueChoice == 'y' || continueChoice == 'Y');
                break;
            }
        }
        if (i == MAX_KANBAN) { // ���û���ҵ����壬i ������ MAX_KANBAN
            printf("û�иÿ��壬���������뿴�����ƣ�");
        }
    } while (i == MAX_KANBAN);
    printf("�����޸ĳɹ���\n");
    getchar();
    system("cls");
}

void changeTask() {
    char continueChoice;
    char name[51];
    char taskName[51];
    int foundKanban = 0; // ��־����������ָʾ�Ƿ��ҵ�����
    int foundTask = 0;   // ��־����������ָʾ�Ƿ��ҵ�����
    printf("��������Ҫ�޸��������ڿ�������ƣ�");
    do {
        do {
            if (scanf("%50s", name) != 1) {
                printf("����������������룺");
                getchar(); // ������뻺����
                continue;
            }
            break;
        } while (1);

        foundKanban = 0; // ÿ��ѭ����ʼʱ���ÿ����־����
        for (int i = 0; i < MAX_KANBAN; i++) {
            if (strcmp(allKanban[i]->name, name) == 0) {
                foundKanban = 1;
                printf("��������Ҫ�޸���������ƣ�");
                do {
                    if (scanf("%50s", taskName) != 1) {
                        printf("����������������룺");
                        getchar(); // ������뻺����
                        continue;
                    }
                    break;
                } while (1);
                foundTask = 0; // ÿ��ѭ����ʼʱ���������־����
                for (int j = 0; j < MAX_TASK; j++) {
                    if (strcmp(allKanban[i]->allTask[j].name, taskName) == 0) {
                        foundTask = 1;
                        int found = 0;
                        do {
                            printf("������Ҫ�޸ĵ���Ŀ(0-����, 1-����, 2-���ȼ�, 3-״̬): ");
                            int choice;
                            do {
                                if (scanf("%d", &choice) != 1 || (choice < 0 || choice > 3)) {
                                    printf("�������������0-3֮������֣�");
                                    getchar(); // ������뻺����
                                    continue;
                                }
                                found = 1;
                                break;
                            } while (!found);

                            switch (choice) {
                                case 0:
                                    printf("�������µ���������(���50�ַ�): ");
                                    do {
                                        if (scanf("%50s", allKanban[i]->allTask[j].name) != 1) {
                                            printf("����������������룺");
                                            getchar(); // ������뻺����
                                            continue;
                                        }
                                        break;
                                    } while (1);
                                    break;
                                case 1:
                                    printf("�������µ���������(���200�ַ�): ");
                                    do {
                                        if (scanf("%200s", allKanban[i]->allTask[j].content) != 1) {
                                            printf("����������������룺");
                                            getchar(); // ������뻺����;
                                            continue;
                                        }
                                        break;
                                    } while (1);
                                    break;
                                case 2:
                                    printf("�������µ��������ȼ�(0-��, 1-��, 2-��): ");
                                    do {
                                        if (scanf("%d", &allKanban[i]->allTask[j].priority) != 1 || allKanban[i]->allTask[j].priority < 0 || allKanban[i]->allTask[j].priority > 2) {
                                            printf("���ȼ��������������0-2֮������֣�");
                                            getchar(); // ������뻺����
                                            continue;
                                        }
                                        break;
                                    } while (1);
                                    break;
                                case 3:
                                    printf("�������µ�����״̬(0-TODO, 1-DOING, 2-DONE): ");
                                    do {
                                        if (scanf("%d", &allKanban[i]->allTask[j].status) != 1 || allKanban[i]->allTask[j].status < 0 || allKanban[i]->allTask[j].status > 2) {
                                            printf("״̬�������������0-2֮������֣�");
                                            getchar(); // ������뻺����
                                            continue;
                                        }
                                        break;
                                    } while (1);
                                    break;
                                default:
                                    printf("����������������룡\n");
                                    break;
                            }
                            printf("�����޸���Ŀ(y/n)? ");
                            scanf(" %c", &continueChoice); // ע��ǰ��Ŀո���������ǰ��Ļ��з�
                            while (getchar() != '\n'); // ������뻺����
                        } while (continueChoice == 'y' || continueChoice == 'Y');
                        printf("�����޸ĳɹ���\n");
                        getchar();
                        system("cls");
                        return;
                    }
                }
                if (!foundTask) {
                    printf("û�и����������������������ƣ�");
                }
                break;
            }
        }
        if (!foundKanban) {
            printf("û�иÿ��壬���������뿴�����ƣ�");
        }
    } while (!foundKanban || !foundTask);
}
