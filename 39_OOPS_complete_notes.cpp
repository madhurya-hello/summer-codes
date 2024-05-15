/*

// OBJECT ORIENTED PROGRAMMING IN C++

class Hero{
    
    // note that "private" and "public" are called access modifiers

    private:    // can be accessed inside the class only
    int health;

    public:     // can be accessed outside the class also 
    char level;

    // constructor
    Hero(){
        cout<<"constructor called";
    }

    // parameterised constructor
    Hero(int health){
        this -> health = health;    // note that "this->health" represents the health variable declared under the class. This is because (*this).health is actually writen as this->health
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }
}

int main(){
   
    // Creating an object (static allocation)
    Hero a;
    a.setHealth(90);
    a.setLevel('B');
    cout << "level is: " << a.level;
    cout << "Health is: " << a.health;

    // Creating an object (dynamic allocation)
    Hero *b = new Hero;
    b->setHealth(30);       // note that b->something is same as (*b).something
    b->setLevel('D');
    cout << "Level is: " << (*b).level;         // could also be written as cout << "Level is: " << b->level;
    cout << "Health is: " <<  (*b).health;      // could also be written as cout << "Health is: " <<  b->health;

    // NOTE
    when we create an object by "Hero ramesh;"  then by default, the contructor "Hero()" will be called
    therefore we can use "Hero ramesh(50);" to call the constructor "Hero(int health)" i.e. "Hero ramesh(50);" will create an object ramesh with its health set as 50
    if we sometimes do not manually create the "Hero()" constructor, then c++ will automatically create a default Hero() constructor
    but parameterised constructors must be created manually

    // V.V.IMP NOTE
    as discussed earlier, when we create a class named "Hero", then c++automatically creates a default constructor "Hero()" inside the class
    now, if we define our own constructor named "Hero()" inside the class then the default one gets deleted
    but, if we decide to define a parametirised constructor "example: Hero(int level)" without defining the "Hero()", then also the original "Hero()" will get deleted and then whenever we try to create "Hero ramesh;" inside int main(), it will give an error since "Hero()" is deleted
    therefore we must define the "Hero()" before defining any parameterised constructor

}

// COPY CONSTRUCTOR

Hero ramesh(50, 'B');    // an object ramesh is created with health=50 and level='B'
Hero suresh(ramesh);     // this will call a constructor named "copy" (inbuilt constructor) which will create an object named suresh and will copy all the contents of ramesh into suresh

Hero (Hero &temp) {       // we can also define the copy constructor ourselves
this->health = temp.health;
this->level = temp.level;
}
// ofcourse if we define the copy constructor ourselves, then the inbuilt one will get deleted

// SHALLOW AND DEEP COPY 

the inbuild copy constructor creates a shallow copy. this means that the address at which the values are stored in ramesh is copied into suresh. since the address is copied, therefore if any value of ramesh changes, the same change can also be seen in suresh
Hence, we can define a constructor which will do a deep copy so that both the object are independent of each other

Hero ramesh("ramesh baba");  // an object ramesh will be created with name="ramesh baba"
Hero (Hero &temp){      // inside the "Hero" class we will define a constructor
    char *ch = new char[strlen(temp.name) + 1];     // a new empty character array is created dynamically
    strcpy(ch, tenp.name);      // the name "ramesh baba" is copied to the array
    this->name=ch;
}
Hero suresh(ramesh);    // now a deep copy of "ramesh baba" will be store in "suresh.name" and even if we change the "ramesh.name" to "ramesh singh", the "suresh.name" will still contain "ramesh baba"

// ASSIGNMENT OPERATOR

Hero ramesh(50, "A");
Hero suresh(35, "C");

suresh = ramesh     // all the values of ramesh will be copied to suresh

// DESTRUCTOR

when defining a destructor, we use a tilda sign (~)

~Hero{
    cout<<"destructor is called";
}

note that, when an object is created statically, then destructor will be called automatically at the end of the program
but, when an object is created dynamically, we have to manually call the destructor
Hero *b = new Hero;
delete b;   // destructor called

// STATIC KEYWORD

class Hero{
    private:
    int health;
    public:
    char level;
    static int timeToComplete;  //  it is linked with the class and hence is same for all the objects
}
int Hero::timeToComplete = 5;   // its value can be accessed using the scope resolution operator (::)
int main(){
    cout<<Hero::timeToComplete; // its value can be accesed even without creating an object
    Hero ramesh;
    cout<<ramesh.timeToComplete;    // its value can also be accessed with the help of an object (but it is not recommended)
    Hero suresh;
    suresh.timeToComplete = 10;     // the value is changed, and since the static operator is class dependent, the value inside ramesh will also change
}

// STATIC FUNCTION

note that static functions can only access static members
hence, the use of health, level, etc. will give an error
also note that static functions does not have the "this" keyword 
hence, "this->health" will an give an error

class Hero{
    private:
    int health;
    public:
    char level;
    static int timeToComplete;  
    static int random(){        
        return timeToComplete;
    }
}
int Hero::timeToComplete = 5;
int main(){
    cout<<Hero::random()<<endl;   // static function are accessed using the scope resolution operator
}


// 4 PILLARS OF OOPS = ENCAPSULATION | INHERITANCE | POLYMORPHISM | ABSTRACTION

// ENCAPSULATION //

when a class is created containing members like health, level, etc. and functions like getter, setter, etc. then it is called encapsulation
if we keep all the members of a class under "private" and getter and setter are not defined, then it can never be accessed in the "int main()", hence encapsulation can hide information
if we define getter but donot define setter then the member of class can only be accessed in the "int main()" and cannot be changed, hence by encapsulation we can also make the data "read-only"

// INHERITANCE //

all the members and functions of the parent class (under public and protected) are copied (shallow) to the child class

class Human{    
    public:
    int age=50;
    public:
    int getAge(){
        return age;
    }
    void setAge(int age){
        this->age=age;
    }
};
class Male: public Human {      // class Child_Class: mode_of_inheritance Parent_Class   // all the members and functions of "Human" are copied (shallow) to "Male" 
    public:
    int height=195;
    void sleep(){
        cout<<"I am sleeping"<<endl;
    }
};
int main()
{
    Male Devon;
    Human Levan;
    cout<<Devon.age;    // even though age is not defined under "Male", it can be accessed due to inheritance
    Devon.setAge(35);   // when the age of devan is set to 35, the age of levan will also change to 35
}


# Access Modifier Table :

1. Public
2. Protected    // simillar to private but can also be accesed inside the child class
3. Private 

Parent Class    |   Mode of Inheritance     |   Child Class
public          |   public                  |   public
public          |   protected               |   protected
public          |   private                 |   private
protected       |   public                  |   protected
protected       |   protected               |   protected
protected       |   private                 |   private

# Types of Inheritance :

01. Single Inheritance

class Hero1{

}
class Hero2: public Hero1{

}

02. Multi Level Inheritance

class Hero1{

}
class Hero2: public Hero1{

}
class Hero3: public Hero2{

}

03. Multiple Inheritance

class Hero1{

}
class Hero2{

}
class Hero3: public Hero1, public Hero2{

}

Note: 
let's say a function named "func" is present on both class "Hero1" and "Hero2", then in that case both the functions will be inherited by Hero3
Hero3.Hero1::func();    // this will call the function "func" of Hero1
Hero3.Hero2::func();    // this will call the function "func" of Hero2

04. Hierarchical Inheritance

class Hero1(){

}
class Hero2: public Hero1{

}
class Hero3: public Hero1{

}

05. Hybrid Inheritance

if two or more of the above mentioned inheritance types are used

class Hero1{

}
class Hero2{

}
class Hero3: public Hero1{

}
class Hero4: public Hero2, public Hero3{

}


// POLYMORPHISM //

# Compile-Time Polymorphism

1. Function Overloading
it allows us to define multiple functions with the same name, but the condition is that the input parameters must be different

class Hero{
    void sayName{
        cout<<"Hello"<<endl;
    }
    void sayName(string name){
        cout<<"Hello"<<name<<endl;
    }
    void sayName(string name, int age){
        cout<<"Hello"<<name<<endl;
    }
    void sayName(string name, char sex){
        cout<<"Hello"<<name<<endl;
    }
}

Note:
we can create function overloading only by changing the input parameters
we cannot create a function overloading by chaning the return type
void sayName(){
    cout<<"Hello"<<endl;
}
int sayName(){              // this will not cause any function overloading 
    cout<<"Hello"<<endl;
    return 1;
}

2. Operator Overloading

Example 1: making the '+' operator to substract two numbers instead of adding them

class Hero{
    public:
    int a;

    void operator+ (Hero &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout<< value1-value2
    }
}

int main(){
    Hero obj1, obj2;
    obj1.a = 10;
    obj2.a = 7;
    obj1 + obj2;    // this will print 3
}

Example 2: making the '()' operator to print "hello"

class Hero{
    void operator() (){
        cout<<"Hello"<<endl;
    }
}
int main(){
    Hero obj1;
    obj1();     // this will print "Hello"
}

# Run-Time Polymorphism

class Hero1{
    void speak{
        cout<<"Ha Ha Ha"<<endl;
    }
}
class Hero2: public Hero1{
    void speak{
        cout<<"La La La"<<endl;
    }
}
class Hero3: public Hero1{
    void speak{
        cout<<"Da Da Da"<<endl;
    }
}
int main(){
    Hero2.speak();  // will print "La La La"
    Hero3.speak();  // will print "Da Da Da  "
}

// ABSTRACTION //

read it from: https://stackoverflow.com/questions/742341/difference-between-abstraction-and-encapsulation


*/