#include <iostream>
#include "include/video.hpp"

using namespace std;

int main() {
    video Shrek = video(23, "Shrek", 95, "Comedy", "Finished");
    video b = video(0, "Mad Max", 125, "Acción", "Finished");
    video c = video(0, "Tron", 120, "Acción", "Finished");

    Shrek.expandedview();
    Shrek.show();
    Shrek.grading();

    // while (1) {
    // }
}