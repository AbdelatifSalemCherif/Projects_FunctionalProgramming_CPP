/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : June 14, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 25 Functions
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

namespace UsersProcess
{
    struct sUser
    {
        string UserName = "Empty";
        string PassWord = "1234";
        short Key = 0;
        bool MarkDelete = false;
    };

    bool IsValidUser(string FileName, sUser UserToCheck, string Separator);

    short ReadKey(vector <string>& SevicesMesseges_ORDRED, short NumberOfServices, vector <short>& Loks_ORDRED)
    {
        short Key = 0;

        for (short i = 0; i < NumberOfServices; i++)
        {
            Key |= MyInput::ReadYesOrNo("Has Permission To " + SevicesMesseges_ORDRED[i] + " ? yes/no ? ") * Loks_ORDRED[i];
        }

        return Key;
    }

    sUser ReadNewUser(vector <string>& SevicesMesseges_ORDRED, short NumberOfServices, vector <short>& Loks_ORDRED
        , string Header = "Please enter User :\n ", string UserName = "Empty")
    {
        sUser User;

        cout << Header;

        User.UserName = (UserName == "Empty") ? MyInput::ReadString("Enter User Name ? ") : UserName;
        User.PassWord = MyInput::ReadString("\nEnter Password ? ");
        User.Key = ReadKey(SevicesMesseges_ORDRED, NumberOfServices, Loks_ORDRED);


        return User;

    }

    vector <string> LoadUsersFromFileToVectorString(string FileName)
    {
        vector <string> vStringUsers;

        fstream File;

        File.open(FileName, ios::in);

        if (File.is_open())
        {
            string StringUser = "";

            while (getline(File, StringUser))
            {

                if (StringUser != "" && StringUser != " ")
                {
                    vStringUsers.push_back(StringUser);
                }
            }

            File.close();
        }

        return vStringUsers;
    }

    sUser ConvertStringUserToUser(string StringUser, string Separator = "#//#")
    {
        sUser User;

        vector <string> vStringUser = MyStringProcess::SplitStringToVector(StringUser, Separator);

        User.UserName = vStringUser[0];
        User.PassWord = vStringUser[1];
        User.Key = (short)stoi(vStringUser[2]);

        return User;
    }

    vector <sUser> ConvertVectorStringUsersToVectorUsers(vector <string>& vStringUsers, string Separator = "#//#")
    {
        vector <sUser> vUsers;

        for (short i = 0; i < vStringUsers.size(); i++)
        {
            vUsers.push_back(ConvertStringUserToUser(vStringUsers[i], Separator));
        }

        return vUsers;
    }

    void PrintUsersList(vector <sUser>& vUsers)
    {
        cout << "\t\t\tUser List (" << vUsers.size() << ") User(s)" << endl;

        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

        cout << MyOutput::ManipilatorSpaces("|User Name", 40) << MyOutput::ManipilatorSpaces("|Password", 40)
            << MyOutput::ManipilatorSpaces("|Permission", 40) << endl;

        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

        for (sUser& User : vUsers)
        {
            cout << MyOutput::ManipilatorSpaces("|" + User.UserName, 40) << MyOutput::ManipilatorSpaces("|" + User.PassWord, 40)
                << MyOutput::ManipilatorSpaces("|" + to_string(User.Key), 35) << endl;
        }

        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    }

    bool IsUserExist_InFile(string FileName, string UserName, string Separator = "#//#")
    {
        fstream File;

        File.open(FileName, ios::in);

        if (File.is_open())
        {
            string StringUser = "";

            while (getline(File, StringUser))
            {
                if (UserName == ConvertStringUserToUser(StringUser).UserName)
                {
                    return true;
                }
            }
            File.close();
        }

        return false;
    }

    bool IsUserExist(vector <sUser>& vUsers, sUser& UserToCheck)
    {
        for (sUser& User : vUsers)
        {
            if (User.UserName == UserToCheck.UserName)
            {
                return true;
            }
        }
        return false;
    }

    bool IsUserExist(vector <sUser>* vUsers, sUser* UserToCheck)
    {
        for (sUser& User : *vUsers)
        {
            if (User.UserName == UserToCheck->UserName)
            {
                return true;
            }
        }
        return false;
    }

    bool IsUserExist(string UserName, vector <sUser>& vUsers)
    {
        for (sUser& User : vUsers)
        {
            if (User.UserName == UserName)
            {
                return true;
            }
        }
        return false;
    }

