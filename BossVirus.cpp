#include <iostream>
using namespace std;
#include "Virus.h"
#include "BossVirus.h"

BossVirus::BossVirus(string n, int a , int hp , string s):Virus(n,a,hp){
  //cout << n << " is created."<< endl;
  skill = s;
}


BossVirus::~BossVirus(){
  //cout << name << " is defeated (Child)" << endl;
}

void BossVirus::set_HP(int playerATK){

    HP -= playerATK;
    cout << "*You counter attack " << playerATK <<" damage to the boss !!*" <<endl;
    if(HP<0) HP =0;
    //else (ตอนแรกเรารับ Cast Barrier มา ตอนนี้เปลี่ยนแล้ว)
    //cout << "Cast Barrier is != 1, did you mean 'Virus::set_HP()'?" <<endl;
}

 
string BossVirus::get_skill(){
  return skill;
}

void BossVirus::castSkill(){
   cout << ">> "<< name << " has used skill '" << skill <<"'"<<endl << endl;
}