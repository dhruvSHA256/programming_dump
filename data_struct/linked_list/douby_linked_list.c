#include <stdio.h>
#include <stdlib.h>

struct list {
  int data;
  struct list *next;
  struct list *prev;
};

void trav(struct list *topnode, int forward) {
  struct list *currnode = topnode;
  if (forward == 1) {
    while (currnode) {
      printf("%d\n", currnode->data);
      currnode = currnode->next;
    }
  } else {
    while (currnode->next) {
      currnode = currnode->next;
    }
    while (currnode) {
      printf("%d\n", currnode->data);
      currnode = currnode->prev;
    }
  }
}

void insert_end(struct list **topnode, int data) {
  struct list *newnode = (struct list *)malloc(sizeof(struct list));
  newnode->data = data;
  newnode->next = NULL;
  newnode->prev = NULL;

  if (*topnode == NULL) {
    *topnode = newnode;

  } else {
    struct list *currnode = *topnode;
    while (currnode->next) {
      currnode = currnode->next;
    }
    currnode->next = newnode;
    newnode->prev = currnode;
  }
}

void insert_beg(struct list **topnode, int data) {
  struct list *newnode = (struct list *)malloc(sizeof(struct list));
  newnode->data = data;
  newnode->prev = NULL;
  newnode->next = *topnode;
  (*topnode)->prev = newnode;
  *topnode = newnode;
}

void insert_pos(struct list *topnode, int data, int pos) {
  int i;
  struct list *newnode = (struct list *)malloc(sizeof(struct list));
  newnode->data = data;
  struct list *currnode = topnode;
  for (i = 0; i < pos - 2; i++) {
    if (currnode->next) {
      currnode = currnode->next;
    } else {
      printf("Linkedlist smaller than given position");
      return;
    }
  }
  newnode->next = currnode->next;
  newnode->prev = currnode;
  currnode->next->prev = newnode;
  currnode->next = newnode;
}

void del_end(struct list **topnode) {
  struct list *currnode = *topnode;
  while (currnode->next->next) {
    currnode = currnode->next;
  }
  free(currnode->next);
  currnode->next = NULL;
}

void del_beg(struct list **topnode) {
  struct list *currnode = *topnode;
  *topnode = currnode->next;
  (*topnode)->prev = NULL;
  free(currnode);
}

void del_pos(struct list *topnode, int pos) {
  int i;
  struct list *currnode = topnode;
  for (i=0; i<pos-2; i++) {
   if(currnode->next){
        currnode=currnode->next;
   }
   else {
   printf("Linkedlist smaller than given position");
   return;
   }
  }
  struct list *tempnode = currnode->next;
  currnode->next->next->prev = currnode;
  currnode->next=currnode->next->next;
  free(tempnode);
}

void freeList(struct list *topnode) {
  struct list *tmp;
  while (topnode != NULL) {
    tmp = topnode;
    topnode = topnode->next;
    free(tmp);
  }
}

int main() {

  struct list *topnode = NULL;

  insert_end(&topnode, 98);
  insert_end(&topnode, 97);
  insert_end(&topnode, 96);
  insert_beg(&topnode, 100);
  insert_beg(&topnode, 101);
  insert_beg(&topnode, 102);
  insert_beg(&topnode, 103);
  insert_beg(&topnode, 104);

  printf("\nTraversal Forward : \n\n");
  trav(topnode, 1);

  printf("\nTraversal Backward : \n\n");
  trav(topnode, 0);

  del_end(&topnode);
  printf("\nDel_end : \n\n");
  trav(topnode, 1);

  del_beg(&topnode);
  printf("\nDel_beg : \n\n");
  trav(topnode, 1);

  insert_pos(topnode, 9999, 3);
  printf("\nInsertion at pos 3 :\n\n");
  trav(topnode, 1);

  del_pos(topnode, 3);
  printf("\nDeletion at pos 3 :\n\n");
  trav(topnode, 1);

  freeList(topnode);

  return 0;
}
