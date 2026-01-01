#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int r, c, m;

void set_mines(int** arr, int ir, int ic){
    int pos, row, col;
    int count=0;
    srand(time(0));
    while(count<m){
        pos = rand()%(r*c);
        row = pos/c;
        col = pos%c;
        if (row!=ir && col!=ic && arr[row][col]!=-1){
            arr[row][col] = -1;
            count++;
        }
    }
}

void set_values(int** arr){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (arr[i][j] != -1){
                if (i>0){   
                    if (arr[i-1][j] == -1) arr[i][j]++;
                    if (j>0 && arr[i-1][j-1] == -1) arr[i][j]++; 
                    if (j<c-1 && arr[i-1][j+1] == -1) arr[i][j]++;
                }
                if (i<r-1){
                    if (arr[i+1][j] == -1) arr[i][j]++;
                    if (j>0 && arr[i+1][j-1] == -1) arr[i][j]++; 
                    if (j<c-1 && arr[i+1][j+1] == -1) arr[i][j]++;
                }
                if (j>0 && arr[i][j-1] == -1) arr[i][j]++;
                if (j<c-1 && arr[i][j+1] == -1) arr[i][j]++; 
            }
        }
    }
}

void display_val(int** arr){
    cout << "   ";
    for (int i=0; i<c; i++) cout << "   " << i << "  ";
    cout << endl;
    for (int i=0; i<r; i++){
        if (i==0){
            cout << "   ";
            for (int j=0; j<c; j++){cout << " _____";}
            cout << endl;
        }
        for (int k=0; k<3; k++){
            if (k==1) cout << ' ' << i << " |";
            else cout << "   |";

            for (int j=0; j<c; j++){
                if (k==2) cout << "_____|";
                else if (k==1){
                    cout << "  ";
                    if (arr[i][j]==-1){cout << "*  |";}
                    else {
                        if (arr[i][j]==1) cout << "\033[1;34m";
                        else if (arr[i][j]==2) cout << "\033[1;32m";
                        else if (arr[i][j]==3) cout << "\033[1;31m";
                        else if (arr[i][j]==4) cout << "\033[1;94m";
                        cout << arr[i][j] << "  \033[0m|";
                    }
                }
                else cout << "     |";
            }
            cout << endl;
        } 
    }
}

void rev_zero(int** arr, char** disp, int i, int j){
    disp[i][j] = arr[i][j] + '0';
    if (i>0){   
        if (arr[i-1][j]==0 && disp[i-1][j]!='0') rev_zero(arr, disp, i-1, j);
        else disp[i-1][j] = arr[i-1][j] + '0';
        if (j>0){
            if (arr[i-1][j-1]==0 && disp[i-1][j-1]!='0') rev_zero(arr, disp, i-1, j-1);
            else disp[i-1][j-1] = arr[i-1][j-1] + '0';
        }
        if (j<c-1){
            if (arr[i-1][j+1]==0 && disp[i-1][j+1]!='0') rev_zero(arr, disp, i-1, j+1);
            else disp[i-1][j+1] = arr[i-1][j+1] + '0';
        }
    }
    if (i<r-1){
        if (arr[i+1][j]==0 && disp[i+1][j]!='0') rev_zero(arr, disp, i+1, j);
        else disp[i+1][j] = arr[i+1][j] + '0';
        if (j>0){             
            if (arr[i+1][j-1]==0 && disp[i+1][j-1]!='0') rev_zero(arr, disp, i+1, j-1);
            else disp[i+1][j-1] = arr[i+1][j-1] + '0';
        }
        if (j<c-1){
            if (arr[i+1][j+1]==0 && disp[i+1][j+1]!='0') rev_zero(arr, disp, i+1, j+1);
            else disp[i+1][j+1] = arr[i+1][j+1] + '0';
        }
    }
    if (j>0){   
        if (arr[i][j-1]==0 && disp[i][j-1]!='0') rev_zero(arr, disp, i, j-1);
        else disp[i][j-1] = arr[i][j-1] + '0';
    }
    if (j<c-1){
        if (arr[i][j+1]==0 && disp[i][j+1]!='0') rev_zero(arr, disp, i, j+1);
        else disp[i][j+1] = arr[i][j+1] + '0';
    }
}

