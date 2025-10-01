#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int order;

void insertSorted(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL ||
       (order == 1 && (*head)->data >= value) ||
       (order == 2 && (*head)->data <= value)) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL &&
          ((order == 1 && temp->next->data < value) ||
           (order == 2 && temp->next->data > value)))
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
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
    printf("Liste triee:\n");
    printList(head);
    return 0;
}
