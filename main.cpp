#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string.h>
#include <exception>
#include <iomanip>
using namespace std;
#include "Player.h"
#include "Virus.h"
#include "BossVirus.h"
#include "VirusLL.h"
#include "myexception.h"
#include "HighScore.h"

// asd

//cin ทุกจุดจะต้องทำ throw, catch สำหรับหัวข้อ exception handling

/* สิ่งที่ต้องทำ
1. ทำการแสดงผลโดยรวมของ main, มี 3 level (จำนวนไวรัส 2 3 4) [CLEAR!]
เมื่อเริ่มเกม เลือกโหมดเสร็จ จะ เติม Virus เข้าใน Linked List ตามระดับความยาก //พอฆ่า 1 ตัวได้ ก็จะลบตัวนั้นออกจาก Linked List โดยใน Destructor จะบอกว่าไวรัสตัวนั้นถูกกำจัด
2. สร้าง class Player(){string name; string job; string skill; int ATK; int HP; int DEF;}; เติมข้อมูล ลงไป ตามที่ผู้เล่นกรอก [CLEAR!]
3. สร้าง class Virus(){string name; int ATK; int HP;} //ATK เพิ่มขึ้นทุกเทิร์น, เติม Virus, ชื่อ คุณสมบัติ, จำนวนตามความยาก ลงใน Linked List, กำหนดคุณสมบัติให้แต่ละตัว ก่อนใส่ใน Linked List [CLEAR!]
4. ทำโปรแกรมสุ่มเลข 1 - 100 [CLEAR!]
5. บันทึกจำนวน Turn เอาไว้เป็นตัวแปร ในการบอกว่า Turn ที่เท่าไหร่  เพื่อเอาไปใช้ บอกสถิติ ใน High Score [CLEAR!]
6. ทำ Sorting ของ High Score แบบ Insertion [CLEAR!] 
7. เพิ่ม exception 

*/
//----------------------------- Function Declaration --------------------------------
void showCredit();
void showCharacter(string,string,int,int,int); 
void checkJobchoice(string,int);
string menuName();
int menuCharater(string);
int inputYN();
int checkYN1(string);
//int checkYN2(string);
//int checkYN3(string);
int inputNum(int);
int checkNumber(int,int);

int specialFight(char[]);

