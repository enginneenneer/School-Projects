#include <iostream>		
#include <string>               
#include <cmath>
#include <vector>
#include <algorithm>
#include<map>
#include<stack>

using namespace std;

class Numbers{
    private:
        int x, y , z;
    public:
        
        void menu(){
            cout << "\nLab. 3 OOP" << endl;
            cout << "1 = Ubung 1" << endl;
            cout << "2 = Ubung 2" << endl;
            cout << "4 = Ubung 4" << endl;
            cout << "0 = EXIT" << endl;
        }//menu()
        
        
        void ex_1(){            
            string nick;
            int year;
            cout << "Nick = ";
            cin >> nick; 
            if(cin.fail()) { cout << "Error String! Exit Now!"; cin.clear(); 
                            exit (EXIT_FAILURE);
                            }
            cout << "\nJahr = ";
            cin >> year; 
            if(cin.fail()) { cout << "Error Integer! Exit Now!"; cin.clear();
                            exit (EXIT_FAILURE);
                            }
            cout << nick << " wurde auf " << year << " geboren";
        }//ex_1
        
       
        int mini_rechner(string str)
        {
            map<char,int>priority;
            priority['^']=3;
            priority['*']=2,priority['/']=2;
            priority['+']=1,priority['-']=1;
        
            stack<char>op_stack;
            stack<int>val_stack;
        
            int val=0;
            for(int i=0;str[i];i++)
            {
                if(str[i]>='0'&&str[i]<='9')
                  val=val*10+str[i]-'0';
                else
                {
                    if(op_stack.empty()) // first operator
                    {
                        val_stack.push(val);
                        op_stack.push(str[i]);
                    }
                    else if(priority[op_stack.top()] < priority[str[i]]) // current operator is more prior then previous operator. so push it to stack.
                    {
                        val_stack.push(val);
                        op_stack.push(str[i]);
                    }
                    else // current operator is less prior then previous operator. so calculate previous operators resultant value
                    {
                        int num1,num2;
                        num1=val_stack.top(); val_stack.pop();
                        num2=val;
                        if(op_stack.top()=='+')
                          //val_stack.push(addition(num1, num2));
                          val_stack.push(num1 + num2);
                        else if(op_stack.top()=='-')
                          //val_stack.push(subtraction(num1, num2));
                          val_stack.push(num1 - num2);
                        else if(op_stack.top()=='*')
                          //val_stack.push(multiplication(num1, num2));
                          val_stack.push(num1 * num2);
                        else if(op_stack.top()=='/')
                          //val_stack.push(division(num1, num2));
                          val_stack.push(num1 / num2);
                        else
                          //val_stack.push(exponential(num1, num2));
                          val_stack.push(pow(num1 , num2));
                        op_stack.pop(); // as operator's value calculation done, pop it from the stack
                        op_stack.push(str[i]); // push the new operator
                    }
                    val=0;
                }
            }
            val_stack.push(val); // last value
        
            // calculate remaining operators value
            while(!op_stack.empty())
            {
                int num1,num2;
                num2=val_stack.top(); val_stack.pop();
                num1=val_stack.top(); val_stack.pop();
                if(op_stack.top()=='+')
                    //val_stack.push(addition(num1, num2));
                    val_stack.push(num1 + num2);
                else if(op_stack.top()=='-')
                    //val_stack.push(subtraction(num1, num2));
                    val_stack.push(num1 - num2);
                else if(op_stack.top()=='*')
                    //val_stack.push(multiplication(num1, num2));
                    val_stack.push(num1 * num2);
                else if(op_stack.top()=='/')
                    //val_stack.push(division(num1, num2));
                    val_stack.push(num1 / num2);
                else
                    //val_stack.push(exponential(num1, num2));
                    val_stack.push(pow(num1 , num2));
                op_stack.pop();
            }
            return val_stack.top();
        }

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
                cout << "0 = Exit \nTag = ";
                cin>>day;
                if (day=="0")
                    break;
                cout << endl;
                cout << "note = ";
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
        cout << "\n Wahle eine Option : " << endl;
        cin >> opt;
        if (opt == '1'){
            lab3.ex_1();
        }
        else if (opt == '2'){
            cout << "3+5+8*2 = "<<lab3.mini_rechner("3+5+8*2");
        }
        else if (opt == '4'){
            lab3.ex_4();
        }
        else {
            cout << "Exit now!";
            break;
        }
    }//while
     
 return 0;
}