#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    float gradePoint, credit;
    float totalWeightedPoints = 0, totalCredits = 0, cgpa;

    cout << "Enter number of subjects: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "\nSubject " << i << endl;

        cout << "Enter grade point: ";
        cin >> gradePoint;

        cout << "Enter credit: ";
        cin >> credit;

        if (gradePoint < 0 || credit <= 0) {
            cout << "Invalid input! Grade point must be >= 0 and credit must be > 0.\n";
            return 1;
        }

         totalWeightedPoints += gradePoint * credit;
         totalCredits += credit;
    }

    cgpa = totalWeightedPoints / totalCredits;

    cout << fixed << setprecision(2);
    cout << "\nYour CGPA is: " << cgpa << endl;
}