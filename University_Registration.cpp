#include <iostream>
#include <fstream>
#include <string>


#pragma warning(disable : 4996)

using namespace std;

string currentAdminid = "";
string currentStudentRegNo = "";
string currentCourseId = "";
string currentAcademicid = "";
string currentManagementid = "";

char admins_Record[] = "Admins_Record.txt";
char managements_Record[] = "Managements_Record.txt";
char academics_Record[] = "Academics_Record.txt";
char students_Record[] = "Students_Record.txt";
char courses_Record[] = "Courses_Record.txt";
char course_Registration_Record[] = "Course_Registration_Record.txt";
char temp_Record[] = "Temp_Record.txt";

class Admin {
public:
    string id;
    string name;
    string password;

};
class Academic {
public:
    string id;
    string name;
    string password;

};
class Management {
public:
    string id;
    string name;
    string password;

};
class Student {
public:
    string regNo;
    int indexNo;
    string name;
    string password;

    //should implement
    bool isValidRegNo() {
        return true;
    }
};
class Course {
public:
    string id;
    string name;
};

void mainInterface();
int academicInterface();
void academicViewAllStudentsInterface();
void academicFindStudentsInterface();
int managementInterface();
void managementViewAllStudentsInterface();
void managementFindStudentsInterface();
int adminInterface();
int adminUserAccountsInterface();
void adminFindAccountsInterface();
void adminViewAllAccountsInterface();
void adminViewAllAdminsInterface();
void adminViewAllAcademicsInterface();
void adminViewAllManagementsInterface();
void adminViewAllStudentsInterface();
void adminCreateAccountsInterface();
void adminModifyAccountsInterface();
void adminDeleteAccountsInterface();
int adminCourseInterface();
void adminFindCourseInterface();
void adminViewAllCoursesInterface();
void adminAddCourseInterface();
void adminModifyCourseInterface();
void adminDeleteCourseInterface();
int studentInterface();
void studentRegisterForCourseInterface();
void studentViewRegisteredCoursesInterface();
void studentFindCoursesInterface();
void studentViewAllCoursesInterface();
void viewDetailsInterface(Admin);
void viewDetailsInterface(Student);
void viewDetailsInterface(Management);
void viewDetailsInterface(Academic);
void viewDetailsInterface(Course);



void close() {
    system("cls");
    cout << endl<<endl<<endl<<endl<<endl<<"\t--- Thanks for using our registration system ---" << endl << endl << endl << endl << endl;
    exit(0);
}
int getChoice(int max) {
    //should check choice is a int or not and choice is in range.
    int choice;
    cout << endl << "Select : ";
    cin >> choice;
    return choice;
}

bool isAdminPresent(string adminId) {
    ifstream inFile(admins_Record);
    string line;
    int flag = 1;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[50];
            strcpy(temp, line.c_str());

            char* ptr;
            ptr = strtok(temp, " |");

            if (adminId == ptr) {
                return true;
                flag = 0;
                break;
            }
        }
    }
    if (flag != 0) {
        return false;
    }
}
bool isStudentPresent(string studentRegNo) {
    ifstream inFile(students_Record);
    string line;
    int flag = 1;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[50];
            strcpy(temp, line.c_str());

            char* ptr;
            ptr = strtok(temp, " |");

            if (studentRegNo == ptr) {
                return true;
                flag = 0;
                break;
            }
        }
    }
    if (flag != 0) {
        return false;
    }
}
bool isAcademicPresent(string academicId) {
    ifstream inFile(academics_Record);
    string line;
    int flag = 1;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[50];
            strcpy(temp, line.c_str());

            char* ptr;
            ptr = strtok(temp, " |");

            if (academicId == ptr) {
                return true;
                flag = 0;
                break;
            }
        }
    }
    if (flag != 0) {
        return false;
    }
}
bool isManagementPresent(string managementId) {
    ifstream inFile(managements_Record);
    string line;
    int flag = 1;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[50];
            strcpy(temp, line.c_str());

            char* ptr;
            ptr = strtok(temp, " |");

            if (managementId == ptr) {
                return true;
                flag = 0;
                break;
            }
        }
    }
    if (flag != 0) {
        return false;
    }
}
bool isCoursePresent(string courseId) {
    ifstream inFile(courses_Record);
    string line;
    int flag = 1;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[50];
            strcpy(temp, line.c_str());

            char* ptr;
            ptr = strtok(temp, " |");

            if (courseId == ptr) {
                return true;
                flag = 0;
                break;
            }
        }
    }
    if (flag != 0) {
        return false;
    }
}

