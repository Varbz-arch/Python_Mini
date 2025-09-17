#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000  

struct Patient {
    char name[50];
    int age;
    char disease[50];
    char phone[15];
};
int isValidPhone(char phone[]) {
    int len = strlen(phone);
    if (len != 10) return 0;  

    for (int i = 0; i < len; i++) {
        if (!isdigit(phone[i])) return 0;  
    }
    return 1;
}
void saveToFile(struct Patient p) {
    FILE *fp = fopen("notes.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "Name: %s | Age: %d | Disease: %s | Phone: %s\n",
            p.name, p.age, p.disease, p.phone);
    fflush(fp);   // force writing immediately
    fclose(fp);
    printf("Record also written to notes.txt\n");  // Debug message
}

int main() {
    struct Patient patients[MAX];
    int choice, count = 0;

    while (1) {
        printf("\n--- Digital Health Management ---\n");
        printf("1. Add Patient Record\n");
        printf("2. Display All Records\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline from buffer

        if (choice == 1) {
            if (count < MAX) {
                printf("Enter Name: ");
                fgets(patients[count].name, 50, stdin);
                patients[count].name[strcspn(patients[count].name, "\n")] = '\0'; 

                printf("Enter Age: ");
                scanf("%d", &patients[count].age);
                getchar();

                printf("Enter Disease: ");
                fgets(patients[count].disease, 50, stdin);
                patients[count].disease[strcspn(patients[count].disease, "\n")] = '\0';

                while (1) {
                    printf("Enter Phone (10 digits): ");
                    fgets(patients[count].phone, 15, stdin);
                    patients[count].phone[strcspn(patients[count].phone, "\n")] = '\0';

                    if (isValidPhone(patients[count].phone)) {
                        break; 
                    } else {
                        printf("Invalid phone number! Please enter exactly 10 digits.\n");
                    }
                }

                count++;
                printf("Record added successfully!\n");
            } else {
                printf("Record limit reached.\n");
            }
        } 
        else if (choice == 2) {
            printf("\n--- Patient Records ---\n");
            for (int i = 0; i < count; i++) {
                printf("%d) Name: %s | Age: %d | Disease: %s | Phone: %s\n",
                       i + 1, patients[i].name, patients[i].age, 
                       patients[i].disease, patients[i].phone);
            }
            if (count == 0) printf("No records found.\n");
        } 
        else if (choice == 3) {
            printf("Exiting... Stay Healthy!\n");
            break;
        } 
        else {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
