class _stack {
  stack<int> s;
  int minEle;
public :
  int getMin();
  int pop();
  void push(int);
};

/*returns min element from stack*/
int _stack :: getMin()
{
  if (s.empty()) return -1 ;
  else return minEle ;
}

/*returns poped element from stack*/
int _stack ::pop()
{
  if ( s.empty()) return -1 ;
  int top = s.top() ;
  s.pop() ;
  if ( top < minEle ) {
    int newmin = 2 * minEle - top ;
    top = minEle ;
    minEle = newmin ;
  }
  return top  ;

}

/*push element x into the stack*/
void _stack::push(int x)
{
  //Your code here
  if (s.empty()) {
    s.push(x) ; minEle = x ;
  }
  else {
    if ( x < minEle) {
      int dummy = 2 * x - minEle ;
      // of course dummy will be less than x
      s.push(dummy) ;
      minEle = x ;
    }
    else s.push(x) ;
  }
}
