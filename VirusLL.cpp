#include <iostream>
using namespace std;
#include "Player.h"
#include "Virus.h"   //Node
#include "VirusLL.h" //Class Template
int damage(int, int, int);

int checkNum2(int choice) {
	int a;
	cin >> a;
	while (a > choice || a <= 0) {
		if (a > choice || a <= 0) {
			// throw myex1;
			cin >> a;
		}
	}
	return a;
}

VirusLL::VirusLL() { // Constructor
	head = NULL;
	size = 0; //มีกี่ตัว
}

//จะลบหมดทีเดียวก็ต่อเมื่อ 'แพ้' ก่อนฆ่าหมด นอกนั้นจะลบตัวหัวอย่างเดียว
VirusLL::~VirusLL() { // Destructor
	// clear all nodes
	int i;
	Virus *temp; // Pointer ชี้หัวขบวนไว้
	for (i = 0; i < size; i++) {
		temp = head;
		head = head->move_next(); //ขยับหัวขบวนให้ร่นเข้าไป (ได้หัวขบวนใหม่)
		delete temp; //ลบหัวขบวนอันเก่า ที่ Pointer ชี้อยู่
	} //ลบทำจนกว่าจะเท่าขนาดของ size LL
	size = 0;
}

void VirusLL::delete_head() { //ใช้เมื่อ ฆ่ามอนสเตอร์ตาย จะลบ หัวของ VirusLL ออก
	int i;
	Virus *temp = head;
	if (temp != NULL) {
		head = head->move_next();
		delete temp;
		size -= 1;
	} else
		cout << "Error" << endl; //ตรงนี้ใช้ throw catch ได้
}

void VirusLL::show_all() { //สำหรับทดสอบว่า LinkedList สร้างถูกมั้ย
	Virus *temp = head;
	int i;
	for (i = 0; i < size; i++) {
		temp->show_node();
		temp = temp->move_next();
	}
}

// node ใหม่เข้ามา
void VirusLL::add_node(Virus *&A) {
	head->insert(A); // new_node -> next = head;
	head = A;
	// cout << A -> get_name() << " is added to VirusLL"<<endl; //Test

	size++;
}

string VirusLL::get_virusName() {
	Virus *t = head;
	string virusName = t->get_name();
	return virusName;
}

int VirusLL::random() {
	// random 1-100
	int ran;
	while (ran <= 0 || ran > 101) {
		srand(time(NULL));
		ran = rand() % 101;
	}
	return ran;
}

//--------------------------------------------------
//เพื่อให้ง่ายต่อการเรียกใช้ค่าต่างๆ การต่อสู้จะไว้ใน LL.cpp แทน
//(ถ้าเอาไปใส่ใน main จะต้อง get_name จาก Node แล้วยังต้องเรียกใช้ get_name จาก LL อีก?
//ถ้าอยู่ในนี้....... สร้าง Virus *t = head; แล้วชี้ไป get_name
//จะทำให้ไม่ต้องสร้างฟังก์ชันซ้ำซ้อนเยอะแยะ 2 ที่)

