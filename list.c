#include <stdio.h>
#include <stdlib.h>

struct node{int i; struct node *next; };

void print_list(struct node *n){
  while(n){
    if(n->next){
      printf("%d, ",n->i);
    }else{
      printf("%d\n",n->i);
    }
    n = n->next;
  }
}

struct node * insert_front(struct node *n, int data){
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->i = data;
  new->next = n;
  return new;
}

struct node * free_list(struct node *n){
  struct node *x = n;
  struct node *y;
  while(n){
    y = n->next;
    n->i = 0;
    n->next = 0;
    free(n);
    n = y;
  }
  return x;
}

void main(){
  struct node *n1 = (struct node *)malloc(sizeof(struct node));
  struct node *n2 = (struct node *)malloc(sizeof(struct node));
  struct node *n3 = (struct node *)malloc(sizeof(struct node));

  n1->i = 5;
  n1->next = n2;
  n2->i = 8;
  n2->next = n3;
  n3->i = 1;

  printf("Testing print_list\n");
  print_list(n1);

  printf("Testing insert_front\n");
  print_list(insert_front(n1,3));

  printf("Testing free_list\n");
  print_list(free_list(n1));
}
