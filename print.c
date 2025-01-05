void printAbout(){
    printf("ϵͳ��:kanban\n");
    printf("�汾��:0.0.1\n");
    printf("����:���κ�\n");
    printf("ѧ��:8007124056\n");
    printf("������:���ѧԺ����ռ䰲ȫרҵ2024��242��\n");
    printf("��ϵ��ʽ:19579858291\n");
    printf("����:Alizenty@outlook.com\n");
    printf("��������:2025��1��4��\n");
    printf("��������:C����\n");
    printf("��������:Windows\n");
    printf("��������:Dev-C++\n");
    printf("��Ŀ��ַ:https://github.com/zhangsanlzh/kanban\n");
    getchar();getchar();
}

void printHelp(){
    printf("��ӭʹ��kanbanϵͳ��������ҽ��ṩһЩ�����İ�����Ϣ\n");
    printf("�������ܣ�\n");
    printf("    kanban��һ������C���ԵĿ������ϵͳ�������԰����û������Լ��Ĺ������񣬲�����ֳɲ�ͬ�Ŀ��塣\n");
    printf("    ����Դ�����ɾ�����޸Ŀ��壬������ɾ�����޸����񣬲���������䵽��ͬ�Ŀ����С�\n");
    printf("    �����ͨ����ͬ����ͼ�鿴����Ľ��ȣ����������ȼ���״̬��ʱ��Ƚ���ɸѡ��\n");
    printf("    Ĭ������£���������񶼽��������ȼ��ɸߵ���������ʾ����ͬ���ȼ�������������ʾ�����е�����\n");
    printf("\n");
    printf("0.0.1�汾˵����\n");
    printf("    0.0.1�汾����˵�¼����������û�ͬʱʹ�ã�ÿ���û������Լ����û��������롣\n");
    printf("    ͬʱ��ϵͳ����ÿ���û������ݽ��ж����洢���û����Ե�ϵͳ�ļ��е�data�ļ������ҵ��Լ��������ļ���\n");
    printf("    δʵ�ֶ���ʱ���ݵĻ��棬����Ƿ������˳�����ô���β��������ݽ���ʧ��\n"); 
	printf("    ��ʱΪ���û������ݽ��м��ܴ����벻Ҫ��ϵͳ�д洢��Ҫ���ݣ�\n"); 
    printf("\n");
    printf("���ߵĻ���\n");
    printf("    ����һ���ǳ�������Ŀ�������԰�������������񣬲�����ֳɲ�ͬ�Ŀ��塣\n");
    printf("    ��Ӧ�ó���һ�������Ŀ���������Ƿ��ܰ�������߹���Ч�ʡ�\n");
    printf("\n");
    printf("ϵͳ���������У���ӭ���������������\n");
    printf("�����ͨ�����·�ʽ��ϵ�����ߣ�\n");
    printf("    ���κ�(8007124056)\n");
    printf("    ����:Alizenty@outlook.com\n");
    printf("����������µ�ַ�鿴��ĿԴ���룺\n");
    printf("    https://github.com/zhangsanlzh/kanban\n");
    printf("    ף����ˣ�\n");
    getchar();getchar();
}

void printTask(kanban **p, char name[51], int priority){
    for(int i=0;i<MAX_KANBAN;i++){
        if(strcmp(allKanban[i]->name, name) == 0){
            for(int j=0;j<MAX_TASK;j++){
                if(allKanban[i]->allTask[j].occupied == 1 && allKanban[i]->allTask[j].priority == priority){
                    if(allKanban[i]->allTask[j].status == DOING){
                        switch(allKanban[i]->allTask[j].priority){
                            case 0:
                                printf("    (LOW)");
                                break;
                            case 1:
                                printf("    (MIDDLE)");
                                break;
                            case 2:
                                printf("    (HIGH)");
                                break;
                        }
                        printf("(DOING)");
                        printf("%s\n        %s\n", 
                        allKanban[i]->allTask[j].name, allKanban[i]->allTask[j].content);
                    }
                    else if(allKanban[i]->allTask[j].status == TODO){
                        switch(allKanban[i]->allTask[j].priority){
                            case 0:
                                printf("    (LOW)");
                                break;
                            case 1:
                                printf("    (MIDDLE)");
                                break;
                            case 2:
                                printf("    (HIGH)");
                                break;
                        }
                        printf("(TODO)");
                        printf("%s\n        %s\n", 
                        allKanban[i]->allTask[j].name, allKanban[i]->allTask[j].content);
                    }
                    else if(allKanban[i]->allTask[j].status == DONE){
                        switch(allKanban[i]->allTask[j].priority){
                            case 0:
                                printf("    (LOW)");
                                break;
                            case 1:
                                printf("    (MIDDLE)");
                                break;
                            case 2:
                                printf("    (HIGH)");
                                break;
                        }
                        printf("(DONE)");
                        printf("%s\n        %s\n", 
                        allKanban[i]->allTask[j].name, allKanban[i]->allTask[j].content);
                    }
                }
            }
        }
    }
}

