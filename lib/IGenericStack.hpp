
#ifndef IGENERICSTACK_HPP
#define IGENERICSTACK_HPP

/**
 * @brief Interface for a Generic Stack.
 *
 * This interface defines the methods necessary for a generic stack.
 *
 * @tparam T The type of data the stack will hold.
 */
template <typename T>
class IGenericStack {
public:
    /**
     * @brief Adds an object to the top of the stack.
     *
     * @param o The object to be pushed onto the stack.
     */
    virtual void push(T o) = 0;

    /**
     * @brief Removes and returns the top object from the stack.
     *
     * @return The top object from the stack.
     */
    virtual T pop() = 0;

    /**
     * @brief Returns the top object from the stack without removing it.
     *
     * @return The top object from the stack.
     */
    virtual T top() const = 0;

    /**
     * @brief Checks if the stack is empty.
     *
     * @return True if the stack is empty, false otherwise.
     */
    [[nodiscard]] virtual bool isEmpty() const = 0;
};

#endif //IGENERICSTACK_HPP
