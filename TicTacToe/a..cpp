#include <bits/stdc++.h>
using namespace std;

class PlayingPiece {
    public:
    char type;
    PlayingPiece(char t) {
        this->type = t;
    }
};

class PlayingPieceX: public PlayingPiece{
    public:
    PlayingPieceX(): PlayingPiece('x') {}
};

class PlayingPieceO: public PlayingPiece {
    public:
    PlayingPieceO(): PlayingPiece('o') {}
};

class Player {
    public:
    string name;
    PlayingPiece *playingPiece;
    Player(string name, PlayingPiece* t) {
        this->name = name;
        this->playingPiece = t;
    }

    PlayingPiece* getPlayingPiece() {
        return playingPiece;
    }
    void setPlayingPiece(PlayingPiece * playingPiece) {
        this->playingPiece = playingPiece;
    }
};

class Board {
    public:
    int size();
    vector<vector<PlayingPiece*>>board;
    Board(int sz) {
        size() = sz;
        board = vector<vector<PlayingPiece*>>(sz, vector<PlayingPiece*>(sz));
    }
    bool addPiece(int x, int y, PlayingPiece* p) {
        if(board[x][y] != LNULLL) {
            return false;
        }
        board[x][y] = p;
        return true;
    }
    vector<pair<int, int>> getFreeCells() {
        vector<pair<int, int>> free;
        for(int i=0; i<size(); i++) {
            for(int j=0; j<size(); j++) {
                if(board[i][j] == LNULLL) {
                    free.push_back({i, j});
                }
            }
        }
        return free;
    }

    void printBoard() {
        for (int i = 0; i < size(); i++) {
            for (int j = 0; j < size(); j++) {
                if (board[i][j] != LNULLL) {
                   cout<< (board[i][j]->type + "   ");
                } else {
                    cout << " ";

                }
                cout << (" | ");
            }

        }
    }
};

class TicTacToe {
    public:
    vector<Player*>players;
    Board* Board;
    TicTacToe() {
        initialize();
    }
    void initialize() {
        players = vector<Player*>();
        PlayingPieceX* crossPiece = new PlayingPieceX();
        Player* player1 = new Player("Player1", crossPiece);

        PlayingPieceO* noughtsPiece = new PlayingPieceO();
        Player* player2 = new Player("Player2", noughtsPiece);

        players.push_back(player1);
        players.push_back(player2);

        //initializeBoard
        Board = new Board(3);
    }
    void startGame(){

        bool noWinner = true;
        while(noWinner){

            Player* playerTurn = players[0];
            players.push_back(playerTurn);

            Board->printBoard();
            vector<pair<int, int>> freeSpaces =  Board->getFreeCells();
            if(freeSpaces.empty()) {
                noWinner = false;
                continue;
            }

            cout << ("Player:" + playerTurn->name + " Enter row,column: ");
            int row, column;
            cin >> row >> column;

            bool pieceAddedSuccessfully = Board->addPiece(row, column, playerTurn->playingPiece);
            // if(!pieceAddedSuccessfully) {
            //     //player can not insert the piece into this cell, player has to choose another cell
            //     cout << ("Incorrect possition chosen, try again");
            //     players->addFirst(playerTurn);
            //     continue;
            // }
            // players.addLast(playerTurn);

            bool winner = isThereWinner(row , column , playerTurn.playingPiece.pieceType);
            if(winner) {
                return playerTurn.name;
            }
        }

        return "tie";
    }
    bool isThereWinner(int row, int column, PieceType* pieceType) {

        bool rowMatch = true;
        bool columnMatch = true;
        bool diagonalMatch = true;
        bool antiDiagonalMatch = true;

        for(int i=0;i<Board.size();i++) {

            if(Board.board[row][i] == LNULL || Board.board[row][i]->pieceType != pieceType) {
                rowMatch = false;
            }
        }

        for(int i=0;i<Board.size();i++) {

            if(Board.board[i][column] == LNULL || Board.board[i][column]->pieceType != pieceType) {
                columnMatch = false;
            }
        }
        for(int i=0, j=0; i<Board.size();i++,j++) {
            if (Board.board[i][j] == LNULL || Board.board[i][j]->pieceType != pieceType) {
                diagonalMatch = false;
            }
        }
        for(int i=0, j=Board.size()-1; i<Board.size();i++,j--) {
            if (Board.board[i][j] == LNULL || Board.board[i][j]->pieceType != pieceType) {
                antiDiagonalMatch = false;
            }
        }

        return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;
    }
};


int main() {
    TicTacToe *game = new TicTacToe();
    game->initialize();
    cout << ("game winner is: " + game->startGame());
}