//find function have bugs
int findAdmin(string adminId) {
    ifstream inFile(admins_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[50];
            strcpy(temp, line.c_str());

            char* ptr;
            ptr = strtok(temp, " |");

            if (adminId == ptr) {
                Admin admin;
                admin.id = *ptr;
                ptr = strtok(temp, " |");
                admin.name = *ptr;
                viewDetailsInterface(admin);
                return -1;
                break;
            }
        }
    }
    cout << "No record Found..." << endl;
    system("pause");
    return 0;
}
int findStudent(string studentRegNo) {
    ifstream inFile(students_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[50];
            strcpy(temp, line.c_str());

            char* ptr;
            ptr = strtok(temp, " |");

            if (studentRegNo == ptr) {
                cout << line<<endl;
                return -1;
                break;
            }
        }
    }
    cout << "No record Found..."<<endl;
    system("pause");
    return 0;
}
int findAcademic(string academicId) {
    ifstream inFile(academics_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[50];
            strcpy(temp, line.c_str());

            char* ptr;
            ptr = strtok(temp, " |");

            if (academicId == ptr) {
                cout << line<<endl;
                return -1;
                break;
            }
        }
    }
    cout << "No record Found..."<<endl;
    system("pause");
    return 0;
}
int findManagement(string managementId) {
    ifstream inFile(managements_Record);
    string line;
    
    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[50];
            strcpy(temp, line.c_str());

            char* ptr;
            ptr = strtok(temp, " |");

            if (managementId == ptr) {
                cout << line<<endl;
                return -1;
                break;
            }
        }
    }
    cout << "No record Found..."<<endl;
    
    system("pause");
    return 0;
}
int findCourse(string courseId) {
    ifstream inFile(courses_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[50];
            strcpy(temp, line.c_str());

            char* ptr;
            ptr = strtok(temp, " |");

            if (courseId == ptr) {
                cout << line<<endl;
                return -1;
                break;
            }
        }
    }
    cout << "No record Found..."<<endl;
    system("pause");
    return 0;
}

void create(Admin admin) {

    if (isAdminPresent(admin.id)) {
        cout << "User Already Exists..."<<endl;
    }
    else {
        ofstream outFile(admins_Record,ios_base::app);

        outFile << endl<<admin.id << " | " << admin.name << " | " << admin.password;

        cout << "Admin Created Successfully..." << endl;

        outFile.close();
    
    }
    system("pause");
    
}
void create(Student student) {

    if (isStudentPresent(student.regNo)) {
        cout << "User Already Exists..." << endl;
    }
    else {
        ofstream outFile(students_Record, ios_base::app);

        outFile <<endl<< student.regNo << " | " << student.indexNo << " | " << student.name << " | " << student.password;

        cout << "Student Created Successfully..." << endl;

        outFile.close();

    }
    system("pause");

}
void create(Academic academic) {

    if (isAcademicPresent(academic.id)) {
        cout << "User Already Exists..." << endl;
    }
    else {
        ofstream outFile(academics_Record, ios_base::app);

        outFile << endl << academic.id << " | " << academic.name << " | " << academic.password;

        cout << "Academic Created Successfully..." << endl;

        outFile.close();

    }
    system("pause");

}
void create(Management management) {

    if (isManagementPresent(management.id)) {
        cout << "User Already Exists..." << endl;
    }
    else {
        ofstream outFile(managements_Record, ios_base::app);

        outFile << endl << management.id << " | " << management.name << " | " << management.password;

        cout << "Management Created Successfully..." << endl;

        outFile.close();

    }
    system("pause");

}
void create(Course course) {

    if (isCoursePresent(course.id)) {
        cout << "Course Already Exists..." << endl;
    }
    else {
        ofstream outFile(courses_Record, ios_base::app);

        outFile << endl << course.id << " | " << course.name;

        cout << "Course Created Successfully..." << endl;

        outFile.close();

    }
    system("pause");

}

