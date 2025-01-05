void load_kanbans_from_file(char *name) {
    char filename[256];
    snprintf(filename, sizeof(filename), ".\\data\\%s.txt", name);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        file = fopen(filename, "w+");  // 尝试以 "w+" 模式创建文件
        if (file == NULL) {
            perror("Failed to create file");
            return;
        }
        fclose(file);  // 创建文件后关闭，以便后续以 "r+" 模式打开
        file = fopen(filename, "r");
        if (file == NULL) {
            perror("Failed to open file after creation");
            return;
        }
    }

    for (int i = 0; i < MAX_KANBAN; i++) {
        if (fscanf(file, "%d %d %50s %200s %d\n", &allKanban[i]->occupied, &allKanban[i]->task_num, allKanban[i]->name, allKanban[i]->content, &allKanban[i]->priority) != 5) {
            break;  // 如果没有读取到五个值，认为文件读取结束或格式不正确
        }
        for (int j = 0; j < allKanban[i]->task_num; j++) {
            if (fscanf(file, "%d %50s %200s %d %d\n", &allKanban[i]->allTask[j].status, allKanban[i]->allTask[j].name, allKanban[i]->allTask[j].content, &allKanban[i]->allTask[j].priority, &allKanban[i]->allTask[j].occupied) != 5) {
                break;  // 如果没有读取到五个值，认为文件读取结束或格式不正确
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
        file = fopen(".\\data\\person.txt", "w+");  // 尝试以 "w+" 模式创建文件
        if (file == NULL) {
            perror("Failed to create file");
            return;
        }
        fclose(file);  // 创建文件后关闭，以便后续以 "r+" 模式打开
        file = fopen(".\\data\\person.txt", "r");
        if (file == NULL) {
            perror("Failed to open file after creation");
            return;
        }
    }

    for (int i = 0; i < MAX_PERSON; i++) {
        if (fscanf(file, "%d %50s %50s\n", &allPerson[i].occupied, allPerson[i].name, allPerson[i].password) != 3) {
            break;  // 如果没有读取到三个值，认为文件读取结束或格式不正确
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
        if (allPerson[i].occupied) {  // 假设只有当 occupied 为真时才保存
            fprintf(file, "%d %s %s\n", allPerson[i].occupied, allPerson[i].name, allPerson[i].password);
        }
    }

    fclose(file);
}
