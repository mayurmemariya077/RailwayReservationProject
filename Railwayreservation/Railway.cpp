



#include <iostream>
#include <cstring>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[20];

    static int trainCount;

public:

    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    Train(int no, const char name[], const char src[],
          const char dest[], const char time[])
    {
        trainNumber = no;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    ~Train()
    {
        trainCount--;
    }

    void inputTrainDetails()
    {
        cout << "\nEnter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 20);
    }

    void displayTrainDetails()
    {
        cout << "\nTrain Number : " << trainNumber;
        cout << "\nTrain Name   : " << trainName;
        cout << "\nSource       : " << source;
        cout << "\nDestination  : " << destination;
        cout << "\nTrain Time   : " << trainTime << endl;
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        if (totalTrains < 100)
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
            cout << "\nTrain Record Added Successfully!\n";
        }
        else
        {
            cout << "\nStorage Full!\n";
        }
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "\nNo Train Records Found!\n";
            return;
        }

        cout << "\n===== All Train Records =====\n";
        for (int i = 0; i < totalTrains; i++)
        {
            trains[i].displayTrainDetails();
            cout << "----------------------------\n";
        }
    }

    void searchTrainByNumber(int number)
    {
        bool found = false;


        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain Found:\n";
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nTrain Number " << number << " not found!\n";
        }
    }
};

int main()
{
    RailwaySystem rs;
    int choice, trainNo;

    do
    {
        cout << "\n===== Railway Reservation System =====";
        cout << "\n1. Add New Train Record";
        cout << "\n2. Display All Train Records";
        cout << "\n3. Search Train By Number";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            rs.addTrain();
            break;

        case 2:
            rs.displayAllTrains();
            break;

        case 3:
            cout << "\nEnter Train Number to Search: ";
            cin >> trainNo;
            rs.searchTrainByNumber(trainNo);
            break;

        case 4:
            cout << "\nThank You. Goodbye!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}