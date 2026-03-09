template<typename T>
class Stack<T> {
private:
	T backer[];
	const size_t len;
	size_t empty = 0;
public:
	explicit Stack(size_t length = 6) : len(length), backer(T[length]) {}
	void push(T item);
	T pop();
}

template<typename T>
T Stack<T>::pop() {
	if(empty <= 0) throw runtime_error("Stack underflow"); // FAIL
	T item = backer[--empty];
	// don't bother writing over it that'll happen later
	return item;
}
void Stack<T>::push(T item) {
	if (empty >= len) throw runtime_error("Stack overflow"); // no way its a stack overflow reference
	backer[empty++] = item;
}

template<typename T>
class Queue<T> {
private:
	T backer[];
	const size_t len;
	size_t head = 0;
	size_t nextEmpty = 0;
public:
	explicit Queue(size_t length = 6) : backer(T[length]), len(length) {}
	T pop();
	void push(T item);
}

template<typename T>
T Stack::pop() {
	if (nextEmpty == head) throw runtime_error("Queue underflow");
	T item = backer[head];
	head = (head + 1) % length;
	return item;
}
void Stack::push(T item) {
	if (((nextEmpty + 1) % length) == head) throw runtime_error("Queue overflow");
	backer[nextEmpty] = item;
	nextEmpty = (nextEmpty+1) % length;
}

template<typename T>
class Deque {
private:
	T backer[];
	const size_t len;
	size_t head = 0;
	size_t tail = 0;
	inline size_t plusWrap(size_t x) {
		return (x + 1)%len;
	}
	inline size_t minusWrap(size_t x) {return (x || len) - 1;}
public:
	explicit Deque(size_t length) : len(length), backer(T[length]) {}
	void toFront(T item) {
		if (minusWrap(head) == tail)
			throw runtime_error("Deque overflow (toFront)");
		if (head == tail) 
			tail = plusWrap(tail);
		backer[head] = item;
		head = minusWrap(head);
	}
	void toBack(T item) {
		if (plusWrap(tail) == head)
			throw runtime_error("Deque overflow (toBack)");
		if (tail == head)
			head = minusWrap(head);
		backer[tail] = item;
		tail = plusWrap(tail);
	}
	T fromFront() {
		if (head == tail)
			throw runtime_error("Deque underflow (fromFront)");
		T out = backer[head];
		head = plusWrap(head);
		return out;
	}
	T fromBack() {
		if (tail == head)
			throw runtime_error("Deque underflow(fromBack)");
		T out = backer[tail];
		tail = minusWrap(tail);
		return out;
	}
}
