#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "include/video.hpp"
#include "include/serie.hpp"

using namespace std;

void menufilm(vector<video*> movies);
void menuseries(vector<Serie*> series);

int main() {
    int num = 0;
    video Shrek = video(23, "Shrek", 95, 5, "Comedy", "Finished");
    video Madmax = video(26, "Mad Max", 125, 3, "Acción", "Finished");
    video Tron = video(88, "Tron", 120, 3, "Acción", "Finished");
    video GodzillaMinusOne = video(77, "Godzilla Minus One", 124, 3.95, "Acción", "Finished");
    video Immaculate = video(666, "Immaculate", 89, 2.9, "Terror", "Pendiente");

    // Serie Declaration:

    Serie Ep1 = Serie();
    Ep1.setData(3, "Full measure", "Breaking Bad", 1);
    Serie Ep2 = Serie();
    Ep2.setData(2, "Aquí Vamos", "Invencible", 1);
    Serie Ep3 = Serie();
    Ep3.setData(20, "¡Comienza la Batalla de Supervivencia!", "Beyblade: Metal Fusion", 1);

    vector<video*> movies{&Madmax, &Shrek, &Tron, &GodzillaMinusOne, &Immaculate};

    vector<Serie*> series{&Ep1, &Ep2, &Ep3};

    while (num != 9999) {
        cout << "¿Qué quieres ver?" << endl;
        cout << "1. Peliculas" << endl;
        cout << "2. Series" << endl;
        cout << "3. Salir" << endl;
        cin >> num;
        system("clear");
        if (num == 1) {
            menufilm(movies);
        } else if (num == 2) {
            menuseries(series);
        } else if (num == 3) {
            num = 9999;
        }
    }
}

void menufilm(vector<video*> movies) {
    int num = 0;
    while (num != 9999) {
        int x = 0;
        while (num != 9999) {
            cout << "¿Cuál película quieres ver?(Coloca un número)" << endl;
            for (int i = 0; i < movies.size(); i++) {
                std::cout << i + 1 << ". " << movies[i]->getname() << " (Grade: " << movies[i]->getgrade()
                          << ", Gender: " << movies[i]->getgender() << ")\n";
            };
            cout << movies.size() + 1 << ". Filtrar" << endl;
            cout << movies.size() + 2 << ". Salir" << endl;
            cin >> num;
            system("clear");
            if (num == movies.size() + 2) {
                num = 9999;
            } else if (num == movies.size() + 1) {
                while (1) {
                    cout << "¿Cómo quieres que se filtren las películas?" << endl;
                    cout << "1. Por calificación" << endl;
                    cout << "2. Por genéro" << endl;
                    cout << "3. Salir\n" << endl;
                    cin >> num;
                    system("clear");
                    if (num == 1) {
                        std::sort(movies.begin(), movies.end(), [](video* a, video* b) { return *a > *b; });
                        break;
                    } else if (num == 2) {
                        // cosa de filtro
                        std::sort(movies.begin(), movies.end(), [](video* a, video* b) { return *a == *b; });
                        break;
                    } else if (num == 3) {
                        break;
                    } else {
                        cout << "Opción inválida" << endl;
                    }
                }

            } else if (num < movies.size() + 1 && num > 0) {
                while (1) {
                    movies[num - 1]->show();
                    cout << "¿Qué desea hacer?" << endl;
                    cout << "1. Ver más información" << endl;
                    cout << "2. Asignar calificación" << endl;
                    cout << "3. Ver Película" << endl;
                    cout << "4. Ver todas" << endl;
                    cin >> x;
                    system("clear");
                    if (x == 4) {
                        break;
                    } else if (x == 2) {
                        movies[num - 1]->grading();
                    } else if (x == 1) {
                        string trash;
                        movies[num - 1]->showInfo();
                        cout << "Presione cualquier tecla para continuar\n" << endl;
                        cin >> trash;
                        cout << endl;
                        system("clear");
                    } else if (x == 3) {
                        string trash;
                        cout << "Usted esta viendo " << movies[num - 1]->getname() << endl;
                        cout << "\nPresione cualquier tecla para salir\n" << endl;
                        cin >> trash;
                        cout << endl;
                        system("clear");
                    } else {
                        cout << "Opción inválida, intente de nuevo.\n";
                    }
                }
            } else {
                system("clear");
                cout << "Opción Invalida, elija una opción válida porfavor \n" << endl;
            }
        }
    }
}

void menuseries(vector<Serie*> series) {
    int num = 0;
    while (num != 9999) {
        std::sort(series.begin(), series.end(), [](Serie* a, Serie* b) { return *a < *b; });
        cout << "¿Cuál serie quieres ver?(Coloca un número)" << endl;
        for (int i = 0; i < series.size(); i++) {
            std::cout << i + 1 << ". " << series[i]->getepiName() << "( Serie: " << series[i]->getserieName()
                      << " )"
                      << "\n";
        };
        cout << series.size() + 1 << ". Salir" << endl;
        cin >> num;
        system("clear");
        if (num == series.size() + 1) {
            num = 9999;
        } else if (num < series.size() + 1 && num > 0) {
            series[num - 1]->showInfo();
        } else {
            cout << "Opción Invalida, elija una opción válida porfavor \n" << endl;
        }
    }
}