////------------------------------------ Main ----------------------------------------
int main () {
  cout << "Corona Colony Destroy.exe" << endl;

  //------------------ Variable ---------------------

  int menuchoice,choice;
  Player *P1;
  string name, job, skill;
  int jobchoice, levelchoice ,okchoice, okchoice2;
  int countPlay = 0; //ใช้สำหรับแสดง High Score ที่แตกต่างกัน
  int result; //ใช้บอกว่า แพ้ หรือชนะ 
  int playerScore, rank; //ใช้แสดง High Score

  Player *PS; //PlayerSpecial ข้างล่างตรงนี้ ตัวแปรสำหรับ Special ทั้งหมด
  //BossVirus B1;
  BossVirus *B1;
  int specialChoice, specialReadyChoice;
  string nameBoss, skillBoss; 
  int castBarrier;
  int bossHP,psHP;
  int bossATK,psATK;
  int turn=2; //สำหรับรัน จำนวนรอบที่สู้กับ บอส Special Mode
  //try{ //--coming soon(exception)

  char str1[7][60] = {"CALL UP ON THE ANCIENT POWERS",                                          "TO PROTECT US NOW AND IN FUTURE HOURS",                                  "BRING TO ME THE BLESSING OF FERTILITY",                                  "REJUVIURO PESTI CANI",                                                   "LOCOULSO TORMATUS AVIUL",                                                "GO AWAY THE VILLIAN VIRUS!"};


  do{ //while(menuchoice != 4); 
  //Main Menu
  cout << "---------------------------------------------" << endl;
  cout << "                    Menu                     " << endl;
  cout << "             [1]  Start Game                 " << endl;
  cout << "             [2]  High Score                 " << endl;
  cout << "             [3]  Credit                     " << endl;
  cout << "             [4]  Exit                       " << endl << endl;

  cout << "         [5] Play Special Mode   [NEW!]     " << endl;
  cout << "---------------------------------------------" << endl;
  cout << ": ";
  menuchoice = inputNum(5);
    
    //-------------------- Play Special Mode------------------------
  if(menuchoice == 5){
    cout << endl;
    cout << "  Welcome to our limited Special Mode !!  " << endl<<endl;

    cout<< "\t'This event will end in 350 years !" << endl;
    cout<< "\t  Let's play before it's gone !!" <<endl<<endl; 

    cout << "\t\t  Do you want to play ?" << endl;
    cout << "\t\t  Play [1]     Back [2]" << endl << endl;
    cout << "---------------------------------------------" << endl;
    specialChoice = inputNum(2);

    if(specialChoice == 1) //เริ่มเกม โปรแกรมที่ 2 สำหรับ Polymorphism
    {
      
    //1. สร้าง Player
    //2. สร้าง Boss monster
      cout << "              Event Start !!!              "<< endl<<endl;

      cout << " From now on, you will act as 'Naofumi'," <<endl;
      cout << "     as a protector of the world." << endl <<endl; 

      cout << "                Okay [1]                    " << endl;
      cout << "---------------------------------------------" << endl;
      okchoice2 = inputNum(1);

      PS = new Player("Naofumi", "Protector", "Counter Barrier", 80, 300, 30);//สร้างเป็น พ้อยเตอร์ ให้เปลี่ยนแปลง HP ของผู้เล่นได้
      //ใน Special Mode จะไม่มีคุณสมบัติสกิลอะไรเลย อาชีพก็แยกพิเศษ 

      cout << "Continue [1] " << endl;
      okchoice2 = inputNum(1);
      
      B1 = new BossVirus("Disaster Virus", 45, 400, "Pneumonia Spread");
      
      skillBoss = B1 -> get_skill();
      nameBoss = B1 -> get_name();

      //cout << "Name Boss: " << nameBoss <<endl;

      cout << "\t\t\t ----------------" << endl<< endl;

      cout << "\t\t\t !!! Warning !!!" << endl << endl;

      cout << "\t\t\t ----------------" << endl <<endl;
      cout << "\t\t   === BOSS FIGHT  === " << endl <<endl;
     //delete B1;

      cout << "*Note : '" << nameBoss << "' is very savage."<<endl;
      cout << " It can attacks you with extreme damage." << endl << endl;

      cout << " It's also very tough, you 'cannot' attack it" << endl;
      cout << " with normal attack." << endl <<endl;

      cout << " Continue [1] " <<endl;
      cout << "---------------------------------------------" << endl;
			okchoice2 = inputNum(1);

      cout << "Your ultimate skill is unlocked." << endl << endl;

      cout << "You can use 'Counter Barrier' now." << endl << endl;

      cout << "*To cast 'Counter Barrier', type following words"<<endl;
      cout << "accurately, which will appear on the screen soon." << endl<< endl;

      cout << "READY [1]"<<endl;
      cout << "---------------------------------------------" <<endl;
      okchoice2 = inputNum(1);
      
      cout << "       ---- !!! BOSS FIGHT START !!! ----    "<< endl<<endl;

      cout << nameBoss << " : " << endl;
      cout << "\"HOW YOU DARE KILL MY CHILDREN??\"" << endl << endl;

      cout << "Roarrrrrrrr !!!" << endl <<endl;

      do{
        psATK = PS -> get_ATK(); 
        bossATK = B1 -> get_ATK(); //บอสก็ตีแรงขึ้นเหมือนกัน +5 ทุก turn
        //เพิ่มขึ้นทุกเทิร์น ใช้ assign ใน set_HP(psATK) สำหรับ CounterAttack
        //มี 2 ฟังก์ชัน ที่ทำให้ Polymorphism
        //คือ B1 -> set_HP(int); กับ B1 -> Virus::set_HP(int); 
        //     ^ ของลูก Counter Attacked     ^ ของพ่อแม่ Normal Attacked 

        B1 -> castSkill();
        if(turn%7==0)
        {
          cout << "Cast 'Counter Barrier' to defend !" << endl;
          castBarrier = specialFight(str1[5]);
        }

        else if(turn%6==0){
          cout <<"You should hurry and recast the barrier !" << endl;
          castBarrier = specialFight(str1[4]);
        }

        else if(turn%5==0){
         cout << "Recast the barrier again !" <<endl;
         castBarrier = specialFight(str1[3]);
        }

        else if(turn%4==0){
          cout << "Recast the barrier again !" <<endl;
          castBarrier = specialFight(str1[2]);
        }

        else if(turn%3==0){
          cout <<"You should hurry and recast the barrier !" << endl;
          castBarrier = specialFight(str1[1]);
        }
 
        else if(turn%2==0) {
          cout << "Cast 'Counter Barrier' to defend !" << endl;
          castBarrier = specialFight(str1[0]);  
        }
      
        else {
          cout << "Cast 'Counter Barrier' to defend !" << endl;
          castBarrier = specialFight(str1[5]);
        }
      
        

        if(castBarrier == 1){         
           cout << "---------------------------------------------" << endl <<endl;

          cout << "            Barrier cast successful !" <<endl << endl;

          cout << "---------------------------------------------" << endl;
			    cout << "Continue [1] ";
			    okchoice2 = inputNum(1);

          cout << endl << "BOSS ATTACK !!" << endl;
          cout <<"- 0" << endl << endl;
          PS -> show_HP();
          cout << endl;
          B1 -> set_HP(psATK); // Counter Attack, Override Parent Func
          cout << endl;
          B1 -> show_HP();
          cout << "---------------------------------------------" << endl <<endl;

          cout <<"              The barrier is broken." <<endl <<endl;

          cout << "---------------------------------------------" << endl;
        } 
        else if(castBarrier == 0){
          cout << endl;
          cout << "---------------------------------------------" << endl <<endl;

          cout <<"            Casting Barrier Failed !!! " << endl << endl;

          cout << "---------------------------------------------" << endl <<endl;

          cout <<"BOSS ATTACK !!" << endl;
          cout <<"- " << bossATK << endl;
          PS -> set_HP(bossATK); //เลือดลด
          cout << endl;
          PS -> show_HP();
          cout << "---------------------------------------------" << endl;
        } 

				  cout << "Continue [1] ";
				  okchoice2 = inputNum(1);

          bossHP = B1 -> get_HP(); //ถ้าเลือดเป็น 0 จะลบบอสทิ้ง + ไม่ให้ตีต่อ
          psHP = PS -> get_HP(); //ใช้เช็คว่าเป็น 0เปล่า ถ้าเป็น 0จะออกลูป
          
          if(psHP!=0&&bossHP!=0){
          cout << "---------------------------------------------" << endl <<endl;
          cout << "         It's your turn to attack !!" << endl << endl;

          cout << "                 Attack!! [1] " <<endl<<endl;
          cout << "---------------------------------------------" << endl;
				  okchoice2 = inputNum(1); 
          cout <<endl;
          cout << ">> *You attack '1' damage to the boss" << endl << endl;
          B1 -> Virus::set_HP(1); //Polymorphism Override แบบเรียกพ่อแม่
          B1 -> show_HP();  
          cout << "---------------------------------------------" << endl;
			    cout << "Continue [1] ";
          okchoice2 = inputNum(1);
          cout << endl;
          }//end if psHP!=0


          B1 -> set_ATK(5); //บอสจะตีแรงขึ้นทีละ 5
          if(castBarrier == 1)PS -> plus_ATK(12); //Player Counter ได้จะแรงขึ้นทีละ 12


          if(bossHP == 0) delete B1; //ลบพ้อยเตอร์ที่ชี้บอสน่ะเอง
          turn++; //

      }while(psHP!=0 && bossHP!=0); //วนถ้าบอสยังไม่ตาย หรือ เพลเยอร์ยังไม่ตาย
      //ถ้าคนใดคนนึงตาย ให้ออกจากลูป --> แปลว่า ถ้าทั้งคู่ยังไม่ตาย จะวน !!?

      if(bossHP==0 && psHP>0){
        cout << "---------------------------------------------" << endl<<endl;

        cout << "           =**= Congratulation =**=         " <<endl<<endl;

        cout << "You have saved the world from the Virus !!" << endl << endl;

        cout << "     Hope you enjoy our 'Special Mode' !" << endl << endl <<endl;
      }

      else if(psHP ==0){
        cout << endl<<"            _- Sorry, You Lose :( -_         " <<endl <<endl;

        cout << "              Try again next time.           " << endl << endl;
      }
      	cout << "Back to Menu [1] " <<endl;
        cout << "---------------------------------------------" << endl;
			 okchoice2 = inputNum(1);

       turn = 2;
    }//end special choice == play 
    //(Go back to menu)
  }//end menuchoice == 5
  if(menuchoice == 4) return 0;
  if(menuchoice == 3) showCredit(); 
  if(menuchoice == 2) {
     if(countPlay==0) {
       printHighScore(0,0,name,playerScore); //Default
       cout<<": ";
       choice = inputNum(1);
     }
     else {
       printHighScore(rank,levelchoice,name,playerScore);
       cout<<": ";
       choice = inputNum(1);
     }
  }
  if(menuchoice == 1)
  {
    {//วงเล็บเปล่าสำหรับให้ destruct ก่อนทำขั้นตอนถัดไป

   //jobchoice 1 คือ samurai, 2 คือ mage, 3 คือ healer
    int HP, DEF, ATK;

    VirusLL LL1;
    Virus *t; //ชี้ new V1(name,atk,hp) สร้างไวรัสตัวใหม่, แล้วว add_node(t) เข้าใน VirusLL


    //------------------------- Import Monster ------------------------

    cout << endl << "Choose Game Level" << endl;
    cout << "\t1.) Easy" << endl; 
    cout << "\t2.) Normal" << endl;
    cout << "\t3.) Hard" << endl;
    cout<<": ";
    levelchoice = inputNum(3);
  

    //หลังจากเลือก level, ทำการ Import Virus เข้าไปใน Linked List ดังนี้

    //สิ่งที่ต้องการ : เอา Virus ที่อยู่หัวขบวน (head) มาปู้ยี่ปู้ยำ แล้ว delete ออกจากขบวน, จัดขบวนใหม่, เอา Virus ที่หัวขบวนตัวต่อมา มาปู้ยี่ปู้ยำต่อ แล้ว delete, โปรแกรมทำงาน จนกว่า ใน Linked List Virus จะไม่มี Virus เหลืออยู่ "หรือ" HP ผู้เล่นเป็น 0 ซะก่อน

    // เวลา Add มันจะ Add จากหัว แปลว่า ตัวสุดท้ายที่เข้ามาจะอยู่ที่หัวขบวน
    // เวลา ลบ มันจะ ลบ จากหัวขบวน :. จะต้องเอา Virus ที่อยากลบก่อน เติมใน LL เป็นตัวสุดท้าย
    //Add V1 V2 ไว้นอกเงื่อนไข, ถ้า levelchoice == 2 || 3 ค่อยเพิ่ม V3, V4
  
    switch(levelchoice){
      case 1: //Easy
        t = new Virus("Alpha Coronavirus", 11, 200); LL1.add_node(t);
        t = new Virus("Rookie Coronavirus", 10, 150); LL1.add_node(t);
        break;
      case 2: //Normal
        t = new Virus("Beta Coronavirus", 12, 250); LL1.add_node(t);
        t = new Virus("Alpha Coronavirus", 11, 200); LL1.add_node(t);
        t = new Virus("Rookie Coronavirus", 10, 150); LL1.add_node(t);
        break;
      case 3: //Hard
        t = new Virus("Brutal Coronavirus", 15, 400); LL1.add_node(t);
        t = new Virus("Beta Coronavirus", 12, 250); LL1.add_node(t);
        t = new Virus("Alpha Coronavirus", 11, 200); LL1.add_node(t);
        t = new Virus("Rookie Coronavirus", 10, 150); LL1.add_node(t);
        break;
    }



    //--------------------------- เกริ่นนำ -------------------------  
    cout << "---------------------------------------------" << endl;
    cout << endl << " GAME START !!!" << endl << endl;
    cout << "---------------------------------------------" << endl; 
  

    cout << endl << "   - Welcome to Corona Colony Destroy ! ! -" << endl;
    cout << endl << "I'm so glad you are here to help us destroy the" <<  endl; cout << "frightening villian name 'Corona Virus'" << endl << endl;

    cout << "[Enter to continue]" << endl;
 
    cin.ignore();
    cin.get();

    cout << "---------------------------------------------" << endl; 

    cout << "Let me describe a bit," << endl << endl;
    cout << "\tHere is a small world where Corona Virus live, " << endl; 
    cout << "having party, eating yummy pizza and the most" << endl;
    cout << "important thing is..." << endl << endl;
   
    cout << "'Preparing the ARMY to attack the human world'" << endl << endl;

    //------------------------- สร้างตัวละคร -----------------------
    while(okchoice==0){                         //-->ทดลองwhile
      cout << "and" << endl << endl;
      cout << "\"You are here to destroy Corona World\"" << endl;
      cout << "    Your name: ";
      cin >> name;
      //พอได้ข้อมูลครบ จะเอา name ไปสร้าง Object Player
      cout << endl;
    
      cout << "---------------------------------------------" << endl; 
      cout << "Choose your Hero Class" << endl;
      cout << "\t1.) Samurai Warrior  (Use Physical Attack)"<< endl;
      cout << "\t2.) Purify Mage      (Use Magical Attack)" << endl;
      cout << "\t3.) Furious Healer   (Use Furious Attack)" << endl;
      cout << ": " ;
      jobchoice = inputNum(3);
        //แสดงรายละเอียดตัวละคร ให้ผู้เล่นเช็คตัวละครที่เลือกอีกครั้ง
      checkJobchoice(name,jobchoice);
    //cout << "---------------------------------------------" << endl;
      string choiceYN; 
      cout << "OK [yes/no])?" << endl << ": ";
      okchoice = inputYN();
      }//end-while

    //ได้ name, job ครบแล้ว, ใส่ name , job และ กำหนด  ATK, HP, DEF ตามของแต่ละอาชีพ สร้างเป็น object Player ของผู้เล่น

    /*กำหนดคร่าวๆ Samurai HP : 220  (ATK //ค่าสมมติ ไม่มีผลต่อเกม :70) DEF: 20
    Mage HP: 200 ATK : 80 DEF: 16
    Healer HP: 210 ATK: 60 DEF: 18*/

    switch(jobchoice){
      case 1:
        job = "Samurai Warrior";
        HP = 220;
        ATK = 70;
        DEF = 20;
        skill = "Brave Samurai";
        break;
      //ค่าพวกนี้ ใช้แค่แสดง status ข้อมูลเท่ๆ, มีแค่ HP ที่เอาไปใช้จริง
      case 2:
        job = "Purify Mage";
        HP = 180;
        ATK = 80;
        DEF = 16;
        skill = "Purify Magic";
        break;
     case 3:
        job = "Furious Healer";
        HP = 205;
        ATK = 60;
        DEF = 18;
        skill = "Furious Healing";
       break;
     default:
      cout << "Error: Switch Case: 'jobchoice'";
      break;

    }

    P1 = new Player(name, job, skill, ATK, HP, DEF); //player constructor
    
    /* ย้ายไปอยู่บรรทัดที่ 159 นะ
    //cout << "---------------------------------------------" << endl; 
    cout << "OK [yes/no])?" << endl << ": ";
    */

    //ถ้าไม่ใช้ yes no y n จะถามจนกว่าจะใช่
    //ถ้าเป็น Yes หรือ y, Ok k, จะไปต่อ 
   //if(okchoice == ("No") || okchoice =="N") //ถามยืนยันอีกที ว่า   จะสร้างตัวละครใหม่มั้ย ถ้าสร้าง ก็วน ถ้าไม่เอาแล้ว ก็ไปต่อโลด 

    //-------------------------- เริ่มเกม --------------------------
    //cout << "---------------------------------------------" << endl <<endl;

    cout << endl;
    cout << "Now that you are ready for the destroy role." << endl;
    cout << "It's time to eliminate all of the villian virus !" << endl << endl;

    cout << "---------------------------------------------" << endl; 
    cout << "Let me tell some rule that" <<endl;
    cout << " \"YOU HAVE TO REMEMBER\"." << endl << endl;

    cout << "1. Corona Virus will attack more and more severe" <<endl;
    cout << "   as long as you don't get rid of them," << endl;
    cout << "   so try to kill them as fast as you can." <<endl << endl;
    
    cout << "2. Corona Virus will choose a number from 1-100," <<endl;
    cout << "   Your task is to guess what they choose." << endl << endl;
    cout << " \t\"THE CLOSER YOUR GUESS TO THE VIRUS," << endl;
    cout << " THE MORE DAMAGE YOU DO TO THEM.\"" << endl << endl; 
    
    cout << "---------------------------------------------" << endl; 
    
    int readyChoice=0;
    while(readyChoice==0){
      cout << "Ready ? [yes/no]" << endl;
      readyChoice = inputYN();
    }
      cout<<endl;
      cout << "...Well, I know you, our brave hero, are" << endl;
      cout << "        always ready! Let's go :)       " << endl;
    /* ->เราเปลี่ยนตัวแปร readyChoice จากString เป็น int 
        แล้วก็ใช้ inputYN แทนนะ
    cin >> readyChoice;
    if(!(readyChoice == "yes" || readyChoice == "Y" ||readyChoice =="y"||readyChoice=="Yes"||readyChoice=="yEs"||readyChoice=="yeS"))
    */
    

    cout << "---------------------------------------------" << endl; 
    cout << "!!! Fight Start !!!" << endl;

    result = LL1.Fight(P1,levelchoice);
   //อยากเอาข้อมูลของ Player P1 ไปใช้ใน LL.Fight(), **มีการ  เปลี่ยนแปลงค่าด้วย **ควรเป็นพ้อยท์เตอร์??
    if(result == 0){
      cout << endl << "Our 'System Hero' will soon help you "<< endl; 
      cout << "destroy the remaining Virus" << endl<<endl;

      cout << "[Enter to continue]" << endl;

      cin.ignore();
      cin.get();
    }//end if

  }//วงเล็บเปล่าสำหรับให้ destruct enemy ก่อนเข้า showCredit

    if(result ==1){
      playerScore = P1 -> get_score();
      rank = sortHighScore(playerScore,levelchoice);
      printHighScore(rank,levelchoice,name,playerScore);
      choice = inputNum(1);
      
    }
    countPlay=1;  
    cout << "---------------------------------------------" << endl<<endl;
  
    cout << "              =**= Credit =**=               " << endl <<endl;

    cout << "                - Developer -               " << endl<<endl;

    cout << "     Warunyupa   Lerdsaeng         6313180  " << endl;
    cout << "     Nalin       Suesangiamsakul   6313216  " << endl;
    cout << "     Sorawit     Kuhakasemsin      6313219  " << endl<<endl;

  cout << "---------------------------------------------" << endl;
  cout << " Back to Menu [1]" << endl;
  choice = inputNum(1);

  okchoice=0; //เพื่อให้วนกลับไปแล้ว กลับเข้าลูป while ถามชื่อได้
  }//end menuchoice == 1
  }while(menuchoice!=4); 
}//end main