void updateAdmin(string adminId) {

    bool found = false;

    Admin admin;
    admin.id = adminId;
    cout << "Name     : ";
    cin>>admin.name;
    cout << "Password : ";
    cin >> admin.password;

    ifstream inFile(admins_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[100];
            strcpy(temp, line.c_str());

            char* ptr;

            ptr = strtok(temp, " |");

            if (admin.id==ptr){
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << admin.id << " | " << admin.name << " | " << admin.password;
                outFile.close();
                found = true;
            }
            else {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << line;
                outFile.close();
            }
        }
    }
    inFile.close();

    if (found){
        remove(admins_Record);
        rename(temp_Record, admins_Record);
    }
}
void updateStudent(string studentRegNo) {

    bool found = false;

    Student student;
    student.regNo = studentRegNo;
    cout << "Index No : ";
    cin >> student.indexNo;
    cout << "Name     : ";
    cin >> student.name;
    cout << "Password : ";
    cin >> student.password;

    ifstream inFile(students_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[100];
            strcpy(temp, line.c_str());

            char* ptr;

            ptr = strtok(temp, " |");

            if (student.regNo == ptr) {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << student.regNo << " | " << student.indexNo << " | " << student.name << " | " << student.password;
                outFile.close();
                found = true;
            }
            else {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << line;
                outFile.close();
            }
        }
    }
    inFile.close();

    if (found) {
        remove(students_Record);
        rename(temp_Record, students_Record);
    }
}
void updateAcademic(string academicId) {

    bool found = false;

    Academic academic;
    academic.id = academicId;
    cout << "Name     : ";
    cin >> academic.name;
    cout << "Password : ";
    cin >> academic.password;

    ifstream inFile(academics_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[100];
            strcpy(temp, line.c_str());

            char* ptr;

            ptr = strtok(temp, " |");

            if (academic.id == ptr) {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << academic.id << " | " << academic.name << " | " << academic.password;
                outFile.close();
                found = true;
            }
            else {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << line;
                outFile.close();
            }
        }
    }
    inFile.close();

    if (found) {
        remove(academics_Record);
        rename(temp_Record, academics_Record);
    }}
void updateManagement(string managementId) {

    bool found = false;

    Management management;
    management.id = managementId;
    cout << "Name     : ";
    cin >> management.name;
    cout << "Password : ";
    cin >> management.password;

    ifstream inFile(managements_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[100];
            strcpy(temp, line.c_str());

            char* ptr;

            ptr = strtok(temp, " |");

            if (management.id == ptr) {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << management.id << " | " << management.name << " | " << management.password;
                outFile.close();
                found = true;
            }
            else {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << line;
                outFile.close();
            }
        }
    }
    inFile.close();

    if (found) {
        remove(managements_Record);
        rename(temp_Record, managements_Record);
    }
}
void updateCourse(string courseId) {

    bool found = false;

    Course course;
    course.id = courseId;
    cout << "Name     : ";
    cin >> course.name;

    ifstream inFile(courses_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[100];
            strcpy(temp, line.c_str());

            char* ptr;

            ptr = strtok(temp, " |");

            if (course.id == ptr) {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << course.id << " | " << course.name;
                outFile.close();
                found = true;
            }
            else {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << line;
                outFile.close();
            }
        }
    }
    inFile.close();

    if (found) {
        remove(courses_Record);
        rename(temp_Record, courses_Record);
    }
}

