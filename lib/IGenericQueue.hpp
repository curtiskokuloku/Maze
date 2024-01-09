
#ifndef IGENERICQUEUE_HPP
#define IGENERICQUEUE_HPP

/**
 * @brief Interface for a Generic Queue.
 *
 * This interface defines the methods necessary for a generic queue.
 *
 * @tparam T The type of data the queue will hold.
 */
template <typename T>
class IGenericQueue {
    /**
     * @brief Adds an object to the queue.
     *
     * @param o The object to be added to the queue.
     */
    virtual void add(T o) = 0;

    /**
     * @brief Removes and returns the front object from the queue.
     *
     * @return The front object from the queue.
     */
    virtual T remove() = 0;

    /**
     * @brief Returns the number of items in the queue.
     *
     * @return The number of items in the queue.
     */
    [[nodiscard]] virtual int length() const = 0;
};

#endif //IGENERICQUEUE_HPP
