#include <stdio.h>

#define MAX 20

struct stack {
  int top;
  int array[MAX];
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
    return s.array[s.top--];
  }
}

int push(int data) {
  if (full()) {
    printf("Overflow");
    return -1;
  } else {
    s.array[++s.top] = data;
    return 1;
  }
}

void display() {
  if (empty()) {
    printf("Stack empty");
  } else {
    for (int i = 0; i <= s.top; i++) {
      printf("%d ", s.array[i]);
    }
  }
}

int main() {
  s.top = -1;
  int i, j;
  int data; 
  int choice;

  printf( "\n  1. push\n  2. pop\n  3. display\n  4. quit\n>");
  scanf("%d", &choice);
  while (choice != 4){
    switch (choice) {
    case 1:
      printf("Enter data : ");
      scanf("%d",&data);
      push(data);
      break;
    case 2:
      printf("Popped %d",pop());
      break;
    case 3:
      display();
      break;
    }
  printf( "\n  1. push\n  2. pop\n  3. display\n  4. quit\n>");
    scanf("%d", &choice);
  }
  return 0;
}
