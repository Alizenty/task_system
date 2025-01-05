void enRoll(){
    for(int i=0;i<MAX_PERSON;i++){
        if(allPerson[i].occupied == 0){
            printf("请输入用户名(最多50字符): ");
            do {
                if (scanf("%50s", allPerson[i].name) != 1) {
                    printf("输入错误，请重新输入:");
                    getchar(); // 清除输入缓冲区
                    continue;
                }
                break;
            } while (1);
            printf("请输入密码(最多50字符): ");
            do {
                if (scanf("%50s", allPerson[i].password) != 1) {
                    printf("输入错误，请重新输入:");
                    getchar(); // 清除输入缓冲区
                    continue;
                }
                break;
            } while (1);
            allPerson[i].occupied = 1;
            printf("用户注册成功！");
            getchar();getchar();
            system("cls");
            return;
        }
    }
    printf("用户已满,无法注册新用户.");
    getchar();getchar();
    system("cls");
}

void login(){
    printf("请输入用户名: ");
    char name[51];
    do {
        if (scanf("%50s", name) != 1) {
            printf("输入错误，请重新输入:");
            getchar(); // 清除输入缓冲区
            continue;
        }
        break;
    } while (1);
    printf("请输入密码: ");
    char password[51];
    do {
        if (scanf("%50s", password) != 1) {
            printf("输入错误，请重新输入:");
            getchar(); // 清除输入缓冲区
            continue;
        }
        break;
    } while (1);
    for(int i=0;i<MAX_PERSON;i++){
        if(strcmp(allPerson[i].name, name) == 0 && strcmp(allPerson[i].password, password) == 0){
            printf("登录成功！\n");
            strcpy(_name,name);
            load_kanbans_from_file(name);
            getchar();getchar();
            system("cls");
            printChoose();
            return;
        }
    }
    printf("用户名或密码错误，请重新输入！");
    getchar();getchar();
    system("cls");
}
