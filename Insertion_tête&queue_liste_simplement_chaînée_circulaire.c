#include <stdio.h>
#include <stdlib.h>

typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

void insertHead(CNode** head, int value) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    newNode->data = value;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    CNode* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

void insertTail(CNode** head, int value) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    newNode->data = value;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    CNode* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

void printList(CNode* head) {
    if (head == NULL) return;
    CNode* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(retour)\n");
}

int main() {
    CNode* head = NULL;
    int n, val;
    printf("Combien d'elements en tete ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Entrez l'element %d: ", i+1);
        scanf("%d", &val);
        insertHead(&head, val);
    }
    printf("Combien d'elements en queue ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Entrez l'element %d: ", i+1);
        scanf("%d", &val);
        insertTail(&head, val);
    }
    printf("Liste circulaire simplement chainee:\n");
    printList(head);
    return 0;
}