void showCredit(){
  int choice;
  cout << "---------------------------------------------" << endl<<endl;
  
  cout << "              =**= Credit =**=               " << endl <<endl;

  cout << "                - Developer -               " << endl<<endl;

  cout << "     Warunyupa   Lerdsaeng         6313180  " << endl;
  cout << "     Nalin       Suesangiamsakul   6313216  " << endl;
  cout << "     Sorawit     Kuhakasemsin      6313219  " << endl<<endl;

  cout << "---------------------------------------------" << endl;
  cout << " Back [1]" << endl;
  choice = inputNum(1);
}

void showCharacter(string name,string job, string skill, int ATK,int HP,int DEF){
  cout << "---------------------------------------------" << endl; 
  cout<< "\"" << name << "\"" << " Are you sure? " << "'" << job << "'" << " ?" << endl<<endl;
  cout<<"\t\t\t  -- Status -- " << endl;
  cout<<"\t\tATK: "<< ATK << endl;
  cout<<"\t\tHP : "<< HP << endl;
  cout<<"\t\tDEF: "<< DEF << endl;
  cout<<"\t\tSkill: "<< skill <<endl<<endl;
  cout << "---------------------------------------------" << endl; 
}


string menuName(){
  char name[70];

  cout << "\"You are here to destroy Corona World\"" << endl;
  cout << "    Your name: ";
  cin >> name; 
  while(strlen(name)==0){
    try{
      cin >> name;
    if(cin.fail())
      throw "Not text"; 
    }
    //กรณีชื่อซ้ำล่ะ ต้องรอlinkedlist hightscore ไหมหนอ
   catch (const char *error) {
				cerr << error;
				cout << endl;
				cin.clear();
				cin.ignore(50, '\n');
    }
  }
  cout << endl;
  return name;
  //พอได้ข้อมูลครบ จะเอา name ไปสร้าง Object Player
}



