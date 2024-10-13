Future Banking System
A Simple Banking System in C
This C project is a basic console-based banking system where users can create accounts, log in to
existing accounts, deposit money, withdraw money, and view account details. The data is stored in a
text file for persistence.
Overview
--------
This program allows users to create bank accounts, log in, deposit, withdraw, and check balances. It
simulates basic banking operations using file I/O in C for data persistence.
Key Components:
- accountCreate(): Creates a new account and stores user details in CustomerDetails.txt.
- deposit(): Allows logged-in users to deposit money.
- withdraw(): Allows logged-in users to withdraw money (if they have enough balance).
- checking(): Authenticates users by checking their username and password, and displays account
details.
Features
--------
- Account Creation: Create a new user account with username, password, and ID number.
- Login: Existing users can log in with their username and password.
- Deposit Money: Deposit money into the logged-in account.
- Withdraw Money: Withdraw money from the logged-in account.
- Account Details: View the details of the logged-in account.
- File I/O: The system saves user details in a file for persistent data storage.
Getting Started
---------------
Prerequisites:
- Windows OS (due to the use of windows.h library for gotoxy() function).
- A C compiler, such as gcc.
Installation:
1. Clone the repository:
git clone https://github.com/KaushanS/Future-Banking-System.git
2. Compile the C code:
gcc main.c -o bank.exe
3. Run the compiled executable:
./bank.exe
Usage
-----
- When you run the program, you'll see two options:
- Create an account: To create a new user account.
- Already user..Log in: To log in to an existing account.
- After logging in, users can:
- Deposit money.
- Withdraw money.
- Exit the system.
Files
-----
- main.c: The main source code of the banking system.
- CustomerDetails.txt: A text file that stores customer information such as username, password,
name, ID, account number, and balance.
Contributing
------------
Contributions are welcome! Feel free to submit a pull request or open an issue for any bugs or
feature requests.
License
-------
This project is licensed under the MIT License - see the LICENSE file for details.
