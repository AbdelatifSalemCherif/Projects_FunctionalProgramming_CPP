/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : June 15, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 6 Functions
==================================================================
*/

#pragma once

#include<iostream>

#include"../../HighlyUsedLibraries/MyInput.h"
#include"../../HighlyUsedLibraries/MyOutput.h"
#include"../SharedBankLogic/ClientsProcess.h"
#include"ATMDataTypes.h"

using namespace std;

namespace ATMServices
{
    void RunCheckBalanceServiceScreen(ATMDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        MyOutput::PrintCard(Login.MainMenue.ServicesNames_ORDRED[Login.MainMenue.CheckBalanceService.MyNumberInMenueCallMe - 1],
            70, MyStringProcess::Middle);

        cout << "\nYour Balace is " << Login.CurrentClient.AccountBalance;

        Login.MainMenue.CheckBalanceService.KeepRunningMyBody = false;
        Login.MainMenue.KeepRunningMyBody = true;

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.MyName + "...");

    }

    void RunCheckBalanceServiceBody(ATMDataTypes::sLogin& Login)
    {
        do
        {

            RunCheckBalanceServiceScreen(Login);

        } while (Login.MainMenue.CheckBalanceService.KeepRunningMyBody);
    }



    void RunDepositServiceScreen(ATMDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        MyOutput::PrintCard(Login.MainMenue.ServicesNames_ORDRED[Login.MainMenue.DepositService.MyNumberInMenueCallMe - 1],
            70, MyStringProcess::Middle);

        int Amount = MyInput::ReadNumbreMultipleOf((int)5, "\nEnter amount multiple of \'5 ? ");

        if (MyInput::ReadYesOrNo("\n\nAre you sure you want to perform this transaction ? yes/no ? "))
        {
            ClientsProcess::AddToBalance(Login.CurrentClient, Amount);
            ClientsProcess::UpdateClientInVectorClients(Login.Clients.vClients, Login.CurrentClient);
            ClientsProcess::SaveClientsInFile(Login.Clients.FileName, Login.Clients.vClients, Login.Clients.Separator);
        }

        Login.MainMenue.DepositService.KeepRunningMyBody = false;
        Login.MainMenue.KeepRunningMyBody = true;

        MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.MyName + "...");

    }

    void RunDepositServiceBody(ATMDataTypes::sLogin& Login)
    {
        do
        {

            RunDepositServiceScreen(Login);

        } while (Login.MainMenue.DepositService.KeepRunningMyBody);
    }




    void RunNormalWithdrawServiceScreen(ATMDataTypes::sLogin& Login)
    {
        MyOutput::RestScreen();

        MyOutput::PrintCard(Login.MainMenue.ServicesNames_ORDRED[Login.MainMenue.NormalWithDrawService.MyNumberInMenueCallMe - 1]
            , 70, MyStringProcess::Middle);

        int Amount = MyInput::ReadNumbreMultipleOf((int)5, "\nEnter an amount multiple of \'5 ? ");

        if (MyInput::ReadYesOrNo("\n\nAre you sure you want to perform this transaction ? yes/no ? "))
        {
            if (ClientsProcess::AddToBalance(Login.CurrentClient, Amount * -1))
            {
                ClientsProcess::UpdateClientInVectorClients(Login.Clients.vClients, Login.CurrentClient);
                ClientsProcess::SaveClientsInFile(Login.Clients.FileName, Login.Clients.vClients, Login.Clients.Separator);

                cout << "\nDone successfully, New balance is : " << Login.CurrentClient.AccountBalance;

                Login.MainMenue.NormalWithDrawService.KeepRunningMyBody = false;
                Login.MainMenue.KeepRunningMyBody = true;

                MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.MyName + "...");
            }
            else
            {
                Login.MainMenue.NormalWithDrawService.KeepRunningMyBody = true;

                cout << "\n\nThe Amount exeeds your balance, make another choice." << endl;
                MyOutput::SystemPause("\n\nPress any key to go back to Continue...");
            }
        }
        else
        {
            Login.MainMenue.NormalWithDrawService.KeepRunningMyBody = false;
            Login.MainMenue.KeepRunningMyBody = true;

            MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.MyName + "...");
        }

    }

    void RunNormalWithdrawServiceBody(ATMDataTypes::sLogin& Login)
    {
        do
        {

            RunNormalWithdrawServiceScreen(Login);

        } while (Login.MainMenue.NormalWithDrawService.KeepRunningMyBody);
    }

}