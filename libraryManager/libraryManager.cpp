// libraryManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "items.h"

Catalogue* g_pCatalog = NULL;
Bank* g_pBank = NULL;

void call_addItem() {
    if (g_pCatalog)
        g_pCatalog->addItem();
    else
        cout << "The catalogue class was not created!";

}

void call_deleteItem() {
    if (g_pCatalog)
        g_pCatalog->deleteItem();
    else
        cout << "The catalogue class was not created!";
}

void call_findItem() {
    if (g_pCatalog)
        g_pCatalog->findItem();
    else
        cout << "The catalogue class was not created!";

}
void call_issueItem() {
    if (g_pCatalog)
        g_pCatalog->issueItem(g_pBank);
    else
        cout << "The catalogue class was not created!";
}

void call_updateReturned() {
    if (g_pCatalog)
        g_pCatalog->updateReturned();
    else
        cout << "The catalogue class was not created!";

}

void call_save() {
    if (g_pCatalog)
        g_pCatalog->saveData();
    else
        cout << "The catalogue class was not created!";
}

void call_read() {
    if (g_pCatalog)
        g_pCatalog->readData();
    else
        cout << "The catalogue class was not created!";
}

void call_help() {
    cout << "allowed commands: add, delete, find, issue, return, save, read, exit, help. To see more details, please enter a command below. To exit help, please enter exit." << endl;
    string command;
    while (true)
    {
        cin >> command;
        if (!command.compare("add"))
            cout << "Add an entry item to Catalogue, Here you have to enter details of entry." << endl;
        else if (!command.compare("delete"))
            cout << "Delete an entry item from Catalogue, Here you have to enter the serial number of the item." << endl;
        else if (!command.compare("find"))
            cout << "Find an entry item from Catalogue. You have to enter a serial number you are going to find." << endl;
        else if (!command.compare("issue"))
            cout << "Issue an entry item to member, Here you have to enter the serial number of the item and member number." << endl;
        else if (!command.compare("return"))
            cout << "Update an item of borrowed entry. Here you have to enter the serial number of the item." << endl;
        else if (!command.compare("save"))
            cout << "Save data of Catalogue." << endl;
        else if (!command.compare("read"))
            cout << "Read data from file." << endl;
        else if (!command.compare("exit"))
            cout << "Finish the application." << endl;
        else if (!command.compare("help"))
            cout << "Show available commands details." << endl;
        else if (!command.compare("exit"))
            break;
        else
            cout << "Please enter right command." << endl;
    }
}

int main()
{
    g_pCatalog = new Catalogue();
    g_pBank = new Bank();
    cout << "The functionalities of the app: add, delete, find, issue, return, save, read, exit, help; Please enter one of those commands." << endl;
    string command;
    while (true) {
        cin >> command;
        if (!command.compare("add"))
            call_addItem();
        else if (!command.compare("delete"))
            call_deleteItem();
        else if (!command.compare("find"))
            call_findItem();
        else if (!command.compare("issue"))
            call_issueItem();
        else if (!command.compare("return"))
            call_updateReturned();
        else if (!command.compare("save"))
            call_save();
        else if (!command.compare("read"))
            call_read();
        else if (!command.compare("exit"))
            break;
        else if (!command.compare("help"))
            call_help();
        else
            cout << "Please enter right command." << endl;
    }
    delete g_pCatalog;
    delete g_pBank;
}
