#include "List.h"

#include <iostream>
#include <chrono>
#include <ctime>
#include "tddFuncs.h"

using namespace std;

int main(){

   cout << "Running tests from: " << __FILE__ << endl;


   ///////////2000 ints
   List<int> l;

  auto begin = std::chrono::high_resolution_clock::now();

  for( int i = 0; i < 2000; i++)
    l.insert(l.getSize()/2, i);


  auto end = std::chrono::high_resolution_clock::now();
  std::cout<< "\nInsert 2000 ints: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " ns" << std::endl;


  ASSERT_EQUALS(2000,l.getSize());



  /////////////////4000 ints
  List<int> m;
  begin = std::chrono::high_resolution_clock::now();

  for( int i = 0; i < 4000; i++)
    m.insert(m.getSize()/2, i);


  end = std::chrono::high_resolution_clock::now();
  std::cout<< "\nInsert 4000 ints: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " ns" << std::endl;

  
  ASSERT_EQUALS(4000,m.getSize());


  ///////////////6000 ints
  List<int> p;
  begin = std::chrono::high_resolution_clock::now();

  for( int i = 0; i < 6000; i++)
    p.insert(p.getSize()/2, i);


  end = std::chrono::high_resolution_clock::now();
  std::cout<< "\nInsert 6000 ints: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " ns" << std::endl;


  ASSERT_EQUALS(6000,p.getSize());


  //////////////8000 ints
    List<int> n;
  begin = std::chrono::high_resolution_clock::now();

  for( int i = 0; i < 8000; i++)
    n.insert(n.getSize()/2, i);


  end = std::chrono::high_resolution_clock::now();
  std::cout<< "\nInsert 8000 ints: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " ns" << std::endl;


  ASSERT_EQUALS(8000,n.getSize());


  /////////////10000 ints
  List<int> o;
  begin = std::chrono::high_resolution_clock::now();

  for( int i = 0; i < 10000; i++)
    o.insert(o.getSize()/2, i);


  end = std::chrono::high_resolution_clock::now();
  std::cout<< "\nInsert 10000 ints: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " ns" << std::endl;


  ASSERT_EQUALS(10000,o.getSize());
   
}
