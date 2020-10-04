/********************************************
    Nombre de Alumnos: Mario Ivan Jimenez Alfaro #727740
                       Benjamin Gil Flores #727211
                       Alejandro
                       Carlos
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

int currentDayOfWeek = 7;

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
    for (int i = 0; i < 2; i++)
    {
        islands[i].dispatchers[0] = extra;
        islands[i].dispatchers[1] = supreme;
        islands[i].dispatchers[2] = diesel;
    }
    
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

int selectFuelTypes() 
{
    int opc;
    printf("------- Selecci%cne el tipo de combustible -------\n\n"
           "\t0 - Extra\n"
           "\t1 - Supreme\n"
           "\t2 - Diesel\n"
           "Ingrese su selecci%cn: ", 162, 162);
    scanf("%i", &opc);
    verifyOption(&opc, 2, 0);
    printf("\n");
    return opc;
}

int selectIsland() 
{
    int opc;
    printf("------- Selecci%cne una isla -------\n\n"
           "\t0 - Isla 1\n"
           "\t1 - Isla 2\n"
           "Ingrese su selecci%cn: ", 162, 162);
    scanf("%i", &opc);
    verifyOption(&opc, 1, 0);
    printf("\n");
    return opc;
}

float selectamount()
{
    float amount; 
    printf("------- Selecci%cne el monto para el dia %d -------\n\n", 162, currentDayOfWeek);
    printf("Monto: \t");
    scanf("%f", &amount);
    printf("\n");
    return amount;
}

void menu() 
{
    int opc;
    do {
        printf("\n------- Bienvenido a Mobil M%cxico, que desea hacer? -------\n\n"
               "\t1 - Captura de Consumo\n"
               "\t2 - Reporte de Consumo por d%ca\n"
               "\t3 - Reporte de Consumo por Combustible\n"
               "\t4 - Selecci%cn de dia de la semana\n"
               "\t5 - Reinicio de Aplicaci%cn\n"
               "\t6 - Salir\n\n"
               "Ingrese su selecci%con: ", 130, 161, 162, 162, 162);
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

void captureConsumption() {
    systemAction(K_CONSOLE_CLEAR);

    int island, fuelType;
    float amount;
    
    float *currentDayExpenseAmount, *total;
    char *dispatcherName;

    island = selectIsland();
    fuelType = selectFuelTypes();
    amount = selectamount();

    currentDayExpenseAmount = &islands[island].dispatchers[fuelType].expenses[currentDayOfWeek - 1];
    total = &islands[island].dispatchers[fuelType].total;
    dispatcherName = islands[island].dispatchers[fuelType].name;

    if (*currentDayExpenseAmount == 0) {
        *currentDayExpenseAmount = amount;
        *total -= amount;
        printf(
            "Se registraron %.2f lts para la isla %d con despachador %s en el dia %d\n", 
            *currentDayExpenseAmount, 
            island,
            dispatcherName,
            currentDayOfWeek
        );

        printf("Su cantidad total ahora es de: %.2f\n", *total);
    } else {
        printf(
            "La isla %d con despachador %s ya tiene un registro para el dia %d, el registro fue de: %.2f lts\n",
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

    printf("Do something");
}

void consumptionReportByFuel() 
{
    systemAction(K_CONSOLE_CLEAR);

    printf("Do something");
}

void selectDayOfTheWeek() 
{
    systemAction(K_CONSOLE_CLEAR);

    int opc;
    printf("------- Selecci%cne el tipo de combustible -------\n\n"
           "\t1 - Lunes\n"
           "\t2 - Martes\n"
           "\t3 - Miercoles\n"
           "\t4 - Jueves\n"
           "\t5 - Viernes\n"
           "\t6 - Sabado\n"
           "\t7 - Domingo\n\n"
           "Ingrese su selecci%cn: ", 162, 162);

    scanf("%d", &opc);
    verifyOption(&opc, 7, 1);
    currentDayOfWeek = opc;
    printf("\n\nHas seleccionado el dia %d", currentDayOfWeek);
    printf("\n");
}

void restartApp() 
{
    systemAction(K_CONSOLE_CLEAR);

    // NO FUNCIONA
    printf("Reiniciando la aplicacion ... \n\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < K_DISPATCHERS; j++)
        {
            memset(islands[i].dispatchers[j].expenses, 0, K_DAYS_WEEK);
            islands[i].dispatchers[j].total = K_MAX_LITERS;   
        }    
    printf("La aplicacion se reinicio con exito\n");
}

void main() {
    initializeIslands();
    menu();
}