    string ConvertUserToStringUser(sUser& User, string Separator = "#//#")
    {
        string StringUser = "";

        StringUser += User.UserName + Separator;
        StringUser += User.PassWord + Separator;
        StringUser += to_string(User.Key) + Separator;


        return StringUser;
    }

    void AddStringUserToFile(string FileName, string StringUser)
    {
        fstream File;

        File.open(FileName, ios::out | ios::app);

        if (File.is_open())
        {
            File << StringUser << "\n";

            File.close();
        }

    }

    void PrintUserCard(sUser& User, string Header = "\nThe Following is extracted client record :\n")
    {
        cout << Header;

        cout << "---------------------------------------------" << endl;
        cout << "User Name  : " << User.UserName << endl;
        cout << "Password   : " << User.PassWord << endl;
        cout << "Permission : " << User.Key << endl;
        cout << "---------------------------------------------" << endl;


    }

    vector <sUser> LoadUsers(string FileName, string Separator = "#//#")
    {
        vector <sUser> vUsers;

        fstream File;

        File.open(FileName, ios::in);

        if (File.is_open())
        {
            string StringUser = "";
            sUser User;


            while (getline(File, StringUser))
            {
                if (StringUser != "" && StringUser != " ")
                {
                    User = ConvertStringUserToUser(StringUser, Separator);
                    vUsers.push_back(User);
                }
            }
            File.close();
        }

        return vUsers;
    }

    bool IsValidUser(string FileName, sUser UserToCheck, string Separator = "#//#")
    {
        vector <sUser> vUsers = LoadUsers(FileName, Separator);

        for (sUser& User : vUsers)
        {
            if (User.UserName == UserToCheck.UserName && User.PassWord == UserToCheck.PassWord)
            {
                return true;
            }
        }

        return false;
    }

    bool FindUserByUserName(vector <sUser>& vUsers, string UserName, sUser& UserFounded)
    {
        for (sUser& User : vUsers)
        {
            if (User.UserName == UserName)
            {
                UserFounded = User;

                return true;
            }
        }

        return false;
    }

    bool FindUserByUserNameAndPassword(vector <sUser>& vUsers, string UserName, string Password, sUser& UserFounded)
    {
        for (sUser& User : vUsers)
        {
            if (User.UserName == UserName && User.PassWord == Password)
            {
                UserFounded = User;

                return true;
            }
        }

        return false;
    }

    bool MarkUserToDelete(string UserName, vector <sUser>& vUsers)
    {
        for (sUser& User : vUsers)
        {
            if (UserName == User.UserName && User.UserName != "Admin")
            {
                User.MarkDelete = true;

                return true;
            }
        }

        return false;
    }

    void SaveUsersInFile(string FileName, vector <sUser>& vUsers, string Separator = "#//#")
    {
        fstream File;

        File.open(FileName, ios::out);

        if (File.is_open())
        {
            for (sUser& User : vUsers)
            {
                if (!User.MarkDelete)
                {
                    File << ConvertUserToStringUser(User, Separator) << endl;
                }
            }

            File.close();
        }
    }

    bool DeleteUserInFile(string FileName, vector <sUser>& vUsers, string UserName, string Separator = "#//#")
    {
        if (MarkUserToDelete(UserName, vUsers))
        {
            SaveUsersInFile(FileName, vUsers, Separator);

            vUsers = LoadUsers(FileName, Separator);

            return true;
        }

        return false;
    }

    bool UpdateUserInVectorUsers(vector <sUser>& vUsers, sUser UserToUpdate)
    {
        for (sUser& User : vUsers)
        {
            if (User.UserName == UserToUpdate.UserName)
            {
                User = UserToUpdate;

                return true;
            }
        }

        return false;
    }

    bool UpdateUserInFile(string Header, string FileName, vector <sUser>& vUsers, string UserName,
        string Separator, vector <string>& SevicesMesseges_ORDRED, short NumberOfServices, vector <short> &Loks_ORDRED)
    {
        sUser User = ReadNewUser(SevicesMesseges_ORDRED, NumberOfServices, Loks_ORDRED, Header, UserName);

        if (UpdateUserInVectorUsers(vUsers, User))
        {
            SaveUsersInFile(FileName, vUsers, Separator);

            return true;
        }

        return false;
    }




    bool DoesKeyOpenLock(short Lock, short Key)
    {
        return (Key & Lock) == Lock;
    }

    void ShowUserHisKeyDidntOpenLock()
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "Access Denied," << endl;
        cout << "You dont have permission to do this" << endl;
        cout << "Please contact your Admin" << endl;
        cout << "-----------------------------------------------------" << endl;
    }



}