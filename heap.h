#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  
  void heapify(int idx);


private:
  /// Add whatever helper functions and data members you need below
  vector<T> data;
  int aryn;
  PComparator comparator;

};

// Add implementation of member functions here

// constructor for heap
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
    comparator = c;
    aryn = m;
}

// deconstructor for heap
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
  while(!empty()){
    data.pop_back();
  }

}

// pushes item back into heapf
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  data.push_back(item);
  int idx = data.size()-1;
  while(comparator(data[idx], data[(idx-1)/aryn])){
    swap(data[idx],data[(idx-1)/aryn]);
    idx = (idx-1)/aryn;
  }
  return;
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const // FINISHED FUNCTION
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw underflow_error("No elements");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw underflow_error("No elements to pop");
  }
  T temp = data[data.size()-1];
  data[0] = temp;
  data.pop_back();
  heapify(0);


}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx){
  // if statement to check if leaf node
  if((unsigned)idx*aryn+1 >= data.size()){
    return;
  }
  // index of child with greatest value, initalized with first child
  int value_child = aryn*idx+1;
  // loop to go through all siblings of value_child and find the most valuable node
  int temp = value_child;
  for(int i=1; i<aryn; i++){
    if((unsigned)temp + i < data.size()){
      // compares value child with all other sibligs
      if(comparator(data[temp+i], data[value_child])){
        value_child = temp + i;
        }
    }
  }
  if(comparator(data[value_child], data[idx])){
    swap(data[value_child], data[idx]);
    heapify(value_child);
  }
}




// returns bool if empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return data.size();
}



#endif
