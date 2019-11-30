#include <iostream> 
#include <iterator> 
#include <map> 
  
using namespace std; 
  
int main() 
{  
    map<int, int> gquiz1; 
    gquiz1.insert(pair<int, int>(1, 40)); 
    gquiz1.insert(pair<int, int>(2, 30)); 
    gquiz1.insert(pair<int, int>(3, 60)); 
    gquiz1.insert(pair<int, int>(4, 20)); 
    gquiz1.insert(pair<int, int>(5, 50));  
    gquiz1.insert(pair<int, int>(6, 50)); 
    gquiz1.insert(pair<int, int>(7, 10));
    map<int, int>::iterator itr;  
    cout<<gquiz1.at(1);
    gquiz1[8]=90;
    cout<<endl;
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) { 
        cout<<itr->first<<" ";
    } 
    cout<<endl;
       for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) { 
          cout<<itr->second<<" "; 
    }
    cout<<endl<<endl;
    cout << endl;
    return 0;
}
