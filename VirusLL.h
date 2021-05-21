#ifndef VirusLL_h
#define VirusLL_h
class VirusLL{ //Virus LinkedList
  private: 
    Virus *head;
    int size;
  
  public:
    void add_node(Virus *&);
    void show_all();
    int Fight(Player *&,int); 
  
    
    VirusLL(); //constructor
    ~VirusLL(); //destructor
    void delete_head();
    string get_virusName();
    int random(); //random1-100
};

#endif