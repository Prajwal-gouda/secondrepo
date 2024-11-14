#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listnode *listpointer;

struct listnode {
    char name[40];
    char usn[40];
    char sem[40];
    listpointer link;
};

listpointer create(int n) {
    int i;
    listpointer temp, first = NULL;
   
    for(i = 0; i < n; i++) {
        temp = (listpointer)malloc(sizeof(struct listnode));
        printf("Enter student details (name, usn, sem):\n");
        printf("Name: ");
        scanf("%s", temp->name);
        printf("USN: ");
        scanf("%s", temp->usn);
        printf("Semester: ");
        scanf("%s", temp->sem);
       
        temp->link = first;
        first = temp;
    }
    printf("List created successfully\n");
    return first;
}

void display(listpointer first) {
    if(first == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("NAME\tUSN\tSEM\n");
    while(first != NULL) {
        printf("%s\t%s\t%s\n", first->name, first->usn, first->sem);
        first = first->link;
    }
}

int main() {
    int choice, n;
    listpointer first = NULL;

    while(1) {
        printf("\nenter the choice\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number of students: ");
                scanf("%d", &n);
                first = create(n);
                break;
            case 2:
                display(first);
                break;
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}