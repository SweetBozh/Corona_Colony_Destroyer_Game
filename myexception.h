class excep1:public exception{
  virtual const char* what() const throw(){
    return "Invaild Value,Try again!";
  }
}myex1;

class excep2:public exception{
  virtual const char* what() const throw(){
    return "Your answer is Out of Range,Try again! ";
  }
}myex2;

class excep3:public exception{
  virtual const char* what() const throw(){
    return "Please put 'yes'or 'no',Try again!";
  }
}myex3;



