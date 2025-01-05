void load_kanbans_from_file(char *name) {
    char filename[256];
    snprintf(filename, sizeof(filename), ".\\data\\%s.txt", name);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        file = fopen(filename, "w+");  // ������ "w+" ģʽ�����ļ�
        if (file == NULL) {
            perror("Failed to create file");
            return;
        }
        fclose(file);  // �����ļ���رգ��Ա������ "r+" ģʽ��
        file = fopen(filename, "r");
        if (file == NULL) {
            perror("Failed to open file after creation");
            return;
        }
    }

    for (int i = 0; i < MAX_KANBAN; i++) {
        if (fscanf(file, "%d %d %50s %200s %d\n", &allKanban[i]->occupied, &allKanban[i]->task_num, allKanban[i]->name, allKanban[i]->content, &allKanban[i]->priority) != 5) {
            break;  // ���û�ж�ȡ�����ֵ����Ϊ�ļ���ȡ�������ʽ����ȷ
        }
        for (int j = 0; j < allKanban[i]->task_num; j++) {
            if (fscanf(file, "%d %50s %200s %d %d\n", &allKanban[i]->allTask[j].status, allKanban[i]->allTask[j].name, allKanban[i]->allTask[j].content, &allKanban[i]->allTask[j].priority, &allKanban[i]->allTask[j].occupied) != 5) {
                break;  // ���û�ж�ȡ�����ֵ����Ϊ�ļ���ȡ�������ʽ����ȷ
            }
        }
    }

    fclose(file);
}

void save_kanbans_to_file(char *name) {
    char filename[256];
    snprintf(filename, sizeof(filename), ".\\data\\%s.txt", name);

    FILE *file = fopen(filename, "w+");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < MAX_KANBAN; i++) {
        if (allKanban[i]->occupied == 1) {
            fprintf(file, "%d %d %s %s %d\n", allKanban[i]->occupied, allKanban[i]->task_num, allKanban[i]->name, allKanban[i]->content, allKanban[i]->priority);
            for (int j = 0; j < allKanban[i]->task_num; j++) {
                if (allKanban[i]->allTask[j].occupied == 1) {
                    fprintf(file, "%d %s %s %d %d\n", allKanban[i]->allTask[j].status, allKanban[i]->allTask[j].name, allKanban[i]->allTask[j].content, allKanban[i]->allTask[j].priority, allKanban[i]->allTask[j].occupied);
                }
            }
        }
    }

    fclose(file);
}

void load_persons_from_file() {
    FILE *file = fopen(".\\data\\person.txt", "r");
    if (file == NULL) {
        file = fopen(".\\data\\person.txt", "w+");  // ������ "w+" ģʽ�����ļ�
        if (file == NULL) {
            perror("Failed to create file");
            return;
        }
        fclose(file);  // �����ļ���رգ��Ա������ "r+" ģʽ��
        file = fopen(".\\data\\person.txt", "r");
        if (file == NULL) {
            perror("Failed to open file after creation");
            return;
        }
    }

    for (int i = 0; i < MAX_PERSON; i++) {
        if (fscanf(file, "%d %50s %50s\n", &allPerson[i].occupied, allPerson[i].name, allPerson[i].password) != 3) {
            break;  // ���û�ж�ȡ������ֵ����Ϊ�ļ���ȡ�������ʽ����ȷ
        }
    }

    fclose(file);
}

void save_persons_to_file() {
    FILE *file = fopen(".\\data\\person.txt", "w+");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < MAX_PERSON; i++) {
        if (allPerson[i].occupied) {  // ����ֻ�е� occupied Ϊ��ʱ�ű���
            fprintf(file, "%d %s %s\n", allPerson[i].occupied, allPerson[i].name, allPerson[i].password);
        }
    }

    fclose(file);
}
