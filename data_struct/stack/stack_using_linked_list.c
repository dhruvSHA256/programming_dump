#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void del_beg() {
    struct node *currnode = head;
    head = currnode->next;
    free(currnode);
}

void insert_beg(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

struct stack {
    int top;
};

struct stack s;

int empty() {
    if (s.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int full() {
    if (s.top == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int pop() {
    if (empty()) {
        printf("Underflow");
        return -1;
    } else {
        int pop_elem = head->data;
        s.top--;
        del_beg();
        return pop_elem;
    }
}

int push(int data) {
    if (full()) {
        printf("Overflow");
        return -1;
    } else {
        insert_beg(data);
        s.top++;
        return 1;
    }
}

void display() {
    if (empty()) {
        printf("Stack empty");
    } else {
        struct node *currnode = head;
        while (currnode) {
            printf("%d\n", currnode->data);
            currnode = currnode->next;
        }
    }
}

int main() {
    s.top = -1;
    int data, popped;
    int choice;

    printf("\n  1. push\n  2. pop\n  3. display\n  4. quit\n>");
    scanf("%d", &choice);
    while (choice != 4) {
        switch (choice) {
            case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                popped = pop();
                if (popped != -1) printf("Popped %d", popped);
                break;
            case 3:
                display();
                break;
        }
        printf("\n  1. push\n  2. pop\n  3. display\n  4. quit\n>");
        scanf("%d", &choice);
    }
    return 0;
}
