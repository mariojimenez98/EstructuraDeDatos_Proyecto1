/********************************************
    Nombre de Alumnos: Mario Ivan Jimenez Alfaro #727740
                       Benjamin Gil Flores #727211
                       Alejandro Sada Prendes #725958
                       Carlos Alanis #
    Fecha: 10 de Octubre 2020
    Materia: Estructura de Datos
    Programa: Proyecto 1
    Descripcion: Estudio para Mobil Mexico
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K_MAX_LITERS 5000.00
#define K_DAYS_WEEK 7
#define K_DISPATCHERS 3
#define K_ISLANDS 2

#define K_CONSOLE_PAUSE 91
#define K_CONSOLE_CLEAR 92

#define true 1
#define false 0

// Defining structures and initializing variables
typedef struct {
    char name[26];
    float expenses[K_DAYS_WEEK];
    float total;
} Dispatcher;

typedef struct {
    Dispatcher dispatchers[K_DISPATCHERS];
} Island;

Dispatcher extra = { "Extra", { 0 }, K_MAX_LITERS };
Dispatcher supreme = { "Supreme", { 0 }, K_MAX_LITERS };
Dispatcher diesel = { "Diesel", { 0 }, K_MAX_LITERS };

Island islands[2];

int i, j, currentDayOfWeek = 7;

// Explicit declaration of functions
void captureConsumption();
void consumptionReportByDay();
void consumptionReportByFuel();
void selectDayOfTheWeek();
void restartApp();

// Executes a system action in current operating system
void systemAction(int action)
{
    switch(action) {
        case K_CONSOLE_CLEAR:
            #if __unix__
                system("clear");
            #else
                system("cls");
            #endif
            break;
        case K_CONSOLE_PAUSE:
            #if __unix__
                printf("Press [Enter] to continue\n");
                getchar();
                getchar();
            #else
                system("pause");
            #endif
            break;
    }
}

// Assigning dispatchers to islands
void initializeIslands()
{
    for (i = 0; i < K_ISLANDS; i++)
    {
        islands[i].dispatchers[0] = extra;
        islands[i].dispatchers[1] = supreme;
        islands[i].dispatchers[2] = diesel;
    }

}

int verifyOption(int *value, int max, int min)
{
    if (*value > max || *value < min)
    {
        do
        {
            printf("\tOpci%cn no valida, intente de nuevo: ", 162);
            scanf("%i", &*value);
        } while (*value > max || *value < min);
    }
    return 1;
}

float verifyAmount(float *amt)
{
    if (*amt > K_MAX_LITERS || *amt < 0.00)
    {
        do
        {
            printf("\tMonto no valido, intente de nuevo: ");
            scanf("%f", &*amt);
        } while (*amt > K_MAX_LITERS || *amt < 0.00);
    }
}

int selectFuelTypes()
{
    int opc;
    printf("\t------- Selecci%cne el tipo de combustible -------\n\n"
           "\t\t0 - Extra\n"
           "\t\t1 - Supreme\n"
           "\t\t2 - Diesel\n"
           "\n\tIngrese su selecci%cn: ", 162, 162);
    scanf("%i", &opc);
    verifyOption(&opc, 2, 0);
    printf("\n");
    return opc;
}

int selectIsland()
{
    int opc;
    printf("\t------- Selecci%cne una isla -------\n\n"
           "\t\t0 - Isla 1\n"
           "\t\t1 - Isla 2\n"
           "\n\tIngrese su selecci%cn: ", 162, 162);
    scanf("%i", &opc);
    verifyOption(&opc, 1, 0);
    printf("\n");
    return opc;
}

float selectAmount()
{
    float amount;
    printf("\t------- Selecci%cne el monto para el dia %d -------\n\n", 162, currentDayOfWeek);
    printf("\tMonto: \t");
    scanf("%f", &amount);
    verifyAmount(&amount);
    printf("\n");
    return amount;
}

void menu()
{
    int opc;
    do
    {
        printf("\n\t------- Bienvenido a Mobil M%cxico, que desea hacer? -------\n\n"
               "\t\t1 - Captura de consumo\n"
               "\t\t2 - Reporte de consumo por d%ca\n"
               "\t\t3 - Reporte de consumo por combustible\n"
               "\t\t4 - Selecci%cn de dia de la semana\n"
               "\t\t5 - Reinicio de aplicaci%cn\n"
               "\t\t6 - Salir\n\n"
               "\tIngrese su selecci%con: ", 130, 161, 162, 162, 162);
        scanf("%i", &opc);
        if (verifyOption(&opc, 6, 1) == true) {
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

        systemAction(K_CONSOLE_PAUSE);
        systemAction(K_CONSOLE_CLEAR);
    } while (opc != 6);
}

void captureConsumption()
{
    systemAction(K_CONSOLE_CLEAR);

    int island, fuelType;
    float amount;

    float *currentDayExpenseAmount, *total;
    char *dispatcherName;

    island = selectIsland();
    fuelType = selectFuelTypes();
    amount = selectAmount();

    currentDayExpenseAmount = &islands[island].dispatchers[fuelType].expenses[currentDayOfWeek - 1];
    total = &islands[island].dispatchers[fuelType].total;
    dispatcherName = islands[island].dispatchers[fuelType].name;

    if (*currentDayExpenseAmount == 0) {
        *currentDayExpenseAmount = amount;
        *total -= amount;
        printf("\tSe registraron %.2f lts para la isla %d con despachador %s en el dia %d\n",
            *currentDayExpenseAmount,
            island,
            dispatcherName,
            currentDayOfWeek
        );

        printf("\tSu cantidad total ahora es de: %.2f\n", *total);
    } else {
        printf("\tLa isla %d con despachador %s ya tiene un registro para el dia %d, el registro fue de: %.2f lts\n",
            island,
            dispatcherName,
            currentDayOfWeek,
            *currentDayExpenseAmount
        );
    }
}

void consumptionReportByDay()
{
    systemAction(K_CONSOLE_CLEAR);

    selectDayOfTheWeek();
    printf("\n\t------- Reporte de consumo por d%ca -------\n\n", 161);
    for (i = 0; i < K_ISLANDS; i++)
        {
            printf("\n\t-------- Isla %i --------", i + 1);
            for (j = 0; j < K_DISPATCHERS; j++)
                printf("\n\t\tDespachador: %i\tCombustible: %s\tMonto Consumido: %0.2f lts\n",
                       j,
                       islands[i].dispatchers[j].name,
                       islands[i].dispatchers[j].expenses[currentDayOfWeek - 1]
                );
        }
    printf("\n");
}

void consumptionReportByFuel()
{
    systemAction(K_CONSOLE_CLEAR);

    int fuelType = selectFuelTypes();
    float totalConsumption = 0.0;

    printf("\n\t------- Reporte de consumo por combustible -------\n\n");
    for (i = 0; i < K_ISLANDS; i++)
    {
        printf("\n\t-------- Isla %i --------", i + 1);
        for (j = 0; j < K_DAYS_WEEK; j++)
        {
            printf("\n\t\tD%ca: %i\tCombustible: %s\tMonto Consumido: %0.2f lts\n",
                   161,
                   j + 1,
                   islands[i].dispatchers[fuelType].name,
                   islands[i].dispatchers[fuelType].expenses[j]

            );
            totalConsumption = totalConsumption + islands[i].dispatchers[fuelType].expenses[j];
        }
    }
    printf("\n\t----------------------------------------------------------------------------\n");
    printf("\n\tDurante toda la semana, las islas consumieron un total de %0.2f lts de %s\n\n",
           totalConsumption, islands[0].dispatchers[fuelType].name);
}

void selectDayOfTheWeek()
{
    systemAction(K_CONSOLE_CLEAR);

    int opc;
    printf("\t------- Selecci%cne el d%ca de la semana -------\n\n"
           "\t1 - Lunes\n"
           "\t2 - Martes\n"
           "\t3 - Miercoles\n"
           "\t4 - Jueves\n"
           "\t5 - Viernes\n"
           "\t6 - Sabado\n"
           "\t7 - Domingo\n\n"
           "Ingrese su selecci%cn: ", 162, 161, 162);

    scanf("%d", &opc);
    verifyOption(&opc, 7, 1);
    currentDayOfWeek = opc;
    printf("\n\n\tHas seleccionado el dia %d", currentDayOfWeek);
    printf("\n");
}

void restartApp()
{
    systemAction(K_CONSOLE_CLEAR);

    printf("\tReiniciando la aplicacion ... \n\n");
    for (i = 0; i < K_ISLANDS; i++)
        for (j = 0; j < K_DISPATCHERS; j++)
        {
            memset(islands[i].dispatchers[j].expenses, 0, sizeof(islands[i].dispatchers[j].expenses));
            islands[i].dispatchers[j].total = K_MAX_LITERS;
        }

    currentDayOfWeek = 7;

    printf("\tLa aplicacion se reinicio con exito\n\n");
}

void main() {
    initializeIslands();
    menu();
}
