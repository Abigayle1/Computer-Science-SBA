
  /*
Students Name: ABIGAYLE MCGROWDER
School: THE HERBERT MORRISON TECHNICAL HIGH SCHOOL
Project title: The St. James High School's Library Management System
Project Synopsis: This program is designed to automate the distribution and collection process for the library at the St. James High School.
Skills Used: Read/Write to file, search, add/remove/update records
*/

#include <stdio.h> 
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

//functions
int Welcome();
int Passcode();
int MainMenu();
int ClearScreen();
int Register_student();
void distribute_book();  
void Add_Book_to_inventory();
void View_inventory();
void View_Stud_data();
void Remove_Student();
void updated_stud();
void return_book(); 
int cal_fee();

int actualsize = 0;//current number of registered students.
int num_books=0;
#define maxsize 1000 //maximum number of students that can be registered.

//Defining Structures for Students and Books
struct database
{
	char lastname[15];
	char firstname[15];
	int stud_ID;
	int stud_grade;	
};
 struct database stud[maxsize]; // declare an array of database structs named stud that can be access by using the instance/variable stud.
 
 struct book_database
 {
 	char book_title [35];
	int book_ID;
	int book_cond;
	char unit[20];
 } book; 
 
int main ()
{
	//Declaring Global Variables in Main
	int loop=1;
	system ("color 4f");

	Welcome(); //Calling the Welcome Screen Function.
	Passcode(); //Calling the Passcode function.
	
	while (loop!=0) //Creating the loop for the Main Menu.
	{
		ClearScreen();
		char selection = MainMenu();
		switch (selection)
		{
			case ('1'):
				Register_student();
				getch();
				break;
			case ('2'):
				distribute_book();
				getch();
				break;
			case ('3'):
				return_book(); 
				getch();
				break;
			case ('4'):
				View_inventory();
				getch();
				break;
			case ('5'):
				Add_Book_to_inventory();
				getch();
				break;
			case ('6'):
				View_Stud_data();
				getch();
				break;
			case ('7'):
				updated_stud();
				getch();
				break;
			case ('8'):
				Remove_Student();
				getch();
				break;
			case ('9'):
				printf ("\n\t\t\t\tSorry to see you go! Press any key to exit! ");
				getch();
				printf("Exiting");
				int a; //Delay in response time.
				for(a = 0;a < 3;a++)
				{
	    			printf(".");
	    			fflush(stdout);
	    			sleep(1);
				}
				loop=0;
				break;
			default: 
			printf("\t\t\t\tOops! That is an INVALID choice. Please press a key and re-select a correct option!");
			getch();
		}
	}
	return 0;
}