int count_flags(char** arr, int i, int j){
    int count=0;
    if (i>0){   
        if (arr[i-1][j] == 'F') count++;
        if (j>0 && arr[i-1][j-1] == 'F') count++;
        if (j<c-1 && arr[i-1][j+1] == 'F') count++;
    }
    if (i<r-1){
        if (arr[i+1][j] == 'F') count++;
        if (j>0 && arr[i+1][j-1] == 'F') count++;
        if (j<c-1 && arr[i+1][j+1] == 'F') count++;
    }
    if (j>0 && arr[i][j-1] == 'F') count++;
    if (j<c-1 && arr[i][j+1] == 'F') count++;
    return count;
}

bool chord(int** arr, int ir, int ic, char** disp){
    int count=count_flags(disp, ir, ic);
    bool hit = false;
    if (count!= arr[ir][ic]) return false;
    for (int di=-1; di<=1; di++){
        for (int dj=-1; dj<=1; dj++){
            if (!(di==0 && dj==0)){
                int ni=ir+di;
                int nj=ic+dj;
                if (ni>=0 && ni<r && nj>=0 && nj<c){
                    if (arr[ni][nj]==-1) hit=true;
                    else if (arr[ni][nj]==0) rev_zero(arr, disp, ni, nj);
                    else disp[ni][nj] = arr[ni][nj]+'0';
                }
            }
        }
    }
    return hit;
}

void instructions(){
    cout << "**** MINESWEEPER ****\n";
    cout << "1. Enter row and column number to select a cell e.g. '2 3'\n";
    cout << "2. In order to flag a mine, enter F.\n";
    cout << "3. To check a cell, enter C.\n";
    cout << "4. For chording a revealed cell, enter C after row and column number.\n";
    cout << "If a flag is placed on a wrong neighbour cell and a mine is revealed during chording, you will lose.\n ";
}

