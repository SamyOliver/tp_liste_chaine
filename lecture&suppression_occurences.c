#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void insertEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void deleteOccurrences(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }

    while (temp != NULL) {
        if (temp->data == value) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    Node* head = NULL;
    int n, val, x;

    printf("Combien d'elements voulez-vous inserer ? ");
    scanf("%d", &n);

    printf("Entrez les elements de la liste:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }

    printf("Liste initiale :\n");
    printList(head);

    printf("Entrez l'element a supprimer : ");
    scanf("%d", &x);

    deleteOccurrences(&head, x);

    printf("Liste apres suppression de toutes les occurrences de %d :\n", x);
    printList(head);

    return 0;
}
