//File: A2_S5_20221099_5.cpp
//purpose: Add a new player and score, Print the top 10 players and score and Search for a player's highest scor.
//Author: Abdelmonaem Mahmoud
//Section: S5
//ID: 20220206
//TA: Eng/Maya
//Date: 3 Nov 2023

#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

struct player
{
    string player_name;
    int player_High_Score;
};


bool o(const player& x, const player& y)
{
    return x.player_High_Score > y.player_High_Score;
}

int main()
{
    deque <player> players;
    
    while (true)
    {
        cout<<"\nMenu:\n"
            <<"1- Add a new player\n"
            <<"2- Print the top 10 players and score\n"
            <<"3- Search for a player's highest scor\n"
            <<"4- Exit\n"
            <<"Enter your choice: ";
        int choice;
        cin>>choice;
        if (choice==1)
        {
            player player;
            cout<<"player name: ";
            cin>>player.player_name;
            cout<<"player score: ";
            cin>>player.player_High_Score;

            players.push_back(player);

            sort(players.begin(), players.end(), o);

            if (players.size()>10)
            {
                players.pop_back();
            }
        }
        else if (choice==2)
        {
            cout<<endl;
            for (const auto& player : players)
            {
                cout<<player.player_name<<"  "<<player.player_High_Score<<endl;
            }
            
        }
        else if (choice==3)
        {
            string player_name2;
            cout<<"Enter player name: ";
            cin>>player_name2;
            bool found=false;

            for (const auto& player : players)
            {
                if (player.player_name==player_name2)
                {
                    cout<<endl<<player.player_name<<" "<<player.player_High_Score<<endl;
                    found=true;
                    break;
                }
                
            }
            
            if (!found)
            {
                cout<<"Not exist.";
            }
            
        }
        else if (choice==4)
        {
            cout<<"Exit program.\n";
            return 0;
        }
    
    }
}