int deleteAdmin(string adminId) {

    bool found = false;
    char c;

    cout << "Confirm (Y/N) : ";
    cin >> c;

    if (!(c == 'Y' || c == 'y')) {
        cout << "Cancelled..."<<endl;
        return -1;
    }

    ifstream inFile(admins_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[100];
            strcpy(temp, line.c_str());

            char* ptr;

            ptr = strtok(temp, " |");

            if (adminId == ptr) {
                found = true;
            }
            else {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << line;
                outFile.close();
            }
        }
    }
    inFile.close();

    if (found) {
        remove(admins_Record);
        rename(temp_Record, admins_Record);
    }
    cout << "Deleted Successfully..." << endl;
    return 0;
}
int deleteStudent(string studentRegNo) {

    bool found = false;
    char c;
    cout << "Confirm (Y/N) : ";
    cin >> c;

    if (!(c == 'Y' || c == 'y')) {
        cout << "Cancelled..." << endl;
        return -1;
    }


    ifstream inFile(students_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[100];
            strcpy(temp, line.c_str());

            char* ptr;

            ptr = strtok(temp, " |");

            if (studentRegNo == ptr) {
                found = true;
            }
            else {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << line;
                outFile.close();
            }
        }
    }
    inFile.close();

    if (found) {
        remove(students_Record);
        rename(temp_Record, students_Record);
    }
    cout << "Deleted Successfully..." << endl;
    return 0;
}
int deleteAcademic(string academicId) {

    bool found = false;
    char c;

    cout << "Confirm (Y/N) : ";
    cin >> c;

    if (!(c == 'Y' || c == 'y')) {
        cout << "Cancelled..." << endl;
        return -1;
    }
    ifstream inFile(academics_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[100];
            strcpy(temp, line.c_str());

            char* ptr;

            ptr = strtok(temp, " |");

            if (academicId == ptr) {
                found = true;
            }
            else {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << line;
                outFile.close();
            }
        }
    }
    inFile.close();

    if (found) {
        remove(academics_Record);
        rename(temp_Record, academics_Record);
    }
    cout << "Deleted Successfully..." << endl;
    return 0;
}
int deleteManagement(string managementId) {

    bool found = false;
    char c;

    cout << "Confirm (Y/N) : ";
    cin >> c;

    if (!(c == 'Y' || c == 'y')) {
        cout << "Cancelled..." << endl;
        return -1;
    }
    ifstream inFile(managements_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[100];
            strcpy(temp, line.c_str());

            char* ptr;

            ptr = strtok(temp, " |");

            if (managementId == ptr) {
                found = true;
            }
            else {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << line;
                outFile.close();
            }
        }
    }
    inFile.close();

    if (found) {
        remove(managements_Record);
        rename(temp_Record, managements_Record);
    }
    cout << "Deleted Successfully..." << endl;
    return 0;
}
int deleteCourse(string courseId) {

    bool found = false;
    char c;
    cout << "Confirm (Y/N) : ";
    cin >> c;

    if (!(c == 'Y' || c == 'y')) {
        cout << "Cancelled..." << endl;
        return -1;
    }
    ifstream inFile(courses_Record);
    string line;

    while (getline(inFile, line)) {
        if (line.length() > 0) {
            char temp[100];
            strcpy(temp, line.c_str());

            char* ptr;

            ptr = strtok(temp, " |");

            if (courseId == ptr) {
                found = true;
            }
            else {
                ofstream outFile(temp_Record, ios_base::app);
                outFile << endl << line;
                outFile.close();
            }
        }
    }
    inFile.close();

    if (found) {
        remove(courses_Record);
        rename(temp_Record, courses_Record);
    }
    cout << "Deleted Successfully..." << endl;
    return 0;
}

void viewAllStudents() {
    ifstream inFile(students_Record);
    string line;

    if (!inFile) {
        cout << "No records found..." << endl;
    }
    else {
        while (getline(inFile, line)) {
            if (line.length() > 0) {
                cout << endl << "\t" << line;
            }
        }
    }
    inFile.close();
    cout << endl << endl;
    system("pause");
}
void viewAllAdmins() {
    ifstream inFile(admins_Record);
    string line;

    if (!inFile) {
        cout << "No records found..." << endl;
    }
    else {
        while (getline(inFile, line)) {
            if (line.length() > 0) {
                cout << endl << "\t" << line;
            }
        }
    }
    inFile.close();
    cout << endl<<endl;
    system("pause");
}
void viewAllAcademics() {
    ifstream inFile(academics_Record);
    string line;

    if (!inFile) {
        cout << "No records found..." << endl;
    }
    else {
        while (getline(inFile, line)) {
            if (line.length() > 0) {
                cout << endl << "\t" << line;
            }
        }
    }
    inFile.close();
    cout << endl << endl;
    system("pause");
}
void viewAllManagements() {
    ifstream inFile(managements_Record);
    string line;

    if (!inFile) {
        cout << "No records found..." << endl;
    }
    else {
        while (getline(inFile, line)) {
            if (line.length() > 0) {
                cout << endl << "\t" << line;
            }
        }
    }
    inFile.close();
    cout << endl << endl;
    system("pause");
}
void viewAllCourses() {
    ifstream inFile(courses_Record);
    string line;

    if (!inFile) {
        cout << "No records found..." << endl;
    }
    else {
        while (getline(inFile, line)) {
            if (line.length() > 0) {
                cout << endl << "\t" << line;
            }
        }
    }
    inFile.close();
    cout << endl << endl;
    system("pause");
}


