#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int n, Score[10], R = 0;
struct Player{
        char name[10];
    }v[11];
void read_player()
{
    int l, i, j;
    system("CLS");
    for(i = 1; i <= n; i++)
        cout << "__________";
    cout << "_\n";
    for(i = 1; i <= n; i++)
    {
        cout << "| " << v[i].name;
        l = strlen(v[i].name);
        for(j = 1; j <= 8 - l; j++)
            cout << " ";
    }
    cout << "|\n";
    for(i = 1; i <= n; i++)
        cout << "----------";
    cout << "-\n";
}
void afis()
{
    int i, l, j;
    read_player();
    R++;
    cout << " Round " << R << ":\n";
    for(i = 1; i <= n; i++)
    {
        cout << "| ";
        l = 0;
        j = Score[i];
        if(j == 0)
        {
            l = 1;
        }else
        {
            while(j)
            {
                l++;
                j /= 10;
            }
        }
        switch(l)
        {
            case(1):cout << "   " << Score[i] << "    ";
            break;
            case(2):cout << "  " << Score[i] << "    ";
            break;
            case(3):cout << "  " << Score[i] << "   ";
            break;
        }
    }
    cout << "|\n";
    for(i = 1; i <= n; i++)
        cout << "----------";
    cout << "-\n";
}
bool Game()
{
    int i, Curent, done = 0;
    afis();
    cout << "   Points earned:\n\n";
    for(i = 1; i <= n; i++)
    {
        cout << " " << v[i].name << ": ";
        cin >> Curent;
        Score[i] += Curent;
        if(Score[i] >= 500)
            done = 1;
    }
    if(done)
        return 1;
    return 0;
}
int main()
{
    int g, i, loc = 1;

    cout << "The number of players is: ";
    cin >> n;
    cout << "Players' names must be less than 8 characters \n";
    cout << "Enter the names of the players: \n";
    for(i = 1; i <= n; i++)
        cin >> v[i].name;
    while(!Game());
    system("CLS");
    do
    {
        g = 1;
        for(i = 1; i < n; i++)
            if(Score[i] > Score[i + 1])
            {
                g = 0;
                swap(v[i].name,v[i + 1].name);
                swap(Score[i], Score[i + 1]);
            }
    }while(!g);
    cout << "\n   RANKING:\n\n";
    for(i = 1; i <= n; i++)
    {
        cout << " Seats " << loc << ": " << v[i].name << ": " << Score[i] << "\n";
        if(Score[i] != Score[i + 1])
            loc++;
    }
    cout << "\n   Congrats!!!\n\n\n";
    cout << "You want to close the application?  ";
    cin >> i;
    return 0;
}
