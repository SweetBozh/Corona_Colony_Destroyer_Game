#ifndef Virus_h
#define Virus_h
class Virus{
  protected:
    string name;
    int ATK;
    int HP;
    int HPmax;
    //สำหรับ LinkedList
    Virus *next;
  public:
    Virus(string="Corona",int=99,int=999); //Constructor
    ~Virus(); //Destructor
    void operator-=(int);
    void show_HP();
    void set_HP(int);
    void set_ATK(int);

    void virusAttack();

    //สำหรับ LinkedList
    Virus *move_next(); //สำหรับเรียก next (เป็น Private) จากนอก Class Virus
    void insert(Virus *&);
    void show_node(); //สำหรับทดสอบว่า LinkedList สร้างถูกมั้ย
    string get_name();
    int get_HP();
    int get_ATK();
};

#endif