/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : June 14, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 0 Functions
==================================================================
*/

#pragma once

#include<iostream>
#include<vector>

#include"UsersProcess.h"
#include"../SharedBankLogic/ClientsProcess.h"

using namespace std;

namespace BankDataTypes
{

    struct sClients
    {
        vector <ClientsProcess::sClient> vClients;

        string FileName;
        string Separator;
    };

    struct sUsers
    {
        vector<UsersProcess::sUser> vUsers;

        string FileName;
        string Separator;
    };

    struct sService
    {
        string MyName;
        short MyLock = 0;
        short MyNumberInMenueCallMe;

        bool KeepRunningMyBody = false;
    };

    struct sManagerUesersMenue
    {
        string MyName;
        short MyLock;

        sService UsersListService;
        sService DeleteUserService;
        sService UpdateUserService;
        sService AddNewUserService;
        sService FindUserService;

        vector <string> ServicesNames_ORDRED;

        short NumberOfServices;

        short MyNumberInMenueCallMe;

        bool KeepRunningMyBody = false;
    };

    struct sTransactionMenue
    {
        string MyName;
        short MyLock;

        sService DespositService;
        sService WithdrawService;
        sService TotalBalancesService;

        vector <string> ServicesNames_ORDRED;

        short NumberOfServices;

        short MyNumberInMenueCallMe;

        bool KeepRunninMyBody = false;
    };

    struct sMainMenue
    {
        string MyName;

        sTransactionMenue TransactionMenue;
        sManagerUesersMenue ManagerUsersMenue;

        sService ClientListService;
        sService AddNewClientService;
        sService DeleteClientService;
        sService UpdateClientService;
        sService FindClientService;

        vector <string> ServicesNames_ORDRED;

        short NumberOfServices;

        bool KeepRunningMyBody = false;
    };

    struct sLogin
    {
        UsersProcess::sUser CurrentUser;

        sUsers Users;
        sClients Clients;

        sMainMenue MainMenue;

        bool KeepRunningMyBody = true;
    };

}