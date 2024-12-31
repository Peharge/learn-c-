#include <SDL2/SDL.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 800;
const int BLOCK_SIZE = 40;
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

class Tetris {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<std::vector<int>> board;
    std::vector<std::vector<int>> currentPiece;
    int currentX, currentY;
    bool running;

    const std::vector<std::vector<std::vector<int>>> pieces = {
        {{1, 1, 1, 1}},                // I piece
        {{1, 1}, {1, 1}},              // O piece
        {{0, 1, 0}, {1, 1, 1}},        // T piece
        {{1, 1, 0}, {0, 1, 1}},        // S piece
        {{0, 1, 1}, {1, 1, 0}},        // Z piece
        {{1, 0, 0}, {1, 1, 1}},        // L piece
        {{0, 0, 1}, {1, 1, 1}}         // J piece
    };

    bool isValidMove(int newX, int newY, const std::vector<std::vector<int>>& piece) {
        for (int i = 0; i < piece.size(); ++i) {
            for (int j = 0; j < piece[i].size(); ++j) {
                if (piece[i][j]) {
                    int boardX = newX + j;
                    int boardY = newY + i;
                    if (boardX < 0 || boardX >= BOARD_WIDTH || boardY >= BOARD_HEIGHT || (boardY >= 0 && board[boardY][boardX])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void placePiece() {
        for (int i = 0; i < currentPiece.size(); ++i) {
            for (int j = 0; j < currentPiece[i].size(); ++j) {
                if (currentPiece[i][j] && currentY + i >= 0) {
                    board[currentY + i][currentX + j] = currentPiece[i][j];
                }
            }
        }
        clearLines();
        spawnPiece();
    }

    void clearLines() {
        for (int i = 0; i < BOARD_HEIGHT; ++i) {
            bool fullLine = true;
            for (int j = 0; j < BOARD_WIDTH; ++j) {
                if (!board[i][j]) {
                    fullLine = false;
                    break;
                }
            }
            if (fullLine) {
                board.erase(board.begin() + i);
                board.insert(board.begin(), std::vector<int>(BOARD_WIDTH, 0));
            }
        }
    }

    void rotatePiece() {
        std::vector<std::vector<int>> rotated(currentPiece[0].size(), std::vector<int>(currentPiece.size()));
        for (int i = 0; i < currentPiece.size(); ++i) {
            for (int j = 0; j < currentPiece[i].size(); ++j) {
                rotated[j][currentPiece.size() - 1 - i] = currentPiece[i][j];
            }
        }
        if (isValidMove(currentX, currentY, rotated)) {
            currentPiece = rotated;
        }
    }

    void spawnPiece() {
        currentPiece = pieces[std::rand() % pieces.size()];
        currentX = BOARD_WIDTH / 2 - currentPiece[0].size() / 2;
        currentY = -currentPiece.size();
        if (!isValidMove(currentX, currentY, currentPiece)) {
            running = false;
        }
    }

    void renderBlock(int x, int y, SDL_Color color) {
        SDL_Rect rect = {x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE};
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
        SDL_RenderFillRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect);
    }

    void draw() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (int i = 0; i < BOARD_HEIGHT; ++i) {
            for (int j = 0; j < BOARD_WIDTH; ++j) {
                if (board[i][j]) {
                    renderBlock(j, i, {255, 255, 255});
                }
            }
        }

        for (int i = 0; i < currentPiece.size(); ++i) {
            for (int j = 0; j < currentPiece[i].size(); ++j) {
                if (currentPiece[i][j]) {
                    renderBlock(currentX + j, currentY + i, {255, 0, 0});
                }
            }
        }

        SDL_RenderPresent(renderer);
    }

public:
    Tetris() : board(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0)), running(true) {
        std::srand(static_cast<unsigned>(std::time(0)));
        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        spawnPiece();
    }

    ~Tetris() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void play() {
        while (running) {
            SDL_Event e;
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    running = false;
                } else if (e.type == SDL_KEYDOWN) {
                    switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        if (isValidMove(currentX - 1, currentY, currentPiece)) {
                            currentX--;
                        }
                        break;
                    case SDLK_RIGHT:
                        if (isValidMove(currentX + 1, currentY, currentPiece)) {
                            currentX++;
                        }
                        break;
                    case SDLK_DOWN:
                        if (isValidMove(currentX, currentY + 1, currentPiece)) {
                            currentY++;
                        } else {
                            placePiece();
                        }
                        break;
                    case SDLK_UP:
                        rotatePiece();
                        break;
                    }
                }
            }

            if (!isValidMove(currentX, currentY + 1, currentPiece)) {
                placePiece();
            } else {
                currentY++;
            }

            draw();
            SDL_Delay(500);
        }
    }
};

int main() {
    Tetris game;
    game.play();
    return 0;
}
