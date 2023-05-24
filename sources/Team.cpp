//
// Created by oz on 07/04/23.
//
#include "Team.hpp"
#include "Team2.hpp"
#include <climits>

Team::~Team() {
    for (int i = 0; i < this->get_size(); i++) {
        delete this->get_character(i);
    }
}

Team2::Team2(Character *leader_) : Team(leader_) {}

//Team2::~Team2(){
//    for (int i = 0; i < this->get_size(); i++) {
//        delete this->get_character(i);
//    }
//}



void Team::attack(Team *enemy) {
    if (enemy == nullptr) { throw invalid_argument("11111111111111111111"); }
    if (0 == enemy->stillAlive()) { throw runtime_error("22222222222222222222222"); }
    if (!this->leader_alive()) {
        this->set_leader();
    }
    Character *enemy_Close = enemy->get_close_player(this->get_leader());//wat if null
    for (int i = 0; i < this->get_size(); ++i) {
        if (this->get_character(i)->isAlive()) {
            if (!enemy_Close->isAlive()) {
                enemy_Close = enemy->get_close_player(this->get_leader());
                if (enemy_Close == nullptr) {
                    return;

                }
            }
            if (this->get_character(i)->getkind() == COWBOY_) {

                Cowboy *temp = dynamic_cast<Cowboy *>(this->get_character(i));
                if (temp != nullptr) {
                    if (temp->hasboolets())
                        temp->shoot(enemy_Close);
                    else
                        temp->reload();

                }
            }
        }
    }
    for (int i = 0; i < this->get_size(); ++i) {
        if (this->get_character(i)->isAlive()) {
            if (!enemy_Close->isAlive()) {
                enemy_Close = enemy->get_close_player(this->get_leader());
                if (enemy_Close == nullptr) {

                    break;
                }
            }
            if (this->get_character(i)->getkind() == ONINJA_) {

                OldNinja *temp = dynamic_cast<OldNinja *>(this->get_character(i));
                if (temp != nullptr) {
                    if (temp->distance(enemy_Close) <= 1)
                        temp->slash(enemy_Close);
                    else
                        temp->move(enemy_Close);
                }
            }

            if (this->get_character(i)->getkind() == YNINJA_) {

                YoungNinja *temp = dynamic_cast<YoungNinja *>(this->get_character(i));
                if (temp != nullptr) {
                    if (temp->distance(enemy_Close) <= 1)
                        temp->slash(enemy_Close);
                    else
                        temp->move(enemy_Close);
                }
            }

            if (this->get_character(i)->getkind() == TNINJA_) {

                TrainedNinja *temp = dynamic_cast<TrainedNinja *>(this->get_character(i));
                if (temp != nullptr) {
                    if (temp->distance(enemy_Close) <= 1)
                        temp->slash(enemy_Close);
                    else
                        temp->move(enemy_Close);
                }
            }
        }
    }

}


