///
/// Expression
///
/// operator
/**


**/
#include <iostream>
#include <string.h>
class Operand {
private:
    char* name;
    void setName(const char* tempName){
    /// Allocating
    name = new char[strlen(tempName)+1];
    /// copying
    strcpy(name,tempName);
    }
public:
    /// default constructor
    Operand(const char* nameTemp){
        /// call:
        setName(nameTemp);
    }
    Operand(){
        /// call:
        setName("empty");
    }
    /// copy constructor
    Operand (const Operand& copyOjbect){
        /// checking self-assignment
        if (this != &copyOjbect)
            this->setName(copyOjbect.name);
        else
            ;
    }
    /// copy assignment
    Operand& operator=(const Operand& copyOjbect){
        /// checking self-assignment
        if ( this != &copyOjbect)
            this->setName(copyOjbect.name);
        else
            ;

        return *this;
    }

    /// non-type assignment
    Operand& operator=(const char* tempName){
        /// check self-assignment
        if (strcmp(this->name,tempName))
            strcpy(this->name,tempName);
        else
            ;
        return *this;
    }

    /// set non-type assignment
    operator const char*(){
        return this->name;
    }
    operator char*(){
        return this->name;
    }
    /// destructor
    ~Operand(){
        delete[]name;
    }

    /// << overload
    friend std::ostream& operator<<(std::ostream& out,const Operand& obj){
        out<<obj.name;
        return out;
    }
};

int main(){
    { /// my sample
    }
    { /// en.reference.com
        Operand one;
        std::cout<<"one:         "<<one<<std::endl;
        Operand two("this is a two");

        /// copy assignment
        one = two;
        std::cout<<"one:         "<<one<<std::endl;

        /// copy constructor
        Operand three(one);
        std::cout<<"three:       "<<three<<std::endl;

        /// non-type assignment
        three = "this is a thee";
        std::cout<<"three again: "<<three<<std::endl;

        /// set non-type assignment
        const char* four = three;
        char* five = three;
        std::cout<<"four:        "<<four<<std::endl;
        std::cout<<"five:        "<<five<<std::endl;

    }

}

