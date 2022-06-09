#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <process.h>
char mword[50];
char c, st[50];
char s[10][50] = {"jail-diary", "the-three-musketeers", "politics", "gita-rahasya", "freedom-in-exile", "my-truth", "gitanjali", "arabian-nights", "the-guide", "time-machine"};
char s1[10][50] = {"titanic", "star-wars", "the-last-emperor", "gandhi", "gravity", "slumdog-millionaire", "king's-speech", "first-man", "ordinary-people", "lord-of-the-rings"};
char s2[10][50] = {"armenia", "azerbaijan", "bulgaria", "dominica", "ghana", "libya", "qatar", "mauritius", "chile", "oman"};
char s3[10][50] = {"barack-obama", "albert-einstein", "abraham-lincoln", "michael-jackson", "bill-gates", "narendra-modi", "aryabhatta", "sarojini-naidu", "leonardo-da-vinci", "srinivasa-ramanujan"};
char s4[5][50] = {"dodo", "great-auk", "tasmanian-tiger", "passenger-pigeon", "woolly-mammoth"};
char s5[5][50] = {"the-beatles", "the-eagles", "the-clash", "the-gang-of-four", "the-shadows"};
int points = 0;
void score();
void howtoplay();
void newgame();
void exitgame();
void choices();
void c2();
void c3();
void c4();
void c5();
void c6();
struct candidate
{
    int ccode;
    char cname[20];
    int score;
    char phno[10];
} ca;
void getcandidate()
{
    clrscr();
    gotoxy(20, 10);
    cout << "YOUR CODE...............";
    cin >> ca.ccode;
    gotoxy(20, 12);
    cout << "YOUR NAME...............";
    cin >> ca.cname;
    gotoxy(20, 14);
    cout << "YOUR PHONE NO...........";
    cin >> ca.phno;
}
void putcandidate()    \*display candidate details *
{
    clrscr();
    gotoxy(20, 10);
    cout << "CODE..............." << ca.ccode;
    gotoxy(20, 12);
    cout << "NAME..............." << ca.cname;
    gotoxy(20, 14);
    cout << "PHONE NO..........." << ca.phno;
    gotoxy(20, 16);
    cout << "SCORE.............." << ca.score;
}
char ch;
void boundary() // border of output screen
{
    for (int i = 3; i <= 77; i++)
    {
        textcolor(i);
        gotoxy(i, 2);
        cprintf("²");
        gotoxy(i, 25);
        cprintf("²");
    }
    for (i = 2; i <= 25; i++)
    {
        textcolor(i);
        gotoxy(3, i);
        cprintf("²");
        gotoxy(78, i);
        cprintf("²");
    }
}
void front() // menu window
{
    clrscr();
    boundary();
    gotoxy(34, 7);
    cout << "***GUESS ME***";
    gotoxy(33, 8);
    cout << "================";
    for (int i = 30; i <= 50; i++) // boundary of menu
    {
        gotoxy(i, 13);
        cprintf("²");
        gotoxy(i, 18);
        cprintf("²");
    }
    for (i = 13; i <= 18; i++)
    {
        gotoxy(30, i);
        cprintf("²");
        gotoxy(50, i);
        cprintf("²");
    }
    gotoxy(35, 14);
    cout << "NEW GAME(N/n)";
    gotoxy(33, 15);
    cout << "HOW TO PLAY(H/h)";
    gotoxy(36, 16);
    cout << "SCORE(S/s)";
    gotoxy(36, 17);
    cout << "EXIT(E/e)";
    gotoxy(30, 20);
    cout << "enter your choice="; // player's choice
    cout << ".......";
    gotoxy(49, 20);
    cin >> ch;
    choices();
}
void howtoplay() // help function
{
    clrscr();
    boundary();
    gotoxy(20, 8);
    cout << "This game is filled with terms, phrases, words";
    gotoxy(20, 9);
    cout << "presented in random order each time you play.";
    gotoxy(19, 10);
    cout << "You select letters by typing them .Be careful,";
    gotoxy(18, 11);
    cout << "you are allowed only three wrong guesses per puzzle.";
    gotoxy(20, 12);
    cout << "The hyphen(-) separates two words";
    gotoxy(30, 17);
    cout << "Enjoy playing"
         << "--¯";
    gotoxy(25, 19);
    cout << "Want to play(y/n).....";
    gotoxy(43, 19);
    cin >> c;
    if (c == 'y')
        newgame();
    else if (c == 'n')
        front();
    else
    {
        gotoxy(26, 20);
        cout << "enter again......";
        gotoxy(39, 20);
        cin >> c;
    }
}
void exitgame() // exit game
{
    clrscr();
    boundary();
    gotoxy(24, 13);
    cout << "Thank You For Playing";
    exit(0);
}
void score() // score desciption
{
    clrscr;
    boundary();
    gotoxy(20, 8);
    cout << "You will get 5 points for right answer ";
    gotoxy(20, 9);
    cout << "in first attempt and 3 points in second ";
    gotoxy(20, 10);
    cout << "attempt 2 points in third attempt and ";
    gotoxy(22, 11);
    cout << "1 point in third attempt";
}
void choices() // switch case
{
    switch (ch)
    {
    case 'n':
        newgme();
        break;
    case 'h':
        howtoplay();
        break;
    case 's':
        score();
        break;
    case 'e':
        exitgame();
        break;
    }
}
void newgame() // new game
{
    // guess a book name
    randomize();
    clrscr();
    int cnt = 0;
    char m[50];
    boundary();
    gotoxy(34, 7);
    cout <<”LEVEL 1 ";

        gotoxy(68, 3);
    cout << "SCORE:";
    points = 10;
    gotoxy(76, 3);
    cout << points;
    int r = random(10);
    strcpy(mword, s[r]);
    int ll = 0, a;
    int total = strlen(mword);
    for (int i = 0; i <= strlen(mword); i++)
    {
        int x = 21 + i;
        gotoxy(x, 14);
        cout << "_"; // printing blank for word
        a = i + 22;
        if (mword[i] == '-')
        {
            gotoxy(a, 13);
            cout << "-";

            st[i] = '-';
            total--;
        }
    }
    x while (total > 0)
    {
        gotoxy(24, 10);
        cout << "BOOK NAME";
        int found = 0;
        gotoxy(68, 5 + ll);
        cin >> l; // character entered by user
        ll++;     // position of hyphens
        for (i = 0; i <= strlen(mword); i++)
        {
            a = i + 22;
            if (l == mword[i])
            {
                st[i] = mword[i];
                gotoxy(a, 13);
                cout << l;
                found = 1;
                total--;
            }
        }
        if (found == 0)
        {
            cnt++;
            points--;
        }
        gotoxy(75, 3);
        cout << "     ";
        gotoxy(76, 3);
        cout << points;
        gotoxy(55, 23);
        cout << "incorrect entries=" << cnt;
        if (cnt == 3)
        {
            clrscr();
            gotoxy(29, 13);
            cout << "YOU LOST!";
            getch();
            break;
        }
    }
    gotoxy(75, 3);
    cout << "         ";
    gotoxy(76, 3);
    cout << points;
    getch();
    if (strcmpi(st, mword) == 0)
    {
        clrscr();
        char TRY;
        gotoxy(29, 13);
        cout << "YOU WON!" << endl
             << "MOVE TO NEXT LEVEL-->>";
        gotoxy(38, 14);
        cin >> TRY;
        if (TRY == 'Y' || TRY == 'y')
            c2();
        else if (TRY == 'N' || TRY == 'n')
            front();
    }
    ca.score = points;
}
// guess a movie
void c2()
{
    randomize();
    clrscr();
    int cnt = 0;
    boundary();
    gotoxy(34, 7);
    cout <<”LEVEL 2 ";
        gotoxy(68, 3);
    cout << "SCORE:";
    points += 5;
    gotoxy(76, 3);
    cout << points;
    int r = random(10);
    strcpy(mword, s1[r]);
    int ll = 0, a;
    int total = strlen(mword);
    for (int i = 0; i <= strlen(mword); i++)
    {
        int x = 21 + i;
        gotoxy(x, 14);
        cout << "_"; // printing blank for word
        a = i + 22;
        if (mword[i] == '-')
        {
            gotoxy(a, 13);
            cout << "-";
            total--;
        }
    }
    while (total > 0)
    {
        gotoxy(24, 10);
        cout << "OSCAR MOVIES:";
        int found = 0;
        gotoxy(68, 5 + ll);
        cin >> l; // character entered by user
        ll++;     // position of hyphens
        for (i = 0; i <= strlen(mword); i++)
        {
            a = i + 22;
            if (l == mword[i])
            {
                st[i] = mword[i];
                gotoxy(a, 13);
                cout << l;
                found = 1;
                total--;
            }
        }
        if (found == 0)
        {
            cnt++;
            points--;
        }
        gotoxy(75, 3);
        cout << "     ";
        gotoxy(76, 3);
        cout << points;
        gotoxy(55, 23);
        cout << "incorrect entries=" << cnt;
        if (cnt == 3)
        {
            clrscr();
            gotoxy(29, 13);
            cout << "YOU LOST!";
            getch();
            break;
        }
    }
    gotoxy(75, 3);
    cout << "         ";
    gotoxy(76, 3);
    cout << points;
    getch();
    if (strcmpi(st, mword) == 0)
    {
        clrscr();
        char TRY;
        gotoxy(29, 13);
        cout << "YOU WON!" << endl
             << "MOVE TO NEXT  LEVEL-->>";
        gotoxy(38, 14);
        cin >> TRY;
        if (TRY == 'Y' || TRY == 'y')
            c3();
        else if (TRY == 'N' || TRY == 'n')
            front();
    }
    ca.score = points;
}
// guess the extinct species
void c5()
{
    randomize();
    clrscr();
    int cnt = 0;
    boundary();
    gotoxy(34, 7);
    cout <<”LEVEL 5”;
    points += 5;
    gotoxy(68, 3);
    cout << "SCORE:";
    gotoxy(76, 3);
    cout << points;
    int r = random(5);
    strcpy(mword, s4[r]);
    int ll = 0, a;
    int total = strlen(mword);
    for (int i = 0; i <= strlen(mword); i++)
    {
        int x = 21 + i;
        gotoxy(x, 14);
        cout << "_"; // printing blank for word
        a = i + 22;
        if (mword[i] == '-')
        {
            gotoxy(a, 13);
            cout << "-";
            st[i] = '-';
            total--;
        }
    }
    while (total > 0)
    {
        gotoxy(24, 10);
        cout << "EXTINCT SPECIES:";
        int found = 0;
        gotoxy(68, 5 + ll);
        cin >> l; // character entered by user
        ll++;     // position of hyphens
        for (i = 0; i <= strlen(mword); i++)
        {
            a = i + 22;
            if (l == mword[i])
            {
                st[i] = mword[i];
                gotoxy(a, 13);
                cout << l;
                found = 1;
                total--;
            }
        }
        if (found == 0)
        {
            cnt++;
            points--;
        }
        gotoxy(75, 3);
        cout << "     ";
        gotoxy(76, 3);
        cout << points;
        gotoxy(55, 23);
        cout << "incorrect entries=" << cnt;
        if (cnt == 3)
        {
            clrscr();
            gotoxy(29, 13);
            cout << "YOU LOST!";
            getch();
            break;
        }
    }
    gotoxy(75, 3);
    cout << "         ";
    gotoxy(76, 3);
    cout << points;
    getch();
    if (strcmpi(st, mword) == 0)
    {
        clrscr();
        char TRY;
        gotoxy(29, 13);
        cout << "YOU WON!" << endl
             << "MOVE TO NEXT LEVEL-->>";
        gotoxy(38, 14);
        cin >> TRY;
        if (TRY == 'Y' || TRY == 'y')
            c6();
        else if (TRY == 'N' || TRY == 'n')
            front();
    }
    ca.score = points;
}
// guess a band
void c6()
{
    randomize();
    clrscr();
    int cnt = 0;
    boundary();
    gotoxy(34, 7);
    cout <<”LEVEL 6”;
    points += 5;
    gotoxy(68, 3);
    cout << "SCORE:";
    gotoxy(76, 3);
    cout << points;
    int r = random(5);
    strcpy(mword, s5[r]);
    int ll = 0, a;
    int total = strlen(mword);
    for (int i = 0; i <= strlen(mword); i++)
    {
        int x = 21 + i;
        gotoxy(x, 14);
        cout << "_"; // printing blank for word
        a = i + 22;
        if (mword[i] == '-')
        {
            gotoxy(a, 13);
            cout << "-";
            st[i] = '-';
            total--;
        }
    }
    while (total > 0)
    {
        gotoxy(24, 10);
        cout << "BAND NAME";
        int found = 0;
        gotoxy(68, 5 + ll);
        cin >> l; // character entered by user
        ll++;     // position of hyphens
        for (i = 0; i <= strlen(mword); i++)
        {
            a = i + 22;
            if (l == mword[i])
            {
                st[i] = mword[i];
                gotoxy(a, 13);
                cout << l;
                found = 1;
                total--;
            }
        }
        if (found == 0)
        {
            cnt++;
            points--;
        }
        gotoxy(75, 3);
        cout << "     ";
        gotoxy(76, 3);
        cout << points;
        gotoxy(55, 23);
        cout << "incorrect entries=" << cnt;
        if (cnt == 3)
        {
            clrscr();
            gotoxy(29, 13);
            cout << "YOU LOST!";
            getch();
            break;
        }
    }
    gotoxy(75, 3);
    cout << "         ";
    gotoxy(76, 3);
    cout << points;
    getch();
    if (strcmpi(st, mword) == 0)
    {
        clrscr();
        char TRY;
        gotoxy(29, 13);
        cout << "YOU WON!" << endl
             << "MOVE TO NEXT LEVEL-->>";
        gotoxy(38, 14);
        cin >> TRY;
        if (TRY == 'Y' || TRY == 'y')
            newgame();
        else if (TRY == 'N' || TRY == 'n')
            front();
    }
    ca.score = points;
}
void c3()
{
    randomize();
    clrscr();
    int cnt = 0;
    boundary();
    gotoxy(34, 7);
    cout <<”LEVEL 3”;
    gotoxy(68, 3);
    cout << "SCORE:";
    points += 5;
    gotoxy(76, 3);
    cout << points;
    int r = random(10);
    strcpy(mword, s2[r]);
    int ll = 0, a;
    int total = strlen(mword);
    for (int i = 0; i <= strlen(mword); i++)
    {
        int x = 21 + i;
        gotoxy(x, 14);
        cout << "_"; // printing blank for word
        a = i + 22;
        if (mword[i] == '-')
        {
            gotoxy(a, 13);
            cout << "-";
            st[i] = '-';
            total--;
        }
    }
    while (total > 0)
    {
        gotoxy(24, 10);
        cout << "COUNTRIES:";
        int found = 0;
        gotoxy(68, 5 + ll);
        cin >> l; // character entered by user
        ll++;     // position of hyphens
        for (i = 0; i <= strlen(mword); i++)
        {
            a = i + 22;
            if (l == mword[i])
            {
                st[i] = mword[i];
                gotoxy(a, 13);
                cout << l;
                found = 1;
                total--;
            }
        }
        if (found == 0)
        {
            cnt++;
            points--;
        }
        gotoxy(75, 3);
        cout << "     ";
        gotoxy(76, 3);
        cout << points;
        gotoxy(55, 23);
        cout << "incorrect entries=" << cnt;
        if (cnt == 3)
        {
            clrscr();
            gotoxy(29, 13);
            cout << "YOU LOST!";
            getch();
            break;
        }
    }
    gotoxy(75, 3);
    cout << "         ";
    gotoxy(76, 3);
    cout << points;
    getch();
    if (strcmpi(st, mword) == 0)
    {
        clrscr();
        char TRY;
        gotoxy(29, 13);
        cout << "YOU WON!" << endl
             << "MOVE TO NEXT LEVEL-->>";
        gotoxy(38, 14);
        cin >> TRY;
        if (TRY == 'Y' || TRY == 'y')
            c4();
        else if (TRY == 'N' || TRY == 'n')
            front();
    }
    ca.score = points;
}
// guess famous personalities
void c4()
{
    randomize();
    clrscr();
    int cnt = 0;
    boundary();
    gotoxy(34, 7);
    cout <<”LEVEL 4”;
    points += 5;
    gotoxy(68, 3);
    cout << "SCORE:";
    gotoxy(76, 3);
    cout << points;
    int r = random(10);
    strcpy(mword, s3[r]);
    int ll = 0, a;
    int total = strlen(mword);
    for (int i = 0; i <= strlen(mword); i++)
    {
        int x = 21 + i;
        gotoxy(x, 14);
        cout << "_"; // printing blank for word
        a = i + 22;
        if (mword[i] == '-')
        {
            gotoxy(a, 13);
            cout << "-";
            st[i] = '-';
            total--;
        }
    }
    while (total > 0)
    {
        gotoxy(24, 10);
        cout << "FAMOUS PERSONALITIES:";
        int found = 0;
        gotoxy(68, 5 + ll);
        cin >> l; // character entered by user
        ll++;     // position of hyphens
        for (i = 0; i <= strlen(mword); i++)
        {
            a = i + 22;
            if (l == mword[i])
            {
                st[i] = mword[i];
                gotoxy(a, 13);
                cout << l;
                found = 1;
                total--;
            }
        }
        if (found == 0)
        {
            cnt++;
            points--;
        }
        gotoxy(75, 3);
        cout << "     ";
        gotoxy(76, 3);
        cout << points;
        gotoxy(55, 23);
        cout << "incorrect entries=" << cnt;
        if (cnt == 3)
        {
            clrscr();
            gotoxy(29, 13);
            cout << "YOU LOST!";
            getch();
            break;
        }
    }
    gotoxy(75, 3);
    cout << "         ";
    gotoxy(76, 3);
    cout << points;
    getch();
    if (strcmpi(st, mword) == 0)
    {
        clrscr();
        char TRY;
        gotoxy(29, 13);
        cout << "YOU WON!" << endl
             << "MOVE TO NEXT LEVEL-->>";
        gotoxy(38, 14);
        cin >> TRY;
        if (TRY == 'Y' || TRY == 'y')
            c5();
        else if (TRY == 'N' || TRY == 'n')
            front();
    }
    ca.score = points;
}
void main()
{
    clrscr();
    getcandidate();
    front();
    putcandidate();
    getch();
}