int Welcome() //Function for Welcome Screen.
{
	system ("color 4f");
	printf ("\n\n");
	printf ("\t\t\t\t\t** Welcome to the Library Management System **\n");
	printf ("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf ("\t\t\t\t\t\t MOTTO: Towards Better Living");
	printf ("\n");
	printf ("\n\t\t\t\t\t 'Reading is a passport to countless adventures'");
	printf ("\n\t\t\t\t\t\t\t\t\t -Mary Pope Osborne");
	printf ("\n\n\n");
}

int Passcode() //Password Function
{
	char code[] = "Success";
	char input[20];
	int result;

	printf ("\n");
	printf ("\n");
	printf ("\t\t\t\t\tPlease enter the password: ");
	scanf  ("%s", input);
		result = strcmp (code,input);
	if (result ==0)
	{
		printf("\t\t\t\t\tAccess granted!\n");
		printf ("\n\t\t\t\t\tPress any key to continue. . .");
        getch();
        ClearScreen();
	}	
	else
	{
		 do
        {
            printf ("\t\t\t\t\tAccess denied.\n\n");
            printf ("\t\t\t\t\tPress any key to retry.");
            getch();
            ClearScreen();
            printf("\n\n\n\n\n\t\t\t\t\tPlease enter the correct password: ");
            scanf("%s", input);
            result = strcmp(code, input);
        } while (result != 0);
        printf("\t\t\t\t\tAccess granted!\n");
        printf ("\n\t\t\t\t\tPress any key to continue. . .");
    	getch();
    	ClearScreen();
	}
}

int MainMenu()//Function to be used for Main Menu, containing 9 options for the user.
{
	char opt;
	system ("color 4f");
	printf ("\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf ("\n\t\t\t\t|Book Room Registration and Distribution System         |");
	printf ("\n\t\t\t\t|Please enter the respective number to type an option : |");
	printf ("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf ("\n\t\t\t\t1. Register a student");
	printf ("\n\t\t\t\t2. Distribute a book");
	printf ("\n\t\t\t\t3. Return a book"); 
	printf ("\n\t\t\t\t4. Veiw book inventory");
	printf ("\n\t\t\t\t5. Add a new book to the inventory");
	printf ("\n\t\t\t\t6. Print students data to screen"); 
	printf ("\n\t\t\t\t7. Update students data"); 
	printf ("\n\t\t\t\t8. Remove a student"); 
	printf ("\n\t\t\t\t9. Exit the program");
	printf ("\n");
	opt = getch();
}

int ClearScreen() //Function to Clear the screen.
{
	system ("cls");
}

int Register_student() //Function to Register a new student. 
{
	ClearScreen();
	system ("color 8f");
	if (actualsize == maxsize) // Check if maximum number of students reached.
	{
		printf("\t\t\tMaximum number of students reached.\n");
	}
	else
	{	
	FILE * in = fopen("students.txt", "a"); // open the file in append mode to add new data to it

		printf ("\n\n");
		printf("\t\t\t\tENTER THE REQUIRED INFORMATION TO REGISTER : \n");
  		printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		
		printf ("\n\t\t\tEnter student's ID number : ");
		scanf  ("%d", &stud[actualsize].stud_ID);
		
	 	printf ("\t\t\tEnter student's full name (Last Name, First Name): ");
		scanf  ("%s", stud[actualsize].lastname);
		scanf  ("%s", stud[actualsize].firstname);
		
		printf ("\t\t\tEnter student's grade : ");
		scanf  ("%d", &stud[actualsize].stud_grade);
		
		fprintf(in, "%d %s %s %d\n",stud[actualsize].stud_ID, stud[actualsize].lastname,stud[actualsize].firstname, stud[actualsize].stud_grade); 
												
		printf("\t\t\tStudent successfully registered.\n");
	
		actualsize++; // increment the number of registered students.
		
		fclose(in);
		
		printf("\n\t\t\tTo go back to the Main Menu, press any key.");
		getch();
	}
}

void distribute_book() //Function to distribute a book to a student.
{
    ClearScreen();
    system ("color 8f");
    int book_id, stud_id;
    int found_book = 0, found_student = 0;
    
    printf ("\n\n");
	printf ("\t\t\t\t\tBOOK DISTRIBUTION");
	printf ("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	
    printf("\n\t\t\tEnter the book ID: "); // Prompt the user to enter the book ID
    scanf("%d", &book_id);

    FILE *availbooks = fopen("Available_Books.txt", "r"); // Open the available books database file for reading
    if (availbooks == NULL) 
	{
        printf("\t\t\tError: could not open Available_Books.txt\n");
        return;
    }

    // Open a temporary file for writing
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
	{
        printf("\t\t\tError: could not create temp.txt\n");
        fclose(availbooks);
        return;
    }

    // Read each line from the available books database file
    char line[100];
    while (fgets(line, sizeof(line), availbooks)) 
	{
        // Parse the line to extract the book ID, title, unit, condition, and count
        int current_book_id, current_count, cond;
        char title[50], unit[15];
        sscanf(line, "%d %s %s %d %d", &current_book_id, title, unit, &cond, &current_count);

        // If the current line matches the ID of the book we want to distribute,
        // decrement the count of available books and set the found flag to true
        if (current_book_id == book_id)
		{
            found_book = 1;

            current_count--;  // Decrement the count of available books		
     		
            // Write the updated line to the temporary file
            fprintf(temp_file, "%d %s %s %d %d\n", current_book_id, title, unit, cond, current_count);

            printf("\n\t\t\tThe '%s %s' book with ID '%d' \n\t\t\thave been located:)\n", title, unit, current_book_id);
            break;
		}
		else
		{
            // Otherwise, write the current line to the temporary file
            fprintf(temp_file, "%s", line);
		}
	}
	
	// Close the files
	fclose(availbooks);
	fclose(temp_file);

	// If the book was not found, display an error message and return
	if (!found_book) 
	{
        printf("\t\t\tError: book with ID %d not found\n", book_id);
        return;
    }

    // Prompt the user to enter the student ID
    printf("\n\t\t\tEnter the student ID: ");
    scanf("%d", &stud_id);

    // Open the student database file for reading
    FILE *in = fopen("students.txt", "r");
    if (in == NULL) 
	{
        printf("\t\t\tError: could not open students.txt\n");
        return;
    }

    // Open a temporary file for writing
    temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) 
	{
        printf("\t\t\tError: could not create temp.txt\n");
        fclose(in);
        return;
    }

    // Read each line from the student database file
    while (fgets(line, sizeof(line), in)) 
	{
        // Parse the line to extract the student ID, last name, first name, grade, and book ID
        int current_student_id, current_book_id;
        char lname[15], fname[15];
        int grade;
        sscanf(line, "%d %s %s %d    %d", &current_student_id, lname, fname, &grade, &current_book_id);
        
        // If the current line matches the ID of the student we want to distribute the book to,
        // update the book ID and set the found flag to true
           if (current_student_id == stud_id)
			{
                found_student = 1;
                
                fprintf(temp_file, "%d %s %s %d %d\n", current_student_id, lname, fname, grade, book_id); 

                printf("\n\t\t\tThe book have been successfully distributed:)");     
            }
			else
			{
                // Otherwise, write the current line to the temporary file
                fprintf(temp_file, "%s" , line);
 			}
	}
			// Close the files
			fclose(temp_file);
			fclose(in);
			
			// Remove the original student database file and rename the temporary file to replace it
    		remove("students.txt");
   			rename("temp.txt","students.txt");	
		
	
	if (!found_student) 
	{
        printf("\t\t\tError: student with ID %d not found\n", stud_id);
    }
    printf("\n\n\t\t\tTo go back to the Main Menu, press any key..");
	getch();
}

void return_book() //Function to return book.
{
    ClearScreen();
    system ("color 8f");
    printf ("\n\n");
	printf ("\t\t\t\t\t\tBOOK RETURN");
    printf ("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    
    int book_id, stud_id;
    int found_book = 0, found_student = 0;

    // Prompt the user to enter the book ID
    printf("\n\t\t\t\tEnter the book ID: ");
    scanf("%d", &book_id);

    FILE *availbooks = fopen("Available_Books.txt", "r");  // Open the available books database file for reading.
    if (availbooks == NULL) 
    {
        printf("\t\t\t\tError: could not open Available_Books.txt\n");
        return;
    }
        
    FILE *temp_file = fopen("temp.txt", "w"); // Open a temporary file for writing.
    if (temp_file == NULL) 
    {
        printf("\t\t\t\tError: could not create temp.txt\n");
        fclose(availbooks);
        return;
    }

    // Read each line from the available books database file
    char line[100];
    
    while (fgets(line, sizeof(line), availbooks)) 
    {
        // Parse the line to extract the book ID and title
        int current_book_id, current_count, cond;
        char title[50], unit[15];
        
        sscanf(line, "%d %s %s %d %d", &current_book_id, title, unit, &cond, &current_count);

        // If the current line matches the ID of the book we want to return,
        // increment the count of available books and set the found flag to true
        if (current_book_id == book_id)
        {
            found_book = 1;
            cal_fee();
    
            // Increment the count of available books
            current_count++;

            // Write the updated line to the temporary file
            fprintf(temp_file, "%d %s %s %d\n", current_book_id, title, unit, cond);
		}
	}
            // Close the files
            fclose(availbooks);
            fclose(temp_file);

            // Remove the original available books database file and rename the temporary file to replace it
            remove("Available_Books.txt");
            rename("temp.txt", "Available_Books.txt");

            // Prompt the user to enter the student ID
            printf("\n\n\t\t\t\tEnter the student ID: ");
            scanf("%d", &stud_id);

            // Open the student database file for reading
            FILE *in = fopen("students.txt", "r");
            if (in == NULL) 
            {
                printf("\t\t\t\tError: could not open students.txt\n");
                return;
            }

            // Open a temporary file for writing
            temp_file = fopen("temp.txt", "w");
            if (temp_file == NULL) 
            {
                printf("\t\t\t\tError: could not create temp.txt\n");
                fclose(in);
                return;
            }

            // Read each line from the student database file
            char lname[15], fname[15];
            int grade, current_book_id=NULL;
            while (fgets(line, sizeof(line), in)) 
            {
                // Parse the line to extract the student ID and book ID
                int current_student_id;
                sscanf(line, "%d %s %s %d %d", &current_student_id, lname, fname, &grade, &current_book_id);

                // If the current line matches the ID of the student who borrowed the book,
                // update the book ID and set the found flag to true
                if (current_student_id == stud_id && current_book_id == book_id) 
				{
	                found_student = 1;
	                
					// Set the book ID to 0 to indicate that the student has returned the book
	                current_book_id = '\0';
	
	                // Write the updated line to the temporary file
	                fprintf(temp_file, "%d %s %s %d %d\n", current_student_id, lname, fname, grade, current_book_id);
	
	                printf("\n\t\t\t\tStudent, '%s %s' with ID %d has returned the book with ID %d\n", fname, lname, current_student_id, book_id);
            	}
            	else 
            	{
	               	// Write the unchanged line to the temporary file
	                fprintf(temp_file, "%d %s %s %d %d\n", current_student_id, lname, fname, grade, current_book_id);
            	}
        	}

        // Close the files
        fclose(in);
        fclose(temp_file);

        // Remove the original student database file and rename the temporary file to replace it
        remove("students.txt");
        rename("temp.txt", "students.txt");

        // If the book or student was not found, print an error message
        if (!found_book) 
        {
            printf("\n\t\t\t\tError: book with ID %d not found or not borrowed\n", book_id);
        }
        if (!found_student) 
        {
            printf("\n\t\t\t\tError: student with ID %d did not borrow book with ID %d\n", stud_id, book_id);
        }
		printf ("\n\n\t\t\t\tPress any key to go back to main menu.");
		getch();
        return;
}

int cal_fee() //Function to calculate the fee charged on a book that is returned after its return date.
{
	int days_late;
	float late_fee = 0.0;
	
	printf ("\t\t\t\tEnter the number of days that the book is late : ");
	scanf ("%d", &days_late);
	
	// Calculate late fee based on number of days late
    if (days_late > 0) 
    {
        late_fee = days_late * 20.0; // $20 per day late
    }
    printf ("\n\t\t\t\tThe book is %d days late and a fee of $%4.2f will be charged.", days_late, late_fee);
return late_fee;
}
   
void View_inventory() //Function to view the list of Books in the library.
{
    ClearScreen();
    system ("color 8f");
    printf ("\n\n");
    printf ("\n\t\t\t\t\t\tLIST OF AVAILABLE BOOKS");
    printf ("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    // Open the "Available_Books.txt" file for reading
    FILE *availbooks = fopen("Available_Books.txt", "r");
    if (availbooks == NULL)
    {
        printf("\t\t\t\tError: Available_Books.txt is empty\n");
    }
    else
    {
    // Read in each line of the file and print it to the screen
    char line[100];
    while (fgets(line, sizeof(line), availbooks))
    {
        printf("\t\t\t\t%s", line);
    }

    fclose(availbooks); // Close the file
	}
    printf("\n\n\t\t\t\tPress any key to return to the main menu.");
    getch();
}

void View_Stud_data() //Function to view the list of registered student.
{
	ClearScreen();
	system ("color 8f");
	printf ("\n\n");
	printf ("\t\t\t\t\tLIST OF REGISTERED STUDENTS\n");
	printf ("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	//Open the "students.txt" for reading
	FILE *in =fopen("students.txt", "r");
	if (in == NULL)
	{
		printf ("\t\t\tError: could not open students.txt file\n");
		return;
	}
	//Read in each line of the file and print it to the screen
	char line[100];
	
	while (fgets(line, sizeof(line), in))
	{
		printf ("\t\t\t\t%s", line);
	}
	
	fclose(in); //close the file.
	
	printf ("\n\t\t\t\tPress any key to return to the main menu.");
	getch();
}

void updated_stud() //Function to update the students grade level.
  {
    ClearScreen();
	system ("color 8f");
	printf ("\n\n");
	printf ("\t\t\t\t\tUPDATE STUDENTS INFORMATION");
	printf ("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	int id, grade;
    int found = 0;

    // Prompt the user to enter the student ID
    printf("\t\t\t\tEnter the student ID: ");
    scanf("%d", &id);

    // Open the student database file for reading
    FILE *in = fopen("students.txt", "r");
    if (in == NULL) {
        printf("\t\t\t\tError: could not open students.txt\n");
        return;
    }

    // Open a temporary file for writing
    FILE *tempt_file = fopen("tempt.txt", "w");
    if (tempt_file == NULL) 
	{
        printf("\t\t\t\tError: could not create tempt.txt\n");
        fclose(in);
        return;
    }

    // Read each line from the student database file
    char line[100];
    while (fgets(line, sizeof(line), in)) 
	{
        // Parse the line to extract the student ID and grade level
        int current_id, current_grade;
        char fname[15], lname[15];
        sscanf(line, "%d %s %s %d", &current_id, lname, fname, &current_grade);

        // If the current line matches the ID of the student we want to upgrade,
        // update the grade level and set the found flag to true
        if (current_id == id) 
		{
            found = 1;

            printf("\t\t\t\tEnter the student's new grade: ");
            scanf("%d", &grade);

            fprintf(tempt_file, "%d %s %s %d\n", id,lname, fname, grade);
            printf("\t\t\t\tThe Student, %s %s have been successfully upgraded to %d\n", fname, lname, grade);
        } 
		else 
		{
            // Otherwise, write the current line to the temporary file
            fprintf(tempt_file, "%s", line);
        }
    }

    // Close the files
    fclose(in);
    fclose(tempt_file);

    // Remove the original student database file and rename the temporary file to replace it
    remove("students.txt");
    rename("tempt.txt", "students.txt");

    if (!found) 
	{
        printf("\t\t\t\tError: student with ID %d not found\n", id);
    }
    printf("\n\t\t\t\tTo go back to the Main Menu, press any key.");
	getch();
}

void Remove_Student() //Function to remove a student from the system.
  {
  	ClearScreen();
  	system ("color 8f");
  	printf ("\n\n");
  	printf ("\t\t\t\t\tSTUDENTS DEREGISTRATION");
  	printf ("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  	
  	int stud_id;
  	
  	printf("\t\t\tEnter the ID of the student you want to remove: ");
    scanf("%d", &stud_id);
	
	// Open the "Students.txt" file for reading and "temp.txt" file for temporarly holding the contents in student.txt.
	FILE *in = fopen("Students.txt", "r");
    FILE *temp_file = fopen("temp.txt", "w");
    
    if (in == NULL || temp_file == NULL)
	{
        printf("\t\t\tError: could not open file\n");
        return;
    }
    
    int found = 0; // Flag to keep track if student is found.
    
    // Loop through each line of the "Students.txt" file
    char line[100];
    while (fgets(line, sizeof(line), in)) 
	{
        int id;
        char lname[20];
        char fname[20];
        int grade;

        // Extract the student details from the line
        sscanf(line, "%d %s %s %d", &id, lname, fname, &grade);

        // Check if the current line corresponds to the student to be removed
        if (id == stud_id) 
		{
            found = 1; // Set the flag to true to indicate the student is found
            continue; // Skip this line and move on to the next line
        }

        // If the current line does not correspond to the student to be removed, write it to the "temp.txt" file
        fprintf(temp_file, "%d %s %s %d\n", id, lname, fname, grade);
    }
    
	fclose(in);
    fclose(temp_file);
    
     remove("students.txt");
     rename("temp.txt", "students.txt"); 
    
    // If the student was not found, display a message to the user
    if (!found) 
	{
        printf("\t\t\tError: student with ID %d not found\n", stud_id);
    }
	else 
	{
        printf("\t\t\tStudent with ID %d has been successfully removed from the file.\n", stud_id);
    }
    
    printf("\n\t\t\tTo go back to the Main Menu, press any key.");
    getch();
  }

void Add_Book_to_inventory() //Function to add a new book to the library's inventory.
{
	ClearScreen();
	system ("color 8f");
	printf ("\n\n");
	printf ("\t\t\t\t\tADDING BOOKS TO INVENTORY");
	printf ("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	int id, condition;
	char title[35];
	
    // Open the "Book_Inventory.txt" file for appending
    FILE * availbooks = fopen("Available_Books.txt", "a");
    if (availbooks == NULL)
	{
        printf("\t\t\tError: could not open Available_Books.txt\n");
        return;
    }
    
    struct book_database book;

 	// Get the book details from the user
    printf("\t\t\tEnter the book ID: ");
    scanf("%d", &book.book_ID);
    
    printf("\t\t\tEnter the book title: ");
    scanf("%s %s", book.book_title, book.unit);
    
    	
	printf("\t\t\tEnter book's condition (1 = Good, 2 = Fair, 3 = damaged): ");
    scanf("%d", &book.book_cond);
      
    fprintf(availbooks, "%d %s %s %d\n", book.book_ID, book.book_title, book.unit, book.book_cond); // Write the book ID, title, and condition to the file.
	
	num_books++; //increment the number of books available to be distributed.
	
    // Close the file
    fclose(availbooks);
    printf ("\n\n\t\t\tThe book have been successfully added to the inventory.");
    printf("\n\t\t\tTo go back to the Main Menu, press any key.");
	getch();
}

