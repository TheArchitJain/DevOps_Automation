#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;
void login();
void signup();
void forgot();
void calculatefare();
int book();
int main()
{
    cout << "\t\t\t________________________________________________________\n\n";
    cout << "\t\t\t     Welcome to VehiRent - Your Personal Cab Service     \n\n";
    cout << "\t\t\t__________________      MENU      ______________________\n\n";
    cout << "                                                                                \n\n";
    cout << "\t | Press 1 to Login                 | " << endl;
    cout << "\t | Press 2 to Signup                | " << endl;
    cout << "\t | Press 3 if you Forgot Password   | " << endl;
    cout << "\t | Press 4 to Exit                  | " << endl;
    cout << "\t Please Enter Your Choice  : " << endl;
    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t\t\t Thank You!  \n\n"
             << endl;
        break;
    default:
        cout << "Please Enter the choice from given above." << endl;
        sleep(5);
        main();
    }
}
void login()
{
    int count = 0;
    string username, password, id, pass;
    system("cls");
    cout << "\t\t________________________________________________________\n\n";
    cout << "\t\t     Welcome to VehiRent - Your Personal Cab Service     \n\n";
    cout << "\t\t__________________      LOGIN      ______________________\n\n";
    cout << "                                                                                \n\n"
         << endl;
    cout << "Please Enter Your Username and Password : " << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

    ifstream input("test.txt"); // opening database file
    while (input >> id >> pass)
    {
        if (id == username && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << username << " You have Successfully Logged In" << endl;
        book();
    }
    else
    {
        cout << "Login Failed. Please Check your Username and password" << endl;
        main();
    }
}
void signup()
{
    string username, password;
    system("cls");
    cout << "\t\t________________________________________________________\n\n";
    cout << "\t\t     Welcome to VehiRent - Your Personal Cab Service     \n\n";
    cout << "\t\t__________________      SIGNUP      ______________________\n\n";
    cout << "                                                                                \n\n"
         << endl;
    cout << "Please Enter the Username and Password to Signup : " << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

    ofstream reg("test.txt", ios::app);         // opening database.txt file (write inside file)
    reg << username << ' ' << password << endl; // writing to database.txt (username and password)
    cout << "You have Successfully Signed Up" << endl;
    main();
}
void forgot()
{
    int ch;
    system("cls");
    cout << "\t\t________________________________________________________\n\n";
    cout << "\t\t     Welcome to VehiRent - Your Personal Cab Service     \n\n";
    cout << "\t\t__________________      FORGOT PASSWORD      ______________________\n\n";
    cout << "                                                                                \n\n"
         << endl;
    cout << "Press 1 to Reset Password" << endl;
    cout << "Press 2 to go back to Main Menu" << endl;
    cout << "Enter your choice : ";
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
        system("cls");
        int count = 0;
        string username, password, id, pass;
        cout << "\t\t________________________________________________________\n\n";
        cout << "\t\t     Welcome to VehiRent - Your Personal Cab Service     \n\n";
        cout << "\t\t__________________      RESET PASSWORD      ______________________\n\n";
        cout << "                                                                                \n\n"
             << endl;
        cout << "Please Enter the Username You remembered : ";
        cin >> username;
        ifstream input("test.txt"); // opening database.txt file
        while (input >> id >> pass)
        {
            if (id == username)
            {
                count = 1;
            }
        }
        input.close();
        if (count == 1)
        {
            cout << "Your Account is found !" << endl;
            cout << "Your Password is : " << pass << endl;
            main();
        }
        else
        {
            cout << "Username not found" << endl;
            main();
        }
        break;
    }
    case 2:
        main();
    default:
        cout << "Please Enter the choice from given above." << endl;
        forgot();
    }
}
void display(vector<string> cars)
{
    cout << "Enter the type of car you want to book : " << endl;
    for (int i = 0; i < cars.size(); i++)
    {
        cout << i + 1 << ". " << cars[i] << endl;
    }
}

