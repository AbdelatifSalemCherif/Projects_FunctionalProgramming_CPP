/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : June 14, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 5 Functions
==================================================================
*/

#include<iostream>

#include"../../HighlyUsedLibraries/MyInput.h"
#include"../../HighlyUsedLibraries/MyOutput.h"
#include"../../HighlyUsedLibraries/MyStringProcess.h"
#include"../SharedBankLogic/ClientsProcess.h"
#include"UsersProcess.h"
#include"BankMenues.h"
#include"BankDataTypes.h"


using namespace std;

namespace BankProject
{
    BankDataTypes::sLogin Login;

    void RunLoginScreen()
    {
        MyOutput::RestScreen();

        MyOutput::PrintCard("Login", 70, MyStringProcess::Middle);


        string UserName = MyInput::ReadString("\nPlease Enter User Name ? "),
            Password = MyInput::ReadString("\nPlease Enter Password ? ");



        while (!UsersProcess::FindUserByUserNameAndPassword(Login.Users.vUsers, UserName, Password, Login.CurrentUser))
        {
            MyInput::RestScreen();

            MyOutput::PrintCard("Login", 70, MyStringProcess::Middle);

            cout << "\a\n\nInvalid UserName/Password" << endl << endl;

            UserName = MyInput::ReadString("\nPlease Enter User Name ? ");
            Password = MyInput::ReadString("\nPlease Enter Password ? ");
        }

        BankMenues::RunMainMenueBody(Login);

        Login.KeepRunningMyBody = true;
    }