void mainInterface() {
    system("cls");
    cout << "\t--- Log in ---" << endl
        << "1.Student" << endl
        << "2.Academic Staff" << endl
        << "3.Management Staff" << endl
        << "4.Administrator" << endl
        << "0.Exit" << endl;

    switch (getChoice(4)) {
    case 1:
        studentInterface();
        break;
    case 2:
        academicInterface();
        break;
    case 3:
        managementInterface();
        break;
    case 4:
        adminInterface();
        break;
    case 0:
        close();
        break;

    }
}

int academicInterface() {
    system("cls");
    cout << "\t--- Home ---" << endl
        << "1.View all students" << endl
        << "2.Find a student" << endl
        << "9.Back" << endl
        << "0.Exit" << endl;

    switch (getChoice(2)) {
        case 1:
            academicViewAllStudentsInterface();
            break;
        case 2:
            academicFindStudentsInterface();
            break;
        case 9:
            mainInterface();
            return -1;
            break;
        case 0:
            close();
            break;
    }
    academicInterface();
    return 0;
}
void academicViewAllStudentsInterface() {
    system("cls");
    cout << "\t--- View All Students ---" << endl << endl
        << "Home/View All Students" << endl << endl;

    viewAllStudents();
}
void academicFindStudentsInterface() {
    system("cls");
    cout << "\t--- Find Students ---" << endl << endl
        << "Home/Find Students" << endl << endl;

    Student student;
    cout << "Enter Reg No : ";
    cin >> student.regNo;
    findStudent(student.regNo);
}

int managementInterface() {
    system("cls");
    cout << "\t--- Home ---" << endl
        << "1.View all students" << endl
        << "2.Find a student" << endl
        << "9.Back" << endl
        << "0.Exit" << endl;

    switch (getChoice(2)) {
    case 1:
        managementViewAllStudentsInterface();
        break;
    case 2:
        managementFindStudentsInterface();
        break;
    case 9:
        mainInterface();
        return -1;
        break;
    case 0:
        close();
        break;
    }
    managementInterface();
    return 0;
}
void managementViewAllStudentsInterface() {
    system("cls");
    cout << "\t--- View All Students ---" << endl << endl
        << "Home/View All Students" << endl << endl;

    viewAllStudents();
}
void managementFindStudentsInterface() {
    system("cls");
    cout << "\t--- Find Students ---" << endl << endl
        << "Home/Find Students" << endl << endl;

    Student student;
    cout << "Enter Reg No : ";
    cin >> student.regNo;
    findStudent(student.regNo);
}

