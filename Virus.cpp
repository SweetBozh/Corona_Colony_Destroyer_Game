#include <iostream>
using namespace std;
#include "Virus.h" //Node

Virus::Virus(string n,int a,int h){
  name = n;
  ATK = a;
  HP = h;
  HPmax = h;
}

Virus::~Virus(){
  cout << name << " is defeated" << endl;
}

void Virus::operator-=(int a){
  HP-=a;
}

void Virus::show_HP(){
  cout << name << " HP: " << HP << "/" << HPmax << endl;
}

void Virus::set_HP(int damage){
  HP -= damage;
  if(HP < 0) HP = 0;
}

void Virus::set_ATK(int a){
  //cout << "ATK = "<< ATK << endl; *สำหรับ Test
  ATK += a;
  //cout << "After ATK = " << ATK << endl;
}//ถ้าตายก็ไม่ต้องเปลี่ยนไร เพราะมันจะออกจากโลกไปเลย.. (ลบจาก LL)

void Virus::virusAttack(){
  cout << ">> *" << name << " attack you " << ATK << " damage.*" << endl << endl;
}


//------------------------------------------------------------
//สำหรับ LinkedList
Virus* Virus::move_next(){
  return next;
}

void Virus::insert(Virus *&x){
  x -> next = this; // t->next = head; เติมที่หัว โดยให้หัว ปจบ.ชี้มาที่ตัวใหม่
}

void Virus::show_node(){
  cout << "Node : " <<  name << endl;
}

string Virus::get_name(){
  return name;
}

int Virus::get_HP(){
  return HP;
}

int Virus::get_ATK(){
  return ATK;
}