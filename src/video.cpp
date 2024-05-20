#include "../include/video.hpp"

video::video(int Id_, std::string name_, int duration_, std::string gender_, std::string status_) {
    Id = Id_;
    name = name_;
    duration = duration_;
    gender = gender_;
    status = status_;
};

void video::show() {
    std::string x = "Título: " + name + "\n" + "Calificación: " + format(grade);
    std::cout << x << "\n" << std::endl;
}

void video::expandedview() {
    std::string x = "Título: " + name + "\n" + "Id:" + "Duracion: " + std::to_string(duration) + "\n" +
                    "Género: " + gender + "\n" + "Calificación: " + format(grade) + "\n" +
                    "Status: " + status;
    std::cout << x << "\n" << std::endl;
}

void video::grading() {
    int grade_;
    std::cout << "Usted esta calificando: " << name << std::endl;
    std::cout << "Introduzca un valor entre 1 y 5: ";
    std::cin >> grade_;
    std::cout << std::endl;
    while (grade_ > 5 || grade_ < 1) {
        std::cout << "Calificación inválida, porfavor coloque una entre 1-5: ";
        std::cin >> grade_;
        std::cout << std::endl;
    }
    if (grade != -1) {
        average(grade_);
    } else {
        grade = grade_;
    }
    std::cout << "Nueva calificación: " << grade << std::endl;
}

void video::average(int grade_) { grade = (grade + grade_) / 2; }

void video::setId(int Id_) { Id = Id_; }

void video::setname(std::string name_) { name = name_; }

void video::setgender(std::string gender_) { gender = gender_; }

void video::setgrade(int grade_) { grade = grade_; }

void video::setstatus(std::string status_) { status = status_; }

void video::setduration(int duration_) { duration = duration_; }

int video::getId() { return Id; }

std::string video::getname() { return name; }

std::string video::getgender() { return gender; }

int video::getgrade() { return grade; }

int video::getduration() { return duration; }

std::string video::getstatus() { return status; }

std::string video::format(float value) {
    char buffer[50];
    sprintf(buffer, "%.2f", value);
    return std::string(buffer);
}