void Team2::attack(Team *enemy) {
    if (enemy == nullptr) { throw invalid_argument("11111111111111111111"); }
    if (0 == enemy->stillAlive()) { throw runtime_error("22222222222222222222222"); }
    if (!this->leader_alive()) {
        this->set_leader();
    }
    Character *enemy_Close = enemy->get_close_player(this->get_leader());//wat if null
    for (int i = 0; i < this->get_size(); ++i) {
        if (this->get_character(i)->isAlive()) {
            if (!enemy_Close->isAlive()) {
                enemy_Close = enemy->get_close_player(this->get_leader());
                if (enemy_Close == nullptr) {
                    return;
                }
            }
            if (this->get_character(i)->getkind() == COWBOY_) {

                Cowboy *temp = dynamic_cast<Cowboy *>(this->get_character(i));
                if (temp != nullptr) {
                    if (temp->hasboolets())
                        temp->shoot(enemy_Close);
                    else
                        temp->reload();


                }
            }
            if (this->get_character(i)->getkind() == ONINJA_) {

                OldNinja *temp = dynamic_cast<OldNinja *>(this->get_character(i));
                if (temp != nullptr) {
                    if (temp->distance(enemy_Close) <= 1)
                        temp->slash(enemy_Close);
                    else
                        temp->move(enemy_Close);
                }
            }

            if (this->get_character(i)->getkind() == YNINJA_) {

                YoungNinja *temp = dynamic_cast<YoungNinja *>(this->get_character(i));
                if (temp != nullptr) {
                    if (temp->distance(enemy_Close) <= 1)
                        temp->slash(enemy_Close);
                    else
                        temp->move(enemy_Close);
                }
            }

            if (this->get_character(i)->getkind() == TNINJA_) {

                TrainedNinja *temp = dynamic_cast<TrainedNinja *>(this->get_character(i));
                if (temp != nullptr) {
                    if (temp->distance(enemy_Close) <= 1)
                        temp->slash(enemy_Close);
                    else
                        temp->move(enemy_Close);
                }
            }
        }
    }

}


Character *get_close_player_nin(Character *ninja, Team *enemy, int speed) {
    Character *team_Close = nullptr;
    double turns = INT_MAX;

    for (int k = 0; k < enemy->get_size(); ++k) {

        if (enemy->get_character(k)->isAlive()) {

            int distance = ninja->distance(enemy->get_character(k));
            if (distance > 1) {
                int hp = enemy->get_character(k)->get_HP();
                int turn = distance / speed + hp / 40;
                if ((distance % speed) > 0)
                    turns++;
                if (hp % 40 > 0)
                    turns++;

                if (turn < turns) {
                    turns = turn;
                    team_Close = enemy->get_character(k);
                }
            } else {
                int hp = enemy->get_character(k)->get_HP();
                int turn = hp / 40;
                if (hp % 40 > 0)
                    turns++;
                if (turn < turns) {
                    turns = turn;
                    team_Close = enemy->get_character(k);
                }
            }
        }
    }
    return team_Close;
}

Character *get_close_player_cow(Character *ninja, Team *enemy) {
    Character *team_Close = nullptr;
    double hp = INT_MAX;

    for (int k = 0; k < enemy->get_size(); ++k) {

        if (enemy->get_character(k)->isAlive() && enemy->get_character(k)->get_HP() < hp) {
            hp = enemy->get_character(k)->get_HP();
            team_Close = enemy->get_character(k);
        }
    }

    return team_Close;
}

void SmartTeam::attack(Team *enemy) {
    if (enemy == nullptr) { throw invalid_argument("11111111111111111111"); }
    if (0 == enemy->stillAlive()) { throw runtime_error("22222222222222222222222"); }
    if (!this->leader_alive()) {
        this->set_leader();
    }

    for (int i = 0; i < this->get_size(); ++i) {

        if (this->get_character(i)->getkind() != COWBOY_) {
            Ninja *temp = nullptr;

            if (this->get_character(i)->getkind() == YNINJA_) {
                temp = dynamic_cast<YoungNinja *>(this->get_character(i));
            }
            if (this->get_character(i)->getkind() == ONINJA_) {
                temp = dynamic_cast<OldNinja *>(this->get_character(i));
            }
            if (this->get_character(i)->getkind() == TNINJA_) {
                temp = dynamic_cast<TrainedNinja *>(this->get_character(i));
            }

            Character *enemy_Close = get_close_player_nin(this->get_character(i), enemy, temp->get_speed());
            if (enemy_Close == nullptr) {
                break;
            }
            if (temp != nullptr) {
                if (temp->distance(enemy_Close) <= 1)
                    temp->slash(enemy_Close);
                else
                    temp->move(enemy_Close);
            }
        }
    }
    for (int i = 0; i < this->get_size(); ++i) {
        if (this->get_character(i)->getkind() == COWBOY_) {
            Cowboy *temp1 = dynamic_cast<Cowboy *>(this->get_character(i));
            Character *enemy_Close = get_close_player_cow(this->get_character(i), enemy);
            if (enemy_Close == nullptr) {
                break;
            }
            if (temp1 != nullptr) {
                if (temp1->hasboolets())
                    temp1->shoot(enemy_Close);
                else
                    temp1->reload();

            }
        }


    }
}


