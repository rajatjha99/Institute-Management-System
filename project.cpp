#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <stdlib.h>
#include <iomanip.h>
#include <graphics.h>

typedef char option[45] ;
const int row = 10, col = 10 ;
int scan ; //To hold the special character for moving the prompt in menu
int ascii ;

//To display the main menu options
option a[] = {
		"Entry",
		"Display",
		"Enquiry",
		"Modification",
		"About Us",
		"Exit",
	} ;
//To display the ENTRY menu option.
option b[] = {
		"Teacher",
		"Student",
		"Exam Form",
		"Exam Schedule",
		"Result",
		"Back To Previous Menu",
	} ;
//To display the DISPLAY menu option
option c[] = {
		"Teacher",
		"Student",
		"Time-Table",
		"Exam Form",
		"Exam Schedule",
		"Result",
		"Back To Previous Menu",
	} ;
//To display the ENQUIRY menu option
option d[] = {
		"Teacher",
		"Student",
		"back To Previous Menu",
	} ;
//To display the MODIFICATION menu option
option e[] = {
		"Teacher",
		"Student",
		"Back To Previous Menu",
	} ;
//To display the PERFORMANCE menu option
option f[] = {
		"Foundation",
		"Back To Previous Menu",
	   } ;

/* Class Definitions */
//Function used for screening
class main_menu
{
	private:
		int j, done ;
	public:
		void normal(int x, int y, char *str) ;
		void reverse(int x, int y, char *str) ;
		void box(int x1, int y1, int x2, int y2) ;
		char menu() ;
		void control_menu() ;
		void entry_menu() ;
		char e_menu();
		void timetable();
		void display_menu() ;
		char d_menu() ;
		void enquiry_menu() ;
		char enqu_menu() ;
		void modification_menu() ;
		char mod_menu() ;
		void performance_menu() ;
		char perform_menu() ;
		void welcome_screen() ;
};

/*Class member for drawing boxes*/
class shape
{
	public:
		void line_hor(int, int, int, char) ;
		void line_ver(int, int, int, char) ;
		void box(int, int, int, int, char) ;
};
//class contain all the information of teacher
class teacher
{
	private:
		  void add_to_file(int, char [], char [], char[], char[], char[]) ;	//function to add record
		  void box_for_display(int) ;		//function to draw box
		  void box_for_enquiryteacher(int) ;	//function to draw box
		  int coll_id ;
		  char coll_name[30], coll_loc[30], coll_str[30], coll_degI[30], coll_degII[30] ;

	public:
		void new_teacher(void) ;		//function for entering information of a new teacher
		void display_list(void) ;		//function for displaying all the teachers and their information
		void teacher_enquiry(void) ;     	//function for enquirying about aparticular teacher
		void teacher_modification(void) ;	//function for modifying the teacher details
		void clear(int, int) ;			//function for performing screen clear function
		int found_teacher(int) ;		//function to find the teacher in teacher.dat
		char *return_name(int) ;		//function for validation entry of teacher name
		char *return_loc(int) ;			//function for validiation entry of teacher location
		char *return_str(int) ;			//function for validation entry of teacher stream
		char *return_degI(int) ;		//function for validation entry of degree(b.tech/b.sc)
		char *return_degII(int) ;		//function for validation entry of teacher degree(m.tech/m.sc)
		void display(int) ;			//function for displaying teacher information
		void modify_teacher(int, char [], char [], char [], char [], char []) ;	//funcion for teacher modification
		int last_collid(void) ;			//function to find the last teacher id in teacher.dat
		int recordno(int) ;			//function to find the record number in teacher.dat
} ;
class student
{
	private:
		//function to add record
void add_to_file(int, char[], char[], char[], char[], char[], char[], char[], char[], char[], char[]) ;
void box_for_display(int) ;	//function to draw box
void box_for_enquirystudent(int) ;//function to draw box
int stu_id ;
char stu_name[30], stu_fname[30], stu_add[30], stu_city[30], stu_state[30], stu_zip[30], stu_contact[30], stu_code[30], stu_strm[30], stu_deg[30] ;
public:
void new_student(void) ;	//function for entreing information of new student
void display_list(void) ;	//function to display student details
void enquiry_student(void) ;	//function to display particular student detail
void student_modification(void) ;//function to modify student information
void clear(int, int) ;		//function for clearing screen
int found_student(int) ;	//function to find the student in student.dat
char *return_name(int) ;	//function for validation entry of student name
void examdisplay(int, int) ;	//function to display information
void resultdisplay(int) ;       //function to display information
char *return_fname(int) ;	//function for validation entry of student father name
char *return_address(int) ;     //function for validation entry of address
char *return_stream(int) ;	//function for validation entry of stream
char *return_city(int) ;	//function for validation entry of city
char *return_state(int) ;	//function for validation entry of state
char *return_zip(int) ;	        //function for validation entry of zip
char *return_contact(int) ;	//function for validation entry of contact number
char *return_code(int) ;	//function for validation entry of std code
char *return_degree(int) ;	//function for validation entry of degree
void display(int) ;		//function to display
//function to modify the student details
void modify_student(int, char[], char[], char[], char[], char[], char[], char[]) ;
int last_stuid(void) ;		//function to find the last student id in student.dat
int recordno(int) ;		//function to find the record number in student.dat
} ;
class examinfo
{
private:
char stu_deg[30], stu_name[30], stu_fname[30], stu_add[30], stu_strm[30], sd1[30], ed1[30], sm1[30], em1[30], sy1[30], ey1[30], deg[30] ;
int stu_id, examform_id, hp1, hp2, hp3, hp4, hp5, hp6, hp7, hp8, s1, s2, com, gk ;
int p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16 ;
//function to add record
void add_to_file_schedule(char[], char[], char[], char[], char[], char[], char[]) ;
public:
void exam_formentry() ;		//function for the form fill up
void exam_scheduleentry(void) ;	//function for the entry of the schedule
void display_list(void) ;	//function to display
void display_schedulelist(void) ;//function to display
void result_entry(void) ;	//function for the entry of the result
void resultdisplay_list(void) ;	//function for the result display
char *return_degname(int) ;	//function for the valid entry of degree
int last_examformid(void) ;	//function to find the last id
void clear(int, int) ;		//function for clearing screen
void display(int) ;		//function to display
//function to add record
void add_to_file_form(int, int, char[], char[], char[], char[], char[]) ;
//function to add record
void add_to_filebaI(int, char[], char[], int, int, int, int, int) ;
//function to add record
void add_to_filebaII(int, char[], char[], int, int, int, int, int) ;
//function to add record
void add_to_filebaIII(int, char[], char[], int, int, int, int, int) ;
//function to add record
void add_to_filemaI(int, char[], char[], int, int, int, int, int, int, int, int) ;
//function to add record
void add_to_filemaII(int, char[], char[], int, int, int, int, int, int, int, int) ;
};
class performance
{
	public:
		void foundation(void) ;
};
// Display Screen */


/*Function to display all the menu prompt message from the pointer array
of option a[]*/
void main_menu::normal(int x, int y, char *str)
{
	gotoxy(x, y) ;
	cprintf("%s", str) ;
}
//Function to move the cursor in the menu prompt with reverse video color
void main_menu::reverse(int x, int y, char *str)
{
	textcolor(5+143);
	textbackground(WHITE);
	gotoxy(x, y);
	cprintf("%s", str);
	textcolor(GREEN);
	textbackground(BLACK);
}
void main_menu::box(int x1, int y1, int x2, int y2)
{
	for(int col = x1; col < x2; col++)
	{
		gotoxy(col, y1) ;
		cprintf("%c", 196) ;
		gotoxy(col, y2) ;
		cprintf("%c", 196) ;
	}
	for(int row = y1; row < y2; row++)
	{
		gotoxy(x1, row) ;
		cprintf("%c", 179) ;
		gotoxy(x2, row) ;
		cprintf("%c", 179) ;
	}
	gotoxy(x1, y1) ;
	cprintf("%c", 218) ;
	gotoxy(x1, y2) ;
	cprintf("%c", 192) ;
	gotoxy(x2, y1) ;
	cprintf("%c", 191) ;
	gotoxy(x2, y2) ;
	cprintf("%c", 217) ;
}
char main_menu::menu()
{
	clrscr() ;
	textcolor(22) ;
	box(20, 6, 65, 20) ;
	box(18, 4, 67, 22) ;
	textcolor(5+143) ;
	gotoxy(28, 5) ;
	textbackground(WHITE) ;
	cprintf("Institute Management System") ;
	textbackground(BLACK) ;
	textcolor(22) ;
	for(int i = 1; i < 6; i++)
		normal(32, i + 10, a[i]) ;
	reverse(32, 10, a[0]) ;
	i = done = 0 ;
	_setcursortype(_NOCURSOR) ;//change the cursor type
	do
	{
		int key = getch()  ;
		switch(key)
		{
			case 72:
				normal(32, i + 10, a[i]) ;
				i-- ;
				if(i == -1)
					i = 5 ;
				reverse(32, i + 10, a[i]) ;
				break ;

			case 80:
				normal(32, i + 10, a[i]) ;
				i++ ;
				if(i == 6)
					i = 0 ;
				reverse(32, i + 10, a[i]) ;
				break ;

			case 13:
				done = 1 ;
		}
	}
	while(!done) ;
	_setcursortype(_NOCURSOR) ;
	return(i + 49) ;
}
/*The function main_menu() is used to display the main menu of university managment system.
This function uses 6 main options and each has its specific purposes for maintaining
the university.In this menu,the user can avail the facilities by pressing any number
from 1 to 5 and in case he presses any other key the prompt will come back from menu to the
source promgram or it is better to press '0' to exit from the menu.other than 0 and 1...5
if you press any other key the university managment system do not response till you press a valid number
*/
void main_menu::control_menu()
{
	char choice ;
	do
	{
		choice = menu() ;

		clrscr() ;

		switch(choice)
		{
			case '1':
				box(3, 1, 75, 24) ;
				box(5, 2, 73, 23) ;
				gotoxy(7, 4) ;
				entry_menu() ;		//sub menu of main menu
				break ;

			case '2':
				box(3, 1, 75, 24) ;
				box(5, 2, 73, 23) ;
				gotoxy(7, 5) ;
				display_menu() ;	//sub menu of main menu
				break ;

			case '3':
				box(3, 1, 75, 24) ;
				box(5, 2, 73, 23) ;
				gotoxy(7, 6) ;
				enquiry_menu() ;	//sub menu of main menu
				break ;

			case '4':
				box(3, 1, 75, 24) ;
				box(5, 2, 73, 23) ;
				gotoxy(7, 8) ;
				modification_menu() ;	//sub menu of main menu
				break ;

			case '5':
				box(3, 1, 75, 24) ;
				box(5, 2, 73, 23) ;
				gotoxy(7, 9) ;
				performance_menu() ;	//sub menu of main menu
				break ;

			case '6':
				exit(0) ;
		}
	} while(choice != 5) ;
}
/*design of entry menu:- This function is used to return the cursor position to the entry menu function where the menu prompt is valid(design function)*/
char main_menu::e_menu()
{
	clrscr() ;

	textcolor(22) ;
	box(25, 6, 65, 20) ;
	box(23, 4, 67, 22) ;
	textcolor(5 + 143) ;
	gotoxy(34, 5) ;
	textbackground(GREEN) ;
	cprintf("Entry Menu") ;
	textcolor(22) ;
	textbackground(BLACK) ;
	for(int i = 1; i < 6; i++)
		normal(32, i + 10, b[i]) ;
	reverse(32, 10, b[0]) ;
	i = done = 0 ;
	_setcursortype(_NOCURSOR) ;	//change the cursor
	do
	{
		int key = getch() ;
		switch(key)
		{
			 case 72:
				normal(32, i + 10, b[i]) ;
				i-- ;
				if(i == -1)
					i = 5 ;
				reverse(32, i + 10, b[i]) ;
				break ;

			 case 80:
				normal(32, i +10, b[i]) ;
				i++ ;
				if(i == 6)
					i = 0 ;
				reverse(32, i + 10, b[i]) ;
				break ;

			case 13:
				done = 1 ;
		}
	} while(!done) ;
	_setcursortype(_NOCURSOR) ;
	return(i + 49) ;
}
/*Function for entry menu with open teacher, student, examform, schedule and result sub-menu.This is one of the submenu which manages
five basic operations such as:
	-New Teacher
	-New Student
	-Exam Form
	-Exam Schedule
	-Result
while entering new teacher information teacher name, address, streem, degree are asked to enter
student menu provides information to add that are nessary.*/
void main_menu::entry_menu()
{
	char choice ;
	student stu ;
	teacher coll ;
	examinfo einfo ;
	do
	{
		choice = e_menu() ;
		clrscr() ;
		switch(choice)
		{
			case '1':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 gotoxy(7, 4) ;
				 coll.new_teacher() ;	//sub menu of entry menu
				 break ;

			case '2':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 gotoxy(7, 5) ;
				 stu.new_student() ;	//sub menu of entry menu
				 break ;

			 case '3':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 gotoxy(7, 6) ;
				 einfo.exam_formentry() ;	//sub menu of entry menu
				 break ;

			case '4':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 gotoxy(7, 7) ;
				 einfo.exam_scheduleentry() ;	//sub menu of entry menu
				 break ;

			case '5':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 gotoxy(7, 8) ;
				 einfo.result_entry() ;	//sub menu of entry menu
				 break ;

			case '6':
				 return  ;
		}
	}while(choice != 5) ;
}
/*design of display menu:-This function is used to return the cursor poisition to the display menu function where the menu prompt is valid(design part)*/
char main_menu::d_menu()
{
	clrscr() ;
	textcolor(22) ;
	box(25, 6, 65, 20) ;
	box(23, 4, 67, 22) ;
	textcolor(5 + 143) ;
	gotoxy(34, 5) ;
	textbackground(GREEN) ;
	cprintf("Display Menu") ;
	textcolor(22) ;
	textbackground(BLACK) ;
	for(int i = 1; i < 7; i++)
		normal(32, i + 10, c[i]) ;
	reverse(32, 10, c[0]) ;
	i = done = 0 ;
	_setcursortype(_NOCURSOR) ;	//change the cursor type
	do
	{
		int key = getch() ;
		switch(key)
		{
			 case 72:
				normal(32, i+10, c[i]) ;
				i-- ;
				if(i==-1)
					i=5 ;
				reverse(32, i+10, c[i]) ;
				break ;

			 case 80:
				normal(32, i+10, c[i]) ;
				i++ ;
				if(i==7)
					i=0 ;
				reverse(32, i+10, c[i]) ;
				break ;

			case 13:
				done = 1 ;
		}
	}while(!done) ;
	_setcursortype(_NOCURSOR) ;
	return(i + 49) ;
}
/*Function for display menu with teacher,  student,  exam form,  exam schedule,  and result.This is one of the sub menu which manages
five operations such as:
	-Teacher
	-Student
	-Time-Table
	-Exam Form
	-Exam Schedule
	-Result
while displaying records it displays all the records that were enterd in the entry section and
extract this information from their particulat database files*/
void main_menu::display_menu()
{
	char choice ;
	teacher coll ;
	student stu ;
	examinfo einfo ;
	do
	{
		choice = d_menu() ;
		clrscr() ;
		switch(choice)
		{
			case '1':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 coll.display_list() ;	//sub menu of display menu
				 getch() ;
				 break ;

			case '2':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 stu.display_list() ;	//sub menu of display menu
				 getch() ;
				 break ;
			case '3':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 timetable();
				 getch();
				 break;

			case '4':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				  _setcursortype(_NORMALCURSOR) ;
				 einfo.display_list() ;	//submenu of display menu
				 getch() ;
				 break ;

			case '5':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				  _setcursortype(_NORMALCURSOR) ;
				 einfo.display_schedulelist() ;	//sub menu of dispalay menu
				 getch() ;
				 break ;

			case '6':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 einfo.resultdisplay_list() ;	//sub menu of display menu
				 getch() ;
				 break ;

			case '7':
				 return ;
		}
	}while(choice != 5) ;
}
void main_menu::timetable()
{
int sw,sid=0,tid=0;
gotoxy(8,5);
cout<<"1.Student "<<endl;
gotoxy(8,6);
cout<<"2.Teacher "<<endl;
gotoxy(8,8);
cout<<"Choose whose timetable you want to see"<<endl;
gotoxy(8,10);
cin>>sw;
switch(sw)
{
case 1:clrscr();
       box(3, 1, 75, 24) ;
       box(5, 2, 73, 23) ;
       gotoxy(8,3);
       cout<<"Enter the Student ID: ";
       cin>>sid;
       switch(sid)
       {
       case 92:
       clrscr();
       box(3, 1, 75, 24) ;
       box(5, 2, 73, 23) ;
       gotoxy(8,3);
       cout<<"| Time   | Monday | Tuesday | Wednesday | Thursday | Friday |"<<endl<<endl;
       gotoxy(8,4);
       cout<<"============================================================="<<endl<<endl;
       gotoxy(8,5);
       cout<<"| 8-9 am | Maths  | English | Physics   | English  | Physics|"<<endl;
       gotoxy(8,6);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,7);
       cout<<"| 9-10 am| Maths  | Maths   | Chemistry | Ethics   |  EVS   |"<<endl;
       gotoxy(8,8);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,9);
       cout<<"| 9-11 am| English|No class | Physics   |   EEE    |  Maths |"<<endl;
       gotoxy(8,10);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,11);
       cout<<"                       Break(11-12)                          "<<endl;
       gotoxy(8,12);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,13);
       cout<<"| 12-2 pm| CS LAB | No class|  CS Lab   | CHEM LAB | Matlab |"<<endl;
       gotoxy(8,14);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,15);
       cout<<"| 2-4 pm |No class| Phy Lab |  CS Lab   | No class |EEE LAB |"<<endl;
       gotoxy(8,16);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,17);
       cout<<"| 4-6 pm | CS LAB | Phy Lab |  No class |  CS LAB  |No class|"<<endl;
       gotoxy(8,18);
       cout<<"============================================================="<<endl;
       break;
