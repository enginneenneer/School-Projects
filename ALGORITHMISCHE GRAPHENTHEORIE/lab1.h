#include <iostream>
using std::cout;
using std::endl;
int nikolaus[6][6];
int weg[10], ct;

void BKT(int knote)
{
    weg[ct] = knote; ct++;
    int i;
    if( ct == 9 )
    {
        for( i = 0 ; i < ct ; i++ )
            cout << weg[i];
        cout << endl;
        ct--;
        return;
    }
    
    for( i = 1 ; i <= 5 ; i++ )
    {
        if( nikolaus[knote][i] )
        {
            nikolaus[knote][i] = nikolaus[i][knote] = 0;
            BKT(i);
            nikolaus[knote][i] = nikolaus[i][knote] = 1;
        }
    }
    ct--;
}

int main()
{
    nikolaus[1][2] = nikolaus[2][1] = 1;
    nikolaus[1][3] = nikolaus[3][1] = 1;
    nikolaus[1][5] = nikolaus[5][1] = 1;
    nikolaus[3][4] = nikolaus[4][3] = 1;
    nikolaus[2][3] = nikolaus[3][2] = 1;
    nikolaus[2][5] = nikolaus[5][2] = 1;
    nikolaus[3][5] = nikolaus[5][3] = 1;
    nikolaus[4][5] = nikolaus[5][4] = 1;
    BKT(1);
    return 0;
}
Alex
