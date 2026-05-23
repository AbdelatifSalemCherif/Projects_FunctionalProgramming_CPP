/*
==================================================================
* Developer             : Abdelatif SALEM CHERIF
* Teacher               : Dr.Mohammed Abu-Hadhoud
* Educational Platform  : ProgrammingAdvices
* Original Solve Date   : May 9, 2024 (Stored in .txt Archives)
* Extracted & Published : May 23, 2026
* Total Functions       : 22 Functions
==================================================================
*/

#include <iostream>

using namespace std;

namespace MathGame
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

    int ReadIntNumber(string MessageToUser = "Please enter a positive Number \n")
    {
        int Number = 0;

        cout << MessageToUser;
        cin >> Number;

        return Number;
    }

    int RandomInRange(int From, int To)
    {
        int Number = rand();

        return (Number % (To - From + 1)) + From;
    }



    enum enLevel { Easy = 1, Med = 2, Hard = 3, MixLevel = 4 };

    string enLevel_To_String(enLevel LEVEL)
    {
        string Level[4] = { "Easy","Med","Hard","MIX" };

        return Level[LEVEL - 1];
    }

    enLevel ReadLevel(string MessageToUser)
    {

        return (enLevel)ReadIntNumberInRange(1, 4, MessageToUser);
    }

    enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOperationType = 5 };

    string enOperationType_To_String(enOperationType OPERATIONTYPE)
    {
        string OperationType[5] = { "Add","Sub","Mul","Div","MIX" };

        return OperationType[OPERATIONTYPE - 1];
    }

    char enOperationType_To_Char(enOperationType OPERATIONTYPE)
    {
        char OperationType[4] = { '+','-','*','/' };

        return OperationType[OPERATIONTYPE - 1];
    }

    enOperationType ReadOperationType(string MessageToUser)
    {
        return (enOperationType)ReadIntNumberInRange(1, 5, MessageToUser);
    }




    struct stQuestionData
    {
        enOperationType QuestionType;
        enLevel QuestionLevel;

        int PositionOfQuestion, NumberOfQuestions, FirstOperator, SecondOperator, RealAnswer, PlayerAnswer;

        bool IsRightAnswer;

    };

    struct stTestData
    {
        enLevel TestLevel;
        enOperationType TestOperationType;

        int NumberOfQuestions, NumberOfRightAnswer, NumberOfWrongAnswer;

        bool IsPassTest;

    };




    void GetOperators(enLevel Level, int& FirstOperator, int& SecondOperator)
    {
        switch (Level)
        {
        case enLevel::Easy:
            FirstOperator = RandomInRange(1, 10);
            SecondOperator = RandomInRange(1, 10);
            break;
        case enLevel::Med:
            FirstOperator = RandomInRange(10, 100);
            SecondOperator = RandomInRange(1, 10);
            break;
        case enLevel::Hard:
            FirstOperator = RandomInRange(10, 100);
            SecondOperator = RandomInRange(10, 100);
            break;
        default:
            FirstOperator = RandomInRange(1, 100);
            SecondOperator = RandomInRange(1, 100);
            break;
        }
    }

    int Calculate(int FirstOperator, int SecondOperator, enOperationType& OperationType)
    {
        if (OperationType == enOperationType::MixOperationType)
            OperationType = (enOperationType)RandomInRange(1, 4);

        switch (OperationType)
        {
        case enOperationType::Add:
            return FirstOperator + SecondOperator;
        case enOperationType::Sub:
            return FirstOperator - SecondOperator;
        case enOperationType::Mul:
            return FirstOperator * SecondOperator;
        default:
            return FirstOperator / SecondOperator;
        }
    }

    void PrintHeaderQuestion(int NumberofQuestions, int PositionOfQuestion)
    {
        cout << endl << "Question [" << PositionOfQuestion << "/" << NumberofQuestions << "]" << endl;
    }

    void PrintQuestionOperation(stQuestionData QuestionData)
    {
        cout << endl << QuestionData.FirstOperator << endl;
        cout << QuestionData.SecondOperator << "  " << enOperationType_To_Char(QuestionData.QuestionType) << endl;
        cout << "----------" << endl;
    }

    stQuestionData ReadQuestionData(int NumberOfQuestion, int PositionOfQuestion, enLevel Level, enOperationType OperationType)
    {
        stQuestionData QuestionData;

        QuestionData.NumberOfQuestions = NumberOfQuestion;
        QuestionData.PositionOfQuestion = PositionOfQuestion;
        QuestionData.QuestionLevel = Level;
        QuestionData.QuestionType = OperationType;

        GetOperators(QuestionData.QuestionLevel, QuestionData.FirstOperator, QuestionData.SecondOperator);

        QuestionData.RealAnswer = Calculate(QuestionData.FirstOperator, QuestionData.SecondOperator, QuestionData.QuestionType);

        PrintHeaderQuestion(QuestionData.NumberOfQuestions, QuestionData.PositionOfQuestion);

        PrintQuestionOperation(QuestionData);

        QuestionData.PlayerAnswer = ReadIntNumber("");

        QuestionData.IsRightAnswer = QuestionData.RealAnswer == QuestionData.PlayerAnswer;

        return QuestionData;
    }

    void ScreenColor(bool IsRightAnswer)
    {
        if (IsRightAnswer)
        {
            system("Color 2F");
        }
        else
        {
            cout << "\a";
            system("Color 4F");
        }
    }

    void PrintQuestionData(stQuestionData QuestionData)
    {
        ScreenColor(QuestionData.IsRightAnswer);

        if (QuestionData.IsRightAnswer)
            cout << "\nRight Answer :-)" << endl;
        else
        {
            cout << "\nWrang Answer :-(" << endl;
            cout << "The Right Answer is : " << QuestionData.RealAnswer << endl;
        }
    }





    stTestData ReadTestData()
    {
        stTestData TestData;

        TestData.NumberOfQuestions = ReadIntNumberInRange(1, 10, "\nHow Many Questions do you want to answer from 1 to 10 ? ");

        TestData.TestLevel = ReadLevel("\nEnter Questions level [1]:Easy [2]:Med [3]:Hard [4]:MIX ? ");
        TestData.TestOperationType = ReadOperationType("\nEnter Operation Type [1]:Add [2]:Sub [3]:Mul [4]:Div [5]:MIX ? ");

        TestData.NumberOfRightAnswer = 0;
        TestData.NumberOfWrongAnswer = 0;

        stQuestionData QuestionData;

        for (int i = 1; i <= TestData.NumberOfQuestions; i++)
        {
            QuestionData = ReadQuestionData(TestData.NumberOfQuestions, i, TestData.TestLevel, TestData.TestOperationType);
            PrintQuestionData(QuestionData);

            if (QuestionData.IsRightAnswer)
                TestData.NumberOfRightAnswer++;
        }

        TestData.NumberOfWrongAnswer = TestData.NumberOfQuestions - TestData.NumberOfRightAnswer;

        if (TestData.NumberOfRightAnswer >= TestData.NumberOfWrongAnswer)
            TestData.IsPassTest = true;
        else
            TestData.IsPassTest = false;


        return TestData;
    }

    void PrintTestHeader(bool IsPassTest)
    {
        cout << "\n--------------------------------------------------\n";
        if (IsPassTest)
        {
            cout << "Final Result is Pass :-)" << endl;
        }
        else
        {
            cout << "Final Result is Failed :-(" << endl;
        }

        cout << "--------------------------------------------------\n";
    }

    void PrintTestData(stTestData TestData)
    {
        ScreenColor(TestData.IsPassTest);

        PrintTestHeader(TestData.IsPassTest);

        cout << "Number Of Questions : " << TestData.NumberOfQuestions << endl;
        cout << "Question Level : " << enLevel_To_String(TestData.TestLevel) << endl;
        cout << "Operation Type : " << enOperationType_To_String(TestData.TestOperationType) << endl;
        cout << "Number Of Right Answers : " << TestData.NumberOfRightAnswer << endl;
        cout << "Number Of Wrong Answers : " << TestData.NumberOfWrongAnswer << endl;
        cout << "--------------------------------------------------\n";
    }





    void RestScreen()
    {
        system("CLS");
        system("Color 0F");
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

    void GameMathTest()
    {
        stTestData TestData;
        do {
            RestScreen();

            TestData = ReadTestData();

            PrintTestData(TestData);

        } while (DoKeepPlaying());
    }

    void Run()
    {
        srand((unsigned)time(NULL));

        GameMathTest();

    }
}