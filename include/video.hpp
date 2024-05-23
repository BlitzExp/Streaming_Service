#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <iostream>
#include <string>

class video {
public:
    video(int Id, std::string name, int duration, float grade, std::string gender, std::string status);
    void show();          // titulo y calificacion
    void expandedview();  // toda la info
    void grading();       //

    void setId(int Id);
    void setname(std::string name);
    void setgender(std::string gender);
    void setgrade(int grade);
    void setduration(int duration);
    void setstatus(std::string status);

    int getId();
    std::string getname();
    std::string getgender();
    float getgrade();
    int getduration();
    std::string getstatus();

    friend bool operator>(const video object1, const video object2);

private:
    void average(int grade_);
    std::string format(float value_);
    int Id_;
    std::string name_;
    int duration_;
    std::string gender_;
    float grade_ = -1;
    std::string status_;
};

#endif