    void InitialisationOfLoginData()
    {

        Login.KeepRunningMyBody = true;



        Login.Clients.FileName = "Projects/BankData/Clients.txt";
        Login.Clients.Separator = "#//#";
        Login.Clients.vClients = ClientsProcess::LoadClients(Login.Clients.FileName, Login.Clients.Separator);


        Login.Users.FileName = "Projects/BankData/Users.txt";
        Login.Users.Separator = "#//#";
        Login.Users.vUsers = UsersProcess::LoadUsers(Login.Users.FileName, Login.Users.Separator);


        Login.MainMenue.MyName = "Main Menu";


        Login.MainMenue.NumberOfServices = 8;

        Login.MainMenue.ServicesNames_ORDRED.push_back("Client List");
        Login.MainMenue.ServicesNames_ORDRED.push_back("Add New Client");
        Login.MainMenue.ServicesNames_ORDRED.push_back("Delete Client");
        Login.MainMenue.ServicesNames_ORDRED.push_back("Update Client");
        Login.MainMenue.ServicesNames_ORDRED.push_back("Find Client");
        Login.MainMenue.ServicesNames_ORDRED.push_back("Transaction Menue");
        Login.MainMenue.ServicesNames_ORDRED.push_back("Manager Users Menue");
        Login.MainMenue.ServicesNames_ORDRED.push_back("Logout");


        Login.MainMenue.ClientListService.MyName = "Client List";
        Login.MainMenue.ClientListService.MyLock = 1;
        Login.MainMenue.ClientListService.MyNumberInMenueCallMe = 1;


        Login.MainMenue.AddNewClientService.MyName = "Add New Client";
        Login.MainMenue.AddNewClientService.MyLock = 2;
        Login.MainMenue.AddNewClientService.MyNumberInMenueCallMe = 2;


        Login.MainMenue.DeleteClientService.MyName = "Delete Client";
        Login.MainMenue.DeleteClientService.MyLock = 4;
        Login.MainMenue.DeleteClientService.MyNumberInMenueCallMe = 3;


        Login.MainMenue.UpdateClientService.MyName = "Update Client";
        Login.MainMenue.UpdateClientService.MyLock = 8;
        Login.MainMenue.UpdateClientService.MyNumberInMenueCallMe = 4;


        Login.MainMenue.FindClientService.MyName = "Find Client";
        Login.MainMenue.FindClientService.MyLock = 16;
        Login.MainMenue.FindClientService.MyNumberInMenueCallMe = 5;







        Login.MainMenue.TransactionMenue.MyName = "Transaction Menue";
        Login.MainMenue.TransactionMenue.MyLock = 32;
        Login.MainMenue.TransactionMenue.MyNumberInMenueCallMe = 6;

        Login.MainMenue.TransactionMenue.NumberOfServices = 4;
        Login.MainMenue.TransactionMenue.ServicesNames_ORDRED.push_back("Desposit");
        Login.MainMenue.TransactionMenue.ServicesNames_ORDRED.push_back("Withdraw");
        Login.MainMenue.TransactionMenue.ServicesNames_ORDRED.push_back("Total Balances");
        Login.MainMenue.TransactionMenue.ServicesNames_ORDRED.push_back("Main Menue");



        Login.MainMenue.TransactionMenue.DespositService.MyName = "Desposit";
        Login.MainMenue.TransactionMenue.DespositService.MyNumberInMenueCallMe = 1;


        Login.MainMenue.TransactionMenue.WithdrawService.MyName = "Withdraw";
        Login.MainMenue.TransactionMenue.WithdrawService.MyNumberInMenueCallMe = 2;


        Login.MainMenue.TransactionMenue.TotalBalancesService.MyName = "Total Balances";
        Login.MainMenue.TransactionMenue.TotalBalancesService.MyNumberInMenueCallMe = 3;







        Login.MainMenue.ManagerUsersMenue.MyName = "Manager Users Menue";
        Login.MainMenue.ManagerUsersMenue.MyLock = 64;
        Login.MainMenue.ManagerUsersMenue.MyNumberInMenueCallMe = 7;

        Login.MainMenue.ManagerUsersMenue.NumberOfServices = 6;
        Login.MainMenue.ManagerUsersMenue.ServicesNames_ORDRED.push_back("Users List");
        Login.MainMenue.ManagerUsersMenue.ServicesNames_ORDRED.push_back("Add New User");
        Login.MainMenue.ManagerUsersMenue.ServicesNames_ORDRED.push_back("Delete User");
        Login.MainMenue.ManagerUsersMenue.ServicesNames_ORDRED.push_back("Update User");
        Login.MainMenue.ManagerUsersMenue.ServicesNames_ORDRED.push_back("Find User");
        Login.MainMenue.ManagerUsersMenue.ServicesNames_ORDRED.push_back("Main Menue");

        Login.MainMenue.ManagerUsersMenue.UsersListService.MyName = "Users List";
        Login.MainMenue.ManagerUsersMenue.UsersListService.MyNumberInMenueCallMe = 1;


        Login.MainMenue.ManagerUsersMenue.AddNewUserService.MyName = "Add New User";
        Login.MainMenue.ManagerUsersMenue.AddNewUserService.MyNumberInMenueCallMe = 2;

        Login.MainMenue.ManagerUsersMenue.DeleteUserService.MyName = "Delete User";
        Login.MainMenue.ManagerUsersMenue.DeleteUserService.MyNumberInMenueCallMe = 3;

        Login.MainMenue.ManagerUsersMenue.UpdateUserService.MyName = "Update User";
        Login.MainMenue.ManagerUsersMenue.UpdateUserService.MyNumberInMenueCallMe = 4;

        Login.MainMenue.ManagerUsersMenue.FindUserService.MyName = "Find User";
        Login.MainMenue.ManagerUsersMenue.FindUserService.MyNumberInMenueCallMe = 5;




        UsersProcess::sUser Admin;

        Admin.UserName = "Admin";
        Admin.PassWord = "1234";
        Admin.Key = -1;
        Admin.MarkDelete = false;

        if (!UsersProcess::IsUserExist(Login.Users.vUsers, Admin))
        {
            Login.Users.vUsers.push_back(Admin);

            UsersProcess::SaveUsersInFile(Login.Users.FileName, Login.Users.vUsers, Login.Users.Separator);
        }

    }

    void RunLoginBody()
    {

        InitialisationOfLoginData();

        do {

            RunLoginScreen();

        } while (Login.KeepRunningMyBody);
    }

    void BankProgram()
    {

        RunLoginBody();

    }

    void Run()
    {

        BankProgram();

    }
}