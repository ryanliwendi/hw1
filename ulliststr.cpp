#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  if (tail_ == nullptr)
  {
    Item *item = new Item;
    head_ = item, tail_ = item;
  }
  else if (tail_ -> last == ARRSIZE)
  {
    Item *item = new Item;
    item -> prev = tail_;
    tail_ -> next = item;
    tail_ = tail_ -> next;
  }
  tail_ -> val[tail_ -> last] = val;
  tail_ -> last ++;
  size_ ++;
}

void ULListStr::pop_back()
{
  tail_ -> last --;
  if (tail_ -> last == tail_ -> first) // No elements in the current Item
  {
    Item *temp = tail_;
    tail_ = tail_ -> prev;
    delete temp;
    if (tail_ == nullptr)
      head_ = tail_;
    else if (tail_ != nullptr)
      tail_ -> next = nullptr;
  }
  size_ --;
}

void ULListStr::push_front(const std::string& val)
{
  if (head_ == nullptr) /* In the case of adding the first element in the first Item,
                        * for convenience we'll let last increment by one instead of
                        * decrementing first, which requires creation of a new Item
                        */
  {
    Item *item = new Item;
    head_ = item, tail_ = item;
    head_ -> val[head_ -> first] = val;
    head_ -> last ++;
    size_ ++;
    return;
  }
  if (head_ -> first == 0)
  {
    Item *item = new Item;
    item -> next = head_;
    head_ -> prev = item;
    head_ = item;
    head_ -> first = ARRSIZE, head_ -> last = ARRSIZE;
  }
  head_ -> first --;
  head_ -> val[head_ -> first] = val;
  size_ ++;
}

void ULListStr::pop_front()
{
  head_ -> first ++;
  if (head_ -> first == ARRSIZE)
  {
    Item *temp = head_;
    head_ = head_ -> next;
    delete temp;
    if (head_ == nullptr)
      tail_ = head_;
    if (head_ != nullptr)
      head_ -> prev = nullptr;
  }
  size_ --;
}

std::string const & ULListStr::front() const
{
  return head_ -> val[head_ -> first];
}

std::string const & ULListStr::back() const
{
  return tail_ -> val[tail_ -> last - 1];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_)
    return nullptr;
  Item *temp = head_;
  int cur_loc = 0;
  while (cur_loc + (temp -> last - temp -> first) <= loc) // Find loc's corresponding Item
  {
    cur_loc += temp -> last - temp -> first;
    temp = temp -> next;
  }
  /* temp -> val + temp -> first: the pointer to the first element of the corresponding Item
   * loc - cur_loc: further amount of steps we need to take to reach loc
   */
  return temp -> val + (temp -> first) + loc - cur_loc;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
