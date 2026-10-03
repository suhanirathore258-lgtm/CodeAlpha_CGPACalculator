#include <iostream>
#include <iomanip>
using namespace std;

// Convert grade into grade point
double getGradePoint(string grade)
{
    if (grade == "A+")
        return 10;
    else if (grade == "A")
        return 9;
    else if (grade == "B+")
        return 8;
    else if (grade == "B")
        return 7;
    else if (grade == "C+")
        return 6;
    else if (grade == "C")
        return 5;
    else if (grade == "D")
        return 4;
    else if (grade == "F")
        return 0;
    else
        return -1;
}

int main()
{
    int semesters;

    cout << "====================================\n";
    cout << "       RGPV CGPA CALCULATOR\n";
    cout << "====================================\n";

    cout << "Enter number of semesters: ";
    cin >> semesters;

    double totalWeightedSGPA = 0;
    double totalCredits = 0;

    for (int s = 1; s <= semesters; s++)
    {
        int courses;

        cout << "\n----- Semester " << s << " -----\n";
        cout << "Enter number of courses: ";
        cin >> courses;

        double semesterPoints = 0;
        double semesterCredits = 0;

        for (int i = 1; i <= courses; i++)
        {
            string grade;
            double credit;

            cout << "\nCourse " << i << endl;

            cout << "Enter grade (A+/A/B+/B/C+/C/D/F): ";
            cin >> grade;

            double gradePoint = getGradePoint(grade);

            if (gradePoint == -1)
            {
                cout << "Invalid grade entered!\n";
                return 0;
            }

            cout << "Enter credit hours: ";
            cin >> credit;

            semesterPoints += gradePoint * credit;
            semesterCredits += credit;
        }

        double sgpa = semesterPoints / semesterCredits;

        cout << fixed << setprecision(2);
        cout << "\nSGPA of Semester " << s << ": " << sgpa << endl;

        totalWeightedSGPA += sgpa * semesterCredits;
        totalCredits += semesterCredits;
    }

    double cgpa = totalWeightedSGPA / totalCredits;

    cout << "\n====================================\n";
    cout << "             FINAL RESULT\n";
    cout << "====================================\n";

    cout << fixed << setprecision(2);
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Overall CGPA: " << cgpa << endl;

    cout << "====================================\n";

    return 0;
}