int VirusLL::Fight(Player *&P, int mode) {
	Virus *t = head;
	int turn = P->get_score(); // turn แรก = 1
	int virusGuess = 0, playerGuess;
	int playerHP = P->get_HP();

	int atkDamage;
	int countDefeat = 0;

  //อาชีพ
  int countSamurai=0; //ถ้ายังไม่เปิดใช้ passive เป็น 0

	string playerName = P->get_name();
	string playerJob = P->get_job();
	int playerHPmax = P->get_HPmax();

  //------
	string modeStr;
	switch (mode) {
	case 1:
		modeStr = "Easy";
		break;
	case 2:
		modeStr = "Normal";
		break;
	case 3:
		modeStr = "Hard";
		break;
	default:
		modeStr = "Unknown";
	}

	// cout << "Player HP = " << playerHP << endl; <--- Test ว่าเรียกมาได้มั้ย

	while (t != NULL && playerHP > 0) {
		int virusATK = t->get_ATK(); //เพิ่มขึ้น 10 ทุกจบเทิร์น //ไวรัสตัวใหม่ ค่า virusATK
									 //เป็นค่าใหม่ :.ต้องกำหนดค่าใหม่ทุกลูป
		int a;
		string virusName = t->get_name(); //ไวรัสตัวใหม่ ชื่อใหม่
		cout << "---------------------------------------------" << endl;
		cout << "              === Turn " << turn << " ===" << endl;

		// string playerName = P -> get_name();
		t->show_HP();
		P->show_HP();

    if(playerJob == "Samurai Warrior" && playerHP < 180 && countSamurai==0){
      //ใช้เมื่อเริ่ม Turn 
        cout <<endl<< " You use your passive skill 'Samurai Brave' " <<endl<<endl;

        cout << "             - Samurai Brave -  " <<endl;
        cout << "       passive: When HP less than 180," <<endl;
        cout << "             ATK +10 every turns         "<<endl<<endl;

        cout << "Continue [1] " <<endl;
        cout << "---------------------------------------------" << endl;
				checkNum2(1);
        countSamurai = 1;
      //ไม่ต้องเช็คใน Warrior เพราะเราจะแสดงผล Damage เพียวๆ แล้วพิมพ์ (+5)ต่อ เอาค่ามาบวกทีหลัง
      }

      //ใช้เมื่อเริ่ม Turn
    if(playerJob == "Purify Mage"&& turn%3==0){
      cout << endl << "    - You use skill 'Purify Magic' !! -   " << endl << endl;
      cout << "        '" << virusName << "' HP -50" << endl<<endl;

      t -> set_HP(50);

      cout << "Continue [1] "; 
        //cout << "---------------------------------------------" << endl;
				checkNum2(1);
    }
        
    if(playerJob == "Furious Healer" && turn%3==0){
        cout << endl;
        cout << "    - You use skill 'Furious Healing' !! -   " << endl;
        cout << "                 HP + 30                   " << endl<<endl;
        P -> heal();
        playerHP = P -> get_HP(); //Update HP ที่ไว้วนลูป
        cout << "Continue [1] ";
        //cout << "---------------------------------------------" << endl;
				checkNum2(1);
     }

    if(t->get_HP() > 0){ //ไวรัสยังไม่ตายเท่านั้น ถึงจะทายเลขกับเราได้
		cout << endl;
		cout << virusName << " has choosed a number." << endl;
		//สุ่มเลข 1 เลขเก็บไว้ใน VirusGuess //ใส่ไว้ให้บรรทัดที่ 97 นะ
		do {
			a = 0;
			try {
				cout << "Your Guess: ";
				cin >> playerGuess;
				if (cin.fail())
					throw "Wrong.It is not integer";
				if (playerGuess < -1 || playerGuess > 101)
					throw "Wrong.Number";
			} catch (const char *error) {
				cerr << error;
				cout << endl;
				a = 1;
				cin.clear();
				cin.ignore(50, '\n');
			}
		} while (a);
		virusGuess = random();
		cout << endl
			 << "Corona choosed number is '" << virusGuess << "'" << endl
			 << endl;
		atkDamage = damage(virusGuess, playerGuess, turn);


		if (virusGuess == playerGuess) {
			cout << "CRITICAL ATTACK !!!" << endl;
		}

    if(playerJob == "Samurai Warrior" && playerHP < 180){
        cout << ">> *You attack " << atkDamage << "(+10) damage*" << endl << endl;atkDamage +=10; 
    }
		else cout << ">> *You attack " << atkDamage << " damage*" << endl << endl;

		t->set_HP(atkDamage); //แก้ข้อมูล HP ปจบ.ของ Corona

    }//end if ถ้าโดน Purify Mage แล้วมอนไม่ตาย จะทายเลขกับเรา

		// ถ้า HP ของไวรัส < 0 หรือมันตาย ไวรัสจะไม่ตี แต่ขึ้นว่า Defeat เลย
		if (t->get_HP() == 0) //เลือดมอนหมด ลบออก เอาตัวใหม่เข้ามา
		{
			cout << "---------------------------------------------" << endl
				 << endl;
			delete_head();
			t = head;
			countDefeat++;

			cout << endl;

			if (countDefeat > 0 && t != NULL) { //ใช้เมื่อมอนตัวที่ 2 มาช่วยแล้วววว
				cout << "- '" << t->get_name() << "' enters the battle to"
					 << endl
					 << "  protect the colony... -" << endl
					 << endl;

				cout << "---------------------------------------------" << endl;
				cout << "Next [1] ";
				checkNum2(1);
			}

			if (t == NULL) { //มอนหมดก่อน แปลว่าชนะ >> จะไปทำ High Score ดูว่าติด Top
							 //5 มั้ย //เราจะใช้เป็นแบบ ดู mode ว่าเล่น mode ไหน
							 //Insertion กับคะแนนของโหมดนั้น
				cout << "---------------------------------------------" << endl << endl;
				cout << "       =**= !! Congratulation !! =**=        " << endl
					 << endl;

				cout << "            You win in " << turn << " turns!!" << endl
					 << endl;

				cout << "                -- Status --                " << endl;
				cout << "             Name  : " << playerName << endl;
				cout << "             Class : " << playerJob << endl;
				cout << "             HP    : " << playerHP << "/" << playerHPmax << endl;
				cout << "             Mode  : " << modeStr << endl << endl;

				cout << "       ==**=*==*=*==*=*==**=*==*=*==*==     " << endl;
				cout << "         Thanks for playing our game.       " << endl<<endl;

				cout << "----------------------------------------------" << endl;
				cout << "Continue [1] " << endl;
				checkNum2(1);

				// HighScore นี่ ไปไว้ข้างนอกใน Main จะมีประโยชน์ เมื่อ ถ้าเราเล่นจบแล้ว มาเรียก
				// High Score มันจะ Update ได้ :. เราจะต้องสร้างฟังก์ชันเชื่อมกับ Player คือ
				// get_Score ส่วน mode,name รู้ได้จาก main, rank คำนวณต่อได้, เวลาเรียกก็
				// ถ้ามันรันเกมจบ 1 ครั้ง มันจะเข้า main ใช่ปะ เราก็ใช้ int count = 0;
				// count ++; ถ้าเป็น 0; ยังไม่เล่นเกม จะเรียก HighScore เวอร์ชัน Default
				// ล้วน, ถ้าเล่นแล้ว จะเรียกแบบ printHighScore(rank,mode,name,turn)
				// ตามนี้ ลุย !!!!

				//ข้อจำกัดของโปรแกรมเรา คือ เราจะไม่เซฟ HighScore ให้
				//เพราะเวลาค่อนข้างจำกัด + ความชำนาญยังไม่มากพอ แต่อนาคตจะฝึกฝนให้ทำให้ได้
				//(ใช้ตอบใน Presentation ได้)

				//จากนั้น ถ้าชนะ เราจะสรุปผล ชื่อผู้เล่น, อาชีพ, เลือดที่เหลือ, mode, จำนวน
				//Turn แล้วพาไปดู High Score
			}
		} // end if มอนตาย

		else { //ถ้ามอนไม่ตาย จะตีเรา, HP Player ลด, ต้อง set ใหม่, ATK จะเพิ่ม
			   //ต้องเซ็ตใหม่ด้วย
			t->virusAttack(); // >> Virus attack xxx damage
			P->set_HP(virusATK);
			playerHP = P->get_HP(); //สำหรับ Loop while
			t->set_ATK(10);			// Virus ตีแรงขึ้น
			virusATK = t->get_ATK();

			cout << "---------------------------------------------" << endl;
			cout << "Next [1] ";
			checkNum2(1);
		} // end else

		P->set_score(turn);
		turn++;

	} // end while

	if (playerHP == 0) {
		cout << "---------------------------------------------" << endl;
		cout << "              -  Game Over -                 " << endl << endl;

		cout << "You are infected... " << endl << endl;

		cout << "Length of Survival: " << P->get_score() << " Turns" << endl
			 << endl;
		cout << "Thanks for playing our game." << endl;
		cout << "---------------------------------------------" << endl;
		return 0;
	} // end if
	else
		return 1;
} // end Fight

int damage(int botNum, int userNum, int turn) {
	int damage, damageplus = 0, cal;
	if (botNum == userNum) {
		damage = 200;
	} else {
		damage = botNum - userNum;
		if (damage > 0)
			damage *= (-1);
		damage += 100;
	}
  
	cal = damage + damageplus;
	return cal;
}