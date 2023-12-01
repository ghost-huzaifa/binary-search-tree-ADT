#include <cstdlib>
#include <iostream>
#include "include/BinarySearchTree.h"
using namespace std;
const int MAX_SIZE = 100;

int main()
{
  BinarySearchTree<int> T1;
  for (int i = 0; i < MAX_SIZE; i++) {
    T1.insert(rand()%1000);
  }
  while (1) {
    system("CLS");
    cout << "Binary Search Tree [version-0.01]" << endl;
    cout << "\t[I]nsert Element" << endl
      << "\t[S]earch Element" << endl
      << "\t[R]emove Element" << endl
      << "\t[P]rint Tree (IN-ORDER Traversal)" << endl
      << "\t[Q]uit" << endl;
      char opt;
      cin >> opt;
      switch (opt) {
        case 'Q':
          {
            exit(0);
          }
          case 'I':
          {
            int temp;
            cout << "Enter Element to Insert: " << endl;
            cin >> temp;
            if(cin){
              T1.insert(temp);
              cout << "Element has been inserted to the Tree" << endl;
              break;
            }
            else {
              cout << "Invalid Insertion of Element. Exiting...." << endl;
              exit(1);
            }
          }
          case 'S':
          {
            if(T1.empty())
               cout << "No Nodes are present at the moment. Please Insert some first." << endl;
            else
            {
              cout << "Enter Element to Search: " << endl;
              int temp;
              cin >> temp;
              if(cin){
                if(!T1.search(temp))
                  cout << "Element Not Found" << endl;
                else
                cout << "[Success]\n\tElement is present in the Tree" << endl;
              break;
              }
              else {
              cout << "Invalid Insertion of Element. Exiting...." << endl;
              exit(1);
              }
            }
            break;
    }
          case 'R':
          {
            if(!T1.empty()){
              cout << "Enter Element to remove: " << endl;
              int temp;
              cin >> temp;
              if(cin){
                T1.remove(temp);
                cout << "Operation Done." << endl;
              }
              else {
              cout << "Invalid Insertion of Element. Exiting...." << endl;
              exit(1);
              }
            }
            else {
             cout << "No Nodes are present at the moment. Please Insert some first." << endl;
            }
            break;
          }
          case 'P':
          {
            T1.printTree();
            break;
          }
          default: 
          cout << "Invalid Option" << endl;
      }
      system("PAUSE");
  }
    return 0;
}
