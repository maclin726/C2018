#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int main(){
    char input[128], output[128];
    scanf("%s%s", input, output);
    FILE *fp = fopen(input, "r");
    assert(fp != NULL);
    FILE *writeFP = fopen(output, "a");
    assert(writeFP != NULL);

    Student buffer;
    int p = 1;
    fprintf(writeFP, "<table border=\"1\">\n<tbody>\n");
    while( fread(&buffer, sizeof(buffer), 1, fp) ){
        fprintf(writeFP, "<tr>\n<td>%s</td>\n<td>%d</td>\n<td>%s</td>\n",
                buffer.name, buffer.id, buffer.phone);
        fprintf(writeFP, "<td>%f, %f, %f, %f</td>\n<td>%d, %d, %d</td>\n</tr>\n",
                buffer.grade[0], buffer.grade[1], buffer.grade[2], buffer.grade[3], buffer.birth_year,
                buffer.birth_month, buffer.birth_day);
    }
    fprintf(writeFP, "</tbody>\n</table>\n");
    fclose(fp);
    fclose(writeFP);
    return 0;
}