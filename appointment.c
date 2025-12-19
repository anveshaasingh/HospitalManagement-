#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "appointment.h"

struct Appointment {
    int patientId;
    int doctorId;
    char date[20];
};

void bookAppointment() {
    struct Appointment a;
    FILE *fp = fopen("appointments.txt", "a");
    if (!fp) {
        printf("Error opening appointments file!\n");
        return;
    }
    printf("Enter Patient ID: ");
    scanf("%d", &a.patientId);
    printf("Enter Doctor ID: ");
    scanf("%d", &a.doctorId);
    getchar();
    printf("Enter Appointment Date (DD/MM/YYYY): ");
    fgets(a.date, sizeof(a.date), stdin);
    a.date[strcspn(a.date, "\n")] = 0;

    fprintf(fp, "%d %d %s\n", a.patientId, a.doctorId, a.date);
    fclose(fp);
    printf("Appointment booked successfully!\n");
}

void viewAppointments() {
    struct Appointment a;
    FILE *fp = fopen("appointments.txt", "r");
    if (!fp) {
        printf("No appointments found.\n");
        return;
    }
    printf("\n--- Appointments List ---\n");
    while (fscanf(fp, "%d %d %s", &a.patientId, &a.doctorId, a.date) == 3) {
        printf("Patient ID: %d, Doctor ID: %d, Date: %s\n", a.patientId, a.doctorId, a.date);
    }
    fclose(fp);
}

void cancelAppointment() {
    struct Appointment a;
    int pid, did, found = 0;
    char date[20];

    FILE *fp = fopen("appointments.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        printf("Error opening files!\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &pid);
    printf("Enter Doctor ID: ");
    scanf("%d", &did);
    getchar();
    printf("Enter Date to cancel (DD/MM/YYYY): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = 0;

    while (fscanf(fp, "%d %d %s", &a.patientId, &a.doctorId, a.date) == 3) {
        if (a.patientId == pid && a.doctorId == did && strcmp(a.date, date) == 0) {
            found = 1;
        } else {
            fprintf(temp, "%d %d %s\n", a.patientId, a.doctorId, a.date);
        }
    }

    fclose(fp);
    fclose(temp);
    remove("appointments.txt");
    rename("temp.txt", "appointments.txt");

    if (found)
        printf("Appointment canceled successfully!\n");
    else
        printf("Appointment not found!\n");
}
