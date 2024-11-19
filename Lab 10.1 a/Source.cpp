#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Перелік для спеціальності студента
enum Specialization { COMPUTER_SCIENCE, MATHEMATICS, PHYSICS, ENGINEERING, ECONOMICS };

// Структура для зберігання інформації про студента
struct Student {
    string surname;
    unsigned course;
    Specialization specialization;
    union {
        double average;  // Середній бал
        struct {
            int physics;
            int math;
            int informatics;
        } grades;
    } data;
};

// Функція для вводу студентів
void inputStudents(Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter data for student #" << i + 1 << ":\n";
        cout << "Surname: ";
        cin >> students[i].surname;

        cout << "Course (1-5): ";
        cin >> students[i].course;

        int spec;
        cout << "Specialization (0 - Comp. Sci., 1 - Math, 2 - Physics, 3 - Eng., 4 - Econ.): ";
        cin >> spec;
        students[i].specialization = (Specialization)spec; // Заміна static_cast

        cout << "Physics grade: ";
        cin >> students[i].data.grades.physics;
        cout << "Math grade: ";
        cin >> students[i].data.grades.math;
        cout << "Informatics grade: ";
        cin >> students[i].data.grades.informatics;
    }
}

// Функція для підрахунку студентів без трійок
int countExcellentAndGoodStudents(Student* students, int numStudents) {
    int count = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].data.grades.physics > 3 && students[i].data.grades.math > 3 && students[i].data.grades.informatics > 3) {
            count++;
        }
    }
    return count;
}

// Функція для обчислення відсотка студентів з середнім балом меншим за 4
double calculatePercentageBelowFour(Student* students, int numStudents) {
    int countBelowFour = 0;
    for (int i = 0; i < numStudents; i++) {
        double average = (students[i].data.grades.physics + students[i].data.grades.math + students[i].data.grades.informatics) / 3.0;
        if (average < 4.0) {
            countBelowFour++;
        }
    }
    return ((double)countBelowFour / numStudents) * 100; // Заміна static_cast
}

// Функція для відображення студентів у вигляді таблиці
void displayStudentsTable(Student* students, int numStudents) {
    cout << setw(4) << "No" << setw(12) << "Surname" << setw(8) << "Course" << setw(15) << "Specialization"
        << setw(8) << "Physics" << setw(8) << "Math" << setw(12) << "Informatics" << endl;
    cout << string(70, '-') << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << setw(4) << i + 1
            << setw(12) << students[i].surname
            << setw(8) << students[i].course
            << setw(15) << (students[i].specialization == COMPUTER_SCIENCE ? "Comp. Sci." :
                students[i].specialization == MATHEMATICS ? "Math" :
                students[i].specialization == PHYSICS ? "Physics" :
                students[i].specialization == ENGINEERING ? "Engineering" : "Economics")
            << setw(8) << students[i].data.grades.physics
            << setw(8) << students[i].data.grades.math
            << setw(12) << students[i].data.grades.informatics
            << endl;
    }
}

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Динамічний масив студентів
    Student* students = new Student[numStudents];

    // Ввід даних студентів
    inputStudents(students, numStudents);

    // Підрахунок студентів без трійок
    int countNoThrees = countExcellentAndGoodStudents(students, numStudents);
    cout << "Number of students with grades only 'good' or 'excellent': " << countNoThrees << endl;

    // Відсоток студентів з середнім балом меншим за 4
    double percentageBelowFour = calculatePercentageBelowFour(students, numStudents);
    cout << "Percentage of students with an average grade below 4: " << fixed << setprecision(2) << percentageBelowFour << "%" << endl;

    // Виведення даних у вигляді таблиці
    displayStudentsTable(students, numStudents);

    // Звільнення пам'яті
    delete[] students;

    return 0;
}
