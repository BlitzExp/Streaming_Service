#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "include/video.hpp"
#include "include/serie.hpp"

using namespace std;

void menufilm(vector<video*> movies);
void menuseries(vector<vector<Serie*>> series);

int main() {
    system("clear");
    int num = 0;
    video Shrek = video(23, "Shrek", 95, 5, "Comedia", "Finished");
    video Madmax = video(26, "Mad Max", 125, 1, "Acción", "Finished");
    video Tron = video(88, "Tron", 120, 3.5, "Acción", "Finished");
    video Immaculate = video(666, "Immaculate", 89, 4, "Terror", "Pendiente");
    video GodzillaMinusOne = video(77, "Godzilla Minus One", 124, 2, "Acción", "Finished");
    vector<video*> movies{&Tron, &Shrek, &GodzillaMinusOne, &Immaculate, &Madmax};

    // Serie Declaration:
    // Jujutsu Kaisen
    Serie JJK1 = Serie();
    JJK1.setData(1, "Ryomen Sukuna", "Anime", "Jujutsu Kaisen", 1, 5);
    Serie JJK2 = Serie();
    JJK2.setData(2, "Por mí", "Anime", "Jujutsu Kaisen", 1, 3);
    Serie JJK3 = Serie();
    JJK3.setData(3, "Chica de acero", "Anime", "Jujutsu Kaisen", 1, 4);
    vector<Serie*> JJK{&JJK1, &JJK2, &JJK3};

    // Arcane
    Serie Arcane1 = Serie();
    Arcane1.setData(1, "Bienvenido", "Accion", "Arcane", 1, 5);
    Serie Arcane2 = Serie();
    Arcane2.setData(2, "Algunos misterios están mejor sin resolver", "Accion", "Arcane", 1, 5);
    Serie Arcane3 = Serie();
    Arcane3.setData(3, "La violencia bruta es necesaria para el cambio", "Accion", "Arcane", 1, 5);
    vector<Serie*> Arcane{&Arcane1, &Arcane2, &Arcane3};

    // Better Call Saul
    Serie BCS1 = Serie();
    BCS1.setData(1, "Uno", "Crimen", "Better Call Saul", 1, 5);
    Serie BCS2 = Serie();
    BCS2.setData(2, "Mijo", "Crimen", "Better Call Saul", 1, 2);
    Serie BCS3 = Serie();
    BCS3.setData(3, "Nacho", "Crimen", "Better Call Saul", 1, 3);
    vector<Serie*> BCS{&BCS1, &BCS2, &BCS3};

    // The midnight gospel
    Serie TMG1 = Serie();
    TMG1.setData(1, "Malditos Zombies", "Comedia", "The Midnight Gospel", 1, 3);
    Serie TMG2 = Serie();
    TMG2.setData(7, "Muerte", "Comedia", "The Midnight Gospel", 1, 5);
    Serie TMG3 = Serie();
    TMG3.setData(3, "¿Vomitas helado?", "Comedia", "The Midnight Gospel", 1, 2);
    vector<Serie*> TMG{&TMG1, &TMG2, &TMG3};

    // Spy X Family
    Serie SPXFA1 = Serie();
    SPXFA1.setData(3, "Misión 3: Entrar en Edén", "Anime", "Spy X Family", 1, 2);
    Serie SPXFA2 = Serie();
    SPXFA2.setData(8, "Misión 8: Plan de camuflaje contra la policia secreta", "Anime", "Spy X Family", 1, 3);
    Serie SPXFA3 = Serie();
    SPXFA3.setData(25, "Misión 25: Primer contacto", "Anime", "Spy X Family", 1, 2);
    vector<Serie*> SPXFA{&SPXFA1, &SPXFA2, &SPXFA3};

    vector<vector<Serie*>> series{JJK, Arcane, BCS, TMG, SPXFA};

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
    string filtro = "";
    vector<video*> respaldo;
    vector<video*> nuevas;
    respaldo = movies;
    while (num != 9999) {
        nuevas.clear();
        int c = 0;
        int x = 0;
        std::sort(movies.begin(), movies.end(), [](video* a, video* b) { return *a > *b; });
        cout << "¿Cuál película quieres ver?(Coloca un número)" << endl;
        for (int i = 0; i < movies.size(); i++) {
            if (filtro == "") {
                std::cout << i + 1 << ". " << movies[i]->getname() << " (Grade: " << movies[i]->getgrade()
                          << ", Gender: " << movies[i]->getgender() << ")\n";
            } else {
                if (movies[i]->getgender() == filtro) {
                    nuevas.push_back(movies[i]);
                    std::cout << c + 1 << ". " << movies[i]->getname() << " (Grade: " << movies[i]->getgrade()
                              << ", Gender: " << movies[i]->getgender() << ")\n";
                    c = c + 1;
                }
            }
        };
        if (filtro != "") {
            movies = nuevas;
        }
        cout << movies.size() + 1 << ". Filtrar" << endl;
        cout << movies.size() + 2 << ". Salir" << endl;
        cin >> num;
        system("clear");
        if (num == movies.size() + 2) {
            num = 9999;
        } else if (num == movies.size() + 1) {
            while (1) {
                vector<string> generos{};
                movies = respaldo;
                cout << "¿Qué genero de serie quieres ver?" << endl;
                string genero = "";
                bool isthere = false;
                for (int i = 0; i < movies.size(); i++) {
                    genero = movies[i]->getgender();
                    for (int j = 0; j < generos.size(); j++) {
                        if (genero == generos[j]) {
                            isthere = true;
                            break;
                        }
                        isthere = false;
                    }
                    if (isthere == false) {
                        generos.push_back(genero);
                    }
                }
                for (int k = 0; k < generos.size(); k++) {
                    cout << k + 1 << ". " << generos[k] << endl;
                }
                cout << generos.size() + 1 << ". Borrar Filtro\n" << endl;
                cout << generos.size() + 2 << ". Salir\n" << endl;
                cin >> num;
                system("clear");
                if (num == generos.size() + 2) {
                    movies = nuevas;
                    break;
                } else if (num == generos.size() + 1) {
                    movies = respaldo;
                    filtro = "";
                    nuevas.clear();
                    break;
                } else if (num < generos.size() + 1 && num > 0) {
                    movies = respaldo;
                    filtro = generos[num - 1];
                    nuevas.clear();
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
                    cout << "\nInserte una tecla para continuar" << endl;
                    cin >> trash;
                    cout << endl;
                    system("clear");
                } else if (x == 3) {
                    string trash;
                    cout << "Usted esta viendo " << movies[num - 1]->getname() << endl;
                    cout << "\nInserte una tecla para continuar" << endl;
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

void menuseries(vector<vector<Serie*>> series) {
    int num = 0;
    string filtro = "";
    int c = 0;
    vector<vector<Serie*>> respaldo;
    respaldo = series;
    vector<vector<Serie*>> nuevas;
    while (num != 9999) {
        c = 0;
        nuevas.clear();
        std::sort(series.begin(), series.end(), [](vector<Serie*> a, vector<Serie*> b) { return a > b; });
        cout << "¿Cuál serie quieres ver?(Coloca un número)" << endl;
        for (int i = 0; i < series.size(); i++) {
            if (filtro == "") {
                std::cout << i + 1 << ". " << series[i][0]->getserieName();
                float grade = series[i][0]->getgrade();
                for (int j = 1; j < series[i].size(); j++) {
                    grade = (grade + series[i][j]->getgrade()) / 2;
                }
                std::cout << " (Grade: " << grade << ", Gender: " << series[i][0]->getgender() << ")\n";
            } else {
                if (series[i][0]->getgender() == filtro) {
                    nuevas.push_back(series[i]);
                    std::cout << c + 1 << ". " << series[i][0]->getserieName();
                    float grade = series[i][0]->getgrade();
                    for (int j = 1; j < series[i].size(); j++) {
                        grade = (grade + series[i][j]->getgrade()) / 2;
                    }
                    std::cout << " (Grade: " << grade << ", Gender: " << series[i][0]->getgender() << ")\n";
                    c = c + 1;
                }
            }
        };
        if (filtro != "") {
            series = nuevas;
        }
        cout << series.size() + 1 << ". Filtrar" << endl;
        cout << series.size() + 2 << ". Salir" << endl;
        cin >> num;
        system("clear");
        if (num == series.size() + 2) {
            num = 9999;
        } else if (num == series.size() + 1) {
            while (1) {
                vector<string> generos{};
                series = respaldo;
                cout << "¿Qué genero de serie quieres ver?" << endl;
                string genero = "";
                bool isthere = false;
                for (int i = 0; i < series.size(); i++) {
                    genero = series[i][0]->getgender();
                    for (int j = 0; j < generos.size(); j++) {
                        if (genero == generos[j]) {
                            isthere = true;
                            break;
                        }
                        isthere = false;
                    }
                    if (isthere == false) {
                        generos.push_back(genero);
                    }
                }
                for (int k = 0; k < generos.size(); k++) {
                    cout << k + 1 << ". " << generos[k] << endl;
                }
                cout << generos.size() + 1 << ". Borrar Filtro\n" << endl;
                cout << generos.size() + 2 << ". Salir\n" << endl;
                cin >> num;
                system("clear");
                if (num == generos.size() + 2) {
                    series = nuevas;
                    break;
                } else if (num == generos.size() + 1) {
                    filtro = "";
                    series = respaldo;
                    nuevas.clear();
                    break;
                } else if (num < generos.size() + 1 && num > 0) {
                    filtro = generos[num - 1];
                    series = respaldo;
                    nuevas.clear();
                    break;
                } else {
                    cout << "Opción inválida" << endl;
                }
            }
        } else if (num < series.size() + 1 && num > 0) {
            int x;
            while (1) {
                cout << "Serie: " << series[num - 1][0]->getserieName() << "\n";
                int n = series[num - 1].size();
                for (int i = 0; i < n - 1; ++i) {
                    for (int j = 0; j < n - i - 1; ++j) {
                        if (series[num - 1][j]->getseason() > series[num - 1][j + 1]->getseason() ||
                            (series[num - 1][j]->getseason() == series[num - 1][j + 1]->getseason() &&
                             series[num - 1][j]->getepiNumber() > series[num - 1][j + 1]->getepiNumber())) {
                            Serie temp = *series[num - 1][j];
                            series[num - 1][j] = series[num - 1][j + 1];
                            series[num - 1][j + 1] = &temp;
                        }
                    }
                }

                for (int i = 0; i < series[num - 1].size(); i++) {
                    cout << i + 1 << ". " << series[num - 1][i]->getepiName()
                         << "(N: " << series[num - 1][i]->getepiNumber()
                         << ", Season: " << series[num - 1][i]->getseason() << ")\n";
                }
                cout << series[num - 1].size() + 1 << ". Salir" << endl;
                cout << "Elija el capitulo que desee" << endl;
                cin >> x;
                system("clear");
                if (x == series[num - 1].size() + 1) {
                    break;
                } else if (x > 0 && x < series[num - 1].size() + 1) {
                    int y;
                    while (1) {
                        cout << "¿Qué desea hacer?" << endl;
                        cout << "1. Ver más información" << endl;
                        cout << "2. Asignar calificación" << endl;
                        cout << "3. Ver Capitulo" << endl;
                        cout << "4. Ver todos los episodios" << endl;
                        cin >> y;
                        system("clear");
                        if (y == 4) {
                            break;
                        } else if (y == 1) {
                            string trash;
                            series[num - 1][x - 1]->showInfo();
                            cout << "\nInserte una tecla para continuar" << endl;
                            cin >> trash;
                            system("clear");
                        } else if (y == 2) {
                            series[num - 1][x - 1]->grading();
                        } else if (y == 3) {
                            string trash;
                            cout << "Usted esta viendo: " << series[num - 1][x - 1]->getepiName() << endl;
                            cout << "\nInserte una tecla para continuar" << endl;
                            cin >> trash;
                            system("clear");
                        } else {
                            cout << "Opción Inválida" << endl;
                        }
                    }
                } else {
                    cout << "Opción inválida\n" << endl;
                }
            }
        } else {
            system("clear");
            cout << "Opción Invalida, elija una opción válida porfavor \n" << endl;
        }
    }
}