int menuCharater(string name){
  int jobchoice;
  cout << "---------------------------------------------" << endl;
  cout << "Choose your Hero Class" << endl;
  cout << "\t1.) Samurai Warrior  (Use Physical Attack)"<< endl;
  cout << "\t2.) Purify Mage      (Use Magical Attack)" << endl;
  cout << "\t3.) Furious Healer   (Use Furious Attack)" << endl;
  cout << ": " ;
  jobchoice = inputNum(3);
  //แสดงรายละเอียดตัวละคร ให้ผู้เล่นเช็คตัวละครที่เลือกอีกครั้ง
  checkJobchoice(name,jobchoice);
  return jobchoice;
}



int inputNum(int choice){
  int temp,target=0;
  while(target==0){
    try{
      cin>>temp;

      if(cin.fail())
        throw myex2;

      target = checkNumber(temp,choice); 
    }
    catch(exception &e){
      cout<<e.what()<<endl;
      cin.clear();
      cin.ignore(100,'\n');
    }
  }
  return target; //รับคำตอบใส่ใน Temp ถ้าถูก target ยังเป็น 0 แต่คืนค่าเป็น Target ? 

  //สิ่งที่ควรเป็น -> รับคำตอบใส่ใน temp --> เอา temp ไปเช็ค แล้วเปลี่ยนค่า temp !?
  //แล้วลูปรับ target == 0 ? จะวนลูปถ้ายังตอบผิด

  //เปรม: คำตอบที่เราให้ผู้เล่นเลือกมี 1-xx เราเลยเซตให้ตอนแรก target เป็น 0 
  //เปรม: หลังจากเรียกใช้คำสั่ง checkNumber จะส่งค่าtargetมาให้ ซึ่งจะไม่ใช่เลข 0 แล้ว
}

