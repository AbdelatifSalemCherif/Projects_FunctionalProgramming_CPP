/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : June 15, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 21 Functions
==================================================================
*/

#pragma once

#include<iostream>
#include<vector>
#include<fstream>

#include"../../HighlyUsedLibraries/MyInput.h"
#include"../../HighlyUsedLibraries/MyOutput.h"
#include"../../HighlyUsedLibraries/MyStringProcess.h"

using namespace std;

namespace ClientsProcess
{
    struct sClient
    {
        string AccountNumber;
        string PinCode;
        string Name;
        string Phone;
        float AccountBalance = 0;

        bool MarkDelete = false;
    };


    inline vector <string> LoadClientsFromFileToVectorString(string FileName)
    {
        vector <string> vStringClients;

        fstream File;

        File.open(FileName, ios::in);

        if (File.is_open())
        {
            string StringClient = "";

            while (getline(File, StringClient))
            {

                if (StringClient != "" && StringClient != " ")
                {
                    vStringClients.push_back(StringClient);
                }
            }

            File.close();

        }

        return vStringClients;
    }

    inline sClient ConvertStringClientToClient(string StringClient, string Separator = "#//#")
    {
        sClient Client;

        vector <string> vClients = MyStringProcess::SplitStringToVector(StringClient, Separator);

        Client.AccountNumber = vClients[0];

        Client.PinCode = vClients[1];

        Client.Name = vClients[2];

        Client.Phone = vClients[3];

        Client.AccountBalance = stof(vClients[4]);


        return Client;
    }

    inline vector <sClient> ConvertVectorStringClientsToVectorClients(vector <string>& vStringClients, string Separator = "#//#")
    {
        vector <sClient> vClients;

        for (short i = 0; i < vStringClients.size(); i++)
        {
            vClients.push_back(ConvertStringClientToClient(vStringClients[i], Separator));
        }

        return vClients;
    }

    inline void PrintClientsList(vector <sClient>& vClients)
    {
        cout << "\t\t\tClient List (" << vClients.size() << ") Client(s)" << endl;

        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

        cout << MyOutput::ManipilatorSpaces("|Account Number", 20) << MyOutput::ManipilatorSpaces("|Pin Code", 15)
            << MyOutput::ManipilatorSpaces("|Client Name", 35) << MyOutput::ManipilatorSpaces("|Phone", 20)
            << MyOutput::ManipilatorSpaces("|Account Balance", 20) << endl;

        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

        for (sClient& Client : vClients)
        {
            cout << MyOutput::ManipilatorSpaces("|" + Client.AccountNumber, 20) << MyOutput::ManipilatorSpaces("|" + Client.PinCode, 15)
                << MyOutput::ManipilatorSpaces("|" + Client.Name, 35) << MyOutput::ManipilatorSpaces("|" + Client.Phone, 20)
                << MyOutput::ManipilatorSpaces("|" + to_string(Client.AccountBalance), 20) << endl;
        }

        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    }

    inline bool IsClientExist(string FileName, string AccountNumber, string Separator = "#//#")
    {
        fstream File;

        File.open(FileName, ios::in);

        if (File.is_open())
        {
            string StringClient = "";

            sClient Client;

            while (getline(File, StringClient))
            {
                Client = ConvertStringClientToClient(StringClient, Separator);

                if (Client.AccountNumber == AccountNumber)
                {
                    File.close();
                    return true;
                }
            }
            File.close();
        }

        return false;
    }

    inline bool IsClientExist(string AcountNumber, vector<sClient>& vClients)
    {
        for (sClient& Client : vClients)
        {
            if (Client.AccountNumber == AcountNumber)
            {
                return true;
            }
        }

        return false;
    }

    inline sClient ReadClient(string Header = "\nPlease enter client data : ", string AccountNumber = "Empty")
    {
        sClient Client;

        cout << Header;

        Client.AccountNumber = (AccountNumber == "Empty") ? MyInput::ReadString("\nEnter Acoount Number ? ") : AccountNumber;
        Client.PinCode = MyInput::ReadString("\nEnter Pin Code ? ");
        Client.Name = MyInput::ReadString("\nEnter Name ? ");
        Client.Phone = MyInput::ReadString("\nEnter Phone ? ");
        Client.AccountBalance = MyInput::ReadNumber((float)0, "\nEnter Account Balance ? ");


        return Client;
    }

    inline string ConvertClientToStringClient(sClient& Client, string Separator = "#//#")
    {
        string StringClient = "";

        StringClient += Client.AccountNumber + Separator;
        StringClient += Client.PinCode + Separator;
        StringClient += Client.Name + Separator;
        StringClient += Client.Phone + Separator;
        StringClient += to_string(Client.AccountBalance);

        return StringClient;
    }

    inline void AddStringClientToFile(string FileName, string StringClient)
    {
        fstream File;

        File.open(FileName, ios::out | ios::app);

        if (File.is_open())
        {
            File << StringClient << "\n";

            File.close();
        }

    }

