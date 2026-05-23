/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : June 15, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 4 Functions + main
==================================================================
*/

#include<iostream>

#include"../../HighlyUsedLibraries/MyInput.h"
#include"../../HighlyUsedLibraries/MyOutput.h"
#include"../../HighlyUsedLibraries/MyStringProcess.h"
#include"../SharedBankLogic/ClientsProcess.h"
#include"ATMMenues.h"
#include"ATMDataTypes.h"


using namespace std;

namespace ATMproject
{
    ATMDataTypes::sLogin Login;

    void RunLoginScreen()
    {
        MyOutput::RestScreen();

        MyOutput::PrintCard("Login", 70, MyStringProcess::Middle);


        string AccountNumber = MyInput::ReadString("\nPlease Enter your account number ? ");
        string PinCode = MyInput::ReadString("\nPlease Enter Pin Code ? ");


        while (!ClientsProcess::FindClientByAccountNumberAndPinCodeInVectorClients(Login.Clients.vClients, AccountNumber
            , PinCode, Login.CurrentClient))
        {
            MyInput::RestScreen();

            MyOutput::PrintCard("Login", 70, MyStringProcess::Middle);

            cout << "\a\n\nInvalid AccountNumber/PinCode" << endl << endl;

            AccountNumber = MyInput::ReadString("\nPlease Enter your account number ? "),
                PinCode = MyInput::ReadString("\nPlease Enter Pin Code ? ");
        }

        ATMMenues::RunMainMenueBody(Login);

        Login.KeepRunningMyBody = true;
    }

    void InitialisationOfLoginData()
    {
        Login.KeepRunningMyBody = true;

        Login.Clients.FileName = "Projects/BankData/Clients.txt";
        Login.Clients.Separator = "#//#";
        Login.Clients.vClients = ClientsProcess::LoadClients(Login.Clients.FileName, Login.Clients.Separator);



        Login.MainMenue.MyName = "ATM Main Menue";
        Login.MainMenue.NumberOfServices = 5;
        Login.MainMenue.ServicesNames_ORDRED.push_back("Quick Withdraw");
        Login.MainMenue.ServicesNames_ORDRED.push_back("Normal Withdraw");
        Login.MainMenue.ServicesNames_ORDRED.push_back("Deposit");
        Login.MainMenue.ServicesNames_ORDRED.push_back("Check Balance");
        Login.MainMenue.ServicesNames_ORDRED.push_back("Logout");



        Login.MainMenue.QuickWithdrawMenue.MyNumberInMenueCallMe = 1;
        Login.MainMenue.QuickWithdrawMenue.NumberOfAmounts = 9;
        Login.MainMenue.QuickWithdrawMenue.vAmounts.push_back("20");
        Login.MainMenue.QuickWithdrawMenue.vAmounts.push_back("50");
        Login.MainMenue.QuickWithdrawMenue.vAmounts.push_back("100");
        Login.MainMenue.QuickWithdrawMenue.vAmounts.push_back("200");
        Login.MainMenue.QuickWithdrawMenue.vAmounts.push_back("400");
        Login.MainMenue.QuickWithdrawMenue.vAmounts.push_back("600");
        Login.MainMenue.QuickWithdrawMenue.vAmounts.push_back("800");
        Login.MainMenue.QuickWithdrawMenue.vAmounts.push_back("1000");
        Login.MainMenue.QuickWithdrawMenue.vAmounts.push_back("Exit");


        Login.MainMenue.NormalWithDrawService.MyNumberInMenueCallMe = 2;

        Login.MainMenue.DepositService.MyNumberInMenueCallMe = 3;

        Login.MainMenue.CheckBalanceService.MyNumberInMenueCallMe = 4;



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