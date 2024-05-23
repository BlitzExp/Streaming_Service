#include <iostream>
#include "include/video.hpp"
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num = 0;
    video Shrek = video(23, "Shrek", 95, 5, "Comedy", "Finished");
    video Madmax = video(0, "Mad Max", 125, 3, "Acción", "Finished");
    video Tron = video(0, "Tron", 120, 4.5, "Acción", "Finished");
    vector<video*> movies{&Madmax, &Shrek, &Tron};

    while (num != 5) {
        std::sort(movies.begin(), movies.end(), [](video* a, video* b) { return *a > *b; });
        cout << "¿Cuál película quieres calificar?(Coloca un número)" << endl;
        cout << "1. Shrek" << endl;
        cout << "2. Madmax" << endl;
        cout << "3. Tron" << endl;
        cout << "4. Mostrar películas en orden" << endl;
        cout << "5. Salir" << endl;
        cin >> num;
        cout << endl;
        switch (num) {
            case 1:
                Shrek.grading();
                break;
            case 2:
                Madmax.grading();
                break;
            case 3:
                Tron.grading();
                break;
            case 4:
                for (const auto& movie : movies) {
                    std::cout << movie->getname() << " (Grade: " << movie->getgrade() << ")\n";
                }
            case 5:
                break;
        }
    }
}