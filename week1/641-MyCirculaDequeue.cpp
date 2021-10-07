class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        capacity = k + 1;
        arr.assign(capacity, 0);

        front = 0;
        rear = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }
private:
    vector<int> arr;
    int front;
    int rear;
    int capacity;
};
