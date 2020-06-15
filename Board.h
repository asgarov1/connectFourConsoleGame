//
// Created by Javid Asgarov on 15.06.20.
//

#ifndef VIERGEWINNT_BOARD_H
#define VIERGEWINNT_BOARD_H


#include <vector>
#include <string>

class Board {
    //Numbers are chosen based on Wikipedia article's most common size
    int numberOfColumns{7};
    int numberOfRows{6};

    std::vector<std::vector<char>> board;

    bool checkLeft(int y, int x);

    bool checkUp(int y, int x);

    bool checkLeftUp(int y, int x);

    bool checkRightUp(int y, int x);

public:
    bool checkDiagonal(int i, int j);
    bool checkHorizontalAndVertical(int i, int j);

    Board();

    void drawBoard();

    bool hasSpace();

    void drop(char color, int columnNumber);

    bool isColumnAvailable(int columnNumber);

    [[nodiscard]] int getNumberOfColumns() const;

    [[nodiscard]] int getNumberOfRows() const;

    [[nodiscard]] const std::vector<std::vector<char>> &getBoard() const;
};

#endif //VIERGEWINNT_BOARD_H
