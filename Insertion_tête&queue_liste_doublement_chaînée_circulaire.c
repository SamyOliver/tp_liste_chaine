#include <stdio.h>
#include <stdlib.h>

typedef struct DCNode {
    int data;
    struct DCNode* prev;
    struct DCNode* next;
} DCNode;

void insertHead(DCNode** head, int value) {
    DCNode* newNode = (DCNode*)malloc(sizeof(DCNode));
    newNode->data = value;
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
        return;
    }
    DCNode* tail = (*head)->prev;
    newNode->next = *head;
    newNode->prev = tail;
    tail->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertTail(DCNode** head, int value) {
    DCNode* newNode = (DCNode*)malloc(sizeof(DCNode));
    newNode->data = value;
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
        return;
    }
    DCNode* tail = (*head)->prev;
    newNode->next = *head;
    newNode->prev = tail;
    tail->next = newNode;
    (*head)->prev = newNode;
}

void printList(DCNode* head) {
    if (head == NULL) return;
    DCNode* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(retour)\n");
}

int main() {
    DCNode* head = NULL;
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
    printf("Liste doublement circulaire:\n");
    printList(head);
    return 0;
}
