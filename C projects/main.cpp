#include <iostream>
#include <list>
#include <memory>
#include <thread>
#include <atomic>
#include <mutex>

//ingles por convencao, manter UTF-8.

namespace squaretype{  
enum{
    EMPTY,   // " "
    HUMAN,   // "X"
    COMPUTER // "O"
};
};

namespace boardstatus{  
enum{
    ONGOING,
    HUMAN_VICTORY,   
    COMPUTER_VICTORY, 
    DRAW,
};
};

struct possibilityNode{
    possibilityNode *parentNode;
    std::list<std::unique_ptr<possibilityNode>> children;
    uint8_t boardData[9];
};

//interface functions:
char getSquareChar(uint8_t _squaretype);
void printTutorial();
void printBoard(const uint8_t _b[]);
int getBoardStatus(const uint8_t _b[]);
void printBoardStatus(int _status);
bool humanPlay(uint8_t _board[]);
bool debug_humanPlayAsComputer(uint8_t _board[]);
void computerPlay(int _squarePos, int _squaretype, uint8_t _board[]);

//algorithm functions:
void threadedIteration(int _index, const uint8_t _b[]);
int getBestPlay(const uint8_t _b[]);
void makeChild(int _index, int primitivePos, possibilityNode* _parent);
void recursiveLoop(int _depth, int primitivePos, possibilityNode* _parent);

int getFirstEmptySquare(const uint8_t _b[]);
int getNumOfEmptySquares(const uint8_t _b[]);
int getPosOfIndexedEmptySquare(int _index, const uint8_t _b[]);
void copyBoard(const uint8_t _board[], uint8_t _newBoard[]);
int getCurrentTurn(const uint8_t _b[]);

//multithread safety data:
std::mutex mut_lock;
std::atomic<int> victoryMatrix[9];
std::atomic<int> drawMatrix[9];
std::atomic<int> defeatMatrix[9];
std::atomic<int> ongoingMatrix[9];

//misc global data:
const int player_one = squaretype::HUMAN; //first turn
const int player_two = squaretype::COMPUTER; //second turn

int main(){

    uint8_t board[9] =
    {
    squaretype::EMPTY, squaretype::EMPTY, squaretype::EMPTY,
    squaretype::EMPTY, squaretype::EMPTY, squaretype::EMPTY,
    squaretype::EMPTY, squaretype::EMPTY, squaretype::EMPTY
    };

    printTutorial();

    printBoard(board);
    
    //game loop until game ends
    while(true){

        while(!humanPlay(board));
        printBoard(board);
        if(getBoardStatus(board) != boardstatus::ONGOING){
            printBoardStatus(getBoardStatus(board));
            break;
        }

        getCurrentTurn(board);
        computerPlay(getBestPlay(board), squaretype::COMPUTER, board);
        printBoard(board);
        if(getBoardStatus(board) != boardstatus::ONGOING){
            printBoardStatus(getBoardStatus(board));
            break;
        }
    }

    return 0;
}

char getSquareChar(uint8_t _squaretype){

    switch (_squaretype){
        
    case squaretype::EMPTY :
    return ' ';

    case squaretype::HUMAN :
    return 'X';

    case squaretype::COMPUTER :
    return 'O';
    
    default:
    std::cerr << "invalid squaretype! \n";
    exit(1);
    break;

    }
}

void printTutorial(){

    std::cout << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << " 0 | 1 | 2 " << std::endl;
    std::cout << " --+---+--   ->  valid positions" << std::endl;
    std::cout << " 3 | 4 | 5 " << std::endl;
    std::cout << " --+---+--     type the number of the position" << std::endl;
    std::cout << " 6 | 7 | 8     of the square you want to play on" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;

    return;
}

void printBoard(const uint8_t _b[]){

    std::cout << " " << getSquareChar(_b[0]) << " | " << getSquareChar(_b[1]) << " | " << getSquareChar(_b[2]) << std::endl;
    std::cout << " --+---+-- " << std::endl;
    std::cout << " " << getSquareChar(_b[3]) << " | " << getSquareChar(_b[4]) << " | " << getSquareChar(_b[5]) << std::endl;
    std::cout << " --+---+-- " << std::endl;
    std::cout << " " << getSquareChar(_b[6]) << " | " << getSquareChar(_b[7]) << " | " << getSquareChar(_b[8]) << std::endl;
    std::cout << std::endl;

    return;
}

