/********************************************
    Nombre de Alumnos: Mario Ivan Jimenez Alfaro #727740
                       Benjamin
                       Alejandro
                       Carlos
    Fecha: 10 de Octubre 2020
    Materia: Estructura de Datos
    Programa: Proyecto 1
    Descripcion: Estudio para Mobil Mexico
********************************************/

#include <stdio.h>

#define K_MAX_LITERS 5000
#define K_DAYS_WEEK 7
#define K_DISPATCHERS 3

int mIsland1[K_DAYS_WEEK][K_DISPATCHERS], mIsland2[K_DAYS_WEEK][K_DISPATCHERS];

void initializeMatrixes() {
    for (int y = 0; y < K_DAYS_WEEK; y++)
        for (int x = 0; x < K_DISPATCHERS; x++) {
            mIsland1[y][x] = K_MAX_LITERS;
            mIsland2[y][x] = K_MAX_LITERS;
        }
}

void menu() {
    int opc;
    do {
        printf("\n------- Bienvenido a Mobil M%cxico, que desea hacer? -------\n\n"
               "\t1.-Captura de Consumo\n"
               "\t2.-Reporte de Consumo por d%ca\n"
               "\t3.-Reporte de Consumo por Combustible\n"
               "\t4.-Selecci%cn de dia de la semana\n"
               "\t5.-Reinicio de Aplicaci%cn\n"
               "\t6.-Salir\n\n"
               "Ingrese su selecci%con: ", 130, 161, 162, 162, 162);
        scanf("%i", &opc);
        if (verifyOption(&opc, 6, 1) == 1) {
            switch (opc) {
                case 1:
                    captureConsumption();
                    break;
                case 2:
                    consumptionReportByDay();
                    break;
                case 3:
                    consumptionReportByFuel();
                    break;
                case 4:
                    selectDayOfTheWeek();
                    break;
                case 5:
                    restartApp();
                    break;
            }
        }
        system("pause");
        system("cls");
    } while (opc != 6);
}

int verifyOption(int *value, int upper, int lower) {
    if (*value > upper || *value < lower) {
        do {
            printf("Opci%cn no valida, intente de nuevo: ", 162);
            scanf("%i", &*value);
        } while (*value > upper || *value < lower);
    }
    return 1;
}

int selectFuelTypes() {
    int opc;
    printf("------- Selecci%cne el tipo de combustible -------\n\n"
           "\t0.-Extra\n"
           "\t1.-Supreme\n"
           "\t2.-Diesel\n"
           "Ingrese su selecci%cn: ", 162, 162);
    scanf("%i", &opc);
    verifyOption(&opc, 2, 0);
    printf("\n");
    return opc;
}

int selectIsland() {
    int opc;
    printf("------- Selecci%cne una isla -------\n\n"
           "\t0.-Isla 1\n"
           "\t1.-Isla 2\n"
           "Ingrese su selecci%cn: ", 162, 162);
    scanf("%i", &opc);
    verifyOption(&opc, 1, 0);
    printf("\n");
    return opc;
}

void captureConsumption() {
    system("cls");
    // --- INCOMPLETO ---
    int island, day, fuelType;
    island = selectIsland();
    //day = selectDayOfTheWeek();
    fuelType = selectFuelTypes();
    /*if (island == 0) {
        mIsland1[day][fuelType] = algo
    } else {
        mIsland2[day][fuelType] = algo
    }*/
}

void consumptionReportByDay() {

}

void consumptionReportByFuel() {

}

void selectDayOfTheWeek() {

}

void restartApp() {

}

void main() {
    initializeMatrixes();
    menu();
}