int  checkNumber(int a,int choice) {
  if(a>choice|| a<=0) 
      throw myex2;
  return a; 
}

void checkJobchoice(string n,int j){
   if( j == 1 )
      showCharacter(n,"Samurai Warrior","Brave Samurai",70,220,20);
    else if( j == 2 )
      showCharacter(n,"Purify Mage","Purify Magic",80,200,16);
    else 
      showCharacter(n,"Furious Healer","Furious Healing",60,210,18);
    
}

int inputYN(){

  int okchoice = 2;
  string temp;

  while(okchoice==2){
    try{
      cin>>temp;
      if(cin.fail())
        throw myex1;
      okchoice = checkYN1(temp);
    }
    catch(exception &e){
      cout<<e.what()<<endl;
      cin.clear();
      cin.ignore(100,'\n');
    }
  }
  return okchoice;
}

int checkYN1(string choice){
  int okchoice = 0;
  if( choice!="yes" && choice!="YES" && choice!="Yes" &&                        choice!="y"   && choice!="Y"   && choice!="OK"  &&                        choice!="ok"  && choice!="Ok"  && choice!="K"   &&                        choice!="k"   && choice!="no"  && choice!="NO"  &&                        choice!="No"  && choice!="n"   && choice!="N")
  {
      throw myex3;
  }
  //okchoice = checkYN2(choice);

  if( choice=="yes" || choice=="YES" || choice=="Yes" ||                        choice=="y"   || choice=="Y"   || choice=="OK"  ||                        choice=="ok"  || choice=="Ok"  || choice=="K"   || choice=="k")
  //end-condition
      okchoice = 1;
  else
      okchoice = 0;

  return okchoice;
}
    
