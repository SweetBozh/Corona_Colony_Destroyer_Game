class BossVirus: public Virus{ 
   //มีคุณสมบัติต่างไปคือ มี Skill และ ฟังก์ชันชื่อเหมือนที่แสดงผลต่าง (Override), Constructor แบบ Overload
    private:
      string skill;
    public:
      BossVirus(string n="Boss Corona", int a =99, int hp = 999, string s="Default Skill");
      ~BossVirus();
      void set_HP(int);
      string get_skill();
      void castSkill();
};


//คลาสพ่อแม่ แปะไว้
/*class Virus{
  private:
    string name;
    int ATK;
    int HP;
    int HPmax;
    //สำหรับ LinkedList
    Virus *next;
  public:
    Virus(string="Corona",int=99,int=999); //Constructor
    ~Virus(); //Destructor
    void operator+=(int);
    void operator-=(int);
    //void died();
    void show_HP();
    void set_HP(int);
    void set_ATK(int);

    void virusAttack();
*/