int getBoardStatus(const uint8_t _b[]){

    //check horizontal
    for(int i = 0; i < 3; i++){
        if( (_b[i*3 + 0] == _b[i*3 + 1]) && (_b[i*3 + 1] == _b[i*3 + 2]) && (_b[i*3] != squaretype::EMPTY) ){
            return _b[i*3];
        }
    }

    //check vertical
    for(int i = 0; i < 3; i++){
        if( (_b[i + 0*3] == _b[i + 1*3]) && (_b[i + 1*3] == _b[i + 2*3]) && (_b[i] != squaretype::EMPTY) ){
            return _b[i];
        }
    }

    //check diagonal 1
    if( (_b[0] == _b[4]) && (_b[4] == _b[8]) && (_b[0] != squaretype::EMPTY) ){
        return _b[0];
    }

    //check diagonal 2
    if( (_b[2] == _b[4]) && (_b[4] == _b[6]) && (_b[2] != squaretype::EMPTY) ){
        return _b[2];
    }

    //check for draw
    bool draw = true;
    for(int i = 0; i < 9; i++){
        if(_b[i] == squaretype::EMPTY){
            draw = false;
            break;
        }
    }
    if(draw){return boardstatus::DRAW;}

    //if all checks fail the game is still ongoing
    return boardstatus::ONGOING;
}

void printBoardStatus(int _status){

    switch (_status){
        
    case boardstatus::ONGOING :
    std::cout << "game is still ongoing..." << std::endl;
    return;
        
    case boardstatus::HUMAN_VICTORY :
    std::cout << "human (x) won!" << std::endl;
    return;
        
    case boardstatus::COMPUTER_VICTORY :
    std::cout << "computer (o) won!" << std::endl;
    return;
        
    case boardstatus::DRAW :
    std::cout << "game is a draw." << std::endl;
    return;
    
    default:
    std::cerr << "invalid input status! \n";
    exit(1);
    break;

    }
}

bool humanPlay(uint8_t _board[]){

    int squarePos;
    std::cout << "your turn:";
    std::cin >> squarePos;

    if((squarePos >= 0) && (squarePos < 9)){
        if(_board[squarePos] == squaretype::EMPTY){
            _board[squarePos] = squaretype::HUMAN;
            return true;
        }
        else{
            std::cout << "occupied square position, try again!" << std::endl;
            return false;
        }
    }
    else{
        std::cout << "out of bounds square position, try again!" << std::endl;
        return false;
    }
    return false;
}

bool debug_humanPlayAsComputer(uint8_t _board[]){

    int squarePos;
    std::cout << "your turn:";
    std::cin >> squarePos;

    if((squarePos >= 0) && (squarePos < 9)){
        if(_board[squarePos] == squaretype::EMPTY){
            _board[squarePos] = squaretype::COMPUTER;
            return true;
        }
        else{
            std::cout << "occupied square position, try again!" << std::endl;
            return false;
        }
    }
    else{
        std::cout << "out of bounds square position, try again!" << std::endl;
        return false;
    }
    return false;
}

void computerPlay(int _squarePos, int _squaretype, uint8_t _board[]){

    if((_squarePos >= 0) && (_squarePos < 9)){
        if(_board[_squarePos] == squaretype::EMPTY){
            _board[_squarePos] = _squaretype;
            return;
        }
        else{
            std::cerr << "FATAL ERROR! \n";
            std::cerr << "computer attempted to play at an occupied square position: " << _squarePos << "\n";
            exit(EXIT_FAILURE);
        }
    }
    else{
        std::cerr << "FATAL ERROR! \n";
        std::cerr << "computer attempted to play at out of bounds square position: " << _squarePos << "\n";
        exit(EXIT_FAILURE);
    }
    return;
}




void threadedIteration(const int _index, const uint8_t _b[]){

    int primitivePos = getPosOfIndexedEmptySquare(_index, _b);
    if(primitivePos == -1){
        return;
    }

    std::unique_ptr<possibilityNode> root = std::make_unique<possibilityNode>();
    root->parentNode = nullptr;
    copyBoard(_b, root->boardData);
    computerPlay(primitivePos, getCurrentTurn(root->boardData), root->boardData);

    recursiveLoop(9, primitivePos, root.get());

    return;
}

