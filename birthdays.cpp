#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Birthday {
    std::string name;
    int day;
    int month;
};

void add_birthday(std::vector<Birthday>& birthdays) 
{
    std::string name;
    int day, month;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter day: ";
    std::cin >> day;
    std::cout << "Enter month: ";
    std::cin >> month;
    birthdays.push_back({ name, day, month });
}

void edit_birthday(std::vector<Birthday>& birthdays) 
{
    std::string name;
    int day, month;
    std::cout << "Enter name to edit: ";
    std::cin >> name;
    auto it = std::find_if(birthdays.begin(), birthdays.end(), [&name](const Birthday& b) { return b.name == name; });
    if (it == birthdays.end()) {
        std::cout << "Name not found\n";
    }
    else {
        std::cout << "Enter new day: ";
        std::cin >> day;
        std::cout << "Enter new month: ";
        std::cin >> month;
        it->day = day;
        it->month = month;
        std::cout << "Birthday updated\n";
    }
}

void search_birthday(const std::vector<Birthday>& birthdays) {
    std::string name;
    std::cout << "Enter name to search: ";
    std::cin >> name;
    auto it = std::find_if(birthdays.begin(), birthdays.end(), [&name](const Birthday& b) { return b.name == name; });
    if (it == birthdays.end()) {
        std::cout << "Name not found\n";
    }
    else {
        std::cout << "Birthday found: " << it->day << "/" << it->month << "\n";
    }
}

void display_monthly_birthdays(const std::vector<Birthday>& birthdays) {
    int month;
    std::cout << "Enter month to display: ";
    std::cin >> month;
    std::cout << "Birthdays in month " << month << ":\n";
    for (const auto& b : birthdays) {
        if (b.month == month) {
            std::cout << b.name << ": " << b.day << "/" << b.month << "\n";
        }
    }
}

void display_birthdays(const std::vector<Birthday>& birthdays) 
 {
    std::cout << "Birthdays:\n";
    for (const auto& b : birthdays) {
        std::cout << b.name << ": " << b.day << "/" << b.month << "\n";
    }
}

int main() {
    std::vector<Birthday> birthdays;
    while (true) {
        std::cout << "Choose an option:\n"
            << "1. Add birthday\n"
            << "2. Edit birthday\n"
            << "3. Search birthday\n"
            << "4. Display monthly birthdays\n"
            << "5. Display all birthdays\n"
            << "6. Exit\n";
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 1:
            add_birthday(birthdays);
            break;
        case 2:
            edit_birthday(birthdays);
            break;
        case 3:
            search_birthday(birthdays);
            break;
        case 4:
            display_monthly_birthdays(birthdays);
            break;
        case 5:
            display_birthdays(birthdays);
            break;
        case 6:
            break;
        }
    }
}
