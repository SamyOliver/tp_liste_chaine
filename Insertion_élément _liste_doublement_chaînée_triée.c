#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

int order;

void insertSorted(DNode** head, int value) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (*head == NULL ||
       (order == 1 && (*head)->data >= value) ||
       (order == 2 && (*head)->data <= value)) {
        newNode->next = *head;
        if (*head != NULL) (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    DNode* temp = *head;
    while (temp->next != NULL &&
          ((order == 1 && temp->next->data < value) ||
           (order == 2 && temp->next->data > value)))
        temp = temp->next;

    newNode->next = temp->next;
    if (temp->next != NULL) temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

void printList(DNode* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    DNode* head = NULL;
    int n, val;
    printf("Ordre du tri ? (1: croissant, 2: decroissant): ");
    scanf("%d", &order);
    printf("Combien d'elements ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Entrez l'element %d: ", i+1);
        scanf("%d", &val);
        insertSorted(&head, val);
    }
    printf("Liste doublement chainee triee:\n");
    printList(head);
    return 0;
}