int adminInterface() {
    system("cls");
    cout << "\t--- Home ---" << endl
        << "1.User accounts" << endl
        << "2.Courses" << endl
        << "9.Back" << endl
        << "0.Exit" << endl;

    switch (getChoice(2)) {
    case 1:
        adminUserAccountsInterface();
        break;
    case 2:
        adminCourseInterface();
        break;
    case 9:
        mainInterface();
        return -1;
        break;
    case 0:
        close();
        break;

    }
    adminInterface();
    return 0;
}
int adminUserAccountsInterface() {
    system("cls");
    cout << "\t--- User Accounts ---" << endl << endl
        << "Home/User Accounts" << endl << endl
        << "1.Find Accounts" << endl
        << "2.View all Accounts" << endl
        << "3.Create Accounts" << endl
        << "4.Modify Accounts" << endl
        << "5.Delete Accounts" << endl
        << "9.Back" << endl
        << "0.Exit" << endl;

    switch (getChoice(5)) {
    case 1:
        adminFindAccountsInterface();
        break;
    case 2:
        adminViewAllAccountsInterface();
        break;
    case 3:
        adminCreateAccountsInterface();
        break;
    case 4:
        adminModifyAccountsInterface();
        break;
    case 5:
        adminDeleteAccountsInterface();
        break;
    case 9:
        adminInterface();
        return -1;
        break;
    case 0:
        close();
        break;
    }
    adminUserAccountsInterface();
    return 0;
}
void adminFindAccountsInterface() {
    system("cls");
    cout << "\t--- Find Accounts ---" << endl << endl
        << "Home/User Accounts/Find Accounts" << endl << endl
        << "User type" << endl
        << "\t1.Administrator" << endl
        << "\t2.Student" << endl
        << "\t3.Academic Staff" << endl
        << "\t4.Management Staff" << endl;

    switch (getChoice(4)) {
    case 1: {
        Admin admin;
        cout << "Admin id : ";
        cin >> admin.id;
        findAdmin(admin.id);
        break;
    }
    case 2: {
        Student student;
        cout << "Reg No : ";
        cin >> student.regNo;
        findStudent(student.regNo);
        break;
    }
    case 3: {
        Academic academic;
        cout << "Academic id : ";
        cin >> academic.id;
        findAcademic(academic.id);
        break;
    }
    case 4: {
        Management management;
        cout << "Management id : ";
        cin >> management.id;
        findManagement(management.id);
        break;
    }

    }
}
void adminViewAllAccountsInterface() {
    system("cls");
    cout << "\t--- View All Accounts ---" << endl << endl
        << "Home/User Accounts/View All Accounts" << endl << endl
        << "User type" << endl
        << "\t1.Administrator" << endl
        << "\t2.Student" << endl
        << "\t3.Academic Staff" << endl
        << "\t4.Management Staff" << endl;

    switch (getChoice(4)) {
        case 1:
            adminViewAllAdminsInterface();
            break;
        case 2:
            adminViewAllStudentsInterface();
            break;
        case 3:
            adminViewAllAcademicsInterface();
            break;
        case 4:
            adminViewAllManagementsInterface();
            break;
    }

}
void adminViewAllStudentsInterface() {
    system("cls");
    cout << "\t--- View All Students ---" << endl << endl
        << "Home/User Accounts/View All Accounts/View All Students" << endl << endl;

    viewAllStudents();
}
void adminViewAllAdminsInterface() {
    system("cls");
    cout << "\t--- View All Admins ---" << endl << endl
        << "Home/User Accounts/View All Accounts/View All Admins" << endl << endl;

    viewAllAdmins();
}
void adminViewAllAcademicsInterface() {
    system("cls");
    cout << "\t--- View All Academics ---" << endl << endl
        << "Home/User Accounts/View All Accounts/View All Academics" << endl << endl;

    viewAllAcademics();

}
void adminViewAllManagementsInterface() {
    system("cls");
    cout << "\t--- View All Managements ---" << endl << endl
        << "Home/User Accounts/View All Accounts/View All Managements" << endl << endl;

    viewAllManagements();

}
void adminCreateAccountsInterface() {
    system("cls");
    cout << "\t--- Create Accounts ---" << endl << endl
        << "Home/User Accounts/Create Accounts" << endl << endl
        << "User type" << endl
        << "\t1.Administrator" << endl
        << "\t2.Student" << endl
        << "\t3.Academic Staff" << endl
        << "\t4.Management Staff" << endl;

    switch (getChoice(4)) {
    case 1: {
        Admin admin;
        cout << "Admin id : ";
        cin >> admin.id;//check id
        cout << "Name     : ";
        cin >> admin.name;
        cout << "Password : ";
        cin >> admin.password;//check pass

        create(admin);
        break;
    }
    case 2: {
        Student student;
        cout << "Reg No   : ";
        cin >> student.regNo;//check reg no
        cout << "Name     : ";
        cin >> student.name;
        cout << "Index No :";
        cin >> student.indexNo;//check index

        student.password = student.regNo;

        create(student);
        break;
    }
    case 3: {
        Academic academic;
        cout << "Academic id : ";
        cin >> academic.id;
        cout << "Name     : ";
        cin >> academic.name;

        academic.password = academic.id;

        create(academic);
        break;
    }
    case 4: {
        Management management;
        cout << "Management id : ";
        cin >> management.id;
        cout << "Name     : ";
        cin >> management.name;

        management.password = management.name;

        create(management);
        break;
    }

    }
}
void adminModifyAccountsInterface() {
    system("cls");
    cout << "\t--- Modify Accounts ---" << endl << endl
        << "Home/User Accounts/Modify Accounts" << endl << endl
        << "User type" << endl
        << "\t1.Administrator" << endl
        << "\t2.Student" << endl
        << "\t3.Academic Staff" << endl
        << "\t4.Management Staff" << endl;

    switch (getChoice(4)) {
    case 1: {
        Admin admin;
        cout << "Admin id : ";
        cin >> admin.id;
        
        if (isAdminPresent(admin.id)) {
            updateAdmin(admin.id);
            cout << "Updated Successfully..." << endl;
        }
        else {
            cout << "No admin found"<<endl;
        }
        break;
    }
    case 2: {
        Student student;
        cout << "Reg No : ";
        cin >> student.regNo;
        
        if (isStudentPresent(student.regNo)) {
            updateStudent(student.regNo);
            cout << "Updated Successfully..." << endl;
        }
        else {
            cout << "No student found"<<endl;
        }
        break;
    }
    case 3: {
        Academic academic;
        cout << "Academic id : ";
        cin >> academic.id;
        
        if (isAcademicPresent(academic.id)) {
            updateAcademic(academic.id);
            cout << "Updated Successfully..." << endl;
        }
        else {
            cout << "No academic found"<<endl;
        }
        break;
    }
    case 4: {
        Management management;
        cout << "Management id : ";
        cin >> management.id;
        
        if (isManagementPresent(management.id)) {
            updateManagement(management.id);
            cout << "Updated Successfully..." << endl;
        }
        else {
            cout << "No management found"<<endl;
        }
        break;
    }

    }
    system("pause");
}
void adminDeleteAccountsInterface() {
    system("cls");
    cout << "\t--- Modify Accounts ---" << endl << endl
        << "Home/User Accounts/Modify Accounts" << endl << endl
        << "User type" << endl
        << "\t1.Administrator" << endl
        << "\t2.Student" << endl
        << "\t3.Academic Staff" << endl
        << "\t4.Management Staff" << endl;

    switch (getChoice(4)) {
    case 1: {
        Admin admin;
        cout << "Admin id : ";
        cin >> admin.id;
        
        if (isAdminPresent(admin.id)) {
            deleteAdmin(admin.id);
        }
        else {
            cout << "No admin found"<<endl;
        }
        break;
    }
    case 2: {
        Student student;
        cout << "Reg No : ";
        cin >> student.regNo;
        
        if (isStudentPresent(student.regNo)) {
            //deleteStudent(student.regNo);
        }
        else {
            cout << "No student found" << endl;;
        }
        break;
    }
    case 3: {
        Academic academic;
        cout << "Academic id : ";
        cin >> academic.id;
        
        if (isAcademicPresent(academic.id)) {
            //deleteAcademic(academic.id);
        }
        else {
            cout << "No academic found" << endl;;
        }
        
        break;
    }
    case 4: {
        Management management;
        cout << "Management id : ";
        cin >> management.id;
        
        if (isManagementPresent(management.id)) {
            //deleteManagement(management.id);
        }
        else {
            cout << "No management found" << endl;;
        }
        
        break;
    }

    }
    system("pause");
}
int adminCourseInterface() {
    system("cls");
    cout << "\t--- Courses ---" << endl << endl
        << "Home/Courses" << endl << endl
        << "1.Find a Course" << endl
        << "2.View All Courses" << endl
        << "3.Add Courses" << endl
        << "4.Modify Courses" << endl
        << "5.Delete Courses" << endl
        << "9.Back" << endl
        << "0.Exit" << endl;

    switch (getChoice(5)) {
    case 1:
        adminFindCourseInterface();
        break;
    case 2:
        adminViewAllCoursesInterface();
        break;
    case 3:
        adminAddCourseInterface();
        break;
    case 4:
        adminModifyCourseInterface();
        break;
    case 5:
        adminDeleteCourseInterface();
        break;
    case 9:
        adminInterface();
        return -1;
        break;
    case 0:
        close();
        break;
    }
    adminCourseInterface();
    return 0;
}
void adminFindCourseInterface() {
    system("cls");
    cout << "\t--- Find Courses ---" << endl << endl
        << "Home/Courses/Find Courses" << endl << endl;
    
    Course course;
    cout << "Enter Course Id : ";
    cin >> course.id;
    findCourse(course.id);
}
void adminViewAllCoursesInterface() {
    system("cls");
    cout << "\t--- View All Courses ---" << endl << endl
        << "Home/Courses/View All Courses" << endl << endl;

    viewAllCourses();

}
void adminAddCourseInterface() {
    system("cls");
    cout << "\t--- Add Courses ---" << endl << endl
        << "Home/Courses/Add Courses" << endl << endl;

    Course course;
    cout << "Course Id   : ";
    cin >> course.id;//check id
    cout << "Course Name : ";
    cin >> course.name;

    create(course);

}
void adminModifyCourseInterface() {
    system("cls");
    cout << "\t--- Modify Courses ---" << endl << endl
        << "Home/Courses/Modify Courses" << endl << endl;

    Course course;
    cout << "Course Id   : ";
    cin >> course.id;
    
    if (isCoursePresent(course.id)) {
        //updateCourse(course.id);
    }else{
        cout<<"No course found";
    }

}
void adminDeleteCourseInterface() {
    system("cls");
    cout << "\t--- Delete Courses ---" << endl << endl
        << "Home/Courses/Delete Courses" << endl << endl;

    Course course;
    cout << "Course Id   : ";
    cin >> course.id;
    if (isCoursePresent(course.id)) {
        //deleteCourse(course.id);
    }else{
        cout<<"No course found";
    }

}

