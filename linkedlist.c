#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
void count(struct node *head){
    int count=0;
    if(head==NULL)
      printf("linked list is empty");
    struct node *ptr =NULL;
    ptr = head;
    while(ptr !=NULL){
        printf(" LL=%d \n",ptr->data); // data entered in linked list printed 
        count++;
        ptr=ptr->link;
    }
    printf(" count =%d",count); //count no. of nodes
}
void add_at_end(struct node *head,int data){   // insert  element at the  end 
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    while(ptr->link !=NULL){  //checking where link is null and stop at it
        ptr =ptr->link;
    }
    ptr->link =temp;      //updating link at NULL position
}
struct node* add_at_end2(struct node *ptr,int data){   //insert node element at end
 struct node *temp=malloc(sizeof(struct node));
 temp->data=data;
 temp->link=NULL;
    
 ptr->link=temp;
 return temp;   
}
struct node *add_beg(struct node* head,int d){          //insert element at beginning
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=d;
    ptr->link=NULL;
    
    ptr->link=head;
    head =ptr;
    return head;
}
void add_at_pos(struct node* head, int data , int pos){
    struct node *ptr=head;
    struct node *ptr2=malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->link=NULL;
     while(pos != 2){   
           ptr=ptr->link;   //updating ptr to next node
           pos--;           //decrement position
     }
     ptr2->link=ptr->link;
     ptr->link=ptr2;
}
struct node* del_first(struct node *head){
    if(head==NULL)
        printf("list is empty");
    else
    {
        struct node *temp = head;
        head=head->link;
        free(temp);
        temp=NULL;
    }
    return head;
}
struct node* del_last(struct node *head){  //delete lat element
   if(head==NULL)
   printf("List is empty");
   else if(head->link==NULL){
    free(head);
   head=NULL;
   }
   else
   {
    struct node *temp=head;
    struct node *temp2=head; 
    while(temp->link != NULL){
        temp2=temp;
        temp=temp->link;
    }
     temp2->link=NULL;
     free(temp);
     temp=NULL;
   }
   printf("delete1\n ");
   return head;
}
struct node* del_last2(struct node *head){  //delete last element usin single pointer
   if(head==NULL)
   printf("List is empty");
   else if(head->link==NULL){
    free(head);
   head=NULL;
   }
   else
   {
    struct node *temp=head;
    while(temp->link->link != NULL){
        temp=temp->link;
    }
     free(temp->link);
     temp->link=NULL;
     printf("delete2\n");
   }
   //printf("delete2\n");
}
int main() {
    struct node *head=malloc(sizeof(struct node));
    head->data=35;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=5;
    current->link=NULL;
    head->link = current;

    current=malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link = current;
    
    add_at_end(current,63);
  struct node *ptr=current;
  ptr=add_at_end2(ptr,78);
  ptr=add_at_end2(ptr,76);
  ptr = head;
  count(head);

 /* add_beg(head,89);          //use when adding at begginng
   ptr=head;  */ 

    int data=67 , pos=3;
    add_at_pos(head,data,pos);
    ptr=head;
  
   head=del_first(head);   //delete first element
   ptr=head;

   head=del_last(head);  // delete last element 
   ptr=head;
   
    del_last2(head);    //delete last element by using single pointer
   ptr=head;
    count(head);
    return 0;
}