
#include <iostream>
using namespace std;

namespace Space1
{
    void greeting( );
}

namespace Space2
{
    void greeting( );
}

void bigGreeting( );  //global namespace
//void greeting( );     this is not the compiler error

int main( )
{
    {
        using namespace Space2;
        greeting( );  //is compiler error (if you do line 16)
                      //compiler doesn't know which greeting to call
                      //greeting from Space2 or greeting from global namespace
                      //You can solve this problam by saying "Space2::greeting( );"
                        //in this case you don't do line 21
    }

    {
        using namespace Space1;
        greeting( );  //is compiler error (if you do line 16)
    }

    bigGreeting( );
    //greeting( ); is not a compiler error too (if you do line 16)

    return 0;
}

namespace Space1
{
    void greeting( )
    {
        cout << "Hello from namespace Space1.\n";
    }
}

namespace Space2
{
    void greeting( )
    {
        cout << "Greetings from namespace Space2.\n";
    }
}

void bigGreeting( )
{
    cout << "A Big Global Hello!\n";
}