int studentInterface() {
    system("cls");
    cout << "\t--- Home ---" << endl
        << "1.Register for a course" << endl
        << "2.View registered courses" << endl
        << "3.Find a course" << endl
        << "4.View all courses" << endl
        << "9.Back" << endl
        << "0.Exit" << endl;
    
    switch (getChoice(4)) {
        case 1:
            studentRegisterForCourseInterface();
            break;
        case 2:
            studentViewRegisteredCoursesInterface();
            break;
        case 3:
            studentFindCoursesInterface();
            break;
        case 4:
            studentViewAllCoursesInterface();
            break;
        case 9:
            mainInterface();
            return -1;
            break;
        case 0:
            close();
            break;

    }
    studentInterface();
    return 0;
}
void studentRegisterForCourseInterface() {
    system("cls");
    cout << "\t--- Register for Course ---" << endl << endl
        << "Home/Register for Course" << endl << endl;

    Course course;
    cout << "Enter Course Id : ";
    cin >> course.id;
    
    //regCourse(course.id);
    
    //ask for another registration - to implement
}
void studentViewRegisteredCoursesInterface() {
    system("cls");
    cout << "\t--- View Registered Courses ---" << endl << endl
        << "Home/View Registered Courses" << endl << endl;

    //viewRegCourses();
}
void studentFindCoursesInterface() {
    system("cls");
    cout << "\t--- Find Courses ---" << endl << endl
        << "Home/Find Courses" << endl << endl;

    Course course;
    cout << "Enter Course Id : ";
    cin >> course.id;
    findCourse(course.id);
}
void studentViewAllCoursesInterface() {
    system("cls");
    cout << "\t--- View All Courses ---" << endl << endl
        << "Home/View All Courses" << endl << endl;

    viewAllCourses();
}

