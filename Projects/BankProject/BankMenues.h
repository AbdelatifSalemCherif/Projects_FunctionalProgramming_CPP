/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : June 14, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 9 Functions
==================================================================
*/

#pragma once

#include<iostream>
#include<vector>

#include"../../HighlyUsedLibraries/MyOutput.h"
#include"../../HighlyUsedLibraries/MyInput.h"
#include"UsersProcess.h"
#include"BankServices.h"
#include"BankDataTypes.h"

using namespace std;

namespace BankMenues
{

    void SwitchServiceBodyChooseFromTransaction(BankDataTypes::sLogin& Login, short& UserChoice)
    {
        if (UserChoice == Login.MainMenue.TransactionMenue.DespositService.MyNumberInMenueCallMe)
        {
            BankServices::RunDespositServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.TransactionMenue.WithdrawService.MyNumberInMenueCallMe)
        {
            BankServices::RunWithdrawServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.TransactionMenue.TotalBalancesService.MyNumberInMenueCallMe)
        {
            BankServices::RunTotalBalancesServiceBody(Login);
        }

    }

    void RunTranactionMenueScreen(BankDataTypes::sLogin& Login)
    {
        MyInput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.TransactionMenue.MyLock, Login.CurrentUser.Key))
        {

            MyOutput::PrintMenue(Login.MainMenue.TransactionMenue.MyName + " Screen"
                , Login.MainMenue.TransactionMenue.ServicesNames_ORDRED, Login.MainMenue.TransactionMenue.NumberOfServices);


            short UserChoice = MyInput::ReadNumberInRange((short)1, (short)4, "\nChoose what you want to do ? [1 to 4] ? ");

            if (UserChoice == 4)
            {
                Login.MainMenue.TransactionMenue.KeepRunninMyBody = false;
                Login.MainMenue.KeepRunningMyBody = true;
            }
            else
            {
                SwitchServiceBodyChooseFromTransaction(Login, UserChoice);

            }

        }
        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();

            MyOutput::SystemPause("\nPress any Key to go back to " + Login.MainMenue.MyName + "...");

            Login.MainMenue.TransactionMenue.KeepRunninMyBody = false;
            Login.MainMenue.KeepRunningMyBody = true;
        }


    }

    void RunTransactionMenueBody(BankDataTypes::sLogin& Login)
    {
        do
        {

            RunTranactionMenueScreen(Login);

        } while (Login.MainMenue.TransactionMenue.KeepRunninMyBody);

    }






    void SwitchServiceBodyChooseFromManagerUsersMenue(BankDataTypes::sLogin& Login, short& UserChoice)
    {
        if (UserChoice == Login.MainMenue.ManagerUsersMenue.UsersListService.MyNumberInMenueCallMe)
        {
            BankServices::RunUsersListServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.ManagerUsersMenue.AddNewUserService.MyNumberInMenueCallMe)
        {
            BankServices::RunAddNewUserServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.ManagerUsersMenue.DeleteUserService.MyNumberInMenueCallMe)
        {
            BankServices::RunDeleteUserServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.ManagerUsersMenue.FindUserService.MyNumberInMenueCallMe)
        {
            BankServices::RunFindUserServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.ManagerUsersMenue.UpdateUserService.MyNumberInMenueCallMe)
        {
            BankServices::RunUpdateUserServiceBody(Login);
        }
    }

    void RunManagerUsersMenueScreen(BankDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        if (UsersProcess::DoesKeyOpenLock(Login.MainMenue.ManagerUsersMenue.MyLock, Login.CurrentUser.Key))
        {

            MyOutput::PrintMenue(Login.MainMenue.ManagerUsersMenue.MyName + " Screen"
                , Login.MainMenue.ManagerUsersMenue.ServicesNames_ORDRED, Login.MainMenue.ManagerUsersMenue.NumberOfServices);


            short UserChoice = MyInput::ReadNumberInRange((short)1, (short)6, "\nChoose what you want to do ? [1 to 6] ? ");

            if (UserChoice == 6)
            {
                Login.MainMenue.ManagerUsersMenue.KeepRunningMyBody = false;
                Login.MainMenue.KeepRunningMyBody = true;
            }
            else
            {
                SwitchServiceBodyChooseFromManagerUsersMenue(Login, UserChoice);
            }

        }
        else
        {
            UsersProcess::ShowUserHisKeyDidntOpenLock();

            MyOutput::SystemPause("\n\nPress any Key to go back to " + Login.MainMenue.MyName + "...");

            Login.MainMenue.ManagerUsersMenue.KeepRunningMyBody = false;
            Login.MainMenue.KeepRunningMyBody = true;

        }


    }

    void RunManagerUsersMenueBody(BankDataTypes::sLogin& Login)
    {
        do
        {
            RunManagerUsersMenueScreen(Login);

        } while (Login.MainMenue.ManagerUsersMenue.KeepRunningMyBody);
    }





    void SwitchServiceBodyChooseFromMain(BankDataTypes::sLogin& Login, short& UserChoice)
    {

        if (UserChoice == Login.MainMenue.ClientListService.MyNumberInMenueCallMe)
        {
            BankServices::RunClientsListServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.AddNewClientService.MyNumberInMenueCallMe)
        {
            BankServices::RunAddNewClientServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.DeleteClientService.MyNumberInMenueCallMe)
        {
            BankServices::RunDeleteClientServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.FindClientService.MyNumberInMenueCallMe)
        {
            BankServices::RunFindClientServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.ManagerUsersMenue.MyNumberInMenueCallMe)
        {
            RunManagerUsersMenueBody(Login);
        }
        else if (UserChoice == Login.MainMenue.TransactionMenue.MyNumberInMenueCallMe)
        {
            RunTransactionMenueBody(Login);
        }
        else if (UserChoice == Login.MainMenue.UpdateClientService.MyNumberInMenueCallMe)
        {
            BankServices::RunUpdateClientServiceBody(Login);
        }
    }

    void RunMainMenueScreen(BankDataTypes::sLogin& Login)
    {

        MyOutput::RestScreen();

        MyOutput::PrintMenue(Login.MainMenue.MyName + " Screen", Login.MainMenue.ServicesNames_ORDRED
            , Login.MainMenue.NumberOfServices);


        short UserChoice = MyInput::ReadNumberInRange((short)1, (short)8, "Choose what you want to do ? [1 to 8] ? ");

        if (UserChoice == 8)
        {
            Login.MainMenue.KeepRunningMyBody = false;
        }
        else
        {
            SwitchServiceBodyChooseFromMain(Login, UserChoice);
        }

    }

    void RunMainMenueBody(BankDataTypes::sLogin& Login)
    {

        do {

            RunMainMenueScreen(Login);

        } while (Login.MainMenue.KeepRunningMyBody);


    }

}