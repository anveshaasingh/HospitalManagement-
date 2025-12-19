#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "doctor.h"
#include "appointment.h"

int main() {
    int choice;
    while (1) {
        printf("\n*** Hospital Appointment Management System ***\n");
        printf("1. Add Patient\n");
        printf("2. Add Doctor\n");
        printf("3. Book Appointment\n");
        printf("4. View Patients\n");
        printf("5. View Doctors\n");
        printf("6. View Appointments\n");
        printf("7. Cancel Appointment\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addPatient(); break;
            case 2: addDoctor(); break;
            case 3: bookAppointment(); break;
            case 4: viewPatients(); break;
            case 5: viewDoctors(); break;
            case 6: viewAppointments(); break;
            case 7: cancelAppointment(); break;
            case 8: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
