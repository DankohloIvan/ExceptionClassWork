#pragma once

template <typename T>
class Stack {
	int size_;
	T* stack_;
public:
	Stack() {};
	Stack(int size) : size_(size){
		stack_ = new T[size] {};

	};
	void addElement(T value) {
		T* newStack = new T[size_ + 1];
		for (int i = 0; i < size_; ++i) {
			newStack[i] = stack_[i];
		}
		newStack[size_] = value;
		delete[] stack_;
		stack_ = newStack;
		size_++;
	}
	void pop() {
		if (size_ == 0) {
			throw std::out_of_range("Stack is empty");
		}

		T* newStack;
		if (size_ > 1) {
			newStack = new T[size_ - 1];
		}
		else {
			newStack = nullptr;
		}

		for (int i = 0; i < size_ - 1; ++i) {
			newStack[i] = stack_[i];
		}

		delete[] stack_;
		stack_ = newStack;
		size_--;
	}
	void print() const {
		for (int i = size_ - 1; i >= 0; --i) {
			std::cout << stack_[i] << '\n';
		}
	}
	~Stack() {
		delete[] stack_;
	}
};