#include <iostream>
using namespace std;

const int GOAL_X = 3;
const int GOAL_Y = 3;


class Ball {
public:
    int x, y;

    Ball() : x(0), y(0) {} 

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    int getX() { return x; }
    int getY() { return y; }

    void getPosition() {
        cout << "Ball Position: (" << x << ", " << y << ")" << endl;
    }
};


class Robot {
public:
    string robot_name;
    int hits;

    Robot() : hits(0) {} 

    void set_robname() {
        cout << "Enter robot name: ";
        cin >> robot_name;
    }

    string get_robname() {
        return robot_name;
    }

    void hitBall(Ball &ball, const string &direction) {
        if (direction == "up") {
            ball.move(0, 1);
        } else if (direction == "down") {
            ball.move(0, -1);
        } else if (direction == "left") {
            ball.move(-1, 0);
        } else if (direction == "right") {
            ball.move(1, 0);
        }
        hits++; 
    }

    int getHits() { return hits; }
};

class Goal {
public:
    bool isGoalReached(int ballX, int ballY) {
        return (ballX == GOAL_X && ballY == GOAL_Y);
    }
};


class Team {
public:
    string teamname;
    Robot *robot;

    Team() { robot = new Robot(); } 

    void set_teamname() {
        cout << "Enter team name: ";
        cin >> teamname;
    }

    string get_teamname() {
        return teamname;
    }
};

// Game Class
class Game {
private:
    Team teamOne;
    Team teamTwo;
    Ball ball;
    Goal goal;

public:
    void startGame() {
        // Team One's Turn
        teamOne.set_teamname();
        teamOne.robot->set_robname();
        play(&teamOne);

        // Reset ball for next team
        ball = Ball(); 

        // Team Two's Turn
        teamTwo.set_teamname();
        teamTwo.robot->set_robname();
        play(&teamTwo);

        // Declare Winner
        declareWinner();
    }

    void play(Team *team) {
        cout << "Team " << team->get_teamname() << "'s turn." << endl;
        
        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            cout << "Ball is at: ";
            ball.getPosition();

            cout << "Enter move direction (up/down/left/right): ";
            string direction;
            cin >> direction;

            team->robot->hitBall(ball, direction);
        }

        cout << "Goal reached in " << team->robot->getHits() << " hits!" << endl;
    }

    void declareWinner() {
        int hitsOne = teamOne.robot->getHits();
        int hitsTwo = teamTwo.robot->getHits();

        cout << "Team " << teamOne.get_teamname() << " hits: " << hitsOne << endl;
        cout << "Team " << teamTwo.get_teamname() << " hits: " << hitsTwo << endl;

        if (hitsOne < hitsTwo) {
            cout << "Team " << teamOne.get_teamname() << " wins!" << endl;
        } else if (hitsOne > hitsTwo) {
            cout << "Team " << teamTwo.get_teamname() << " wins!" << endl;
        } else {
            cout << "It's a tie!" << endl;
        }
    }
};

// Main Function
int main() {
    Game game;
    game.startGame();
    return 0;
}
