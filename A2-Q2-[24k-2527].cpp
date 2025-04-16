#include <iostream>
#include <string>
using namespace std;

class Ghost {
protected:
    string workerName;
    int scareLevel;

public:
    Ghost(string name, int level) : workerName(name), scareLevel(level) {}
    virtual ~Ghost() {}
    virtual void haunt() const = 0;
    int getScareLevel() const { return scareLevel; }

    friend ostream& operator<<(ostream& os, const Ghost& g) {
        os << g.workerName << " (Scare Level: " << g.scareLevel << ")";
        return os;
    }
};

class Poltergeist : public Ghost {
public:
    Poltergeist(string name, int level) : Ghost(name, level) {}
    void haunt() const override { cout << workerName << " moves objects violently!" << endl; }
};

class Banshee : public Ghost {
public:
    Banshee(string name, int level) : Ghost(name, level) {}
    void haunt() const override { cout << workerName << " screams eerily!" << endl; }
};

class ShadowGhost : public Ghost {
public:
    ShadowGhost(string name, int level) : Ghost(name, level) {}
    void haunt() const override { cout << workerName << " whispers creepily from the shadows..." << endl; }
};

class ShadowPoltergeist : public Ghost {
public:
    ShadowPoltergeist(string name, int level) : Ghost(name, level) {}
    void haunt() const override {
        cout << workerName << " causes eerie disturbances and whispers ominously..." << endl;
    }
};

class Visitor {
private:
    string name;
    int bravery;

public:
    Visitor(string name, int braveryLevel) : name(name), bravery(braveryLevel) {}
    void reactToHaunting(int scareLevel) const {
        if (scareLevel < bravery - 3)
            cout << name << " laughs and taunts the ghost!" << endl;
        else if (scareLevel > bravery + 3)
            cout << name << " screams and runs away!" << endl;
        else
            cout << name << " is visibly shaken with a shaky voice." << endl;
    }
    int getBravery() const { return bravery; }
};

class HauntedHouse {
private:
    string houseName;
    Ghost* ghosts[10];
    int ghostCount;

public:
    HauntedHouse(string name) : houseName(name), ghostCount(0) {}
    ~HauntedHouse() {
        for (int i = 0; i < ghostCount; i++) {
            delete ghosts[i];
        }
    }

    void addGhost(Ghost* ghost) {
        if (ghostCount < 10) {
            ghosts[ghostCount++] = ghost;
        }
    }

    void displayHauntings() const {
        cout << "\nHaunted House: " << houseName << endl;
        for (int i = 0; i < ghostCount; i++) {
            cout << " - ";
            ghosts[i]->haunt();
        }
    }

    friend void visit(Visitor visitors[], int visitorCount, const HauntedHouse& house);
};

void visit(Visitor visitors[], int visitorCount, const HauntedHouse& house) {
    cout << "\nVisitors entering " << house.houseName << "...\n";
    for (int i = 0; i < visitorCount; i++) {
        for (int j = 0; j < house.ghostCount; j++) {
            visitors[i].reactToHaunting(house.ghosts[j]->getScareLevel());
        }
    }
}

int main() {
    HauntedHouse house1("Demon's Villa");
    house1.addGhost(new Poltergeist("Abdullah", 8));
    house1.addGhost(new Banshee("Ali", 6));
    house1.addGhost(new ShadowGhost("Mysterious Figure", 5));

    HauntedHouse house2("Whispering Hollow");
    house2.addGhost(new ShadowPoltergeist("Evil Twin", 9));

    Visitor visitors[] = {
        Visitor("Umais", 2), Visitor("Xyz", 6), Visitor("Mike Tyson", 9)};
    int visitorCount = 3;

    house1.displayHauntings();
    visit(visitors, visitorCount, house1);

    house2.displayHauntings();
    visit(visitors, visitorCount, house2);

    return 0;
}