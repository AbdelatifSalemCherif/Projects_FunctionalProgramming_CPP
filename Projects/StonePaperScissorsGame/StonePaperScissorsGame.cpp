/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : May 9, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 16 Functions
==================================================================
*/

#include <iostream>

using namespace std;

namespace StonePaperScissorsGame
{
    int ReadIntNumberInRange(int From, int To, string MessageToUser = "Please enter a positive Number \n")
    {
        int Number = 0;

        do {
            cout << MessageToUser;
            cin >> Number;
        } while (Number < From || Number > To);

        return Number;
    }

    int RandomInRange(int From, int To)
    {
        int Number = rand();

        return (Number % (To - From + 1)) + From;
    }

    enum enObject { Stone = 1, Paper = 2, Scissors = 3 };

    string enObject_To_String(enObject Object)
    {
        switch (Object)
        {
        case enObject::Stone:
            return "Stone";
        case enObject::Paper:
            return "Paper";
        case enObject::Scissors:
            return "Scissors";
        }
    }

    enum enWinner { Draw, Player1, Computer };

    string enWinner_To_String(enWinner Winner)
    {
        switch (Winner)
        {
        case enWinner::Player1:
            return "Player1";
        case enWinner::Computer:
            return "Computer";
        case enWinner::Draw:
            return "Draw";
        }
    }

    struct stRoundData
    {
        enObject ObjectChoiceFromPlayer1, ObjectChoiceFromComputer;
        enWinner RoundWinner;

    };

    struct stAllRoundsData
    {
        stRoundData Rounds[10];

        int NumberOfRounds, DrawTimes, Player1WonTimes, ComputerWonTimes;
        enWinner FinalWinner;
    };

    enWinner RoundWinner(enObject ObjectChoiceFromPlayer1, enObject ObjectChoiceFromComputer)
    {
        if (ObjectChoiceFromPlayer1 == ObjectChoiceFromComputer)
            return enWinner::Draw;

        switch (ObjectChoiceFromPlayer1)
        {
        case enObject::Stone:
            switch (ObjectChoiceFromComputer)
            {
            case enObject::Paper:
                return enWinner::Computer;
            case enObject::Scissors:
                return enWinner::Player1;
            }
        case enObject::Paper:
            switch (ObjectChoiceFromComputer)
            {
            case enObject::Scissors:
                return enWinner::Computer;
            case enObject::Stone:
                return enWinner::Player1;
            }
        case enObject::Scissors:
            switch (ObjectChoiceFromComputer)
            {
            case enObject::Paper:
                return enWinner::Player1;
            case enObject::Stone:
                return enWinner::Computer;
            }
        }
    }

    enObject ComputerChoice()
    {
        int Object = RandomInRange(1, 3);

        return (enObject)Object;

    }

    enObject ReadPlayer1Choice(string MessageToUser = "\nYour Choice : [1]:Stone [2]:Paper [3]:Scissors ? ")
    {
        int Object = ReadIntNumberInRange(1, 3, MessageToUser);

        return (enObject)Object;
    }

    stRoundData ReadRoundData(int RoundPosition)
    {
        stRoundData Round;

        cout << "\nRound [" << RoundPosition + 1 << "] begins :\n";
        Round.ObjectChoiceFromPlayer1 = ReadPlayer1Choice();
        Round.ObjectChoiceFromComputer = ComputerChoice();
        Round.RoundWinner = RoundWinner(Round.ObjectChoiceFromPlayer1, Round.ObjectChoiceFromComputer);

        return Round;
    }

    void ScreenColor(enWinner Winner)
    {
        switch (Winner)
        {
        case enWinner::Player1:
            system("Color 2F");
            break;
        case enWinner::Computer:
            cout << "\a";
            system("Color 4F");
            break;
        case enWinner::Draw:
            system("Color 6F");
            break;
        }
    }

