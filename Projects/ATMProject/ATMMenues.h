/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : June 15, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 5 Functions
==================================================================
*/

#pragma once

#include<iostream>
#include<vector>
#include<string>

#include"../../HighlyUsedLibraries/MyInput.h"
#include"../../HighlyUsedLibraries/MyOutput.h"
#include"ATMServices.h"
#include"ATMDataTypes.h"

using namespace std;



namespace ATMMenues
{
    void RunQuickWithdrawMenueScreen(ATMDataTypes::sLogin& Login)
    {
         
        MyOutput::RestScreen();
        MyOutput::PrintMenue(Login.MainMenue.ServicesNames_ORDRED[Login.MainMenue.QuickWithdrawMenue.MyNumberInMenueCallMe - 1]
            , Login.MainMenue.QuickWithdrawMenue.vAmounts, Login.MainMenue.QuickWithdrawMenue.NumberOfAmounts);


        MyOutput::PrintNumber("\nYour Balance is ", Login.CurrentClient.AccountBalance, "\n");


        short ClientChoice = MyInput::ReadNumberInRange((short)1, (short)Login.MainMenue.QuickWithdrawMenue.NumberOfAmounts
            , "Choose what you want to do ? [1 to " + to_string(Login.MainMenue.QuickWithdrawMenue.NumberOfAmounts) + "] ? ");


        if (ClientChoice == Login.MainMenue.QuickWithdrawMenue.NumberOfAmounts)
        {
            Login.MainMenue.QuickWithdrawMenue.KeepRunningMyBody = false;
            Login.MainMenue.KeepRunningMyBody = true;
        }
        else
        {
            if (MyInput::ReadYesOrNo("\n\nAre you sure you want to perform this transaction ? yes/no ? "))
            {
                if (ClientsProcess::AddToBalance(Login.CurrentClient,
                    -1 * stoi(Login.MainMenue.QuickWithdrawMenue.vAmounts[ClientChoice - 1])))
                {
                    ClientsProcess::UpdateClientInVectorClients(Login.Clients.vClients, Login.CurrentClient);
                    ClientsProcess::SaveClientsInFile(Login.Clients.FileName, Login.Clients.vClients, Login.Clients.Separator);

                    cout << "\nDone successfully, New balance is : " << Login.CurrentClient.AccountBalance;

                    Login.MainMenue.QuickWithdrawMenue.KeepRunningMyBody = false;
                    Login.MainMenue.KeepRunningMyBody = true;

                    MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.MyName + "...");
                }
                else
                {
                    Login.MainMenue.QuickWithdrawMenue.KeepRunningMyBody = true;

                    cout << "\n\nThe Amount exeeds your balance, make another choice." << endl;
                    MyOutput::SystemPause("\n\nPress any key to go back to Continue...");
                }
            }
            else
            {
                Login.MainMenue.QuickWithdrawMenue.KeepRunningMyBody = false;
                Login.MainMenue.KeepRunningMyBody = true;

                MyOutput::SystemPause("\n\nPress any key to go back to " + Login.MainMenue.MyName + "...");
            }
        }

    }

    void RunQuickWithdrawMenueBody(ATMDataTypes::sLogin& Login)
    {
        do
        {

            RunQuickWithdrawMenueScreen(Login);

        } while (Login.MainMenue.QuickWithdrawMenue.KeepRunningMyBody);
    }



    void SwitchServiceBodyChooseFromMain(ATMDataTypes::sLogin& Login, short& UserChoice)
    {

        if (UserChoice == Login.MainMenue.CheckBalanceService.MyNumberInMenueCallMe)
        {
            ATMServices::RunCheckBalanceServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.DepositService.MyNumberInMenueCallMe)
        {
            ATMServices::RunDepositServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.NormalWithDrawService.MyNumberInMenueCallMe)
        {
            ATMServices::RunNormalWithdrawServiceBody(Login);
        }
        else if (UserChoice == Login.MainMenue.QuickWithdrawMenue.MyNumberInMenueCallMe)
        {
            RunQuickWithdrawMenueBody(Login);
        }

    }

    void RunMainMenueScreen(ATMDataTypes::sLogin& Login)
    {

        MyOutput::RestScreen();

        MyOutput::PrintMenue(Login.MainMenue.MyName + " Screen", Login.MainMenue.ServicesNames_ORDRED, Login.MainMenue.NumberOfServices);


        short UserChoice = MyInput::ReadNumberInRange((short)1, (short)Login.MainMenue.NumberOfServices,
            "Choose what you want to do ? [1 to" + to_string(Login.MainMenue.NumberOfServices) + "] ? ");

        if (UserChoice == Login.MainMenue.NumberOfServices)
        {
            Login.MainMenue.KeepRunningMyBody = false;
        }
        else
        {
            SwitchServiceBodyChooseFromMain(Login, UserChoice);
        }

    }

    void RunMainMenueBody(ATMDataTypes::sLogin& Login)
    {

        do {

            RunMainMenueScreen(Login);

        } while (Login.MainMenue.KeepRunningMyBody);


    }

}