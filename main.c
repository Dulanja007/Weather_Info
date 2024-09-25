#include <stdio.h>
#include <stdlib.h>

const NO_OF_REGIONS = 50;

enum mainMenuOptions {ADD_NEW_RECORD = 1, PRINT_WEATHER_REPORT,PRINT_SUMMERY, EXIT};

struct weatherDataRecord{
    int centerID;
    char date[15];
    float temperature;
    float humidity;
    int rainfall;
    float windSpeed;
};

struct summeryWeatherReport{
    float maxtemperature;
    float minHumidity;
    int totalRainfall;
    float avgWindSpeed;
};

struct weatherDataRecord readData();
void printWeatherReport(struct weatherDataRecord weatherRecords[NO_OF_REGIONS]);
void printSummeryReport(struct summeryWeatherReport summeryReport);
float findMaxTemperature(struct weatherDataRecord weatherRecords[NO_OF_REGIONS]);
float findMinHumidity(struct weatherDataRecord weatherRecords[NO_OF_REGIONS]);
int calTotalRainfall (struct weatherDataRecord weatherRecords[NO_OF_REGIONS]);
int calAverageWindSpeed (struct weatherDataRecord weatherRecords[NO_OF_REGIONS]);

int main()
{
    mainMenuHandler();
    return 0;
}

void mainMenuHandler(){
    int choice;
    struct weatherDataRecord newRecord;
    struct weatherDataRecord weatherReports[NO_OF_REGIONS];

    do{
    choice = displayMenu();
    switch(choice){
    case ADD_NEW_RECORD:
        printf("Add new record\n");
        newRecord = readData();
         printf("%.2f",newRecord.temperature);
        break;
    case PRINT_WEATHER_REPORT:
        printf("print Weather Report\n");
        break;
        //printWeatherReport();
    case PRINT_SUMMERY:
        printf("print Summery Report\n");
        break;
        //printSummeryReport();
    case EXIT:
        printf("Exit\n");
        break;
    }
    }while(choice!= EXIT);
}

struct weatherDataRecord readData(){
    int centerID;
    char date[15];
    float temperature;
    printf("Enter center ID \t:");
    scanf("%d",&centerID);
    printf("Enter Date (yyyy mm dd) \t:");
    scanf(" %[^\n]s",&date);
    printf("Enter Temperature \t:");
    scanf("%f",&temperature);

    struct weatherDataRecord newRecord = {
        centerID,
        date,
        temperature,
    };
    printf("%d\n",newRecord.centerID);
    printf("%f\n",newRecord.temperature);
    printf("\n");

    return newRecord;

};
int displayMenu(){
    int choice;
    printf("\tMain Menu\n");
    printf("==============================\n");
    printf(" 1. Add new record\n");
    printf(" 2. Print Daily weather report\n");
    printf(" 3. Print Summery Report\n");
    printf(" 4. Exit");

    printf("\n\nInput any number among [1 - 4] : ");
    scanf("%d", &choice);

    return choice;
}
