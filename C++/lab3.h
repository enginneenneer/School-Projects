#include <iostream>		
#include <string>               
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  
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
                    cout << "Yes";
            }
}