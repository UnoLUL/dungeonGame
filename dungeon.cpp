#include <cstdlib>
#include <iostream>
// Dungeon game, created in C++ by Charlie Davey, 2025.

void exitQuery(int score, bool& alive) {
  std::cout << "You left the dungeon and your score was: " << score << '\n';
  std::cout << "Goodbye!" << '\n';
  alive = false;
}

void Combat(int& hp, int& attackPower, int& gold, bool& alive, int& score, float diff) {

  std::cout << "You enter combat!" << '\n';

  // generate monster with randomised health between 1-15
  int monsterHP = (rand() % 15 + 1) * diff;
  bool monsterAlive = true;
  int monsterAttack = 5 * diff; // base attack of 5 * game diff
  int holder; // temp holder

  while (monsterAlive == true && alive == true) {
    std::cout << "Press 1 to attack" << '\n';
    std::cin >> holder;
    if (holder == 1) {
      std::cout << "You come face to face with the monster and dicern some of its characteristics." << '\n';
      std::cout << "Monsters health is : " << monsterHP << '\n';
      std::cout << "Monsters attack modifier is : " << monsterAttack << '\n';

      std::cout << "You attack the monster!" << '\n';
      int damage = (rand() % attackPower + 1); // based on attack power you do different damage;
      std::cout << "You did: " << damage << " damage to the monster" << '\n';
      monsterHP = monsterHP - damage;

      if (monsterHP <= 0) {
        std::cout << "Congrats, you killed the monster!" << '\n';
        monsterAlive = false;
        int goldReward = (rand() % 20 + 10) * diff;
        gold = gold + goldReward;
        score = score + 10 * diff;
        std::cout << "You gained " << goldReward << " gold!" << '\n';

      } else {
        //monsters turn
        std::cout << "The monster strikes at you!" << '\n';
        int damage = (rand() % monsterAttack + 1);
        std::cout << "He did : " << damage << " damage" << '\n';
        hp = hp - damage;
        std::cout << "Your health is now: " << hp << '\n';


      }

    }




    //exit if dead
    if (hp <= 0) {
      std::cout << "You have died!" << '\n';
      exitQuery(score, alive);
    }
    if (monsterAlive == false) {
      break;

    }
  }
}

void Treasure(int& gold, int& score, float diff) {
  std::cout << "You found a treasure chest!" << '\n';
  int goldFound = (rand() % 30 + 20) * diff;
  gold = gold + goldFound;
  score = score + goldFound;
  std::cout << "You gained " << goldFound << " gold!" << '\n';
}

void Shop(int& hp, int& attackPower, int& gold, int& score) {
  std::cout << "You encounter a mysterious shopkeeper..." << '\n';
  std::cout << "He offers you items for sale:" << '\n';
  std::cout << "1. Health Potion - Restore 30 HP (Cost: 25 gold)" << '\n';
  std::cout << "2. Attack Upgrade - +5 attack power (Cost: 40 gold)" << '\n';
  std::cout << "3. Max Health Boost - +20 max HP (Cost: 35 gold)" << '\n';
  std::cout << "4. Leave shop" << '\n';
  std::cout << "Your gold: " << gold << '\n';

  int choice;
  std::cout << "What would you like to buy? ";
  std::cin >> choice;

  if (choice == 1) {
    if (gold >= 25) {
      gold = gold - 25;
      hp = hp + 30;
      std::cout << "You bought a health potion! HP restored by 30." << '\n';
      std::cout << "Your health is now: " << hp << '\n';
    } else {
      std::cout << "Not enough gold!" << '\n';
    }
  } else if (choice == 2) {
    if (gold >= 40) {
      gold = gold - 40;
      attackPower = attackPower + 5;
      std::cout << "You bought an attack upgrade! Attack power increased by 5." << '\n';
      std::cout << "Your attack power is now: " << attackPower << '\n';
      score = score + 20;
    } else {
      std::cout << "Not enough gold!" << '\n';
    }
  } else if (choice == 3) {
    if (gold >= 35) {
      gold = gold - 35;
      hp = hp + 20;
      std::cout << "You bought a max health boost! Health increased by 20." << '\n';
      std::cout << "Your health is now: " << hp << '\n';
    } else {
      std::cout << "Not enough gold!" << '\n';
    }
  } else {
    std::cout << "You leave the shop." << '\n';
  }

  std::cout << "Remember: shops are rare! Next one might be 5-7 rooms away..." << '\n';
}

void Rest(int& hp, int& score) {
  std::cout << "You find a peaceful room with a campfire." << '\n';
  int hpRestore = rand() % 15 + 10;
  hp = hp + hpRestore;
  score = score + 5;
  std::cout << "You rest and recover " << hpRestore << " HP." << '\n';
  std::cout << "Your health is now: " << hp << '\n';
}

