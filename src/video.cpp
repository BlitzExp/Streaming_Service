#include "../include/video.hpp"
#include "video.hpp"

video::video(int Id_, std::string name_, float duration_, std::string gender_, int grade_, std::string status_){
    Id=Id_;
    name=name_;
    duration=duration_;
    gender=gender_;
    grade=grade_;
    status=status_;
};

std::string video::show() { return std::string(); }

std::string video::expandedview() { return std::string(); }

void video::grading() {}

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
