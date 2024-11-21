#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Global parameters:
const int ID_GLOBAL = 4937576;
const short int SIZE = 100;

// database:
typedef struct {
            char name_array[100];
            int id_array[100];
            int nmr_array[100];
            bool active[100];
} database;

// Global clock:
short counter = 0;

// String modification BELOW:
void capitalize(char *str) {
            while (*str) {
                        *str = toupper(*str);
                        str++;
            }
}
/**/

// Modify database BELOW:
void add_database (database *db) {
            printf("What is the name of the student you want to add?\nSTUDENT'S NAME: ");
            scanf("%s" , db->name_array[counter]);
            capitalize(db->name_array[counter]);
            db->id_array[counter] = ID_GLOBAL + 1;
            printf("\nWhat is the telephone number of the student?\nPHONE NUMBER: ");
            scanf("%d" , db->nmr_array[counter]);
            db->active[counter] = true;
            counter++;
}

int locate_database (database *db) {
            short int p;
            scanf("%d" , &p);
            int compare;
            char compare_char;
            switch (p) {
                        case 1:
                                    printf("Insert the student's name: ");
                                    scanf("%s" , &compare_char);
                                    for (int i = 0 ; i < SIZE ; i++) {
                                                if (strcmp(compare_char, db->name_array[i]) == 0) {
                                                            print_specific(db, i);
                                                            return i;
                                                } else {
                                                            printf("Student not found.\n");
                                                }
                                    }
                                    break;
                        case 2:
                                    printf("Insert the student's ID: ");
                                    scanf("%d" , &compare);
                                    for (int i = 0 ; i < SIZE ; i++) {
                                                if (compare == db->id_array[i]) {
                                                            print_specific(db, i);
                                                            return i;
                                                } else {
                                                            printf("ID number not found.\n");
                                                }
                                    }
                                    break;
                        case 3:
                                    printf("Insert the student's phone number: ");
                                    scanf("%d" , &compare);
                                    for (int i = 0 ; i < SIZE ; i++) {
                                                if (compare == db->nmr_array[i]) {
                                                            print_specific(db, i);
                                                            return i;
                                                } else {
                                                            printf("Phone number not found.\n");
                                                }
                                    }


            }
}

void erase_database_decide (database *db, int pointer) {
            char yesNo;
            printf("\nDo you wish to deactivate this student?\nYES or NO: ");
            scanf("%s" , &yesNo);
            capitalize(yesNo);
            if (yesNo == 'YES') {
                        db->active[pointer] = false;
            } else {
                        db->active[pointer] = true;
            }
}
/**/




// All to print BELOW:
void print_all_active (database *db) {
            for (int i = 0 ; i < SIZE ; i++) {
                        if (db->active[i]) {
                                    printf("NAME: %s | ID: %d | NUMBER: %d | STATUS: ENROLLED\n" , db->name_array[i], db->id_array[i], db->nmr_array[i]);
                        }
            }
}

void print_all_innactive (database *db) {
            for (int i = 0 ; i < SIZE ; i++) {
                        if (db->active[i] == false) {
                                    printf("NAME: %s | ID: %d | NUMBER: %d | STATUS: INNACTIVE\n" , db->name_array[i], db->id_array[i], db->nmr_array[i]);
                        }
            }    
}

void print_all_general (database *db) {
            for (int i = 0 ; i < SIZE ; i++) {
                        printf("NAME: %s | ID: %d | NUMBER: %d | " , db->name_array[i], db->id_array[i], db->nmr_array[i]);
                        if (db->active[i]) {
                                    printf("STATUS: ENROLLED\n");
                        } else {
                                    printf("STATUS: INNACTIVE\n");
                        }
            }
}

void print_specific (database *db, int pointer) {
            printf("NAME: %s | ID: %d | NUMBER: %d | " , db->name_array[pointer], db->id_array[pointer], db->nmr_array[pointer]);
            if (db->active[pointer]) {
                        printf("STATUS: ENROLLED\n");
            } else {
                        printf("STATUS: INNACTIVE\n");
            }
}
/**/

int main (void) {
            database db;
            bool set = true;
            while (set) {
                        int navigate = 0;
                        printf("\n\n\n\n--Welcome to Old One's University of Engineering's Database--\n\n");
                        printf("What do you wish to do?\n");
                        printf("Press \"1\" ---------------to add a new student to the database\n");
                        printf("Press \"2\" -------------to search for students in the database\n");
                        printf("Press \"3\" --to modify the status of a student in the database\n");
                        printf("Press \"4\" -------------------------------to exit the database\n");
                        printf("INSERT: ");
                        scanf("%d" , &navigate);
                        getchar();

                        switch (navigate) {
                                    case 1:
                                                add_database(&db);
                                                break;
                                    case 2:
                                                navigate = 11;
                                                break;
                                    case 3:
                                                locate_database(&db);
                                                break;
                                    case 4:
                                                return 0;
                                    default:
                                                printf("==Invalid input== Please, try again!\n\n");
                                                continue;
                        }

                        if (navigate == 11) {
                                    printf("\n\nHow do you wish to access the students' information?\n");
                                    printf("Press \"1\" ------------------------------to search all results\n");
                                    printf("Press \"2\" ----------------------to search all active students\n");
                                    printf("Press \"3\" -------------------to search all innactive students\n");
                                    printf("Press \"4\" -----------------------to search a specific student\n");
                                    printf("Press \"5\" ------------------------------to return to the menu\n");
                                    printf("INSERT: ");
                                    scanf("%d" , &navigate);
                                    getchar();

                                    int i;
                                    switch (navigate) {
                                                case 1:
                                                            print_all_general(&db);
                                                            break;
                                                case 2:
                                                            print_all_active(&db);
                                                            break;
                                                case 3:
                                                            print_all_innactive(&db);
                                                            break;
                                                case 4:
                                                            locate_database(&db);
                                                            print_specific(&db, i);
                                                            break;
                                                case 5:
                                                            continue;
                                                default:
                                                            return 0;
                                    }
                        }

                        set = false;

            }

            return 0;
}