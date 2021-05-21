//Insertion


/*เพื่อที่จะสามารถเล่นซ้ำได้ แล้ว Score ของคนใหม่ จะเห็น Score ของคนเดิมอยู่ด้วย

งืมมมมมมมมมมมมมมมมมมมม ช่างมันเถอะ !! เวลาไม่พอที่จะทำละเอียดขนาดนั้น 

วนซ้ำ แต่ว่าคะแนนคนเล่นเก่าจะไม่อยู่ มีแต่ สมปอง สมหมาย สมหมี สมศรี สมเจต

เป็นข้อจำกัดที่ต้องระบุไปในรายงานด้วย

ทำจะเสร้จแล้วติดปัญหานิดหน่อย


*/
#ifndef HighScore_h
#define HighScore_h


void assignArray(int numbers[],int copyNum[]){
  for(int i=0; i<5; i++){
    copyNum[i] = numbers[i]; 
  }
}

void display(int numbers[], int numAmount)
{
  for (int i=0; i<numAmount; i++)
  {
    printf("%4d ",numbers[i]);
  }
  printf("\n");
}

//rank = (playerScore, 1)

int sortHighScore(int playerScore,int mode) //Insertion return อันดับที่
{
  //อยากรู้ว่าเป็นตำแหน่งที่เท่าไหร่ แล้วจะแสดงผลHighScoreในรูปแบบต่างๆ
  int scoreEasy[5] = {4,6,8,11,15};
  int scoreNormal[5] = {10,11,12,14,18};
  int scoreHard[5] = {20,22,26,30,35};

    int newValue = playerScore;
    
    int rank=6;

    int scoreSort[5];
    
    switch(mode){
      case 1: assignArray(scoreEasy,scoreSort); break;
      case 2: assignArray(scoreNormal,scoreSort); break;
      case 3: assignArray(scoreHard,scoreSort); break;
    }

    if(scoreSort[4] ==newValue) rank =5;
    int i;
    //Sort Ascending
    for(i=4; i>=0 && scoreSort[i]>newValue; i--) 
    //If found descending -> shift until not descending
    {
      rank--;
      scoreSort[i+1] = scoreSort[i];
     //display(scoreSort,5); 
    }
    scoreSort[i+1] = newValue;
    if(scoreSort[i] == newValue) rank--;
   //cout << "RANK " <<  rank;
    //display(scoreSort,5);
   return rank;
}

//--------------------------Printing High Score Zone------------------------------
//rank = (playerScore,1)
//mode = 1;



/*
  int choice;
  cout << "---------------------------------------------" << endl;
  cout << "                 - High Score-               " << endl;
  cout << "                   **-Easy-**                " << endl;
  cout << "     1. Sompong                    Turn 4    " << endl;
  cout << "     2. Sommai                     Turn 6    " << endl;
  cout << "     3. Sommee                     Turn 8    " << endl;
  cout << "     4. New Player                 Turn 11   " << endl;
  cout << "     5. Somsri                     Turn 15   " << endl;
  cout << endl;
  cout << "                  **-Normal-**               " << endl;
  cout << "     1. Sompong                    Turn 10   " << endl;
  cout << "     2. Som                     Turn 11   " << endl;
  cout << "     3. Sommee                     Turn 12   " << endl;
  cout << "     4. Somsri                     Turn 14   " << endl;
  cout << "     5. New Player                 Turn 18   " << endl;
  cout << endl;
  cout << "                   **-Hard-**                " << endl;
  cout << "     1. Sompong                    Turn 20   " << endl;
  cout << "     2. Sommai                     Turn 22   " << endl;
  cout << "     3. Sommee                     Turn 26   " << endl;
  cout << "     4. Somsri                     Turn 30   " << endl;
  cout << "     5. New Player                 Turn 35   " << endl;
  cout << "---------------------------------------------" << endl;
  */

void highscoreEasy(int rank, string name, int score){
      cout << "                   **-Easy-**                " << endl;
  switch(rank){
    case 1:
      cout << "     1. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     2. Sommai                     Turn 6    " << endl;
      cout << "     3. Sommee                     Turn 8    " << endl;
      cout << "     4. Somsri                     Turn 11   " << endl;
      cout << "     5. Somjade                    Turn 15   " << endl;
      cout << endl;
      break;
    case 2:
      cout << "     1. Sompong                    Turn 4    " << endl;
      cout << "     2. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     3. Sommee                     Turn 8    " << endl;
      cout << "     4. Somsri                     Turn 11   " << endl;
      cout << "     5. Somjade                    Turn 15   " << endl;
      cout << endl;
      break;
    case 3:
      cout << "     1. Sompong                    Turn 4    " << endl;
      cout << "     2. Sommai                     Turn 6    " << endl;
      cout << "     3. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     4. Somsri                     Turn 11   " << endl;
      cout << "     5. Somjade                    Turn 15   " << endl;
      cout << endl;
      break;
    case 4:
      cout << "     1. Sompong                    Turn 4    " << endl;
      cout << "     2. Sommai                     Turn 6    " << endl;
      cout << "     3. Sommee                     Turn 8    " << endl;
      cout << "     4. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     5. Somjade                    Turn 15   " << endl;
      cout << endl;
      break;
    case 5:
      cout << "     1. Sompong                    Turn 4    " << endl;
      cout << "     2. Sommai                     Turn 6    " << endl;
      cout << "     3. Sommee                     Turn 8    " << endl;
      cout << "     4. Somsri                     Turn 11   " << endl;
      cout << "     5. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << endl;
      break;
    default:
      cout << "     1. Sompong                    Turn 4    " << endl;
      cout << "     2. Sommai                     Turn 6    " << endl;
      cout << "     3. Sommee                     Turn 8    " << endl;
      cout << "     4. Somsri                     Turn 11   " << endl;
      cout << "     5. Somjade                    Turn 15   " << endl;
      cout << endl;
      break;
  }
}

