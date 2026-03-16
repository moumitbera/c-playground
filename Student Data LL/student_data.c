#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char student_id[50];
    char gender;
    struct Node *next;
};

struct Node* create_node(){
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Enter the name:\n");
    scanf("%s", newNode->name);
    printf("Enter Student ID:\n");
    scanf("%s", newNode->student_id);
    printf("Enter Gender:\n");
    scanf(" %c", &newNode->gender);
    newNode->next = NULL;

    return newNode;
}


struct Node* find_node(struct Node *head){
    char strID[50];
    printf("Enter the student ID to find: \n");
    scanf("%s", strID);
    struct Node *temp = head;

    while(temp != NULL && strcmp(temp->student_id, strID) != 0){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Element does not exist!\n");
        return NULL;
    }

    printf("Located the details\n");
    return temp;
}

void tell_choices(){
    printf("\nEnter the number given to select the choices:\n");
    printf("1. Insert data at the beginning.\n");
    printf("2. Insert data at the last.\n");
    printf("3. Insert data after Student ID.\n");
    printf("4. Edit details with Student ID.\n");
    printf("5. Delete data Student ID.\n");
    printf("8. Display all.\n");
    printf("9. Exit.\n");
}

void insert_beg(struct Node **head){
    struct Node *node = create_node();
    if (node == NULL){
        printf("Could not create the node!\n");
        return;
    }
    node->next = *head;
    *head = node;
}

void insert_last(struct Node **head){
    struct Node *node = create_node();
    if (node == NULL){
        printf("Could not create node!\n");
        return;
    }
    node->next = NULL;

    if(*head == NULL){
        *head = node;
        return;
    }

    struct Node *temp = *head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = node;

}

void insert_afterID(struct Node **head){
    if(*head == NULL){
        printf("The list is empty\n");
        return;
    }
    
    struct Node *temp = find_node(*head);
    if(temp == NULL){
        return;
    }
    struct Node *node = create_node();
    if (node == NULL){
        printf("Could not create node!\n");
        return;
    }

    node->next = temp->next;
    temp->next = node;
}

void edit_wID(struct Node **head){
    if(*head == NULL){
        printf("The list is empty.\n");
        return;
    }

    struct Node *fNode = find_node(*head);
    if(fNode == NULL){
        return;
    }

    printf("Editing Student ID: %s\n", fNode->student_id);
    printf("Enter new name: \n");
    scanf("%s", fNode->name);
    printf("Enter new gender: \n");
    scanf(" %c", &fNode->gender);
    
    printf("Edited Successfully.\n");
}

void del_wID(struct Node **head){
    if(*head == NULL){
        printf("The list is empty.\n");
        return;
    }
    char strID[50];
    printf("Enter the student ID to find: \n");
    scanf("%s", strID);
    struct Node *fNode = *head;
    struct Node *prev = NULL;

    while(fNode != NULL && strcmp(fNode->student_id, strID) != 0){
        prev = fNode;
        fNode = fNode->next;
    }

    if(fNode == NULL){
        printf("Element does not exist!\n");
        return;
    } 

    printf("Located the details\n");

    printf("Details:\nID: %s | %s | %c\n", fNode->student_id, fNode->name, fNode->gender);
    //deleting the first node
    if(prev == NULL){
        *head = fNode->next;
        free(fNode);
        return;
    }

    prev->next = fNode->next;
    free(fNode);
}

void display(struct Node *head){
    struct Node *temp = head;
    printf("Details: \n");
    if (head == NULL){
        printf("This list is empty!\n");
        return;
    }
    while(temp != NULL){
        printf("ID: %s | %s | %c\n", temp->student_id, temp->name, temp->gender);
        temp = temp->next;
    }
}

int main(){
    printf("This is a system to manage student details\n");

    struct Node *head = NULL;
    while(1){
        int choice;
        tell_choices();
        scanf(" %d", &choice);

        switch(choice){
            case 1:
                insert_beg(&head);
                break;
            case 2:
                insert_last(&head);
                break;
            case 3:
                insert_afterID(&head);
                break;
            case 4:
                edit_wID(&head);
                break;
            case 5:
                del_wID(&head);
                break;
            case 8:
                display(head);
                break;
            case 9:
            printf("Exiting program\n");
                exit(0);
            default:
                printf("Enter a valid choice\n");
                break;
        }
    }
}