    inline void PrintClientCard(sClient& Client, string Header = "\nThe Following is extracted client record :\n")
    {
        cout << Header;

        cout << "---------------------------------------------" << endl;
        cout << "Account Number : " << Client.AccountNumber << endl;
        cout << "Pin code       : " << Client.PinCode << endl;
        cout << "Name           : " << Client.Name << endl;
        cout << "Phone          : " << Client.Phone << endl;
        cout << "Acount Balance : " << Client.AccountBalance << endl;
        cout << "---------------------------------------------" << endl;


    }

    inline vector <sClient> LoadClients(string FileName, string Separator = "#//#")
    {
        vector <sClient> vClients;

        fstream File;

        File.open(FileName, ios::in);

        if (File.is_open())
        {
            string Line = "";

            sClient Client;

            while (getline(File, Line))
            {
                if (Line != "" && Line != " ")
                {
                    Client = ConvertStringClientToClient(Line, Separator);

                    vClients.push_back(Client);
                }
            }

            File.close();

        }

        return vClients;
    }

    inline bool FindClientByAccountNumberInVectorClients(vector <sClient>& vClients, string AccountNumber, sClient& ClientFounded)
    {
        for (sClient& Client : vClients)
        {
            if (Client.AccountNumber == AccountNumber)
            {
                ClientFounded = Client;

                return true;
            }
        }

        return false;
    }

    inline bool FindClientByAccountNumberAndPinCodeInVectorClients(vector <sClient>& vClients, string AccountNumber, string PinCode
        , sClient& ClientFounded)
    {
        for (sClient& Client : vClients)
        {
            if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
            {
                ClientFounded = Client;
                return true;
            }
        }

        return false;
    }

    inline bool MarkClientToDelete(string AccountNumber, vector <sClient>& vClients)
    {
        for (sClient& Client : vClients)
        {
            if (AccountNumber == Client.AccountNumber)
            {
                Client.MarkDelete = true;

                return true;
            }
        }

        return false;
    }

    inline void SaveClientsInFile(string FileName, vector <sClient>& vClients, string Separator = "#//#")
    {
        fstream File;

        File.open(FileName, ios::out);

        if (File.is_open())
        {
            string StringClient = "";

            for (sClient& Client : vClients)
            {
                if (!Client.MarkDelete)
                {
                    StringClient = ConvertClientToStringClient(Client, Separator);

                    File << StringClient << endl;
                }
            }

            File.close();
        }

    }

    inline bool DeleteClientInFile(string FileName, vector <sClient>& vClients, string AccountNumber, string Separator = "#//#")
    {
        if (MarkClientToDelete(AccountNumber, vClients))
        {
            SaveClientsInFile(FileName, vClients, Separator);

            vClients = LoadClients(FileName, Separator);

            return true;
        }

        return false;
    }

    inline bool UpdateClientInVectorClients(vector <sClient>& vClients, sClient ClientToUpdate)
    {
        for (sClient& Client : vClients)
        {
            if (Client.AccountNumber == ClientToUpdate.AccountNumber)
            {
                Client = ClientToUpdate;

                return true;
            }
        }

        return false;
    }

    inline bool UpdateClientInFile(string FileName, vector <sClient>& vClients, string AccountNumber, string Separator = "#//#")
    {
        sClient Client = ReadClient("\n\n", AccountNumber);

        if (UpdateClientInVectorClients(vClients, Client))
        {
            SaveClientsInFile(FileName, vClients, Separator);

            return true;
        }

        return false;
    }

    inline float SumBalancesAllClients(vector <sClient>& vClients)
    {
        float Sum = 0;

        for (sClient& Client : vClients)
        {
            Sum += Client.AccountBalance;
        }

        return Sum;
    }

    inline void ShowTotalBalaceTable(vector <sClient>& vClients)
    {
        cout << "\t\t\tBalances List (" << vClients.size() << ") Client(s)" << endl;

        cout << "------------------------------------------------------------------------------------------------" << endl;

        cout << MyOutput::ManipilatorSpaces("|Account Number", 30) << MyOutput::ManipilatorSpaces("|Client Name", 35)
            << MyOutput::ManipilatorSpaces("|Account Balance", 30) << endl;

        cout << "------------------------------------------------------------------------------------------------" << endl;

        for (sClient& i : vClients)
        {
            cout << MyOutput::ManipilatorSpaces("|" + i.AccountNumber, 30) << MyOutput::ManipilatorSpaces("|" + i.Name, 35)
                << MyOutput::ManipilatorSpaces("|" + to_string(i.AccountBalance), 30) << endl;
        }

        cout << "------------------------------------------------------------------------------------------------" << endl;

        cout << MyStringProcess::ReverseString(MyOutput::ManipilatorSpaces(MyStringProcess::ReverseString("Total Balances : "
            + to_string(SumBalancesAllClients(vClients))), 78)) << endl;
    }

    inline bool AddToBalance(sClient& Client, float AddingAmount)
    {
        float NewAmount = Client.AccountBalance + AddingAmount;

        if (NewAmount >= 0)
        {
            Client.AccountBalance = NewAmount;
            return true;
        }

        return false;
    }
}