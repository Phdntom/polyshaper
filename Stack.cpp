
//Basic Array implemented stack
template<class T>
class Stack{
	int size;
	T array[5000];

 public:
	Stack( ){size = 0;};
	void Push(T item);
	T Pop();
	bool IsEmpty();
	Stack<T>& operator =(const Stack<T>& rightSide);
};

template<class T>
void Stack<T>::Push(T item){
	if(size < 1000)
		array[size] = item;
	else
		cout << "Stack overflow\n";
	size++;
}

template<class T>
T Stack<T>::Pop(){
	if(size > 0) {
		size--;
		return array[size];
	}
	else
		cout << "Stack underflow\n";
}

template<class T>
bool Stack<T>::IsEmpty(){
	return (size == 0);
}

template<class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& aStack)
{
	for(int i = 0; i < aStack.size; i++)
		array[i] = aStack.array[i];
	size = aStack.size;

}//= operator
