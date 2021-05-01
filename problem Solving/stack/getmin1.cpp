
stack<int>s ; // normal stack
stack<int>ss ; // support stack


void push( int a) {
	s.push(a) ;
	if ( ss.empty()) ss.push(a) ;
	else if (a <= ss.top() ) ss.push(a) ;
}

bool isFull( int n) {
	if  ( s.size() >= n ) return 1 ;
	else return 0 ;
}

bool isEmpty() {
	if ( s.empty()) return 1 ;
	else return 0 ;
}

int pop() {
	if ( s.empty()) return -1 ;
	int e = s.top( ) ;
	s.pop() ;

	if ( e == ss.top()) ss.pop() ;
	return e ;

}

int getMin() {
	if ( ss.empty()) return -1 ;
	else return ss.top() ;

}