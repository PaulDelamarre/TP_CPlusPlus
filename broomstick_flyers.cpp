/**
 * CNAM :: STI112 :: Algorithmique/C++
 * David SALLE (10/01/2022)
 *
 * DESCRIPTION
 * Code de départ du challenge "Broomstick Flyers" (anciennement Fantastic bits)
 * sur la plateforme codingame :
 * https://www.codingame.com/ide/puzzle/fantastic-bits
 */

// Includes de base dans codingame
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Espace de nom utilisé
using namespace std;


//============================================================================
// Entity class
//============================================================================

/**
 * A moving entity in the game (wizards, snaffles, bludgers)
 */
class Entity
{
private:
    /**
     * Entity identifier (0 <= _id <= 12)
     */
    int _id;

    /**
     * Entity type : "WIZARD", "OPPONENT_WIZARD" or "SNAFFLE" (or "BLUDGER" after first league)
     */
    string _type;

    /**
     * Entity position on X axis (0 < x < 16000)
     */
    int _x;

    /**
     * Entity position on Y axis (0 < y < 7500)
     */
    int _y;

    /**
     * Entity velocity on X axis (-1000000 < vx < 1000000)
     */
    int _vx;

    /**
     * Entity velocity on Y axis (-1000000 < vx < 1000000)
     */
    int _vy;

    /**
     * Entity state : true if the wizard is holding a Snaffle, false otherwise
     */
    bool _state;

public:
    /**
     * Initialize an entity with parameters
     * @param id
     * @param type
     * @param x
     * @param y
     * @param vx
     * @param vy
     * @param state
     */
    Entity(int id, string &type, int x, int y, int vx, int vy, int state) {
        _id = id;
        _type = type;
        _x = x;
        _y = y;
        _vx = vx;
        _vy = vy;
        if (state == 1) {
            _state = true;
        } else {
            _state = false;
        }
    }

    /**
     * Return entity id
     * @return
     */
    int get_id() {
        return _id;
    }

    /**
     * Return entity type
     * @return
     */
    string get_type() {
        return _type;
    }

    /**
     * Return entity x position
     * @return
     */
    int get_x() {
        return _x;
    }

    /**
     * Return entity y position
     * @return
     */
    int get_y() {
        return _y;
    }

    /**
     * Return entity vx velocity
     * @return
     */
    int get_vx() {
        return _vx;
    }

    /**
     * Return entity vy velocity
     * @return
     */
    int get_vy() {
        return _vy;
    }

    /**
     * Return entity state
     * @return
     */
    bool get_state() {
        return _state;
    }

    /**
     * Print an entity to the debug screen
     */
    void print() {
        cerr << "  id=" << _id;
        cerr << ", type=" << _type;
        cerr << ", x=" << _x;
        cerr << ", y=" << _y;
        cerr << ", vx=" << _vx;
        cerr << ", vy=" << _vy;
        cerr << ", s=" << _state << endl;
    }

};


//============================================================================
// Bot class
//============================================================================

/**
 * Your AI bot
 */
class Bot {
private:
    /**
     * Entities arrays
     */
    // TODO #1 : create a dynamic array to store all entities
    vector<Entity> _entities;

    /**
     * My team id : if 0 you need to score on the right of the map, if 1 you need to score on the left
     */
    int _my_team_id;

    /**
     * My score
     */
    int _my_score;

    /**
     * My magic
     */
    int _my_magic;

    /**
     * Opponent score
     */
    int _opponent_score;

    /**
     * Opponent magic
     */
    int _opponent_magic;

public:
    /**
     * Initialize the bot with parameters
     */
    Bot(int my_team_id, int my_score, int my_magic, int opponent_score, int opponent_magic) {
        _my_team_id = my_team_id;
        _my_score = my_score;
        _my_magic = my_magic;
        _opponent_score = opponent_score;
        _opponent_magic = opponent_magic;
    }

    /**
     * Add a new entity to the bot
     */
    void add(Entity &an_entity) {        
        // TODO #2 : add entity to the dynamic array of entities
        _entities.push_back(an_entity);
        // TODO #3 : sort entities using id as key  
           
    }

    /**
     * Print bot informations to the debug screen
     */
    void print() {
        cerr << "=== scores and magics ===" << endl;
        cerr << "  my_team_id=" << _my_team_id << endl;
        cerr << "  my_score=" << _my_score << ", my_magic=" << _my_score<< endl;
        cerr << "  op_score=" << _opponent_score << ", op_magic=" << _opponent_score<< endl;
        
        cerr << "=== entities ===" << endl;
        // TODO #4 : print all entities from the dynamic array   
        for(Entity item : _entities) {
            item.print();
        }   
    }

    /**
     * Play a moving action for a wizard in the game
     * @param verb should be MOVE or THROW
     * @param x with 0 < x < 16000
     * @param y with 0 < y < 7500
     * @param parameter with 0 <= thrust (MOVE) <= 150 and 0 <= power (THROW) <= 500
     */
    void play_action(string verb, int x, int y, int parameter) {
        cout << verb << " " << x << " " << y << " " << parameter << endl;
    }

    /**
     * Play an magic for a wizard in the game
     * @param spell should be OBLIVIATE, PETRIFICUS, ACCIO or FLIPENDO
     * @param id of the entity for the spell
     */
    void play_action(string spell, int id) {
        cout << spell << " " << id << endl;
    }

    /**
     * Choose best action for each of my 2 wizards
     */
    void choose_best_actions_for_wizards() {
        // Play action for my first wizard
        if (_entities[0].get_state()==true)
        {
            play_action("THROWS", 16000, 3700, 500);
        }else{
            play_action("MOVE", _entities[5].get_x(),_entities[5].get_y(),150);
        }
        // Play action for my second wizard   
        if (_entities[1].get_state()==true)
        {
            play_action("THROWS", 16000, 3700, 500);
        }else{
            play_action("MOVE", _entities[5].get_x(),_entities[5].get_y(),150);
        } 
    }
};


//============================================================================
// main function
//============================================================================

/**
 * Entry point of the program
 * @return 0 for a normal exit, another value otherwise
 */
int main()
{
    // Read my team id to know where I should score
    int my_team_id;
    cin >> my_team_id; cin.ignore();

    // Game loop
    while (1) {
        // Reading scores and magics for both players
        int my_score;
        int my_magic;
        cin >> my_score >> my_magic; cin.ignore();
        int opponent_score;
        int opponent_magic;
        cin >> opponent_score >> opponent_magic; cin.ignore();

        // Reading entities number
        int entities;
        cin >> entities; cin.ignore();

        // Create the AI bot
        Bot my_bot(my_team_id, my_score, my_magic, opponent_score, opponent_magic);

        // Reading entities details
        for (int i = 0; i < entities; i++) {
            int entity_id;
            string entity_type;
            int x;
            int y;
            int vx;
            int vy;
            int state;
            cin >> entity_id >> entity_type >> x >> y >> vx >> vy >> state; cin.ignore();

            // Create a new entity and add it to the bot
            Entity an_entity(entity_id, entity_type, x, y, vx, vy, state);
            my_bot.add(an_entity);
        }

        // Print bot informations
        my_bot.print();

        // Choose best actions for my wizards
        my_bot.choose_best_actions_for_wizards();
    }
}