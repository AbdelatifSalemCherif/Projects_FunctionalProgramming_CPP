/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : June 15, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 0 Functions
==================================================================
*/

#pragma once

#include<iostream>
#include<vector>

#include"../SharedBankLogic/ClientsProcess.h"

using namespace std;

namespace ATMDataTypes
{

    struct sClients
    {
        vector <ClientsProcess::sClient> vClients;

        string FileName;
        string Separator;
    };

    struct sService
    {
        short MyNumberInMenueCallMe;

        bool KeepRunningMyBody = false;
    };

    struct sQuickWithdrawMenue
    {
        vector <string> vAmounts;

        short NumberOfAmounts;

        short MyNumberInMenueCallMe;

        bool KeepRunningMyBody = false;
    };

    struct sMainMenue
    {
        string MyName;

        sQuickWithdrawMenue QuickWithdrawMenue;
        sService NormalWithDrawService;
        sService DepositService;
        sService CheckBalanceService;

        vector <string> ServicesNames_ORDRED;

        short NumberOfServices;

        bool KeepRunningMyBody = false;
    };

    struct sLogin
    {
        ClientsProcess::sClient CurrentClient;

        sClients Clients;

        sMainMenue MainMenue;

        bool KeepRunningMyBody = true;
    };

}