void difficulty_level(){
    cout << "Select difficulty level: \n";
    cout << "\t1. Beginner (8x8, 10 mines)\n\t2. Intermediate (16x16, 40 mines)\n\t3. Expert (30x16, 99 mines)\n\t4. Custom\n";
    cout << "Level: ";
    int level;
    while (!(cin >> level)){
        cin.clear();
        cin.ignore(10000, '\n');
    }
    while (level<1 || level>4){
        cout << "Invalid difficulty level. Enter level: ";
        while (!(cin >> level)){
            cin.clear();
            cin.ignore(10000, '\n');
        }     
    }
    if (level==1) r=8, c=8, m=10; 
    else if (level==2) r=16, c=16, m=40;
    else if (level==3) r=16, c=30, m=99;
    else{
        do{
            cout << "Enter number of rows (>3): ";
            while (!(cin >> r)){
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cout << "Enter number of columns(>3): ";
            while (!(cin >> c)){
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while(r<=3 || c<=3);
        int max = 0.35*r*c + 1;
        do {
            cout << "Enter number of mines(<" << max+1 << "): ";
            while (!(cin >> m)){
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (m>max);
    }
}

bool disp_move(int** arr, char** disp){
    int count=0;
    cout << "   ";
    for (int i=0; i<c; i++) cout << "   " << i << "  ";
    cout << endl;
    for (int i=0; i<r; i++){
        if (i==0){
            cout << "   ";
            for (int j=0; j<c; j++){ cout << " _____"; }
            cout << endl;
        }
        for (int k=0; k<3; k++){
            if (k==1) cout << ' ' << i << " |";
            else cout << "   |";

            for (int j=0; j<c; j++){
                if (k==2) cout << "_____|";
                else if (k==1){
                    if (disp[i][j]!='\0'){
                        cout << "  ";
                        if (arr[i][j]==1) cout << "\033[1;34m";
                        else if (arr[i][j]==2) cout << "\033[1;32m";
                        else if (arr[i][j]==3) cout << "\033[1;31m";
                        else if (arr[i][j]==4) cout << "\033[1;94m";
                        cout << disp[i][j] << "  \033[0m|";
                        if (disp[i][j]!='F') count++;
                    } else cout << "     |";
                }
                else cout << "     |";
            }
            cout << endl;
        } 
    }
    if (count == (r*c)-m) return true;
    else return false;
}

int main(){
    instructions();
    difficulty_level();

    int** grid = new int*[r];
    char** disp_char = new char*[r];
    for (int i=0; i<r; i++){
        grid[i] = new int[c];
        disp_char[i] = new char[c];
        for (int j=0; j<c; j++){
            grid[i][j]=0;
            disp_char[i][j]='\0';
        }
    }

    disp_move(grid, disp_char);
    bool gameover=false, win=false;
    int r_pos, c_pos;
    char move;
    do {
        do{
            cout << "Enter cell coordinates [row] [col]: ";
            cin >> r_pos >> c_pos;
            if (cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Enter numbers only\n";
                continue;
            }
        } while (r_pos<0 || r_pos>=r || c_pos<0 || c_pos>=c);
        do{
            cout << "Enter your move [F/C]: ";
            cin >> move;
        } while(move!='C' && move!='c' && move!='F' && move!='f');
        if (move=='f' || move=='F'){disp_char[r_pos][c_pos] = 'F';}
        system("cls");
        disp_move(grid, disp_char);
    } while (move!='C' && move!='c');
    set_mines(grid, r_pos, c_pos);
    set_values(grid);
    if (grid[r_pos][c_pos]==0) rev_zero(grid, disp_char, r_pos, c_pos);
    else disp_char[r_pos][c_pos] = grid[r_pos][c_pos]+'0';
    system("cls");
    disp_move(grid, disp_char);
    while (!gameover && !win){
        do{
            cout << "Enter cell coordinates [row] [col]: ";
            cin >> r_pos >> c_pos;
            if (cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Enter numbers only\n";
                continue;
            }
        } while (r_pos<0 || r_pos>=r || c_pos<0 || c_pos>=c);
        do{
            cout << "Enter your move [F/C]: ";
            cin >> move;
        } while(move!='C' && move!='c' && move!='F' && move!='f');
        if (move=='f' || move=='F'){    
            if (disp_char[r_pos][c_pos]=='\0') disp_char[r_pos][c_pos] = 'F';
        } else if (move=='c' || move=='C'){     
            if (grid[r_pos][c_pos] == -1){
                gameover = true;
            } else {
                if (grid[r_pos][c_pos] == 0){
                    rev_zero(grid, disp_char, r_pos, c_pos);
                } else {
                    if (disp_char[r_pos][c_pos]!='\0' && disp_char[r_pos][c_pos]!='F' && disp_char[r_pos][c_pos]!='0'){ gameover=chord(grid, r_pos, c_pos, disp_char);}
                    else disp_char[r_pos][c_pos] = grid[r_pos][c_pos] + '0';
                }
            }
        }
        system("cls");
        if (gameover){
            display_val(grid);
            cout << "YOU LOST!!!\n";
            system("pause");
        }
        else{
            if (disp_move(grid, disp_char)){
                win = true;
                cout << "You won!\n";
            }
        }     
    }
    for (int i=0; i<r; i++){
        delete[] grid[i];
        grid[i] = nullptr;
        delete[] disp_char[i];
        disp_char[i] = nullptr;
    }
    delete[] grid;
    delete[] disp_char;
    return 0;
}
