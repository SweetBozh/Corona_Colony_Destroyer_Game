#ifndef Player_h
#define Player_h

class Player{
  private: 
    string name;
    string job;
    string skill; 
    int ATK;
    int HP;
    int DEF;
    int score; //จำนวน turn
    int HPmax;
  public:
    Player(string,string,string,int,int,int); 
    ~Player();

    int get_HP();

    // สำหรับ healer
    void heal();

    int get_score();
    void set_score(int);
    void show_HP();
    void set_HP(int);

    string get_name();
    string get_job();
    int get_HPmax();

    //Polymorphism //
    int get_ATK();
    void plus_ATK(int);
};

#endif