string source, destination;
vector<string> cars = {"Micro", "Mini", "Sedan", "SUV", "Luxury"};
void car()
{
    cout << "Enter the source : ";
    cin >> source;
    cout << "Enter the destination : ";
    cin >> destination;
}
int a;
int book()
{
    car();

    int fare, x;

    while (!cars.empty())
    {
        display(cars);

        cin >> a;

        if (a > 0 && a <= cars.size())
        {
            cout << "You have selected " << cars[a - 1] << " car" << endl;
            calculatefare();

            cout << "Do you want to book another car? " << endl;
            cout << "Press 1 to book another car" << endl;
            cout << "Press 2 to exit" << endl;
            cin >> x;
            if (x == 2)
            {
                exit(0);
            }
            else
            {
                book();
            }
        }
        else
        {
            cout << "Invalid input. Please select a valid option." << endl;
        }
    }

    cout << "No more cars available." << endl;

    return 0;
}
void calculatefare()
{
    int km, fare;
    transform(source.begin(), source.end(), source.begin(), ::tolower);
    transform(destination.begin(), destination.end(), destination.begin(), ::tolower);

    cout << "You are booking your ride from " << source << " to " << destination << endl;
    if (((source == "delhi" && destination == "meerut") || (source == "meerut" && destination == "delhi")) && cars[a - 1] == "Micro")
    {
        km = 70;
        fare = km * 10;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "meerut") || (source == "meerut" && destination == "delhi")) && cars[a - 1] == "Mini")
    {
        km = 70;
        fare = km * 15;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "meerut") || (source == "meerut" && destination == "delhi")) && cars[a - 1] == "Sedan")
    {
        km = 70;
        fare = km * 20;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "meerut") || (source == "meerut" && destination == "delhi")) && cars[a - 1] == "SUV")
    {
        km = 70;
        fare = km * 25;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "meerut") || (source == "meerut" && destination == "delhi")) && cars[a - 1] == "Luxury")
    {
        km = 70;
        fare = km * 30;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "gurugram") || (source == "gurugram" && destination == "delhi")) && cars[a - 1] == "Micro")
    {
        km = 30;
        fare = km * 10;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "gurugram") || (source == "gurugram" && destination == "delhi")) && cars[a - 1] == "Mini")
    {
        km = 30;
        fare = km * 15;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "gurugram") || (source == "gurugram" && destination == "delhi")) && cars[a - 1] == "Sedan")
    {
        km = 30;
        fare = km * 20;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "gurugram") || (source == "gurugram" && destination == "delhi")) && cars[a - 1] == "SUV")
    {
        km = 30;
        fare = km * 25;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "gurugram") || (source == "gurugram" && destination == "delhi")) && cars[a - 1] == "Luxury")
    {
        km = 30;
        fare = km * 30;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "noida") || (source == "noida" && destination == "delhi")) && cars[a - 1] == "Micro")
    {
        km = 50;
        fare = km * 10;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "noida") || (source == "noida" && destination == "delhi")) && cars[a - 1] == "Mini")
    {
        km = 50;
        fare = km * 15;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "noida") || (source == "noida" && destination == "delhi")) && cars[a - 1] == "Sedan")
    {
        km = 50;
        fare = km * 20;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "noida") || (source == "noida" && destination == "delhi")) && cars[a - 1] == "SUV")
    {
        km = 50;
        fare = km * 25;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "noida") || (source == "noida" && destination == "delhi")) && cars[a - 1] == "Luxury")
    {
        km = 50;
        fare = km * 30;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "ghaziabad") || (source == "ghaziabad" && destination == "delhi")) && cars[a - 1] == "Micro")
    {
        km = 40;
        fare = km * 10;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "ghaziabad") || (source == "ghaziabad" && destination == "delhi")) && cars[a - 1] == "Mini")
    {
        km = 40;
        fare = km * 15;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "ghaziabad") || (source == "ghaziabad" && destination == "delhi")) && cars[a - 1] == "Sedan")
    {
        km = 40;
        fare = km * 20;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "ghaziabad") || (source == "ghaziabad" && destination == "delhi")) && cars[a - 1] == "SUV")
    {
        km = 40;
        fare = km * 25;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "ghaziabad") || (source == "ghaziabad" && destination == "delhi")) && cars[a - 1] == "Luxury")
    {
        km = 40;
        fare = km * 30;
        cout << "Your fare is : " << fare << endl;
    }
    else
    {
        cout << "No Rides Available right now Please TRY AGAIN " << endl;
        book();
    }
    cout << "Do You Want to confirm your booking ?" << endl;
    cout << "Press 1 to confirm" << endl;
    cout << "Press 2 to cancel" << endl;
    int y;
    cin >> y;
    if (y == 1)
    {
        cout << "Your booking is confirmed" << endl;
        cout << "Have a safe journey , THANK YOU !!" << endl;
        cars.erase(cars.begin() + a - 1);
    }
    else if (y == 2)
    {
        cout << "Your booking is cancelled" << endl;
        cout << "Do you want to book another car ?" << endl;
        cout << "Press 1 to book another car" << endl;
        cout << "Press 2 to exit" << endl;
        int z;
        cin >> z;
        if (z == 1)
        {
            system("cls");
            book();
        }
        else if (z == 2)
        {
            exit(0);
        }
        else
        {
            cout << "Please enter the correct choice" << endl;
            book();
        }
    }
    else
    {
        cout << "Please enter the correct choice" << endl;
        book();
    }
}