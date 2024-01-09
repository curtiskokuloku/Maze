
#ifndef GENERICQUEUE_HPP
#define GENERICQUEUE_HPP

#include "iostream"

#include "GenericNode.hpp"
#include "IGenericQueue.hpp"

/**
 * @brief Implementation of QGen using a linked list.
 *
 * This class implements the QGen interface using a linked list.
 *
 * @tparam T The type of data the queue will hold.
 */
template <typename T>
class GenericQueue : public IGenericQueue<T> {
public:
    /**
     * @brief Default Constructor.
     *
     * Initializes the front and rear pointers to nullptr and size to 0.
     */
    GenericQueue() : size(0), front(nullptr), rear(nullptr) {}

    /**
     * @brief Adds an object to the queue.
     *
     * @param o The object to be added to the queue.
     */
    void add(T o) override {
        if (size == 0) {
            front = new GenericNode<T>(o, nullptr);
            rear = front;
        } else {
            rear->setNext(new GenericNode<T>(o, nullptr));
            rear = rear->getNext();
        }
        size++;
    }

    /**
     * @brief Removes and returns the front object from the queue.
     *
     * @return The front object from the queue.
     */
    T remove() override {
        if (size == 0)
            throw std::runtime_error("Removing from empty queue");

        T answer = front->getData();
        GenericNode<T>* temp = front;
        front = front->getNext();
        delete temp; // Free the memory
        size--;

        if (size == 0)
            rear = nullptr;

        return answer;
    }

    /**
     * @brief Returns the number of items in the queue.
     *
     * @return The number of items in the queue.
     */
    [[nodiscard]] int length() const override {
        return this->size;
    }

private:
    /**
     * Pointer to the front of the linked list.
     */
    GenericNode<T>* front;

    /**
     * Pointer to the rear of the linked list.
     */
    GenericNode<T>* rear;

    /**
     * Number of items in the queue.
     */
    int size;
};

#endif //GENERICQUEUE_HPP