case 49:
       clrscr();
       box(3, 1, 75, 24) ;
       box(5, 2, 73, 23) ;
       gotoxy(8,3);
       cout<<"| Time   | Monday | Tuesday | Wednesday | Thursday | Friday |"<<endl<<endl;
       gotoxy(8,4);
       cout<<"============================================================="<<endl<<endl;
       gotoxy(8,5);
       cout<<"| 8-9 am | English|  Maths  | No class  | English  |  EEE   |"<<endl;
       gotoxy(8,6);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,7);
       cout<<"| 9-10 am| Maths  | No class| Chemistry | No class |  EVS   |"<<endl;
       gotoxy(8,8);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,9);
       cout<<"| 9-11 am|   EEE  | EVS     | Physics   | Ethics   |  Maths |"<<endl;
       gotoxy(8,10);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,11);
       cout<<"                       Break(11-12)                          "<<endl;
       gotoxy(8,12);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,13);
       cout<<"| 12-2 pm|No class| CS Lab  |  CS Lab   | No class |No class|"<<endl;
       gotoxy(8,14);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,15);
       cout<<"| 2-4 pm | CS Lab | Phy Lab | CHEM Lab  | No class | Matlab |"<<endl;
       gotoxy(8,16);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,17);
       cout<<"| 4-6 pm |EEE LAB | No class|  No class |  CS LAB  | CS Lab |"<<endl;
       gotoxy(8,18);
       cout<<"============================================================="<<endl;
       break;
case 31:
       clrscr();
       box(3, 1, 75, 24) ;
       box(5, 2, 73, 23) ;
       gotoxy(8,3);
       cout<<"| Time   | Monday | Tuesday | Wednesday | Thursday | Friday |"<<endl<<endl;
       gotoxy(8,4);
       cout<<"============================================================="<<endl<<endl;
       gotoxy(8,5);
       cout<<"| 8-9 am |No class|No class | Chemistry | English  | Ethics |"<<endl;
       gotoxy(8,6);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,7);
       cout<<"| 9-10 am| Maths  | Maths   |   Maths   | No class |English |"<<endl;
       gotoxy(8,8);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,9);
       cout<<"| 9-11 am|  EEE   | Maths   | Physics   |   Maths  |No class|"<<endl;
       gotoxy(8,10);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,11);
       cout<<"                       Break(11-12)                          "<<endl;
       gotoxy(8,12);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,13);
       cout<<"| 12-2 pm|EEE LAB | No class|  CS Lab   | CHEM LAB | CS LAB |"<<endl;
       gotoxy(8,14);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,15);
       cout<<"| 2-4 pm | CS LAB | EEE Lab |  No class |  CS LAB  |No class|"<<endl;
       gotoxy(8,16);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,17);
       cout<<"| 4-6 pm |No Class| Phy Lab |  CHEM LAB | No class | Matlab |"<<endl;
       gotoxy(8,18);
       cout<<"============================================================="<<endl;
       break;
default:
	clrscr();
       box(3, 1, 75, 24) ;
       box(5, 2, 73, 23) ;
       gotoxy(8,3);
       cout<<"Invalid choice"<<endl;
       break;
       }
       break;
case 2:clrscr();
       box(3, 1, 75, 24) ;
       box(5, 2, 73, 23) ;
       gotoxy(8,3);
       cout<<"Enter the Teacher ID: ";
       cin>>tid;
       switch(tid)
       {
case 92:
       clrscr();
       box(3, 1, 75, 24) ;
       box(5, 2, 73, 23) ;
       gotoxy(8,3);
       cout<<"| Time   | Monday | Tuesday | Wednesday | Thursday | Friday |"<<endl<<endl;
       gotoxy(8,4);
       cout<<"============================================================="<<endl<<endl;
       gotoxy(8,5);
       cout<<"| 8-9 am |   912  | No class|    802    |   501    |   G07  |"<<endl;
       gotoxy(8,6);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,7);
       cout<<"| 9-10 am|No class|   912   | No class  |    912   |  912   |"<<endl;
       gotoxy(8,8);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,9);
       cout<<"| 9-11 am|  802   |   G07   |    912    |   G07    |  802   |"<<endl;
       gotoxy(8,10);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,11);
       cout<<"                       Break(11-12)                          "<<endl;
       gotoxy(8,12);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,13);
       cout<<"| 12-2 pm|  322   | No class|  No class |    518   |   901  |"<<endl;
       gotoxy(8,14);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,15);
       cout<<"| 2-4 pm |  412   |   412   |   G03     |    711   |No class|"<<endl;
       gotoxy(8,16);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,17);
       cout<<"| 4-6 pm |  909   |   322   |  No class |    901   |No class|"<<endl;
       gotoxy(8,18);
       cout<<"============================================================="<<endl;
       break;
case 49:

       clrscr();
       box(3, 1, 75, 24) ;
       box(5, 2, 73, 23) ;
       gotoxy(8,3);
       cout<<"| Time   | Monday | Tuesday | Wednesday | Thursday | Friday |"<<endl<<endl;
       gotoxy(8,4);
       cout<<"============================================================="<<endl<<endl;
       gotoxy(8,5);
       cout<<"| 8-9 am |   207  | No class|    622    |   130    |   G05  |"<<endl;
       gotoxy(8,6);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,7);
       cout<<"| 9-10 am|No class|   622   | No class  |    622   |  207   |"<<endl;
       gotoxy(8,8);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,9);
       cout<<"| 9-11 am|  411   |   G05   |    130    |   G05    |  130   |"<<endl;
       gotoxy(8,10);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,11);
       cout<<"                       Break(11-12)                          "<<endl;
       gotoxy(8,12);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,13);
       cout<<"| 12-2 pm|  231   | No class|  No class |    519   |   902  |"<<endl;
       gotoxy(8,14);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,15);
       cout<<"| 2-4 pm |  512   |   231   |   G01     |    121   |No class|"<<endl;
       gotoxy(8,16);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,17);
       cout<<"| 4-6 pm |  512   |   404   |  No class |    903   |No class|"<<endl;
       gotoxy(8,18);
       cout<<"============================================================="<<endl;
       break;
case 31:
       clrscr();
       box(3, 1, 75, 24) ;
       box(5, 2, 73, 23) ;
       gotoxy(8,3);
       cout<<"| Time   | Monday | Tuesday | Wednesday | Thursday | Friday |"<<endl<<endl;
       gotoxy(8,4);
       cout<<"============================================================="<<endl<<endl;
       gotoxy(8,5);
       cout<<"| 8-9 am |   222  | No class|    432    |   222    |   G01  |"<<endl;
       gotoxy(8,6);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,7);
       cout<<"| 9-10 am|No class|   432   | No class  |   502    |  432   |"<<endl;
       gotoxy(8,8);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,9);
       cout<<"| 9-11 am|  101   |   801   |    G01    |   G01    |  801   |"<<endl;
       gotoxy(8,10);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,11);
       cout<<"                       Break(11-12)                          "<<endl;
       gotoxy(8,12);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,13);
       cout<<"| 12-2 pm|  901   | No class|  No class |    123   |   109  |"<<endl;
       gotoxy(8,14);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,15);
       cout<<"| 2-4 pm |  111   |   123   |   G10     |    220   |No class|"<<endl;
       gotoxy(8,16);
       cout<<"-------------------------------------------------------------"<<endl;
       gotoxy(8,17);
       cout<<"| 4-6 pm |  G10   |   109   |  No class |    109   |No class|"<<endl;
       gotoxy(8,18);
       cout<<"============================================================="<<endl;
       break;
default:
	clrscr();
       box(3, 1, 75, 24) ;
       box(5, 2, 73, 23) ;
       gotoxy(8,3);
       cout<<"Invalid choice"<<endl;
       break;
       }
       break;
