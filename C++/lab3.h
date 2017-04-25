
#include <iostream>		
#include <string>               
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

class Numbers{
    private:
        int x, y , z;
    public:
        
        void menu(){
            cout << "\nLab. 3 OOP" << endl;
            cout << "1 = Exercitiu 1" << endl;
            cout << "2 = Exercitiu 2" << endl;
            cout << "4 = Exercitiu 4" << endl;
            cout << "0 = EXIT" << endl;
        }//menu()
        
        
        void ex_1(){            
            string nick;
            int year;
            cout << "nick = ";
            cin >> nick; 
            if(cin.fail()) { cout << "Error String! Exit Now!"; cin.clear(); 
                            exit (EXIT_FAILURE);
                            }
            cout << "\nyear = ";
            cin >> year; 
            if(cin.fail()) { cout << "Error Integer! Exit Now!"; cin.clear();
                            exit (EXIT_FAILURE);
                            }
            cout << nick << " was born on " << year;
        }//ex_1
        
       
        int ex_2(){
            try {
                int lval{0}; int rval{0}; char op{' '};
                cout << "Rechenausdruck (mit +,-,*,/, Ende mit ;) ";
                cin >> lval;
                if( !cin ) { cerr << "Kein linker Operand"; return -1; }
                while( cin >> op && op != ';' ) {
                    if( !cin ) { cerr << "Kein Operator"; return -2; }
                    cin >> rval;
                    if( !cin ) { cerr << "Kein rechter Operand"; return -3; }
                    switch( op ){
                        case '+': lval += rval; break;
                        case '-': lval -= rval; break;
                        case '*': lval *= rval; break;
                        case '/': lval /= rval; break;
                        default : { cerr << "Unbekannter Operator"; return -4; }
                    }//switch()
            }// while()
            cout << "Ergebnis: " << lval << endl;
            return 0;
            }
            catch (int lval){
                    cout << "Error";
            }
        }//ex_2()
        
        float avg_vector(vector<int> v){
          if (v.size() == 0)
            return 0;
          else{
            float sum = 0;
            for_each(v.begin(), v.end(), [&] (float n) {
              sum += n;
            });
            return (sum / v.size()); 
          }
        }
        
        void ex_4(){
            vector<int> mon, tue, wed, thu, fri, sat, sun;
            string day{"yes"};
            int grade{0};
            
            while (true){
                cout << "Type 0 if you want out\nday = ";
                cin>>day;
                if (day=="0")
                    break;
                cout << endl;
                cout << "grade = ";
                cin>>grade;
                if (day== "mon")
                    mon.push_back(grade);
                if (day=="tue")
                    tue.push_back(grade);
                if (day=="wed")
                    wed.push_back(grade);
                if (day=="wed")
                    wed.push_back(grade);
                if (day=="fri")
                    fri.push_back(grade);
                if (day=="sat")
                    sat.push_back(grade);
                if (day=="sun")
                    sun.push_back(grade);
            }//while
            
            cout <<"Mon = " << avg_vector(mon) << endl;
            cout <<"Tue = " << avg_vector(tue) << endl;
            cout <<"Wed = " << avg_vector(wed) << endl;
            cout <<"Thu = " << avg_vector(thu) << endl;
            cout <<"Fri = " << avg_vector(fri) << endl;
            cout <<"Sat = " << avg_vector(sat) << endl;
            cout <<"Sun = " << avg_vector(sun) << endl;
        }//ex_4()  
};

int main( ) {
    
    Numbers lab3;
    
    while (true) {
        lab3.menu();
        char opt;
        cout << "\n Choose an option : " << endl;
        cin >> opt;
        if (opt == '1'){
            lab3.ex_1();
        }
        else if (opt == '2'){
            cout << lab3.ex_2();
        }
        else if (opt == '4'){
            lab3.ex_4();
        }
        else {
            cout << "Exit now!";
        }
    }//while
     
    
 return 0;
}
