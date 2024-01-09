
#ifndef GENERICNODE_HPP
#define GENERICNODE_HPP

/**
 * @brief A simplified generic node class using templates for data.
 *
 * This class represents a node that can store data of any type.
 * The class uses templates to achieve this generic behavior.
 *
 * @tparam T The type of data the node will hold.
 */
template <typename T>
class GenericNode {
public:
    /**
     * Default Constructor that initializes data and next pointer to nullptr.
     */
     GenericNode() : data(nullptr), next(nullptr) {}

     /**
      * Constructor with specified data and next node
      * @param o The data to be stored in the node.
      * @param link Pointer to the next node in the sequence.
      */
      GenericNode(T o, GenericNode<T> link) : data(o), next(link) {}

      // Selectors

      /**
       * Get the data stored in the node
       * @return The data stores in the node of type T
       */
      T getData() const {
          return this->data;
      }

    /**
     * Set the data of the node
     * @param o The data to be set in the node
     */
      void setData(T o) {
          this->data = o;
      }

    /**
     * Get the pointer to the next node.
     * @return Pointer to the next node.
     */
      GenericNode<T>* getNext() const {
          return this->next;
      }

    /**
     * Set the next node.
     * @param link Pointer to the next node to be set.
     */
      void setNext(GenericNode<T>* link) {
          this->next = link;
      }

private:
    /**
     * Data stored in the node
     */
    T data;

    /**
     * Pointer to the next node
     */
     GenericNode<T>* next;
};

#endif //GENERICNODE_HPP