//analyzes the board and returns the position with most possible victories
int getBestPlay(const uint8_t _b[]){

    for(int i = 0; i < 9; i++){
        victoryMatrix[i] = 0;
        drawMatrix[i] = 0;
        defeatMatrix[i] = 0;
        ongoingMatrix[i] = 0;
    }

    unsigned int max_threads = std::thread::hardware_concurrency();

    if(max_threads == 1){
        std::thread t0(threadedIteration,0, _b);
        t0.join();
        std::thread t1(threadedIteration,1, _b);
        t1.join();
        std::thread t2(threadedIteration,2, _b);
        t2.join();
        std::thread t3(threadedIteration,3, _b);
        t3.join();
        std::thread t4(threadedIteration,4, _b);
        t4.join();
        std::thread t5(threadedIteration,5, _b);
        t5.join();
        std::thread t6(threadedIteration,6, _b);
        t6.join();
        std::thread t7(threadedIteration,7, _b);
        t7.join();
        std::thread t8(threadedIteration,8, _b);
        t8.join();
    }
    else if(max_threads == 2){
        std::thread t0(threadedIteration,0, _b);
        std::thread t1(threadedIteration,1, _b);
        t0.join();
        t1.join();
        std::thread t2(threadedIteration,2, _b);
        std::thread t3(threadedIteration,3, _b);
        t2.join();
        t3.join();
        std::thread t4(threadedIteration,4, _b);
        std::thread t5(threadedIteration,5, _b);
        t4.join();
        t5.join();
        std::thread t6(threadedIteration,6, _b);
        std::thread t7(threadedIteration,7, _b);
        t6.join();
        t7.join();
        std::thread t8(threadedIteration,8, _b);
        t8.join();
    }
    else if(max_threads == 4){
        std::thread t0(threadedIteration,0, _b);
        std::thread t1(threadedIteration,1, _b);
        std::thread t2(threadedIteration,2, _b);
        std::thread t3(threadedIteration,3, _b);
        t0.join();
        t1.join();
        t2.join();
        t3.join();
        std::thread t4(threadedIteration,4, _b);
        std::thread t5(threadedIteration,5, _b);
        std::thread t6(threadedIteration,6, _b);
        std::thread t7(threadedIteration,7, _b);
        t4.join();
        t5.join();
        t6.join();
        t7.join();
        std::thread t8(threadedIteration,8, _b);
        t8.join();
    }
    else if(max_threads == 8){
        std::thread t0(threadedIteration,0, _b);
        std::thread t1(threadedIteration,1, _b);
        std::thread t2(threadedIteration,2, _b);
        std::thread t3(threadedIteration,3, _b);
        std::thread t4(threadedIteration,4, _b);
        std::thread t5(threadedIteration,5, _b);
        std::thread t6(threadedIteration,6, _b);
        std::thread t7(threadedIteration,7, _b);
        t0.join();
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();
        t7.join();
        std::thread t8(threadedIteration,8, _b);
        t8.join();
    }
    else{
        threadedIteration(0, _b);
        threadedIteration(1, _b);
        threadedIteration(2, _b);
        threadedIteration(3, _b);
        threadedIteration(4, _b);
        threadedIteration(5, _b);
        threadedIteration(6, _b);
        threadedIteration(7, _b);
        threadedIteration(8, _b);
    }

    int most_victories = -1;
    int most_victories_pos = -1;
    std::cout << std::endl;
    std::cout << "possible victories (for computer):" << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << victoryMatrix[i*3+j] << " ";
            if(victoryMatrix[i*3+j] > most_victories){
                most_victories = victoryMatrix[i*3+j];
                most_victories_pos = i*3+j;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "square position with highest ammount of possible victories: " << most_victories_pos << std::endl;


    int most_draws = -1;
    int most_draws_pos = -1;
    std::cout << std::endl;
    std::cout << "possible draws (for computer):" << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << drawMatrix[i*3+j] << " ";
            if(drawMatrix[i*3+j] > most_draws){
                most_draws = drawMatrix[i*3+j];
                most_draws_pos = i*3+j;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "square position with highest ammount of possible draws: " << most_draws_pos << std::endl;

    int least_defeats = 99999999;
    int least_defeats_pos = -1;
    std::cout << std::endl;
    std::cout << "possible defeats (for computer):" << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << defeatMatrix[i*3+j] << " ";
            if((defeatMatrix[i*3+j] < least_defeats) && (_b[i*3+j] == squaretype::EMPTY)){
                least_defeats = defeatMatrix[i*3+j];
                least_defeats_pos = i*3+j;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "square position with least ammount of possible defeats: " << least_defeats_pos << std::endl;
    
    // magic numbers found during testing
    if(most_victories == 1 || most_victories == 15){
        std::cout << std::endl;
        std::cout << "the computer played: " << most_victories_pos << " because the human made a mistake!" << std::endl;
        std::cout << std::endl;
        return most_victories_pos;
    }
    else{
        std::cout << std::endl;
        std::cout << "the computer played: " << least_defeats_pos << " because it has the least ammount of defeats" << std::endl;
        std::cout << std::endl;
        return least_defeats_pos;
    }
    
}

void makeChild(int _index, int primitivePos, possibilityNode* _parent){

    if(getPosOfIndexedEmptySquare(_index, _parent->boardData) == -1){
        return;
    }

    std::unique_ptr<possibilityNode> child = std::make_unique<possibilityNode>();
    child->parentNode = _parent;
    copyBoard(_parent->boardData, child->boardData);
    computerPlay(getPosOfIndexedEmptySquare(_index, child->boardData), getCurrentTurn(child->boardData), child->boardData);
    _parent->children.push_back(std::move(child));

    int status = getBoardStatus(_parent->children.back()->boardData);
    if(status == boardstatus::COMPUTER_VICTORY){
        victoryMatrix[primitivePos].fetch_add(1, std::memory_order_relaxed);
        return;
    }
    if(status == boardstatus::HUMAN_VICTORY){
        defeatMatrix[primitivePos].fetch_add(1, std::memory_order_relaxed);
        return;
    }
    if(status == boardstatus::DRAW){
        drawMatrix[primitivePos].fetch_add(1, std::memory_order_relaxed);
        return;
    }
    if(status == boardstatus::ONGOING){
        ongoingMatrix[primitivePos].fetch_add(1, std::memory_order_relaxed);
        return;
    }

}

void recursiveLoop(int _depth, int primitivePos, possibilityNode* _parent){

    if(_depth <= 0){
        return;
    }

    makeChild(0, primitivePos, _parent);
    makeChild(1, primitivePos, _parent);
    makeChild(2, primitivePos, _parent);
    makeChild(3, primitivePos, _parent);
    makeChild(4, primitivePos, _parent);
    makeChild(5, primitivePos, _parent);
    makeChild(6, primitivePos, _parent);
    makeChild(7, primitivePos, _parent);
    makeChild(8, primitivePos, _parent);

    for(auto& _child : _parent->children){
        recursiveLoop(_depth-1, primitivePos, _child.get());
    }
    

}

//returns the square position of the first empty square
//returns -1 if there is none
int getFirstEmptySquare(const uint8_t _b[]){

    for(int i = 0; i < 9; i++){
        if(_b[i] == squaretype::EMPTY){
            return i;
        }
    }
    return -1;
}

//returns the number of empty squares in a board
int getNumOfEmptySquares(const uint8_t _b[]){

    int result = 0;
    for(int i = 0; i < 9; i++){
        if(_b[i] == squaretype::EMPTY){
            result++;
        }
    }
    return result;

}

//returns the square position of the indexed empty square of a board
//
// example: index = 1
//
// O |   | X
// --+---+--
//   | O | O
// --+---+--
// X | O | X
//
// returns 3, which is the position of the second empty square (zero based index)
//
// returns -1 if it doesnt find a single empty square
int getPosOfIndexedEmptySquare(int _index, const uint8_t _b[]){

    int result = -1;
    for(int i = 0; i < 9; i++){
        if(_b[i] == squaretype::EMPTY){
            if(_index == 0){
                result = i;
                return result;
            }
            else{
                _index--;
            }
        }
    }
    return result;

}

//copies _board into _newBoard
void copyBoard(const uint8_t _board[], uint8_t _newBoard[]){
    _newBoard[0] = _board[0];
    _newBoard[1] = _board[1];
    _newBoard[2] = _board[2];
    _newBoard[3] = _board[3];
    _newBoard[4] = _board[4];
    _newBoard[5] = _board[5];
    _newBoard[6] = _board[6];
    _newBoard[7] = _board[7];
    _newBoard[8] = _board[8];
    return;
}

int getCurrentTurn(const uint8_t _b[]){
    int hum = 0;
    int com = 0;
    for(int i = 0; i < 9; i++){
        if(_b[i] == squaretype::HUMAN){
            hum++;
        }
        if(_b[i] == squaretype::COMPUTER){
            com++;
        }
    }
    if(hum == com){
        return player_one;
    }
    return player_two;
}
