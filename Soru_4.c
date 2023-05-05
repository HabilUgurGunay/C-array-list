#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* ÝkiSayýEkle(struct Node* List1, struct Node* List2) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int tasý = 0;

    while (List1 != NULL || List2 != NULL) {
        int toplam = tasý;
        if (List1 != NULL) {
            toplam += List1->data;
            List1 = List1->next;
        }
        if (List2 != NULL) {
            toplam += List2->data;
            List2 = List2->next;
        }
        tasý = toplam / 10;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = toplam % 10;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (tasý > 0) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = tasý;
        newNode->next = NULL;
        tail->next = newNode;
    }

    return head;
}

void printList(struct Node* head) {
    printf("(%d -> ", head->data);
    head = head->next;
    printf("%d -> ", head->data);
    head = head->next;
    printf("%d) ", head->data);
    head = head->next;

    
}

int main() {
    struct Node* List1 = (struct Node*)malloc(sizeof(struct Node));
    List1->data = 2;
    List1->next = (struct Node*)malloc(sizeof(struct Node));
    List1->next->data = 4;
    List1->next->next = (struct Node*)malloc(sizeof(struct Node));
    List1->next->next->data = 3;
    List1->next->next->next = NULL;

    struct Node* List2 = (struct Node*)malloc(sizeof(struct Node));
    List2->data = 5;
    List2->next = (struct Node*)malloc(sizeof(struct Node));
    List2->next->data = 6;
    List2->next->next = (struct Node*)malloc(sizeof(struct Node));
    List2->next->next->data = 4;
    List2->next->next->next = NULL;

    printf("Giris: ");
    printList(List1);
    printf("+ ");
    printList(List2);

    int s1 = List1->next->next->data*100;
    int s2 = List1->next->data*10;
    int s3 = List1->data;
    int s4 = List2->next->next->data*100;
    int s5 = List2->next->data*10;
    int s6 = List2->data;

    int toplam = s1 + s2 + s3 + s4 + s5 + s6;

    struct Node* result = ÝkiSayýEkle(List1, List2);
    
    printf(" \nCikis: ");
    printList(result);

    printf("\nAciklama: ");
    printf("%d", List1->next->next->data);
    printf("%d", List1->next->data);
    printf("%d +", List1->data);
    printf(" %d", List2->next->next->data);
    printf("%d", List2->next->data);
    printf("%d", List2->data);
    printf(" = %d", toplam);
    return 0;
}
