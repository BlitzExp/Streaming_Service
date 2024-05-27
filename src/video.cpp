#include "../include/video.hpp"

video::video(int Id, std::string name, int duration, float grade, std::string gender, std::string status) {
    Id_ = Id;
    name_ = name;
    duration_ = duration;
    grade_ = grade;
    gender_ = gender;
    status_ = status;
};

void video::show() {
    std::string x = "Título: " + name_ + "\n" + "Calificación: " + format(grade_);
    std::cout << x << "\n" << std::endl;
}

void video::showInfo() {
    std::string x = "Título: " + name_ + "\n" + "Id:" + "Duracion: " + std::to_string(duration_) + "\n" +
                    "Género: " + gender_ + "\n" + "Calificación: " + format(grade_) + "\n" +
                    "Status: " + status_;
    std::cout << x << "\n" << std::endl;
}

void video::grading() {
    int grade;
    std::cout << "Usted esta calificando: " << name_ << std::endl;
    std::cout << "Introduzca un valor entre 1 y 5: ";
    std::cin >> grade;
    std::cout << std::endl;
    while (grade > 5 || grade < 1) {
        std::cout << "Calificación inválida, porfavor coloque una entre 1-5: ";
        std::cin >> grade;
        std::cout << std::endl;
    }
    if (grade_ != -1) {
        average(grade);
    } else {
        grade_ = grade;
    }
    std::cout << "Nueva calificación: " << grade_ << std::endl;
}

void video::average(int grade) { grade_ = (grade_ + grade) / 2; }

void video::setId(int Id) { Id_ = Id; }

void video::setname(std::string name) { name_ = name; }

void video::setgender(std::string gender) { gender_ = gender; }

void video::setgrade(int grade) { grade_ = grade; }

void video::setstatus(std::string status) { status_ = status; }

void video::setduration(int duration) { duration_ = duration; }

int video::getId() { return Id_; }

std::string video::getname() { return name_; }

std::string video::getgender() { return gender_; }

float video::getgrade() { return grade_; }

int video::getduration() { return duration_; }

std::string video::getstatus() { return status_; }

std::string video::format(float value) {
    char buffer[50];
    sprintf(buffer, "%.2f", value);
    return std::string(buffer);
}

bool operator>(const video object1, const video object2) {
    if (object1.grade_ > object2.grade_) {
        return true;
    }
    return false;
}
