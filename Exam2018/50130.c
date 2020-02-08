#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char user[40][35];
int bal[40];
char ins[100];
char file[5][100];
int n;
int delock(char *a){
    if(strstr(a, "earns") != NULL)
        return 1;
    else if(strstr(a, "spends") !=  NULL)
        return 2;
    else if(strstr(a, "becomes") != NULL)
        return 3;
    else if(strstr(a, "gives") != NULL)
        return 4;
    else
        return 0;
}
int money(char *a){
    int len = strlen(a);
    int sum = 0;
    int count = 0;
    for(int i = len-1; i >= 0; i--){
        sum += (a[i]-'0')*pow(10,count);
        count++;
    }
    return sum;
}
int validname(char *a){
    for(int i = 0; i < n; i++)
        if(strcmp(user[i], a) == 0)
            return 1;
    return 0;
}
int validmoney(char *a){
    for(int i = 0; i < strlen(a); i++){
        if(!isdigit(a[i]))
            return 0;
    }
    return 1;
}
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s%d", user[i], &bal[i]);
    while(gets(ins) != NULL){
        int filecount = 0;
        char *start = ins;
        start = strtok(start, " ");
        while(start != NULL){
            strcpy(file[filecount], start);
            filecount++;
            start = strtok(NULL, " ");
        }
        if(filecount == 3){
            if(!validname(file[0]) || !validmoney(file[2]))
                continue;
            int k = money(file[2]);
            if(delock(file[1]) == 1)
                for(int i = 0; i < n; i++)
                    if(strcmp(user[i], file[0]) == 0)
                        bal[i] += k;
            else if(delock(file[1]) == 2)
                for(int i = 0; i < n; i++)
                    if(strcmp(user[i], file[0]) == 0 && bal[i]-k>=0)
                        bal[i] -= k;
            else if(delock(file[1]) == 3)
                for(int i = 0; i < n; i++)
                    if(strcmp(user[i], file[0]) == 0)
                        bal[i] = k;
            continue;
        }
        else if(filecount == 4){
            if( !validname(file[0]) || !validmoney(file[3]) || !validname(file[2]) )
                continue;
            int k = money(file[3]);
            if(delock(file[1]) == 4){
                for(int i = 0; i < n; i++){
                    if(strcmp(user[i], file[0]) == 0){
                        if(bal[i]-k>=0)
                            bal[i] -= k;
                        else
                            continue;   
                    }
                    if(strcmp(user[i], file[2]) == 0)
                        bal[i] += k;
                }
            }
            else
                continue;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%s %d\n", user[i], bal[i]);
}