void printDoingTask(){
    for(int i=0;i<MAX_KANBAN;i++){
        if(allKanban[i]->occupied == 1){
            for(int j=0;j<MAX_TASK;j++){
                if(allKanban[i]->allTask[j].occupied == 1 && allKanban[i]->allTask[j].status == DOING){
                    switch(allKanban[i]->allTask[j].priority){
                            case 0:
                                printf("    (LOW)");
                                break;
                            case 1:
                                printf("    (MIDDLE)");
                                break;
                            case 2:
                                printf("    (HIGH)");
                                break;
                    }
                    printf("(DOING)");
                    printf("%s\n        %s\n", 
                    allKanban[i]->allTask[j].name, allKanban[i]->allTask[j].content);
                }
            }
        }
    }
    getchar();getchar();
}

void printKanban(int priority){
    for(int i=0;i<MAX_KANBAN;i++){
        if(allKanban[i]->occupied == 1 && allKanban[i]->priority == priority){
            switch(priority){
                case 0:
                    printf("(LOW)");
                    break;
                case 1:
                    printf("(MIDDLE)");
                    break;
                case 2:
                    printf("(HIGH)");
                    break;
            }
            printf("%s\n%s\n�����б�:\n",allKanban[i]->name, allKanban[i]->content);
            printTask(&allKanban[i], allKanban[i]->name, HIGH);
            printTask(&allKanban[i], allKanban[i]->name, MIDDLE);
            printTask(&allKanban[i], allKanban[i]->name, LOW);
            printf("\n");
        }
    }
}

void printProgressBar() {
    for (int i = 0; i <= 100; ++i) {
	int width = 50; // �������Ŀ��
    int pos = width * i / 100;
    
    printf("         [");
    for (int i = 0; i < width; ++i) {
        if (i < pos) printf("=");
        else if (i == pos) printf(">");
        else printf(" ");
    }
    printf("] %d %%\r", i);
    usleep(50000);
    fflush(stdout);
    }
    printf("\n");
}

void printLogo() {
	printf("\033[34m");
    printf("%s\n","          �����[  �����[ �����������[ �������[   �����[�������������[  �����������[ �������[   �����[");
    printf("%s\n","          �����U �����X�a�����X�T�T�����[���������[  �����U�����X�T�T�����[�����X�T�T�����[���������[  �����U");
    printf("%s\n","          �����������X�a ���������������U�����X�����[ �����U�������������X�a���������������U�����X�����[ �����U");
    printf("%s\n","          �����X�T�����[ �����X�T�T�����U�����U�^�����[�����U�����X�T�T�����[�����X�T�T�����U�����U�^�����[�����U");
    printf("%s\n","          �����U  �����[�����U  �����U�����U �^���������U�������������X�a�����U  �����U�����U �^���������U");
    printf("%s\n","          �^�T�a  �^�T�a�^�T�a  �^�T�a�^�T�a  �^�T�T�T�a�^�T�T�T�T�T�a �^�T�a  �^�T�a�^�T�a  �^�T�T�T�a");
    printf("%s\n","                                                    ");
    printf("                   kanban 0.0.1 ��Ȩ�����κ�����\n"); 
    printf("%s\n","                                                    ");
    printf("\033[32m");
}


void printMenu() {
    printf("+------------------------------------+\n");
    printf("|             �������ϵͳ           |\n");
    printf("+------------------------------------+\n");
    printf("| 1. ��������                        |\n");
    printf("| 2. ɾ������                        |\n");
    printf("| 3. �޸Ŀ���                        |\n");
    printf("| 4. ��������                        |\n");
    printf("| 5. ɾ������                        |\n");
    printf("| 6. �޸�����                        |\n");
    printf("| 7. ��ӡ���п���                    |\n");
    printf("| 8. ��ӡ�����е�����                |\n");
    printf("| 9. ����ϵͳ                        |\n");
    printf("| 10. ����                           |\n");
    printf("| 11. �˳�ϵͳ                       |\n");
    printf("+------------------------------------+\n");
}

void printChoose(){
    int choice;
    do{
    system("cls");
    printMenu();
    printf("������ѡ��: ");
do {
	    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 11) {
	        printf("ѡ��Ϸ���������1-11֮�������:");
	        getchar(); // ������뻺����
	        continue;
	    }
	    break;
	} while (1);  
	system("cls");  
	switch(choice){
        case 1:
            createKanban();
            break;
        case 2:
            deleteKanban();
            break;
        case 3:
            changeKanban();
            break;
        case 4:
            createTask();
            break;
        case 5:
            deleteTask();
            break;
        case 6:
            changeTask();
            break;
        case 7:
            printKanban(HIGH);
            printKanban(MIDDLE);
            printKanban(LOW);
            getchar();getchar();
            break;
        case 8:
            printDoingTask();
            break;
        case 9:
            printAbout();
            break;
        case 10:
            printHelp();
            break;
        case 11:
            save_kanbans_to_file(_name);
            save_persons_to_file();
            exit(0);
            break;
        default:
            printf("����������������룡");
            break;
    }
    }while(1);
}