default:
	clrscr();
       box(3, 1, 75, 24) ;
       box(5, 2, 73, 23) ;
       gotoxy(8,3);
       cout<<"Invalid choice"<<endl;
}
}
/*design of enquiry menu:-This function is used to return the cursor position to the enquiry menu function where the menu prompt is valid(design function)*/
char main_menu::enqu_menu()
{
	clrscr() ;
	textcolor(22) ;
	box(25, 6, 65, 20) ;
	box(23, 4, 67, 22) ;
	textcolor(5 + 143) ;
	gotoxy(34, 5) ;
	textbackground(GREEN) ;
	cprintf("Enquiry Menu") ;
	textcolor(22) ;
	textbackground(BLACK) ;
	for(int i = 1; i < 3; i++)
		normal(32, i + 10, d[i]) ;
	reverse(32, 10, d[0]) ;
	i = done = 0 ;
	_setcursortype(_NOCURSOR) ;	//change the cursor type
	do
	{
		int key = getch() ;
		switch(key)
		{
			  case 72:
				normal(32, i+10, d[i]) ;
				i-- ;
				if(i==-1)
					i=2 ;
				reverse(32, i+10, d[i]) ;
				break ;

			  case 80:
				normal(32, i+10, d[i]) ;
				i++ ;
				if(i==3)
					i=0 ;
				reverse(32, i+10, d[i]) ;
				break ;

			case 13:
				done = 1 ;
		}
	}while(!done) ;
	_setcursortype(_NOCURSOR) ;
	return(i + 49) ;
}
/*This function is used for the enwuiry of a particular teacher or student
This function asks the user to enter id of the teacher or student for which
they want to enquir about*/
void main_menu::enquiry_menu()
{
	char choice ;
	teacher coll ;
	student stu ;
	examinfo einfo ;
	do
	{
		choice = enqu_menu() ;
		clrscr() ;
		switch(choice)
		{
			case '1':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 coll.teacher_enquiry() ;	//Sub menu of Enquiry
				 getch() ;
				 break ;

			case '2':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 stu.enquiry_student() ;		//sub menu of Enquiry
				 getch() ;
				 break ;

			case '3':
				 return ;
		}
	}while(choice != 5) ;
}
/*design of modify menu:-This function is used to return the cursor position to the modify menu function where the menu prompt is valid(design function)*/
char main_menu::mod_menu()
{
	clrscr() ;
	textcolor(22) ;
	box(25, 6, 65, 20) ;
	box(23, 4, 67, 22) ;
	textcolor(5 + 143) ;
	gotoxy(34, 5) ;
	textbackground(GREEN) ;
	cprintf("Modification Menu") ;
	textcolor(22) ;
	textbackground(BLACK) ;
	for(int i = 1; i < 3; i++)
		normal(32, i + 10, e[i]) ;
	reverse(32, 10, e[0]) ;
	i = done = 0 ;
	_setcursortype(_NOCURSOR) ;
	do
	{
		int key = getch() ;
		switch(key)
		{
			 case 72:
				normal(32, i+10, e[i]) ;
				i-- ;
				if(i==-1)
					i=2 ;
				reverse(32, i+10, e[i]) ;
				break ;

			 case 80:
				normal(32, i+10, e[i]) ;
				i++ ;
				if(i==3)
					i=0 ;
				reverse(32, i+10, e[i]) ;
				break ;

			case 13:
				done = 1 ;
		}
	}while(!done) ;
	_setcursortype(_NOCURSOR) ;
	return(i + 49) ;
}
/*This function is used to modify the information of the teacher or student.
This function asks for the teacher or student id for modification.First it
shows the old record and then asks the user "Do You Want To Modify(Y/N).If
the user press yes it ask the user to enter the new information and then
saves it in their particular data files*/
void main_menu::modification_menu()
{
	char choice ;
	teacher coll ;
	student stu ;
	examinfo einfo ;
	do
	{
		choice = mod_menu() ;
		clrscr() ;
		switch(choice)
		{
			case '1':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 coll.teacher_modification() ;	//sub menu of modification
				 break ;

			case '2':
				 box(3, 1, 75, 24) ;
				 box(5, 2, 73, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 stu.student_modification() ;	//sub menu ofmodification
				 break ;

			case '3':
				  return ;
		}
	}while(choice != 3) ;
}
/*design of perform menu:-This function is used to return the cursor position to the performance menu function where the menu prompt is valid(design function)*/
char main_menu::perform_menu()
{
	clrscr() ;
	textcolor(22) ;
	box(25, 6, 65, 20) ;
	box(23, 4, 67, 22) ;
	textcolor(5 + 143) ;
	gotoxy(34, 5) ;
	textbackground(GREEN) ;
	cprintf("Performance Menu") ;
	textcolor(22) ;
	textbackground(BLACK) ;
	for(int i = 1; i < 2; i++)
		normal(32, i + 10, f[i]) ;
	reverse(32, 10, f[0]) ;
	i = done = 0 ;
	_setcursortype(_NOCURSOR) ;
	do
	{
		int key = getch() ;
		switch(key)
		{
			  case 72:
				normal(32, i+10, f[i]) ;
				i-- ;
				if(i==-1)
					i=1 ;
				reverse(32, i+10, f[i]) ;
				break ;

			  case 80:
				normal(32, i+10, f[i]) ;
				i++ ;
				if(i==2)
					i=0 ;
				reverse(32, i+10, f[i]) ;
				break ;

			case 13:
				done = 1 ;
		}
	} while(!done) ;
	_setcursortype(_NOCURSOR) ;
	return(i + 49) ;
}
/*This function dispalys the performance of the university such as
	- Foundation
	-Annual Report
*/
void main_menu::performance_menu()
{
	char choice ;
	performance perf ;
	do
	{
		choice = perform_menu() ;
		clrscr() ;
		switch(choice)
		{
			case '1':
				 box(2, 1, 77, 24) ;
				 box(3, 2, 75, 23) ;
				 _setcursortype(_NORMALCURSOR) ;
				 perf.foundation() ;
				 getch() ;
				 break ;

			 case '2':
				   return ;
		}
	}while(choice != 2) ;
}
/* function to draw horizontal line.This public function draws one horizontal line at a time*/
void shape::line_hor(int coloumn1, int coloumn2, int row, char c)
{
	for(coloumn1; coloumn1 <= coloumn2; coloumn1++)
	{
		gotoxy(coloumn1, row) ;
		cout<<c ;
	}
}

/*function to draw vertical line.this public function draws one vertical line at a time.*/
void shape::line_ver(int row1, int row2, int coloumn, char c)
{
	for(row1; row1 <= row2; row1++)
	{
		 gotoxy(coloumn, row1) ;
		 cout << c ;
	}
}

/*Function for drawing box.This function draws a box for menus*/
void shape::box(int coloumn1, int row1, int coloumn2, int row2, char c)
{
	char ch = 218 ;
	char c1, c2, c3, c4 ;
	char l1 = 196, l2 = 179 ;
	if(c == ch)
	{
		c1 = 218 ;
		c2 = 191 ;
		c3 = 217 ;
		c4 = 217 ;
		l1 = 196 ;
		l2 = 179 ;
	}
	else
	{
		c1 = c ;
		c2 = c ;
		c3 = c ;
		c4 = c ;
		l1 = c ;
		c2 = c ;
	}
	gotoxy(coloumn1, row1) ;
	cout << c1 ;
	gotoxy(coloumn2, row1) ;
	cout << c2 ;
	gotoxy(coloumn1, row2) ;
	cout << c3 ;
	gotoxy(coloumn2, row2) ;
	cout << c4 ;
	coloumn1++ ;
	coloumn2-- ;
	line_hor(coloumn1, coloumn2, row1, l1) ;//Horizontal lines
	line_hor(coloumn1, coloumn2, row1, l1) ;
	coloumn1-- ;
	coloumn2++ ;
	row1++ ;
	row2-- ;
	line_ver(row1, row2, coloumn1, l2) ;//vertical line
	line_ver(row1, row2, coloumn2, l2) ;
}
/*Function for creating a new teacher.This is a very important function which is used used to create new teacher with
all the details of the teacher.This function uses member functions like last_collid(), add_to_file(), delete_account etc.
The last_collid() function will create automatically a new teacher id number after cheaking from the "COLLEGE.dat" file.
Here the teacher id numbers start from 1 onwards if it is the first record.Also in this function the validation cheaking
occurs to the name, address, stream and degree.At the time of validation cheaking the name,
address, stream and degree should not blank and sholud not more than the specified length.*/
void teacher::new_teacher(void)
{
	char ch ;
	int i, valid ;
	clrscr() ;
	teacher coll ;
	shape s ;
	s.box(2, 1, 79, 25, 318) ;
	s.box(25, 2, 54, 4, 219) ;
	gotoxy(65, 2) ;
	cout<<"<0>=EXIT" ;
	gotoxy(3, 3) ;
	for(i = 1; i <= 76; i++)
		cprintf(" ") ;
	textbackground(BLACK) ;
	textcolor(BLACK+BLINK) ;
	textbackground(WHITE) ;
	gotoxy(30, 3) ;
	_setcursortype(_NOCURSOR) ;//changes cursor type
	cprintf("TEACHER-ENTRY") ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;

	getch() ;

	int d1, m1, y1 ;
	struct date d ;

	getdate(&d) ;	//For extracting system date

	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;

	int coll_id ,x;
       //	coll_id = coll.last_collid() ;
       //	coll_id++ ;
	do
	{
		coll_id=(rand()%99)+0;
		x=found_teacher(coll_id);
	}while(x==1);
	char coll_name[30], coll_loc[30], coll_str[30], coll_degI[30], coll_degII[30] ;
	_setcursortype(_NORMALCURSOR) ;
	gotoxy(5, 6) ;
	cout << "DATE:-"<< d1 <<"/" << m1 << "/" << y1 ;
	gotoxy(5, 8) ;
	cout << "TEACHER-ID:"<<coll_id ;
	gotoxy(5, 10) ;
	cout << "NAME:" ;
	gotoxy(5, 12) ;
	cout <<"CABIN NO.:" ;
	gotoxy(5, 14) ;
	cout <<"SUBJECT:" ;
	gotoxy(5, 16) ;
	cout <<"QUALIFICATION:" ;
	gotoxy(5, 18) ;
	cout <<"PHONE NO.:" ;
	do
	{
		coll.clear(16, 10) ;
		coll.clear(5, 23) ;
		gotoxy(5, 23) ;
		cout << "ENTER THE NAME OF THE TEACHER" ;
		valid = 1 ;
		gotoxy(16, 10) ;
		gets(coll_name) ;
		strupr(coll_name) ;
		if(coll_name[0] == '0')
			return ;
		if(strlen(coll_name) == 0 || strlen(coll_name) > 20)
		{
			valid = 0 ;
			gotoxy(5, 23) ;
			cprintf("\7 NAME SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		coll.clear(28, 12) ;
		coll.clear(5, 23) ;
		gotoxy(5, 23) ;
		cout <<"ENTER THE CABIN NO. OF THE TEACHER" ;
		valid = 1 ;
		gotoxy(28, 12) ;
		gets(coll_loc) ;
		strupr(coll_loc) ;
		if(coll_loc[0] == '0')
			return ;
		if(strlen(coll_loc) == 0 || strlen(coll_loc) > 20)
		{
			valid = 0 ;
			gotoxy(5, 23) ;
			cprintf("\7 CABIN NO. SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		coll.clear(26, 14) ;
		for(int i = 5; i < 79; i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}

		gotoxy(5, 23) ;
		cout << "ENTER THE SUBJECT TAUGHT BY THE TEACHER" ;
		valid = 1 ;
		gotoxy(26, 14) ;
		gets(coll_str) ;
		strupr(coll_str) ;
		if(coll_str[0] == '0')
			return ;
		if(strlen(coll_str) == 0 || strlen(coll_str) > 20)
		{
			valid = 0 ;
			gotoxy(5, 23) ;
			cprintf("\7 SUBJECT SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		coll.clear(26, 16) ;
		for(int i = 5; i < 79; i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER THE QUALIFICATION OF THE TEACHER" ;
		valid = 1 ;
		gotoxy(26, 16) ;
		gets(coll_degI) ;
		strupr(coll_degI) ;
		if(coll_degI[0] == '0')
			return ;
		if(strlen(coll_degI) == 0 || strlen(coll_degI) > 20)
		{
			valid = 0 ;
			gotoxy(5, 23) ;
			cprintf("\7 QUALIFICATION SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		coll.clear(29, 18) ;
		for(int i = 5; i < 79; i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER THE PHONE NO. OF THE TEACHER" ;
		valid = 1 ;
		gotoxy(29, 18) ;
		gets(coll_degII) ;
		strupr(coll_degII) ;
		if(coll_degII[0] == '0')
			return ;
		if(strlen(coll_degII) == 0 || strlen(coll_degII) > 20)
		{
			valid = 0 ;
			gotoxy(5, 23) ;
			cprintf("\7 PHONE NO. SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		valid = 1 ;
		for(int i = 5; i < 79; i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"DO YOU WANT TO SAVE THE RECORD(Y/N):" ;
		ch = getch() ;
		if(ch == 0)
			return ;
		ch = toupper(ch) ;
	} while(ch != 'N' && ch != 'Y') ;
	if(ch == 'N')
		return ;
	//append the record to teacher, dat
	add_to_file(coll_id, coll_name, coll_loc, coll_str, coll_degI, coll_degII) ;
}
/*This is a function which displays the details of all the teachers under the university
with all the detail such as colleg id,  teacher name,  teacher address,  teacher stream, teacher degree
that are under that teacher.Thus the user can look and know the detail of teachers*/
void teacher::display_list(void)
{
	clrscr() ;
	int flag ;
	fstream file ;
	gotoxy(25, 1) ;
	cout <<"TEACHER DISPLAY LIST" ;
	gotoxy(25, 2) ;
	cout <<"======================" ;
	gotoxy(1, 3) ;
	for(int j = 1; j <= 79; j++)
		cout << "=" ;
	gotoxy(1, 5) ;
	cout <<"ID" ;
	gotoxy(4, 5) ;
	cout <<"NAME" ;
	gotoxy(20, 5) ;
	cout <<"CABIN NO" ;
	gotoxy(34, 5) ;
	cout <<"SUBJECT" ;
	gotoxy(48, 5) ;
	cout <<"QUALIFICATION" ;
	gotoxy(62, 5) ;
	cout <<"    PHONE NO." ;
	gotoxy(1, 6) ;
	for(j = 1; j <= 79; j++)
		cout << "=" ;
	file.open("COLLEGE.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int row = 7 ;
	while(file.read((char*) this, sizeof(teacher)))
	{
		flag = 0 ;
		delay(2) ;
		gotoxy(1, row) ;
		cout <<coll_id ;
		gotoxy(4, row) ;
		puts(coll_name) ;
		gotoxy(20, row) ;
		puts(coll_loc) ;
		gotoxy(34, row) ;
		puts(coll_str) ;
		gotoxy(48, row) ;
		puts(coll_degI) ;
		gotoxy(66, row) ;
		puts(coll_degII) ;
		row++ ;
		if(row > 23)
		{
			flag = 1 ;
			row = 6 ;
			gotoxy(4, 24) ;
			cout <<"PRESS ANY KEY TO CONTINUE" ;
			clrscr() ;
		}
	}
	gotoxy(1, row) ;
	for(j = 1; j <= 79; j++)
		cout << "=" ;
	row++ ;
	file.close() ;
	if(!flag)
	{
		gotoxy(4, 24) ;
		cout <<"PRESS ANY KEY TO CONTINUE:" ;
		getch() ;
	}
}
/*This function is used to enquire about the teacher.This function ask for the teacher id
to enquie about and after matching the id it displays the record of the enquired teacher */
void teacher::teacher_enquiry(void)
{
	clrscr() ;
	int t_collid = 0 ;
	teacher coll ;
	gotoxy(71, 1) ;
	cout <<"<0>=EXIT" ;
	gotoxy(5, 5) ;
	cout <<"ENTER TEACHER ID" ;
	cin>>t_collid ;
	if(t_collid == 0)
		return ;
	if(!coll.found_teacher(t_collid))
	{
		gotoxy(5, 5) ;
		cout <<"\7 INVALID TEACHER ID" ;
		getch() ;
		return ;
	}
	box_for_enquiryteacher(t_collid) ;
	int row = 9, flag ;
	fstream file ;
	file.open("COLLEGE.dat", ios::in) ;
	while(file.read((char*)this, sizeof(teacher)))
	{
		if(coll_id == t_collid)
		{
			delay(2) ;
			gotoxy(4, row) ;
			puts(coll_str) ;
			gotoxy(38, row) ;
			puts(coll_degI) ;
			gotoxy(55, row) ;
			puts(coll_degII) ;
			row++ ;
			if(row > 23)
			{
				flag = 1 ;
				row = 7 ;
				gotoxy(4, 24) ;
				cout <<"PRESS ANY KEY TO CONTINUE:" ;
				getch() ;
				clrscr() ;
				box_for_enquiryteacher(t_collid) ;
			}
		}
	}
	file.close() ;
	if(!flag)
	{
		gotoxy(4, 24) ;
		cout <<"PRESS ANY KEY TO CONTINUE" ;
		getch() ;
	}
}
/* This function is used to modify the teacher detail.This function asks for the
teacher id for which the information is to be modified.Then it asks "Do you want to
Modify (Y/N)".If 'Y' is entred it asks for the user to enter new information.
*/
void teacher::teacher_modification(void)
{
	clrscr() ;
	int j ;
	int t, t_collid ;
	gotoxy(17, 1) ;
	cout <<"<0>=EXIT" ;
	gotoxy(5, 5) ;
	cout << "ENTER THE TEACHER ID:" ;
	cin >> t_collid ;
	if(t_collid==0)
		return ;
	clrscr() ;
	if(!found_teacher(t_collid))
	{
		gotoxy(5, 5) ;
		cout <<"\7 TEACHER NOT FOUND:" ;
		getch() ;
		return ;
	}
	gotoxy(71, 1) ;
	cout <<"<0>=EXIT" ;
	textbackground(WHITE) ;
	gotoxy(3, 3) ;
	for(j = 1; j <= 76; j++)
		cprintf("") ;
	textbackground(BLACK) ;
	textcolor(BLACK+BLINK) ;
	textbackground(WHITE) ;
	gotoxy(30, 3) ;
	cprintf("MODIFY TEACHER DETAIL") ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;
	int d1, m1, y1 ;
	struct date d ;
	getdate(&d) ;
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	gotoxy(4, 2) ;
	cout << "DATE:"<<d1<<"/"<<m1<<"/"<<y1 ;
	char ch ;
	display(t_collid) ;
	teacher coll ;
	do{
		coll.clear(5, 13) ;
		gotoxy(5, 13) ;
		cout <<"MODIFY TEACHER DETAILS:(Y/N)" ;
		ch=getche() ;
		if(ch=='0')
			return ;
		ch=toupper(ch) ;
	}while(ch!='N'&&ch!='Y') ;
	if(ch=='N')
		return ;
	int modified=0, valid ;
	char t_name[30], t_loc[30], t_str[30], t_degI[30], t_degII[30] ;
	gotoxy(5, 15) ;
	cout <<"NAME:" ;
	gotoxy(5, 16) ;
	cout <<"CABIN NO.:" ;
	gotoxy(5, 17) ;
	cout <<"SUBJECT:" ;
	gotoxy(5, 18) ;
	cout <<"QUALIFICATION:" ;
	gotoxy(5, 19) ;
	cout <<"PHONE NO.:" ;
	do
	{
		coll.clear(15, 15) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER NAME OR PRESS ENTER FOR NO CHANGE:" ;
		valid=1 ;
		gotoxy(15, 15) ;
		gets(t_name) ;
		strupr(t_name) ;
		if(t_name[0]=='0')
			return ;
		if(strlen(t_name)>20)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("NAME SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		coll.clear(20, 16) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER CABIN NO. OR PRESS ENTER FOR NO CHANGE:" ;
		valid=1 ;
		gotoxy(20, 16) ;
		gets(t_loc) ;
		strupr(t_loc) ;
		if(t_loc[0]=='0')
			return ;
		if(strlen(t_loc)>20)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("CABIN NO. SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		coll.clear(18, 17) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER SUBJECT OR PRESS ENTER FOR NO CHANGE:" ;
		valid=1 ;
		gotoxy(18, 17) ;
		gets(t_str) ;
		strupr(t_str) ;
		if(t_str[0]=='0')
			return ;
		if(strlen(t_str)>20)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("SUBJECT SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		coll.clear(18, 18) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER QUALIFICATION OR PRESS ENTER FOR NO CHANGE:" ;
		valid=1 ;
		gotoxy(18, 18) ;
		gets(t_degI) ;
		strupr(t_degI) ;
		if(t_degI[0]=='0')
			return ;
		if(strlen(t_degI)>20)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("QUALIFICATION SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		coll.clear(25, 19) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER PHONE NO. OR PRESS ENTER FOR NO CHANGE:" ;
		valid=1 ;
		gotoxy(25, 19) ;
		gets(t_degII) ;
		strupr(t_degII) ;
		if(t_degII[0]=='0')
			return ;
		if(strlen(t_degII)>20)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("PHONE NO. SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}while(!valid) ;
	if(strlen(t_degII)>0)
		modified=1 ;
	if(!modified)
		return ;
	coll.clear(5, 23) ;
	do
	{
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		valid=1 ;
		gotoxy(5, 21) ;
		cout <<"DO YOU WANT TO SAVE CHANGES(Y/N)" ;
		ch=getche() ;
		if(ch=='0')
			return ;
		ch=toupper(ch) ;
	}while(ch!='N'&&ch!='Y') ;
	if(ch=='N')
		return ;
	modify_teacher(t_collid, t_name, t_loc, t_str, t_degI, t_degII) ;
	gotoxy(5, 22) ;
	cout <<"\7 RECORD MODIFIED" ;
	gotoxy(5, 23) ;
	cout <<"PRESS ANY KEY TO CONTINUE" ;
	getch() ;
}

/*supporting function of teacher*/
/*Function for clearing specified row and coloumn. By using this function you can clear
from a specified row and coloumn in your screen. Here the function utillizes
two parrameter for clearing the row and coloumn*/
void teacher::clear(int col, int row)
{
	for(int j=col ;j<=76 ;j++)
	{
		gotoxy(j, row) ;
		cout <<"" ;
	}
}
/* Function to find a teacher for display teacher function. This is used to find any account in the
"teacher.dat"data files, where the file is searched from the first record position and it searches
whether the entred id exit or not. If it exit then the variable found will return a value 1 or
0 as the parameter*/
int teacher::found_teacher(int t_collid)
{
	fstream file ;
	file.open("COLLEGE.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int found=0 ;
	//searches the specified record in teacher.dat data file
	while(file.read((char*)this, sizeof(teacher)))
	{
		if(coll_id==t_collid)
		{
			found=1 ;
			break ;
		}
	}
	file.close() ;
	return found ;
}
/*Function for return name of the teacher from teacher.dat.This function is basically used
to return only name teacher if the teacher is in the "teacher.dat"data file.When the name is
returned it may simply display/modify other functions*/
char *teacher::return_name(int t_collid)
{
	fstream file ;
	file.open("COLLEGE.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_name[30] ;
	//returns the name to display at  screen if found.
	while(file.read((char*)this,  sizeof(teacher)))
	{
		if(coll_id==t_collid)
		{
			strcpy(t_name, coll_name) ;
			break ;
		}
	}
	file.close() ;
	return t_name ;
}
/*Function to return the location of the teacher from teacher.dat .This funcion is basicially
used to return only location of the teacher if location is in the "College.dat" data files.When
the loication  is returned it may simply display/modify other functions */
char *teacher::return_loc(int t_collid)
{
	fstream file ;
	file.open("COLLEGE.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_loc[30] ;
	//return the address to display at screen if found
	while(file.read((char*)this, sizeof(teacher)))
	{
		if(coll_id==t_collid)
		{
			strcpy(t_loc, coll_loc) ;
			break ;
		}
	}
	file.close() ;
	return t_loc ;
}
/*Function to return the stream of the teacher from teacher.dat .This funcion is basicially
used to return only stream of the teacher if stream is in the "teacher.dat" data files.When
the stream  is returned it may simply display/modify other functions */
char *teacher::return_str(int t_collid)
{
	fstream file ;
	file.open("COLLEGE.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_str[30] ;
	//return the stream to display at  screen if found
	while(file.read((char*)this, sizeof(teacher)))
	{
		if(coll_id==t_collid)
		{
			strcpy(t_str, coll_str) ;
			break ;
		}
	}
	file.close() ;
	return t_str ;
}
/*Function to return the stream of the teacher from teacher.dat .This funcion is basicially
used to return only stream of the teacher if stream is in the "teacher.dat" data files.When
the stream  is returned it may simply display/modify other functions */
char *teacher::return_degI(int t_collid)
{
	fstream file ;
	file.open("COLLEGE.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_degI[30] ;
	//return the degree to display at  screen if found
	while(file.read((char*)this, sizeof(teacher)))
	{
		if(coll_id==t_collid)
		{
			strcpy(t_degI, coll_degI) ;
			break ;
		}
	}
	file.close() ;
	return t_degI ;
}
/*Function to return the stream of the teacher from teacher.dat .This funcion is basicially
used to return only stream of the teacher if stream is in the "teacher.dat" data files.When
the stream  is returned it may simply display/modify other functions */
char *teacher::return_degII(int t_collid)
{
	fstream file ;
	file.open("COLLEGE.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_degII[30] ;
	//return the degree to display at  screen if found
	while(file.read((char*)this, sizeof(teacher)))
	{
		if(coll_id==t_collid)
		{
			strcpy(t_degII, coll_degII) ;
			break ;
		}
	}
	file.close() ;
	return t_degII ;
}


/*Function to display teacher details.This function displays the heading and
the teacher id, name, location and stream on the screen*/
void teacher::box_for_display(int t_collid)
{
	int d1, m1, y1 ;
	struct date d ;
	getdate (&d) ;
	d1=d.da_day ;
	m1=d.da_mon ;
	y1=d.da_year ;
	gotoxy(63, 2) ;
	cout <<"DATE:"<<d1<<"/"<<m1<<"/"<<y1 ;
	gotoxy(4, 2) ;
	cout <<"TEACHER ID"<<t_collid ;
	teacher coll ;
	char t_name[30] ;
	strcpy(t_name, coll.return_name(t_collid)) ;
	char t_loc[30] ;
	strcpy(t_loc, coll.return_loc(t_collid)) ;
	char t_stream[30] ;
	strcpy(t_stream, coll.return_str(t_collid)) ;
	gotoxy(25, 2) ;
	cout <<t_name ;
	gotoxy(25, 3) ;
	cout <<t_loc ;
	gotoxy(4, 5) ;
	cout <<"ENQUIRY MENU FOR TEACHER" ;
	textbackground(WHITE) ;
	textcolor(BLACK) ;
	textcolor(WHITE) ;
	gotoxy(1, 6) ;
	for(int i=1 ;i<=76 ;i++)
		cout <<"=" ;
	gotoxy(4, 7) ;
	cprintf("SUBJECT            QUALIFICATION          PHONE NO.") ;
	gotoxy(1, 8) ;
	for(i=1 ;i<=76 ;i++)
		cout <<"=" ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;
}
/*supporting function for teacher display*/
void teacher::display(int t_collid)
{
	fstream file ;
	file.open("COLLEGE.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	//Display the record content matching with t_collid from COLLEGE.dat data files.
	while(file.read((char*)this, sizeof(teacher)))
	{
		if(t_collid==coll_id)
		{
			gotoxy(8, 5) ;
			cout <<"TEACHER ID:"<<coll_id ;
			gotoxy(8, 6) ;
			cout <<"NAME:" ;
			puts(coll_name) ;
			gotoxy(8, 7) ;
			cout <<"CABIN NO.:" ;
			puts(coll_loc) ;
			gotoxy(8, 8) ;
			cout <<"SUBJECT:" ;
			puts(coll_str) ;
			gotoxy(8, 9) ;
			cout <<"QUALIFICATION:" ;
			puts(coll_degI) ;
			gotoxy(8, 10) ;
			cout <<"PHONE NO.:" ;
			puts(coll_degII) ;
			break ;
		}
	}
	file.close() ;
}
/*supporting function for modification of teacher*/
void teacher::modify_teacher(int t_collid, char t_name[30], char t_loc[30], char t_str[30], char t_degI[30], char t_degII[30])
{
	int recno ;
	recno=recordno(t_collid) ;
	fstream file ;
	//open file COLLEGE.dat for overwrite mode.
	file.open("COLLEGE.dat", ios::out|ios::ate) ;
	strcpy(coll_name, t_name) ;
	strcpy(coll_loc, t_loc) ;
	strcpy(coll_str, t_str) ;
	strcpy(coll_degI, t_degI) ;
	strcpy(coll_degII, t_degII) ;
	int position ;
	//finds the position in the data file ;
	position=(recno-1)*sizeof(teacher) ;
	file.seekp(position) ;
	//overwrite the modified record in to the COLLEGE.dat data file.
	file.write((char *)this, sizeof(teacher)) ;
	file.close() ;
	return ;
}
/*supporting function for generating the last teacher id*/
int teacher::last_collid(void)
{
	fstream file ;
	file.open("COLLEGE.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int count=0 ;
	//find the last id number.
	while(file.read((char *)this, sizeof(teacher)))
		count=coll_id ;
	file.close() ;
	return count ;
}
/* supporting function for add to file*/
void teacher::add_to_file(int t_collid, char t_name[30], char t_loc[30], char t_str[30], char t_degI[30], char t_degII[30])
{
	coll_id=t_collid ;
	strcpy(coll_name, t_name) ;
	strcpy(coll_loc, t_loc) ;
	strcpy(coll_str, t_str) ;
	strcpy(coll_degI, t_degI) ;
	strcpy(coll_degII, t_degII) ;
	cout <<coll_str ;
	//Append new record into COLLEGE.dat data files.
	fstream file ;
	file.open("COLLEGE.dat", ios::out|ios::app) ;
	file.write((char *)this, sizeof(teacher)) ;
	file.close() ;
}
/*supporting function for teacher enquiry*/
void teacher::box_for_enquiryteacher(int t_collid)
{
	gotoxy(4, 2) ;
	cout <<"TEACHER ID:"<<t_collid ;
	teacher coll ;
	char t_name[30] ;
	strcpy(t_name, coll.return_name(t_collid)) ;
	char t_loc[30] ;
	strcpy(t_loc, coll.return_loc(t_collid)) ;
	gotoxy(25, 2) ;
	cout <<t_name ;
	gotoxy(25, 3) ;
	cout <<t_loc ;
	gotoxy(4, 5) ;
	cout <<"ENQUIRY REPORT OF TEACHER";
	textbackground(WHITE) ;
	textcolor(BLACK) ;
	textbackground(WHITE) ;
	gotoxy(1, 6) ;
	for(int i=1 ;i<=76 ;i++)
		cout <<"=" ;
	gotoxy(4, 7) ;
	cprintf("SUBJECT                         QUALIFICATION         PHONE NO.") ;
	gotoxy(1, 8) ;
	for(i=1 ;i<=79 ;i++)
		cout <<"=" ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;
}
/*Function for returning the record for updating teacher information.*/
int teacher::recordno(int t_collid)
{
	fstream file ;
	file.open("TEACHER.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int count=0 ;
	//find the records position in TEACHER.dat data file
	while(file.read((char*)this, sizeof(teacher)))
	{
		count++ ;
		if(t_collid==coll_id)
			break ;
	}
	file.close() ;
	return count ;
}
/*Function for creating a new student.This is a very important function which is used used to create new student with
all the details of the student.This function uses member functions like last_stuid(), add_to_file(),  etc.
The last_stuid() function will create automatically a new student id number after cheaking from the "STUDENT.dat" file.
Here the Student id numbers start from 1 onwards if it is the first record.Also in this function the validation cheaking
occurs to the name, father's name, address, city, state, contact number, code zip, stream and degree.At the time of validation
cheaking the name, father's name, address, city, state, contact number, zip, stream and degree should not blank and sholud not
more than the specified length.*/
void student::new_student(void)
{
	char ch ;
	int i, valid ;
	clrscr() ;
	student stu ;
	shape s ;
	s.box(2, 1, 79, 25, 318) ;
	s.box(25, 2, 54, 4, 219) ;
	gotoxy(65, 2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3, 3) ;
	for(i=1 ;i<=76 ;i++)
		cprintf("") ;
	textbackground(BLACK) ;
	textcolor(BLACK+BLINK) ;
	textbackground(WHITE) ;
	_setcursortype(_NOCURSOR) ;//changes cursor type
	gotoxy(30, 3) ;
	cprintf("STUDENT INFORMATION") ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;
	int d1, m1, y1 ;
	struct date d ;//for extracting system date
	getdate(&d) ;
	d1=d.da_day ;
	m1=d.da_mon ;
	y1=d.da_year ;
	int stu_id,x ;
 //	stu_id=stu.last_stuid() ;
   //	stu_id++ ;
	do
	{
		stu_id=(rand()%99)+0;
		x=found_student(stu_id);
	}while(x==1);
	char stu_name[30], stu_fname[30], stu_add[30], stu_city[30], stu_state[30], stu_zip[30], stu_cont[30], stu_code[30], stu_strm[30], stu_deg[30] ;
	_setcursortype(_NORMALCURSOR) ;
	gotoxy(5, 6) ;
	cout <<"DATE:-"<<d1<<'/'<<m1<<'/'<<y1 ;
	gotoxy(5, 7) ;
	cout <<"STUDENT ID:-"<<stu_id ;
	gotoxy(5, 8) ;
	cout <<"STUDENT NAME:-" ;
	gotoxy(5, 9) ;
	cout <<"FATHERS NAME:-" ;
	gotoxy(5, 10) ;
	cout <<"ADDRESS:-" ;
	gotoxy(5, 11) ;
	cout <<"CITY:-" ;
	gotoxy(5, 12) ;
	cout <<"STATE:-" ;
	gotoxy(5, 13) ;
	cout <<"PIN CODE:-" ;
	gotoxy(5, 14) ;
	cout <<"CONTACT NO:-" ;
	gotoxy(5, 15) ;
	cout <<"NATIONAITY:-" ;
	gotoxy(5, 16) ;
	cout <<"STUDENT BRANCH:-" ;
	gotoxy(5, 17) ;
	cout <<"STUDENT DEGREE:-" ;
	do
		{
			clear(24, 8) ;
			clear(5, 23) ;
			gotoxy(5, 23) ;
			cout <<"ENTER THE NAME OF THE STUDENT" ;
			valid=1 ;
			gotoxy(24, 8) ;
			gets(stu_name) ;
			strupr(stu_name) ;
			if(stu_name[0]=='0')
				return ;
			if(strlen(stu_name)==0 || strlen(stu_name)>20)
			{
				valid=0 ;
				gotoxy(5, 23) ;
				cprintf("NAME SHOULD NOT BE GREATER THAN 20") ;
				getch() ;
			}
		}
		while(!valid) ;
		do
		{
			clear(24, 9) ;
			for(int i=5 ;i<79 ;i++)
			{
				gotoxy(i, 23) ;
				printf(" ") ;
			}
			gotoxy(5, 23) ;
			cout <<"ENTER FATHER'S NAME" ;
			valid=1 ;
			gotoxy(24, 9) ;
			gets(stu_fname) ;
			strupr(stu_fname) ;
			if(stu_fname[0]=='0')
				return ;
			if(strlen(stu_fname)=='0' || strlen(stu_fname)>20)
			{
				valid=0 ;
				gotoxy(5, 23) ;
				cprintf("NAME SHOULD NOT BE GREATER THAN 20") ;
				getch() ;
			}
		}while(!valid) ;
		do
		{
			clear(19, 10) ;
			for(int i=5 ;i<79 ;i++)
			{
				gotoxy(i, 23) ;
				printf(" ") ;
			}
			gotoxy(5, 23) ;
			cout <<"ENTER THE ADDRESS" ;
			valid=1 ;
			gotoxy(19, 10) ;
			gets(stu_add) ;
			strupr(stu_add) ;
			if(stu_add[0]=='0')
				return ;
			if(strlen(stu_add)==0 || strlen(stu_add)>20)
			{
				valid=0 ;
				gotoxy(5, 23) ;
				cprintf("ADDRESS SHOULD NOT BE  GREATER THAN 20") ;
				getch() ;
			}
		}while(!valid) ;
		do
		{
			clear(16, 11) ;
			for(int i=5 ;i<79 ;i++)
			{
				gotoxy(i, 23) ;
				printf(" ") ;
			}
			gotoxy(5, 23) ;
			cout <<"ENTER  CITY NAME" ;
			valid=1 ;
			gotoxy(16, 11) ;
			gets(stu_city) ;
			strupr(stu_city) ;
			if(stu_city[0]=='0')
				return ;
			if(strlen(stu_city)==0 || strlen(stu_city)>20)
			{
				valid=0 ;
				gotoxy(5, 23) ;
				cprintf("CITY NAME SHOULD NOT BE GREATER THAN 20") ;
				getch() ;
			}
		}while(!valid) ;
		do
		{
			clear(17, 12) ;
			for(int i=5 ;i<79 ;i++)
			{
				gotoxy(i, 23) ;
				printf(" ") ;
			}
			gotoxy(5, 23) ;
			cout <<"ENTER  STATE" ;
			valid=1 ;
			gotoxy(17, 12) ;
			gets(stu_state) ;
			strupr(stu_state) ;
			if(stu_state[0]=='0')
				return ;
			if(strlen(stu_state)==0 || strlen(stu_state)>20)
			{
				valid=0 ;
				gotoxy(5, 23) ;
				cprintf("STATE NAME SHOULD NOT BE GREATER THAN 20") ;
				getch() ;
			}
		}while(!valid) ;
		do
		{
			clear(20, 13) ;
			for(int i=5 ;i<79 ;i++)
			{
				gotoxy(i, 23) ;
				printf(" ") ;
			}
			gotoxy(5, 23) ;
			cout <<"ENTER THE PIN CODE" ;
			valid=1 ;
			gotoxy(20, 13) ;
			gets(stu_zip) ;
			if(stu_name[0]=='0')
				return ;
			if(strlen(stu_zip)==0 || strlen(stu_zip)>8)
			{
				valid=0 ;
				gotoxy(5, 23) ;
				cprintf("PINCODE SHOULD NOT BE GREATER THAN 8") ;
				getch() ;
			}
		}while(!valid) ;
		do
		{
			clear(22, 14) ;
			for(int i=5 ;i<79 ;i++)
			{
				gotoxy(i, 23) ;
				printf(" ") ;
			}
			gotoxy(5, 23) ;
			cout <<"ENTER THE CONTACT NO." ;
			valid=1 ;
			gotoxy(22, 14) ;
			gets(stu_cont) ;
			if(stu_cont[0]=='0')
				return ;
			if(strlen(stu_cont)==0 || strlen(stu_cont)>10)
			{
				valid=0 ;
				gotoxy(5, 23) ;
				cprintf("CONTACT NO. SHOULD NOT BE GREATER THAN 10") ;
				getch() ;
			}
		}while(!valid) ;
		do
		{
			clear(20, 15) ;
			for(int i=5 ;i<79 ;i++)
			{
				gotoxy(i, 23) ;
				printf(" ") ;
			}
			gotoxy(5, 23) ;
			cout <<"ENTER THE NATIONALITY" ;
			valid=1 ;
			gotoxy(20, 15) ;
			gets(stu_code) ;
			if(stu_code[0]=='0')
				return ;
			if(strlen(stu_code)==0 || strlen(stu_code)>10)
			{
				valid=0 ;
				gotoxy(5, 23) ;
				cprintf("NATIONALITY SHOULD NOT BE GREATER THAN 10") ;
				getch() ;
			}
		}while(!valid) ;
		do
		{
			clear(26, 16) ;
			for(int i=5 ;i<79 ;i++)
			{
				gotoxy(i, 23) ;
				printf(" ") ;
			}
			gotoxy(5, 23) ;
			cout <<"ENTER THE SUBJECT " ;
			valid=1 ;
			gotoxy(26, 16) ;
			gets(stu_strm) ;
			strupr(stu_strm) ;
			if(stu_strm[0]=='0')
				return ;
			if(strlen(stu_strm)==0 || strlen(stu_strm)>20)
			{
				valid=0 ;
				gotoxy(5, 23) ;
				cprintf("SUBJECT SHOULD NOT BE GREATER THAN 20") ;
				getch() ;
			}
		}while(!valid) ;
		do
		{
			clear(26, 17) ;
			for(int i=5 ;i<79 ;i++)
			{
				gotoxy(i, 23) ;
				printf(" ") ;
			}
			gotoxy(5, 23) ;
			cout <<"ENTER THE DEGREE (B.TECH/B.SC-I/II/III Or M.TECH/M.SC-I/II)" ;
			valid=1 ;
			gotoxy(26, 17) ;
			gets(stu_deg) ;
			strupr(stu_deg) ;
			if(stu_deg[0]=='0')
				return ;
			if(strlen(stu_deg)==0 || strlen(stu_deg)>20)
			{
				valid=0 ;
				gotoxy(5, 23) ;
				cprintf("DEGREE SHOULD NOT BE GREATER THAN 20") ;
				getch() ;
			}
		}while(!valid) ;
		stu.clear(5, 23) ;
		do
		{
			valid=1 ;
			for(int i=5 ;i<79 ;i++)
			{
				gotoxy(i, 23) ;
				printf(" ") ;
			}
			gotoxy(5, 23) ;
			cout <<"DO YOU WANT TO SAVE THE RECORD (Y/N):-" ;
			ch=getche() ;
			if(ch==0)
				return ;
			ch=toupper(ch) ;
		}while(ch!='N'&&ch!='Y') ;
		if(ch=='N')
			return ;
		//append the record to student .dat.
		add_to_file(stu_id, stu_name, stu_fname, stu_add, stu_city, stu_state, stu_zip, stu_cont, stu_code, stu_strm, stu_deg) ;


}
/*This is a function which displays the details of all the Students under the university
with all the detail such as student id,  student name,  student address,  student stream, student degree
etc.Thus the user can look and know the detail of student*/
void student::display_list(void)
{
	clrscr() ;
	int flag ;
	fstream file ;
	gotoxy(25, 1) ;
	cout <<"STUDENT DISPLAY LIST" ;
	gotoxy(25, 2) ;
	cout <<"=====================" ;
	gotoxy(1, 3) ;
	for(int j=1 ;j<=79 ;j++)
		cout <<"=" ;
	gotoxy(1, 5) ;
	cout <<"STUID" ;
	gotoxy(10, 5) ;
	cout <<"NAME" ;
	gotoxy(26, 5) ;
	cout <<"FATHER NAME" ;
	gotoxy(43, 5) ;
	cout <<"ADDRESS" ;
	gotoxy(62, 5) ;
	cout <<"BRANCH" ;
	gotoxy(72, 5) ;
	cout <<"DEGREE" ;
	gotoxy(1, 6) ;
	for(j=1 ;j<=79 ;j++)
		cout <<"=" ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int row=7 ;
	//reads all the record to display on the screen
	while(file.read((char*)this, sizeof(student)))
	{
		flag=0 ;
		delay(2) ;
		gotoxy(1, row) ;
		cout <<stu_id ;
		gotoxy(10, row) ;
		puts(stu_name) ;
		gotoxy(26, row) ;
		puts(stu_fname) ;
		gotoxy(43, row) ;
		puts(stu_add) ;
		gotoxy(63, row) ;
		puts(stu_strm) ;
		gotoxy(73, row) ;
		puts(stu_deg) ;
		row++ ;
		if(row>23)
		{
			flag=1 ;
			row=6 ;
			gotoxy(4, 24) ;
			cout <<"PRESS ANY KEY TO CONTINUE" ;
			getch() ;
			clrscr() ;
		}
	}
	gotoxy(1, row) ;
	for(j=1 ;j<=79 ;j++)
		cout <<"=" ;
	row++ ;
	file.close() ;
	if(!flag)
	{
		gotoxy(4, 24) ;
		cout <<"PRESS ANY KEY TO CONTINUE....." ;
		getch() ;
	}
}
/*This function is used to enquire about the Student.This function ask for the student id
to enquire about and after matching the id it displays the record of the enquired student */
void student::enquiry_student(void)
{
	clrscr() ;
	int t_stuid=0 ;
	student stu ;
	gotoxy(71, 1) ;
	cout <<"<0>=EXIT" ;
	gotoxy(5, 5) ;
	cout <<"ENTER STUDENT ID:" ;
	cin>>t_stuid ;
	if(t_stuid==0)
		return ;
	clrscr() ;
	if(!stu.found_student(t_stuid))
	{
		gotoxy(5, 5) ;
		cout <<"\7 INVALID STUDENT ID" ;
		getch() ;
		return ;
	}
	//Displays the haeading from this function.
	box_for_enquirystudent(t_stuid) ;
	int row=9, flag ;
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			delay(2) ;
			gotoxy(4, row) ;
			puts(stu_state) ;
			gotoxy(14, row) ;
			puts(stu_zip) ;
			gotoxy(25, row) ;
			puts(stu_code) ;
			gotoxy(38, row) ;
			puts(stu_contact) ;
			gotoxy(57, row) ;
			puts(stu_strm) ;
			gotoxy(70, row) ;
			puts(stu_deg) ;
			row++ ;
			if(row>23)
			{
				flag=1 ;
				row=7 ;
				gotoxy(4, 24) ;
				cout <<"PRESS ANY KEY TO CONTINUE:" ;
				getch() ;
				box_for_enquirystudent(t_stuid) ;
			}
		}
	}
	file.close() ;
	if(!flag)
	{
		gotoxy(4, 24) ;
		cout <<"PRESS ANY KEY TO CONTINUE:" ;
		getch() ;
	}
}
/* This function is used to modify the student detail.This function asks for the
student id for which the information is to be modified.Then it asks "Do you want to
Modify (Y/N)".If 'Y' is entered it asks for the user to enter new information.
*/
void student::student_modification(void)
{
	clrscr() ;
	int j ;
	int t, t_stuid ;
	gotoxy(17, 1) ;
	cout <<"<0>=EXIT" ;
	gotoxy(5, 5) ;
	cout <<"ENTER THE STUDENT ID:-" ;
	cin>>t_stuid ;
	if(t_stuid==0)
		return ;
	clrscr() ;
	if(!found_student(t_stuid))
	{
		gotoxy(5, 5) ;
		cout <<"\7 STUDENT NOT FOUND" ;
		getch() ;
		return ;
	}
	gotoxy(71, 1) ;
	cout <<"<0>=EXIT" ;
	textbackground(WHITE) ;
	gotoxy(3, 3) ;
	for(j=1 ;j<=76 ;j++)
		cprintf(" ") ;
	textbackground(BLACK) ;
	textcolor(BLACK+WHITE) ;
	textbackground(WHITE) ;
	gotoxy(30, 3) ;
	cprintf("MODIFY STUDENT DETAIL SCREEN:") ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;
	int d1, m1, y1 ;
	struct date d ;
	getdate(&d) ;
	d1=d.da_day ;
	m1=d.da_mon ;
	y1=d.da_year ;
	gotoxy(4, 2) ;
	cout <<"DATE:"<<d1<<"/"<<m1<<"/"<<y1 ;
	char ch ;
	display(t_stuid) ;
	student stu ;
	do
	{
		stu.clear(5, 13) ;
		gotoxy(5, 13) ;

		cout <<"MODIFY THESE STUDENT DETAILS<Y/N>" ;
		ch=getche() ;
		if(ch=='0')
			return ;
		ch=toupper(ch) ;
	}
	while(ch!='N' && ch!='Y') ;
	if(ch=='N')
		return ;
	int modified=0, valid ;
	char t_name[30], t_fname[30], t_add[30], t_stream[30], t_city[30], t_state[30], t_zip[30], t_code[10], t_contact[30], t_deg[30] ;
	gotoxy(5, 15) ;
	cout <<"NAME:-" ;
	gotoxy(5, 16) ;
	cout <<"FATHER NAME:-" ;
	gotoxy(5, 17) ;
	cout <<"ADDRESS:-" ;
	gotoxy(5, 18) ;
	cout <<"STATE:-" ;
	gotoxy(5, 19) ;
	cout <<"CONTACT-NO.:-" ;
	gotoxy(5, 20) ;
	cout <<"BRANCH:-" ;
	gotoxy(5, 21) ;
	cout <<"DEGREE:-" ;
	do
	{
		stu.clear(17, 15) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER NAME OR PRESS ENTER FOR NO CHANGE" ;
		valid=1 ;
		gotoxy(17, 15) ;
		gets(t_name) ;
		strupr(t_name) ;
		if(t_name[0]=='0')
			return ;
		if(strlen(t_name)>20)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 NAME SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}
	while(!valid) ;
	do
	{	stu.clear(23, 16) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER FATHER NAME OR PRESS ENTER FOR NO CHANGE" ;
		valid=1 ;
		gotoxy(23, 16) ;
		gets(t_fname) ;
		strupr(t_fname) ;
		if(t_fname[0]=='0')
			return ;
		if(strlen(t_fname)>20)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 FATHER NAME SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}
	while(!valid) ;
	do
	{	stu.clear(19, 17) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER ADDRESS OR PRESS ENTER FOR NO CHANGE" ;
		valid=1 ;
		gotoxy(19, 17) ;
		gets(t_add) ;
		strupr(t_add) ;
		if(t_add[0]==-'0')
			return ;
		if(strlen(t_add)>20)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 ADDRESS SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}
	while(!valid) ;
	do
	{	stu.clear(17, 18) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER STATE OR PRESS ENTER FOR NO CHANGE" ;
		valid=1 ;
		gotoxy(17, 18) ;
		gets(t_state) ;
		strupr(t_state) ;
		if(t_state[0]=='0')
			return ;
		if(strlen(t_state)>20)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 STATE SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}
	while(!valid) ;
	do
	{	stu.clear(23, 19) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER CONTACT NO. OR PRESS ENTER FOR NO CHANGE" ;
		valid=1 ;
		gotoxy(23, 19) ;
		gets(t_contact) ;
		strupr(t_contact) ;
		if(t_contact[0]=='0')
			return ;
		if(strlen(t_contact)>10)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 CONTACT NO. SHOULD NOT BE GREATER THAN 10") ;
			getch() ;
		}
	}
	while(!valid) ;
	do
	{
		stu.clear(18, 20) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER SUBJECT OR PRESS ENTER FOR NO CHANGE" ;
		valid=1 ;
		gotoxy(18, 20) ;
		gets(t_stream) ;
		strupr(t_stream) ;
		if(t_stream[0]=='0')
			return ;
		if(strlen(t_stream)>20)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 SUBJECT SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}
	while(!valid) ;
	do
	{
		stu.clear(18, 21) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(1, 23) ;
		cout <<"ENTER DEGREE OR PRESS ENTER FOR NO CHANGE(B.TECH/B.SC-I/II/III OR M.TECH/M.SC-I/II)" ;
		valid=1 ;
		gotoxy(18, 21) ;
		gets(t_deg) ;
		strupr(t_deg) ;
		if(t_deg[0]=='0')
			return ;
		if(strlen(t_deg)>20)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 DEGREE SHOULD NOT BE GREATER THAN 20") ;
			getch() ;
		}
	}while(!valid) ;
	if(strlen(t_deg)>0)
		modified=1 ;
	if(!modified)
		return ;
	for(int i=1 ;i<81 ;i++)
	{
		gotoxy(i, 23) ;
		printf(" ") ;

	}

	for(i=1 ;i<80 ;i++)
	{
		gotoxy(i, 24) ;
		printf(" ") ;
	}
	//clears the screen at 23rd row & from 5th coloum
	stu.clear(5, 23) ;
	do
	{
		gotoxy(5, 23) ;
		cout <<"DO YOU WANT TO SAVE CHANGES (Y/N):-" ;
		ch=getche() ;
		if(ch=='0')
			return ;
		ch=toupper(ch) ;
	}while(ch!='N' && ch!='Y') ;
	if(ch=='N')
		return ;
	//passes the parameter to add in data file
	modify_student(t_stuid, t_name, t_fname, t_add, t_state, t_contact, t_stream, t_deg) ;
	for(i=5 ;i<79 ;i++)
	{
		gotoxy(i, 23) ;
		printf(" ") ;
	}
	gotoxy(5, 23) ;
	cout <<"\7 RECORD MODIFIED" ;
	gotoxy(5, 24) ;
	cout <<"PRESS ANY KEY TO CONTINUE" ;
	getch() ;

}
/*supporting function function for student*/
/*Function for clearing specified row and coloumn. By using this function you can clear
from a specified row and coloumn in your screen. Here the function utillizes
two parrameter for clearing the row and coloumn*/
void student::clear(int col, int row)
{
	for(int j=col ;j<=79 ;j++)
	{
		gotoxy(j, row) ;
		cout <<"" ;
	}
}
/* Function to find a student for display teacher function. This is used to find any account in the
"student.dat"data files, where the file is searched from the first record position and it searches
whether the entred id exit or not. If it exit then the variable found will return a value 1 or
0 as the  parameter*/
int student::found_student(int t_stuid)
{
	fstream file ;
	file.open("student.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int found=0 ;
	//searches the specified record in student.dat data file
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			found=1 ;
			break ;
		}
	}
	file.close() ;
	return found ;
}
/*Function for return name of the student from student.dat.This function is basically used
to return only name student if the student is in the "student.dat"data file.When the name is
returned it may simply display/modify other functions*/
char *student::return_name(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_name[30] ;
	//returns the name to display at screen if found.
	while(file.read((char*)this,  sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_name, stu_name) ;
			break ;
		}
	}
	file.close() ;
	return t_name ;
}
/*int *student::return_id(int t_stuid)
{
	fstream file;
	file.open("STUDENT.dat", ios::in);
	file.seekg(0,ios::beg);
	int x=0;
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
			x=1;
	}
	return x;
} */
/*Function for return name of the student's father from student.dat.This function is basically used
to return only name student's father if the student is in the "student.dat"data file.When the name is
returned it may simply display/modify other functions*/
char *student::return_fname(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_fname[30] ;
	//returns the father name to display at screen if found.
	while(file.read((char*)this,  sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_fname, stu_fname) ;
			break ;
		}
	}
	file.close() ;
	return t_fname ;
}

/*Function to return the address of the student from student.dat .This funcion is basicially
used to return only address of the student if address is in the "student.dat" data files.When
the address  is returned it may simply display/modify other functions */
char *student::return_address(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_address [30] ;
	//return the address to display at screen if found
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_address, stu_add) ;
			break ;
		}
	}
	file.close() ;
	return t_address ;
}
/*Function to return the city of the student from student.dat .This funcion is basicially
used to return only city of the student if city is in the "student.dat" data files.When
the city  is returned it may simply display/modify other functions */
char *student::return_city(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_city [30] ;
	//return the city to display at screen if found
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_city, stu_city) ;
			break ;
		}
	}
	file.close() ;
	return t_city ;
}
/*Function to return the state of the student from student.dat .This funcion is basicially
used to return only state of the student if state is in the "student.dat" data files.When
the state  is returned it may simply display/modify other functions */
char *student::return_state(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_state [30] ;
	//return the state to display at screen if found
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_state, stu_state) ;
			break ;
		}
	}
	file.close() ;
	return t_state ;
}
/*Function to return the zip of  the student from student.dat .This funcion is basicially
used to return only zip of the student if zip is in the "student.dat" data files.When
the zip  is returned it may simply display/modify other functions */
char *student::return_zip(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_zip[30] ;
	//return the zip to display at  screen if found
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_zip, stu_zip) ;
			break ;
		}
	}
	file.close() ;
	return t_zip ;
}

/*Function to return the contact of the student from student.dat .This funcion is basicially
used to return only contact of the student if contact is in the "student.dat" data files.When
the contact  is returned it may simply display/modify other functions */
char *student::return_contact(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_contact [30] ;
	//return the contact to display at screen if found
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_contact, stu_contact) ;
			break ;
		}
	}
	file.close() ;
	return t_contact ;
}
/*Function to return the code of the student from student.dat .This funcion is basicially
used to return only code of the student if code is in the "student.dat" data files.When
the code  is returned it may simply display/modify other functions */
char *student::return_code(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_code [30] ;
	//return the code to display at screen if found
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_code, stu_code) ;
			break ;
		}
	}
	file.close() ;
	return t_code ;
}
/*Function to return the stream of the student from student.dat .This funcion is basicially
used to return only stream of the student if stream is in the "student.dat" data files.When
the stream is returned it ma
y simply display/modify other functions */
char *student::return_stream(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_stream [30] ;
	//return the stream to display at report screen if found
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_stream, stu_strm) ;
			break ;
		}
	}
	file.close() ;
	return t_stream ;
}
/*Function to return the degree of the student from student.dat .This funcion is basicially
used to return only degree of the student if degree is in the "student.dat" data files.When
the degree is returned it may simply display/modify other functions */

char *student::return_degree(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	char t_deg[30] ;
	//return the stream to display at report screen if found
	while(file.read((char*)this, sizeof(student)))
	{
		if(stu_id==t_stuid)
		{
			strcpy(t_deg, stu_deg) ;
			break ;
		}
	}
	file.close() ;
	return t_deg ;
}

/*Function to display student detail. This function displays the student name,
student id, father name, address, contact no., zip,  city,  state.*/
void student::box_for_display(int t_stuid)
{
	int d1, m1, y1 ;
	struct date d ;
	getdate(&d) ;
	d1=d.da_day ;
	m1=d.da_mon ;
	y1=d.da_year ;
	gotoxy(63, 2) ;
	cout <<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1 ;
	gotoxy(4, 2) ;
	cout <<"STUDENT ID:"<<t_stuid ;
	student stu ;
	char t_name[30] ;
	strcpy(t_name, stu.return_name(t_stuid)) ;
	char t_fname[30] ;
	strcpy(t_fname, stu.return_fname(t_stuid)) ;
	char t_add[30] ;
	strcpy(t_add, stu.return_address(t_stuid)) ;
	gotoxy(25, 2) ;
	cout <<t_name ;
	gotoxy(25, 3) ;
	cout <<t_add ;
	gotoxy(25, 4) ;
	cout <<t_fname ;
	gotoxy(4, 5) ;
	cout <<"ENQUIRY FOR STUDENT" ;
	textbackground(WHITE) ;
	textcolor(BLACK) ;
	textbackground(WHITE) ;
	gotoxy(1, 6) ;
	for(int i ;i<=79 ;i++)
		cout <<"=" ;
	gotoxy(4, 7) ;
	cprintf("ADDRESS     CITY     STATE     PIN      CONTACT     CODE    BRANCH     DEGREE") ;
	gotoxy(1, 8) ;
	for(i=1 ;i<=79 ;i++)
		cout <<"=" ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;
}
/*supporting function for student display*/
void student::display(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	//displays the record content  matching with t_stuid from STUDENT.dat data files.
	while(file.read((char *)this, sizeof(student)))
	{
		if(t_stuid==stu_id)
		{
			gotoxy(8, 5) ;
			cout <<"STUDENT ID:-" ;
			gotoxy(8, 6) ;
			cout <<"NAME:-" ;
			puts(stu_name) ;
			gotoxy(8, 7) ;
			cout <<"FATHER NAME:-" ;
			puts(stu_fname) ;
			gotoxy(8, 8) ;
			cout <<"ADDRESS:-" ;
			puts(stu_add) ;
			gotoxy(8, 9) ;
			cout <<"STATE:-" ;
			puts(stu_state) ;
			gotoxy(8, 10) ;
			cout <<"CONTACT:-" ;
			puts(stu_contact) ;
			gotoxy(8, 11) ;
			cout <<"BRANCH:-" ;
			puts(stu_strm) ;
			gotoxy(8, 12) ;
			cout <<"DEGREE:-" ;
			puts(stu_deg) ;
			//break ;
		}
	}
	file.close() ;
}
/*supporting function for student modification */
void student::modify_student(int t_stuid, char t_name[30], char t_fname[30], char t_add[30], char t_state[30], char t_cont[30], char t_str[30], char t_deg[30])
{
	int recno ;
	recno=recordno(t_stuid) ;
	fstream file ;
	//open file STUDENT.dat for overwrite mode
	file.open("STUDENT.dat", ios::out|ios::ate) ;
	strcpy(stu_name, t_name) ;
	strcpy(stu_fname, t_fname) ;
	strcpy(stu_add, t_add) ;
	strcpy(stu_state, t_state) ;
	strcpy(stu_contact, t_cont) ;
	strcpy(stu_strm, t_str) ;
	strcpy(stu_deg, t_deg) ;
	//find the  position in data file
	int position ;
	position=(recno-1)*sizeof(student) ;
	file.seekp(position) ;
	//overwrite the modified record into STUDENT.dat datafile.
	file.write((char *)this, sizeof(student)) ;
	file.close() ;
	return  ;
}
/*supporting function for creating last student id*/
int student:: last_stuid(void)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int count=0 ;
	//find the last id number
	while(file.read((char *)this, sizeof(student)))
		count=stu_id ;
	file.close() ;
	return count ;

}
/* supporting function for add to file for student*/
void student::add_to_file(int t_stuid, char t_name[30], char t_fname[30], char t_add[30], char t_city[30], char t_state[30], char t_zip[30], char t_cont[30], char t_code[30], char t_strm[30], char t_deg[30])
{
	fstream file ;
	stu_id=t_stuid ;
	strcpy(stu_name, t_name) ;
	strcpy(stu_fname, t_fname) ;
	strcpy(stu_add, t_add) ;
	strcpy(stu_city, t_city) ;
	strcpy(stu_state, t_state) ;
	strcpy(stu_zip, t_zip) ;
	strcpy(stu_contact, t_cont) ;
	strcpy(stu_code, t_code) ;
	strcpy(stu_strm, t_strm) ;
	strcpy(stu_deg, t_deg) ;
	//append newm record into STUDENT.dat data file.
	file.open("STUDENT.dat", ios::out|ios::app) ;
	file.write((char *)this, sizeof(student)) ;
	file.close() ;
}
/*supporting function for student enquiry*/
void student::box_for_enquirystudent(int t_stuid)
{
	int d1, m1, y1 ;
	struct date d ;
	getdate(&d) ;
	d1=d.da_day ;
	m1=d.da_mon ;
	y1=d.da_year ;
	gotoxy(63, 2) ;
	cout <<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1 ;
	gotoxy(4, 2) ;
	cout <<"STUDENT ID:"<<t_stuid ;
	student stu ;
	char t_name[30] ;
	strcpy(t_name, stu.return_name(t_stuid)) ;
	char t_add[30] ;
	strcpy(t_add, stu.return_address(t_stuid)) ;
	char t_fname[30] ;
	strcpy(t_fname, stu.return_fname(t_stuid)) ;
	gotoxy(25, 2) ;
	cout <<t_name ;
	gotoxy(25, 3) ;
	cout <<t_fname ;
	gotoxy(25, 3) ;
	cout <<t_add ;
	gotoxy(4, 5) ;
	cout <<"ENQUIRY REPORT OF STUDENT" ;
	textbackground(WHITE) ;
	textcolor(BLACK) ;
	textbackground(WHITE) ;
	gotoxy(1, 6) ;
	for(int i=1 ;i<=79 ;i++)
		cout <<"=" ;
	gotoxy(4, 7) ;
	cprintf("STATE      PIN       NATIONAL        CONTACT           BRANCH         DEGREE") ;
	gotoxy(1, 8) ;
	for(i=1 ;i<=79 ;i++)
		cout <<"=" ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;
}
/*Function for returning the record for updating teacher information.*/
int student::recordno(int t_stuid)
{
	fstream file ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int count=0 ;
	//find the records position in TEACHER.dat data file
	while(file.read((char*)this, sizeof(student)))
	{
		count++ ;
		if(t_stuid==stu_id)
			break ;
	}
	file.close() ;
	return count ;
}
/*This is a important function.This function asks for the student id for the
form entry and after entering the student id it matches the id in "STUDENT.dat"
if id is found it extract information related to that id and displays in the
screen and the writes it in to "FORM.dat" data file*/
void examinfo::exam_formentry()
{
	clrscr() ;
	int t, valid, i, t_stuid ;
	student stu ;
	examinfo einfo ;
	shape s ;
	s.box(2, 1, 79, 25, 218) ;
	s.box(25, 2, 54, 4, 219) ;
	gotoxy(5, 5) ;
	cout <<"ENTER THE STUDENT ID:-" ;
	cin>>t_stuid ;
	if(t_stuid==0)
		return ;
	if(!stu.found_student(t_stuid))
	{
		gotoxy(5, 5) ;
		cout <<"\7 STUDENT NOT FOUND" ;
		getch() ;
		return ;
	}
	gotoxy(65, 2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3, 3) ;
	for(i=1 ;i<=76 ;i++)
	cprintf(" ") ;
	textbackground(BLACK) ;
	textcolor(BLACK+BLINK) ;
	textbackground(WHITE) ;
	gotoxy(30, 3) ;
	cout <<"EXAM ENTRY FORM" ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;
	int d1, m1, y1 ;
	struct date d ;
	getdate(&d) ;
	d1=d.da_day ;
	m1=d.da_mon ;
	y1=d.da_year ;
	int examform_id ;
	char ch ;
	examform_id=einfo.last_examformid() ;
	examform_id++ ;
	gotoxy(5, 6) ;
	cout <<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1 ;
	gotoxy(5, 8) ;
	cout <<"EXAM FORM ID:-"<<examform_id ;
	gotoxy(5, 9) ;
	cout <<"NAME:-" ;
	gotoxy(5, 10) ;
	cout <<"FATHER NAME:-" ;
	gotoxy(5, 11) ;
	cout <<"ADDRESS:-" ;
	gotoxy(5, 12) ;
	cout <<"BRANCH:-" ;
	gotoxy(5, 13) ;
	cout <<"DEGREE:-" ;
	stu.examdisplay(t_stuid, examform_id) ;
}
/* supporting function for add to file for student*/
void examinfo::add_to_file_form(int t_stuid, int t_examformid, char t_name[30], char t_fname[30], char t_add[30], char t_strm[30], char t_deg[30])
{
	fstream file ;
	stu_id=t_stuid ;
	examform_id=t_examformid ;
	strcpy(stu_name, t_name) ;
	strcpy(stu_fname, t_fname) ;
	strcpy(stu_add, t_add) ;
	strcpy(stu_strm, t_strm) ;
	strcpy(stu_deg, t_deg) ;
	//append newm record into STUDENT.dat data file.
	file.open("FORM.dat", ios::out|ios::app) ;
	file.write((char *)this, sizeof(examinfo)) ;
	file.close() ;
}
/*supporting function for creating last student id*/
int examinfo:: last_examformid(void)
{
	fstream file ;
	file.open("FORM.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int count=0 ;
	//find the last id number
	while(file.read((char *)this, sizeof(examinfo)))
		count=examform_id ;
	file.close() ;
	return count ;
}
/*Function for clearing specified row and coloumn. By using this function you can clear
from a specified row and coloumn in your screen. Here the function utillizes
two parrameter for clearing the row and coloumn*/
void examinfo::clear(int col, int row)
{
	for(int j=col ;j<=79 ;j++)
	{
		gotoxy(j, row) ;
		cout <<"" ;
	}
}
/*This is a special function related to form it reads the student incormation
from "STUDENT.dat" and put is on the screen of Exam form entry screen after
matching the id of the student*/
void student::examdisplay(int t_stuid, int t_examformid)
{

	fstream file ;
	examinfo einfo ;
	char tstu_name[30], tstu_fname[30], tstu_add[30], tstu_strm[30], tstu_deg[30] ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	//displays the record content  matching with t_stuid from STUDENT.dat data files.
	while(file.read((char *)this, sizeof(student)))
	{
		if(t_stuid==stu_id)
		{

			gotoxy(16, 9) ;
			puts(stu_name) ;
			strcpy(tstu_name, stu_name) ;
			gotoxy(24, 10) ;
			puts(stu_fname) ;
			strcpy(tstu_fname, stu_fname) ;
			gotoxy(19, 11) ;
			puts(stu_add) ;
			strcpy(tstu_add, stu_add) ;
			gotoxy(18, 12) ;
			puts(stu_strm) ;
			strcpy(tstu_strm, stu_strm) ;
			gotoxy(18, 13) ;
			puts(stu_deg) ;
			strcpy(tstu_deg, stu_deg) ;


		}
	}
	file.close() ;
	char ch ;
	do
	{
		einfo.clear(5, 23) ;
		gotoxy(5, 23) ;
		cout <<"DO YOU WANT TO SAVE THE RECORD (Y/N):-" ;
		ch=getche() ;
		if(ch==0)
			return ;
		ch=toupper(ch) ;
	}while(ch!='N' && ch!='Y') ;
	if(ch=='N')
		return ;
	else
	{
	       einfo.add_to_file_form(t_stuid, t_examformid, tstu_name, tstu_fname, tstu_add, tstu_strm, tstu_deg) ;

	}
}
/*This is a special function because this function displays all the forms that
are being entred and finally displays on the screen*/
void examinfo::display_list(void)
{
	clrscr() ;
	int flag, t_stuid ;
	fstream file ;
	student stu ;
	gotoxy(25, 1) ;
	cout <<"EXAM FORM DISPLAY LIST" ;
	gotoxy(25, 2) ;
	cout <<"========================" ;
	gotoxy(1, 3) ;
	for(int j=1 ;j<=79 ;j++)
		cout <<"=" ;
	gotoxy(2, 5) ;
	cout <<"enter student id:" ;
	cin>>t_stuid ;
	if(!stu.found_student(t_stuid))
	{
		gotoxy(5, 5) ;
		cout <<"\7 STUDENT NOT FOUND" ;
		getch() ;
		return ;
	}
	for(int i=2 ;i<79 ;i++)
	{
		gotoxy(i, 5) ;
		printf(" ") ;
	}

	gotoxy(1, 5) ;
	cout <<"FORM ID" ;
	gotoxy(10, 5) ;
	cout <<"STU ID" ;
	gotoxy(18, 5) ;
	cout <<"NAME" ;
	gotoxy(32, 5) ;
	cout <<"F-NAME" ;
	gotoxy(50, 5) ;
	cout <<"ADDRESS" ;
	gotoxy(68, 5) ;
	cout <<"BRANCH" ;
	gotoxy(75, 5) ;
	cout <<"DEG" ;
	gotoxy(1, 6) ;
	for(j=1 ;j<=79 ;j++)
		cout <<"=" ;
	file.open("FORM.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int row=7 ;
	while(file.read((char*)this, sizeof(examinfo)))
	{
		if(t_stuid==stu_id)
		{
		flag=0 ;
		delay(2) ;
		gotoxy(1, row) ;
		cout <<examform_id ;
		gotoxy(10, row) ;
		cout <<stu_id ;
		gotoxy(18, row) ;
		puts(stu_name) ;
		gotoxy(32, row) ;
		puts(stu_fname) ;
		gotoxy(50, row) ;
		puts(stu_add) ;
		gotoxy(68, row) ;
		puts(stu_strm) ;
		gotoxy(75, row) ;
		puts(stu_deg) ;
		}
		row++ ;
		if(row>23)
		{
			flag=1 ;
			row=6 ;
			gotoxy(4, 23) ;
			cout <<"PRESS ANY KEY TO CONTINUE" ;
			getch() ;
			clrscr() ;
		}
	}
		file.close() ;
	gotoxy(1, row) ;
	for(j=1 ;j<=79 ;j++)
		cout <<"=" ;
	row++ ;
	if(!flag)
	{
		gotoxy(5, 23) ;
		cout <<"PRESS ANY KEY TO CONTINUE" ;
		getch() ;
	}
}
/*This is a special function which is used to enter the examination schedule
which includes starting date,  starting month,  staring year as well as ending
date,  ending month,  ending year*/
void examinfo::exam_scheduleentry(void)
{
	char ch ;
	int i, valid ;
	clrscr() ;
	examinfo einfo ;
	shape s ;
	s.box(2, 1, 79, 25, 318) ;
	s.box(25, 2, 54, 4, 219) ;
	gotoxy(65, 2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3, 3) ;
	for(i=1 ;i<=76 ;i++)
		cprintf("") ;
	textbackground(BLACK) ;
	textcolor(BLACK+BLINK) ;
	textbackground(WHITE) ;
	gotoxy(30, 3) ;
	cprintf("EXAM SCHEDULE ENTRY") ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;
	int d1, m1, y1 ;
	struct date d ;
	getdate(&d) ;
	d1=d.da_day ;
	m1=d.da_mon ;
	y1=d.da_year ;
	char deg[30] ;
	char sd1[30], ed1[30], sm1[30], em1[30], sy1[30], ey1[30] ;
	gotoxy(5, 6) ;
	cout <<"DATE:"<<d1<<"/"<<m1<<"/"<<y1 ;
	gotoxy(5, 8) ;
	cout <<"DEGREE:-" ;
	gotoxy(5, 10) ;
	cout <<"STARTING DATE:-" ;
	gotoxy(5, 12) ;
	cout <<"ENDING DATE:-" ;
	gotoxy(5, 14) ;
	cout <<"STARTING MONTH:-" ;
	gotoxy(5, 16) ;
	cout <<"ENDING MONTH:-" ;
	gotoxy(5, 18) ;
	cout <<"STARTING YEAR:-" ;
	gotoxy(5, 20) ;
	cout <<"ENDING YEAR:-" ;
	do
	{
		einfo.clear(18, 8) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER DEGREE" ;
		valid=1 ;
		gotoxy(18, 8) ;
		gets(deg) ;
		strupr(deg) ;
		if(deg[0]=='0')
			return ;
		if(strlen(deg)==0||strlen(deg)>30)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 DEGREE SHOULD NOT BE GREATER THAN 30") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		einfo.clear(25, 10) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER STARTING DATE" ;
		valid=1 ;
		gotoxy(25, 10) ;
		gets(sd1) ;
		strupr(sd1) ;
		if(sd1[0]=='0')
			return ;
		if(strlen(sd1)==0||strlen(sd1)>30)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 STARTING DATE SHOULD NOT BE GREATER THAN 30") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		einfo.clear(23, 12) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER ENDING DATE" ;
		valid=1 ;
		gotoxy(23, 12) ;
		gets(ed1) ;
		strupr(ed1) ;
		if(ed1[0]=='0')
			return ;
		if(strlen(ed1)==0||strlen(ed1)>30)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 ENDING DATE SHOULD NOT BE GREATER THAN 30") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		einfo.clear(24, 14) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER STARTING MONTH" ;
		valid=1 ;
		gotoxy(24, 14) ;
		gets(sm1) ;
		strupr(sm1) ;
		if(sm1[0]=='0')
			return ;
		if(strlen(sm1)==0||strlen(sd1)>30)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 STARTING MONTH SHOULD NOT BE GREATER THAN 30") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		einfo.clear(24, 16) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER ENDING MONTH" ;
		valid=1 ;
		gotoxy(24, 16) ;
		gets(em1) ;
		strupr(em1) ;
		if(em1[0]=='0')
			return ;
		if(strlen(em1)==0||strlen(em1)>30)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 ENDING MONTH SHOULD NOT BE GREATER THAN 30") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		einfo.clear(25, 18) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER STARTING YEAR" ;
		valid=1 ;
		gotoxy(25, 18) ;
		gets(sy1) ;
		strupr(sy1) ;
		if(sd1[0]=='0')
			return ;
		if(strlen(sy1)==0||strlen(sy1)>30)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 STARTING YEAR SHOULD NOT BE GREATER THAN 30") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		einfo.clear(23, 20) ;
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		gotoxy(5, 23) ;
		cout <<"ENTER ENDING YEAR" ;
		valid=1 ;
		gotoxy(23, 20) ;
		gets(ey1) ;
		strupr(ey1) ;
		if(ey1[0]=='0')
			return ;
		if(strlen(ey1)==0||strlen(ey1)>30)
		{
			valid=0 ;
			gotoxy(5, 23) ;
			cprintf("\7 ENDING YEAR SHOULD NOT BE GREATER THAN 30") ;
			getch() ;
		}
	}while(!valid) ;
	do
	{
		for(int i=5 ;i<79 ;i++)
		{
			gotoxy(i, 23) ;
			printf(" ") ;
		}
		valid=1 ;
		gotoxy(5, 23) ;
		cout <<"DO YOU WANT TO SAVE THE RECORD(Y/N)" ;
		ch=getche() ;
		if(ch==0)
			return ;

		ch=toupper(ch) ;
	}while(ch!='N'&&ch!='Y') ;
	if(ch=='N')
		return ;
	add_to_file_schedule(deg, sd1, ed1, sm1, em1, sy1, ey1) ;
}
/* supporting function for add to file for student*/
void examinfo::add_to_file_schedule(char t_deg[30], char t_sd1[30], char t_ed1[30], char t_sm1[30], char t_em1[30], char t_sy1[30], char t_ey1[30])
{
	fstream file ;
	strcpy(sd1, t_sd1) ;
	strcpy(ed1, t_ed1) ;
	strcpy(sm1, t_sm1) ;
	strcpy(em1, t_em1) ;
	strcpy(sy1, t_sy1) ;
	strcpy(ey1, t_ey1) ;
	strcpy(deg, t_deg) ;
	//append newm record into STUDENT.dat data file.
	file.open("SCHEDULE.dat", ios::out|ios::app) ;
	file.write((char *)this, sizeof(examinfo)) ;
	file.close() ;
}
/*This is a important function the use to display the schedule of the exam
that are going to be conducted in the teachers*/
void examinfo::display_schedulelist(void)
{
	clrscr() ;
	int flag ;
	fstream file ;
	gotoxy(25, 1) ;
	cout <<"EXAM SCHEDULE DISPLAY LIST" ;
	gotoxy(25, 2) ;
	cout <<"===========================" ;
	gotoxy(1, 3) ;
	for(int j=1 ;j<=76 ;j++)
		cout <<"=" ;
	gotoxy(1, 5) ;
	cout <<"DEGREE" ;
	gotoxy(10, 5) ;
	cout <<"START DATE" ;
	gotoxy(20, 5) ;
	cout <<"END DATE" ;
	gotoxy(30, 5) ;
	cout <<"START MONTH" ;
	gotoxy(40, 5) ;
	cout <<"END MONTH" ;
	gotoxy(50, 5) ;
	cout <<"START YEAR" ;
	gotoxy(60, 5) ;
	cout <<"END YEAR" ;
	gotoxy(1, 6) ;
	for(j=1 ;j<=79 ;j++)
		cout <<"=" ;
	file.open("SCHEDULE.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int row=7 ;
	while(file.read((char*)this, sizeof(examinfo)))
	{
		flag=0 ;
		delay(2) ;
		gotoxy(1, row) ;
		puts(deg) ;
		gotoxy(10, row) ;
		puts(sd1) ;
		gotoxy(20, row) ;
		puts(ed1) ;
		gotoxy(30, row) ;
		puts(sm1) ;
		gotoxy(40, row) ;
		puts(em1) ;
		gotoxy(50, row) ;
		puts(sy1) ;
		gotoxy(60, row) ;
		puts(ey1) ;
		row++ ;
		if(row>23)
		{
			flag=1 ;
			row=6 ;
			gotoxy(4, 23) ;
			cout <<"PRESS ANY KEY TO CONTINUE" ;
			getch() ;
			clrscr() ;
		}
	}
	gotoxy(1, row) ;
	for(j=1 ;j<=79 ;j++)
		cout <<"=" ;
	row++ ;
	file.close() ;
	if(!flag)
	{
		gotoxy(5, 23) ;
		cout <<"PRESS ANY KEY TO CONTINUE" ;
		getch() ;
	}
}
/*This is a special function.This funcion is used to enter the marks of the
student.This function first asks for the student id and then it flashes the
student name,  address,  stream,  degree the it asks to enter the marks after comparing
the degree*/
void examinfo::result_entry(void)
{
	char ch ;
	int i, valid, t_stuid, thp1, thp2, thp3, thp4, thp5, thp6, ts1, ts2, tcom, tgk, tp1, tp2, tp3, tp4, tp5, tp6 ;
	clrscr() ;
	char tstu_name[30], tstu_fname[30], tstu_add[30], tstu_strm[30], tstu_deg[30] ;
	shape s ;
	student stu ;
	s.box(2, 1, 79, 25, 218) ;
	s.box(25, 2, 54, 4, 219) ;
	gotoxy(65, 2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(5, 3) ;
	cout <<"ENTER THE STUDENT ID:-" ;
	cin>>t_stuid ;
	if(!stu.found_student(t_stuid))
	{
		gotoxy(5, 4) ;
		cout <<"\7 STUDENT NOT FOUND" ;
		getch() ;
		return ;
	}
	gotoxy(65, 2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3, 3) ;
	for(i=1 ;i<=79 ;i++)
	cprintf("") ;
	textbackground(BLACK) ;
	textcolor(BLACK+BLINK) ;
	textbackground(WHITE) ;
	gotoxy(30, 3) ;
	cprintf("RESULT ENTRY") ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;
	int d1, m1, y1 ;
	struct date d ;
	getdate(&d) ;
	d1=d.da_day ;
	m1=d.da_mon ;
	y1=d.da_year ;
	gotoxy(5, 6) ;
	cout <<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1 ;
	gotoxy(5, 8) ;
	cout <<"NAME:-" ;
	gotoxy(5, 10) ;
	cout <<"DEGREE:-" ;
	gotoxy(5, 12) ;
	cout <<"SUBJECT:-" ;
	stu.resultdisplay(t_stuid) ;
}
void student::resultdisplay(int t_stuid)
{

	fstream file ;
	examinfo einfo ;
	char tstu_name[30], tstu_fname[30], tstu_add[30], tstu_strm[30], tstu_deg[30] ;
	int thp1, thp2, thp3, thp4, thp5, thp6, thp7, thp8, ts1, ts2, tcom, tgk ;
	int tp1, tp2, tp3, tp4, tp5, tp6, tp7, tp8, tp9, tp10, tp11, tp12, tp13, tp14, tp15, tp16 ;
	float cgpa;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	//displays the record content  matching with t_stuid from STUDENT.dat data files.
	while(file.read((char *)this, sizeof(student)))
	{
		if(t_stuid==stu_id)
		{
			gotoxy(16, 8) ;
			puts(stu_name) ;
			strcpy(tstu_name, stu_name) ;
			gotoxy(18, 10) ;
			puts(stu_strm) ;
			strcpy(tstu_strm, stu_strm) ;
			gotoxy(18, 12) ;
			puts(stu_deg) ;
			strcpy(tstu_deg, stu_deg) ;

		}
	}
	file.close() ;
	file.open("STUDENT.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	while(file.read((char*)this, sizeof(student)))
	{
		strcpy(tstu_deg, stu_deg) ;
		if(stu_id==t_stuid)
		{
		if((strcmpi(stu_deg, "B.Tech-I")==0)||(strcmpi(stu_deg, "B.SC-I")==0))
		{
			gotoxy(5, 14) ;
			cout <<"CALCULUS :" ;
			cin>>thp1 ;
			gotoxy(5, 15) ;
			cout <<"PROGRAMMING :" ;
			cin>>thp2 ;
			gotoxy(5, 16) ;
			cout <<"PHYSICS:" ;
			cin>>ts1 ;
			gotoxy(5, 17) ;
			cout <<"CHEMISTRY:" ;
			cin>>ts2 ;
			gotoxy(5, 18) ;
			cout <<"ENGLISH:" ;
			cin>>tcom ;
			cgpa=((float)(thp1+thp2+ts1+ts2+tcom)/50);
			gotoxy(5, 22);
			cout<<"CGPA:"<<(float)cgpa;
		}
		else if((strcmpi(stu_deg, "B.Tech-II")==0)||(strcmpi(stu_deg, "B.SC-II")==0))
		{
			gotoxy(5, 14) ;
			cout <<"DSA :" ;
			cin>>thp3 ;
			gotoxy(5, 15) ;
			cout <<"NETWORKING :" ;
			cin>>thp4 ;
			gotoxy(5, 16) ;
			cout <<"SENSORS:" ;
			cin>>ts1 ;
			gotoxy(5, 17) ;
			cout <<"BEEE:" ;
			cin>>ts2 ;
			gotoxy(5, 18) ;
			cout <<"FRENCH:" ;
			cin>>tcom ;
			cgpa=((float)(thp3+thp4+ts1+ts2+tcom)/50);
			gotoxy(5, 22);
			cout<<"CGPA:"<<(float)cgpa;
		}
		else if((strcmpi(stu_deg, "B.Tech-III")==0)||(strcmpi(stu_deg, "B.SC-III")==0))
		{
			gotoxy(5, 14) ;
			cout <<"SPANISH:" ;
			cin>>thp5 ;
			gotoxy(5, 15) ;
			cout <<"DLD:" ;
			cin>>thp6 ;
			gotoxy(5, 16) ;
			cout <<"COMPILER DESIGN:" ;
			cin>>thp7 ;
			gotoxy(5, 17) ;
			cout <<"DISCRETE M.TECHTHEM.TECHTICS:" ;
			cin>>thp8 ;
			gotoxy(5, 18) ;
			cout <<"GENERAL KNOWLEDGE:" ;
			cin>>tgk ;
			cgpa=((float)(thp5+thp6+thp7+thp8+tgk)/50);
			gotoxy(5, 22);
			cout<<"CGPA:"<<(float)cgpa;
		}
		else if((strcmpi(stu_deg, "M.Tech-I")==0)||(strcmpi(stu_deg, "M.SC-I")==0))
		{
			gotoxy(5, 14) ;
			cout <<"GERM.TECHN:-" ;
			cin>>tp1 ;
			gotoxy(5, 15) ;
			cout <<"APPLIED ALGEBRA:-" ;
			cin>>tp2 ;
			gotoxy(5, 16) ;
			cout <<"ETHICS AND VALUES:-" ;
			cin>>tp3 ;
			gotoxy(5, 17) ;
			cout <<"ARTIFICIAL INTELLIGENCE:-" ;
			cin>>tp4 ;
			gotoxy(5, 18) ;
			cout <<"MECHANICS:-" ;
			cin>>tp5 ;
			gotoxy(5, 19) ;
			cout <<"THERMODYNAMICS:-" ;
			cin>>tp6 ;
			gotoxy(5, 20) ;
			cout <<"OPERATING SYSTEMS:-" ;
			cin>>tp7 ;
			gotoxy(5, 21) ;
			cout <<"INNOVATIVE PROJECTS:-" ;
			cin>>tp8 ;
			cgpa=((float)(tp1+tp2+tp3+tp4+tp5+tp6+tp7+tp8)/50);
			gotoxy(5, 22);
			cout<<"CGPA:"<<(float)cgpa;
		}
		else if((strcmpi(stu_deg, "M.Tech-II")==0)||(strcmpi(stu_deg, "M.SC-II")==0))
		{
			gotoxy(5, 14) ;
			cout <<"CHINESE:-" ;
			cin>>tp9 ;
			gotoxy(5, 15) ;
			cout <<"STATISTICS:-" ;
			cin>>tp10 ;
			gotoxy(5, 16) ;
			cout <<"M.TECHCHINE LEARNING:-" ;
			cin>>tp11 ;
			gotoxy(5, 17) ;
			cout <<"SURFACE ENGINEERING:-" ;
			cin>>tp12 ;
			gotoxy(5, 18) ;
			cout <<"CLOUD COMPUTING:-" ;
			cin>>tp13 ;
			gotoxy(5, 19) ;
			cout <<"NUCLEAR SCIENCES:-" ;
			cin>>tp14 ;
			gotoxy(5, 20) ;
			cout <<"IoT SM.TECHRT SYSTEMS:-" ;
			cin>>tp15 ;
			gotoxy(5, 21) ;
			cout <<"CAPTSTONE PROJECT:-" ;
			cin>>tp16 ;
			cgpa=((float)(tp9+tp10+tp11+tp12+tp13+tp14+tp15+tp16)/50);
			gotoxy(5,22);
			cout<<"CGPA:"<<(float)cgpa;
		}
	    }
	}
	char ch ;
	do
	{
		clear(5, 23) ;
		gotoxy(5, 23) ;
		cout <<"DO YOU WANT TO SAVE THE RECORD (Y/N):-" ;
		ch=getche() ;
		if(ch==0)
			return ;
		ch=toupper(ch) ;
	}while(ch!='N' && ch!='Y') ;
	if(ch=='N')
		return ;
	if(ch=='Y')
	{
		if((strcmp(tstu_deg, "B.TECH-I")==0)||(strcmp(tstu_deg, "B.SC-I")==0))
		{
			einfo.add_to_filebaI(t_stuid, tstu_name, tstu_deg, thp1, thp2, ts1, ts2, tcom) ;
		}
		else if((strcmp(tstu_deg, "B.TECH-II")==0)||(strcmp(tstu_deg, "B.SC-II")==0))
		{
			einfo.add_to_filebaII(t_stuid, tstu_name, tstu_deg, thp3, thp4, ts1, ts2, tcom) ;
		}
		else if((strcmp(tstu_deg, "B.TECH-III")==0)||(strcmp(tstu_deg, "B.SC-III")==0))
		{
			einfo.add_to_filebaIII(t_stuid, tstu_name, tstu_deg, thp5, thp6, thp7, thp8, tgk) ;
		}
		else if((strcmp(tstu_deg, "M.TECH-I")==0)||(strcmp(tstu_deg, "M.SC-I")==0))
		{
			einfo.add_to_filemaI(t_stuid, tstu_name, tstu_deg, tp1, tp2, tp3, tp4, tp5, tp6, tp7, tp8) ;
		}
		else if((strcmp(tstu_deg, "M.TECH-II")==0)||(strcmp(tstu_deg, "M.SC-II")==0))
		{
			einfo.add_to_filemaII(t_stuid, tstu_name, tstu_deg, tp9, tp10, tp11, tp12, tp13, tp14, tp15, tp16) ;
		}
	}
}
//supporting function of result
void examinfo::add_to_filebaI(int t_stuid, char t_name[30], char t_deg[30], int t_hp1, int t_hp2, int t_s1, int t_s2, int t_com)
{
	fstream file ;
	stu_id=t_stuid ;
	hp1=t_hp1 ;
	hp2=t_hp2 ;
	s1=t_s1 ;
	s2=t_s2 ;
	com=t_com ;
	strcpy(stu_name, t_name) ;
	strcpy(stu_deg, t_deg) ;
	//append newm record into STUDENT.dat data file.
	file.open("RESULTF.dat", ios::out|ios::app) ;
	file.write((char *)this, sizeof(examinfo)) ;
	file.close() ;
}
//suporting function of result
void examinfo::add_to_filebaII(int t_stuid, char t_name[30], char t_deg[30], int t_hp3, int t_hp4, int t_s1, int t_s2, int t_com)
{
	fstream file ;
	stu_id=t_stuid ;
	hp3=t_hp3 ;
	hp4=t_hp4 ;
	s1=t_s1 ;
	s2=t_s2 ;
	com=t_com ;
	strcpy(stu_name, t_name) ;
	strcpy(stu_deg, t_deg) ;
	//append newm record into STUDENT.dat data file.
	file.open("RESULTS.dat", ios::out|ios::app) ;
	file.write((char *)this, sizeof(examinfo)) ;
	file.close() ;
}
//suporting function function of result
void examinfo::add_to_filebaIII(int t_stuid, char t_name[30], char t_deg[30], int t_hp5, int t_hp6, int t_hp7, int t_hp8, int t_gk)
{
	fstream file ;
	stu_id=t_stuid ;
	hp5=t_hp5 ;
	hp6=t_hp6 ;
	hp7=t_hp7 ;
	hp8=t_hp8 ;
	gk=t_gk ;
	strcpy(stu_name, t_name) ;
	strcpy(stu_deg, t_deg) ;
	//append newm record into STUDENT.dat data file.
	file.open("RESULTT.dat", ios::out|ios::app) ;
	file.write((char *)this, sizeof(examinfo)) ;
	file.close() ;
}
//suporting fuinction of result
void examinfo::add_to_filemaI(int t_stuid, char t_name[30], char t_deg[30], int t_p1, int t_p2, int t_p3, int t_p4, int t_p5, int t_p6, int t_p7, int t_p8)
{
	fstream file ;
	stu_id=t_stuid ;
	p1=t_p1 ;
	p2=t_p2 ;
	p3=t_p3 ;
	p4=t_p4 ;
	p5=t_p5 ;
	p6=t_p6 ;
	p7=t_p7 ;
	p8=t_p8 ;
	strcpy(stu_name, t_name) ;
	strcpy(stu_deg, t_deg) ;
	//append newm record into STUDENT.dat data file.
	file.open("RESULTMF.dat", ios::out|ios::app) ;
	file.write((char *)this, sizeof(examinfo)) ;
	file.close() ;
}
//suporting function of result
void examinfo::add_to_filemaII(int t_stuid, char t_name[30], char t_deg[30], int t_p9, int t_p10, int t_p11, int t_p12, int t_p13, int t_p14, int t_p15, int t_p16)
{
	fstream file ;
	stu_id=t_stuid ;
	p9=t_p9 ;
	p10=t_p10 ;
	p11=t_p11 ;
	p12=t_p12 ;
	p13=t_p13 ;
	p14=t_p14 ;
	p15=t_p15 ;
	p16=t_p16 ;
	strcpy(stu_name, t_name) ;
	strcpy(stu_deg, t_deg) ;
	//append newm record into STUDENT.dat data file.
	file.open("RESULTMS.dat", ios::out|ios::app) ;
	file.write((char *)this, sizeof(examinfo)) ;
	file.close() ;
}
/*This is a important function it displays the result of the student according
to their degree for different different  result data fiels*/
void examinfo::resultdisplay_list(void)
{
	clrscr() ;
	fstream file ;
	student stu ;
	gotoxy(25, 1) ;
	cout <<"EXAM RESULT DISPLAY LIST" ;
	gotoxy(25, 2) ;
	cout <<"=============================" ;
	int t_stuid ;
	gotoxy(5, 3) ;
	cout <<"enter student id" ;
	cin>>t_stuid ;
	if(!stu.found_student(t_stuid))
	{
		gotoxy(5, 4) ;
		cout <<"\7 invalid" ;
		getch() ;
		return ;
	}
	int d1, m1, y1 ;
	struct date d ;
	getdate(&d) ;
	d1=d.da_day ;
	m1=d.da_mon ;
	y1=d.da_year ;
	gotoxy(62, 3) ;
	cout <<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1 ;
	char t_studeg[30] ;
	strcpy(t_studeg, stu.return_degree(t_stuid)) ;
	if((strcmp(t_studeg, "B.TECH-I")==0) || (strcmp(t_studeg, "B.SC-I")==0))
	{
			gotoxy(1, 4) ;
			for(int j=1 ;j<=79 ;j++)
				cout <<"=" ;
			gotoxy(1, 5) ;
			cout <<"ID" ;
			gotoxy(3, 5) ;
			cout <<"NAME" ;
			gotoxy(34, 5) ;
			cout <<"DEGREE" ;
			gotoxy(48, 5) ;
			cout <<"HONOURS" ;
			gotoxy(40, 6) ;
			cout <<"PAPER I" ;
			gotoxy(50, 6) ;
			cout <<"PAPER II" ;
			gotoxy(65, 5) ;
			cout <<"SUBCIDIARY" ;
			gotoxy(60, 6) ;
			cout <<"PAPER I" ;
			gotoxy(68, 6) ;
			cout <<"PAPER II" ;
			gotoxy(76, 5) ;
			cout <<"COMPULSORY" ;
			gotoxy(1, 7) ;
			for(j=1 ;j<=79 ;j++)
				cout <<"=" ;
	file.open("RESULTF.dat", ios::in) ;
	file.seekg(0, ios::beg) ;
	int row=8 ;
	while(file.read((char*)this, sizeof(examinfo)))
	{

			gotoxy(1, row) ;
			cout <<stu_id ;
			gotoxy(3, row) ;
			puts(stu_name) ;
			gotoxy(34, row) ;
			puts(stu_deg) ;
			gotoxy(40, row) ;
			cout <<hp1 ;
			gotoxy(50, row) ;
			cout <<hp2 ;
			gotoxy(60, row) ;
			cout <<s1 ;
			gotoxy(70, row) ;
			cout <<s2 ;
			gotoxy(72, row) ;
			cout <<com ;
			row++ ;
			if(row>23)
			{
				row=7 ;
				gotoxy(4, 24) ;
				cout <<"PRESS ANY KEY TO CONTINUE..." ;
				getch() ;
				clrscr() ;
			}
			gotoxy(1, row) ;
			for(int j=1 ;j<=79 ;j++)
				cout <<"=" ;

		}
		file.close() ;
	 }
	if((strcmp(t_studeg, "B.TECH-II")==0)||(strcmp(t_studeg, "B.SC-II")==0))
	{
		gotoxy(1, 4) ;
		for(int j=1 ;j<=79 ;j++)
			cout <<"=" ;
		gotoxy(1, 5) ;
		cout <<"ID" ;
		gotoxy(3, 5) ;
		cout <<"NAME" ;
		gotoxy(34, 5) ;
		cout <<"DEGREE" ;
		gotoxy(48, 5) ;
		cout <<"HONOURS" ;
		gotoxy(40, 6) ;
		cout <<"PAPER III" ;
		gotoxy(50, 6) ;
		cout <<"PAPER IV" ;
		gotoxy(65, 5) ;
		cout <<"SUBCIDIARY" ;
		gotoxy(60, 6) ;
		cout <<"PAPER I" ;
		gotoxy(68, 6) ;
		cout <<"PAPER II" ;
		gotoxy(76, 5) ;
		cout <<"COMPULSORY" ;
		gotoxy(1, 7) ;
		for(j=1 ;j<=79 ;j++)
			cout <<"=" ;
		file.open("RESULTS.dat", ios::in) ;
		file.seekg(0, ios::beg) ;
		int row=8 ;
	while(file.read((char*)this, sizeof(examinfo)))
	{
		gotoxy(1, row) ;
		cout <<t_stuid ;
		gotoxy(3, row) ;
		puts(stu_name) ;
		gotoxy(34, row) ;
		puts(stu_deg) ;
		gotoxy(40, row) ;
		cout <<hp3 ;
		gotoxy(50, row) ;
		cout <<hp4 ;
		gotoxy(60, row) ;
		cout <<s1 ;
		gotoxy(70, row) ;
		cout <<s2 ;
		gotoxy(72, row) ;
		cout <<com ;
		row++ ;
		if(row>23)
		{
			row=7 ;
			gotoxy(4, 24) ;
			cout <<"PRESS ANY KEY TO CONTINUE..." ;
			getch() ;
			clrscr() ;
		}
		gotoxy(1, row) ;
		for(int j=1 ;j<=79 ;j++)
			cout <<"=" ;
	   }
		file.close() ;
	}
	if((strcmp(t_studeg, "B.TECH-III")==0)||(strcmp(t_studeg, "B.SC-III")==0))
	{
		gotoxy(1, 4) ;
		for(int j=1 ;j<=79 ;j++)
			cout <<"=" ;
		gotoxy(1, 5) ;
		cout <<"ID" ;
		gotoxy(3, 5) ;
		cout <<"NAME" ;
		gotoxy(34, 5) ;
		cout <<"DEGREE" ;
		gotoxy(53, 5) ;
		cout <<"HONOURS" ;
		gotoxy(40, 6) ;
		cout <<"PAPER V" ;
		gotoxy(50, 6) ;
		cout <<"PAPER VI" ;
		gotoxy(60, 6) ;
		cout <<"PAPER VII" ;
		gotoxy(70, 6) ;
		cout <<"PAPER VIII" ;
		gotoxy(78, 5) ;
		cout <<"G.K" ;
		gotoxy(1, 7) ;
		for(j=1 ;j<=79 ;j++)
			cout <<"=" ;
		file.open("RESULTT.dat", ios::in) ;
		file.seekg(0, ios::beg) ;
		int row=8 ;
		while(file.read((char*)this, sizeof(examinfo)))
		{
			gotoxy(1, row) ;
			cout <<t_stuid ;
			gotoxy(3, row) ;
			puts(stu_name) ;
			gotoxy(34, row) ;
			puts(stu_deg) ;
			gotoxy(40, row) ;
			cout <<hp5 ;
			gotoxy(50, row) ;
			cout <<hp6 ;
			gotoxy(60, row) ;
			cout <<hp7 ;
			gotoxy(70, row) ;
			cout <<hp8 ;
			gotoxy(72, row) ;
			cout <<gk ;
			row++ ;
			if(row>23)
			{
				row=7 ;
				gotoxy(4, 24) ;
				cout <<"PRESS ANY KEY TO CONTINUE..." ;
				getch() ;
				clrscr() ;
			}
			gotoxy(1, row) ;
			for(int j=1 ;j<=79 ;j++)
				cout <<"=" ;
		}
		file.close() ;
	}
	if((strcmp(t_studeg, "M.TECH-I")==0)||(strcmp(t_studeg, "M.SC-I")==0))
	{
		gotoxy(1, 4) ;
		for(int j=1 ;j<=79 ;j++)
			cout <<"=" ;
		gotoxy(1, 5) ;
		cout <<"ID" ;
		gotoxy(3, 5) ;
		cout <<"NAME" ;
		gotoxy(34, 5) ;
		cout <<"DEGREE" ;
		gotoxy(53, 5) ;
		cout <<"M.TECHSTER DEGREE" ;
		gotoxy(40, 6) ;
		cout <<"I" ;
		gotoxy(44, 6) ;
		cout <<"II" ;
		gotoxy(48, 6) ;
		cout <<"III" ;
		gotoxy(52, 6) ;
		cout <<"IV" ;
		gotoxy(56, 6) ;
		cout <<"V" ;
		gotoxy(60, 6) ;
		cout <<"VI" ;
		gotoxy(64, 6) ;
		cout <<"VII" ;
		gotoxy(68, 6) ;
		cout <<"VIII" ;
		gotoxy(1, 7) ;
		for(j=1 ;j<=79 ;j++)
			cout <<"=" ;
		file.open("RESULTMF.dat", ios::in) ;
		file.seekg(0, ios::beg) ;
		int row=8 ;
		while(file.read((char*)this, sizeof(examinfo)))
		{
			gotoxy(1, row) ;
			cout <<t_stuid ;
			gotoxy(3, row) ;
			puts(stu_name) ;
			gotoxy(34, row) ;
			puts(stu_deg) ;
			gotoxy(40, row) ;
			cout <<p1 ;
			gotoxy(44, row) ;
			cout <<p2 ;
			gotoxy(48, row) ;
			cout <<p3 ;
			gotoxy(52, row) ;
			cout <<p4 ;
			gotoxy(56, row) ;
			cout <<p5 ;
			gotoxy(60, row) ;
			cout <<p6 ;
			gotoxy(64, row) ;
			cout <<p7 ;
			gotoxy(68, row) ;
			cout <<p8 ;
			row++ ;
			if(row>23)
			{

				row=7 ;
				gotoxy(4, 24) ;
				cout <<"PRESS ANY KEY TO CONTINUE..." ;
				getch() ;
				clrscr() ;
			}
			gotoxy(1, row) ;
			for(int j=1 ;j<=79 ;j++)
				cout <<"=" ;
		}
	file.close() ;
	}
	if((strcmp(t_studeg, "M.TECH-II")==0)||(strcmp(t_studeg, "M.SC-II")==0))
	{
		gotoxy(1, 4) ;
		for(int j=1 ;j<=79 ;j++)
			cout <<"=" ;
		gotoxy(1, 5) ;
		cout <<"ID" ;
		gotoxy(3, 5) ;
		cout <<"NAME" ;
		gotoxy(34, 5) ;
		cout <<"DEGREE" ;
		gotoxy(53, 5) ;
		cout <<"MASTER DEGREE" ;
		gotoxy(40, 6) ;
		cout <<"IX" ;
		gotoxy(44, 6) ;
		cout <<"X" ;
		gotoxy(48, 6) ;
		cout <<"XI" ;
		gotoxy(52, 6) ;
		cout <<"XII" ;
		gotoxy(56, 6) ;
		cout <<"XIII" ;
		gotoxy(60, 6) ;
		cout <<"XIV" ;
		gotoxy(64, 6) ;
		cout <<"XV" ;
		gotoxy(68, 6) ;
		cout <<"XVI" ;
		gotoxy(1, 7) ;
		for(j=1 ;j<=79 ;j++)
			cout <<"=" ;
		file.open("RESULTMS.dat", ios::in) ;
		file.seekg(0, ios::beg) ;
		int row=8 ;
		while(file.read((char*)this, sizeof(examinfo)))
		{
			gotoxy(1, row) ;
			cout <<t_stuid ;
			gotoxy(3, row) ;
			puts(stu_name) ;
			gotoxy(34, row) ;
			puts(stu_deg) ;
			gotoxy(40, row) ;
			cout <<p9 ;
			gotoxy(44, row) ;
			cout <<p10 ;
			gotoxy(48, row) ;
			cout <<p11 ;
			gotoxy(52, row) ;
			cout <<p12 ;
			gotoxy(56, row) ;
			cout <<p13 ;
			gotoxy(60, row) ;
			cout <<p14 ;
			gotoxy(64, row) ;
			cout <<p15 ;
			gotoxy(68, row) ;
			cout <<p16 ;
			row++ ;
			if(row>23)
			{
				row=7 ;
				gotoxy(4, 24) ;
				cout <<"PRESS ANY KEY TO CONTINUE..." ;
				getch() ;
				clrscr() ;
			}
			gotoxy(1, row) ;
			for(j=1 ;j<=79 ;j++)
				cout <<"=" ;
		}
		file.close() ;
	}
	 getch() ;
}

void performance::foundation(void)
{

	gotoxy(65, 2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(3, 3) ;
	for(int i=1 ;i<=76 ;i++)
		cprintf("") ;
	textbackground(BLACK) ;
	textcolor(BLACK+BLINK) ;
	textbackground(WHITE) ;
	_setcursortype(_NOCURSOR) ;//changes cursor type
	gotoxy(30, 3) ;
	cprintf("FOUNDATION") ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLACK) ;
	int d1, m1, y1 ;
	struct date d ;//for extracting system date
	getdate(&d) ;
	d1=d.da_day ;
	m1=d.da_mon ;
	y1=d.da_year ;
	gotoxy(5, 4) ;
	cout <<"DATE:-"<<d1<<"/"<<m1<<"/"<<y1 ;
	gotoxy(5, 5) ;
	textcolor(GREEN+BLINK) ;
	cout <<"\t \t \t \t OUR VOCATION" ;
	gotoxy(5, 6) ;
	textcolor(GREEN+BLINK) ;
	cout <<"	WE SERVE THE GENEROUS MISSION TO PROVIDE UNBIASED AND" ;
	gotoxy(5, 7) ;
	textcolor(GREEN+BLINK) ;
	cout <<"UNINTERRUPTED EDUCATION AND MOTIVATION TO ALL THOSE YOUNG, BRIGHT " ;
	gotoxy(5, 8) ;
	textcolor(GREEN+BLINK) ;
	cout<<"ASPIRANTS, NOT ONLY IN INDIA BUT TO THOSE ALL AROUND THE WORLD." ;
	gotoxy(5, 9) ;
	textcolor(GREEN+BLINK) ;
	cout <<"THIS PROJECT AIMS TO FULFILL THE ASPIRATIONS OF ALL THOSE WORTHY" ;
	gotoxy(5, 10) ;
	textcolor(GREEN+BLINK) ;
	cout <<"AND DESERVING STUDENTS WIHOUT ANY BIAS WHATSOEVER IN " ;
	gotoxy(5, 11) ;
	textcolor(GREEN+BLINK) ;
	cout <<"TERMS OF RACE, CULTURE OR RELIGION. " ;
	gotoxy(5, 12) ;
	textcolor(GREEN+BLINK) ;
	gotoxy(5, 13) ;
	textcolor(GREEN+BLINK) ;
	cout <<"HERITAGE AND SPORTS" ;
	gotoxy(5, 14);
	cout <<"THE FOUNDATION ALSO MAKES AN EFFORT TO REACH OUT" ;
	gotoxy(5, 15) ;
	textcolor(GREEN+BLINK) ;
	cout <<"TO LIKE-MINDED INDIVIDUALS, AND TO TOGETHER JOIN " ;
	gotoxy(5, 16) ;
	textcolor(GREEN+BLINK) ;
	cout <<"THEM IN THEIR MUCH NEEDED IMPETUS " ;
	gotoxy(5, 17) ;
	textcolor(GREEN+BLINK) ;
	cout <<"TO A FEW GLOBALLY RELATED DEVELOPMENT ISSUES." ;
	gotoxy(5, 21) ;
	textcolor(GREEN+BLINK) ;
	cout <<"GLOBAL LEADERSHIP AND HUMAN DEVELOPMENT AND EXCELLENCE  " ;
	gotoxy(5, 22) ;
	textcolor(GREEN+BLINK) ;
	cout <<"ALL AROUND." ;
}

void main(void)
{

	main_menu ob_menu ;
	int gdriver = DETECT, gmode, errorcode ;
	char pass[10], ch ;

	initgraph(&gdriver, &gmode, "c:\\tc\\bgi") ;

	closegraph() ;
	ob_menu.control_menu() ;

	getch() ;
	closegraph() ;
}
