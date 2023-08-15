#include <stdio.h>
#include <stdlib.h>

struct NODE //구조체 선언
{
    struct NODE* llink;
    int data;
    struct NODE* rlink;
};
struct NODE* head;
struct NODE* tail;

//노드 생성 함수
struct NODE* makenode(int value) {
    struct NODE* node = (struct NODE*)malloc(sizeof(struct NODE));
    node->llink = NULL;
    node->data = value;
    node->rlink = NULL;
    return node;
}

//출력 함수
void print() {
    struct NODE* p;
    p = head->rlink;
    while (p->rlink != tail) {
        printf("%d->", p->data);
        p = p->rlink;
    }
    printf("%d\n", p->data);
}

void init() {
    head = (struct NODE*)malloc(sizeof(struct NODE));
    tail = (struct NODE*)malloc(sizeof(struct NODE));
    head->data = 0;
    tail->data = 0;

    head->rlink = tail;
    head->llink = head;
    tail->rlink = tail;
    tail->llink = head;
}

//뒤로부터 노드 추가하는 함수
void push_back(int value) {
    struct NODE* newnode = makenode(value);
    struct NODE* p;
    p = tail;
    p->llink->rlink = newnode;
    newnode->llink = p->llink;
    p->llink = newnode;
    newnode->rlink = p;
}

void removenode(int value) {
    struct NODE* p;
    p = head->rlink;
    while (p->rlink != tail) {
        if (p->data == value) {
            p->rlink->llink = p->llink;
            p->llink->rlink = p->rlink;
            free(p);
            return;
        }
        p = p->rlink;
    }
}

void searchnode(int value)
{
    struct NODE* p;
    p = head->rlink;
    while (p->rlink != tail)
    {
        if (p->data == value)
        {
            printf("%d is exist\n", value);
            break;
        }
    }
}

int main() {
    init();
    push_back(60);
    push_back(30);
    push_back(50);
    print();
    removenode(30);
    print();
    searchnode(10);

    return 0;
}