#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

struct Train {
    int number;
    int departureHour;
    int departureMin;
    int arrivalHour;
    int arrivalMin;
    char direction[30];
    float distance;
};

int main() 
{
    setlocale(LC_ALL, "RUS");
    struct Train trains[5];
    int i;
    float time, speed;
    for (i = 0; i < 5; i++) 
    {
        printf("\nПоезд %d\n", i + 1);
        printf("Номер поезда: ");
        scanf("%d", &trains[i].number);
        printf("Время отправления (часы минуты): ");
        scanf("%d%d", &trains[i].departureHour, &trains[i].departureMin);
        printf("Время прибытия (часы минуты): ");
        scanf("%d%d", &trains[i].arrivalHour, &trains[i].arrivalMin);
        printf("Направление: ");
        scanf("%29s", trains[i].direction);
        printf("Расстояние (км): ");
        scanf("%f", &trains[i].distance);
    }
    printf("\nСредняя скорость поездов:\n");
    for (i = 0; i < 5; i++) 
    {
        time = (trains[i].arrivalHour * 60 + trains[i].arrivalMin) - (trains[i].departureHour * 60 + trains[i].departureMin);
        if (time < 0)
            time += 1440;
        time = time / 60;
        if (time > 0) 
        {
            speed = trains[i].distance / time;
            printf("\nНомер поезда: %d\n", trains[i].number);
            printf("Направление: %s\n", trains[i].direction);
            printf("Средняя скорость: %.2f км/ч\n", speed);
        }
        else 
        {
            printf("\nНомер поезда: %d. Скорость рассчитать невозможно.\n",
                trains[i].number);
        }
    }
}