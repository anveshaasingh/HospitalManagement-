#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doctor.h"

struct Doctor {
    int id;
    char name[50];
    char specialization[50];
};

void addDoctor() {
    struct Doctor d;
    FILE *fp = fopen("doctors.txt", "a");
    if (!fp) {
        printf("Error opening doctor file!\n");
        return;
    }
    printf("Enter Doctor ID: ");
    scanf("%d", &d.id);
    getchar();
    printf("Enter Doctor Name: ");
    fgets(d.name, sizeof(d.name), stdin);
    d.name[strcspn(d.name, "\n")] = 0;
    printf("Enter Specialization: ");
    fgets(d.specialization, sizeof(d.specialization), stdin);
    d.specialization[strcspn(d.specialization, "\n")] = 0;

    fprintf(fp, "%d %s %s\n", d.id, d.name, d.specialization);
    fclose(fp);
    printf("Doctor added successfully!\n");
}

void viewDoctors() {
    struct Doctor d;
    FILE *fp = fopen("doctors.txt", "r");
    if (!fp) {
        printf("No doctors found.\n");
        return;
    }
    printf("\n--- Doctor List ---\n");
    while (fscanf(fp, "%d %s %s", &d.id, d.name, d.specialization) == 3) {
        printf("ID: %d, Name: %s, Specialization: %s\n", d.id, d.name, d.specialization);
    }
    fclose(fp);
}
