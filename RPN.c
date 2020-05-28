/* 通过栈简单实现中缀表达式转化为后缀表达式 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Static{
    char date;
    struct Static *next;
} Static;
typedef Static *Sta;

void push(Sta *top, char date);
char pop(Sta *top);
void rpn(char str[], Sta top);

int main() {
    Sta top = NULL;
    char str[100];
    scanf("%s", str);
    rpn(str, top);
    return 0;
}

void push(Sta *top, char date) {
    Sta t = (Sta)malloc(sizeof(Static));
    t->date = date;
    if(*top == NULL) {
        *top = t;
        t->next = NULL;
    }
    else {
        t->next = *top;
        *top = t;
    }
}

char pop(Sta *top) {
    Sta f = *top;
    char r = (*top)->date;
    *top = (*top)->next;
    free(f);
    return r;
}

void rpn(char str[], Sta top) {
    while(*str != '\0') {
        if(*str >= '0') {
            printf("%c", *str);
        }
        else {
            printf(" ");
            if(*str == '(') {
                push(&top, *str);
            }
            if(*str == ')') {
                while(top->date != '(') {

                    printf("%c", pop(&top));
                }
                pop(&top);
            }
            if(*str == '*' || *str == '/') {
                push(&top, *str);
            }
            if(*str == '+' || *str == '-') {
                if(top == NULL) {
                    push(&top, *str);
                }
                else if(top->date == '*' || top->date == '/') {
                    while(top != NULL) {
                        printf("%c", pop(&top));
                    }
                    push(&top, *str);
                }
                else {  
                    push(&top, *str);
                }
            }
        }
        str++;
    }
    while(top != NULL) {
        printf("%c", pop(&top));
    }
}
