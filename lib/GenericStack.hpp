
#ifndef GENERICSTACK_HPP
#define GENERICSTACK_HPP

#include "iostream"

#include "GenericNode.hpp"
#include "IGenericStack.hpp"

/**
 * @brief Implementation of IGenericStack using linked list.
 *
 * This class implements the IGenericStack interface using a linked list.
 *
 * @tparam T The type of data the stack will hold.
 */
template <typename T>
class GenericStack : public IGenericStack<T> {
public:
    /**
    * @brief Default Constructor.
    *
    * Initializes the start pointer to nullptr.
    */
    GenericStack() : start(nullptr) {}

    /**
     * @brief Adds an object to the top of the stack.
     *
     * @param o The object to be pushed onto the stack.
     */
    void push(T o) override {
        start = new GenericNode<T>(o, start);
    }

    /**
     * @brief Removes and returns the top object from the stack.
     *
     * @return The top object from the stack.
     */
    T pop() override {
        if (isEmpty())
            throw std::runtime_error("Tried to pop an empty stack");
        T data = start->getData();
        GenericNode<T>* temp = start;
        start = start->getNext();
        delete temp; // Free the memory
        return data;
    }

    /**
     * @brief Returns the top object from the stack without removing it.
     *
     * @return The top object from the stack.
     */
    T top() const override {
        if (isEmpty())
            return T(); // Return default-constructed object for simplicity
        return start->getData();
    }

    /**
     * @brief Checks if the stack is empty.
     *
     * @return True if the stack is empty, false otherwise.
     */
    [[nodiscard]] bool isEmpty() const override {
        return start == nullptr;
    }
private:
    /**
     * Pointer to the start of the linked list
     */
    GenericNode<T>* start;
};

#endif //GENERICSTACK_HPP
