class StackNode<T> {
	T item;
	StackNode<T> *prev;
	StackNode(StackNode<T> *prev, T item) : prev(prev), item(item) {}
}

class Stack<T> {
private:
	StackNode<T> *top = nullptr;
public:
	T pop() {
		if (top == nullptr)
			throw runtime_error("Stack underflow");
		auto prev = top->prev;
		auto val = top->item;
		delete top;
		top = prev;
		return val;
	}
	void push(T item) {
		top = new StackNode(top, item); // EASY
		// CANNOT overflow
	}
}

class DequeNode<T> {
	DequeNode<T> *prev = nullptr;
	DequeNode<T> *next = nullptr;
	T item;
	// DequeNode<T>(DequeNode<T> *p, DequeNode<T> *n, T x) : prev{p}, next{n}, item{i} {}
}

class Deque<T> {
template class DequeNode<T>;
private:
	DequeNode<T> *head = nullptr;
	DequeNode<T> *tail = nullptr;
public:
	void toFront(T item) {
		if (head == nullptr) { // list is empty
			head = tail = new DequeNode{nullptr, nullptr, item};
			return;
		}
		head = new DequeNode{nullptr, head, item};
		head->next->prev = head; // backlink
	}
	void toBack(T item) {
		if (tail == nullptr) {
			tail = head = new DequeNode{nullptr, nullptr, item};
		}
		tail = new DequeNode{tail, nullptr, item};
		tail->prev->next = tail; // backlink
	}
	T fromFront() {
		if (head == nullptr)
			throw runtime_error("Deque underflow (fromFront)")
		auto node = head;
		head = head->next;
		if (head == nullptr) // list is now empty
			tail = nullptr;
		else // need to fix backlink
			head->prev = nullptr;
		auto item = node->item;
		delete node;
		return item;
	}
	T fromBack() {
		if (tail == nullptr)
			throw runtime_error("Deque underflow(fromBack)");
		auto node = tail;
		tail = tail->prev;
		if (tail == nullptr) // list empty
			head = nullptr;
		else // need to fix backlink
			tail->next = nullptr;
		auto item = node->item;
		delete node;
		return item;
	}
}
// And there's my argument for linkedlist representation.
// It takes more code than would be necessary normally, but it's more stable in my opinion.
// These ones also CANNOT overflow.

