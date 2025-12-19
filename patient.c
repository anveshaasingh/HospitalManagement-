#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

struct Patient {
    int id;
    char name[50];
    int age;
};

void addPatient() {
    struct Patient p;
    FILE *fp = fopen("patients.txt", "a");
    if (!fp) {
        printf("Error opening patient file!\n");
        return;
    }
    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    getchar();
    printf("Enter Patient Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;
    printf("Enter Age: ");
    scanf("%d", &p.age);

    fprintf(fp, "%d %s %d\n", p.id, p.name, p.age);
    fclose(fp);
    printf("Patient added successfully!\n");
}

void viewPatients() {
    struct Patient p;
    FILE *fp = fopen("patients.txt", "r");
    if (!fp) {
        printf("No patients found.\n");
        return;
    }
    printf("\n--- Patient List ---\n");
    while (fscanf(fp, "%d %s %d", &p.id, p.name, &p.age) == 3) {
        printf("ID: %d, Name: %s, Age: %d\n", p.id, p.name, p.age);
    }
    fclose(fp);
}