void Boss(int& hp, int& attackPower, int& gold, bool& alive, int& score, float diff) {
  std::cout << "=== BOSS ROOM ===" << '\n';
  std::cout << "A massive creature blocks your path!" << '\n';

  // generate boss with tougher stats
  int bossHP = (rand() % 30 + 20) * diff * 2;
  bool bossAlive = true;
  int bossAttack = 8 * diff; // stronger than normal monsters
  int holder; // temp holder

  while (bossAlive == true && alive == true) {
    std::cout << "Press 1 to attack the boss" << '\n';
    std::cin >> holder;
    if (holder == 1) {
      std::cout << "You face the terrifying boss!" << '\n';
      std::cout << "Boss health is : " << bossHP << '\n';
      std::cout << "Boss attack modifier is : " << bossAttack << '\n';

      std::cout << "You attack the boss!" << '\n';
      int damage = (rand() % attackPower + 1); // based on attack power you do different damage;
      std::cout << "You did: " << damage << " damage to the boss" << '\n';
      bossHP = bossHP - damage;

      if (bossHP <= 0) {
        std::cout << "INCREDIBLE! You defeated the boss!" << '\n';
        bossAlive = false;
        int goldReward = (rand() % 50 + 50) * diff;
        gold = gold + goldReward;
        score = score + 50 * diff;
        std::cout << "You gained " << goldReward << " gold and massive score!" << '\n';

      } else {
        //boss turn
        std::cout << "The boss unleashes a devastating attack!" << '\n';
        int damage = (rand() % bossAttack + 1);
        std::cout << "The boss did : " << damage << " damage" << '\n';
        hp = hp - damage;
        std::cout << "Your health is now: " << hp << '\n';
      }
    }

    //exit if dead
    if (hp <= 0) {
      std::cout << "You have been slain by the boss!" << '\n';
      exitQuery(score, alive);
    }
    if (bossAlive == false) {
      break;
    }
  }
}

int main() {
  // player setup
  int hp = 30;
  int attackPower = 10;
  int score = 0;
  int gold = 0;
  bool alive = true;

  bool firstTime = true;
  int holder; // holds user input

  // random num
  srand(time(NULL));

  int compNum = (rand() % + 1);


  // rooms  settings
  int roomNum = 0;
  float diff = 1.00; // difficulty multipler

  // rooms
  std::string roomType[] = {"Combat", "Treasure", "Shop", "Rest", "Boss"};

  while (alive == true) {
    roomNum++;
    if (roomNum == 5 || roomNum == 10 || roomNum == 15 ||
      roomNum == 20 || roomNum == 25) {
      diff = diff * 1.5;
    std::cout << "The dungeon grows more dangerous... Difficulty increased!" << '\n';
      } // difficulty scaling

      // Displaying user stats.
      if (firstTime == true) {
        std::cout << "You awake inside an old dungeon, unable to remember how you got yourself in this situation." << '\n';
        std::cout << "Your only option now is to move foward." << '\n';
        std::cout << "Health: " << hp << '\n';
        std::cout << "Attack Strength: " << attackPower << '\n';
        std::cout << "Gold: " << gold << '\n';

        std::cout << "type 1 to enter the next room, 0 to exit the program" << '\n';
        std::cin >> holder;

        if (holder == 0) {
          exitQuery(score, alive);
        } else {
          std::cout << "Into the dungeon..." << '\n';
          firstTime = false;

        }

      } else { // if not first time
        std::cout << "\n=== Room " << roomNum << " ===" << '\n';
        std::cout << "Health: " << hp << '\n';
        std::cout << "Attack Strength: " << attackPower << '\n';
        std::cout << "Gold: " << gold << '\n';
        std::cout << "Score: " << score << '\n';
        std::cout << "You enter the next room and find..." << '\n';

        int nextRoom;

        // boss rooms appear every 10 rooms
        if (roomNum % 10 == 0) {
          nextRoom = 5; // boss room
        } else {
          nextRoom = (rand() % 4 + 1);
        }

        switch (nextRoom) {
          case 1: // combat
            std::cout << "you are in a combat room." << '\n';
            Combat(hp, attackPower, gold, alive, score, diff);
            break;
          case 2: // treasure
            std::cout << "You are in a treasure room." << '\n';
            Treasure(gold, score, diff);
            break;
          case 3: // shop
            std::cout << "You are in a shop room. " << '\n';
            Shop(hp, attackPower, gold, score);
            break;
          case 4: // rest
            std::cout << "You are in a rest room. " << '\n';
            Rest(hp, score);
            break;
          case 5: // boss
            Boss(hp, attackPower, gold, alive, score, diff);
            break;
        }

        // after each room, ask if player wants to continue
        if (alive == true) {
          std::cout << "\nContinue deeper into the dungeon? (1 = yes, 0 = escape with your score): ";
          std::cin >> holder;
          if (holder == 0) {
            std::cout << "You escape the dungeon safely!" << '\n';
            exitQuery(score, alive);
          }
        }
      }

  }

  std::cout << "\n=== GAME OVER ===" << '\n';
  std::cout << "Final Stats:" << '\n';
  std::cout << "Rooms cleared: " << roomNum << '\n';
  std::cout << "Gold collected: " << gold << '\n';
  std::cout << "Final score: " << score << '\n';

  return 0;
} // main function end DO NOT DELETE
