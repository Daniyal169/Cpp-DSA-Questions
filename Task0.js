class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    insertAtHead(value) {
        const newNode = new Node(value);
        newNode.next = this.head;
        this.head = newNode;
    }

    insertAtTail(value) {
        const newNode = new Node(value);
        this.tail.next = newNode;
        this.tail = newNode;
    }

    insertRandom(position, value) {
        if (position === 1) {
            this.insertAtHead(value);
            return;
        }
        let temp = this.head;
        let count = 1;

        while (count < position - 1 && temp !== null) {
            temp = temp.next;
            count++;
        }

        if (temp === null) {
            this.insertAtTail(value);
            return;
        }

        const newNode = new Node(value);
        newNode.next = temp.next;
        temp.next = newNode;
    }

    deleteNode(position) {
        if (position === 1 && this.head !== null) {
            let temp = this.head;
            this.head = this.head.next;
            if (this.head === null) {
                this.tail = null;
            }
            temp.next = null;
            return;
        }

        let temp = this.head;
        let prev = null;
        let count = 1;

        while (temp !== null && count < position) {
            prev = temp;
            temp = temp.next;
            count++;
        }

        if (temp === null) return;

        if (temp.next === null) {
            this.tail = prev;
        }

        prev.next = temp.next;
    }

    display() {
        if (this.head === null) {
            console.log("List is empty");
            return;
        }
        let temp = this.head;
        while (temp !== null) {
            process.stdout.write(temp.value + " ");
            temp = temp.next;
        }
        console.log();
        console.log("Head is: " + this.head.value);
        console.log("Tail is: " + (this.tail ? this.tail.value : "null"));
        console.log();
    }
}

const linkedList = new LinkedList();

linkedList.insertAtHead(20);
linkedList.display();

linkedList.insertAtTail(26);
linkedList.display();

linkedList.insertRandom(2, 46);
linkedList.display();

linkedList.insertRandom(3, 99);
linkedList.display();