int  specialFight(char text[]){
  char s[100];
  int score=0;
  cout << endl;
  cout << "\tCopy : "<<text<<endl;
  cout << "\t     : ";
  cin.clear();
  cin.ignore();
  cin.getline(s,100);
  cout << endl;
  if(strcmp(s,text)!=0){
     cout << "Wrong!! Try again next Round ^-^"<<endl;
     cout <<" [ "<<text<<" ]"<<" isn't  "<< endl << " [ "<<s<<" ]"<<endl;
     score = 0;
  }
  else{
     cout << "Gorgeous!!"/*<<name*/<<endl;
     //cout <<" [ "<<text<<" ]"<<" is  "<< endl << " [ "<<s<<" ]"<<endl;
     score = 1;
  }
  return score;
}

//ต้องมีฟังก์ชัน check cin วนถามซ้ำว่าเข้ามา ถูก type หรือไม่
//ต้องมีฟังก์ชันสำหรับคำนวณ และ return ดาเมจ

/*เราจะต้องสุ่มไปเลขนึง เช่น 59 CLEAR
แต่ว่า เลขที่โปรแกรมให้มาคือ 99 ดังนั้น จะเอาไปคำนวณ
99-59 = 40 
99-99 = 0
เอาผลที่ได้ไปคูณ -1 
แล้วบวก 100,

ถ้าเลือกคลาส ซามูไร จะตีแรงขึ้นเพิ่ม +5 ทุกเทิร์น
ถ้าเลือกคลาส เมจ     จะร่ายสกิล Purify Magic !! ทุกๆ 3 เทิร์น ทำดาเมจ +30 
ถ้าเลือกคลาส ฮีลเลอร์ จะร่ายสกิล Furious Healing !! ทุกๆ 3 เทิร์น เติม HP +30 

ถ้าทายเลขถูกเป๊ะ จะโจมตีติดคริติคอล ทำดาเมจ 200 !! (//ตอนนี้เลือดมอนเป็น 100 แต่สามารถเพิ่มให้มากกว่านั้นได้ (แต่ไม่น้อยกว่า)) 

พลังโจมตีของ Corona Virus จะเพิ่มขึ้นทุกเทิร์น 
โดยเริ่มจาก 10 กลายเป็น 20 --> 30 พอตาย ตัวต่อไปก็ตี 10 ใหม่
โดยจะมีจำนวน Virus import เข้ามา ตามระดับความยากของเกม 
Easy -> 2 ตัว Normal -> 3 ตัว Hard -> 4 ตัว*/
//เรียง
//