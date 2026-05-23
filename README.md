# 💻 C++ Functional Programming & Clean Code Portfolio

Welcome to my C++ projects repository! This repository serves as a documentation of my learning journey and a **Portfolio** showcasing my skills in software development using C++.

The core focus of this repository is writing **Clean Code**, applying **Functional Programming** concepts, and organizing large projects into manageable, modular, and reusable components (Separation of Concerns).

## 🚀 How to Run (The ```Main.cpp``` Runner)

This repository is designed efficiently. Instead of having multiple disjointed executable files, all projects are accessible through a single entry point: ```Main.cpp``` located in the ```Main``` folder.

To run a specific project:

Open the ```Main.cpp``` file.

2. Inside the source code, you will find function calls for each project.

3. Simply Uncomment the project you want to run (e.g., the ATM system) and Comment out the rest.

4. Compile and Run (e.g., press ```Ctrl + F5``` in Visual Studio). The selected project will exclusively run in the console.

## 📂 Repository Architecture (* File Tree *)

The project is structured professionally, separating logic, UI (Menus), data, and shared libraries:
```
📂 Projects_FunctionalProgramming_CPP/
├─ 📂 HighlyUsedLibraries/         # Shared utility functions and general-purpose tools
├─ 📂 Main/
│   └── Main.cpp                 # The main entry point linking all projects
└─ 📂 Projects/
    ├─📂 ATMProject/              # The ATM System Interface
    │   ├── ATMDataTypes.h
    │   ├── ATMMenues.h
    │   ├── ATMServices.h
    │   └── ATMproject.cpp
    ├─📂 BankData/                # Database (Text files) separated from logic
    │   ├── Clients.txt
    │   └── Users.txt
    ├─📂 BankProject/             # The Core Bank Management System
    │   ├── BankDataTypes.h
    │   ├── BankMenues.h
    │   ├── BankProject.cpp
    │   ├── BankServices.h
    │   └── UsersProcess.h
    ├─📂 MathGame/                # Highly customizable Math Game
    │   └── MathGame.cpp
    ├─📂 ProjectsCollectionHeader/
    │   └── ProjectsCollectionHeader.h
    ├─📂 SharedBankLogic/         # Core logic shared between Bank and ATM
    │   └── ClientsProcess.h
    └─📂 StonePaperScissorsGame/  # Interactive CLI Game
        └── StonePaperScissorsGame.cpp
```

## 🏦 1. Core Bank Management System (```BankProject```)

A comprehensive, secure, and modular banking management system. This project highlights my ability to handle complex business logic, file I/O, and advanced security concepts.

Key Features:

Client Management: View all clients, add new clients, delete, update client details, and perform transactions (Deposit / Withdraw).

Advanced User Management & Security (RBAC):

  - The system includes a sophisticated Role-Based Access Control mechanism using a 	  "Locks and Keys" logic.

  - ***Super Admin:*** The system has a default Admin account (Username: admin, Password: 123). The admin has universal access to all features.

  - ***Custom Permissions:*** The Admin can add, delete, or update other users and assign them specific permissions (keys) to access certain parts of the system.

**Architecture:** Built using Clean Code principles, strictly divided into ```DataTypes```, ```Menus```, ```Services```, and ```UsersProcess```.

## 💳 2. ATM System (```ATMProject```)

A client-facing ATM interface that integrates seamlessly with the Bank's ecosystem.

***Authentication:*** Clients must log in using their Account Number and PIN Code.

***Services:*** Once authenticated, clients can check their balance, deposit money, and withdraw money safely.

***Architecture Integration:*** It shares the core logic (```ClientsProcess.h```) and database (```Clients.txt```) with the main Bank project via the SharedBankLogic folder, demonstrating real-world system architecture.

## 🧮 3. Customizable Math Game (```MathGame```)

An interactive CLI game testing math skills, demonstrating strong control over game loops, conditionals, and UI/UX in a console environment.

***Dynamic Customization***: Users can choose difficulty (Easy, Normal, Hard, or "Mix") and operation types (Add, Subtract, Multiply, Divide, or "Mix").

***Custom Rounds***: The player decides how many rounds they want to play.

***Immersive UX***: Features color-coded results (Green for winning, Red for losing) and triggers a Bell Sound upon winning/losing.

***Final Evaluation***: At the end, a comprehensive evaluation table is printed showing total wins, losses, and final score.

## ✂️ 4. Stone, Paper, Scissors Game (```StonePaperScissorsGame```)

A classic game implemented in C++ where the user plays against the computer.

Users select the number of rounds to play against the computer's randomized choices.

***Rich UX Elements***: Similar to the Math Game, it features colored outputs (Green/Red) and sound effects for each round result.

***Detailed Statistics***: After all rounds finish, the game displays a detailed summary table summarizing the player's name, rounds won, rounds lost, draws, and the ultimate winner.

## 🛠️ Shared Libraries & Clean Code (```HighlyUsedLibraries```)

To adhere to the **DRY** (**Don't Repeat Yourself**) principle, I created a folder for highly reusable functions used across all projects. This includes essential **UI** and validation tools such as:

```ResetScreen()```

```ReadYesOrNo()```

```RandomNumber()```

```PrintMenu()```

```PrintCard()```

Created by
***Abdelatif SALEM CHERIF***
