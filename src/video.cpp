#include "../include/video.hpp"
#include "video.hpp"

video::video(int Id_, std::string name_, float duration_, std::string gender_, float grade_, std::string status_){
    Id=Id_;
    name=name_;
    duration=duration_;
    gender=gender_;
    grade=grade_;
    status=status_;
};

std::string video::show() { 
    std::string x="Título"+name+"\n"+"Calificación"+std::to_string(grade);
    return x;
}

std::string video::expandedview() {
    std::string x=std::to_string(Id)+"\n"+"Título"+name+"\n"+"Id:"+"Duracion"+std::to_string(duration)+"\n"+"Género"+gender+"\n"+"Calificación"+std::to_string(grade)+"\n"+"Status:"+status;
    return x;
}

float video::grading(int grade_) {
    while (grade_>5||grade_<1){
        std::cout<<"Calificación inválida, porfavor coloque una entre 1-5: ";
        std::cin>>grade_;
        std::cout<<std::endl;
    }
    average(grade_);
    return grade;
}

void video::average(int grade_) {
    grade=(grade+grade)/2;
}

void video::setId(int Id_) {Id=Id_;}

void video::setname(std::string name_) {name=name_;}

void video::setgender(std::string gender_) {gender=gender_;}

void video::setgrade(int grade_) {grade=grade_;}

void video::setstatus(std::string status_) {status=status_;}

int video::getId() { return Id; }

std::string video::getname() { return name; }

std::string video::getgender() { return gender; }

int video::getgrade() { return grade; }

std::string video::getstatus() { return status; }