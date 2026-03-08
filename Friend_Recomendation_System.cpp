#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int Max = 20;
string names[Max];
int Adjmatrix[Max][Max];
int userCount = 0;
int Find_ID(string name)
{
    for (int i = 0; i < userCount; i++)
    {
        if (names[i] == name)
        {
            return i;
        }
    }

    return -1;
}

void addUser()
{
    system("cls");
    if (userCount >= Max)
    {
        cout << "System is FULL!" << endl;
    }
    else
    {
        cout << "============= Register New User=============\n";
        string n;

        while (true)
        {
            cout << "Enter your name: ";
            getline(cin, n);

            if (n.empty() || n == " " || n == "\t")
            {
                cout << "Name should not be Empty.\n " << endl;
            }
            else
                break;
        }

        if (Find_ID(n) != -1)
        {
            cout << "This user already Registered\n";
        }
        else
        {
            names[userCount] = n;
            for (int j = 0; j < Max; j++)
            {
                Adjmatrix[userCount][j] = 0;
            }
            userCount++;
            cout << "User added successfully\n";
        }
    }
    cout << "\nPress Enter to continue...";
    cin.get();
}

void makeFriend()
{
    system("cls");
    string n1, n2;
    cout << "=========== Connect  (ADD friend)  =============" << endl;
    cout << "Enter first name: ";
    getline(cin, n1);
    cout << "Enter second name: ";
    getline(cin, n2);

    int u = Find_ID(n1);
    int v = Find_ID(n2);
    if (u != -1 && v != -1 && u != v)
    {
        if (Adjmatrix[u][v] == 0)
        {
            Adjmatrix[u][v] = 1;
            Adjmatrix[v][u] = 1;
            cout << "Friendship Established!" << endl;
        }
        else
        {
            cout << "They are already friends!" << endl;
        }
    }
    else
    {
        cout << "User not found!" << endl;
    }
    cout << "\nPress Enter to continue...";
    cin.get();
}
void checkMutualFriends()
{
    system("cls");
    string n1, n2;
    cout << "=========== Check Mutual Friends =============" << endl;
    cout << "Enter first name: ";
    getline(cin, n1);
    cout << "Enter second name: ";
    getline(cin, n2);
    int u = Find_ID(n1);
    int v = Find_ID(n2);
    if (u != -1 && v != -1)
    {
        if (Adjmatrix[u][v] == 1)
        {
            cout << n1 << "and" << n2 << "are friends\n";
        }
        cout << "\nMutual Friends List: " << endl;
        bool found = false;
        for (int i = 0; i < userCount; i++)
        {
            if (Adjmatrix[u][i] == 1 && Adjmatrix[v][i] == 1)
            {
                cout << "- " << names[i] << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No mutual friends found." << endl;
        }
    }
    else
    {
        cout << "Invalid User!" << endl;
    }
    cout << "\nPress Enter to continue...";
    cin.get();
}

void getSuggestions() {
	system("cls");
    string name;
       cout << "=========== Friend Suggestions =============" << endl;
    cout << "Enter name to get recommendations:";
    getline(cin,name);

    int u = Find_ID(name);
    if (u == -1) {
        cout << " User not found.\n";
         cout<<"Press any key to continue"<<endl;
    cin.get();
    }
   else {   
    cout << "\n Suggestions for " << name << " ---\n";
    bool found = false;

    for (int v = 0; v < userCount; v++) {
        // Skip if it's the same person or they are already friends
        if (u == v || Adjmatrix[u][v] == 1) 
        continue;
        int mutualCount = 0;
        for (int k = 0; k < userCount; k++) {
            if (Adjmatrix[u][k] == 1 && Adjmatrix[v][k] == 1) {
                mutualCount++;
            }
        }

        if (mutualCount > 0) {
            cout << names[v] << " (" << mutualCount << " mutual friends)\n";
            found = true;
        }
    }

    if (!found) cout << "No recommendations found.\n";
    cout<<"Press any key to continue"<<endl;
    cin.get();	
}
    
}
void showMenu()
{
    cout << "\n=========== Social Network (Friend Recomendation System) =============" << endl;
    cout << "1. Add User" << endl;
    cout << "2. Make Friend" << endl;
    cout << "3. Show All Users" << endl;
    cout << "4. Get Suggestions" << endl;
    cout << "5. Check Mutual Friends" << endl; // Fixed menu text
    cout << "6. Display Matrix" << endl;
    cout << "7. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}
// --- 4. SHOW DIRECTORY ---
void showAll()
{
    system("cls");
    cout << "--- NETWORK DIRECTORY ---" << endl
         << endl;

    cout << left << setw(5) << "ID" << setw(15) << "Name" << "Friends" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < userCount; i++)
    {
        cout << left << setw(5) << i  << setw(15) << names[i];

        bool anyFriend = false;
        bool first = true;

        for (int j = 0; j < userCount; j++)
        {
            if (Adjmatrix[i][j] == 1)
            {
                if (!first)
                    cout << ", ";
                cout << names[j];
                anyFriend = true;
                first = false;
            }
        }

        if (!anyFriend)
            cout << "No Friends";
        cout << endl;
    }
    cout << "\nPress Enter to continue...";
    cin.get();
}

void displayMatrix()
{
    system("cls");
    if (userCount == 0)
    {
        cout << "Network is empty!" << endl;
    }
    else
    {
        cout << "=========== ADJACENCY MATRIX ===========" << endl
             << endl;

        // student id With name
        for (int i = 0; i < userCount; i++)
        {
            cout << i << " ----- " << names[i] << endl;
        }
        cout << "    ";
        for (int i = 0; i < userCount; i++)
        {
            cout << setw(4) << i;
        }
        cout << "\n    " << string(userCount * 4, '-') << endl;

        // Matrix Rows
        for (int i = 0; i < userCount; i++)
        {
            cout << setw(2) << i << " |"; // Vertical Header
            for (int j = 0; j < userCount; j++)
            {
                cout << setw(4) << Adjmatrix[i][j];
            }
            cout << endl;
        }
    }
    cout << "\nPress Enter to continue...";
    cin.get();
}
int main()
{

    for (int i = 0; i < Max; i++)
    {
        for (int j = 0; j < Max; j++)
        {
            Adjmatrix[i][j] = 0;
        }
    }
    int choice;
    while (true)
    {
        system("cls");
        showMenu();
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        cin.ignore();
        if (choice == 1)
        {
            addUser();
        }
        else if (choice == 2)
        {
            makeFriend();
        }
        else if (choice == 3)
        {
            showAll();
        }
        else if (choice == 4)
        {
            getSuggestions();
        }
        else if (choice == 5)
        {
            checkMutualFriends();
        }
        else if (choice == 6)
        {
            displayMatrix();
        }
        else if (choice == 7)
        {
            break;
        }
    }
}