# Health Record Management (C Project)
This is a simple **console-based Health Record Management System** written in C.  
It allows users to manage basic patient records such as:
- Name  
- Age  
- Disease  
- Phone number (validated for **10 digits**)  
# ✨ Features
- Add new patient records  
- Validate phone numbers (must be 10 digits)  
- Display all saved records  
- Simple menu-driven interface  

1. Defining a Patient structure
struct Patient {
    char name[50];
    int age;
    char disease[50];
    char phone[15];
};
Each patient has name, age, disease, and phone number.
Stored in an array to keep multiple records.

2. Phone Number Validation
int isValidPhone(char phone[]) {
    int len = strlen(phone);
    if (len != 10) return 0;        // must be 10 characters
    for (int i = 0; i < len; i++) {
        if (!isdigit(phone[i])) return 0; // only digits allowed
    }
    return 1;
}
Ensures the entered phone number is exactly 10 digits.
Uses isdigit() to check each character.

3. Menu System
printf("1. Add Patient Record\n");
printf("2. Display All Records\n");
printf("3. Exit\n");
Provides options to add, display, or exit.
Uses a while(1) loop to keep running until the user chooses Exit.

4. Adding a Record
printf("Enter Name: ");
fgets(patients[count].name, 50, stdin);
...
while (1) {
    printf("Enter Phone (10 digits): ");
    fgets(patients[count].phone, 15, stdin);
    if (isValidPhone(patients[count].phone)) break;
    else printf("❌ Invalid phone number! Please enter exactly 10 digits.\n");
}
Collects name, age, disease, and phone.
Repeats phone input until a valid number is entered.

5. Displaying Records
for (int i = 0; i < count; i++) {
    printf("%d) Name: %s | Age: %d | Disease: %s | Phone: %s\n",
           i + 1, patients[i].name, patients[i].age, 
           patients[i].disease, patients[i].phone);
}
Loops through all records and prints them neatly.
If no records exist, it shows No records found.

6. Exiting
else if (choice == 3) {
    printf("Exiting... Stay Healthy!\n");
    break;
}
Gracefully exits the program.