void highscoreNormal(int rank, string name, int score){
      cout << "                  **-Normal-**               " << endl;
  switch(rank){
    case 1:
      cout << "     1. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     2. Sommai                     Turn 11   " << endl;
      cout << "     3. Sommee                     Turn 12   " << endl;
      cout << "     4. Somsri                     Turn 14   " << endl;
      cout << "     5. Somjade                    Turn 18   " << endl;
      cout << endl;
      break;
    case 2:
      cout << "     1. Sompong                    Turn 10   " << endl;
      cout << "     2. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     3. Sommee                     Turn 12   " << endl;
      cout << "     4. Somsri                     Turn 14   " << endl;
      cout << "     5. Somjade                    Turn 18   " << endl;
      cout << endl;
      break;
    case 3:
      cout << "     1. Sompong                    Turn 10   " << endl;
      cout << "     2. Sommai                     Turn 11   " << endl;
      cout << "     3. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     4. Somsri                     Turn 14   " << endl;
      cout << "     5. Somjade                    Turn 18   " << endl;
      cout << endl;
      break;
    case 4:
      cout << "     1. Sompong                    Turn 10   " << endl;
      cout << "     2. Sommai                     Turn 11   " << endl;
      cout << "     3. Sommee                     Turn 12   " << endl;
      cout << "     4. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     5. Somjade                    Turn 18   " << endl;
      cout << endl;
      break;
    case 5:
      cout << "     1. Sompong                    Turn 10   " << endl;
      cout << "     2. Sommai                     Turn 11   " << endl;
      cout << "     3. Sommee                     Turn 12   " << endl;
      cout << "     4. Somsri                     Turn 14   " << endl;
      cout << "     5. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << endl;
      break;
    default:
      cout << "     1. Sompong                    Turn 10   " << endl;
      cout << "     2. Sommai                     Turn 11   " << endl;
      cout << "     3. Sommee                     Turn 12   " << endl;
      cout << "     4. Somsri                     Turn 14   " << endl;
      cout << "     5. Somjade                    Turn 18   " << endl;
      cout << endl;
      break;
  }
}



void highscoreHard(int rank, string name, int score){
      cout << "                   **-Hard-**                " << endl;
  switch(rank){
    case 1:
      cout << "     1. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     2. Sommai                     Turn 22   " << endl;
      cout << "     3. Sommee                     Turn 26   " << endl;
      cout << "     4. Somsri                     Turn 30   " << endl;
      cout << "     5. Somjade                    Turn 35   " << endl;
      cout << endl;
      break;
    case 2:
      cout << "     1. Sompong                    Turn 20   " << endl;
      cout << "     2. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     3. Sommee                     Turn 26   " << endl;
      cout << "     4. Somsri                     Turn 30   " << endl;
      cout << "     5. Somjade                    Turn 35   " << endl;
      cout << endl;
      break;
    case 3:
      cout << "     1. Sompong                   Turn 20   " << endl;
      cout << "     2. Sommai                    Turn 22   " << endl;
      cout << "     3. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     4. Somsri                    Turn 30   " << endl;
      cout << "     5. Somjade                   Turn 35   " << endl;
      cout << endl;
      break;
    case 4:
      cout << "     1. Sompong                   Turn 20   " << endl;
      cout << "     2. Sommai                    Turn 22   " << endl;
      cout << "     3. Sommee                    Turn 26   " << endl;
      cout << "     4. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << "     5. Somjade                   Turn 35   " << endl;
      cout << endl;
      break;
    case 5:
      cout << "     1. Sompong                   Turn 20   " << endl;
      cout << "     2. Sommai                    Turn 22   " << endl;
      cout << "     3. Sommee                    Turn 26   " << endl;
      cout << "     4. Somsri                    Turn 30   " << endl;
      cout << "     5. "<<setw(27) << left << name << "Turn " << score  << endl;
      cout << endl;
      break;
    default:
      cout << "     1. Sompong                   Turn 20   " << endl;
      cout << "     2. Sommai                    Turn 22   " << endl;
      cout << "     3. Sommee                    Turn 26   " << endl;
      cout << "     4. Somsri                    Turn 30   " << endl;
      cout << "     5. Somjade                   Turn 35   " << endl;
      cout << endl;
      break;
  }
}

void printHighScore(int rank,int mode,string name,int score)
{
  //ถ้าคะแนนมีตัวที่ไม่ใช่ Dafault อยู่ จะต้องขึ้นว่า ยินดีด้วยชนะ
  //ถ้ามีแต่ Default จะขึ้นว่าแพ้ (อยู่นอก printHighScore) จะส่งยังไงดี
  //return 1 แปลว่า ติดอันดับ return 0 แปลว่าแห้ว
  cout << "---------------------------------------------" << endl;
  cout << "                 - High Score-               " << endl<<endl;
  switch(mode){
    case 1: 
      highscoreEasy(rank,name,score);
      highscoreNormal(0,name,score);
      highscoreHard(0,name,score); //เรียก Dafault
      break;
    case 2: 
      highscoreEasy(0,name,score);
      highscoreNormal(rank,name,score);
      highscoreHard(0,name,score);
      break;
    case 3: 
      highscoreEasy(0,name,score);
      highscoreNormal(0,name,score);
      highscoreHard(rank,name,score);
      break;
    default:
      highscoreEasy(0,name,score);
      highscoreNormal(0,name,score);
      highscoreHard(0,name,score);
      break;
  }  
  cout << "---------------------------------------------" << endl;
  cout << "Continue [1]" << endl;
}

#endif