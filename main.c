//
//
//
//  tictactoe



#include <stdio.h>

//create array and set to default with dashes
void initialize(char arr[3][3], char symbol)
{
    int i;
    for (i = 0 ; i < 3; ++i) {
        
        int j;
        for (j = 0 ; j < 3; ++j) {
            
            arr[i][j] = symbol;
        }
    }
}

//update array using xy coordinates from player
int update(char arr [3][3], int coordx, int coordy, int player_num) //
{
    
    if (arr[coordx][coordy] != '-') {
        return 0;
    }
    
        if (player_num == 1) {
            arr[coordx][coordy] = 'x';
            return 1;
        }
        
        else if (player_num == 2) {
            arr[coordx][coordy] = 'o';
            return 2;
        }
    return 3;
}

//
//update array using xy coordinates from player 2 using o gamepiece
void updatep2(char arr [3][3], int p2coordx, int p2coordy)
{
    arr[p2coordx][p2coordy] = 'o';
}


//print all values and coordinates of array
void print(char arr[3][3])
{
    int y;
    for (y = 2 ; y >= 0; --y) {
        int x;
        for (x = 0 ; x < 3; ++x) {
            printf("arr[%d][%d] => %c ", x, y, arr[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

////request input of x gamepiece from player 1
//void p1gpc (char p1gamepiece)
//{
//    char buffer;
//
//    printf("Player 1 enter 'x': ");
//    scanf("%c", &p1gamepiece);
//    scanf("%c", &buffer);
//    printf("%c\n", p1gamepiece);
//    if (p1gamepiece == 'x') {
//        return; }
//
//    while (p1gamepiece != 'x') {
//        printf("Player 1 re-enter 'x'\n");
//        scanf("%c", &p1gamepiece);
//        scanf("%c", &buffer);
//        printf("%c\n", p1gamepiece);
//    }
//}

//request input of xy coordinates from player 1 and updates player 1's place on array
void check_coord (char arr [3][3], int coordx, int coordy, int player_num)
{
    
    char buffer;
    
    int success = 0;;
    while (success == 0){
        printf("Player %d enter x-coordinate from 0-2\n", player_num);
        scanf("%d", &coordx);
        scanf("%c", &buffer);
        printf("X-Coord = %d\n", coordx);
        
        while (coordx < 0 || coordx > 2){
            printf("Player %d re-enter x-coordinate from 0-2\n", player_num);
            scanf("%d", &coordx);
            scanf("%c", &buffer);
        }
        
        printf("Player %d enter y-coordinate from 0-2\n", player_num);
        scanf("%d", &coordy);
        scanf("%c", &buffer);
        printf("Y-Coord = %d\n", coordy);
        
        while (coordy < 0 || coordy > 2) {
            printf("Player %d re-enter y-coordinate from 0-2\n", player_num);
            scanf("%d", &coordy);
            scanf("%c", &buffer);
        }
        
        success = update (arr, coordx, coordy, player_num);
        if (success == 0) {
            //print location is already occupied
        }
    }
    
    return;
    
    
}

////request input of o gamepiece from player 2
//void p2gpc (char p2gamepiece)
//{
//    char buffer;
//
//    printf("Player 2 enter 'o': ");
//    scanf("%c", &p2gamepiece);
//    scanf("%c", &buffer);
//    printf("%c\n", p2gamepiece);
//
//    if (p2gamepiece == 'o') {
//        return; }
//
//    while (p2gamepiece != 'o') {
//        printf("Player 2 re-enter 'o'\n");
//        scanf("%c", &p2gamepiece);
//        scanf("%c", &buffer);
//        printf("%c\n", p2gamepiece);
//
//    }
//}

//request input of xy coordinates from player 2 and updates player 2's place on array
void p2coord (char arr [3][3], int p2coordx, int p2coordy)
{
    char buffer;
    
    printf("Player 2 enter x-coordinate from 0-2\n");
    scanf("%d", &p2coordx);
    scanf("%c", &buffer);
    printf("X-Coord = %d\n", p2coordx);
    
    while (p2coordx < 0 || p2coordx > 2) {
        printf("Player 2 re-enter x-coordinate from 0-2\n");
        scanf("%d", &p2coordx);
        scanf("%c", &buffer);
    }
    
    printf("Player 2 enter y-coordinate from 0-2\n");
    scanf("%d", &p2coordy);
    scanf("%c", &buffer);
    printf("Y-Coord = %d\n", p2coordy);
    
    while (p2coordy < 0 || p2coordy > 2) {
        printf("Player 1 re-enter y-coordinate from 0-2\n");
        scanf("%d", &p2coordy);
        scanf("%c", &buffer);
    }
    
    updatep2 (arr, p2coordx, p2coordy);
    
    return;
    
}


//check if any player won
void check_for_win (int* win_status, char gamepiece, char arr[3][3]) {
    
    
    int player_num;
    
    //analyze for wins in columns
    for (int x = 0; x < 3; ++x){
        int counter = 0;
        for (int y = 0; y < 3; ++y){
            if (arr [x][y] == gamepiece) {
                ++counter;
            }
            else {
                break;
            }
        }
        if (counter == 3){
            if (gamepiece == 'x') {
                player_num = 1;
            }
            else {
                player_num = 2;
            }
            printf("\nTictacoe! You win Player %d!\n\n", player_num);
          
            *win_status = 1;
            return;
        }
    }
    
    //analyze for wins in rows
    for (int y = 0; y < 3; ++y){
        int counter = 0;
        for (int x = 0; x < 3; ++x){
            if (arr [x][y] == gamepiece) {
                ++counter;
            }
            else {
                break;
            }
        }
        if (counter == 3){
            if (gamepiece == 'x') {
                player_num = 1;
            }
            else {
                player_num = 2;
            }
            printf("\nTictacoe! You win Player %d!\n\n", player_num);
            //not sure how to end the program after this
            *win_status = 1;
            return;
        }
    }
    
    //analyze for win diagonally from (0,0) to (2,2)
    for (int y = 0; y < 3; ++y){
        int counter = 0;
        if (arr [y][y] == gamepiece) {
            ++counter;
            
            if (counter == 3){
                if (gamepiece == 'x') {
                    player_num = 1;
                }
                else {
                    player_num = 2;
                }
                printf("\nTictacoe! You win Player %d!\n\n", player_num);
                //not sure how to end the program after this
                *win_status = 1;
                return;
                
            }
            
        }
        
        else {
            counter = 0;
        }
    }
    
    //analyze for win diagonally from (2,0) to (0,2)
    int x = 0;
    int y = 2;
    while (x <=2 && y >=0){
        int counter = 0;
        if (arr [x][y] == gamepiece) {
            ++counter;
            
            if (counter == 3){
                if (gamepiece == 'x') {
                    player_num = 1;
                }
                else {
                    player_num = 2;
                }
                printf("\nTictactoe! You win Player %d!\n\n", player_num);
                //not sure how to end the program after this
                *win_status = 1;
                return;
            }
            
        }
        
        else {
            counter = 0;
        }
        ++x;
        --y;
    }
    
    
    return;
}

int main (void)

{
    int win_status = 0;
    
    //        char p1gamepiece;
    //        char p2gamepiece;
    
    int coordx;
    int coordy;
    int player1 = 1;
    int player2 = 2;
    
    printf("Welcome to TicTactToe.\n\n");
    printf("Player 1 is using 'x' to play.\n");
    printf("Player 2 is using 'o' to play. \n\n");
    
    char arr[3][3];
    
    initialize(arr, '-');
    print(arr);
    
    while (win_status == 0) {
        
        //        p1gpc(p1gamepiece);
        check_coord(arr, coordx, coordy, player1);
        print(arr);
        check_for_win (&win_status,'x', arr);
        
        if (win_status == 1){
            return 1;}
        
        //        p2gpc(p2gamepiece);
        check_coord(arr, coordx, coordy, player2);
        print(arr);
        check_for_win (&win_status,'o', arr);
        
        if (win_status == 1){
            return 2;}
        
    }
    
}
