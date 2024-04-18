#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_STUDENTS 2

// Define struct for course details
struct Course {
    char courseName[MAX_LENGTH];
    int courseCode;
};

// Define struct for user details
struct User {
    char name[MAX_LENGTH];
    struct Course courseDetails;
};

// Function to display user details
void displayDetails(struct User user) {
    printf("Name: %s\n", user.name);
    printf("Course Name: %s\n", user.courseDetails.courseName);
    printf("Course Code: %d\n\n", user.courseDetails.courseCode);
}

// Function to edit user details
void editDetails(struct User *user) {
    int choice;
    printf("Which detail do you want to edit? (1 for name, 2 for course name, 3 for course code): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter new name: ");
            getchar(); // Clear input buffer
            fgets(user->name, MAX_LENGTH, stdin);
            user->name[strcspn(user->name, "\n")] = '\0'; // Remove newline character
            break;
        case 2:
            printf("Enter new course name: ");
            getchar(); // Clear input buffer
            fgets(user->courseDetails.courseName, MAX_LENGTH, stdin);
            user->courseDetails.courseName[strcspn(user->courseDetails.courseName, "\n")] = '\0'; // Remove newline character
            break;
        case 3:
            printf("Enter new course code: ");
            scanf("%d", &user->courseDetails.courseCode);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

int main() {
    struct User students[MAX_STUDENTS];
    int i, studentIndex;

    // Prompt user to enter details for each student
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Enter name: ");
        fgets(students[i].name, MAX_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline character
        
        printf("Enter course name: ");
        fgets(students[i].courseDetails.courseName, MAX_LENGTH, stdin);
        students[i].courseDetails.courseName[strcspn(students[i].courseDetails.courseName, "\n")] = '\0'; // Remove newline character
        
        printf("Enter course code: ");
        scanf("%d", &students[i].courseDetails.courseCode);
        getchar(); // Clear newline character from input buffer

        // Display details of student after first entry
        printf("\nDetails of student %d after first entry:\n", i + 1);
        displayDetails(students[i]);
    }

    // Prompt user to choose which student's details to edit
    printf("\nEnter the index of the student you want to edit (1-%d): ", MAX_STUDENTS);
    scanf("%d", &studentIndex);
    if (studentIndex < 1 || studentIndex > MAX_STUDENTS) {
        printf("Invalid index.\n");
        return 1; // Exit with error code
    }
    studentIndex--; // Adjust to 0-based indexing

    // Edit details for the selected student
    printf("\nEditing details for student %d:\n", studentIndex + 1);
    editDetails(&students[studentIndex]);

    // Display details of all students after editing
    printf("\nDetails of all students after editing:\n");
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("Student %d:\n", i + 1);
        displayDetails(students[i]);
    }

    return 0;
}
