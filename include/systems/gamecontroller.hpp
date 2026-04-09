#pragma once

class GameController {
public:
    GameController& instance() {
        static GameController gc {};
        return gc;
    }
private:
    GameController();
    ~GameController();
    GameController(const GameController& other);
    GameController& operator=(const GameController& other);

private:
    // game world
    // combat system
    // game ui controller
};
