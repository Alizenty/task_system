char _name[50];

typedef struct {
    int occupied;
    char name[51];    
    char content[201];
    int priority;
    int status; 
} task;

typedef struct {
    int occupied;
    char name[51];
    char content[201];
    task allTask[MAX_TASK];
    int priority;
    int task_num;
} kanban;

typedef struct {
    int occupied;
    char name[51];
    char password[51];
} person;

kanban *allKanban[MAX_KANBAN];
person allPerson[MAX_PERSON];

void start() {
    for (int j = 0; j < MAX_PERSON; j++) {
        allPerson[j].occupied = 0;
        snprintf(allPerson[j].name, sizeof(allPerson[j].name), "none");
        snprintf(allPerson[j].password, sizeof(allPerson[j].password), "none");
    }
    for (int i = 0; i < MAX_KANBAN; i++) {
        allKanban[i] = (kanban*)malloc(sizeof(kanban));
        if (allKanban[i] == NULL) {
            perror("Failed to allocate memory for kanban");
            exit(EXIT_FAILURE);
        }
        allKanban[i]->occupied = 0;
        for (int j = 0; j < MAX_TASK; j++) {
            allKanban[i]->allTask[j].occupied = 0;
        }
    }
}

void freeAllKanban() {
    for (int i = 0; i < MAX_KANBAN; i++) {
        if (allKanban[i] != NULL) {
            free(allKanban[i]);
        }
    }
}
