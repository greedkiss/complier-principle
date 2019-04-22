#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int Max = 50;
struct Node{
    char start;
    char line[Max];
    Node* next;
};
int main()
{
    char left;
    char right[Max];
    Node* head =(Node *)malloc(sizeof(Node));
    Node* cur;
    scanf("%c%s",&left, right);
    (*head).start = left;
    strcpy(head->line, right);
    cur = head;
    int num;
    while(scanf("%c%s%d",&left, right, num) == 2 && num!= -1){
        Node* info=(Node*)malloc(sizeof(Node));
        (*info).start = left;
        strcpy((*info).line, right);
        cur->next = info;
        cur = info;
        cur->next = NULL;
    }
    Node* show = head;
    while(true){
        printf("%c, %s\n", show->start, show->line);
        show = show->next;
        if(show == NULL)
            break;
    }
    return 0;
}
