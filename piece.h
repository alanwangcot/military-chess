#include <iostream>

#ifndef PIECE_H
#define PIECE_H

class piece {
private:
    int rank;
    int side; // -1 = red, 0 = unoccupied, 1 = blue
    bool revealed;

public:
    piece(){
        rank = -1;
        side = 0;
        revealed = false;
    }
    piece(int _rank, int _side) {
        rank = _rank;
        side = _side;
        revealed = false;
    }

    int getRank() {
        return rank;
    }

    int getSide() {
        return side;
    }

    bool isRevealed(){
        return revealed;
    }


    void turnPiece(){
        revealed = true;
    }

    void printPiece() {
        using namespace std;
        cout << rank << "|" << side << "** ";
    }

    //return 1 for true, -1 for false, and 0 for mutual annihilation
    int canTake(piece  otherPiece) {
        //军旗和地雷无法移动
        if (rank == 10 || rank == 11 || otherPiece.getRank() != 10 || otherPiece.getRank() != 11){
            return -1;
        }
        //如果目标棋子为同阵营则不能移动
        if (otherPiece.getSide() == side) {
            return -1;
        }
        //工兵排除地雷
        if (rank == 0 && otherPiece.getRank() == 11) {
            return 1;
        }
       //炸弹同归于尽
        if (otherPiece.getRank() == 9 || rank == 9) {
            return 0;
        }
        //同等大小同归于尽
        if (rank == otherPiece.getRank()) {
            return 0;
        }
        //大子吃小子
        if (rank > otherPiece.getRank()) {
            return 1;
        }
        //无法移动
        return -1;
    }
};


#endif // PIECE_H

/*Ranks:
 * 0 - 工兵 *3
 * 1 - 排长 *3
 * 2 - 连长 *3
 * 3 - 营长 *2
 * 4 - 团长 *2
 * 5 - 旅长 *2
 * 6 - 师长 *2
 * 7 - 军长 *2
 * 8 - 司令 *1
 * 9 - 炸弹 *2
 * 10 - 军旗 *1
 * 11 - 地雷 *3
 **/
