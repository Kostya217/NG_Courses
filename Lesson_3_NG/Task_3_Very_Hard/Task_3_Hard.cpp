#include <iostream>
#include <random>
#include <conio.h>
#include <ctime>

using namespace std;

/*
In this game I have implemented
-Inventory - key i opens inventory
-Craft - a key i opens a zone for crafting, you can craft using the r key
-Extraction of resources - you can use special tools and press the r key, 
    no tools are needed for the tree (yes, our character breaks them with his hand, he is very strong)
-Building houses - In this game, you can build a mine 
    (we collect the necessary resources and press the m key, you can only build at the top) 
    and a door to hell (we collect the necessary resources and press the h key, you can only build at the top)
- We win only when we enter hell)
- The entrance to the premises is carried out by pressing the letter r
*/
int main()
{
    // Learn our PC work with random numbers
    srand(time(0));

    // World size
    const int wSizeX = 50;
    const int wSizeY = 25;

    // Our map
    char gMap[wSizeY][wSizeX];
    // Player map :3
    char pMap[wSizeY][wSizeX];

    // Player position :3
    int pPosX = wSizeX / 2;
    int pPosY = wSizeY / 2;

    // Player action :3
    char pAction = ' ';

    // Resources Tree and stone
    const int lengthInventory = 12;
    int inventory[lengthInventory];
    for (int i = 0; i < lengthInventory; i++)
    {
        inventory[i] = 0;
    }
    // tree, wood, stone, wood pick, stone pick, mine, ferum, coal, aurum, briliant, ferum pick, door hell


    // Map Generation
    for (int y = 0; y < wSizeY; y++) {
        for (int x = 0; x < wSizeX; x++) {
            if (x == 0 ||
                y == 0 ||
                x == wSizeX - 1 ||
                y == wSizeY - 1)

                gMap[y][x] = '|';
            else
                switch (rand() % 20) {
                case 1: gMap[y][x] = 't'; break;
                case 2: gMap[y][x] = 's'; break;
                default: gMap[y][x] = '.';
                }
            pMap[y][x] = '*';
        }
    }

    // Materials image
    char gCraft[6][255] =
    {
        {"      Wood     |   Wooden pick   |   Stone pick    |      Mine     |   Ferum pick   |       Door hell     |"},
        {"    | w | w |  |      w-w-w      |      s-s-s      |   w-w-w-w-w   |      F-F-F     |      b-b-b-b-b-b    |"},
        {"t =  ------    |        w        |        w        |   s-s   s-s   |        w       |      f-b-a-a-b-f    |"},
        {"    | w | w |  |        w        |        w        |   s-s   s-s   |        w       |      f-f-b-b-f-f    |"},
        {"--------_---------------_-----------------_----------------_----------------_-------------------_----------"},
        {"..........................................................................................................."}

    };

    //Player craft position
    int pPosCraftX = 5;
    int pPosCraftY = 0;

    //vector<string> mine;
    char mine[3][8] = {
        {" _____ "},
        {"|->.<-|"},
        {"|_|.|_|"}
    };

    char hell[9][15] = {
    {" __________   "},
    {"|   //\\\\   |"},
    {"|  //  \\\\  |"},
    {"| //hell\\\\ |"},
    {"|//      \\\\|"},
    {" ==========   "},
    {" \\\\_>.<__// "},
    {"  \\\\....//  "},
    {"   \\\\..//   "}
    };



    while (true) {
        system("cls");

        // Update player map according to movement
        pMap[pPosY + 1][pPosX] = gMap[pPosY + 1][pPosX];
        pMap[pPosY - 1][pPosX] = gMap[pPosY - 1][pPosX];
        pMap[pPosY][pPosX + 1] = gMap[pPosY][pPosX + 1];
        pMap[pPosY][pPosX - 1] = gMap[pPosY][pPosX - 1];
        pMap[pPosY + 1][pPosX + 1] = gMap[pPosY + 1][pPosX + 1];
        pMap[pPosY - 1][pPosX + 1] = gMap[pPosY - 1][pPosX + 1];
        pMap[pPosY + 1][pPosX - 1] = gMap[pPosY + 1][pPosX - 1];
        pMap[pPosY - 1][pPosX - 1] = gMap[pPosY - 1][pPosX - 1];

        // Draw map on screen
        for (int y = 0; y < wSizeY; y++) {
            for (int x = 0; x < wSizeX; x++) {

                // If player at this point - just place player
                if (pPosX == x && pPosY == y) {
                    cout << "@";
                    continue;
                }
                switch (pMap[y][x]) {
                case 't': cout << "t"; break;
                case 's': cout << "s"; break;
                default: cout << pMap[y][x];
                }
            }
            cout << endl;
        }

        // Ask player to make action

        cout << ">";
        pAction = _getch();

        // Process player action (movement for current time)

        switch (pAction) {
        case 'w': if (gMap[pPosY - 1][pPosX] == '.') pPosY--; break;
        case 's': if (gMap[pPosY + 1][pPosX] == '.') pPosY++; break;
        case 'a': if (gMap[pPosY][pPosX - 1] == '.') pPosX--; break;
        case 'd': if (gMap[pPosY][pPosX + 1] == '.') pPosX++; break;

            // Process destroy tree

        case 'r':
            if (gMap[pPosY - 1][pPosX] == 't') { 
                inventory[0]++; 
                gMap[pPosY - 1][pPosX] = '.'; 
            }
            if (gMap[pPosY + 1][pPosX] == 't') { 
                inventory[0]++;  
                gMap[pPosY + 1][pPosX] = '.'; 
            }
            if (gMap[pPosY][pPosX - 1] == 't') { 
                inventory[0]++;  
                gMap[pPosY][pPosX - 1] = '.'; 
            }
            if (gMap[pPosY][pPosX + 1] == 't') { 
                inventory[0]++;  
                gMap[pPosY][pPosX + 1] = '.'; 
            }

            if ((inventory[3] != 0 || inventory[4] != 0)) {
                if (gMap[pPosY - 1][pPosX] == 's') {
                    inventory[2]++;
                    gMap[pPosY - 1][pPosX] = '.';
                }
                if (gMap[pPosY + 1][pPosX] == 's') {
                    inventory[2]++;
                    gMap[pPosY + 1][pPosX] = '.';
                }
                if (gMap[pPosY][pPosX - 1] == 's') {
                    inventory[2]++;
                    gMap[pPosY][pPosX - 1] = '.';
                }
                if (gMap[pPosY][pPosX + 1] == 's') {
                    inventory[2]++;
                    gMap[pPosY][pPosX + 1] = '.';
                }
                
            }
            if (gMap[pPosY][pPosX - 1] == '>'
                && gMap[pPosY][pPosX + 1] == '<'
                && gMap[pPosY][pPosX + 2] == '-') {
                bool exitMine = true;

                int pPosYMine = pPosY;
                int pPosXMine = pPosX;
                // Our map
                char gMapMine[wSizeY][wSizeX];
                // Player map :3
                char pMapMine[wSizeY][wSizeX];

                // Player action :3
                char pAction = ' ';

                // Map Generation
                for (int y = 0; y < wSizeY; y++) {
                    for (int x = 0; x < wSizeX; x++) {
                        if (x == 0 ||
                            y == 0 ||
                            x == wSizeX - 1 ||
                            y == wSizeY - 1)

                            gMapMine[y][x] = '|';
                        else
                            switch (rand() % 20) {
                            case 1: gMapMine[y][x] = 'f'; break; //Ferum
                            case 2: gMapMine[y][x] = 'c'; break; //Coal
                            case 3: gMapMine[y][x] = 'a'; break; //Aurum
                            case 4: gMapMine[y][x] = 'b'; break; //Briliant
                            default: gMapMine[y][x] = '.';
                            }
                        pMapMine[y][x] = '*';
                    }
                }
                for (int i = 0, y = pPosYMine - 1; i < 3; i++, y++)
                {
                    for (int j = 0, x = pPosXMine - 3; j < 7; j++, x++)
                    {
                        gMapMine[y][x] = mine[i][j];
                        pMapMine[y][x] = gMapMine[y][x];
                    }
                }

                while (exitMine) {
                    system("cls");

                    // Update player map according to movement
                    pMapMine[pPosYMine + 1][pPosXMine] = gMapMine[pPosYMine + 1][pPosXMine];
                    pMapMine[pPosYMine - 1][pPosXMine] = gMapMine[pPosYMine - 1][pPosXMine];
                    pMapMine[pPosYMine][pPosXMine + 1] = gMapMine[pPosYMine][pPosXMine + 1];
                    pMapMine[pPosYMine][pPosXMine - 1] = gMapMine[pPosYMine][pPosXMine - 1];
                    pMapMine[pPosYMine + 1][pPosXMine + 1] = gMapMine[pPosYMine + 1][pPosXMine + 1];
                    pMapMine[pPosYMine - 1][pPosXMine + 1] = gMapMine[pPosYMine - 1][pPosXMine + 1];
                    pMapMine[pPosYMine + 1][pPosXMine - 1] = gMapMine[pPosYMine + 1][pPosXMine - 1];
                    pMapMine[pPosYMine - 1][pPosXMine - 1] = gMapMine[pPosYMine - 1][pPosXMine - 1];

                    // Draw map on screen
                    for (int y = 0; y < wSizeY; y++) {
                        for (int x = 0; x < wSizeX; x++) {

                            // If player at this point - just place player
                            if (pPosXMine == x && pPosYMine == y) {
                                cout << "@";
                                continue;
                            }
                            switch (pMapMine[y][x]) {
                            case 'f': cout << "f"; break;
                            case 'c': cout << "c"; break;
                            case 'a': cout << "a"; break;
                            case 'b': cout << "b"; break;
                            case '|': cout << "|"; break;
                            default: cout << pMapMine[y][x];
                            }
                        }
                        cout << endl;
                    }

                    // Ask player to make action

                    cout << ">";
                    pAction = _getch();

                    // Process player action (movement for current time)

                    switch (pAction) {
                    case 'w': if (gMapMine[pPosYMine - 1][pPosXMine] == '.') pPosYMine--; break;
                    case 's': if (gMapMine[pPosYMine + 1][pPosXMine] == '.') pPosYMine++; break;
                    case 'a': if (gMapMine[pPosYMine][pPosXMine - 1] == '.') pPosXMine--; break;
                    case 'd': if (gMapMine[pPosYMine][pPosXMine + 1] == '.') pPosXMine++; break;

                    case 'r':
                        
                        if (inventory[4] > 0) {
                            if (gMapMine[pPosYMine - 1][pPosXMine] == 'f') {
                                inventory[6]++;
                                gMapMine[pPosYMine - 1][pPosXMine] = '.';
                            }
                            if (gMapMine[pPosYMine + 1][pPosXMine] == 'f') {
                                inventory[6]++;
                                gMapMine[pPosYMine + 1][pPosXMine] = '.';
                            }
                            if (gMapMine[pPosYMine][pPosXMine - 1] == 'f') {
                                inventory[6]++;
                                gMapMine[pPosYMine][pPosXMine - 1] = '.';
                            }
                            if (gMapMine[pPosYMine][pPosXMine + 1] == 'f') {
                                inventory[6]++;
                                gMapMine[pPosYMine][pPosXMine + 1] = '.';
                            }
                        }
                        if (inventory[3] > 0 || inventory[4] > 0) {
                            if (gMapMine[pPosYMine - 1][pPosXMine] == 'c') {
                                inventory[7]++;
                                gMapMine[pPosYMine - 1][pPosXMine] = '.';
                            }
                            if (gMapMine[pPosYMine + 1][pPosXMine] == 'c') {
                                inventory[7]++;
                                gMapMine[pPosYMine + 1][pPosXMine] = '.';
                            }
                            if (gMapMine[pPosYMine][pPosXMine - 1] == 'c') {
                                inventory[7]++;
                                gMapMine[pPosYMine][pPosXMine - 1] = '.';
                            }
                            if (gMapMine[pPosYMine][pPosXMine + 1] == 'c') {
                                inventory[7]++;
                                gMapMine[pPosYMine][pPosXMine + 1] = '.';
                            }
                        }
                        if (inventory[10] > 0) {
                            if (gMapMine[pPosYMine - 1][pPosXMine] == 'a') {
                                inventory[8]++;
                                gMapMine[pPosYMine - 1][pPosXMine] = '.';
                            }
                            if (gMapMine[pPosYMine + 1][pPosXMine] == 'a') {
                                inventory[8]++;
                                gMapMine[pPosYMine + 1][pPosXMine] = '.';
                            }
                            if (gMapMine[pPosYMine][pPosXMine - 1] == 'a') {
                                inventory[8]++;
                                gMapMine[pPosYMine][pPosXMine - 1] = '.';
                            }
                            if (gMapMine[pPosYMine][pPosXMine + 1] == 'a') {
                                inventory[8]++;
                                gMapMine[pPosYMine][pPosXMine + 1] = '.';
                            }
                        }
                        if (inventory[10] > 0) {
                            if (gMapMine[pPosYMine - 1][pPosXMine] == 'b') {
                                inventory[9]++;
                                gMapMine[pPosYMine - 1][pPosXMine] = '.';
                            }
                            if (gMapMine[pPosYMine + 1][pPosXMine] == 'b') {
                                inventory[9]++;
                                gMapMine[pPosYMine + 1][pPosXMine] = '.';
                            }
                            if (gMapMine[pPosYMine][pPosXMine - 1] == 'b') {
                                inventory[9]++;
                                gMapMine[pPosYMine][pPosXMine - 1] = '.';
                            }
                            if (gMapMine[pPosYMine][pPosXMine + 1] == 'b') {
                                inventory[9]++;
                                gMapMine[pPosYMine][pPosXMine + 1] = '.';
                            }
                        }
                        if (gMapMine[pPosYMine][pPosXMine - 1] == '>' && gMapMine[pPosYMine][pPosXMine + 1] == '<') {
                            exitMine = false;
                        }
                        break;

                        // Inventory
                    case 'i':
                        system("cls");
                        cout << "Your inventory : " << endl;
                        if (inventory[0] > 0) cout << "Tree : " << inventory[0] << endl;

                        if (inventory[1] > 0) cout << "Wood : " << inventory[1] << endl;

                        if (inventory[2] > 0) cout << "Stone : " << inventory[2] << endl;

                        if (inventory[3] > 0) cout << "Pick Wood : " << inventory[3] << endl;

                        if (inventory[4] > 0) cout << "Pick Stone : " << inventory[4] << endl;

                        if (inventory[6] > 0) cout << "Ferum : " << inventory[6] << endl;

                        if (inventory[7] > 0) cout << "Coal : " << inventory[7] << endl;

                        if (inventory[8] > 0) cout << "Aurum : " << inventory[8] << endl;

                        if (inventory[9] > 0) cout << "Briliant : " << inventory[9] << endl;

                        if (inventory[10] > 0) cout << "Ferum pick : " << inventory[10] << endl;

                        cout
                            << "Do you like craft anything ?" << endl
                            << "Enter 'c' for begin craft  " << endl
                            << "Exit - enter any key, besides 'c'" << endl;
                        cout << ">";
                        pAction = _getch();
                        cout << endl;
                        // Craft
                        switch (pAction) {
                        case 'c':
                            bool exit = true;
                            while (exit) {
                                system("cls");
                                cout << "Craft zone" << endl
                                    << "Press r and go to _ for craft thing" << endl
                                    << "Tree : " << inventory[0] << endl
                                    << "Wood : " << inventory[1] << endl
                                    << "Stone : " << inventory[2] << endl
                                    << "Ferum : " << inventory[6] << endl
                                    << "Coal : " << inventory[7] << endl
                                    << "Aurum : " << inventory[8] << endl
                                    << "Briliant : " << inventory[9] << endl;
                                for (int i = 0; i < 6; i++) {
                                    for (int j = 0; j < 255; j++) {
                                        if (pPosCraftX == i && pPosCraftY == j) {
                                            cout << "@";
                                            continue;
                                        }
                                        if (i < 5)
                                        {
                                            if (inventory[0] < 1 && j < 16) cout << "*";
                                            else if (inventory[1] < 5 && j >= 16 && j < 33) cout << "*";
                                            else if ((inventory[1] < 2 || inventory[2] < 3) && (j >= 33 && j < 51)) cout << "*";
                                            else if ((inventory[1] < 5 || inventory[2] < 8) && (j >= 51 && j < 68)) cout << "*";
                                            else if ((inventory[1] < 2 || inventory[6] < 3) && (j >= 68 && j < 84)) cout << "*";
                                            else if ((inventory[6] < 6 || inventory[8] < 2 || inventory[9] < 10) && (j >= 84 && j < 107)) cout << "*";
                                            else cout << gCraft[i][j];
                                        }
                                        else {
                                            cout << gCraft[i][j];
                                        }
                                        
                                    }
                                    cout << endl;
                                }
                                // Ask player to make action
                                cout << ">";
                                pAction = _getch();


                                // Process player action (movement for current time)
                                switch (pAction) {
                                case 'w': if (gCraft[pPosCraftX - 1][pPosCraftY] == '_') pPosCraftX--; break;
                                case 's': if (gCraft[pPosCraftX + 1][pPosCraftY] == '.') pPosCraftX++; break;
                                case 'a': if (gCraft[pPosCraftX][pPosCraftY - 1] == '.') pPosCraftY--; break;
                                case 'd': if (gCraft[pPosCraftX][pPosCraftY + 1] == '.') pPosCraftY++; break;

                                    // Craft materials
                                case 'r':
                                    if (pPosCraftY == 8 && inventory[0] > 0) {
                                        inventory[0]--;
                                        inventory[1] += 4;
                                    }
                                    else if (pPosCraftY == 24 && inventory[1] >= 5) {
                                        inventory[3]++;
                                        inventory[1] -= 5;
                                    }
                                    else if (pPosCraftY == 42 && inventory[2] >= 3 && inventory[1] >= 2) {
                                        inventory[4]++; inventory[2] -= 3; ;
                                        inventory[1] -= 2;
                                    }
                                    else if (pPosCraftY == 59 && inventory[2] >= 8 && inventory[1] >= 5) {
                                        inventory[5]++;
                                        inventory[2] -= 8;
                                        inventory[1] -= 5;
                                    }
                                    else if (pPosCraftY == 76 && inventory[1] >= 2 && inventory[6] >= 3) {
                                        inventory[10]++;
                                        inventory[6] -= 3;
                                        inventory[1] -= 2;
                                    }
                                    else if (pPosCraftY == 96 && (inventory[6] >= 6 && inventory[8] >= 2 && inventory[9] >= 10)) {
                                        inventory[11]++;
                                        inventory[6] -= 6;
                                        inventory[8] -= 2;
                                        inventory[9] -= 10;
                                    }
                                    break;

                                default: exit = false;
                                }
                            }
                        }
                    }
                }
            }
            if (gMap[pPosY][pPosX - 1] == '>'
                && gMap[pPosY][pPosX + 1] == '<'
                && gMap[pPosY][pPosX + 2] == '_') {
                system("cls");
                cout << "You win the game!" << endl;
                return 0;
            }
                break;

        case 'm':
            if (inventory[5] > 0) {
                for (int i = 0, y = pPosY - 3; i < 3; i++, y++)
                {
                    for (int j = 0, x = pPosX - 3; j < 7; j++, x++)
                    {
                        gMap[y][x] = mine[i][j];
                        pMap[y][x] = gMap[y][x];
                    }
                }
                inventory[5]--;
            }
            break;

        case 'h':
            if (inventory[11] > 0) {
                for (int i = 0, y = pPosY - 9; i < 9; i++, y++)
                {
                    for (int j = 0, x = pPosX - 6; j < 12; j++, x++)
                    {
                        gMap[y][x] = hell[i][j];
                        pMap[y][x] = gMap[y][x];
                    }
                }
                inventory[11]--;
            }
            break;

            // Inventory
        case 'i':
            system("cls");
            cout << "Your inventory : " << endl;
            if (inventory[0] > 0) cout << "Tree : " << inventory[0] << endl;

            if (inventory[1] > 0) cout << "Wood : " << inventory[1] << endl;

            if (inventory[2] > 0) cout << "Stone : " << inventory[2] << endl;

            if (inventory[3] > 0) cout << "Pick Wood : " << inventory[3] << endl;

            if (inventory[4] > 0) cout << "Pick Stone : " << inventory[4] << endl;

            if (inventory[5] > 0) cout << "Mine : " << inventory[5] << endl;

            if (inventory[6] > 0) cout << "Ferum : " << inventory[6] << endl;

            if (inventory[7] > 0) cout << "Coal : " << inventory[7] << endl;

            if (inventory[8] > 0) cout << "Aurum : " << inventory[8] << endl;

            if (inventory[9] > 0) cout << "Briliant : " << inventory[9] << endl;

            if (inventory[10] > 0) cout << "Ferum pick : " << inventory[10] << endl;

            if (inventory[11] > 0) cout << "Door hell : " << inventory[11] << endl;

            cout
                << "Do you like craft anything ?" << endl
                << "Enter 'c' for begin craft  " << endl
                << "Exit - enter any key, besides 'c'" << endl;
            cout << ">";
            pAction = _getch();
            cout << endl;
            // Craft
            switch (pAction) {
            case 'c':
                bool exit = true;
                while (exit) {
                    system("cls");
                    cout << "Craft zone" << endl
                        << "Press r and go to _ for craft thing" << endl
                        << "Tree : " << inventory[0] << endl
                        << "Wood : " << inventory[1] << endl
                        << "Stone : " << inventory[2] << endl
                        << "Ferum : " << inventory[6] << endl
                        << "Coal : " << inventory[7] << endl
                        << "Aurum : " << inventory[8] << endl
                        << "Briliant : " << inventory[9] << endl;
                    for (int i = 0; i < 6; i++) {
                        for (int j = 0; j < 255; j++) {
                            if (pPosCraftX == i && pPosCraftY == j) {
                                cout << "@";
                                continue;
                            }
                            if (i < 4)
                            {
                                if (inventory[0] < 1 && j < 16) cout << "*";
                                else if (inventory[1] < 5 && j >= 16 && j < 33) cout << "*";
                                else if ((inventory[1] < 2 || inventory[2] < 3) && (j >= 33 && j < 51)) cout << "*";
                                else if ((inventory[1] < 5 || inventory[2] < 8) && (j >= 51 && j < 68)) cout << "*";
                                else if ((inventory[1] < 2 || inventory[6] < 3) && (j >= 68 && j < 84)) cout << "*";
                                else if ((inventory[6] < 6 || inventory[8] < 2 || inventory[9] < 10) && (j >= 84 && j < 107)) cout << "*";
                                else cout << gCraft[i][j];
                            }
                            else {
                                cout << gCraft[i][j];
                            }
                        }
                        cout << endl;
                    }
                    // Ask player to make action
                    cout << ">";
                    pAction = _getch();


                    // Process player action (movement for current time)
                    switch (pAction) {
                    case 'w': if (gCraft[pPosCraftX - 1][pPosCraftY] == '_') pPosCraftX--; break;
                    case 's': if (gCraft[pPosCraftX + 1][pPosCraftY] == '.') pPosCraftX++; break;
                    case 'a': if (gCraft[pPosCraftX][pPosCraftY - 1] == '.') pPosCraftY--; break;
                    case 'd': if (gCraft[pPosCraftX][pPosCraftY + 1] == '.') pPosCraftY++; break;

                        // Craft materials
                    case 'r':
                        if (pPosCraftY == 8 && inventory[0] > 0) {
                            inventory[0]--;
                            inventory[1] += 4;
                        }
                        else if (pPosCraftY == 24 && inventory[1] >= 5) {
                            inventory[3]++;
                            inventory[1] -= 5;
                        }
                        else if (pPosCraftY == 42 && inventory[2] >= 3 && inventory[1] >= 2) {
                            inventory[4]++; inventory[2] -= 3; ;
                            inventory[1] -= 2;
                        }
                        else if (pPosCraftY == 59 && inventory[2] >= 8 && inventory[1] >= 5) {
                            inventory[5]++;
                            inventory[2] -= 8;
                            inventory[1] -= 5;
                        }
                        else if (pPosCraftY == 76 && inventory[1] >= 2 && inventory[6] >= 3) {
                            inventory[10]++;
                            inventory[6] -= 3;
                            inventory[1] -= 2;
                        }
                        else if (pPosCraftY == 96 && (inventory[6] >= 6 && inventory[8] >= 2 && inventory[9] >= 10)) {
                            inventory[11]++;
                            inventory[6] -= 6;
                            inventory[8] -= 2;
                            inventory[9] -= 10;
                        }
                        break;

                    default: exit = false;
                    }
                }
            }
            }
        }

    }

