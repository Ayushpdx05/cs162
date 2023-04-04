#include <iostream>
#include <cstdlib>
#include <ctime>



using namespace std;


int moneyrack_spot();

void update_shooting_results(int player_results[5][5], int input);

void displaying_xom(int player_results[5][5], int i);

void displaying_results(int player_results[5][5],int theSize, int i);

int main(){
    srand(time(0)); //setting the seed for rand
int question;

int player_one_array[5][5] = {0};
    int player_two_array[5][5] = {0}; //0 initialization
    cout << "Welcome to the 3pt shooting contest!" << endl;
    update_shooting_results(player_one_array,moneyrack_spot());
    update_shooting_results(player_two_array,moneyrack_spot());
    displaying_xom(player_one_array,1);
    displaying_xom(player_two_array,2);
    while (true) {
        cout << "Please Decide wheter you want to play again or quit the program. (1 - play again) (2 - Quit program and display results)";
	cin >> question;
        if (question == 1) {
            cout << "Playing game again..." << endl;
            update_shooting_results(player_one_array,moneyrack_spot());
            update_shooting_results(player_two_array,moneyrack_spot());
            displaying_xom(player_one_array,1);
            displaying_xom(player_two_array,2);
        } else if (question == 2) {
            cout << "thanks for playing" << endl;
            displaying_results(player_one_array,5,1);
            displaying_results(player_two_array,5,2);
            break;
        } else {
            cout << "Invalid input, please try again." << endl;
        }
    }
    return 0;
}

int moneyrack_spot(){
    int input;
    cout <<  "Where do you want to put your money-ball rack? Enter 1-5:"  <<  endl;
    cin >> input;
    while(input < 1 || input > 5) { // re-prompt until valid input is given
        cout << "Invalid input. Please enter a number between 1 and 5:" << endl;
        cin >> input;
    }
return input;
}

void update_shooting_results(int player_results[5][5], int input) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (input - 1 == i) {
                int shot_success = rand()%2;
                if (shot_success == 0) {
                    player_results[i][j] = 2;
                } else {
                    player_results[i][j] = 0;
                }
            } else {
                int shot_success = rand()%2;
                if(shot_success == 0 && j == 4)
                    player_results[i][j] = 2;
                else if(shot_success == 0) {
                    player_results[i][j] = 1;
                } else {
                    player_results[i][j] = 0;
                }
            }
        }
    }
}
    
void displaying_xom(int player_results[5][5],int i){
    cout << "player results"<< i << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if(player_results[i][j] == 0){
                cout << " x ";
            }
            else if(player_results[i][j] == 1){
                cout << " O ";
            }
            else if(player_results[i][j] == 2){
                cout << " M ";
            }
        }
    cout << endl;
    }
    cout << endl; //additional space between each row
}




void printArray_p1(int player_results[5][5], int theSize){ //function to print out the array
    for (int i = 0; i < theSize; i++)
    {   
        for(int j = 0; j < theSize; j++){
            if(player_results[i][j] == 0){
                cout << " x " << endl;
            }
            else if(player_results[i][j] == 1){
                cout << " O " << endl;
            }
            else if(player_results[i][j] == 2){
                cout << " M " << endl;
            }
            
        }
        
    }
}

void displaying_results(int player_results[5][5],int theSize,int i){
    int sum = 0;
     for (int i = 0; i < theSize; i++)
    {   
        for(int j = 0; j < theSize; j++){
            sum+= player_results[i][j];
        }
    }
     cout << " total score for the player " << i << " is " << sum << endl;
}


void comparing_scores(int player_results_1[5][5],int player_results_2[5][5]){
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            sum1 += player_results_1[i][j];
            sum2 += player_results_2[i][j];
        }
    }
    if(sum1 == sum2){
        cout << "it was a tie game" << endl;
    }
    if(sum1 > sum2){
        cout << "player one won" << endl;
    }
    if(sum1 < sum2){
        cout << "player two won" << endl;
    }
}


