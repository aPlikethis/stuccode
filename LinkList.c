#include <stdio.h>
#include <stdlib.h>
#define TURE 1

typedef struct Node {
    int date;
    struct Node *next;
}Node;
typedef Node *LinkList; 

/* 头插法创建链表 */
void addLB(LinkList L);
void printL(LinkList L);//输出链表中所有数据

int main() {
    LinkList L = (LinkList )malloc(sizeof(Node));
    L->date = -1;
    L->next = NULL;
    addLB(L);
    printL(L);
    return 0;
}

void addLB(LinkList L) {
    while(TURE) {
        LinkList t = (LinkList )malloc(sizeof(Node));
        scanf("%d", &t->date);
        if(t->date == 0) {
            break;
        }
        t->next = L->next;
        L->next = t;
    }
}
void printL(LinkList L) {
    L = L->next;
    while(L != NULL) {
        printf("%d\n", L->date);
        L = L->next;
    }
}