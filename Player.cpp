#include <iostream>
using namespace std;
#include "Player.h"
Player::Player(string n,string j,string s,int a,int h,int d)
{
  name = n;
  job = j;
  skill = s;
  ATK = a;
  HP = h;
  DEF = d;
  HPmax = h;

  //set turn = 1 เมื่อสร้างตัวละคร
  score = 1;

  cout<< "---------------------------------------------" << endl; 
  cout<< "\"" << name << "\"" << " is now " << "'" << job << "'" << "." << endl<<endl;
 
  cout<< "\t\t\t  -- Status -- " << endl;
  cout<< "\t\tATK: "<< ATK << endl;
  cout<< "\t\tHP : "<< HP << endl;
  cout<< "\t\tDEF: "<< DEF << endl;
  cout<< "\t\tSkill: "<< skill << endl <<endl;
  cout << "---------------------------------------------" << endl; 
}

Player::~Player(){
  cout << "Player Destructor" << endl;
}

void Player::heal(){
  HP+=30;
}

int Player::get_HP(){
  return HP;
}

int Player::get_score(){
  return score;
}

void Player::set_score(int s){
  score = s;
}

void Player::show_HP(){
  cout << name << " HP: " << HP << "/" << HPmax << endl;
}//เราจะโชว์ HP 40 / 200 ...ดูเหมือนว่าจะต้องมีตัวแปร HP ไว้เก็บ HP Max ด้วย แล้วก็ HP เฉยๆ ที่เก็บ HP ที่เปลี่ยนค่าบ่อยๆ

void Player::set_HP(int damage){
  HP -= damage;
  if(HP < 0) HP = 0;
}

string Player::get_name(){
  return name;
}

string Player::get_job(){
  return job;
}

int Player::get_HPmax(){
  return HPmax;
}
//Polymorphism
int Player::get_ATK()
{
  return ATK;
}

void Player::plus_ATK(int a){
  ATK += a;
}