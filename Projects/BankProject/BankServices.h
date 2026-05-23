/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : June 14, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 26 Functions
==================================================================
*/

#pragma once

#include<iostream>

#include"../../HighlyUsedLibraries/MyInput.h"
#include"../../HighlyUsedLibraries/MyOutput.h"
#include"UsersProcess.h"
#include"../SharedBankLogic/ClientsProcess.h"
#include"../../HighlyUsedLibraries/MyStringProcess.h"
#include"BankMenues.h"
#include"BankDataTypes.h"

using namespace std;

namespace BankServices
{

    void RunClientsListServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyInput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.ClientListService.MyLock, Login.CurrentUser.Key))
        {
            ClientsProcess::PrintClientsList(Login.Clients.vClients);
        }
        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.MyName + "...");

        Login.MainMenue.KeepRunningMyBody = true;
        Login.MainMenue.ClientListService.KeepRunningMyBody = false;

    }

    void RunClientsListServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {
            RunClientsListServiceScreen(Login);

        } while (Login.MainMenue.ClientListService.KeepRunningMyBody);
    }





    void RunAddNewClientServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.AddNewClientService.MyLock, Login.CurrentUser.Key))
        {
            string AccountNumber;
            ClientsProcess::sClient Client;

            do {

                MyOutput::PrintCard(Login.MainMenue.AddNewClientService.MyName, 70, MyStringProcess::enLeftRightMiddle::Middle);


                AccountNumber = MyInput::ReadString("\nEnter Account Number ? ");

                while (ClientsProcess::IsClientExist(AccountNumber, Login.Clients.vClients))
                {
                    AccountNumber = MyInput::ReadString("\nClient with [" + AccountNumber
                        + "] already exists, Enter another Account Number ? ");
                }


                Client = ClientsProcess::ReadClient("\n\nAdding new client :\n", AccountNumber);

                ClientsProcess::AddStringClientToFile(Login.Clients.FileName,
                    ClientsProcess::ConvertClientToStringClient(Client, Login.Clients.Separator));

            } while (MyInput::ReadYesOrNo("Client Added Successfully, do you want to add more clients ? (yes or no) ? "));

        }
        else
        {

            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.MyName + "...");

        Login.MainMenue.KeepRunningMyBody = true;
        Login.MainMenue.AddNewClientService.KeepRunningMyBody = false;
    }

    void RunAddNewClientServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {
            RunAddNewClientServiceScreen(Login);
        } while (Login.MainMenue.AddNewClientService.KeepRunningMyBody);

    }





    void RunDeleteClientServiceScreen(BankDataTypes::sLogin& Login)
    {

        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.DeleteClientService.MyLock, Login.CurrentUser.Key))
        {
            string AccountNumber = MyInput::ReadString("\nEnter Account Number ? ");
            ClientsProcess::sClient Client;


            MyOutput::PrintCard(Login.MainMenue.AddNewClientService.MyName, 70, MyStringProcess::enLeftRightMiddle::Middle);

            if (ClientsProcess::FindClientByAccountNumberInVectorClients(Login.Clients.vClients, AccountNumber, Client))
            {
                ClientsProcess::PrintClientCard(Client, "\nThe following are the client details :\n");

                if (MyInput::ReadYesOrNo("\nAre you sure you want delete this client ? yes/no ? "))
                {
                    ClientsProcess::DeleteClientInFile(Login.Clients.FileName, Login.Clients.vClients, AccountNumber
                        , Login.Clients.Separator);

                    cout << "\nClient Deletes successfully" << endl;

                }
            }
            else
            {

                cout << "Client with Account Number (" << AccountNumber << ") Not Found !" << endl;
            }

        }
        else
        {

            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.MyName + "...");

        Login.MainMenue.KeepRunningMyBody = true;
        Login.MainMenue.DeleteClientService.KeepRunningMyBody = false;

    }

    void RunDeleteClientServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {
            RunDeleteClientServiceScreen(Login);

        } while (Login.MainMenue.DeleteClientService.KeepRunningMyBody);
    }




    void RunUpdateClientServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.UpdateClientService.MyLock, Login.CurrentUser.Key))
        {
            string AccountNumber = MyInput::ReadString("Please enter account number ? ");
            ClientsProcess::sClient Client;

            MyOutput::PrintCard(Login.MainMenue.UpdateClientService.MyName + " Screen", 70, MyStringProcess::Middle);

            if (ClientsProcess::FindClientByAccountNumberInVectorClients(Login.Clients.vClients, AccountNumber, Client))
            {
                ClientsProcess::PrintClientCard(Client, "\nThe following are the client details :\n");

                if (MyInput::ReadYesOrNo("\nAre you sure you want update this client ? yes/no ? "))
                {
                    ClientsProcess::UpdateClientInFile(Login.Clients.FileName, Login.Clients.vClients
                        , AccountNumber, Login.Clients.Separator);

                    cout << "\nClient Apdated successfully" << endl;
                }


            }
            else
            {
                cout << "Client with Account Number (" << AccountNumber << ") Not Found !" << endl;
            }

        }

        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }


        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.MyName + "...");

        Login.MainMenue.UpdateClientService.KeepRunningMyBody = false;
        Login.MainMenue.KeepRunningMyBody = true;
    }

    void RunUpdateClientServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {

            RunUpdateClientServiceScreen(Login);

        } while (Login.MainMenue.UpdateClientService.KeepRunningMyBody);
    }





    void RunFindClientServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.FindClientService.MyLock, Login.CurrentUser.Key))
        {

            string AccountNumber = MyInput::ReadString("Please enter account number ? ");

            ClientsProcess::sClient Client;

            if (ClientsProcess::FindClientByAccountNumberInVectorClients(Login.Clients.vClients, AccountNumber, Client))
            {
                ClientsProcess::PrintClientCard(Client, "\nThe following are the client details :\n");
            }
            else
            {
                cout << "Client with Account Number (" << AccountNumber << ") Not Found !" << endl;
            }

        }
        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to back to " + Login.MainMenue.MyName + "...");

        Login.MainMenue.FindClientService.KeepRunningMyBody = false;
        Login.MainMenue.KeepRunningMyBody = true;


    }

    void RunFindClientServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {

            RunFindClientServiceScreen(Login);

        } while (Login.MainMenue.FindClientService.KeepRunningMyBody);
    }




    void RunDespositServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.TransactionMenue.DespositService.MyLock, Login.CurrentUser.Key))
        {
            MyOutput::PrintCard(Login.MainMenue.TransactionMenue.DespositService.MyName + " Screen", 70, MyStringProcess::Middle);

            string AcountNumber = MyInput::ReadString("\nPlease enter Account Number ? ");

            ClientsProcess::sClient Client;

            while (!ClientsProcess::FindClientByAccountNumberInVectorClients(Login.Clients.vClients, AcountNumber, Client))
            {
                AcountNumber = MyInput::ReadString("\nPlease enter Account Number ? ");
            }

            ClientsProcess::PrintClientCard(Client, "\nThe Following are the client details :\n");

            float Amount = MyInput::ReadPositiveNumber((float)0, "\nPlease enter disposit amount ? ");

            if (MyInput::ReadYesOrNo("\nAre you sure you want perform this transaction ? (yes/no)? "))
            {
                ClientsProcess::AddToBalance(Client, Amount);

                ClientsProcess::UpdateClientInVectorClients(Login.Clients.vClients, Client);
                ClientsProcess::SaveClientsInFile(Login.Clients.FileName, Login.Clients.vClients, Login.Clients.Separator);

                cout << "\nDesposit successfully, New Balance is " << Client.AccountBalance << endl;
            }
        }
        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.TransactionMenue.MyName + "...");

        Login.MainMenue.TransactionMenue.DespositService.KeepRunningMyBody = false;
        Login.MainMenue.TransactionMenue.KeepRunninMyBody = true;


    }

    void RunDespositServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {

            RunDespositServiceScreen(Login);

        } while (Login.MainMenue.TransactionMenue.DespositService.KeepRunningMyBody);
    }




    void RunWithdrawServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.TransactionMenue.WithdrawService.MyLock, Login.CurrentUser.Key))
        {
            MyOutput::PrintCard(Login.MainMenue.TransactionMenue.WithdrawService.MyName + " Screen", 70, MyStringProcess::Middle);

            string AcountNumber = MyInput::ReadString("\nPlease enter Account Number ? ");

            ClientsProcess::sClient Client;

            while (!ClientsProcess::FindClientByAccountNumberInVectorClients(Login.Clients.vClients, AcountNumber, Client))
            {
                AcountNumber = MyInput::ReadString("\nPlease enter Account Number ? ");
            }

            ClientsProcess::PrintClientCard(Client, "\nThe Following are the client details :\n");

            float Amount = MyInput::ReadPositiveNumber((float)0, "\nPlease enter disposit amount ? ");

            if (MyInput::ReadYesOrNo("\nAre you sure you want perform this transaction ? (yes/no)? "))
            {
                if (ClientsProcess::AddToBalance(Client, Amount * (-1)))
                {

                    ClientsProcess::UpdateClientInVectorClients(Login.Clients.vClients, Client);
                    ClientsProcess::SaveClientsInFile(Login.Clients.FileName, Login.Clients.vClients, Login.Clients.Separator);

                    cout << "\nWithdraw successfully, New Balance is " << Client.AccountBalance << endl;
                }
                else
                {
                    cout << "\nAmount Exeeds the balance, you can\'t whithdraw up to : " << Client.AccountBalance << endl;
                }
            }

        }
        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.TransactionMenue.MyName + "...");

        Login.MainMenue.TransactionMenue.WithdrawService.KeepRunningMyBody = false;
        Login.MainMenue.TransactionMenue.KeepRunninMyBody = true;

    }

    void RunWithdrawServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {

            RunWithdrawServiceScreen(Login);

        } while (Login.MainMenue.TransactionMenue.WithdrawService.KeepRunningMyBody);
    }




    void RunTotalBalancesServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.TransactionMenue.TotalBalancesService.MyLock, Login.CurrentUser.Key))
        {
            ClientsProcess::ShowTotalBalaceTable(Login.Clients.vClients);

        }
        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.TransactionMenue.MyName + "...");

        Login.MainMenue.TransactionMenue.TotalBalancesService.KeepRunningMyBody = false;
        Login.MainMenue.TransactionMenue.KeepRunninMyBody = true;

    }

    void RunTotalBalancesServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {

            RunTotalBalancesServiceScreen(Login);

        } while (Login.MainMenue.TransactionMenue.TotalBalancesService.KeepRunningMyBody);
    }




    void RunUsersListServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.ManagerUsersMenue.UsersListService.MyLock, Login.CurrentUser.Key))
        {
            UsersProcess::PrintUsersList(Login.Users.vUsers);
        }
        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.ManagerUsersMenue.MyName + "...");

        Login.MainMenue.ManagerUsersMenue.UsersListService.KeepRunningMyBody = false;
        Login.MainMenue.ManagerUsersMenue.KeepRunningMyBody = true;


    }

    void RunUsersListServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {

            RunUsersListServiceScreen(Login);

        } while (Login.MainMenue.ManagerUsersMenue.UsersListService.KeepRunningMyBody);
    }




    void RunAddNewUserServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.ManagerUsersMenue.AddNewUserService.MyLock, Login.CurrentUser.Key))
        {
            MyOutput::PrintCard(Login.MainMenue.ManagerUsersMenue.AddNewUserService.MyName + " Screen", 70
                , MyStringProcess::Middle);

            string UserName = MyInput::ReadString("\nAdding New User :\nPlease enter User Name ? ");

            UsersProcess::sUser User;

            while (UsersProcess::IsUserExist(UserName, Login.Users.vUsers))
            {
                cout << "\a\n\nUser with [" << UserName << "] already exists";
                UserName = MyInput::ReadString("\nEnter another User Name ? ");
            }

            vector <short> Loks;

            Loks.push_back(1);
            Loks.push_back(2);
            Loks.push_back(4);
            Loks.push_back(8);
            Loks.push_back(16);
            Loks.push_back(32);
            Loks.push_back(64);

            User = UsersProcess::ReadNewUser(Login.MainMenue.ServicesNames_ORDRED, Login.MainMenue.NumberOfServices - 1, Loks,
                "", UserName);

            Login.Users.vUsers.push_back(User);

            UsersProcess::SaveUsersInFile(Login.Users.FileName, Login.Users.vUsers, Login.Users.Separator);

        }

        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.ManagerUsersMenue.MyName + "...");

        Login.MainMenue.ManagerUsersMenue.AddNewUserService.KeepRunningMyBody = false;
        Login.MainMenue.ManagerUsersMenue.KeepRunningMyBody = true;

    }

    void RunAddNewUserServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {

            RunAddNewUserServiceScreen(Login);

        } while (Login.MainMenue.ManagerUsersMenue.AddNewUserService.KeepRunningMyBody);
    }





    void RunDeleteUserServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.ManagerUsersMenue.DeleteUserService.MyLock, Login.CurrentUser.Key))
        {
            MyOutput::PrintCard(Login.MainMenue.ManagerUsersMenue.DeleteUserService.MyName + " Screen", 70
                , MyStringProcess::Middle);

            string UserName = MyInput::ReadString("\nPlease enter User Name ? ");

            UsersProcess::sUser User;

            if (UsersProcess::FindUserByUserName(Login.Users.vUsers, UserName, User))
            {
                UsersProcess::PrintUserCard(User, "\n\nthe following are the user details :\n");

                if (MyInput::ReadYesOrNo("\nare you sure you want delete this user ? yes/no ? "))
                {
                    if (UsersProcess::DeleteUserInFile(Login.Users.FileName, Login.Users.vUsers, UserName, Login.Users.Separator))
                    {
                        cout << "\nUser Deleted Duccessfully.";
                    }
                    else
                    {
                        cout << "\a\n\nYou cannot Delete Thehis User.";
                    }
                }

            }

        }
        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.ManagerUsersMenue.MyName + "...");

        Login.MainMenue.ManagerUsersMenue.DeleteUserService.KeepRunningMyBody = false;
        Login.MainMenue.ManagerUsersMenue.KeepRunningMyBody = true;
    }

    void RunDeleteUserServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {

            RunDeleteUserServiceScreen(Login);

        } while (Login.MainMenue.ManagerUsersMenue.DeleteUserService.KeepRunningMyBody);
    }




    void RunUpdateUserServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.ManagerUsersMenue.UpdateUserService.MyLock, Login.CurrentUser.Key))
        {
            MyOutput::PrintCard(Login.MainMenue.ManagerUsersMenue.UpdateUserService.MyName + " Screen", 70
                , MyStringProcess::Middle);

            string UserName = MyInput::ReadString("\nPlease enter User Name ? ");

            UsersProcess::sUser User;

            if (UsersProcess::FindUserByUserName(Login.Users.vUsers, UserName, User))
            {
                UsersProcess::PrintUserCard(User, "\nThe following are the User details :\n");

                if (MyInput::ReadYesOrNo("\nAre you sure you want update this User ? yes/no ? "))
                {
                    vector <short> Locks;

                    Locks.push_back(1);
                    Locks.push_back(2);
                    Locks.push_back(4);
                    Locks.push_back(8);
                    Locks.push_back(16);
                    Locks.push_back(32);
                    Locks.push_back(64);

                    UsersProcess::UpdateUserInFile("\n\n", Login.Users.FileName, Login.Users.vUsers, UserName
                        , Login.Users.Separator, Login.MainMenue.ServicesNames_ORDRED, Login.MainMenue.NumberOfServices - 1
                        , Locks);

                    cout << "\nUser updated successfully" << endl;

                }
            }
            else
            {
                cout << "User with User Name (" << UserName << ") Not Found !" << endl;
            }

        }
        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.ManagerUsersMenue.MyName + "...");

        Login.MainMenue.ManagerUsersMenue.UpdateUserService.KeepRunningMyBody = false;
        Login.MainMenue.ManagerUsersMenue.KeepRunningMyBody = true;
    }


    void RunUpdateUserServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {

            RunUpdateUserServiceScreen(Login);

        } while (Login.MainMenue.ManagerUsersMenue.UpdateUserService.KeepRunningMyBody);
    }





    void RunFindUserServiceScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.ManagerUsersMenue.FindUserService.MyLock, Login.CurrentUser.Key))
        {
            string UserName = MyInput::ReadString("Please enter User Name ? ");

            UsersProcess::sUser User;


            if (UsersProcess::FindUserByUserName(Login.Users.vUsers, UserName, User))
            {
                UsersProcess::PrintUserCard(User, "\nThe following are the User details :\n");
            }
            else
            {
                cout << "User with User Name (" << UserName << ") Not Found !" << endl;
            }

        }
        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();
        }

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.ManagerUsersMenue.MyName + "...");

        Login.MainMenue.ManagerUsersMenue.FindUserService.KeepRunningMyBody = false;
        Login.MainMenue.ManagerUsersMenue.KeepRunningMyBody = true;

    }

    void RunFindUserServiceBody(BankDataTypes::sLogin& Login)
    {
        do
        {

            RunFindUserServiceScreen(Login);

        } while (Login.MainMenue.ManagerUsersMenue.FindUserService.KeepRunningMyBody);
    }




}