void viewDetailsInterface(Admin admin) {
    system("cls");
    cout << "\t--- Admin Details --- " << endl << endl;

    cout << "Id   : " << admin.id << endl
        << "Name : " << admin.name << endl;
    system("pause");
}
void viewDetailsInterface(Student student) {
    system("cls");
    cout << "\t--- Admin Details --- " << endl << endl;

    cout << "Reg No   : " << student.regNo << endl
         << "Index No : " << student.indexNo << endl
         << "Name     : " << student.name << endl;
    system("pause");
}
void viewDetailsInterface(Academic academic) {
    system("cls");
    cout << "\t--- Admin Details --- " << endl << endl;

    cout << "Id   : " << academic.id << endl
        << "Name : " << academic.name << endl;
    system("pause");
}
void viewDetailsInterface(Management management) {
    system("cls");
    cout << "\t--- Admin Details --- " << endl << endl;

    cout << "Id   : " << management.id << endl
        << "Name : " << management.name << endl;
    system("pause");
}
void viewDetailsInterface(Course course) {
    system("cls");
    cout << "\t--- Admin Details --- " << endl << endl;

    cout << "Id   : " << course.id << endl
        << "Name : " << course.name << endl;
    system("pause");
}



/*
regCourse(course.id);
viewRegCourses();
*/



int main() {

    mainInterface();

    return 0;
}
