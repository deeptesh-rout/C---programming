#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int userBatting, userBowling;
    int userWicket = 0, systemWicket = 0;
    int over, user, option;
    int userScore = 0, systemScore = 0;
    int computerToss, computerBowling, computerBatting;

    cout << "Ladies and Gentlemen, a great match between the user and the system. Let's see who will win the match" << endl;
    cout << "How many overs do you want to play?" << endl;
    cin >> over;
    cout << "Total 5 wickets in each team" << endl;
    cout << "It's toss time. What is your call?" << endl;
    cout << "Head (0), Tail (1): ";
    cin >> user;

    computerToss = rand() % 2;

    if (computerToss == user) {
        cout << "Congratulations, you won the toss" << endl;
        cout << "What do you want to choose, batting or bowling first? [(1): bat or (2): ball]" << endl;
        cin >> option;

        if (option == 1) {
            cout << "You chose batting first (System will bowl to you)" << endl;
            cout << "Enter 1: One run, 2: Two runs, 3: Three runs, 4: Four runs, 5: Five runs, 6: Six runs" << endl;

            for (int i = 1; i <= over; i++) {
                for (int j = 1; j <= 6; j++) {
                    cout << "Bat:";
                    cin >> userBatting;
                    computerBowling = (rand() % 6) + 1;
                    if (userBatting != computerBowling) {
                        cout << "You hit: " << userBatting << " runs, System chose: " << computerBowling << endl;
                        userScore += userBatting;
                    } else {
                        userWicket++;
                        cout << "Oops, you're out because your choice and the computer's choice are the same. You: " << userBatting << ", System chose: " << computerBowling << endl;
                    }
                    if (userWicket == 5) break;
                }
                if (userWicket == 5) break;
                cout << "After completing " << i << " over(s), the score is " << userScore << " runs with the loss of " << userWicket << " wicket(s)" << endl;
            }

            cout << "Total score: " << userScore << endl;
            cout << "2nd innings start in a few sec, \"now it's your turn to bowl and defend your Score\" (Target): " << (userScore + 1) << "\nchoose the same number as system chooses for taking wicket" << endl;

            for (int i = 1; i <= over; i++) {
                for (int j = 1; j <= 6; j++) {
                    cout << "Ball:";
                    cin >> userBowling;
                    computerBatting = (rand() % 6) + 1;

                    if (userBowling != computerBatting) {
                        cout << "System hit: " << computerBatting << " runs, You chose: " << userBowling << endl;
                        systemScore += computerBatting;
                    } else {
                        systemWicket++;
                        cout << "Yes, you got it, " << systemWicket << " wickets gone of System because your choice and the computer's choice are the same. You: " << userBowling << ", System chose: " << computerBatting << endl;
                    }
                    if (systemWicket == 5) break;
                }
                if (systemWicket == 5) break;
                cout << "After completing " << i << " over(s), the score is " << systemScore << " runs with the loss of " << systemWicket << " wicket(s)" << endl;
            }

            if (userScore > systemScore) {
                cout << "Congratulations, you won the game by: " << (userScore - systemScore) << " runs" << endl;
            } else if (userScore < systemScore) {
                cout << "Oo you lose the game by: " << (5 - systemWicket) << " wickets, but nice try. Best of Luck for the next game" << endl;
            } else {
                cout << "Oo it is a tie score between You and the System " << userScore << " - " << systemScore << " runs, Well played" << endl;
            }
        } else if (option == 2) {
            cout << "You chose bowling first (System will bat first...)" << endl;
            cout << "Enter 1: One run, 2: Two runs, 3: Three runs, 4: Four runs, 5: Five runs, 6: Six runs" << endl;

            for (int i = 1; i <= over; i++) {
                for (int j = 1; j <= 6; j++) {
                    cout << "Ball:";
                    cin >> userBowling;
                    computerBatting = (rand() % 6) + 1;

                    if (userBowling != computerBatting) {
                        cout << "System hit: " << computerBatting << " runs, You chose: " << userBowling << endl;
                        systemScore += computerBatting;
                    } else {
                        systemWicket++;
                        cout << "Yes, you got it, " << systemWicket << " wickets gone of System because your choice and the computer's choice are the same. You: " << userBowling << ", System chose: " << computerBatting << endl;
                    }
                    if (systemWicket == 5) break;
                }
                if (systemWicket == 5) break;
                cout << "After completing " << i << " over(s), the score is " << systemScore << " runs with the loss of " << systemWicket << " wicket(s)" << endl;
            }

            cout << "Total score: " << systemScore << endl;
            cout << "2nd innings start in a few sec, \"now it's your turn to bat and chase the Score\" (Target): " << (systemScore + 1) << endl;

            for (int i = 1; i <= over; i++) {
                for (int j = 1; j <= 6; j++) {
                    cout << "Bat:";
                    cin >> userBatting;
                    computerBowling = (rand() % 6) + 1;
                    if (userBatting != computerBowling) {
                        cout << "You hit: " << userBatting << " runs, System chose: " << computerBowling << endl;
                        userScore += userBatting;
                    } else {
                        userWicket++;
                        cout << "Oops, you're out because your choice and the computer's choice are the same. You: " << userBatting << ", System chose: " << computerBowling << endl;
                    }
                    if (userWicket == 5) break;
                }
                if (userWicket == 5) break;
                cout << "After completing " << i << " over(s), the score is " << userScore << " runs with the loss of " << userWicket << " wicket(s)" << endl;
            }

            if (userScore > systemScore) {
                cout << "Congratulations, you won the game by: " << (5 - systemWicket) << " wickets" << endl;
            } else if (userScore < systemScore) {
                cout << "You lose the game by: " << (systemScore - userScore) << " runs, but nice try. Best of Luck for the next game" << endl;
            } else {
                cout << "Oo it is a tie score between You and the System " << userScore << " - " << systemScore << " runs, Well played" << endl;
            }
        }
    } else {
        cout << "System won the toss and chose batting first" << endl;
        cout << "Enter 1: One run, 2: Two runs, 3: Three runs, 4: Four runs, 5: Five runs, 6: Six runs" << endl;

        for (int i = 1; i <= over; i++) {
            for (int j = 1; j <= 6; j++) {
                cout << "Ball:";
                cin >> userBowling;
                computerBatting = (rand() % 6) + 1;

                if (userBowling != computerBatting) {
                    cout << "System hit: " << computerBatting << " runs, You chose: " << userBowling << endl;
                    systemScore += computerBatting;
                } else {
                    systemWicket++;
                    cout << "Yes, you got it, " << systemWicket << " wickets gone of System because your choice and the computer's choice are the same. You: " << userBowling << ", System chose: " << computerBatting << endl;
                }
                if (systemWicket == 5) break;
            }
            if (systemWicket == 5) break;
            cout << "After completing " << i << " over(s), the score is " << systemScore << " runs with the loss of " << systemWicket << " wicket(s)" << endl;
        }

        cout << "Total score: " << systemScore << endl;
        cout << "2nd innings start in a few sec, \"now it's your turn to bat and chase the Score\" (Target): " << (systemScore + 1) << endl;

        for (int i = 1; i <= over; i++) {
            for (int j = 1; j <= 6; j++) {
                cout << "Bat:";
                cin >> userBatting;
                computerBowling = (rand() % 6) + 1;
                if (userBatting != computerBowling) {
                    cout << "You hit: " << userBatting << " runs, System chose: " << computerBowling << endl;
                    userScore += userBatting;
                } else {
                    userWicket++;
                    cout << "Oops, you're out because your choice and the computer's choice are the same. You: " << userBatting << ", System chose: " << computerBowling << endl;
                }
                if (userWicket == 5) break;
            }
            if (userWicket == 5) break;
            cout << "After completing " << i << " over(s), the score is " << userScore << " runs with the loss of " << userWicket << " wicket(s)" << endl;
        }

        if (userScore > systemScore) {
            cout << "Congratulations, you won the game by: " << (5 - systemWicket) << " wickets" << endl;
        } else if (userScore < systemScore) {
            cout << "You lose the game by: " << (systemScore - userScore) << " runs, but nice try. Best of Luck for the next game" << endl;
        } else {
            cout << "Oo it is a tie score between You and the System " << userScore << " - " << systemScore << " runs, Well played" << endl;
        }
    }
    return 0;
}
