#include <stdio.h>
#include <stdlib.h>
struct Node{
    int value;
    struct Node *next;
};

struct Node *head = NULL;
int amount = 0;

void insert(int value){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->value = value;
    amount++;
    if (head == NULL){
        head = temp;
        head->next = NULL;
        return;
    }
    struct Node *sec;
    sec = head;
    while (sec->next != NULL){
        sec = sec->next;
    }
    sec->next = temp;
    temp->next = NULL;
}

void print_list(){
    struct Node *temp;
    temp = head;
    if (temp == NULL){
        return;
    } else{
        while (temp->next != NULL){
            printf("%d\n", temp->value);
            temp = temp->next;
        }
        printf("%d\n", temp->value);
    }
}

void delete(int position){
    if (position >= amount || position < 0) return;
    struct Node *temp;
    struct Node *left;
    temp = head;
    for (int j = 0; j <= position; ++j) {
        if (j == position - 1){
            left = temp;
        } else if ( j == position){
            left->next = temp->next;
            break;
        }
        temp = temp->next;
    }
}

int main3() {
    insert(3);
    insert(9);
    insert(4);
    insert(6);
    insert(1);
    insert(912);
    delete(2);
    print_list();
    return 0;
}

