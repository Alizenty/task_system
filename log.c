void enRoll(){
    for(int i=0;i<MAX_PERSON;i++){
        if(allPerson[i].occupied == 0){
            printf("�������û���(���50�ַ�): ");
            do {
                if (scanf("%50s", allPerson[i].name) != 1) {
                    printf("�����������������:");
                    getchar(); // ������뻺����
                    continue;
                }
                break;
            } while (1);
            printf("����������(���50�ַ�): ");
            do {
                if (scanf("%50s", allPerson[i].password) != 1) {
                    printf("�����������������:");
                    getchar(); // ������뻺����
                    continue;
                }
                break;
            } while (1);
            allPerson[i].occupied = 1;
            printf("�û�ע��ɹ���");
            getchar();getchar();
            system("cls");
            return;
        }
    }
    printf("�û�����,�޷�ע�����û�.");
    getchar();getchar();
    system("cls");
}

void login(){
    printf("�������û���: ");
    char name[51];
    do {
        if (scanf("%50s", name) != 1) {
            printf("�����������������:");
            getchar(); // ������뻺����
            continue;
        }
        break;
    } while (1);
    printf("����������: ");
    char password[51];
    do {
        if (scanf("%50s", password) != 1) {
            printf("�����������������:");
            getchar(); // ������뻺����
            continue;
        }
        break;
    } while (1);
    for(int i=0;i<MAX_PERSON;i++){
        if(strcmp(allPerson[i].name, name) == 0 && strcmp(allPerson[i].password, password) == 0){
            printf("��¼�ɹ���\n");
            strcpy(_name,name);
            load_kanbans_from_file(name);
            getchar();getchar();
            system("cls");
            printChoose();
            return;
        }
    }
    printf("�û���������������������룡");
    getchar();getchar();
    system("cls");
}
