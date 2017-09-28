#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class String{
    
    // less than inequality operator
    friend bool operator<(const String& alpha, const String& beta){
        int length = 0;
        if(alpha.crtsize <= beta.crtsize){
            length = alpha.crtsize;
        }else
            length = beta.crtsize;
        for(int i=0; i< length; i++){
            if (alpha.str[i] < beta.str[i]){
                return true;
            }else if(alpha.str[i] > beta.str[i])
                return false;
        }
        return false;
    }
    
    //greater than inequality operator
    friend bool operator>(const String& alpha, const String& beta){
        return (beta < alpha);
    }
    
    //equality operator
    friend bool operator==(const String& alpha, const String& beta){
        return !(alpha < beta || alpha > beta);
    }
    
    //not equals operator
    friend bool operator!=(const String& alpha, const String& beta){
        return !(alpha == beta);
    }
    
    //less than or equal to 
    friend bool operator<=(const String& alpha, const String& beta){
        return (alpha < beta || alpha == beta);
    }
    
    //greater than or equal to 
    friend bool operator>=(const String& alpha, const String& beta){
        return (alpha > beta || alpha == beta);
    }
    
    //insertion operator 
    friend ostream& operator<<(ostream& out, const String& itr){
        for(int i = 0; i< itr.crtsize; i++){
            out << itr.str[i];
        }
        return out;
    }
    //extraction operator
    friend istream& operator>>(istream& buffer, String& itr){
        int i = 0;
        char ch;
        itr.crtsize = 0;
        while (buffer >> ch){
         if (itr.crtsize == (itr.size-1) )
               {itr.resize();}
            itr.str[i] = ch;
            itr.crtsize++;
            i++;
            if (cin.peek() == '\n' || cin.peek() == ' ')
             break;
            }
     return buffer;
    }
    
    friend istream& getline(istream& buffer, String& itr, char limit = '\n'){
        int i = 0;
        char ch;
        itr.crtsize = 0;
        while (cin.get(ch)){
         if (itr.crtsize == (itr.size-1) )
               {itr.resize();}
            itr.str[i] = ch;
            itr.crtsize++;
            i++;
            if (cin.peek() == limit)
             break;
            }
     return buffer;
    }
    
    public:
    // Default Constructor
    String(){
        size = 1; 
        crtsize  = 0;
        str = new char[size];
    }
    // CString Constructor
    String(char* strchar){
        crtsize = strlen(strchar);
        size = crtsize + 5; 
        str = new char[size];
        for(int i=0; i < crtsize; i++){
            str[i] = strchar[i];
        }
    }
    // Copy Constructor
    String(const String& st){
        size = st.size;
        crtsize = st.crtsize;
        str = new char[st.size];
        for(int i = 0; i < crtsize; i++){
            str[i] = st.str[i];
        }
    }
    // Assignment operator
    String& operator=(const String& st){
        
        if(this->str != st.str){
        delete [] str;
        
        size = st.size;
        crtsize = st.crtsize;
        
        str = new char[st.size];
        
        for(int i = 0; i < crtsize; i++){
            str[i] = st.str[i];
        }
    }
    return *this;    
    }
    
    // Destructor
    ~String(){
        delete [] str;
        crtsize = 0;
    }
    
    int length(){
        return this->crtsize;
    }
   
    int maxsize(){
        return this->size;
    }
    
    bool empty(){
        if(this->crtsize==0)
            return true;
        return false;
    }
    
    void clear(){
        delete [] this->str;
        this->crtsize = 0;
    }
    
    char& operator[](int pos){
    int p;
      if (pos > crtsize-2)
        p = crtsize-2;
      else if(pos < 0)
        p = 0;
      else
        p = pos;
    
    return this->str[p];
    }
    
    const char& operator[](int pos) const{
      int p = pos;
      if (p > crtsize-2)
        p = crtsize-2;
      else if(p < 0){
        p = 0;
      }
      else
        p = pos;
    
    return this->str[p];
    }
    
    char& back(){
        return this->str[crtsize-2];
    }
    
    const char& back() const{
        return this->str[crtsize-2];
    }
    
    char& front(){
        return this->str[0];
    }
    
    const char& front() const{
        return this->str[0];
    }
    
    friend String& operator+(const String& alpha, const String& beta){
        String* temp = new String; 
        temp->size = alpha.crtsize+beta.crtsize+5;
        temp->crtsize = alpha.crtsize+beta.crtsize;
        
        temp->str = new char[temp->size];
        for(int i =0, j=0;i<temp->crtsize;i++)
        {
            if (i < alpha.crtsize){
                temp->str[i] = alpha.str[i];
            }else{
                temp->str[i] = beta.str[j];
                j++;
            }
        }

        return *temp;
    }
   
   String& operator+=(const String& beta){
      *this = *this + beta;
      return *this;
   }
   
    
    private:
    int size;    // size of cstring array
    int crtsize; // tracker variable
    char * str; // cstring pointer
    // helper Resize function
    void resize(){
        int nsze = size*2;
        char *temp = new char[nsze]; 
        for(int i = 0; i < crtsize; i++){
            temp[i] = str[i];
        }
        
        delete [] str; 
        str = temp;
        
    }

};