    void PrintRoundData(stRoundData Round, int RoundPosition)
    {
        ScreenColor(Round.RoundWinner);

        cout << endl << "--------------------Round[" << RoundPosition + 1 << "]--------------------" << endl;
        cout << "Plyer 1 Choice  :" << enObject_To_String(Round.ObjectChoiceFromPlayer1) << endl;
        cout << "Computer Choice :" << enObject_To_String(Round.ObjectChoiceFromComputer) << endl;
        cout << "Round Winner    :" << enWinner_To_String(Round.RoundWinner) << endl;
        cout << "-------------------------------------------------\n";
    }

    enWinner FinalWinner(int Player1WonTimes, int ComputerWonTimes)
    {
        int WinOrLose = Player1WonTimes - ComputerWonTimes;

        if (WinOrLose != 0)
        {
            if (WinOrLose > 0)
            {
                return enWinner::Player1;
            }
            else
            {
                return enWinner::Computer;
            }
        }
        else {
            return enWinner::Draw;
        }
    }

    stAllRoundsData ReadAllRounds()
    {
        stAllRoundsData AllRoundsData;

        AllRoundsData.NumberOfRounds = ReadIntNumberInRange(1, 10, "How Rounds 1 to 10 ? \n");

        AllRoundsData.Player1WonTimes = 0;
        AllRoundsData.ComputerWonTimes = 0;
        AllRoundsData.DrawTimes = 0;

        for (int i = 0; i < AllRoundsData.NumberOfRounds; i++)
        {
            AllRoundsData.Rounds[i] = ReadRoundData(i);
            PrintRoundData(AllRoundsData.Rounds[i], i);

            switch (AllRoundsData.Rounds[i].RoundWinner)
            {
            case enWinner::Player1:
                AllRoundsData.Player1WonTimes++;
                break;
            case enWinner::Computer:
                AllRoundsData.ComputerWonTimes++;
                break;
            case enWinner::Draw:
                AllRoundsData.DrawTimes++;
                break;
            }
        }

        AllRoundsData.FinalWinner = FinalWinner(AllRoundsData.Player1WonTimes, AllRoundsData.ComputerWonTimes);

        return AllRoundsData;
    }

    void PrintAllRoundsData(stAllRoundsData AllRoundsData)
    {
        ScreenColor(AllRoundsData.FinalWinner);

        cout << "\n\t\t------------------------------------------------------\n";
        cout << "\t\t\t\t* * * G a m e  O v e r  * * * " << endl;
        cout << "\t\t------------------------------------------------------\n";
        cout << "\t\t------------------[Game Result]-----------------------\n";
        cout << "\t\tGame Rounds        : " << AllRoundsData.NumberOfRounds << endl;
        cout << "\t\tPlayer 1 Won Times : " << AllRoundsData.Player1WonTimes << endl;
        cout << "\t\tComputer Won Times : " << AllRoundsData.ComputerWonTimes << endl;
        cout << "\t\tDraw Times         : " << AllRoundsData.DrawTimes << endl;
        cout << "\t\tFinal Winner       : " << enWinner_To_String(AllRoundsData.FinalWinner) << endl;
        cout << "\t\t------------------------------------------------------\n";
    }

    bool DoKeepPlaying()
    {
        bool Yes = false, No = false;

        string IWantToPlay;

        do {
            cout << "\nDo you want to play again ? Y/N ?";
            cin >> IWantToPlay;

            Yes = IWantToPlay == "Y" || IWantToPlay == "y" || IWantToPlay == "Yes" || IWantToPlay == "YES"
                || IWantToPlay == "yes";
            No = IWantToPlay == "N" || IWantToPlay == "n" || IWantToPlay == "No"
                || IWantToPlay == "NO" || IWantToPlay == "no";


        } while (IWantToPlay.length() > 3 || (!Yes && !No));

        return Yes;

    }

    void GameStonePaperScissors()
    {
        stAllRoundsData AllRoundsData;

        bool KeepPlaying = true;


        do {
            system("CLS");
            system("Color 0F");

            AllRoundsData = ReadAllRounds();
            PrintAllRoundsData(AllRoundsData);

            KeepPlaying = DoKeepPlaying();

        } while (KeepPlaying);
    }

    void Run()
    {
        srand((unsigned)time(NULL));

        GameStonePaperScissors();

    }
}