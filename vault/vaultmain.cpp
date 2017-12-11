#include "vaultmain.h"


int main() {
    Vault vault1;                   //declares vault object. Make new each time?
    ifstream input;                 //declares variable for input from a save file
    ofstream output;                //declares variable for output to populate a file with user's data
    ofstream save;                  //declares variable for output to save file
    char usr_cmd = ' ';             //declares variable for storing user commands
    char usr_cmd2 = ' ';            //declares secondary variable for storing user commands
    string usr_input = "";          //declares variable for string input form user
    string filename = "";
    
    
    
    cout << "Welcome to PASSVAULT" << endl;
    cout << "Enter the task you wish to complete:" << endl;
    cout << "    N - Create New Vault" << endl;
    cout << "    R - Retrieve Saved Vault" << endl;
    cin >> usr_cmd;
    while ((usr_cmd != 'N') && (usr_cmd != 'n') && (usr_cmd != 'R') && (usr_cmd != 'r')) {
        cout << "Invalid command. Please re-enter:" << endl;
        cin >> usr_cmd;
    }
    
    switch (usr_cmd) {
        case 'N':
        case 'n':
            cout << "Enter your desired username:" << endl;
            cin >> usr_input;
            vault1.SetUsername(usr_input);
            cout << "Enter your master password:" << endl;
            cin >> usr_input;
            vault1.SetMaster(usr_input);
            cout << "Verify your master password:" << endl;
            cin >> usr_input;
            while (usr_input != vault1.GetMaster()) {
                cout << "The password you entered does not match your previous entry." << endl;
                cout << "Re-enter your password:" << endl;
                cin >> usr_input;
                vault1.SetMaster(usr_input);
                cout << "Verify password:" << endl;
                cin >> usr_input;
            }
            cout << "Your master password has been verified. Please store it somewhere safe." << endl;
            break;
        case 'R':
        case 'r':
            cout << "Enter username:" << endl;
            cin >> usr_input;
            filename = usr_input;
            filename.append(".txt");
            vault1.SetSavefile(filename);
            vault1.Import();
            cout << "Your vault has been recovered. Enter your master password:" << endl;
            cin >> usr_input;
            while (usr_input != vault1.GetMaster()) {
                cout << "Invalid password. Try again." << endl;
                cin >> usr_input;
            }
            break;
    }
    
    while ((usr_cmd != 'Q') && (usr_cmd != 'q')) {
        cout << "What would you like to do?" << endl;
        cout << "    1 - Store Password" << endl;
        cout << "    2 - Retrieve/Change Password" << endl;
        cout << "    3 - Output File" << endl;
        cin >> usr_cmd;
        while ((usr_cmd < 1) || (usr_cmd > 3)) {
            cout << "Invalid command. Please re-enter:" << endl;
            cin >> usr_cmd;
        }
        
        switch (usr_cmd) {
            case 1:
                {
                vault1.SetJ(0);
                cout << "What service is this password for?" << endl;
                cin >> usr_input;
                vault1.SetServiceName(vault1.GetJ(), usr_input);
                cout << "Would you like to assign a random password or your own?" << endl;
                cout << "    1 - Random Password" << endl;
                cout << "    2 - Specify Password" << endl;
                while ((usr_cmd != 1) && (usr_cmd != 2)) {
                    cout << "Invalid command. Please re-enter:" << endl;
                    cin >> usr_cmd2;
                }
                switch (usr_cmd2) {
                    case 1:
                        {
                        vault1.SetPassword(vault1.GetJ(), vault1.RandPass());
                        }
                        break;
                    case 2:
                        {
                        cout << "Enter your password:" << endl;
                        cin >> usr_input;
                        vault1.SetPassword(vault1.GetJ(), usr_input);
                        cout << "Verify your password:" << endl;
                        cin >> usr_input;
                        while (usr_input != vault1.GetPassword(vault1.GetJ())) {
                            cout << "The password you entered does not match your previous entry." << endl;
                            cout << "Re-enter your password:" << endl;
                            cin >> usr_input;
                            vault1.SetPassword(vault1.GetJ(), usr_input);
                            cout << "Verify password:" << endl;
                            cin >> usr_input;
                        }
                        }
                        break;
                    default:
                        break;
                }
                cout << "Your password for " << vault1.GetServiceName(vault1.GetJ()) << " is " << vault1.GetPassword(vault1.GetJ()) << "." << endl;
                vault1.SetJ(vault1.GetJ() + 1);
                }
                break;
            case 2:
                {
                cout << "Which service would you like to retrieve your password for?" << endl;
                cin >> usr_input;
                int found_at = -1;
                for (int i = 0; i < vault1.GetJ(); i++) {
                    if (MakeLower(vault1.GetServiceName(i)) == MakeLower(usr_input)) {
                        found_at = i;
                    }
                }
                if (found_at > -1) {
                    cout << "Your password for " << vault1.GetServiceName(found_at) << " is " << vault1.GetPassword(found_at) << endl;
                } else {
                    cout << "The specified service was not found in the vault." << endl;
                }
                cout << "Would you like to change this password?" << endl;
                cout << "    Y - Yes" << endl;
                cout << "    N - No" << endl;
                cin >> usr_cmd;
                while ((usr_cmd != 'N') && (usr_cmd != 'n') && (usr_cmd != 'Y') && (usr_cmd != 'y')) {
                    cout << "Invalid command. Please re-enter:" << endl;
                    cin >> usr_cmd;
                }
                
                switch (usr_cmd) {
                    case 'Y':
                    case 'y':
                        {
                        cout << "Enter new password:" << endl;
                        cin >> usr_input;
                        vault1.SetPassword(vault1.GetJ(), usr_input);
                        cout << "Verify your password:" << endl;
                        cin >> usr_input;
                        while (usr_input != vault1.GetPassword(vault1.GetJ())) {
                            cout << "The password you entered does not match your previous entry." << endl;
                            cout << "Re-enter your password:" << endl;
                            cin >> usr_input;
                            vault1.SetPassword(vault1.GetJ(), usr_input);
                            cout << "Verify password:" << endl;
                            cin >> usr_input;
                        }
                        }
                        break;
                }
                }
                break;
            case 3:
                {
                filename = vault1.GetUsername();
                filename.append("_outfile.txt");
                vault1.SetOutfile(filename);
                vault1.VaultOut();
                cout << "Your passwords have been printed to " << vault1.GetOutfile() << endl;
                }
                break;
        }
    }
    vault1.Save();
    
    return 0;
}

string MakeLower(string str) {
    string new_str = "";
    char new_char = ' ';
    for (int i = 0; i < str.length(); i++) {
        new_char = tolower(str.at(i));
        new_str.push_back(new_char);
    }
    return new_str;
}