Character *Team::get_leader() { return this->leader; }

Character *Team::get_character(int i) { return this->character[i]; }

int Team::get_size() const { return size; }


///todo  to fiks
void Team::print() {
    cout << "Team" << endl;
    for (int i = 0; i < this->get_size(); ++i) {
        cout << this->get_character(i)->getName() << "  is alive-" << this->get_character(i)->isAlive() << " h_p"
             << this->get_character(i)->get_HP() << endl;
    }
}

void SmartTeam::print() {
    cout << "SmartTeam" << endl;
    for (int i = 0; i < this->get_size(); ++i) {
        cout << this->get_character(i)->getName() << "  is alive-" << this->get_character(i)->isAlive() << " h_p"
             << this->get_character(i)->get_HP() << endl;
    }
}

void Team2::print() {
    cout << "Team2" << endl;
    for (int i = 0; i < this->get_size(); ++i) {
        cout << this->get_character(i)->getName() << "  is alive-" << this->get_character(i)->isAlive() << " h_p"
             << this->get_character(i)->get_HP() << endl;
    }
}


void Team::set_leader() {
    double min_distance = INT_MAX;
    int index = -1;
    for (int i = 0; i < this->get_size(); ++i) {
        if (this->get_character(i)->isAlive() && this->get_leader()->distance(this->get_character(i)) < min_distance) {
            index = i;
            min_distance = this->get_leader()->distance(this->get_character(i));
        }
    }
    this->leader = this->get_character(index);
}


Team::Team(Character *leader_) {
    if (leader_->get_inteam()) { throw runtime_error(""); }
    this->character[0] = leader_;
    this->leader = leader_;
    leader_->set_inteam();
    this->size = 1;
}

void Team::add(Character *player) {
    if (size == 10) { throw runtime_error(""); }
    if (player->get_inteam()) { throw runtime_error(""); }
    character[size] = player;
    size++;
    player->set_inteam();
}

Character *Team::get_close_player(Character *character) {
    Character *team_Close = nullptr;
    double min_distance_team = INT_MAX;
    for (int k = 0; k < this->get_size(); ++k) {

        if (this->get_character(k)->isAlive() && character->distance(this->get_character(k)) < min_distance_team) {
            min_distance_team = character->distance(this->get_character(k));
            team_Close = this->get_character(k);
        }
    }
    return team_Close;
}

Character *Team2::get_close_player(Character *character) {
    Character *team_Close = nullptr;
    double min_distance_team = INT_MAX;
    for (int k = 0; k < this->get_size(); ++k) {

        if (this->get_character(k)->getkind() == COWBOY_) {
            if (this->get_character(k)->isAlive() && character->distance(this->get_character(k)) < min_distance_team) {
                min_distance_team = character->distance(this->get_character(k));
                team_Close = this->get_character(k);
            }
        }
    }
    for (int k = 0; k < this->get_size(); ++k) {
        if (this->get_character(k)->getkind() != COWBOY_) {
            if (this->get_character(k)->isAlive() && character->distance(this->get_character(k)) < min_distance_team) {
                min_distance_team = character->distance(this->get_character(k));
                team_Close = this->get_character(k);
            }
        }
    }
    return team_Close;
}


bool Team::leader_alive() { return this->get_leader()->isAlive(); }

int Team::stillAlive() {
    int num = 0;
    for (int k = 0; k < this->get_size(); ++k) {
        if (this->get_character(k)->isAlive())
            num++;
    }
    return num;
}
