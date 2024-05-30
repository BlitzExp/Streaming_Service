#include <iostream>
#include <vector>
#include <algorithm>

#include "include/video.hpp"
#include "include/serie.hpp"

using namespace std;

int menufilm(vector<video*> movies);
int menuseries(vector<Serie*> series);

int main() {
    int num = 0;
    video Shrek = video(23, "Shrek", 95, 5, "Comedy", "Finished");
    video Madmax = video(0, "Mad Max", 125, 3, "Acción", "Finished");
    video Tron = video(0, "Tron", 120, 4.5, "Acción", "Finished");

    Serie Ep1 = Serie();
    Ep1.setData(3, "Full measure", "Breaking Bad", 1);
    Serie Ep2 = Serie();
    Ep2.setData(2, "Aquí Vamos", "Invencible", 1);
    Serie Ep3 = Serie();
    Ep3.setData(20, "¡Comienza la Batalla de Supervivencia!", "Beyblade: Metal Fusion", 1);

    vector<video*> movies{&Madmax, &Shrek, &Tron};

    vector<Serie*> series{&Ep1, &Ep2, &Ep3};

    while (num != 9999) {
        cout << "¿Qué quieres ver?" << endl;
        cout << "1. Peliculas" << endl;
        cout << "2. Series" << endl;
        cin >> num;
        cout << endl;
        if (num == 1) {
            num = menufilm(movies);
        } else if (num == 2) {
            num = menuseries(series);
        }
    }
}

int menufilm(vector<video*> movies) {
    int num = 0;
    std::sort(movies.begin(), movies.end(), [](video* a, video* b) { return *a > *b; });
    cout << "¿Cuál película quieres calificar?(Coloca un número)" << endl;
    for (int i = 0; i < movies.size(); i++) {
        std::cout << i + 1 << ". " << movies[i]->getname() << " (Grade: " << movies[i]->getgrade() << " )\n";
    };
    cout << "4. Salir" << endl;
    cin >> num;
    cout << endl;
    if (num == movies.size() + 1) {
        return 9999;
    } else if (num < movies.size() + 1 && num > 0) {
        movies[num - 1]->show();
        movies[num - 1]->showInfo();
        movies[num - 1]->grading();
    } else {
        cout << "Opción Invalida, elija una opción válida porfavor \n" << endl;
    }

    return num;
}

int menuseries(vector<Serie*> series) {
    int num = 0;
    std::sort(series.begin(), series.end(), [](Serie* a, Serie* b) { return *a < *b; });
    cout << "¿Cuál episodio quieres ver?(Coloca un número)" << endl;
    for (int i = 0; i < series.size(); i++) {
        std::cout << i + 1 << ". " << series[i]->getepiName() << "( Serie: " << series[i]->getserieName()
                  << " )"
                  << "\n";
    };
    cout << series.size() + 1 << ". Salir" << endl;
    cin >> num;
    cout << endl;
    if (num == series.size() + 1) {
        return 9999;
    } else if (num < series.size() + 1 && num > 0) {
        series[num - 1]->showInfo();
    } else {
        cout << "Opción Invalida, elija una opción válida porfavor \n" << endl;
    }

    return num;
}
